#!/usr/bin/python

import numpy as np
import time

for n in range(500):
    A = np.random.rand(n,n)
    B = np.random.rand(n,n)

    t0 = time.process_time()
    C = A @ B
    t1 = time.process_time()

    print(n, t1-t0)
