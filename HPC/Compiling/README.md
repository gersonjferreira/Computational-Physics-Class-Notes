# Compiling your code

Let's discuss how to compile a C code:

- from the bash terminal *by hand* calling `gcc`
- from bash using a makefile and calling `make`
- using the VS Code approach

[[_TOC_]]

## Compiling by hand and using Makefile

The best way to compile a code in Linux is to use a `Makefile`. For more information, please check its documentation and a tutorial at the links below:

- Official documentation of [[gnu make]](https://www.gnu.org/software/make/manual/make.html)
- A short and practical documentation the [Wikipedia for Makefile](https://en.wikipedia.org/wiki/Makefile)
- The Tutorials Point [tutorial for Makefile](https://www.tutorialspoint.com/makefile/index.htm)

Let's check two examples. In both cases I'll consider the files located at the folder [Examples > multiple_files](Examples/multiple_files/), these are:

- `main_code.c`, which contains the main() function for the binary.
- `aux_functions.c`, with auxiliary functions to be used by main().
- `aux_functions.h`, the headers for the functions in the file above.

**Option 1:** You could compile these simply calling gcc on all c files as

```bash
$ gcc main_code.c aux_functions.c -o main_code.out
```

This command would combine all c files into one and compile as if it was a single file, generating the binary `main_code.out`.

**Option 2:** Compile aux_functions.c as a `.o` library. The advantage of this case is that you can reuse the `.o` file into other projects. So you can keep a folder will your personal libraries to be used later.

To compile the library we run

```bash
$ gcc -c aux_functions.c -o aux_functions.o
```

The `-c` flag tells gcc to compile the code, but not to link it as a final binary. So it is an incomplete compilation. It needs to be linked later to a main code.

To link the library to the main code, we run:

```bash
$ gcc -c main_code.c -o main_code.o
$ gcc main_code.o aux_function.o -o main_code.out
```

The first line above compiles the `main_code.c` as a library as well, and the second line links both libraries to produce the final binary `main_code.out`. Notice that one of the `.o` objects must have a main() function.

This process is a **dynamical linking**. This means that the final binary `main_code.out` is not independent. To run, it needs the `.o` files. If you delete one of the `.o` files, the `main_code.out` won't run. Try it and read the error message. Alternatively, you could call a **static linking**, the the documentations above for more information. Here we'll prefer dynamical linking.

**Option 3: Use a makefile.** The makefile makes the process above automatic. Consider the simple example. Save this code as `Makefile`, and notice that the indentations must be **TABs and not SPACEs**.

```makefile
DEPS=aux_functions.h
OBJ=main_code.o aux_functions.o

%.o: %.c $(DEPS)
	gcc -c -o $@ $<

main_code: $(OBJ)
	gcc -o $@.out $^

clean:
	rm *.o *.out
```

To run this makefile, call the command `$ make`. To call a specific target, call its name, for instance `$ make clean`.

On the makefile, the labels before each `:` indicates a target (or rule). The `%.o` target will apply to all `.o` files that are referenced. But since this is generic target, it does not get executed at first. The execution starts at the first non-generic target, which in this case is the `main_code:` target. 

The `main_code:` target. After the `:` we list all files that are required for that target. In this case these are listed in the OBJ variable as `.o` files. But we don't have `.o` files yet! So `make` will search for a generic target on how to obtain the `.o` files and call it. So it calls the `%.o:` target for each `.o` file, and once finished, it runs the main_code target by running the lines below it. Here, $@ refers to the target name, and $^ to the full list of dependencies that follows the `:`. So it runs the *third command of option 2 above*.

The `%.o` target. This target creates the `.o` files. It depends on the corresponding `.c` file and the files in the DEPS variable. If these exist, it runs the rules within this target. So, for each .o file it runs the command with $@ referring to the target name, which is the full .o filename, and $< refers to the first dependence following the `:`, which is the corresponding .c file. This target *runs the first two commands of option 2 above (those with the -c flag)*.

## Compilation flags

The `gcc` compiler has a ton of flags for optimization. For all details check the manual pages in `$ man gcc` on the Linux terminal or online at [die.net](https://linux.die.net/man/1/gcc). I'll list here the most common flags and their description from the man pages.

To turn on all compilation warnings, use `-Wall` (recommended)!

How to use the flags? To call `gcc` with `-Wall` and an optimization flag, use:

```bash
$ gcc -Wall -O3 my_file.c
```

#### Optimization flags

The recommendation is to use `-O3`, but be brave and check `-Ofast` as well.

- **-O1**

> The compiler tries to reduce code size and execution time, without performing any optimizations that take a great deal of compilation time.

- **-O2**

> Optimize even more. GCC performs nearly all supported optimizations that do not involve a space-speed tradeoff. As compared to -O, this option increases both compilation time and the performance of the generated code.


- **-O3** (recommended)

> Optimize yet more. -O3 turns on all optimizations specified by -O2 and also turns on the -finline-functions, -funswitch-loops, -fpredictive-commoning, -fgcse-after-reload, -ftree-vectorize and -fipa-cp-clone options.

- **-Ofast** (awesome but dangerous: possible rounding error in floats)

>Disregard strict standards compliance.  -Ofast enables all -O3 optimizations.  It also enables optimizations that are not valid for all standard-compliant programs.  It turns on -ffast-math, -fallow-store-data-races and the Fortran-specific -fstack-arrays, unless -fmax-stack-var-size is specified, and -fno-protect-parens.

The **-Ofast** flag is dangerous, notice that it enables **-ffast-math**, which is described as

>  **-ffast-math**: This option is not turned on by any -O option besides -Ofast since it can result in incorrect output for programs that depend on an exact implementation of IEEE or ISO rules/specifications for math functions. It may, however, yield faster code for programs that do not require the guarantees of these specifications.

#### Include and library paths

To add a directory to the list searched by gcc to include headers and libraries, use these flags:

> **-I dir** : looks for headers (.h files) in `dir`

> **-L dir** : looks for libraries in `dir`.

For instance, let's say you wrote ODE libraries and its is stored in `/home/myself/MyCodes/` with the following structure:

- /home/myself/MyCodes/
  - Incs/
    - rk4.h
    - euler.h
    - ...
  - Libs/
    - librk4.so
    - libeuler.so
    - ...
  - Project/
    - main.c

Now, in main.c you include rk4.h as

```c
#include <stdio.h>
#include <rk4.h>
...
```

To compile the main.c you must inform where the rk4 library is installed, since it is not a default library of the system. To do it, call gcc as

```bash
$ gcc main.c -I/home/myself/MyCodes/Incs/ -L/home/myself/MyCodes/Libs -lrk4
```

The flag `-lrk4` tells gcc to look for a library `librk4.so` first in the directories listed by the `-L` flag. If not found there, it will look at the system set of libraries. Similarly, the `-I` flag tells gcc where to look for the `rk4.h` file.

**To compile your code as a library** [[more info here]](https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html). Let's say you have your `rk4.c` and `rk4.h` code ready. To make it a library, first compile as object and then make it a library with these commands:

```bash
$ gcc -c -fpic rk4.c 
$ gcc -shared -o librk4.so rk4.o
```

Since this is a library, the `rk4.c` should not have a *main* function! It should only contain auxiliary functions as listed in the `rk4.h` file.


## Compiling and debugging from VS Code

To compile, debug and run your code within VS Code, we use **tasks**. These are some useful references on how to use these tasks:

- [Using C/C++ with VS Code](https://code.visualstudio.com/docs/cpp/config-linux)
- [Debugging](https://code.visualstudio.com/docs/editor/debugging)
- [Tasks](https://code.visualstudio.com/docs/editor/tasks)
- [Run and debug for C/C++ in VS Code](https://medium.com/@GorvGoyl/run-debug-intellisense-c-c-in-vscode-within-5-minutes-3ed956e059d6)

The tasks are configured by the following files in the `.vscode` folder within your project:

- `tasks.json`: defines how your code will be compiled. To call this task, type `Ctrl + Shift + B`. After the file is compiled, open the terminal and run it by calling `./mybin`, where `mybin` is the name of your compiled binary file. To initialize a default `task.json`, go to the menu *Terminal > Configure default build task...*
- `launch.json`: defines how to launch the debugger, which can be run by pressing `F5`. To initialize a default `launch.json`, go to *Run > Add configuration...* and choose `C++ (GDB/LLDB)`.

#### Example of tasks.json

Let's start with this generic `tasks.json` that defines three tasks. In each task, the **label** defines the task name, which will show up in a list when you type `Ctrl + Shift + B`. 

```json

{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "Compile to run",
            "command": "/usr/bin/gcc",
            "args": [
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.out",
                "-lm"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build"
        },
        {
            "type": "shell",
            "label": "Compile to debug",
            "command": "/usr/bin/gcc",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.out",
                "-lm"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build"
        },
        {
            "type": "shell",
            "label": "Make",
            "command": "/usr/bin/make",
            "args": [],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build"
        }
    ]
}
```

The first two tasks above run the `gcc` **command**, but the first compiles without the `-g` debug flag (or *arg*). The `${file}` placeholder refers to the active file, but you can replace it with the explicit name of your code, e.g. `hello.c`. The `${fileBasenameNoExtension}` placeholder refers to the active file without its extension, thus yielding `hello.out` as the final binary name. You can also put it there explicitly. So the first and second tasks run as

```bash
gcc hello.c -o hello.out -lm # task: Compile to run
gcc -g hello.c -o hello.out -lm # task: Compile to debug
```

The option **cwd** defines the work directory as the current workspace folder. The **problemMatcher** is `gcc` itself, which will read and list the error and warning messages.

The third task, labeled **Make** will run the `make` command on the `makefile` script. This is the best approach, since the `makefile` structure allow for much more detailed and complex compilation schemes for multiple file compilations.

#### Example of launch.json

Let's define two **launch configurations**, the first will run the **Compile to debug** task and then run the **debugger**, while the second will run the **Compile to run** task and run the code without debugging. 

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Compile to debug",
            "miDebuggerPath": "/usr/bin/gdb"
        },
        {
            "name": "Build and run active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Compile to run"
        },
        {
            "name": "Run active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```