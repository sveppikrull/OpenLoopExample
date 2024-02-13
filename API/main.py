import numpy as np
import matplotlib.pyplot as plt
import lib.ODE as ODE
from time import perf_counter
import sys

def main():
    if len(sys.argv) > 1:
        Ns = int(sys.argv[1])
    else:
        Ns = 1000000
    t0 = 0
    x0 = np.array([[1,0]])
    dt = 0.001
    mu = 50
    num_runs = 10
    cpu_time = 0

    for i in range(num_runs):
        start_t = perf_counter()
        t = np.zeros(Ns+1)
        t[0] = t0
        # Initialize states
        nx = x0.size
        x = np.zeros((Ns+1,nx))
        x[0,:] = x0
        ODE.VanDerPol(x,t,dt,Ns,mu)
        stop_t = perf_counter()
        cpu_time += stop_t-start_t
    
    print("{:.8f} ".format(cpu_time/num_runs),end="")
    
    # Uncomment to plot
    '''
    plt.figure(figsize=[9,6])
    plt.plot(x[:,0],x[:,1])
    plt.xlabel(r'$x_1$')
    plt.ylabel(r'$x_2$')
    plt.title(r'$x_2$ as a function of $x_1$')

    fig, axs = plt.subplots(2,figsize=[9,6])
    fig.suptitle(r'$x_1$ and $x_2$ as a function of time')
    axs[0].plot(t, x[:,0])
    axs[0].set_ylabel(r'$x_1$')
    axs[1].plot(t, x[:,1])
    axs[1].set_xlabel(r't')
    axs[1].set_ylabel(r'$x_2$')
    plt.show()
    '''
    
    return 0




if __name__ == '__main__':
    main()