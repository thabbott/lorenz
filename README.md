# Lorenz System

A simple C programming exercise: implement the functions in lorenz.c!

## Getting started

The Lorenz system code can be run without any external dependencies, but viewing
the results with the provided view.py script requires a few common packages from
the scientific Python stack. The simplest way to get your own scientific Python
stack working is probably to install an [Anaconda
distribution](https://www.anaconda.com/download/). It will contain all you need
to run the view.py script and more.

However, two functions in lorenz.c must be implemented before the code will
work. The first, initialize_system, sets initial x, y, and z values for a set of points. (Points near x,y,z = 1,1,1 make good initial values.) The second, step_system, steps each point forward by a given time step. Both functions operate in-place by modifying values in arrays for x, y, and z; importantly, however, they do so by passing the arrays as parameters, **not by declaring the arrays as external (global) varibles**.

After implementing the functions, the code can be compiled with the provided
Makefile. In a bash-like shell and with the required scientific Python
dependencies, running
```console
you@computer:~ make
you@computer:~ ./lorenz
you@computer:~ python view.py
```
will simulate the Lorenz system and display an animation of the results. If you
re-run the simulation, be sure to remove the created lorenz_xyz.out files first.
If you want additionally to remove the files created during compilation, invoke
```console
you@computer:~ make clean
```
to do so.
