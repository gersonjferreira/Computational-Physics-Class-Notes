# High Performance Computational Physics

Class notes and codes for the **high performance computational physics @ UFU**.

**Prerequisite:** basic knowledge of some computer language (C, Fortran or Python), calculus and linear algebra. The classes and videos are in Portuguese, but all notes are written in English so we practice it. 

**Goal:** (i) learn how to install and use a Linux cluster; (ii) write high performance codes in C using Lapack, FFTW, openMP, and MPI; (iii) solve physics problems using parallel computing. 

**Complementary achievements:** (i) learn how to use git; (ii) write python wrappers for the C code using Cython.

**The classes:** we have a 14-computers cluster at our disposal to install Linux (Debian) and set it up to work as a cluster (*except this year due to the COVID-19 pandemic*). Next we revise the C language basics and learn how to solve traditional problems using a single process (e.g. calculate $`\pi`$ using Monte Carlo, the Ising model, Laplace equation, molecular dynamics, ...). Then we learn how to parallelize these codes using threads, openMP and MPI.

**Plans for the future:** (i) Either buy GPUs or ask to use computer time somewhere else; (ii) I'm not sure if we should have machine/deep learning as a topic here, or propose a new class dedicated to it.

## References

First I'll list a few online tutorials, and below I list interesting books and papers.

**Online tutorials**

