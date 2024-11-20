# Testing the compiler and libs

I'm assuming you are using the GCC compiler either on Linux or on Windows via MSYS2+MinGW [^adapted] or WSL+Debian. But the codes listed here should work also on Cygwin, WSL and Intel Compilers.

[^adapted]: These notes were adapted from the notes on [Prof. Dr. Wotao Yin's UCLA webpage](https://www.math.ucla.edu/~wotaoyin/windows_coding.html).

The codes below use openMP, FFT, Lapack and MPI. We'll study all these throughout the course. For now you don't need to understand all these codes and commands, let's just make sure everything works. But here's a first suggestion for you to study ahead:

- Follow a `bash terminal` tutorial: [Ryan's tutorials](https://ryanstutorials.net/bash-scripting-tutorial/)
- Learn a bit about [git](https://en.wikipedia.org/wiki/Git)

About some of the bash commands below:

- the `$` sign is an user prompt indicating a command line
- `wget` downloads the file and saves in the current folder
- to check the current folder, run `$ pwd`. To change folders use the `cd` command.
- `export` defines an environment variable. To read the contents of an environment variable, say PATH, run `$ echo $PATH`
- `gcc` and `g++` are the C and C++ compilers
- `mpicc` and `mpiexec` are the compiler and executer for the MPI
- when you run a command, the system tries to find it on the `$PATH`. To run a binary that is not on PATH but on the current folder, we use the `./`

### openMP: Hello to many cores!

Open your terminal (**WSL** or **MSYS2+MINGW** or any **Linux**). In all cases, run:

```bash
$ wget https://computing.llnl.gov/tutorials/openMP/samples/C/omp_hello.c
$ gcc -fopenmp omp_hello.c -o omp_hello.exe
$ export OMP_NUM_THREADS=8
$ ./omp_hello.exe
```

### MPI: Hello to many nodes!

On **Linux** or **Windows with WSL**, open the terminal and run:

```bash
$ wget https://raw.githubusercontent.com/wesleykendall/mpitutorial/gh-pages/tutorials/mpi-hello-world/code/mpi_hello_world.c
$ mpicc mpi_hello_world.c -o mpi_hello.exe
$ mpiexec -n 2 mpi_hello.exe
```

On Win7 or Win8, open the **MSYS2-MINGW64 terminal** and run:

```bash
$ wget https://raw.githubusercontent.com/wesleykendall/mpitutorial/gh-pages/tutorials/mpi-hello-world/code/mpi_hello_world.c
$ gcc mpi_hello_world.c -lmsmpi -o mpi_hello.exe
$ mpiexec -n 2 mpi_hello.exe
```

### Lapack: Hello to linear algebra!

This testing code uses C++, but Lapack will work with C as well:

```bash
$ wget https://www.math.ucla.edu/~wotaoyin/software/lapack_test.cpp
$ g++ lapack_test.cpp -lopenblas -o lapack_test.exe
$ ./lapack_test.exe
```

If you are not using `openblas`, replace the library link above with `-llapack`.

### FFT: Hello to Fourier!

In this case we'll use `git` to clone a code repository.

```bash
$ git clone https://github.com/undees/fftw-example.git
$ cd fftw-example/
$ gcc fftw_example.c -lfftw3 -lm -o fftw_example.exe
$ ./fftw_example.exe
 ```

 ---