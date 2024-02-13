#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "include/ODE.h"


int main(int argc, char *argv[])
{
    // Use input arguments to set number of time steps
    int Ns = (argc > 1) ? atoi(argv[1]) : (int) 1e6;
    // Loop parameter
    int i;
    // Declare parameters
    double t0 = 0;
    double x0[2] = {1,0};
    double dt = 0.001;
    double mu = 50;
    // Declare arrays
    double *x, *t;
    // Time recording parameters
    int num_runs = 10;
    clock_t start, stop;
    double elapsed_time = 0;
    // Loop
    for(i = 0; i < num_runs; i++)
    {
        // Start timer
        start = clock();
        // Allocate arrays
        x = (double*) malloc((Ns+1)*2*sizeof(double));
        t = (double*) malloc((Ns+1)*sizeof(double));
        // Initialize initial conditions
        x[0] = x0[0]; x[1] = x0[1];
        t[0] = t0;
        // Call VanDerPol
        VanDerPol(x, t, dt, Ns, mu);
        // Stop timer
        stop = clock();
        // Free allocated memory
        free(x); free(t);
        // Add time
        elapsed_time += ((double)(stop - start)) / CLOCKS_PER_SEC;
    }
    
    printf("%.8f ",elapsed_time/num_runs);

    return 0;
}