import numpy as np
from timeit import default_timer as timer

def mc_count(N):
    # sample N random numbers
    x = np.random.rand(N)
    y = np.random.rand(N)
    # vetorized check if < 1 and sum
    return np.sum(1*(x**2 + y**2 < 1))

# define number of samples
Ntot = 1000000000
splits = 10

# start the timer
t0 = timer()

Nin = 0
for i in range(splits):
    Nin = mc_count(int(Ntot/splits))

# stop the timer
t1 = timer()

print("Pi = ", 4.0*Nin/Ntot)
print(" t = ", t1 - t0, "s")