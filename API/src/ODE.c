#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdio.h>
#include <numpy/arrayobject.h>
#include "../include/ODE.h"

static char module_name[] =
    "__name__";

static char module_doc[] =
    "__doc__";

static char VanDerPol_doc[] =
    "__doc__";

static PyObject *VanDerPol(PyObject *self, PyObject *args)
{
    PyArrayObject *x_in, *t_in;
    double mu, dt;
    int Ns;
    // Parse the input arguments
    if (!PyArg_ParseTuple(args, "O!O!did", &PyArray_Type, &x_in, &PyArray_Type, &t_in, &dt, &Ns, &mu))
        return NULL;

    // Check if input arrays are not NULL
    if (x_in == NULL || t_in == NULL) {
        PyErr_SetString(PyExc_ValueError, "Input arrays cannot be NULL");
        return NULL;
    }
    // Check if input arrays have correct dimensions
    if (PyArray_DIM(x_in, 0) != Ns+1 || PyArray_DIM(x_in, 1) != 2 || PyArray_DIM(t_in, 0) != Ns + 1) {
        PyErr_SetString(PyExc_ValueError, "Incorrect dimensions for input arrays");
        return NULL;
    }  
    // Flatten the input arrays in Fortran style
    double *x_data = (double *)PyArray_DATA(x_in);
    double *t_data = (double *)PyArray_DATA(t_in);
    // Call the C function
    VanDerPol_C(x_data, t_data, dt, Ns, mu);
    // No need to return anything since we're modifying the arrays in place
    Py_INCREF(Py_None);
    return Py_None;
}


static PyMethodDef Methods[] =
{
    {"VanDerPol", VanDerPol, METH_VARARGS, VanDerPol_doc},
    {NULL,NULL,0,NULL}
};

static struct PyModuleDef ODE = {
    PyModuleDef_HEAD_INIT,
    module_name,
    module_doc,
    -1,
    Methods
};

PyMODINIT_FUNC PyInit_ODE()
{
    PyObject *module = PyModule_Create(&ODE);
    import_array();
    return module;
}
