The python language
===================

.. code:: py

    print("Hello, world!")

**Python** is one of the most used computer languages nowadays. It's an interpreted language, but highly efficient since its libraries typically call Fortran or C codes on their backend. Its `Wikipedia <https://en.wikipedia.org/wiki/Python_(programming_language)>`_ article has a bit of its history and links to interesting texts and books.

Here I'll give a brief introduction to essential features of the language and how to use it. I suggest we use the `Anaconda distribution <https://www.anaconda.com>`_, since it runs equally well in Linux, Windows and Mac. Also, besides my introduction below, check also these tutorials:

#. Python at Tutorial's point: `[python] <https://www.tutorialspoint.com/python>`_, `[numpy] <www.tutorialspoint.com/numpy/>`_, `[matplotlib] <https://www.tutorialspoint.com/matplotlib/index.htm>`_

#. Official documentation for `[numpy - scipy - matplotlib] <https://www.scipy.org/docs.html>`_

#. How to install `Anaconda <https://docs.anaconda.com/anaconda/install/>`_

The IDEs
--------

The *Integrated Development Environments (IDEs)* are the softwares that we use to edit / debug / run our codes. Here, I'll suggest we start with these two that are already installed with Anaconda:

* `Jupyter: <https://jupyter.org>`_ is a web-based IDE that runs in your browser. It runs the code in cells and allows you to use *markdown* and *Latex* to document your code. Since *jupyter* integrates code, documentation and images, I **recommend** we start with this one. The name **jupyter** refers to the three initial languages it was design to support: *julia*, *python*, and *R*. 

* `Spyder IDE: <https://www.spyder-ide.org>`_ is a traditional IDE with the text editor and dedicated panels for the output and figures. The name **Spyder** means *Scientific Python Development Environment*. The figure below shows how it looks like.

The images below show how these IDE look like.

.. list-table:: 

    * - .. figure:: figs/jupyter-helloworld.png

           The Jupyter IDE

      - .. figure:: figs/spyder-helloworld.png

           The Spyder IDE

Other very interesting IDEs are the `PyCharm <https://www.jetbrains.com/pycharm/>`_ and `VS Code <https://code.visualstudio.com>`_. I actually use **VS Code** for everything: python, C, and even for writting this webpage. But if you are a beginner, I recommend you first try **Spyder** and **Jupyter**.

Using the IDEs
^^^^^^^^^^^^^^

More details will be covered in the first class with simple examples, but here are the most important things to remember.

* **Jupyter:** The code runs in blocks called *cells*. To **run a cell** type ``SHIFT+ENTER``. 

.. warning::
    Evidently, you can run the cells out of order while developing, but the final code should be organized to run cell-by-cell in order. 

The following **keyboard shortcuts** run in *Command mode*, which is activated by pressing ``ESC``. A full list of shortcuts can be seen by pressing ``ESC+H``. To **add a cell**, type ``ESC+A`` to add above or ``ESC+B`` to add below. To **delete a cell** type ``ESC+D+D``. 

To **change a cell type** check the buttons bar at the top of the window you see a list of cell types. The most important ones are *code* and `markdown <https://guides.github.com/features/mastering-markdown/>`_. In the *markdown mode* you can write formatted text and Latex equations, which is quite useful to document your code and present the results. You can also change the cell to *markdown mode* by calling ``ESC+M``, and back to *code mode* with ``ESC+Y``.

* **Spyder:**


Variables, data types and operations
------------------------------------

Functions and scope of variables
--------------------------------

Decision making: if / else / etc...
-----------------------------------

Loops: for / while
------------------
