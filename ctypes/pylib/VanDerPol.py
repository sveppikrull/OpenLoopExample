import ctypes
import os
import numpy as np
from numpy.ctypeslib import as_array

# Get the directory of the current Python script
script_dir = os.path.dirname(os.path.abspath(__file__))

# Navigate one level up from the script directory
parent_dir = os.path.dirname(script_dir)

# Construct the full path to the shared library
lib_path = os.path.join(parent_dir, 'lib', 'lib.so')

# Load the shared library
lib = ctypes.CDLL(lib_path)

def VanDerPol(x0,t0,dt,Ns,mu):
    # Initialize time
    t = np.zeros(Ns+1)
    t[0] = t0
    # Initialize states
    nx = x0.size
    x = np.zeros((nx,Ns+1))
    x[:,0] = x0
    # Convert to ctypes
    t_c = (ctypes.c_double * t.size)(*t)
    x_c = (ctypes.c_double * x.size)(*x.flatten('F'))
    dt_c = ctypes.c_double(dt)
    Ns_c = ctypes.c_int(Ns)
    mu_c = ctypes.c_double(mu)
    # Call shared library
    lib.VanDerPol(x_c,t_c,dt_c,Ns_c,mu_c)
    # Convert back to np arrays
    x = as_array(x_c,shape=(nx*(Ns+1),)).reshape((nx, Ns+1), order='F')
    t = as_array(t_c)

    return x,t