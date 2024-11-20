import numpy as np
from timeit import default_timer as timer


for n in range(3, 2500, 100):

    h = 2*np.eye(n) - np.eye(n, k=1) - np.eye(n, k=-1) 

    t0 = timer()
    w, v = np.linalg.eigh(h)
    t1 = timer()

    print(n, t1-t0)