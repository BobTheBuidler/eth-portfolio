#include <Python.h>

PyMODINIT_FUNC
PyInit_utils(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("eth_portfolio__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_eth_portfolio____loaders___utils");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "eth_portfolio__mypyc.init_eth_portfolio____loaders___utils");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_utils(); }
