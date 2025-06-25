#include <Python.h>

PyMODINIT_FUNC
PyInit__stableish(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("295eace8438df6ec133b__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_eth_portfolio____stableish");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "295eace8438df6ec133b__mypyc.init_eth_portfolio____stableish");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit__stableish(); }
