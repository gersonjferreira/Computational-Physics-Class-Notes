"""
This script demonstrates the usage of the NNFS library to train a neural network
using the Metropolis algorithm. It visualizes the predictions and error evolution.
"""

import matplotlib.pyplot as plt
import numpy as np
import nnfs

nn = nnfs.nn(1, 1, 3, 10, nnfs.Activations('Tanh'), nnfs.Loss('MSE'))

x = np.array([np.linspace(0, 1, 10)]).T
y = np.sin(2*np.pi*x)

Pred, Erro, Epochs = nn.metropolis(x, y,
                                   batch_size=5,
                                   bach_epochs=100,
                                   max_epochs=100000, 
                                   tE0=0.1,
                                   decay_rate=1e-3,
                                   tEmin=1e-2,
                                   delta_bias=1e-2,
                                   delta_weight=1e-2,
                                   Error_threshold=1e-8)
print("Erro:\n", Erro)
print("Epochs:\n", Epochs)

x2 = np.array([np.linspace(0, 1, 100)]).T
y2 = nn.predict(x2)

plt.figure(figsize=(8, 4))

plt.subplot(121)
plt.title('Prediction vs Data')
plt.plot(x, y, 'o', label='Data')
plt.plot(x, Pred, 'o', label='Training')
plt.plot(x2, y2, '-', label='Prediction')
plt.xlabel('x (input)')
plt.ylabel('y (output)')
plt.legend()

plt.subplot(122)
plt.title('Error vs Epochs')
plt.loglog(nn.Errors)
plt.xlabel('Epochs')
plt.ylabel('Error (log scale)')

plt.tight_layout()
plt.show()
