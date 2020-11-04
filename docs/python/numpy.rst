Introduction to numpy
=====================

First of all, we'll always ``import numpy as np``, so all numpy commands start with ``np.``. 

These are good tutorials to complement our discussion:

- https://numpy.org/devdocs/user/quickstart.html

- https://www.w3schools.com/python/numpy_intro.asp

- https://www.tutorialspoint.com/numpy/index.htm

Together with **scipy**, **numpy** is one of the most essential libraries in python scientific computing, as it provides

- N-dimensional arrays (lists / matrices / tensors)
- Easy broadcasting of functions over lists
- Linear Algebra
- Fourier transforms
- Random numbers and matrices
- ...

Numpy documentation
-------------------

Always check the `official numpy documentation <https://numpy.org/doc/stable/reference/index.html>`_, I'll list useful links here:

- `Mathematical functions: <https://numpy.org/doc/stable/reference/routines.math.html>`_ trigonometric, hyperbolic, sums, products, gradient, dot and cross products, exponential and log, mod/remainder, real, imag and conjugate, ...

- `Array creation <https://numpy.org/doc/stable/reference/routines.array-creation.html>`_ and `array manipulation <https://numpy.org/doc/stable/reference/routines.array-manipulation.html>`_ to create and manipulate lists, vectors and matrices.

- The `fast Fourier transform <https://numpy.org/doc/stable/reference/routines.fft.html>`_.

- The `linear algebra module <https://numpy.org/doc/stable/reference/routines.linalg.html>`_ with eigenvalues/eigenvectors, linear systems, matrix decompositions, ...

- `Random number generators <https://numpy.org/doc/stable/reference/random/index.html>`_

- ...

Broadcasting
------------

This term refers to the action of the numpy functions over lists and arrays. Check this example:

.. code-block:: python
    :caption: Example: broadcasting arrays
    :linenos:

    import numpy as np
    
    # define two arrays for the example
    x = np.array([0, 1, 2, 3, 4])
    y = np.array([5, 6, 7, 8, 9])

    # let's test some broadcasting
    print('result 1 =', x * y)
    print('result 1 =', x / y)
    print('result 1 =', np.sin(x))
    print('result 1 =', np.exp(x) * np.log(y))

In all cases above, notice that the operations and functions act on all elements of the arrays **element-wise**. For instance, the code ``z = x * y`` would be equivalent to this cumbersome C-like code:

.. code-block:: python
    :caption: Example: element-wise operation without broadcasting
    :linenos:

    import numpy as np
    
    # define two arrays for the example
    x = np.array([0, 1, 2, 3, 4])
    y = np.array([5, 6, 7, 8, 9])

    # init z as a 5-element array with zeros
    z = np.zeros(5)

    # loop over the elements to apply z = x * y
    for i in range(5):
        z[i] = x[i] * y[i]

    # print the result and compare with the broadcasting
    print('without broadcasting: ', z)
    print('   with broadcasting: ', x * y)

So, the broadcasting makes the code easier to read, avoiding the unnecessary *for loop*. But that's not all! The **most important** feature here is that the **broadcasting is fast!** Since python is an interpreted language, **loops are slow** (typically), so we should always try to avoid loops and favor broadcasts. The trick here is that the broadcast is efficiently implemented within the numpy code.

Broadcasting with user defined functions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

What about the functions that we implement? Will they also run broadcasts? That depends. If the function operation only uses numpy arrays and numpy calls, it will probably allow for broadcast. Check this example:

.. code-block:: python
    :caption: Example: broadcast with user defined function
    :linenos:

    import numpy as np
    import matplotlib.pyplot as plt

    # sums the n first terms of the geometric geometric_series
    # for f = 1/(1-x) for |x| < 1
    def geometric_series(x, n):
        f = 0*x # init as zero
        for i in range(n):
            f += x**i # sum each term
        # return the sum
        return f

    # define an x array
    x = np.linspace(-0.99, 0.99, 100)

    # sum up to order 10
    fa = geometric_series(x, 4)

    # exact result for comparison
    fe = 1/(1-x)

    # plot results to compare
    plt.figure()
    plt.plot(x, fa, label='approximation')
    plt.plot(x, fe, label='exact')
    plt.legend()
    plt.grid()
    plt.ylim(0,3)
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.tight_layout()
    plt.show()

