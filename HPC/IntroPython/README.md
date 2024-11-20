# Introduction to python

I'll we need from python is an interface to plot our results obtained in C. But with time I'll prepare a more complete introduction here. For a better introduction to python, please check the [Tutorials Point](https://www.tutorialspoint.com/python/index.htm).

## Install and use a virtual environment

> The instructions here are valid for Debian/Ubuntu either native or within WSL.

A python virtual environment (venv) creates a sub-installation of python within your project folder or within your user folder. Your choice. This allow us to install python packages within our venv without affecting the operational system, among other advantages. For more, check [its documentation](https://virtualenv.pypa.io/en/latest/).

1. Install pip on Linux by running

```bash
$ sudo apt update
$ sudo apt install python3-pip python3-dev
```

2. Let's install the **virtualenv** package on the user home to avoid messing with the OS.

```bash
$ pip3 install virtualenv --user
```

3. Use `nano` to edit the `.bashrc` file (bash start file) to put the virtualenv binary on the PATH. Within `nano`, CTRL+S saves the file, and CTRL+X quits the editor. Add this to the last line:

```bash
export PATH=$PATH:$HOME/.local/bin
```

To update the PATH variable, either close and reopen the terminal, or simply run

```bash
$ source .bashrc
```

4. Let's create a venv. You can choose to make a venv for each project, which requires you to install your python packages on each project as well. Or set a venv for your home folder to use in all projects. Here I'll call my venv **base**, but you can try to be more creative. Run the code bellow to create this venv, and it will create a folder called *base* as well, that's were all configuration and packages of your virtual python will be installed.

```bash
$ virtualenv base
```

5. Edit `.bashrc` (use `nano` again) and add this line at the end. It activates your venv by default when you open the terminal.

```bash
source $HOME/base/bin/activate
```

To activate the venv, either close and reopen the terminal, or run the line above on the terminal.

You will note that now your terminal prompt has a label **(base)**. This tells us that the venv is active and all python commands will be run within it from now on.

6. Install all python packages you'll need. My suggestion is:

```bash
$ pip install --upgrade pip
$ pip install jupyter numpy scipy matplotlib tqdm
```

## Using jupyter on the VS Code

The only approach that works equally well on Linux and Win10+WSL is to use the **jupyter** interface. Let's use within the VS Code.

- On VS Code, search for and install the **python** extension and reload the VS Code.
- Create a new file and save it with the extension **.ipynb**. VS Code will automatically recognize it as a jupyter file and start the jupyter interface.

There are many videos on youtube on how to use jupyter. Try running this code:

```python
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 2*np.pi, 100)
y = np.sin(x)

plt.plot(x, y)
plt.show()
```

This will set `x` as a list of 100 elements equally spaced from 0 to $`2\pi`$, and set `y` as the sin(x) calculated at each *x*. The last two lines plots the data.

#### Plotting data from an external file

In our C codes we will save data in two-column files, where the first column will have the values of *x*, and the second column the values of *y*. Let's say this file is called **data.dat**. To plot its contents in python, here's the code:

```python
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('data.dat')
x = data[:,0] # all lines from column 0
y = data[:,1] # all lines from column 1

plt.plot(x, y)
plt.show()
```

## Calling C codes from python

There are two options:

1. naively calling a subprocess (easy but limited)
2. write a python wrapper to C library (complicated by awesome)

I'll write about these soon.

#### Calling a subprocess

While I don't write the tutorial here, check the subprocess package [documentation](https://docs.python.org/3/library/subprocess.html).

#### A python wrapper

This is done with **Cython**, while I don't write a tutorial, check its [documentation](https://cython.org/).




