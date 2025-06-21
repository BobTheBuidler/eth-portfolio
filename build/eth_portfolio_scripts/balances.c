#include <Python.h>

PyMODINIT_FUNC
PyInit_balances(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("f1e218790a463ec43ce1__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_eth_portfolio_scripts___balances");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "f1e218790a463ec43ce1__mypyc.init_eth_portfolio_scripts___balances");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_balances(); }
