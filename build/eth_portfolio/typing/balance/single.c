#include <Python.h>

PyMODINIT_FUNC
PyInit_single(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("93dc731d39cdfeb0971f__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_eth_portfolio___typing___balance___single");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "93dc731d39cdfeb0971f__mypyc.init_eth_portfolio___typing___balance___single");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_single(); }