Above, our ``geometric_series(x, n)`` works fine and broadcasts the calculation over the array *x*, but *n* has to be an integer. If you try to call ``geometric_series(x, [3,4])`` passing a list on the second argument for *n*, it will fail because within our function *n* is explicitly used as an integer, while *x* is always compatible with a numpy array.

**VECTORIZING A FUNCTION**

It's possible to convert an incompatible function into a version that accepts broadcasting. But let's use it only in simple cases. Here I'll reproduce one great example from the `numpy documentation <https://numpy.org/doc/stable/reference/generated/numpy.vectorize.html>`_:

.. code-block:: python
    :caption: Example: vectorizing a function
    :linenos:

    import numpy as np

    def difforsum(a, b):
        # return a-b if a>b, otherwise return a+b
        if a > b:
            return a - b
        else:
            return a + b

    # vectorize the function
    vdifforsum = np.vectorize(difforsum)

    print("this works: ", vdifforsum([1, 2, 3, 4], 2))
    print("this works: ", vdifforsum(2, [1, 2, 3, 4]))
    print("this works: ", vdifforsum([1, 2, 3, 4], [1, 2, 3, 4]))
    print("this fails: ", difforsum([1, 2, 3, 4], 2))

Notice that the vectorized function will work if: (i) one argument is an array/list and the other a scalar (int or float); or (ii) both arguments are arrays/lists with the same number of elements. 

Arrays, vectors and matrices
----------------------------

A vector is a 1D array, for instance :math:`\vec{r} = (x, y, z)` is a vector with components ``x = r[0]``, ``y = r[1]`` and ``z = r[2]``, which require only one index ``r[i]``. A matrix is a 2D array (it has lines and columns), thus it requires two indices: for a matrix *M*, the i-th line and j-th column is indexed by ``M[i, j]``. Remember that indexes start from 0. So, the first component of the vector **r** is ``r[0]`` and the *M* matrix element in line 3 column 5 is ``M[2,4]``. Be careful!

There are many ways to define a vector:

.. code-block:: python
    :caption: Example: different forms of defining the same vector
    :linenos:

    import numpy as np

    # explicit definition
    x = np.array([0, 1, 2, 3, 4])

    # using arange (initial, final not included, step)
    y = np.arange(0, 5, 1)

    # using linspace (initial, final included, number of elements)
    z = np.linspace(0, 4, 5)

    # check if they match
    print('x =', x)
    print('y =', y)
    print('z =', z)

**ACCESS THE ELEMENTS OR PART OF THE ARRAY**

As shown above, to access the i-th element of an array you call ``x[i-1]``. But you can also refer to section of an array using the form ``x[i:f:s]``, where *i* refers to the initial index, *f* the final index and *s* the step. If you omit *s*, it's assumed *s=1*, and similarly the default values for the other indexes are *i=0* and *f=-1*, which refers to the first and last elements. See how these work in this example:

.. code-block:: python
    :caption: Example: access elements of an array
    :linenos:

    import numpy as np

    x = np.linspace(15, 30, 61)

    print('first 10 elements: ', x[0:10])
    print('first 10 elements: ', x[:10])

    print('the last element: ', x[-1])

    print('the last 10 elements: ', x[-10:])

    print('every 4 elements: ', x[::4])

    print('some from the middle: ', x[10:15])

    print('all elements: ', x)
    print('all elements: ', x[:])

**MATRICES**

Matrices are similar to arrays, but with two indices for the lines and columns. There are many functions to help you build matrices, we'll check these later. For now, let's define a simple matrix and check how to access its elements in this example:

.. code-block:: python
    :caption: Example: defining and accessing matrix elements
    :linenos:

    import numpy as np

    # define a matrix explicitly
    m = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    print('the matrix is: \n', m)

    print('the second line is: ', m[1, :])

    print('the third column is: ', m[:, 2])

    print('the last column is: ', m[:, -1])

    print('the element at the center is: ', m[1,1])

    print('extracting a 2x2 block: \n', m[1:3, 1:3] )

    print('or the same as: \n', m[1:, 1:] )


Useful functions to build arrays, vectors and matrices
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Always check `documentation on array creation <https://numpy.org/doc/stable/reference/routines.array-creation.html>`_ for more details. Here I'll list the methods that I believe to be more useful:

- ``np.eye(N, k)``: builds an NxN matrix with 1 all over the k-th diagonal. Try to run ``np.eye(5)`` and ``np.eye(5, k=3)`` to check how it works.

