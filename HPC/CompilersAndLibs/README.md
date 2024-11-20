# Install and test the compiler and libraries

Ideally we should be working on Linux. But due to the COVID-19 pandemic, this year the students will have to work from home, so I'll try to put here instructions on how to set up the compiler and libraries on Windows as well.

The goal is to install and test:

- **A C compiler:** either [GCC](https://en.wikipedia.org/wiki/GNU_Compiler_Collection) or the [Intel Compilers](https://en.wikipedia.org/wiki/Intel_C%2B%2B_Compiler).
- **[openMP](https://pt.wikipedia.org/wiki/OpenMP):** for single node (multi-core) shared memory parallel programming.
- **[FFTW](https://en.wikipedia.org/wiki/FFTW):** The fast Fourier transform. 
- **[Lapack](https://en.wikipedia.org/wiki/LAPACK):** the linear algebra library.
- **[open MPI](https://en.wikipedia.org/wiki/Open_MPI):** message passing interface, for parallel comunication between nodes.

**On Linux** it is very easy to install gcc (with openMP), FFTW, openBLAS and openMPI. But **on Windows** it is not so easy. After testing many options, I believe that the best path is to use the new **WSL (1 or 2) system on Windows 10**. But if you use Windows 7 or 8, use the MSYS2+MinGW port for GNU on Windows. Instructions for all cases are listed below.

#### Testing the codes and install and IDE

Please first follow the instructions below to install the compiler and libraries on Linux or Windows. Later, come back here and check the [testing instructions](testing.md). In the next class we will install and test the [VS Code IDE](https://code.visualstudio.com/).

## Installing on Linux

If this is your first time using Linux, try the [Ubuntu](https://ubuntu.com/) Linux distribution (please use a LTS release!!) or [Debian](https://www.debian.org/). If you are more experienced, you might enjoy a rolling release distribution as [Manjaro](https://manjaro.org/). 

#### Installing on Ubuntu or Debian

Open the terminal and use the apt package manager to install:

```bash
$ sudo apt update
$ sudo apt install build-essential gdb make
$ sudo apt install libfftw3-3 libfftw3-bin libfftw3-dev
$ sudo apt install liblapack3 liblapacke liblapacke-dev
$ sudo apt install openmpi-bin libopenmpi-dev
$ sudo apt install git
```

#### Installing on Manjaro or Arch

Open the terminal and use the pacman package manager to install:

```bash
$ sudo pacman -Syy
$ sudo pacman -S gcc make
$ sudo pacman -S fftw
$ sudo pacman -S lapack lapacke
$ sudo pacman -S openmpi
$ sudo pacman -S git
```

## Installing on Windows

If you insist on using Windows... we have five options:


1. **On Windows 10**, the best option is the [Windows Subsystem for Linux (**WSL**)](https://en.wikipedia.org/wiki/Windows_Subsystem_for_Linux). There's a [tutorial here](https://code.visualstudio.com/docs/cpp/config-wsl). Choose the **Debian** distribution and after WSL is installed, follow the Debian instructions above to install the libraries.
2. I have a few licences for the **Intel Compilers**. But since the Intel Compiler is not free for general use, let's avoid it. But if you want to try, ask me for a license.
3. If you use **Win 7 or 8**, the best choice is the [MSYS2](https://www.msys2.org/) package manager and the [MinGW](http://www.mingw.org/) GNU port to Windows. See instructions below.
4. ~~Install the [Cygwin](https://www.cygwin.com/) GNU port to Windows~~ (**not a good option**, I've tried and it is awful!)
5. Of course the true best option is to **forget about Windows and install Linux** on a dual boot ;-)

#### Using MSYS2 and MinGW

**Warning:** The [VS Code tutorial](https://code.visualstudio.com/docs/cpp/config-mingw) uses MinGW directly. Instead, I recommend using MSYS2 to manage the packages. Later we can use that tutorial to integrate the `gcc` with VS Code. For now, please follow these instructions:

**MSYS2** is a unix-like command-line environment for Windows. It comes with the pacman package manager, which helps you install packages [^adapted].

[^adapted]: These notes were adapted from the notes on [Prof. Dr. Wotao Yin's UCLA webpage](https://www.math.ucla.edu/~wotaoyin/windows_coding.html).


(1) Go to the [MSYS2 webpage](https://www.msys2.org/) and install it following the usual "Next > Next > Done" Windows style. Now open the **MSYS2 terminal** and run these commands:

```bash
$ pacman -Syuu
$ pacman -S nano
$ pacman -S base-devel git mingw-w64-x86_64-toolchain
$ pacman -S make mingw-w64-x86_64-cmake
$ pacman -S mingw-w64-x86_64-msmpi
$ pacman -S mingw-w64-x86_64-openblas
$ pacman -S mingw-w64-x86_64-fftw
```

Now you can **close the MSYS2 terminal**.

(2) Install the [Microsoft MPI]( https://docs.microsoft.com/en-us/message-passing-interface/microsoft-mpi). Simply open the link and follow the "Next > Next > Done" procedure.

Now open the **MSYS2-MINGW64 terminal** and edit the `~/.bashrc` file (use the `nano` text editor, see below) and add at the end:

```bash
export PATH="$MSMPI_BIN":$PATH
```

**Using the `GNU nano` text editor:** to open a file, run `$ nano .bashrc`. Use the keyboard to move around and enter the line above at the end of the file. To save press `CTRL+S` and to exit press `CTRL+X`. For more information and shortcuts, check [the GNU nano webpage](https://www.nano-editor.org/dist/latest/cheatsheet.html).


---