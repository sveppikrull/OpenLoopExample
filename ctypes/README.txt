This folder contains a implementation of a ExplicitEuler
solver in C that is interfaced using ctypes in python. 
Numpy arrays are converted to C arrays and the external
library lib/lib.so is called to simulate in C. To make this 
folder executable you need to install the packages 
listed in requirements.txt. As well as compiling the C scripts
using a GCC compiler. You can do that using the Makefile provided
by typing:

    make

To run you excecute the python script:

    python main.py

-- Author: Sverrir Kristinsson (s222986@dtu.dk)