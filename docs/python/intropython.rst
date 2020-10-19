Introduction to python
======================

.. code:: py

    print("Hello, world!")

**Python** is one of the most used computer languages nowadays. It's an interpreted language, but highly efficient since its libraries typically call Fortran or C codes on their backend. Its `Wikipedia <https://en.wikipedia.org/wiki/Python_(programming_language)>`_ article has a bit of its history and links to interesting texts and books.

Here I'll give a brief introduction to essential features of the language and how to use it. I suggest we use the `Anaconda distribution <https://www.anaconda.com>`_, since it runs equally well in Linux, Windows and Mac. Also, besides my introduction below, check also these tutorials:

#. Python at Tutorial's point: `[python] <https://www.tutorialspoint.com/python>`_, `[numpy] <www.tutorialspoint.com/numpy/>`_, `[matplotlib] <https://www.tutorialspoint.com/matplotlib/index.htm>`_

#. Official documentation for `[numpy - scipy - matplotlib] <https://www.scipy.org/docs.html>`_

#. Official documentation: `how to install Anaconda <https://docs.anaconda.com/anaconda/install/>`_

#. Youtube video (in Portuguese) `Como instalar Anaconda em Windows e Linux <https://www.youtube.com/watch?v=GaPrX6aF2E8>`_

The IDEs
--------

The *Integrated Development Environments (IDEs)* are the softwares that we use to edit / debug / run our codes. Here, I'll suggest we start with these two that are already installed with Anaconda:

* `Jupyter: <https://jupyter.org>`_ is a web-based IDE that runs in your browser. It runs the code in cells and allows you to use *markdown* and *Latex* to document your code. Since *jupyter* integrates code, documentation and images, I **recommend** we start with this one. The name **jupyter** refers to the three initial languages it was design to support: *julia*, *python*, and *R*. 

* `Spyder IDE: <https://www.spyder-ide.org>`_ is a traditional IDE with the text editor and dedicated panels for the output and figures. The name **Spyder** means *Scientific Python Development Environment*. The figure below shows how it looks like.

The images below show how these IDE look like, click to zoom.

.. list-table:: 

    * - .. image:: ./figs/jupyter-helloworld.png
            :alt: Jupyter IDE
            :width: 99%
            :align: center

        The Jupyter IDE

      - .. image:: ./figs/spyder-helloworld.png
            :alt: Spyder IDE
            :width: 99%
            :align: center
        
        The Spyder IDE

Other very interesting IDEs are the `PyCharm <https://www.jetbrains.com/pycharm/>`_ and `VS Code <https://code.visualstudio.com>`_. I actually use **VS Code** for everything: python, C, and even for writting this webpage. But if you are a beginner, I recommend you first try **Spyder** or **Jupyter**.

.. note:: 
    
    **Jupyter vs Spyder:** Both are great IDEs, however, they are quite different from each other. Their main *pros* and *cons* are:
    
    - *Jupyter*
    
        * (pro) Saves in a single *notebook* the code, markdown/latex notes, and the figures/plots;
        
        * (pro) Run code in cell blocks that allow you to split calculations and plots;

        * (con) The *notebook* (.ipynb) is not a simple text file, but a *json* file; 
        
        * (con) There's no structure for debugging.
    
    - *Spyder* 

        * (pro) Saves the code as simple text (.py);
        
        * (pro) It has a native debugging structure; 
        
        * (pro) Allows you to run individual *cells* (similar to jupyter);

        * (con) Figures must be saved into files for storage.


Using the IDEs
^^^^^^^^^^^^^^

More details will be covered in the first class with simple examples, but here are the most important things to remember.

* **Jupyter:** The code runs in blocks called *cells*. To **run a cell** type ``SHIFT+ENTER``. The jupyter codes are saved in a *json* format (extension .ipynb) and are called **ipython notebooks**, which allows you to save the code, markdown and images in a single file.

.. warning::
    Evidently, you can run the cells out of order while developing, but the final code should be organized to run cell-by-cell in order. 

The following **keyboard shortcuts** run in *Command mode*, which is activated by pressing ``ESC``. A full list of shortcuts can be seen by pressing ``ESC+H``. To **add a cell**, type ``ESC+A`` to add above or ``ESC+B`` to add below. To **delete a cell** type ``ESC+D+D``. 

To **change a cell type** check the buttons bar at the top of the window you see a list of cell types. The most important ones are *code* and `markdown <https://guides.github.com/features/mastering-markdown/>`_. In the *markdown mode* you can write formatted text and Latex equations, which is quite useful to document your code and present the results. You can also change the cell to *markdown mode* by calling ``ESC+M``, and back to *code mode* with ``ESC+Y``.

* **Spyder:** This IDE works with simple text files (extension .py). To run the (entire) code you press ``F5``. Spyder can also work with cells, which are defined by ``# %% Cell Name``. The *Cell Name* is optional, but helps with the organization of the code. To run only the current cell and advance to the next, you press ``Shift + Enter``.

.. warning::
    It might be important to check the **workspace directory** on the top right corner of the window, as it **defines the relative path** to read and save files.

Spyder allows you to choose how to show the plots/images. To find the options go to ``Tools > Preferences > IPython console > Graphics > Backend``. To capture the plots into the Spyder panel, choose **inline**, and to plot as a separate window, choose **automatic**.


Variables, data types and operations
------------------------------------

Functions and scope of variables
--------------------------------

Decision making: if / else / etc...
-----------------------------------

Loops: for / while
------------------
