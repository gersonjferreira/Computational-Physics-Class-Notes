from .activations import Activations
from .layer import Layer
from .loss import Loss

class nn:
    
    def __init__(self, N_INPUT, N_OUTPUT, N_HIDDEN, N_LAYERS, activation, loss, weight_initializer=0.1, bias_initializer=0.1):
        """
        Initializes the neural network with the specified parameters.
        
        Args:
            N_INPUT (int): Number of input features.
            N_OUTPUT (int): Number of output features.
            N_HIDDEN (int): Number of hidden neurons in each layer.
            N_LAYERS (int): Number of hidden layers.
            activation (callable): Activation function for the layers.
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
        self.layers.append(Layer(N_HIDDEN, N_OUTPUT, activation, weight_initializer, bias_initializer))
        
    def forward(self, inputs, reference):
        """
        Performs the forward pass through the entire network.
        
        Args:
            inputs (ndarray): Input data of shape (batch_size, N_INPUT).
        
        Returns:
            ndarray: Output of the network after applying all layers.
        """
        # Pass inputs through each layer
        for layer in self.layers:
            inputs = layer.forward(inputs)
        
        return inputs, self.loss(inputs, reference)