- ``np.ones(shape)``: returns a matrix or array fill with 1. Try running ``np.ones(3)``, ``np.ones([3, 5])`` and ``np.ones([3,3])``.

- ``np.zeros(shape)``: exactly like *ones* above, but fills with zeros.

- ``np.arange(start, stop, step)``: we have seen this one above. If omitted, the default values are *start=0* and *step=1*. Remember that at the end *stop* is not included, the interval is *[start, stop)*.

- ``np.linspace(start, stop, num)``: as seen above, in this case *stop* is included! Here the last argument is the number of elements instead of the step between elements as in *arange*.

There are many other methods, please check the full `numpy reference <https://numpy.org/doc/stable/reference/index.html>`_ for more information. Later, as we solve physics problems we may discuss other useful calls.

Linear Algebra
--------------

The numpy `linear algebra documentation <https://numpy.org/doc/stable/reference/routines.linalg.html>`_ has a lot of useful tools. We'll discuss only a few here.

Vector and matrix operations
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Besides adding and multiplying arrays via broadcasting, we need to know how to operate with mathematical tools like: dot and cross products, matrix-vector multiplication, matrix-matrix multiplication, etc.

**VECTOR-VECTOR OPERATIONS**

Let's jump straight into an example:

.. code-block:: python
    :caption: Example: vector operations
    :linenos:

    import numpy as np

    x = np.array([1, 0, 0])
    y = np.array([0, 1, 0])
    
    z = np.cross(x, y)
    print('the cross product is:', z)

    d = np.dot(x, y)
    print('the dot product is:', d)

    p = x * y
    print('this is a element-wise multiplication: ', p)

.. warning::
    Notice above that the mathematical cross product :math:`\vec{z} = \vec{x} \times \vec{y}` and dot product :math:`d = \vec{x} \cdot \vec{y}` requires a proper call to ``np.cross`` or ``np.dot``, while a simple array multiplication ``x * y`` is simply an element-wise broadcast.

    The same happens with matrices, as we see below.

Additionally, in **quantum mechanics** or it is important to define the scalar dot product as :math:`n = \langle a | b \rangle = \sum_i a_i^* b_i`, where the \* refers to complex conjugation. In this case the correct call is ``n =  np.vdot(a, b)``, since the *vector dot product* conjugates *a* for you.

**MATRIX-MATRIX OPERATIONS**

If *A* and *B* are matrices, we may want to calculate :math:`C = A \cdot B`, where the matrix product here is the usual *line times column* multiplication. But we must be careful because *A \* B* means an element-wise multiplication. Let's check these and other examples:

.. code-block:: python
    :caption: Example: matrix operations
    :linenos:

    import numpy as np

    # let's use simple 2x2 matrices
    A = np.array([[0, 1], [1, 0]])
    B = np.array([[1, 2], [3, 4]])

    print('the matrix product is: \n', np.dot(A, B))

    print('which can be written as: \n', A @ B)

    print('while this is an element-wise multiplication: \n', A * B)

Similarly, ``A**2`` is an element-wise power of the elements of *A*, while the actual matrix power is set by ``np.linalg.matrix_power(A, 2)``. 

.. code-block:: python
    :caption: Example: matrix operations
    :linenos:

    import numpy as np
    
    # let's use simple 2x2 matrices
    A = np.array([[0, 1], [1, 0]])

    print('the element-wise power is: \n', A**2)

    print('the actual matrix power is: \n', np.linalg.matrix_power(A, 2))

    print('the determinant is: ', np.det(A))

    print('the inverse is: \n', np.inv(A))

    # the matrix power call is long, so let's use an alias
    from numpy.linalg import matrix_power as mpow

    print('now the matrix power is: \n', mpow(A, 2))

One of the most important matrix operations are the **eigen-problems**. Let's check it:

.. code-block:: python
    :caption: Example: matrix operations
    :linenos:

    import numpy as np
    
    # let's use simple 2x2 matrices
    A = np.array([[0, 1], [1, 0]])

    # calculate only eigenvalues
    evals = np.linalg.eigvalsh(A)
    print('the eigenvalues are: ', evals)

    # calculate both eigenvalues and eigenvectors
    evals, evecs = np.linalg.eigh(A)
    print('the eigenvalues are: ', evals)
    print('the first eigenvector: ', evecs[:,0])
    print('the second eigenvector: ', evecs[:,1])