- [C programming on Tutorials Point](https://www.tutorialspoint.com/cprogramming/index.htm)
- [Introduction to the bash terminal on StackAbuse](https://stackabuse.com/introduction-to-bash/)


**Computational Physics** 

- T. PANG. An introduction to computational physics. Cambridge University Press, 2006.

**The C language**

- A. BACKES (**FACOM/UFU**). Linguagem C: Completa e Descomplicada (2013)
- B. W. KERNIGHAN, D. M. RITCHIE. C: a linguagem de programação. Campus, EDISA (1986).

**Parallel programming**

- F. ESQUEMBRE, W. CHRISTIAN, M. BELLONI. Parallel programming with Easy Java Simulations. [Am. J. Phys. 86, 54 (2018)](https://doi.org/10.1119/1.5012510).
- C. REBBI. A project-oriented course in computational physics: Algorithms, parallel computing, and graphics. [Am. J. Phys. 76, 314 (2008)](http://dx.doi.org/10.1119/1.2839093).
- W. P. PETERSEN, P. ARBENZ - Introduction to parallel computing [a practical guide with examples in C]. Oxford University Press (2004).
- T. RAUBER. Parallel programming: for multicore and cluster systems. Berlin, Springer-Verlag, 2010.

**Details of the operational system**

- A. S. TANENBAUM. Sistemas operacionais modernos. São Paulo, Prentice Hall, 2003.

## Index for the class notes, videos and exercies

0. **Installing a Debian cluster**

Due to the COVID-19 pandemic we had to change plans mid-course. We won't have physical access to the cluster, nor enough time to configure it from scratch as planned. Therefore this year we'll focus on the codes, and on a next opportunity I'll write notes on how to configure the cluster. For now, [incomplete notes can be found here](DebianCluster).

1. **Installing the compilers and libraries**

We'll need a C compiler working with [openMP](https://en.wikipedia.org/wiki/OpenMP) and the libraries [FFTW](https://en.wikipedia.org/wiki/FFTW), [Lapack](https://en.wikipedia.org/wiki/LAPACK), [open MPI](https://en.wikipedia.org/wiki/Open_MPI), and [openBLAS](https://www.openblas.net). Check the notes on [how to install these on Linux and Windows](CompilersAndLibs). To test the compilers and libraries, [try these examples](CompilersAndLibs/testing.md).

2. **Integrated development environment (IDE)**

Let's use the [VS Code IDE](https://code.visualstudio.com/) since it is awesome and works equally well on Linux, Windows and Mac; and works with many languages (C, python, markdown, Latex, ...). Install these extensions: **C/C++ InteliSense** and **Python**. I also use and recommend the extensions: Markdown Preview Enhanced, Code Spell Checker, Git Graph, Language-Cython. On Windows 10 with WSL, install the extension **Remote - WSL**.

Initially we'll use **makefiles** to compile our codes in the bash terminal. This will allow us to understand a bit better how the compiler works and how to pass flags. Check the **C intro** below for how to use makefiles. Later we'll check how to compile using the VS Code interface directly.

3. **The C language**

The class notes [here](IntroC/) contains: 

- compiled vs interpreted languages; an introduction (hello world, variables, math, complex, functions and scope); loops, sums, integrals: [[youtube]](https://www.youtube.com/watch?v=6sgL0-s33KA); pointers and passing arguments by reference or value; arrays and matrices; input & output; using a makefile to compile; complexity of an algorithm: measure time vs N and the Big O notation; optimization and compilation flag; ...

4. **Python**

Our course is about C and HPC. We will only use **python/matplotlib** to plot our results. Check the [notes here](IntroPython/). Alternatively, for a non-python plot you can use: [gnuplot](http://gnuplot.info) or [qtiplot](https://www.qtiplot.com). 

Here's a simple example on how to write a **[C-to-python wrapper](https://gitlab.com/gersonjferreira/c2python-wrapper)** including how to pass and receive strings, numbers and numpy arrays.

5. **Physics problems to implement numerically**

These are the problems that I recommend as examples and exercises. First try to implement then sequentially and later let's parallelize with openMP and openMPI.

- Monte Carlo integration: to find $`\pi`$
- Using the Fourier transforms to solve ODEs
- Using Lapack to solve ODEs
- Using Lapack to solve linear systems
- Laplace's equation in 2D with boundaries: time-evolution and stationary solution
- Schrödinger equation: time-evolution and the split-operator method
- Molecular dynamics: Lennard-Jones vs contact collisions
- The Ising model
- **Cellular automata and random walk: COVID-19 model**
- ...

6. **The libraries and parallel programming**

> Due to the short *pandemic*-course we won't have time to learn **openMPI**, but I'll prepare notes on this topic eventually.

- To implement codes with multi-core parallel processing on a single computer we use **OpenMP**. Check the [class notes on openMP](OpenMP/) and try to implement numerical integrals in parallel.

- For linear algebra check the class notes on [openBLAS](OpenBLAS) and [Lapack](Lapack):

  - **OpenBLAS** provides low level arithmetic for matrix and vector operations, like matrix-matrix or matrix-vector multiplication.

  - **Lapack** provides higher level linear algebra: matrix factorizations, eigenproblems, etc.

- For numerical Fourier transforms we'll use the [FFTW library](FFT).

Other useful libraries to go deeper:

- [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/) provides almost everything we may need. Quoting their webpage: "*GSL provides a wide range of mathematical routines such as random number generators, special functions and least-squares fitting*". But I recommend you use openBLAS, Lapack and FFTW for their expertise, and go for GSL only for other functions.

- [Boost C++](https://www.boost.org) also is quite extensive. Quoting [Wikipedia](https://en.wikipedia.org/wiki/Boost_(C%2B%2B_libraries)): "*Boost provides support for tasks and structures such as linear algebra, pseudorandom number generation, multithreading, image processing, regular expressions, and unit testing. It contains 161 individual libraries.*". The only problem is that the documentation is not well organized and this library is not very stable, when something change versions, things break. So I don't like to use it.

- [GNU Multiple Precision Arithmetic Library (GMP)](https://gmplib.org) provides arbitrary-precision arithmetic. If your code needs float precision beyond double and quad (long double), try GMP.

- [ScaLAPACK](http://www.netlib.org/scalapack/) provides a Lapack implementation for parallel distributed memory machines. That is, it allow us to parallelize linear algebra codes to run in parallel on different machines. Requires MPI.

- [Armadillo](http://arma.sourceforge.net/docs.html) combines Lapack, FFT, openBLAS and other quite useful features on a simple vectorized notation in C++.

---