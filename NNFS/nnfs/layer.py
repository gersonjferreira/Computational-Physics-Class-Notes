import numpy as np

class Layer():
    """
    Represents a single layer in a neural network.
    
    Attributes:
        weights (ndarray): Weight matrix of shape (n_inputs, n_neurons).
        biases (ndarray): Bias vector of shape (1, n_neurons).
        activation (callable): Activation function for the layer.
    """
    def __init__(self, n_inputs, n_neurons, activation, weight_initializer=0.1, bias_initializer=0.1):
        """
        Initializes the layer with random weights and biases.

        Args:
            n_inputs (int): Number of input features.
            n_neurons (int): Number of neurons in the layer.
            activation (callable): Activation function for the layer.
            weight_initializer (float): Scaling factor for weight initialization.
            bias_initializer (float): Scaling factor for bias initialization.
        """
        # Initialize weights with random values scaled by weight_initializer
        self.weights = weight_initializer * np.random.randn(n_inputs, n_neurons)
        # Initialize biases with random values scaled by bias_initializer
        self.biases  = bias_initializer * np.random.randn(1, n_neurons)
        # Store the activation function
        self.activation = activation.forward
        
    def forward(self, inputs):
        """
        Performs the forward pass through the layer.

        Args:
            inputs (ndarray): Input data of shape (batch_size, n_inputs).
        
        Sets:
            output (ndarray): Output of the layer after applying weights, biases, and activation.
        """
        # Compute the dot product of inputs and weights, add biases, and apply activation
        self.output = self.activation(inputs @ self.weights + self.biases)
        # Return the output
        return self.output

