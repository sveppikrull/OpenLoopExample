// VanDerPol.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/ODE.h"

typedef struct 
{
	double mu;
} VanDerPol_p_t;

void VanDerPol_fun(const double t, const double *x, double *f, const void* p)
{
    // Unpack pointer
    VanDerPol_p_t* VanDerPol_p;
	VanDerPol_p = (VanDerPol_p_t*) p;
    // Calculate derivative
    f[0] = x[1];
    f[1] = (VanDerPol_p->mu)*(1-x[0]*x[0])*x[1] - x[0];
}

void VanDerPol(double* x, double* t, double dt, int Ns, double mu)
{
    // Create and declare void pointer
    VanDerPol_p_t VanDerPol_p;
    VanDerPol_p_t* p = &VanDerPol_p;
    // Fill in value
    p->mu = mu;
    // Declare function
    fun_t* fun = VanDerPol_fun;
    // Number of variables
    int nx = 2;
    // Initialize f
    double * f = (double*) malloc(nx*sizeof(double));
    // Simulate
    ExplicitEuler(fun,f,x,nx,t,dt,Ns,p);
    // free f
    free(f);
}