.. Introduction to Computational Physics documentation master file, created by
   sphinx-quickstart on Sat Oct 17 19:06:16 2020.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Introduction to Computational Physics
=================================================================

.. image:: https://readthedocs.org/projects/compphysics/badge/?version=latest
   :target: https://compphysics.readthedocs.io/?badge=latest
   :alt: Documentation Status

Let's start with a very short introduction. In computational physics a lot of things work by dropping the limits:

.. math::
   \begin{align}
      \dfrac{\partial f(x)}{\partial x} &= \lim_{\Delta x \rightarrow 0} \dfrac{f(x+\Delta x) - f(x)}{\Delta x} \approx \dfrac{f(x+\Delta x) - f(x)}{\Delta x}
      \\
      \int f(x) dx &= \lim_{\Delta x \rightarrow 0} \sum_n f(x_0 + n \Delta x) \Delta x \approx \sum_n f(x_0 + n \Delta x) \Delta x
   \end{align}

That's it. Everything else is variations of these approximations. Now, let's go into the details.

Table of contents
---------------------------------------------------------------------

.. toctree::
   :numbered:
   :maxdepth: 2
   :caption: Intro to python

   python/intropython.md
   python/numpy.md
   python/matplotlib.md

.. toctree::
   :numbered:
   :maxdepth: 2
   :caption: Basic calculus

   calculus/integrals.md
   calculus/derivatives.md


