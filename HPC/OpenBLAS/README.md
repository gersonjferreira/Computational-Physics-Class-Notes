# OpenBLAS

OpenBLAS (**B**asic **L**inear **A**lgebra **S**ubprograms) provides low level arithmetic for matrix and vector operations, like matrix-matrix or matrix-vector multiplication.

**Installing**

On Debian/Ubuntu, install the following packages:

```bash
$ sudo apt update
$ sudo apt install libopenblas-dev
```

On Manjaro/Arch, install:

```bash
$ sudo pacman -Syy
$ sudo pacman -S openblas cblas
# ALTERNATIVE: build openblas-lapack from AUR 
$ sudo pamac build openblas-lapack
```

**The header file**

On Debian/Ubuntu, the header file is `cblas-openblas.h`, while on Manjaro/ARch it is simply `cblas.h` (please check yours). In all cases, it should be located within the default PATH for header files in gcc, so you can simply include it as

```c
...
#include <cblas-openblas.h> // Debian/Ubuntu
#include <cblas.h> // Manjaro/Arch
...
```

**Compile and link the library**

On Debian/Ubuntu the OpenBLAS library is linked with the flag `-lopenblas`, while for Manjaro/Arch, use also `-lcblas`:

```bash
# on Debian/Ubuntu
$ gcc -lopenblas mycode.c
# on Manjaro/Arch
$ gcc -lopenblas -lcblas mycode.c
```

## References

- [The OpenBLAS webpage](https://www.openblas.net) contains the documentation.
- [The BLAS reference manual](http://netlib.org/blas/) has the description of all routines in Fortran notation. 
- For their description within CBLAS, the best source is the [Lapack reference webpage](http://www.netlib.org/lapack/explore-html/). Go to `File > File list > CBLAS > src` and find the CBLAS interface for the BLAS routine you want to use. Typically it will have the same prototype with one extra parameter. Pay attention!
- The [Intel MKL webpage](https://software.intel.com/content/www/us/en/develop/documentation/mkl-developer-reference-c/top/blas-and-sparse-blas-routines.html) has the most well organized documentation for the **CBLAS interface**.

## Example

At the OpenMP folder we have implemented the matrix multiplication as an [example of code](/OpenMP/Examples/matrix_multiplication/) that could be parallelized. There we use OpenBLAS, check it! There we use two functions from OpenBLAS, let's see how they work.

First, if your OpenBLAS is compiled with OpenMP (it probably is), you can set the number of threads with:

```c
openblas_set_num_threads(4);
```

On Manjaro I had to define an `extern` prototype because the CBLAS does not include this function in their header:

```c
extern void openblas_set_num_threads(int);
```

The matrix multiplication `C = A x B` is called as

```c
cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1, A, n, B, n, 0, C, n);
```

To understand the parameters, check the BLAS reference link above and look for the `sgemm` function. On `cblas.h`, its prototype is

```c
void cblas_sgemm(CBLAS_LAYOUT layout, CBLAS_TRANSPOSE TransA,
                 CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const float alpha, const float *A,
                 const int lda, const float *B, const int ldb,
                 const float beta, float *C, const int ldc);
```

The xGEMM actually implements $`C = \alpha A \cdot B + \beta C`$ with options to transpose A and B. The parameters for `sgemm` there are:

**[CBLAS_LAYOUT layout]:** defines if the matrices are stored in [row- or column-major order](https://en.wikipedia.org/wiki/Row-_and_column-major_order). There are two CBLAS parameters predefined to choose: `CblasRowMajor=101` or `CblasColMajor=102`.

For **column-major** and **row-major** orders the matrices are stored as 

- ColMajor: `Aij = a[i + j*lda]`
- RowMajor: `Aij = a[i*lda + j]`

Here `lda` refers to the leading dimension of the array. For ColMajor it is the number of lines, and for RowMajor the number of columns.

**[CBLAS_TRANSPOSE TransA]**
**[CBLAS_TRANSPOSE TransB]:** Indicates if the matrices should be assumed as transposed during the calculation. For instance, if you have defined the matrices `A`  and `B`, but the calculation you need is C = A<sup>T</sup>B, you don't need to transpose `A`, it is sufficient to flip the indexes, and BLAS does that for you already. The options are:

- CblasNoTrans=111 : default, do nothing
- CblasTrans=112 : transpose the matrix
- CblasConjTrans=113 : conjugate-transpose the matrix

**[const int M]:** number of rows in A (or in A<sup>T</sup>), must also match number of rows in C. 

**[const int N]:** number of columns in B (or in B<sup>T</sup>), must also match number of columns in C.

**[const int K]:** number of columns in A and rows in B, or equivalently in their transpose forms.

**[const float alpha]:** value of $`\alpha`$, see above.

**[const float \*A]:** the matrix A.

**[const int lda]:** the leading dimension of A, see the row/col-major order definitions above.

**[const float \*B]:** the matrix B.

**[const int ldb]:** the leading dimension of B, see the row/col-major order definitions above.

**[const float beta]:** value of $`\beta`$, see above. 

**[float \*C]:** the matrix C.

**[const int ldc]:** the leading dimension of C, see the row/col-major order definitions above.


## Naming conventions

To understand the names of the BLAS functions, please check the [MKL webpage](https://software.intel.com/content/www/us/en/develop/documentation/mkl-developer-reference-c/top/blas-and-sparse-blas-routines/blas-routines/naming-conventions-for-blas-routines.html) for more details. I'll list here some examples.

All BLAS functions follow the same structure as `x<name><mod>`. For instance, above we use `sgemm`, where `x=s`, `<name>=ge` and `<mod>=mm`. The meaning of these are:

- `x = s` for float (single precision); `= d` for double; `= c` for complex (single precision); `= z` for double complex.

- `<name>` on BLAS level 2 and 3 defines the type of matrix, with `= ge` for the general case; `= sy` for symmetric matrices; ` = he` for Hermitian; ...

- `<mod>` defines details of the operation. For instance `= mv` indicates a matrix-vector product; `= mm` indicates matrix-matrix product; `= sv` solves a linear system; ...

