import numpy as np
from pylib.ExplicitEuler import ExplicitEuler


def VanDerPol_fun(t,x,p):
    # Calculate slope
    f = np.array([x[1],p*(1-x[0]*x[0])*x[1]-x[0]])
    # Return
    return f


def VanDerPol(x0,t0,dt,Ns,mu):
    # Allocate memory
    x = np.empty((2,Ns+1),dtype=float)
    t = np.empty(Ns+1,dtype=float)
    # Initialize initial conditions
    x[:,0] = x0
    t[0]   = t0
    # Simulate
    ExplicitEuler(VanDerPol_fun,x,t,dt,Ns,mu)
    
    return x,t