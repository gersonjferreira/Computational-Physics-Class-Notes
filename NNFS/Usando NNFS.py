"""
This script demonstrates the usage of the NNFS library to train a neural network
using the Metropolis algorithm. It visualizes the predictions and error evolution.
"""

import matplotlib.pyplot as plt
import numpy as np
import nnfs

# commom parameters
layers = 3
neurons = 5
seed = 42
max_epochs = 100000

# define data
x = np.array([np.linspace(0, 1, 50)]).T
y = np.sin(2*np.pi*x) + np.random.normal(0, 0.1, x.shape)

# create the NN
nn = nnfs.nn(1, 1, 
             layers, neurons,
             nnfs.Activations('Tanh'),
             nnfs.Loss('MSE'),
             weight_initializer=1,
             bias_initializer=1,
             seed=seed
             )

# train the NN using the Metropolis algorithm
Pred, Erro = nn.metropolis(x, y, max_epochs=max_epochs, 
                                   # T = tE0 * exp(-decay_rate * epoch/max_epochs) + tEmin
                                   tE0=10,
                                   decay_rate=50, 
                                   tEmin=1e-8,
                                   # update scale
                                   delta_bias=1e-1,
                                   delta_weight=1e-1,
                                   Error_threshold=1e-6
                                   )

# extract the predictions
x2 = np.array([np.linspace(0, 2, 1000)]).T
y2 = nn.predict(x2)

# plot the results of metropolis
plt.figure(figsize=(8, 8))

plt.subplot(221)
plt.title('Prediction vs Data')
plt.plot(x, y, 'o', label='Data')
plt.plot(x, Pred, 'o', label='Training')
plt.plot(x2, y2, '-', label='Prediction')
plt.xlabel('x (input)')
plt.ylabel('y (output)')
plt.legend()

plt.subplot(222)
plt.title('Error vs Epochs')
plt.loglog(nn.Errors)
plt.xlabel('Epochs')
plt.ylabel('Error (log scale)')
plt.xlim(None, 1.1*max_epochs)

#########################################################################

# create the NN - comment to continue with bias and weitghts from metropolis
nn = nnfs.nn(1, 1, 
             layers, neurons,
             nnfs.Activations('Tanh'),
             nnfs.Loss('MSE'),
             weight_initializer=1,
             bias_initializer=1,
             seed=seed
             )

# training the NN using backpropagation and SGD
Pred, Erro = nn.backpropagation(x, y,
                                learning_rate=0.01,
                                max_epochs=max_epochs,
                                Error_threshold=1e-6
                               )

# extract the predictions
x2 = np.array([np.linspace(0, 2, 100)]).T
y2 = nn.predict(x2)

# plot the results of backpropagation and SGD

plt.subplot(223)
plt.title('Prediction vs Data')
plt.plot(x, y, 'o', label='Data')
plt.plot(x, Pred, 'o', label='Training')
plt.plot(x2, y2, '-', label='Prediction')
plt.xlabel('x (input)')
plt.ylabel('y (output)')
plt.legend()

plt.subplot(224)
plt.title('Error vs Epochs')
plt.loglog(nn.Errors)
plt.xlabel('Epochs')
plt.ylabel('Error (log scale)')
plt.xlim(None, 1.1*max_epochs)

plt.tight_layout()
plt.show()
