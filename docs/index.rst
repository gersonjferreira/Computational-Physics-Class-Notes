Introduction to Computational Physics
=================================================================

| Prof. Dr. Gerson J. Ferreira
| Institute of Physics, Federal University of Uberlândia
| `gjferreira.wordpress.com <https://gjferreira.wordpress.com>`_

About the course
----------------

These are the class notes for the course *Computational Physics*, lectured to the students of *Bacharelado em Física*, *Física Médica*, and *Licenciatura em Física* from the *Instituto de Física*, *Universidade Federal de Uberlândia* (**UFU**). Since this is an optional class intended for students with diverse knowledge and interest in Computational Physics and computer languages, I choose to discuss selected topics superficially with practical examples that may interest the students. Advanced topics are proposed as *home projects* to the students accordingly to their interest. 

.. note:: 
   Initially, I had written a book draft with examples in `Julia <https://julialang.org>`_, but since then this language has changed a lot (improved, actually!). The idea of this new webpage is to move the content of the book here and write examples in many languages (*Julia, Python, and C*). This will be a long process and I'll start with **Python** because its documentation is more accessible to new students. Later I'll add examples in Julia and C.

Topics
------

Since this is an introductory course, we'll focus on simple topics that are useful to solve physics problems. Namely:

#. Introduction to the computer language
#. Plotting beautiful figures
#. Numerical calculus: integrals, derivatives, root finding, ...
#. Linear algebra: system of eqs., eigenvalues, ...
#. Differential equations: initial value problems and boundary value problems
#. Fourier transforms
#. Random numbers and statistics
#. Machine / Deep learning (*soon*)

All these topics will be applied to solve physics problems in exercies along the course.

A very quick introduction
-------------------------

Let's start with a very short introduction. In computational physics a lot of things work by dropping the limits:

.. math::
   \begin{align}
      \dfrac{\partial f(x)}{\partial x} &= \lim_{\Delta x \rightarrow 0} \dfrac{f(x+\Delta x) - f(x)}{\Delta x} \approx \dfrac{f(x+\Delta x) - f(x)}{\Delta x}
      \\
      \int f(x) dx &= \lim_{\Delta x \rightarrow 0} \sum_n f(x_0 + n \Delta x) \Delta x \approx \sum_n f(x_0 + n \Delta x) \Delta x
   \end{align}

That's it. Everything else is variations of these approximations. Now, let's go into the details.

Main references
---------------

.. \textbf{Text-books.} Complementing these notes, complete discussions on the proposed topics can be found on the books available at UFU's library\cite{CScherer2010Metodos, NFranco2006Calculo, Arenales2008Calculo, JCButcher2008NumericalODE, thijssen2007computational, pang2006introduction}, and other references presented throughout the notes.



Table of contents
-----------------

.. toctree::
   :numbered:
   :maxdepth: 2
   :caption: Intro to python

   python/intropython.rst
   python/numpy.rst
   python/matplotlib.rst

.. toctree::
   :numbered:
   :maxdepth: 2
   :caption: Basic calculus

   calculus/integrals.rst
   calculus/derivatives.rst

.. toctree::
   :numbered:
   :maxdepth: 2
   :caption: Ordinary differential equations

   ode/initialvalueproblems.rst
   ode/boundary_value_problems.rst

.. toctree::
   :numbered:
   :maxdepth: 2
   :caption: Fourier transforms

   fft/intro_fft.rst
   




