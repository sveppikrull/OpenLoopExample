import matplotlib.pyplot as plt
import numpy as np

def main():

    data = np.loadtxt('data.txt')

    Ns = data.shape[1] - 1

    x = np.zeros((2,Ns+1))
    t = np.zeros(Ns+1)

    x[0,:] = data[0,:]
    x[1,:] = data[1,:]

    t = data[2,:]

    plt.figure(figsize=[9,6])
    plt.plot(x[0,:],x[1,:])
    plt.xlabel('x_1')
    plt.ylabel('x_2')
    plt.title('x_2 as a function of x_1')


    fig, axs = plt.subplots(2,figsize=[9,6])
    fig.suptitle('x_1 and x_2 as a function of time')
    axs[0].plot(t, x[0,:])
    axs[0].set_ylabel('x_1')
    axs[1].plot(t, x[1,:])
    axs[1].set_xlabel('t')
    axs[1].set_ylabel('x_2')
    
    plt.show()

    return 0




if __name__ == '__main__':
    main()