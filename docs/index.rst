Introduction to Computational Physics
=================================================================

| Prof. Dr. Gerson J. Ferreira
| Institute of Physics, Federal University of Uberlândia
| `gjferreira.wordpress.com <https://gjferreira.wordpress.com>`_

.. note::
   Previously, I had written a book draft on *Computational Physics with examples in Julia*. But I don't want to publish it bacause computer languages change all the time and I want to keep adding topics and exemples. So, instead, I'm moving and updating the content of the book to this webpage.

   In this new version I'll start with examples in **Python**. But in time I'll add examples in **Julia** and **C**.

Let's start with a very short introduction. In computational physics a lot of things work by dropping the limits:

.. math::
   \begin{align}
      \dfrac{\partial f(x)}{\partial x} &= \lim_{\Delta x \rightarrow 0} \dfrac{f(x+\Delta x) - f(x)}{\Delta x} \approx \dfrac{f(x+\Delta x) - f(x)}{\Delta x}
      \\
      \int f(x) dx &= \lim_{\Delta x \rightarrow 0} \sum_n f(x_0 + n \Delta x) \Delta x \approx \sum_n f(x_0 + n \Delta x) \Delta x
   \end{align}

That's it. Everything else is variations of these approximations. Now, let's go into the details.

.. toctree::
   :numbered:
   :maxdepth: 2
   :caption: About the course

   intro.rst

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
   




