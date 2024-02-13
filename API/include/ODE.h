#ifndef ODE_h
#define ODE_h

typedef void fun_t
(
    const double t, const double *x, double *f, const void* p
);

void ExplicitEuler(fun_t* fun, double*f, double* x, int nx,
                   double* t, double dt, int Ns, const void* p);

void VanDerPol_C(double* x, double* t, double dt, int Ns, double mu);

#endif
