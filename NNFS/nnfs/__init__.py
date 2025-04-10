from matplotlib.pylab import f
from .activations import Activations
from .layer import Layer
from .loss import Loss

import numpy as np
from tqdm.cli import tqdm

rng = np.random.default_rng(42)

class nn:
    
    def __init__(self, N_INPUT, N_OUTPUT, N_LAYERS, N_HIDDEN, activation, loss, weight_initializer=0.1, bias_initializer=0.1):
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
        
        # Initialize the first layer with input size and hidden neurons
        self.layers = [Layer(N_INPUT, N_HIDDEN, activation, weight_initializer, bias_initializer)]
        
        # Initialize hidden layers
        for _ in range(1, N_LAYERS):
            self.layers.append(Layer(N_HIDDEN, N_HIDDEN, activation, weight_initializer, bias_initializer))
        
        # Initialize output layer
        # final_act = Activations('Linear')
        self.layers.append(Layer(N_HIDDEN, N_OUTPUT, activation, weight_initializer, bias_initializer))

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
    
    def _compute_regularization(self) -> float:
        """
        Computes the regularization term for the network's weights.
        
        Returns:
            float: The computed regularization term.
        """
        return 1e-4 * sum(np.sum(layer.weights**2) for layer in self.layers)
    
    def metropolis(self, x, y, 
                   batch_size=0, bach_epochs = 10, max_epochs = 1000, 
                   delta_bias = 0.1, delta_weight = 0.1, 
                   tE0 = 1, tEmin = 1e-4, decay_rate = 0.001, 
                   Error_threshold = 0.01):
        """
        Trains the neural network using the Metropolis algorithm.
        
        Args:
            x (ndarray): Input data of shape (num_samples, N_INPUT).
            y (ndarray): Ground truth labels of shape (num_samples, N_OUTPUT).
            batch_size (int): Number of samples in each batch.
            bach_epochs (int): Number of epochs before updating the batch.
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
                - epoch (int): Number of epochs completed.
        """
        # list to store errors vs epochs
        self.Errors = []
        
        if batch_size == 0:
            # set batch size to the number of samples
            batch_size = len(x)
        
        # batch
        batch_index = rng.choice(range(len(x)), batch_size)
        batch_x = x[batch_index]
        batch_y = y[batch_index]
        
        # calculate current prediction and error
        Pred, Erro = self.forward(x, y)
        Erro += self._compute_regularization()
                        
        # loop over epochs
        for epoch in tqdm(range(max_epochs)):
            # Dynamically adjust temperature
            tE = tE0 * np.exp(-decay_rate * epoch) + tEmin
                        
            # store current error
            self.Errors.append(Erro)

            # save current state of the nn
            ws = []
            bs = []
            for layer in self.layers:
                ws.append(layer.weights.copy())
                bs.append(layer.biases.copy())
            
            # sample a random change
            for layer in self.layers:
                shape = layer.weights.shape
                layer.weights += rng.normal(0, delta_weight, shape)
                
                shape = layer.biases.shape
                layer.biases += rng.normal(0, delta_bias, shape)
                
            # check new prediction and error
            Pred2, Erro2 = self.forward(batch_x, batch_y)
            Erro2 += self._compute_regularization()
            
            # Calculate acceptance probability
            delta_E = Erro2 - Erro
            p = np.exp(-delta_E / (tE + 1e-8)) if delta_E > 0 else 1.0
            
            # metropolis condition
            if p < rng.uniform():
                # reject the new state
                for i, layer in enumerate(self.layers):
                    layer.weights = ws[i]
                    layer.biases = bs[i]
            else:
                # accept the new state
                Pred = Pred2
                Erro = Erro2
            
            # finish if the error is small enough
            if Erro < Error_threshold:
                break
            
            # if not finished, update the batch every bach_epochs
            if epoch % bach_epochs == 0:
                batch_index = rng.choice(range(len(x)), batch_size)
                batch_x = x[batch_index]
                batch_y = y[batch_index]
            
        # calculate final prediction with full data
        Pred, Erro = self.forward(x, y)

        # return the final prediction, error, and epoch count
        return Pred, Erro, epoch

    def backpropagation(self, x, y, learning_rate=0.01, max_epochs=1000, Error_threshold=0.01):
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
                - epoch (int): Number of epochs completed.
        """
        self.Errors = []

        for epoch in tqdm(range(max_epochs)):
            # Forward pass
            Pred, Erro = self.forward(x, y)
            Erro += self._compute_regularization()
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
        return Pred, Erro, epoch