Above *A* is an Hermitian matrix (:math:`A^\dagger = A`), we use call *eigvalsh* and *eigh*, which are optimized for Hermitian matrices. Otherwise we would have to call *eigvals* or *eig*. The matrix in the example has two eigenvalues: +1 and -1, and the corresponding eigenvectors are shown above. Notice that the eigenvectors are returned as a matrix *evecs* such that the i-th eigenvector is on the i-th row: *evecs[:,i]*.

**MATRIX-VECTOR OPERATIONS**

A typical example is the solution of the problem :math:`A\cdot X = B`, where *A* is a matrix, *B* a vector and *X* an unknown vector. If *A* is non-singular, the solution is :math:`X = A^{-1} \cdot B`. But in practice, for large matrices, it is better to call the **linear system solver** as shown below Here I'll use the example from numpy's webpage. Consider the linear system of equations

.. math::
    3 x_0 + x_1 = 9,
    
    2 x_1 + x_0 = 8,

and rewrite it as

.. math::
    \begin{pmatrix}
        3 & 1 \\
        1 & 2
    \end{pmatrix}
    \begin{pmatrix}
        x_0 \\ x_1    
    \end{pmatrix}
    =
    \begin{pmatrix}
        9 \\ 8
    \end{pmatrix}

The code below solves the problem with two approaches.

.. code-block:: python
    :caption: Example: linear system of equations
    :linenos:

    import numpy as np

    A = np.array([[3, 1], [1, 2]])
    B = np.array([9, 8])

    # solve using the linear system solver
    X = np.linalg.solve(A, B)
    print('the solution is:', X)

    # is the same as applying the inverse
    X = np.linalg.inv(A) @ B
    print('the solution is:', X)

The solution with the inverse or with the *solve* method match. But the solve method is more efficient for large matrices. Notice that we use *@* for the matrix-vector multiplication, but we could've used ``X = np.dot( np.linalg.inv(A), B)`` instead, its the same.

In **quantum mechanics** we often need to calculate expected values of operators like :math:`a = \langle X | A | Y \rangle`, where *X* and *Y* are state vectors, and *A* is a matrix representing some operator. The correct call here is a bit cumbersome: ``a = np.vdot(X, np.dot(A, Y))``.

Random numbers
--------------

The generation of (pseudo-)random numbers is essential in computational physics. It's the roots of Monte Carlo integrations and random walks codes. We'll see more details about how to use random numbers in the next chapters. For now, let's simply check how to generate them.

A random number is defined by its distribution. For instance, an uniform random number generator in the domain [0,1) must return random numbers in this interval with equal probability. Let's check it by plotting an histogram:

.. tabs::

    .. tab:: Histogram for uniform distribution

        .. image:: ./figs/random-hist.png
            :width: 75%
            :align: center

    .. code-tab:: py The code
        :linenos:

        import numpy as np
        import numpy.random as rng
        import matplotlib.pyplot as plt
        plt.rcParams.update({'font.size': 16})

        # generates a list with 1000 random numbers
        n = 1000
        x = rng.rand(n)

        plt.figure(figsize=(8,4))

        # plot the samples
        plt.subplot(121)
        plt.plot(x, 'o')
        plt.xlabel('sample')
        plt.ylabel('random number')

        # and its histogram
        plt.subplot(122)
        plt.hist(x, rwidth=0.8)
        plt.xlabel('random number')
        plt.ylabel('occurences')

        plt.tight_layout()
        plt.show()

Above the command ``rng.rand(n)`` generates *n* random numbers with an uniform distribution in the interval [0,1), and the matplotlib commmand ``plt.hist(x)`` automatically generates the histogram counting how many numbers fall into each interval. Try increasing or decreasing the number of samples *n*.

At the `random documentation <https://numpy.org/doc/stable/reference/random/generator.html>`_ you'll find other distributions, like the ones below:

.. tabs::

    .. tab:: Exponential distribution

        .. image:: ./figs/random-hist-exp.png
            :width: 75%
            :align: center

    .. tab:: Normal/gaussian distribution

        .. image:: ./figs/random-hist-normal.png
            :width: 75%
            :align: center            
    
    .. tab:: Poisson distribution

        .. image:: ./figs/random-hist-poisson.png
            :width: 75%
            :align: center            

You can also randomize lists with the ``rng.shuffle`` command, or select a random element from a list with the ``rng.choice`` or ``rng.permutation``. Try using these!

Save and read data from files
-----------------------------

TO DO: 

- ``np.savetxt`` and ``np.loadtxt`` for readable files
- ``np.save`` and ``np.load`` for binary files