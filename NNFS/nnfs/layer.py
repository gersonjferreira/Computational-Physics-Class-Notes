import numpy as np

class Layer():
    """
    Represents a single layer in a neural network.
    
    Attributes:
        weights (ndarray): Weight matrix of shape (n_inputs, n_neurons).
        biases (ndarray): Bias vector of shape (1, n_neurons).
        activation (callable): Activation function for the layer.
    """
    def __init__(self, n_inputs, n_neurons, activation, weight_initializer=0.1, bias_initializer=0.1, rng=42):
        """
        Initializes the layer with random weights and biases.

        Args:
            n_inputs (int): Number of input features.
            n_neurons (int): Number of neurons in the layer.
            activation (callable): Activation function for the layer.
            weight_initializer (float): Scaling factor for weight initialization.
            bias_initializer (float): Scaling factor for bias initialization.
        
        Attributes:
            weights (ndarray): Weight matrix of shape (n_inputs, n_neurons).
            biases (ndarray): Bias vector of shape (1, n_neurons).
        """
        # check if rng is number or rng instance
        if isinstance(rng, int):
            rng = np.random.default_rng(rng)
        
        # Initialize weights with random values scaled by weight_initializer
        self.weights = weight_initializer * rng.normal(0, 1, (n_inputs, n_neurons))
        # Initialize biases with random values scaled by bias_initializer
        self.biases  = bias_initializer * rng.normal(0, 1, (1, n_neurons))
        # Store the activation function
        self.activation = activation.forward
        
    def forward(self, inputs):
        """
        Performs the forward pass through the layer.

        Args:
            inputs (ndarray): Input data of shape (batch_size, n_inputs).
        
        Returns:
            ndarray: Output of the layer after applying weights, biases, and activation.
        """
        # Store inputs for use in the backward pass
        self.inputs = inputs
        # Compute the dot product of inputs and weights, add biases, and apply activation
        self.output = self.activation(inputs @ self.weights + self.biases)
        return self.output

    def backward(self, d_output, learning_rate):
        """
        Performs the backward pass and updates weights and biases.
        
        Args:
            d_output (ndarray): Gradient of the loss with respect to the layer's output.
            learning_rate (float): Learning rate for weight and bias updates.
        
        Returns:
            ndarray: Gradient of the loss with respect to the layer's input.
        """
        # Gradient of activation
        d_activation = d_output * self.activation(self.output, derivative=True)
        
        # Gradients for weights and biases
        d_weights = self.inputs.T @ d_activation
        d_biases = np.sum(d_activation, axis=0, keepdims=True)
        
        # Update weights and biases
        self.weights -= learning_rate * d_weights
        self.biases -= learning_rate * d_biases
        
        # Return gradient for the previous layer
        return d_activation @ self.weights.T

