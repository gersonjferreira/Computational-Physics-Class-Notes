from .layer import Layer

import numpy as np
from tqdm.cli import tqdm

class nn:
    
    def __init__(self, N_INPUT, N_OUTPUT, N_LAYERS, N_HIDDEN, activation, loss, weight_initializer=0.1, bias_initializer=0.1, seed=42):
        """
        Initializes the neural network with the specified parameters.
        
        Args:
            N_INPUT (int): Number of input features.
            N_OUTPUT (int): Number of output features.
            N_LAYERS (int): Number of hidden layers.
            N_HIDDEN (int): Number of hidden neurons in each layer.
            activation (callable): Activation function for the layers.
            loss (Loss): Loss function object to calculate the error.
            weight_initializer (float): Scaling factor for weight initialization.
            bias_initializer (float): Scaling factor for bias initialization.
        """
        self.N_INPUT = N_INPUT
        self.N_OUTPUT = N_OUTPUT
        self.N_HIDDEN = N_HIDDEN
        self.N_LAYERS = N_LAYERS
        self.loss = loss.calculate
        self.rng = np.random.default_rng(seed)
        
        # Initialize the first layer with input size and hidden neurons
        self.layers = [Layer(N_INPUT, N_HIDDEN, activation, weight_initializer, bias_initializer, self.rng)]
        
        # Initialize hidden layers
        for _ in range(1, N_LAYERS):
            self.layers.append(Layer(N_HIDDEN, N_HIDDEN, activation, weight_initializer, bias_initializer, self.rng))
        
        # Initialize output layer
        self.layers.append(Layer(N_HIDDEN, N_OUTPUT, activation, weight_initializer, bias_initializer, self.rng))

    def predict(self, inputs):
        return self.forward(inputs, loss=False)[0]
        
    def forward(self, inputs, reference=None, loss=True):
        """
        Performs the forward pass through the entire network.
        
        Args:
            inputs (ndarray): Input data of shape (batch_size, N_INPUT).
            reference (ndarray): Ground truth labels of shape (batch_size, N_OUTPUT).
            loss (bool): If True, computes the loss using the reference labels.
        
        Returns:
            tuple: A tuple containing:
                - output (ndarray): Output of the network after applying all layers.
                - loss (float): Computed loss value.
        """
        # Pass inputs through each layer
        x0 = inputs
        for layer in self.layers:
            # next x1 from previous x0
            x1 = layer.forward(x0)
            # for the next layer, x1 becomes x0
            x0 = x1
            
        # output is the last layer's output
        output = x1
        
        if loss:
            return output, self.loss(output, reference)
        else:
            return output, None
    
    def metropolis(self, x, y, 
                   max_epochs = 1000, 
                   delta_bias = 0.1, delta_weight = 0.1, 
                   tE0 = 1, tEmin = 1e-8, decay_rate = 0.001, 
                   Error_threshold = 1e-3):
        """
        Trains the neural network using the Metropolis algorithm.
        
        Args:
            x (ndarray): Input data of shape (num_samples, N_INPUT).
            y (ndarray): Ground truth labels of shape (num_samples, N_OUTPUT).
            max_epochs (int): Maximum number of training epochs.
            delta_bias (float): Standard deviation for bias perturbation.
            delta_weight (float): Standard deviation for weight perturbation.
            tE0 (float): Initial temperature for the Metropolis algorithm.
            tEmin (float): Minimum temperature for the Metropolis algorithm.
            decay_rate (float): Exponential decay rate for the temperature.
            Error_threshold (float): Error threshold to stop training early.
        
        Returns:
            tuple: A tuple containing:
                - Pred (ndarray): Final predictions of the network.
                - Erro (float): Final error value.
        """
        # list to store errors vs epochs
        self.Errors = []
        
        # calculate current prediction and error
        Pred, Erro = self.forward(x, y)
        # store current error
        self.Errors.append(Erro)
        
        # loop over epochs
        real_epoch = 0
        for epoch in tqdm(range(max_epochs)):
            # Dynamically adjust temperature
            tE = tE0 * np.exp(-decay_rate * real_epoch/max_epochs) + tEmin
            
            # save current state of the nn
            ws = []
            bs = []
            for layer in self.layers:
                ws.append(layer.weights.copy())
                bs.append(layer.biases.copy())
            
            # sample a random change
            for layer in self.layers:
                shape = layer.weights.shape
                layer.weights += self.rng.normal(0, delta_weight, shape)
                
                shape = layer.biases.shape
                layer.biases += self.rng.normal(0, delta_bias, shape)
                
            # check new prediction and error
            Pred2, Erro2 = self.forward(x, y)
            
            # Calculate acceptance probability
            delta_E = Erro2 - Erro
            p = np.exp(-delta_E / (tE + 1e-8)) if delta_E > 0 else 1.0
            
            # metropolis condition
            if p < self.rng.uniform():
                # reject the new state
                for i, layer in enumerate(self.layers):
                    layer.weights = ws[i]
                    layer.biases = bs[i]
            else:
                # accept the new state
                real_epoch += 1
                Pred = Pred2
                Erro = Erro2
            
            # store error every time, even if rejected
            self.Errors.append(Erro)
            
            # finish if the error is small enough
            if Erro < Error_threshold:
                break
            
        # calculate final prediction with full data
        Pred, Erro = self.forward(x, y)
        # store current error
        self.Errors.append(Erro)

        # return the final prediction, error, and epoch count
        return Pred, Erro

    def backpropagation(self, x, y, learning_rate=0.01, max_epochs=1000, Error_threshold=1e-3):
        """
        Trains the neural network using backpropagation and SGD.
        
        Args:
            x (ndarray): Input data of shape (num_samples, N_INPUT).
            y (ndarray): Ground truth labels of shape (num_samples, N_OUTPUT).
            learning_rate (float): Learning rate for weight and bias updates.
            max_epochs (int): Maximum number of training epochs.
            Error_threshold (float): Error threshold to stop training early.
        
        Returns:
            tuple: A tuple containing:
                - Pred (ndarray): Final predictions of the network.
                - Erro (float): Final error value.
        """
        self.Errors = []

        for epoch in tqdm(range(max_epochs)):
            # Forward pass
            Pred, Erro = self.forward(x, y)
            self.Errors.append(Erro)

            # Stop if error is below threshold
            if Erro < Error_threshold:
                break

            # Backward pass
            d_output = self.loss(y, Pred, derivative=True)  # Fix argument order for derivative
            for layer in reversed(self.layers):
                d_output = layer.backward(d_output, learning_rate)

        # Final prediction
        Pred, Erro = self.forward(x, y)
        return Pred, Erro
