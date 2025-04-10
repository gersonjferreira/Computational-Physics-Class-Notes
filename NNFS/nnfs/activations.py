import numpy as np

class Activations():
    """
    A class to handle various activation functions for neural networks.
    Allows dynamic selection of activation methods.
    """
    
    def __init__(self, method='ReLU'):
        """
        Initialize the activation function based on the provided method.
        
        Args:
            method (str): The name of the activation function to use. 
                          Options: 'ReLU', 'Linear', 'Logistic', 'Tanh'.
        
        Raises:
            Exception: If the specified method is not supported.
        """
        # a dictionary of activation methods
        methods = {
            'ReLU': self.ReLU,       # Rectified Linear Unit
            'Linear': self.Linear,   # Linear activation
            'Logistic': self.Logistic, # Sigmoid activation
            'Tanh': self.Tanh        # Hyperbolic tangent activation
        }
        if method in methods:
            # use the dict to set the forward method from the string parameter method
            self.forward = methods[method]
        else:
            # Raise an error for invalid methods
            raise Exception(f'Activation {method} not defined. Supported methods: {list(methods.keys())}')  

    def ReLU(self, inputs):
        """
        Apply the ReLU activation function.
        
        Args:
            inputs (ndarray): Input data.
        
        Returns:
            ndarray: Output after applying ReLU activation.
        """
        return np.maximum(0, inputs)  # Output is max(0, input)

    def Linear(self, inputs):
        """
        Apply the Linear activation function (identity function).
        
        Args:
            inputs (ndarray): Input data.
        
        Returns:
            ndarray: Output after applying Linear activation.
        """
        return inputs  # Output is the same as input

    def Logistic(self, inputs):
        """
        Apply the Logistic (Sigmoid) activation function.
        
        Args:
            inputs (ndarray): Input data.
        
        Returns:
            ndarray: Output after applying Logistic activation.
        """
        return 1 / (1 + np.exp(-inputs))  # Sigmoid formula

    def Tanh(self, inputs):
        """
        Apply the Tanh activation function.
        
        Args:
            inputs (ndarray): Input data.
        
        Returns:
            ndarray: Output after applying Tanh activation.
        """
        return np.tanh(inputs)  # Hyperbolic tangent formula