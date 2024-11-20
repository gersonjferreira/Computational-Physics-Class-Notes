# Lapack

Lapack is the **L**inear **A**lgebra **Pack**age that implements efficiently many operations like matrix factorizations/decompositions, solves linear systems, eigenvalue problems, SVD, ...

**Installing**

On Debian/Ubuntu, install the following packages:

```bash
$ sudo apt update
$ sudo apt install liblapacke-dev
```

The **lapacke** provides the C interface to Lapack. The *-dev* packet already installs everything you might need here. It already includes the *liblapack-doc* package that installs the man pages for both Lapack and BLAS, and PDF file for the LAPACKE C interface (lapacke), which will be located at `/usr/share/doc/liblapack-dev/lapacke.pdf.gz`.

On Manjaro/Arch, install:

```bash
$ sudo pacman -Syy
$ sudo pacman -S lapacke lapack-doc
```

**The header file**

It's sufficient to `#include <lapacke.h>`, which contains all C interfaces to the Lapack library.

**Compile and link the library**

To compile, call the linker with `-llapacke`.

```bash
$ gcc -llapacke mycode.c
```

## References

- The [Lapack official page](http://www.netlib.org/lapack/) has the full documentation, particularly, check:
  - The [reference guide](http://www.netlib.org/lapack/explore-html/)
  - The [User's guide](http://www.netlib.org/lapack/lug/)
- The [Intel MKL webpage](https://software.intel.com/content/www/us/en/develop/documentation/mkl-developer-reference-c/top/lapack-routines.html) is really well organized and has everything!
- Never forget there's always a good [Wikipedia page](https://en.wikipedia.org/wiki/LAPACK).

## Example

Let's take a look at [how to solve a linear system (linearsys.c)](Examples/linearsys.c). Consider the *A* an *NxN* matrix and *B* a *N*-vector, and we want the *N*-vector *X* that solves `A.X=B`, a linear equation. Check the details on the file [linearsys.c](Examples/linearsys.c), where we'll describe on the main aspects of the code there.

There, *A* is a linearized matrix of floats, and *B* a a float vector. Following the Lapack/BLAS naming conventions, *float = s* (prefix for the functions). We also define a integer vector *ipiv* and an integer *info*, which we discuss below.

To solve the linear system we use the **driver** SSYSV. Here the first **S** refers to the *float* vars, then **SY** refers to a symmetric matrix, and **SV** refer to the type of operation, in this case it specifies that it solves a linear system (why SV = linear system? I don't know...).

To call the function we add the prefix for the C interface *LAPACK_* as:

```c
info = LAPACKE_ssysv(LAPACK_COL_MAJOR, 'U', 3, 1, A, 3, ipiv, B, 3);
```

Checking the documentation, you'll see that its prototype is:

```c
lapack_int LAPACKE_ssysv (int matrix_layout, char uplo, lapack_int n, lapack_int nrhs, float *a, lapack_int lda, lapack_int *ipiv, float *b, lapack_int ldb);
```

The parameters here are:

**[int matrix_layout]:** defines if the matrices are stored in [row- or column-major order](https://en.wikipedia.org/wiki/Row-_and_column-major_order). Use either `LAPACK_ROW_MAJOR` or `LAPACK_COL_MAJOR`.

**[char uplo]:** since it matrix is symmetric, it is sufficient to store only its upper (`'U'`) or lower (`'L'`) triangle.

**[lapack_int n]:** Order of matrix A

**[lapack_int nrhs]:** Number of right-hand-sides of B, which is usually a vector (`nrhs=1`), but could be a matrix and the equation `A.X=B` would be solved for each column of B, and each column of X would be a solution.

**[float \*a]:** The matrix A (on input). The code will overwrite A with the matrix D used to define the LU factorization as `A = L.D.U`.

**[lapack_int lda]:** The leading dimension of A. See the [row/col-major order definitions at the OpenBLAS notes](/OpenBLAS/) for more details.

**[lapack_int \*ipiv]:** (output) an array of size *n* with details of the LU decomposition matrix D.

**[float \*b]:** The vector/matrix B (on input). The code will overwrite B with the solution X.

**[lapack_int ldb]:** The leading dimension of B. See the [row/col-major order definitions at the OpenBLAS notes](/OpenBLAS/) for more details.

The function also returns an integers **info**, which informs the status of the calculation. If successful, *info=0*. To understand the error code if *info* is not zero, please check the documentation of the function being called.

## Naming conventions and types of routines

Lapack implements two types of routines/functions. The **driver** routines solve complete problems (e.g., eigenvalue problems, linear systems), while the **computational** routines perform specific tasks (e.g. LU factorization). A **driver** will call the **computational** routines to perform the complete operation.

Within the **drivers** there are also two versions: (i) the **simple driver** like the *-SV* used above to solve a linear system; or (ii) the **expert driver** (e.g. *-SVX*), which allows for extra features and fine tunning. For instance, if *A* is not symmetric, an expert driver would allow you to solve both A.X=B and A<sup>T</sup>.X=B, without having to actually transpose A.

All routines follow the same **naming convetion** as XYYZZZ. The first letter (X) refers to the data type:

- S for float
- D for double
- C for complex
- Z for double complex

The YY section refers to the type of matrix. Fo instance, SY for a symmetric matrix, HE for Hermitian, ST for symmetric-tridiagonal. To see all possible types, [check the Lapack documentation](http://www.netlib.org/lapack/lug/node24.html).

The ZZZ specifies the task. Above, SV and SVX refers to the linear system problem in the simple and expert drivers. The list is long, [check the documentation](http://www.netlib.org/lapack/lug/node25.html) for more.




