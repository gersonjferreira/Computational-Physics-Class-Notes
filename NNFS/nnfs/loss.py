import numpy as np

class Loss():
    """
    A class to handle various loss functions for neural networks.
    Allows dynamic selection of loss methods.
    """
    
    def __init__(self, method='MSE'):
        """
        Initialize the loss function based on the provided method.
        
        Args:
            method (str): The name of the loss function to use.
                          Options: 'MSE'
        
        Raises:
            Exception: If the specified method is not supported.
        """
        # A dictionary of loss methods
        methods = {
            'MSE': self.mean_squared_error,       # Mean Squared Error
        }
        if method in methods:
            # Use the dict to set the calculate method from the string parameter method
            self.calculate = methods[method]
        else:
            # Raise an error for invalid methods
            raise Exception(f'Loss {method} not defined. Supported methods: {list(methods.keys())}')
    
    def mean_squared_error(self, y_true, y_pred, derivative=False):
        """
        Compute the Mean Squared Error (MSE) loss.
        
        Args:
            y_true (ndarray): True labels of shape (batch_size, N_OUTPUT).
            y_pred (ndarray): Predicted values of shape (batch_size, N_OUTPUT).
            derivative (bool): Whether to compute the derivative of the loss.
        
        Returns:
            float: The computed MSE loss or its derivative.
        """
        if derivative:
            return 2 * (y_pred - y_true) / y_true.shape[0]  # Fix normalization by batch size
        return np.mean((y_true - y_pred) ** 2)

