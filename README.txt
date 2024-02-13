This project contains a simple performance analysis of ODE simulations
using various combinations of python and C written for Mac. Each folder contains 
a different implementation of simulating 10e6 time steps of the
"Van Der Pol oscilator". To be able to run this project you must first 
"compile" each folder. Steps to do this are described in the ReadMe file in
each folder. 

API 
    Contains an implementation of a C module that is run using the 
    Python/C API.
C 
    Contains a pure C implementation used as a benchmark.

Ctypes
    Contains an implementation in C that is interfaced in python
    using the package ctypes.

Python
    Contains a pure python implementation.

It is reccomended to use a virtual python enviroment to ensure
that the relevent packages are present and up to date. If you have
virtual enviroment installed on your computer you can start it up by typing in 
the terminal:

    python3.12 -m venv env

    source env/bin/activate

Then use the file requirements.txt to install the packages:

    pip install -r requirements.txt

When you have installed the packages and compiled each folder, you can perform
the performance analysis using the shell script provided. First you must give
the script executable permissions by typing:

    chmod +x PerformanceAnalysis.sh

Then you can excecute it using:

    ./PerformanceAnalysis.sh

And the runtimes are stored in the file Performance.txt.

-- Author: Sverrir Kristinsson (s222986@dtu.dk)
