// ExplicitEuler.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/ODE.h"


void ExplicitEuler(fun_t* fun, double*f, double* x, int nx,
                   double* t, double dt, int Ns, const void* p)
{
    // Loop varibales 
    int i,j;
    // Loop from t_0 to t_Ns
    for(i = 0; i < Ns; i++)
    {
        // Calculate derivative
        fun(t[i], x + i*nx, f, p);
        // Find new point using Euler Maruyama step
        for(j = 0; j < nx; j++)
        {
            x[(i+1)*nx + j] = x[i*nx + j] + f[j]*dt;
        }
        // Update time
        t[i+1] = t[i] + dt;    
    }
}

