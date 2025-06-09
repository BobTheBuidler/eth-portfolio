#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native_5e40436d3861d2c108dc.h"
#include "__native_internal_5e40436d3861d2c108dc.h"

static PyObject *_nonce___BlockCache_setup(PyTypeObject *type);
PyObject *CPyDef__nonce___BlockCache(void);

static PyObject *
_nonce___BlockCache_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce___BlockCache) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce___BlockCache_setup(type);
}

static int
_nonce___BlockCache_traverse(eth_portfolio____loaders____nonce___BlockCacheObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_lock);
    return 0;
}

static int
_nonce___BlockCache_clear(eth_portfolio____loaders____nonce___BlockCacheObject *self)
{
    Py_CLEAR(self->_lock);
    return 0;
}

static void
_nonce___BlockCache_dealloc(eth_portfolio____loaders____nonce___BlockCacheObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce___BlockCache_dealloc)
    _nonce___BlockCache_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce___BlockCache_vtable[1];
static bool
CPyDef__nonce___BlockCache_trait_vtable_setup(void)
{
    CPyVTableItem _nonce___BlockCache_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__nonce___BlockCache_____mypyc_defaults_setup,
    };
    memcpy(_nonce___BlockCache_vtable, _nonce___BlockCache_vtable_scratch, sizeof(_nonce___BlockCache_vtable));
    return 1;
}

static PyObject *
_nonce___BlockCache_get_lock(eth_portfolio____loaders____nonce___BlockCacheObject *self, void *closure);
static int
_nonce___BlockCache_set_lock(eth_portfolio____loaders____nonce___BlockCacheObject *self, PyObject *value, void *closure);
static PyObject *
_nonce___BlockCache_get_ttl(eth_portfolio____loaders____nonce___BlockCacheObject *self, void *closure);
static int
_nonce___BlockCache_set_ttl(eth_portfolio____loaders____nonce___BlockCacheObject *self, PyObject *value, void *closure);

static PyGetSetDef _nonce___BlockCache_getseters[] = {
    {"lock",
     (getter)_nonce___BlockCache_get_lock, (setter)_nonce___BlockCache_set_lock,
     NULL, NULL},
    {"ttl",
     (getter)_nonce___BlockCache_get_ttl, (setter)_nonce___BlockCache_set_ttl,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef _nonce___BlockCache_methods[] = {
    {"__mypyc_defaults_setup",
     (PyCFunction)CPyPy__nonce___BlockCache_____mypyc_defaults_setup,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce___BlockCache_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "BlockCache",
    .tp_new = _nonce___BlockCache_new,
    .tp_dealloc = (destructor)_nonce___BlockCache_dealloc,
    .tp_traverse = (traverseproc)_nonce___BlockCache_traverse,
    .tp_clear = (inquiry)_nonce___BlockCache_clear,
    .tp_getset = _nonce___BlockCache_getseters,
    .tp_methods = _nonce___BlockCache_methods,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce___BlockCacheObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__nonce___BlockCache_template = &CPyType__nonce___BlockCache_template_;

static PyObject *
_nonce___BlockCache_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce___BlockCacheObject *self;
    self = (eth_portfolio____loaders____nonce___BlockCacheObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce___BlockCache_vtable;
    self->_ttl = -113.0;
    if (CPyDef__nonce___BlockCache_____mypyc_defaults_setup((PyObject *)self) == 0) {
        Py_DECREF(self);
        return NULL;
    }
    return (PyObject *)self;
}

PyObject *CPyDef__nonce___BlockCache(void)
{
    PyObject *self = _nonce___BlockCache_setup(CPyType__nonce___BlockCache);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
_nonce___BlockCache_get_lock(eth_portfolio____loaders____nonce___BlockCacheObject *self, void *closure)
{
    if (unlikely(self->_lock == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'lock' of 'BlockCache' undefined");
        return NULL;
    }
    CPy_INCREF(self->_lock);
    PyObject *retval = self->_lock;
    return retval;
}

static int
_nonce___BlockCache_set_lock(eth_portfolio____loaders____nonce___BlockCacheObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'BlockCache' object attribute 'lock' cannot be deleted");
        return -1;
    }
    if (self->_lock != NULL) {
        CPy_DECREF(self->_lock);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_lock = tmp;
    return 0;
}

static PyObject *
_nonce___BlockCache_get_ttl(eth_portfolio____loaders____nonce___BlockCacheObject *self, void *closure)
{
    PyObject *retval = PyFloat_FromDouble(self->_ttl);
    return retval;
}

static int
_nonce___BlockCache_set_ttl(eth_portfolio____loaders____nonce___BlockCacheObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'BlockCache' object attribute 'ttl' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_ttl = tmp;
    return 0;
}

static PyObject *CPyDunder___get___nonce_____mypyc_lambda__0_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef__nonce_____mypyc_lambda__0_obj_____get__(self, instance, owner);
}
static PyObject *_nonce_____mypyc_lambda__0_obj_setup(PyTypeObject *type);
PyObject *CPyDef__nonce_____mypyc_lambda__0_obj(void);

static PyObject *
_nonce_____mypyc_lambda__0_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce_____mypyc_lambda__0_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce_____mypyc_lambda__0_obj_setup(type);
}

static int
_nonce_____mypyc_lambda__0_obj_traverse(eth_portfolio____loaders____nonce_____mypyc_lambda__0_objObject *self, visitproc visit, void *arg)
{
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
_nonce_____mypyc_lambda__0_obj_clear(eth_portfolio____loaders____nonce_____mypyc_lambda__0_objObject *self)
{
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
_nonce_____mypyc_lambda__0_obj_dealloc(eth_portfolio____loaders____nonce_____mypyc_lambda__0_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce_____mypyc_lambda__0_obj_dealloc)
    _nonce_____mypyc_lambda__0_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce_____mypyc_lambda__0_obj_vtable[2];
static bool
CPyDef__nonce_____mypyc_lambda__0_obj_trait_vtable_setup(void)
{
    CPyVTableItem _nonce_____mypyc_lambda__0_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__nonce_____mypyc_lambda__0_obj_____call__,
        (CPyVTableItem)CPyDef__nonce_____mypyc_lambda__0_obj_____get__,
    };
    memcpy(_nonce_____mypyc_lambda__0_obj_vtable, _nonce_____mypyc_lambda__0_obj_vtable_scratch, sizeof(_nonce_____mypyc_lambda__0_obj_vtable));
    return 1;
}


static PyGetSetDef _nonce_____mypyc_lambda__0_obj_getseters[] = {
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef _nonce_____mypyc_lambda__0_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy__nonce_____mypyc_lambda__0_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy__nonce_____mypyc_lambda__0_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce_____mypyc_lambda__0_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__0_obj",
    .tp_new = _nonce_____mypyc_lambda__0_obj_new,
    .tp_dealloc = (destructor)_nonce_____mypyc_lambda__0_obj_dealloc,
    .tp_traverse = (traverseproc)_nonce_____mypyc_lambda__0_obj_traverse,
    .tp_clear = (inquiry)_nonce_____mypyc_lambda__0_obj_clear,
    .tp_getset = _nonce_____mypyc_lambda__0_obj_getseters,
    .tp_methods = _nonce_____mypyc_lambda__0_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get___nonce_____mypyc_lambda__0_obj,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce_____mypyc_lambda__0_objObject),
    .tp_vectorcall_offset = offsetof(eth_portfolio____loaders____nonce_____mypyc_lambda__0_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType__nonce_____mypyc_lambda__0_obj_template = &CPyType__nonce_____mypyc_lambda__0_obj_template_;

static PyObject *
_nonce_____mypyc_lambda__0_obj_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce_____mypyc_lambda__0_objObject *self;
    self = (eth_portfolio____loaders____nonce_____mypyc_lambda__0_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce_____mypyc_lambda__0_obj_vtable;
    self->vectorcall = CPyPy__nonce_____mypyc_lambda__0_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef__nonce_____mypyc_lambda__0_obj(void)
{
    PyObject *self = _nonce_____mypyc_lambda__0_obj_setup(CPyType__nonce_____mypyc_lambda__0_obj);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *_nonce___get_nonce_at_block_env_setup(PyTypeObject *type);
PyObject *CPyDef__nonce___get_nonce_at_block_env(void);

static PyObject *
_nonce___get_nonce_at_block_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce___get_nonce_at_block_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce___get_nonce_at_block_env_setup(type);
}

static int
_nonce___get_nonce_at_block_env_traverse(eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_address);
    Py_VISIT(self->_block);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->___mypyc_temp__0);
    Py_VISIT(self->___mypyc_temp__1.f0);
    Py_VISIT(self->___mypyc_temp__1.f1);
    Py_VISIT(self->___mypyc_temp__1.f2);
    Py_VISIT(self->_nonce);
    Py_VISIT(self->___mypyc_temp__2.f0);
    Py_VISIT(self->___mypyc_temp__2.f1);
    Py_VISIT(self->___mypyc_temp__2.f2);
    Py_VISIT(self->_e);
    return 0;
}

static int
_nonce___get_nonce_at_block_env_clear(eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_address);
    Py_CLEAR(self->_block);
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___mypyc_temp__0);
    Py_CLEAR(self->___mypyc_temp__1.f0);
    Py_CLEAR(self->___mypyc_temp__1.f1);
    Py_CLEAR(self->___mypyc_temp__1.f2);
    Py_CLEAR(self->_nonce);
    Py_CLEAR(self->___mypyc_temp__2.f0);
    Py_CLEAR(self->___mypyc_temp__2.f1);
    Py_CLEAR(self->___mypyc_temp__2.f2);
    Py_CLEAR(self->_e);
    return 0;
}

static void
_nonce___get_nonce_at_block_env_dealloc(eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce___get_nonce_at_block_env_dealloc)
    _nonce___get_nonce_at_block_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce___get_nonce_at_block_env_vtable[1];
static bool
CPyDef__nonce___get_nonce_at_block_env_trait_vtable_setup(void)
{
    CPyVTableItem _nonce___get_nonce_at_block_env_vtable_scratch[] = {
        NULL
    };
    memcpy(_nonce___get_nonce_at_block_env_vtable, _nonce___get_nonce_at_block_env_vtable_scratch, sizeof(_nonce___get_nonce_at_block_env_vtable));
    return 1;
}

static PyMethodDef _nonce___get_nonce_at_block_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce___get_nonce_at_block_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "get_nonce_at_block_env",
    .tp_new = _nonce___get_nonce_at_block_env_new,
    .tp_dealloc = (destructor)_nonce___get_nonce_at_block_env_dealloc,
    .tp_traverse = (traverseproc)_nonce___get_nonce_at_block_env_traverse,
    .tp_clear = (inquiry)_nonce___get_nonce_at_block_env_clear,
    .tp_methods = _nonce___get_nonce_at_block_env_methods,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce___get_nonce_at_block_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__nonce___get_nonce_at_block_env_template = &CPyType__nonce___get_nonce_at_block_env_template_;

static PyObject *
_nonce___get_nonce_at_block_env_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *self;
    self = (eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce___get_nonce_at_block_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__1 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__2 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef__nonce___get_nonce_at_block_env(void)
{
    PyObject *self = _nonce___get_nonce_at_block_env_setup(CPyType__nonce___get_nonce_at_block_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods _nonce___get_nonce_at_block_gen_as_async = {
    .am_await = CPyDef__nonce___get_nonce_at_block_gen_____await__,
};
static PyObject *_nonce___get_nonce_at_block_gen_setup(PyTypeObject *type);
PyObject *CPyDef__nonce___get_nonce_at_block_gen(void);

static PyObject *
_nonce___get_nonce_at_block_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce___get_nonce_at_block_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce___get_nonce_at_block_gen_setup(type);
}

static int
_nonce___get_nonce_at_block_gen_traverse(eth_portfolio____loaders____nonce___get_nonce_at_block_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
_nonce___get_nonce_at_block_gen_clear(eth_portfolio____loaders____nonce___get_nonce_at_block_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
_nonce___get_nonce_at_block_gen_dealloc(eth_portfolio____loaders____nonce___get_nonce_at_block_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce___get_nonce_at_block_gen_dealloc)
    _nonce___get_nonce_at_block_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce___get_nonce_at_block_gen_vtable[7];
static bool
CPyDef__nonce___get_nonce_at_block_gen_trait_vtable_setup(void)
{
    CPyVTableItem _nonce___get_nonce_at_block_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef__nonce___get_nonce_at_block_gen_____next__,
        (CPyVTableItem)CPyDef__nonce___get_nonce_at_block_gen___send,
        (CPyVTableItem)CPyDef__nonce___get_nonce_at_block_gen_____iter__,
        (CPyVTableItem)CPyDef__nonce___get_nonce_at_block_gen___throw,
        (CPyVTableItem)CPyDef__nonce___get_nonce_at_block_gen___close,
        (CPyVTableItem)CPyDef__nonce___get_nonce_at_block_gen_____await__,
    };
    memcpy(_nonce___get_nonce_at_block_gen_vtable, _nonce___get_nonce_at_block_gen_vtable_scratch, sizeof(_nonce___get_nonce_at_block_gen_vtable));
    return 1;
}

static PyMethodDef _nonce___get_nonce_at_block_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy__nonce___get_nonce_at_block_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy__nonce___get_nonce_at_block_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy__nonce___get_nonce_at_block_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy__nonce___get_nonce_at_block_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy__nonce___get_nonce_at_block_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy__nonce___get_nonce_at_block_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce___get_nonce_at_block_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "get_nonce_at_block_gen",
    .tp_new = _nonce___get_nonce_at_block_gen_new,
    .tp_dealloc = (destructor)_nonce___get_nonce_at_block_gen_dealloc,
    .tp_traverse = (traverseproc)_nonce___get_nonce_at_block_gen_traverse,
    .tp_clear = (inquiry)_nonce___get_nonce_at_block_gen_clear,
    .tp_methods = _nonce___get_nonce_at_block_gen_methods,
    .tp_iter = CPyDef__nonce___get_nonce_at_block_gen_____iter__,
    .tp_iternext = CPyDef__nonce___get_nonce_at_block_gen_____next__,
    .tp_as_async = &_nonce___get_nonce_at_block_gen_as_async,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce___get_nonce_at_block_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__nonce___get_nonce_at_block_gen_template = &CPyType__nonce___get_nonce_at_block_gen_template_;

static PyObject *
_nonce___get_nonce_at_block_gen_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce___get_nonce_at_block_genObject *self;
    self = (eth_portfolio____loaders____nonce___get_nonce_at_block_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce___get_nonce_at_block_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef__nonce___get_nonce_at_block_gen(void)
{
    PyObject *self = _nonce___get_nonce_at_block_gen_setup(CPyType__nonce___get_nonce_at_block_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *_nonce___get_block_for_nonce_env_setup(PyTypeObject *type);
PyObject *CPyDef__nonce___get_block_for_nonce_env(void);

static PyObject *
_nonce___get_block_for_nonce_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce___get_block_for_nonce_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce___get_block_for_nonce_env_setup(type);
}

static int
_nonce___get_block_for_nonce_env_traverse(eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_address);
    if (CPyTagged_CheckLong(self->_nonce)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_nonce));
    }
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->_highest_known_nonce_lt_query);
    Py_VISIT(self->_lowest_known_nonce_gt_query);
    Py_VISIT(self->___mypyc_temp__3);
    Py_VISIT(self->___mypyc_temp__4);
    Py_VISIT(self->___mypyc_temp__6);
    Py_VISIT(self->___mypyc_temp__7.f0);
    Py_VISIT(self->___mypyc_temp__7.f1);
    Py_VISIT(self->___mypyc_temp__7.f2);
    Py_VISIT(self->___mypyc_temp__8);
    Py_VISIT(self->___mypyc_temp__11);
    if (CPyTagged_CheckLong(self->_n)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_n));
    }
    Py_VISIT(self->_lo);
    Py_VISIT(self->_hi);
    Py_VISIT(self->___mypyc_temp__12);
    Py_VISIT(self->___mypyc_temp__13.f0);
    Py_VISIT(self->___mypyc_temp__13.f1);
    Py_VISIT(self->___mypyc_temp__13.f2);
    if (CPyTagged_CheckLong(self->_range_size)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_range_size));
    }
    Py_VISIT(self->___mypyc_temp__14);
    Py_VISIT(self->___mypyc_temp__15.f0);
    Py_VISIT(self->___mypyc_temp__15.f1);
    Py_VISIT(self->___mypyc_temp__15.f2);
    Py_VISIT(self->___mypyc_temp__16.f0);
    Py_VISIT(self->___mypyc_temp__16.f1);
    Py_VISIT(self->___mypyc_temp__16.f2);
    Py_VISIT(self->___mypyc_temp__17);
    Py_VISIT(self->___mypyc_temp__18.f0);
    Py_VISIT(self->___mypyc_temp__18.f1);
    Py_VISIT(self->___mypyc_temp__18.f2);
    Py_VISIT(self->___mypyc_temp__19);
    Py_VISIT(self->___mypyc_temp__20.f0);
    Py_VISIT(self->___mypyc_temp__20.f1);
    Py_VISIT(self->___mypyc_temp__20.f2);
    Py_VISIT(self->___mypyc_temp__21);
    Py_VISIT(self->___mypyc_temp__22.f0);
    Py_VISIT(self->___mypyc_temp__22.f1);
    Py_VISIT(self->___mypyc_temp__22.f2);
    if (CPyTagged_CheckLong(self->__nonce)) {
        Py_VISIT(CPyTagged_LongAsObject(self->__nonce));
    }
    Py_VISIT(self->_old_lo);
    Py_VISIT(self->___mypyc_temp__23);
    Py_VISIT(self->___mypyc_temp__24.f0);
    Py_VISIT(self->___mypyc_temp__24.f1);
    Py_VISIT(self->___mypyc_temp__24.f2);
    if (CPyTagged_CheckLong(self->_prev_block_nonce)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_prev_block_nonce));
    }
    return 0;
}

static int
_nonce___get_block_for_nonce_env_clear(eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_address);
    if (CPyTagged_CheckLong(self->_nonce)) {
        CPyTagged __tmp = self->_nonce;
        self->_nonce = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_highest_known_nonce_lt_query);
    Py_CLEAR(self->_lowest_known_nonce_gt_query);
    Py_CLEAR(self->___mypyc_temp__3);
    Py_CLEAR(self->___mypyc_temp__4);
    Py_CLEAR(self->___mypyc_temp__6);
    Py_CLEAR(self->___mypyc_temp__7.f0);
    Py_CLEAR(self->___mypyc_temp__7.f1);
    Py_CLEAR(self->___mypyc_temp__7.f2);
    Py_CLEAR(self->___mypyc_temp__8);
    Py_CLEAR(self->___mypyc_temp__11);
    if (CPyTagged_CheckLong(self->_n)) {
        CPyTagged __tmp = self->_n;
        self->_n = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_lo);
    Py_CLEAR(self->_hi);
    Py_CLEAR(self->___mypyc_temp__12);
    Py_CLEAR(self->___mypyc_temp__13.f0);
    Py_CLEAR(self->___mypyc_temp__13.f1);
    Py_CLEAR(self->___mypyc_temp__13.f2);
    if (CPyTagged_CheckLong(self->_range_size)) {
        CPyTagged __tmp = self->_range_size;
        self->_range_size = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___mypyc_temp__14);
    Py_CLEAR(self->___mypyc_temp__15.f0);
    Py_CLEAR(self->___mypyc_temp__15.f1);
    Py_CLEAR(self->___mypyc_temp__15.f2);
    Py_CLEAR(self->___mypyc_temp__16.f0);
    Py_CLEAR(self->___mypyc_temp__16.f1);
    Py_CLEAR(self->___mypyc_temp__16.f2);
    Py_CLEAR(self->___mypyc_temp__17);
    Py_CLEAR(self->___mypyc_temp__18.f0);
    Py_CLEAR(self->___mypyc_temp__18.f1);
    Py_CLEAR(self->___mypyc_temp__18.f2);
    Py_CLEAR(self->___mypyc_temp__19);
    Py_CLEAR(self->___mypyc_temp__20.f0);
    Py_CLEAR(self->___mypyc_temp__20.f1);
    Py_CLEAR(self->___mypyc_temp__20.f2);
    Py_CLEAR(self->___mypyc_temp__21);
    Py_CLEAR(self->___mypyc_temp__22.f0);
    Py_CLEAR(self->___mypyc_temp__22.f1);
    Py_CLEAR(self->___mypyc_temp__22.f2);
    if (CPyTagged_CheckLong(self->__nonce)) {
        CPyTagged __tmp = self->__nonce;
        self->__nonce = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_old_lo);
    Py_CLEAR(self->___mypyc_temp__23);
    Py_CLEAR(self->___mypyc_temp__24.f0);
    Py_CLEAR(self->___mypyc_temp__24.f1);
    Py_CLEAR(self->___mypyc_temp__24.f2);
    if (CPyTagged_CheckLong(self->_prev_block_nonce)) {
        CPyTagged __tmp = self->_prev_block_nonce;
        self->_prev_block_nonce = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    return 0;
}

static void
_nonce___get_block_for_nonce_env_dealloc(eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce___get_block_for_nonce_env_dealloc)
    _nonce___get_block_for_nonce_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce___get_block_for_nonce_env_vtable[1];
static bool
CPyDef__nonce___get_block_for_nonce_env_trait_vtable_setup(void)
{
    CPyVTableItem _nonce___get_block_for_nonce_env_vtable_scratch[] = {
        NULL
    };
    memcpy(_nonce___get_block_for_nonce_env_vtable, _nonce___get_block_for_nonce_env_vtable_scratch, sizeof(_nonce___get_block_for_nonce_env_vtable));
    return 1;
}

static PyMethodDef _nonce___get_block_for_nonce_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce___get_block_for_nonce_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "get_block_for_nonce_env",
    .tp_new = _nonce___get_block_for_nonce_env_new,
    .tp_dealloc = (destructor)_nonce___get_block_for_nonce_env_dealloc,
    .tp_traverse = (traverseproc)_nonce___get_block_for_nonce_env_traverse,
    .tp_clear = (inquiry)_nonce___get_block_for_nonce_env_clear,
    .tp_methods = _nonce___get_block_for_nonce_env_methods,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce___get_block_for_nonce_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__nonce___get_block_for_nonce_env_template = &CPyType__nonce___get_block_for_nonce_env_template_;

static PyObject *
_nonce___get_block_for_nonce_env_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *self;
    self = (eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce___get_block_for_nonce_env_vtable;
    self->_nonce = CPY_INT_TAG;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__5 = 2;
    self->___mypyc_temp__7 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__9 = CPY_INT_TAG;
    self->___mypyc_temp__10 = CPY_INT_TAG;
    self->_n = CPY_INT_TAG;
    self->___mypyc_temp__13 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->_range_size = CPY_INT_TAG;
    self->___mypyc_temp__15 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__16 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__18 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__20 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->_debug_logs_enabled = 2;
    self->___mypyc_temp__22 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->__nonce = CPY_INT_TAG;
    self->___mypyc_temp__24 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->_prev_block_nonce = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef__nonce___get_block_for_nonce_env(void)
{
    PyObject *self = _nonce___get_block_for_nonce_env_setup(CPyType__nonce___get_block_for_nonce_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods _nonce___get_block_for_nonce_gen_as_async = {
    .am_await = CPyDef__nonce___get_block_for_nonce_gen_____await__,
};
static PyObject *_nonce___get_block_for_nonce_gen_setup(PyTypeObject *type);
PyObject *CPyDef__nonce___get_block_for_nonce_gen(void);

static PyObject *
_nonce___get_block_for_nonce_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce___get_block_for_nonce_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce___get_block_for_nonce_gen_setup(type);
}

static int
_nonce___get_block_for_nonce_gen_traverse(eth_portfolio____loaders____nonce___get_block_for_nonce_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
_nonce___get_block_for_nonce_gen_clear(eth_portfolio____loaders____nonce___get_block_for_nonce_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
_nonce___get_block_for_nonce_gen_dealloc(eth_portfolio____loaders____nonce___get_block_for_nonce_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce___get_block_for_nonce_gen_dealloc)
    _nonce___get_block_for_nonce_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce___get_block_for_nonce_gen_vtable[7];
static bool
CPyDef__nonce___get_block_for_nonce_gen_trait_vtable_setup(void)
{
    CPyVTableItem _nonce___get_block_for_nonce_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef__nonce___get_block_for_nonce_gen_____next__,
        (CPyVTableItem)CPyDef__nonce___get_block_for_nonce_gen___send,
        (CPyVTableItem)CPyDef__nonce___get_block_for_nonce_gen_____iter__,
        (CPyVTableItem)CPyDef__nonce___get_block_for_nonce_gen___throw,
        (CPyVTableItem)CPyDef__nonce___get_block_for_nonce_gen___close,
        (CPyVTableItem)CPyDef__nonce___get_block_for_nonce_gen_____await__,
    };
    memcpy(_nonce___get_block_for_nonce_gen_vtable, _nonce___get_block_for_nonce_gen_vtable_scratch, sizeof(_nonce___get_block_for_nonce_gen_vtable));
    return 1;
}

static PyMethodDef _nonce___get_block_for_nonce_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy__nonce___get_block_for_nonce_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy__nonce___get_block_for_nonce_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy__nonce___get_block_for_nonce_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy__nonce___get_block_for_nonce_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy__nonce___get_block_for_nonce_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy__nonce___get_block_for_nonce_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce___get_block_for_nonce_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "get_block_for_nonce_gen",
    .tp_new = _nonce___get_block_for_nonce_gen_new,
    .tp_dealloc = (destructor)_nonce___get_block_for_nonce_gen_dealloc,
    .tp_traverse = (traverseproc)_nonce___get_block_for_nonce_gen_traverse,
    .tp_clear = (inquiry)_nonce___get_block_for_nonce_gen_clear,
    .tp_methods = _nonce___get_block_for_nonce_gen_methods,
    .tp_iter = CPyDef__nonce___get_block_for_nonce_gen_____iter__,
    .tp_iternext = CPyDef__nonce___get_block_for_nonce_gen_____next__,
    .tp_as_async = &_nonce___get_block_for_nonce_gen_as_async,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce___get_block_for_nonce_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__nonce___get_block_for_nonce_gen_template = &CPyType__nonce___get_block_for_nonce_gen_template_;

static PyObject *
_nonce___get_block_for_nonce_gen_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce___get_block_for_nonce_genObject *self;
    self = (eth_portfolio____loaders____nonce___get_block_for_nonce_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce___get_block_for_nonce_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef__nonce___get_block_for_nonce_gen(void)
{
    PyObject *self = _nonce___get_block_for_nonce_gen_setup(CPyType__nonce___get_block_for_nonce_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *_nonce____get_area_env_setup(PyTypeObject *type);
PyObject *CPyDef__nonce____get_area_env(void);

static PyObject *
_nonce____get_area_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce____get_area_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce____get_area_env_setup(type);
}

static int
_nonce____get_area_env_traverse(eth_portfolio____loaders____nonce____get_area_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_address);
    if (CPyTagged_CheckLong(self->_nonce)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_nonce));
    }
    Py_VISIT(self->_lo);
    Py_VISIT(self->_hi);
    if (CPyTagged_CheckLong(self->_range_size)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_range_size));
    }
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    if (CPyTagged_CheckLong(self->_num_chunks)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_num_chunks));
    }
    if (CPyTagged_CheckLong(self->_chunk_size)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_chunk_size));
    }
    Py_VISIT(self->___mypyc_temp__25);
    if (CPyTagged_CheckLong(self->___mypyc_temp__26)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_temp__26));
    }
    if (CPyTagged_CheckLong(self->___mypyc_temp__27)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_temp__27));
    }
    if (CPyTagged_CheckLong(self->_i)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_i));
    }
    Py_VISIT(self->_points);
    Py_VISIT(self->___mypyc_temp__28);
    Py_VISIT(self->_point);
    Py_VISIT(self->___mypyc_temp__30);
    Py_VISIT(self->___mypyc_temp__31.f0);
    Py_VISIT(self->___mypyc_temp__31.f1);
    Py_VISIT(self->___mypyc_temp__31.f2);
    Py_VISIT(self->_nonces);
    Py_VISIT(self->___mypyc_temp__32);
    Py_VISIT(self->___mypyc_temp__34);
    Py_VISIT(self->_block);
    if (CPyTagged_CheckLong(self->_n)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_n));
    }
    return 0;
}

static int
_nonce____get_area_env_clear(eth_portfolio____loaders____nonce____get_area_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_address);
    if (CPyTagged_CheckLong(self->_nonce)) {
        CPyTagged __tmp = self->_nonce;
        self->_nonce = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_lo);
    Py_CLEAR(self->_hi);
    if (CPyTagged_CheckLong(self->_range_size)) {
        CPyTagged __tmp = self->_range_size;
        self->_range_size = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_num_chunks)) {
        CPyTagged __tmp = self->_num_chunks;
        self->_num_chunks = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_chunk_size)) {
        CPyTagged __tmp = self->_chunk_size;
        self->_chunk_size = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___mypyc_temp__25);
    if (CPyTagged_CheckLong(self->___mypyc_temp__26)) {
        CPyTagged __tmp = self->___mypyc_temp__26;
        self->___mypyc_temp__26 = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->___mypyc_temp__27)) {
        CPyTagged __tmp = self->___mypyc_temp__27;
        self->___mypyc_temp__27 = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_i)) {
        CPyTagged __tmp = self->_i;
        self->_i = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_points);
    Py_CLEAR(self->___mypyc_temp__28);
    Py_CLEAR(self->_point);
    Py_CLEAR(self->___mypyc_temp__30);
    Py_CLEAR(self->___mypyc_temp__31.f0);
    Py_CLEAR(self->___mypyc_temp__31.f1);
    Py_CLEAR(self->___mypyc_temp__31.f2);
    Py_CLEAR(self->_nonces);
    Py_CLEAR(self->___mypyc_temp__32);
    Py_CLEAR(self->___mypyc_temp__34);
    Py_CLEAR(self->_block);
    if (CPyTagged_CheckLong(self->_n)) {
        CPyTagged __tmp = self->_n;
        self->_n = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    return 0;
}

static void
_nonce____get_area_env_dealloc(eth_portfolio____loaders____nonce____get_area_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce____get_area_env_dealloc)
    _nonce____get_area_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce____get_area_env_vtable[1];
static bool
CPyDef__nonce____get_area_env_trait_vtable_setup(void)
{
    CPyVTableItem _nonce____get_area_env_vtable_scratch[] = {
        NULL
    };
    memcpy(_nonce____get_area_env_vtable, _nonce____get_area_env_vtable_scratch, sizeof(_nonce____get_area_env_vtable));
    return 1;
}

static PyMethodDef _nonce____get_area_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce____get_area_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_get_area_env",
    .tp_new = _nonce____get_area_env_new,
    .tp_dealloc = (destructor)_nonce____get_area_env_dealloc,
    .tp_traverse = (traverseproc)_nonce____get_area_env_traverse,
    .tp_clear = (inquiry)_nonce____get_area_env_clear,
    .tp_methods = _nonce____get_area_env_methods,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce____get_area_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__nonce____get_area_env_template = &CPyType__nonce____get_area_env_template_;

static PyObject *
_nonce____get_area_env_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce____get_area_envObject *self;
    self = (eth_portfolio____loaders____nonce____get_area_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce____get_area_env_vtable;
    self->_nonce = CPY_INT_TAG;
    self->_range_size = CPY_INT_TAG;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->_num_chunks = CPY_INT_TAG;
    self->_chunk_size = CPY_INT_TAG;
    self->___mypyc_temp__26 = CPY_INT_TAG;
    self->___mypyc_temp__27 = CPY_INT_TAG;
    self->_i = CPY_INT_TAG;
    self->___mypyc_temp__29 = CPY_INT_TAG;
    self->___mypyc_temp__31 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__33 = CPY_INT_TAG;
    self->___mypyc_temp__35 = CPY_INT_TAG;
    self->_n = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef__nonce____get_area_env(void)
{
    PyObject *self = _nonce____get_area_env_setup(CPyType__nonce____get_area_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods _nonce____get_area_gen_as_async = {
    .am_await = CPyDef__nonce____get_area_gen_____await__,
};
static PyObject *_nonce____get_area_gen_setup(PyTypeObject *type);
PyObject *CPyDef__nonce____get_area_gen(void);

static PyObject *
_nonce____get_area_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce____get_area_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce____get_area_gen_setup(type);
}

static int
_nonce____get_area_gen_traverse(eth_portfolio____loaders____nonce____get_area_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
_nonce____get_area_gen_clear(eth_portfolio____loaders____nonce____get_area_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
_nonce____get_area_gen_dealloc(eth_portfolio____loaders____nonce____get_area_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce____get_area_gen_dealloc)
    _nonce____get_area_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce____get_area_gen_vtable[7];
static bool
CPyDef__nonce____get_area_gen_trait_vtable_setup(void)
{
    CPyVTableItem _nonce____get_area_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__nonce____get_area_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef__nonce____get_area_gen_____next__,
        (CPyVTableItem)CPyDef__nonce____get_area_gen___send,
        (CPyVTableItem)CPyDef__nonce____get_area_gen_____iter__,
        (CPyVTableItem)CPyDef__nonce____get_area_gen___throw,
        (CPyVTableItem)CPyDef__nonce____get_area_gen___close,
        (CPyVTableItem)CPyDef__nonce____get_area_gen_____await__,
    };
    memcpy(_nonce____get_area_gen_vtable, _nonce____get_area_gen_vtable_scratch, sizeof(_nonce____get_area_gen_vtable));
    return 1;
}

static PyMethodDef _nonce____get_area_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy__nonce____get_area_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy__nonce____get_area_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy__nonce____get_area_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy__nonce____get_area_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy__nonce____get_area_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy__nonce____get_area_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy__nonce____get_area_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce____get_area_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_get_area_gen",
    .tp_new = _nonce____get_area_gen_new,
    .tp_dealloc = (destructor)_nonce____get_area_gen_dealloc,
    .tp_traverse = (traverseproc)_nonce____get_area_gen_traverse,
    .tp_clear = (inquiry)_nonce____get_area_gen_clear,
    .tp_methods = _nonce____get_area_gen_methods,
    .tp_iter = CPyDef__nonce____get_area_gen_____iter__,
    .tp_iternext = CPyDef__nonce____get_area_gen_____next__,
    .tp_as_async = &_nonce____get_area_gen_as_async,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce____get_area_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__nonce____get_area_gen_template = &CPyType__nonce____get_area_gen_template_;

static PyObject *
_nonce____get_area_gen_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce____get_area_genObject *self;
    self = (eth_portfolio____loaders____nonce____get_area_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce____get_area_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef__nonce____get_area_gen(void)
{
    PyObject *self = _nonce____get_area_gen_setup(CPyType__nonce____get_area_gen);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *_nonce___get_block_number_env_setup(PyTypeObject *type);
PyObject *CPyDef__nonce___get_block_number_env(void);

static PyObject *
_nonce___get_block_number_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce___get_block_number_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce___get_block_number_env_setup(type);
}

static int
_nonce___get_block_number_env_traverse(eth_portfolio____loaders____nonce___get_block_number_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->___mypyc_temp__36);
    Py_VISIT(self->___mypyc_temp__37);
    Py_VISIT(self->___mypyc_temp__39);
    Py_VISIT(self->___mypyc_temp__40.f0);
    Py_VISIT(self->___mypyc_temp__40.f1);
    Py_VISIT(self->___mypyc_temp__40.f2);
    Py_VISIT(self->___mypyc_temp__41);
    Py_VISIT(self->___mypyc_temp__42);
    Py_VISIT(self->___mypyc_temp__43.f0);
    Py_VISIT(self->___mypyc_temp__43.f1);
    Py_VISIT(self->___mypyc_temp__43.f2);
    Py_VISIT(self->_block);
    Py_VISIT(self->___mypyc_temp__44.f0);
    Py_VISIT(self->___mypyc_temp__44.f1);
    Py_VISIT(self->___mypyc_temp__44.f2);
    Py_VISIT(self->___mypyc_temp__45);
    Py_VISIT(self->___mypyc_temp__46.f0);
    Py_VISIT(self->___mypyc_temp__46.f1);
    Py_VISIT(self->___mypyc_temp__46.f2);
    Py_VISIT(self->___mypyc_temp__47);
    Py_VISIT(self->___mypyc_temp__48.f0);
    Py_VISIT(self->___mypyc_temp__48.f1);
    Py_VISIT(self->___mypyc_temp__48.f2);
    return 0;
}

static int
_nonce___get_block_number_env_clear(eth_portfolio____loaders____nonce___get_block_number_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___mypyc_temp__36);
    Py_CLEAR(self->___mypyc_temp__37);
    Py_CLEAR(self->___mypyc_temp__39);
    Py_CLEAR(self->___mypyc_temp__40.f0);
    Py_CLEAR(self->___mypyc_temp__40.f1);
    Py_CLEAR(self->___mypyc_temp__40.f2);
    Py_CLEAR(self->___mypyc_temp__41);
    Py_CLEAR(self->___mypyc_temp__42);
    Py_CLEAR(self->___mypyc_temp__43.f0);
    Py_CLEAR(self->___mypyc_temp__43.f1);
    Py_CLEAR(self->___mypyc_temp__43.f2);
    Py_CLEAR(self->_block);
    Py_CLEAR(self->___mypyc_temp__44.f0);
    Py_CLEAR(self->___mypyc_temp__44.f1);
    Py_CLEAR(self->___mypyc_temp__44.f2);
    Py_CLEAR(self->___mypyc_temp__45);
    Py_CLEAR(self->___mypyc_temp__46.f0);
    Py_CLEAR(self->___mypyc_temp__46.f1);
    Py_CLEAR(self->___mypyc_temp__46.f2);
    Py_CLEAR(self->___mypyc_temp__47);
    Py_CLEAR(self->___mypyc_temp__48.f0);
    Py_CLEAR(self->___mypyc_temp__48.f1);
    Py_CLEAR(self->___mypyc_temp__48.f2);
    return 0;
}

static void
_nonce___get_block_number_env_dealloc(eth_portfolio____loaders____nonce___get_block_number_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce___get_block_number_env_dealloc)
    _nonce___get_block_number_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce___get_block_number_env_vtable[1];
static bool
CPyDef__nonce___get_block_number_env_trait_vtable_setup(void)
{
    CPyVTableItem _nonce___get_block_number_env_vtable_scratch[] = {
        NULL
    };
    memcpy(_nonce___get_block_number_env_vtable, _nonce___get_block_number_env_vtable_scratch, sizeof(_nonce___get_block_number_env_vtable));
    return 1;
}

static PyMethodDef _nonce___get_block_number_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce___get_block_number_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "get_block_number_env",
    .tp_new = _nonce___get_block_number_env_new,
    .tp_dealloc = (destructor)_nonce___get_block_number_env_dealloc,
    .tp_traverse = (traverseproc)_nonce___get_block_number_env_traverse,
    .tp_clear = (inquiry)_nonce___get_block_number_env_clear,
    .tp_methods = _nonce___get_block_number_env_methods,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce___get_block_number_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__nonce___get_block_number_env_template = &CPyType__nonce___get_block_number_env_template_;

static PyObject *
_nonce___get_block_number_env_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce___get_block_number_envObject *self;
    self = (eth_portfolio____loaders____nonce___get_block_number_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce___get_block_number_env_vtable;
    self->bitmap = 0;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__38 = 2;
    self->___mypyc_temp__40 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->_ts = -113.0;
    self->___mypyc_temp__43 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__44 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__46 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__48 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef__nonce___get_block_number_env(void)
{
    PyObject *self = _nonce___get_block_number_env_setup(CPyType__nonce___get_block_number_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods _nonce___get_block_number_gen_as_async = {
    .am_await = CPyDef__nonce___get_block_number_gen_____await__,
};
static PyObject *_nonce___get_block_number_gen_setup(PyTypeObject *type);
PyObject *CPyDef__nonce___get_block_number_gen(void);

static PyObject *
_nonce___get_block_number_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__nonce___get_block_number_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _nonce___get_block_number_gen_setup(type);
}

static int
_nonce___get_block_number_gen_traverse(eth_portfolio____loaders____nonce___get_block_number_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
_nonce___get_block_number_gen_clear(eth_portfolio____loaders____nonce___get_block_number_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
_nonce___get_block_number_gen_dealloc(eth_portfolio____loaders____nonce___get_block_number_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _nonce___get_block_number_gen_dealloc)
    _nonce___get_block_number_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _nonce___get_block_number_gen_vtable[7];
static bool
CPyDef__nonce___get_block_number_gen_trait_vtable_setup(void)
{
    CPyVTableItem _nonce___get_block_number_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__nonce___get_block_number_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef__nonce___get_block_number_gen_____next__,
        (CPyVTableItem)CPyDef__nonce___get_block_number_gen___send,
        (CPyVTableItem)CPyDef__nonce___get_block_number_gen_____iter__,
        (CPyVTableItem)CPyDef__nonce___get_block_number_gen___throw,
        (CPyVTableItem)CPyDef__nonce___get_block_number_gen___close,
        (CPyVTableItem)CPyDef__nonce___get_block_number_gen_____await__,
    };
    memcpy(_nonce___get_block_number_gen_vtable, _nonce___get_block_number_gen_vtable_scratch, sizeof(_nonce___get_block_number_gen_vtable));
    return 1;
}

static PyMethodDef _nonce___get_block_number_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy__nonce___get_block_number_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy__nonce___get_block_number_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy__nonce___get_block_number_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy__nonce___get_block_number_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy__nonce___get_block_number_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy__nonce___get_block_number_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy__nonce___get_block_number_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__nonce___get_block_number_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "get_block_number_gen",
    .tp_new = _nonce___get_block_number_gen_new,
    .tp_dealloc = (destructor)_nonce___get_block_number_gen_dealloc,
    .tp_traverse = (traverseproc)_nonce___get_block_number_gen_traverse,
    .tp_clear = (inquiry)_nonce___get_block_number_gen_clear,
    .tp_methods = _nonce___get_block_number_gen_methods,
    .tp_iter = CPyDef__nonce___get_block_number_gen_____iter__,
    .tp_iternext = CPyDef__nonce___get_block_number_gen_____next__,
    .tp_as_async = &_nonce___get_block_number_gen_as_async,
    .tp_basicsize = sizeof(eth_portfolio____loaders____nonce___get_block_number_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__nonce___get_block_number_gen_template = &CPyType__nonce___get_block_number_gen_template_;

static PyObject *
_nonce___get_block_number_gen_setup(PyTypeObject *type)
{
    eth_portfolio____loaders____nonce___get_block_number_genObject *self;
    self = (eth_portfolio____loaders____nonce___get_block_number_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _nonce___get_block_number_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef__nonce___get_block_number_gen(void)
{
    PyObject *self = _nonce___get_block_number_gen_setup(CPyType__nonce___get_block_number_gen);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef _noncemodule_methods[] = {
    {"get_nonce_at_block", (PyCFunction)CPyPy__nonce___get_nonce_at_block, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_block_for_nonce", (PyCFunction)CPyPy__nonce___get_block_for_nonce, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"_get_area", (PyCFunction)CPyPy__nonce____get_area, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"_update_nonces", (PyCFunction)CPyPy__nonce____update_nonces, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"_get_num_chunks", (PyCFunction)CPyPy__nonce____get_num_chunks, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_block_number", (PyCFunction)CPyPy__nonce___get_block_number, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _noncemodule = {
    PyModuleDef_HEAD_INIT,
    "eth_portfolio._loaders._nonce",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    _noncemodule_methods
};

PyObject *CPyInit_eth_portfolio____loaders____nonce(void)
{
    PyObject* modname = NULL;
    if (CPyModule_eth_portfolio____loaders____nonce_internal) {
        Py_INCREF(CPyModule_eth_portfolio____loaders____nonce_internal);
        return CPyModule_eth_portfolio____loaders____nonce_internal;
    }
    CPyModule_eth_portfolio____loaders____nonce_internal = PyModule_Create(&_noncemodule);
    if (unlikely(CPyModule_eth_portfolio____loaders____nonce_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_eth_portfolio____loaders____nonce_internal, "__name__");
    CPyStatic__nonce___globals = PyModule_GetDict(CPyModule_eth_portfolio____loaders____nonce_internal);
    if (unlikely(CPyStatic__nonce___globals == NULL))
        goto fail;
    CPyType__nonce_____mypyc_lambda__0_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__nonce_____mypyc_lambda__0_obj_template, NULL, modname);
    if (unlikely(!CPyType__nonce_____mypyc_lambda__0_obj))
        goto fail;
    CPyType__nonce___get_nonce_at_block_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__nonce___get_nonce_at_block_env_template, NULL, modname);
    if (unlikely(!CPyType__nonce___get_nonce_at_block_env))
        goto fail;
    CPyType__nonce___get_nonce_at_block_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__nonce___get_nonce_at_block_gen_template, NULL, modname);
    if (unlikely(!CPyType__nonce___get_nonce_at_block_gen))
        goto fail;
    CPyType__nonce___get_block_for_nonce_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__nonce___get_block_for_nonce_env_template, NULL, modname);
    if (unlikely(!CPyType__nonce___get_block_for_nonce_env))
        goto fail;
    CPyType__nonce___get_block_for_nonce_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__nonce___get_block_for_nonce_gen_template, NULL, modname);
    if (unlikely(!CPyType__nonce___get_block_for_nonce_gen))
        goto fail;
    CPyType__nonce____get_area_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__nonce____get_area_env_template, NULL, modname);
    if (unlikely(!CPyType__nonce____get_area_env))
        goto fail;
    CPyType__nonce____get_area_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__nonce____get_area_gen_template, NULL, modname);
    if (unlikely(!CPyType__nonce____get_area_gen))
        goto fail;
    CPyType__nonce___get_block_number_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__nonce___get_block_number_env_template, NULL, modname);
    if (unlikely(!CPyType__nonce___get_block_number_env))
        goto fail;
    CPyType__nonce___get_block_number_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType__nonce___get_block_number_gen_template, NULL, modname);
    if (unlikely(!CPyType__nonce___get_block_number_gen))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__nonce_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_eth_portfolio____loaders____nonce_internal;
    fail:
    Py_CLEAR(CPyModule_eth_portfolio____loaders____nonce_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic__nonce___logger);
    CPyStatic__nonce___logger = NULL;
    CPy_XDECREF(CPyStatic__nonce___logger_is_enabled);
    CPyStatic__nonce___logger_is_enabled = NULL;
    CPy_XDECREF(CPyStatic__nonce_____log);
    CPyStatic__nonce_____log = NULL;
    CPyStatic__nonce___DEBUG = CPY_INT_TAG;
    CPy_XDECREF(CPyStatic__nonce___nonces);
    CPyStatic__nonce___nonces = NULL;
    CPy_XDECREF(CPyStatic__nonce___locks);
    CPyStatic__nonce___locks = NULL;
    CPy_XDECREF(CPyStatic__nonce___get_transaction_count);
    CPyStatic__nonce___get_transaction_count = NULL;
    CPy_XDECREF(CPyStatic__nonce___igather);
    CPyStatic__nonce___igather = NULL;
    CPy_XDECREF(CPyStatic__nonce___now);
    CPyStatic__nonce___now = NULL;
    CPy_XDECREF(CPyStatic__nonce___BlockCache___lock);
    CPyStatic__nonce___BlockCache___lock = NULL;
    Py_CLEAR(CPyType__nonce___BlockCache);
    Py_CLEAR(CPyType__nonce_____mypyc_lambda__0_obj);
    Py_CLEAR(CPyType__nonce___get_nonce_at_block_env);
    Py_CLEAR(CPyType__nonce___get_nonce_at_block_gen);
    Py_CLEAR(CPyType__nonce___get_block_for_nonce_env);
    Py_CLEAR(CPyType__nonce___get_block_for_nonce_gen);
    Py_CLEAR(CPyType__nonce____get_area_env);
    Py_CLEAR(CPyType__nonce____get_area_gen);
    Py_CLEAR(CPyType__nonce___get_block_number_env);
    Py_CLEAR(CPyType__nonce___get_block_number_gen);
    return NULL;
}

PyObject *CPyDef__nonce_____mypyc_lambda__0_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = cpy_r_instance == cpy_r_r0;
    if (!cpy_r_r1) goto CPyL2;
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
CPyL2: ;
    cpy_r_r2 = PyMethod_New(cpy_r___mypyc_self__, cpy_r_instance);
    if (cpy_r_r2 == NULL) goto CPyL4;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy__nonce_____mypyc_lambda__0_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"instance", "owner", 0};
    static CPyArg_Parser parser = {"OO:__get__", kwlist, 0};
    PyObject *obj_instance;
    PyObject *obj_owner;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_instance, &obj_owner)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner = obj_owner;
    PyObject *retval = CPyDef__nonce_____mypyc_lambda__0_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__get__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce_____mypyc_lambda__0_obj_____call__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    cpy_r_r0 = (PyObject *)&PyLong_Type;
    cpy_r_r1 = CPyStatic__nonce___globals;
    cpy_r_r2 = CPyStatics[3]; /* 'defaultdict' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<lambda>", 24, CPyStatic__nonce___globals);
        goto CPyL4;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<lambda>", 24, CPyStatic__nonce___globals);
        goto CPyL4;
    }
    if (likely(PyDict_Check(cpy_r_r6)))
        cpy_r_r7 = cpy_r_r6;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/_nonce.py", "<lambda>", 24, CPyStatic__nonce___globals, "dict", cpy_r_r6);
        goto CPyL4;
    }
    return cpy_r_r7;
CPyL4: ;
    cpy_r_r8 = NULL;
    return cpy_r_r8;
}

PyObject *CPyPy__nonce_____mypyc_lambda__0_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__call__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, PyVectorcall_NARGS(nargs), kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *retval = CPyDef__nonce_____mypyc_lambda__0_obj_____call__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<lambda>", 24, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    tuple_T3OOO cpy_r_r24;
    char cpy_r_r25;
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    tuple_T3OOO cpy_r_r29;
    tuple_T3OOO cpy_r_r30;
    tuple_T3OOO cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    CPyTagged cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
    tuple_T3OOO cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    int32_t cpy_r_r57;
    char cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    tuple_T3OOO cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject **cpy_r_r81;
    PyObject *cpy_r_r82;
    tuple_T3OOO cpy_r_r83;
    char cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    char cpy_r_r87;
    PyObject *cpy_r_r88;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_gen", "__mypyc_env__", 34, CPyStatic__nonce___globals);
        goto CPyL88;
    }
    CPy_INCREF_NO_IMM(cpy_r_r2);
CPyL1: ;
    cpy_r_r3 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__;
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "__mypyc_next_label__", 34, CPyStatic__nonce___globals);
        goto CPyL89;
    }
    CPyTagged_INCREF(cpy_r_r3);
    goto CPyL83;
CPyL2: ;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_type != cpy_r_r4;
    if (cpy_r_r5) {
        goto CPyL90;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
        goto CPyL87;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r6 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_address;
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "address", 54, CPyStatic__nonce___globals);
        goto CPyL91;
    }
    CPy_INCREF(cpy_r_r6);
CPyL6: ;
    cpy_r_r7 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "block", 54, CPyStatic__nonce___globals);
        goto CPyL92;
    }
    CPy_INCREF(cpy_r_r7);
CPyL7: ;
    cpy_r_r8 = CPyStatic__nonce___get_transaction_count;
    if (unlikely(cpy_r_r8 == NULL)) {
        goto CPyL93;
    } else
        goto CPyL10;
CPyL8: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"get_transaction_count\" was not set");
    cpy_r_r9 = 0;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL51;
    } else
        goto CPyL94;
CPyL9: ;
    CPy_Unreachable();
CPyL10: ;
    PyObject *cpy_r_r10[2] = {cpy_r_r6, cpy_r_r7};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = CPyStatics[419]; /* ('block_identifier',) */
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r8, cpy_r_r11, 1, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL95;
    }
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r7);
    cpy_r_r14 = CPy_GetCoro(cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL91;
    }
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__0);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__0 = cpy_r_r14;
    cpy_r_r15 = 1;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", -1, CPyStatic__nonce___globals);
        goto CPyL91;
    }
    cpy_r_r16 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "__mypyc_temp__0", -1, CPyStatic__nonce___globals);
        goto CPyL91;
    }
    CPy_INCREF(cpy_r_r16);
CPyL14: ;
    cpy_r_r17 = CPyIter_Next(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (cpy_r_r17 == NULL) {
        goto CPyL96;
    } else
        goto CPyL17;
CPyL15: ;
    cpy_r_r18 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL51;
    }
    cpy_r_r19 = cpy_r_r18;
    goto CPyL40;
CPyL17: ;
    cpy_r_r20 = cpy_r_r17;
CPyL18: ;
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__ = 2;
    cpy_r_r21 = 1;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL97;
    } else
        goto CPyL98;
CPyL19: ;
    return cpy_r_r20;
CPyL20: ;
    cpy_r_r22 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r23 = cpy_r_type != cpy_r_r22;
    if (!cpy_r_r23) goto CPyL23;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL24;
    } else
        goto CPyL99;
CPyL22: ;
    CPy_Unreachable();
CPyL23: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL35;
CPyL24: ;
    cpy_r_r24 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__1.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__1.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__1.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__1.f2);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__1 = cpy_r_r24;
    cpy_r_r25 = 1;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", -1, CPyStatic__nonce___globals);
        goto CPyL100;
    }
    cpy_r_r26 = (PyObject **)&cpy_r_r1;
    cpy_r_r27 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "__mypyc_temp__0", -1, CPyStatic__nonce___globals);
        goto CPyL100;
    }
    CPy_INCREF(cpy_r_r27);
CPyL26: ;
    cpy_r_r28 = CPy_YieldFromErrorHandle(cpy_r_r27, cpy_r_r26);
    CPy_DecRef(cpy_r_r27);
    if (unlikely(cpy_r_r28 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL100;
    }
    if (cpy_r_r28) goto CPyL30;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r20 = cpy_r_r1;
    cpy_r_r29 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r29.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "__mypyc_temp__1", -1, CPyStatic__nonce___globals);
        goto CPyL101;
    }
    CPy_INCREF(cpy_r_r29.f0);
    CPy_INCREF(cpy_r_r29.f1);
    CPy_INCREF(cpy_r_r29.f2);
CPyL29: ;
    CPy_RestoreExcInfo(cpy_r_r29);
    CPy_DecRef(cpy_r_r29.f0);
    CPy_DecRef(cpy_r_r29.f1);
    CPy_DecRef(cpy_r_r29.f2);
    goto CPyL18;
CPyL30: ;
    cpy_r_r19 = cpy_r_r1;
    cpy_r_r30 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r30.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "__mypyc_temp__1", -1, CPyStatic__nonce___globals);
        goto CPyL102;
    }
    CPy_INCREF(cpy_r_r30.f0);
    CPy_INCREF(cpy_r_r30.f1);
    CPy_INCREF(cpy_r_r30.f2);
CPyL31: ;
    CPy_RestoreExcInfo(cpy_r_r30);
    CPy_DecRef(cpy_r_r30.f0);
    CPy_DecRef(cpy_r_r30.f1);
    CPy_DecRef(cpy_r_r30.f2);
    goto CPyL40;
CPyL32: ;
    cpy_r_r31 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r31.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "__mypyc_temp__1", -1, CPyStatic__nonce___globals);
        goto CPyL51;
    }
    CPy_INCREF(cpy_r_r31.f0);
    CPy_INCREF(cpy_r_r31.f1);
    CPy_INCREF(cpy_r_r31.f2);
CPyL33: ;
    CPy_RestoreExcInfo(cpy_r_r31);
    CPy_DecRef(cpy_r_r31.f0);
    CPy_DecRef(cpy_r_r31.f1);
    CPy_DecRef(cpy_r_r31.f2);
    cpy_r_r32 = CPy_KeepPropagating();
    if (!cpy_r_r32) {
        goto CPyL51;
    } else
        goto CPyL103;
CPyL34: ;
    CPy_Unreachable();
CPyL35: ;
    cpy_r_r33 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "__mypyc_temp__0", -1, CPyStatic__nonce___globals);
        goto CPyL104;
    }
    CPy_INCREF(cpy_r_r33);
CPyL36: ;
    cpy_r_r34 = CPyIter_Send(cpy_r_r33, cpy_r_arg);
    CPy_DECREF(cpy_r_r33);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r34 == NULL) goto CPyL105;
    cpy_r_r20 = cpy_r_r34;
    goto CPyL18;
CPyL38: ;
    cpy_r_r35 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL51;
    }
    cpy_r_r19 = cpy_r_r35;
CPyL40: ;
    cpy_r_r36 = CPyStatics[408]; /* 1 */
    cpy_r_r37 = PyNumber_Subtract(cpy_r_r19, cpy_r_r36);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL51;
    }
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_nonce != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_nonce);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_nonce = cpy_r_r37;
    cpy_r_r38 = 1;
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 54, CPyStatic__nonce___globals);
        goto CPyL51;
    }
    cpy_r_r39 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_address;
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "address", 55, CPyStatic__nonce___globals);
        goto CPyL51;
    }
    CPy_INCREF(cpy_r_r39);
CPyL43: ;
    cpy_r_r40 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_nonce;
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "nonce", 55, CPyStatic__nonce___globals);
        goto CPyL106;
    }
    CPy_INCREF(cpy_r_r40);
CPyL44: ;
    cpy_r_r41 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "block", 55, CPyStatic__nonce___globals);
        goto CPyL107;
    }
    CPy_INCREF(cpy_r_r41);
CPyL45: ;
    if (likely(PyLong_Check(cpy_r_r40)))
        cpy_r_r42 = CPyTagged_FromObject(cpy_r_r40);
    else {
        CPy_TypeError("int", cpy_r_r40); cpy_r_r42 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 55, CPyStatic__nonce___globals);
        goto CPyL108;
    }
    cpy_r_r43 = CPyDef__nonce____update_nonces(cpy_r_r39, cpy_r_r42, cpy_r_r41);
    CPy_DECREF(cpy_r_r39);
    CPyTagged_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 55, CPyStatic__nonce___globals);
        goto CPyL51;
    } else
        goto CPyL109;
CPyL47: ;
    cpy_r_r44 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_nonce;
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "nonce", 56, CPyStatic__nonce___globals);
        goto CPyL51;
    }
    CPy_INCREF(cpy_r_r44);
CPyL48: ;
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r45 = 1;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 56, CPyStatic__nonce___globals);
        goto CPyL110;
    } else
        goto CPyL111;
CPyL49: ;
    CPyGen_SetStopIterationValue(cpy_r_r44);
    CPy_DECREF(cpy_r_r44);
    if (!0) goto CPyL87;
    CPy_Unreachable();
CPyL51: ;
    cpy_r_r46 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__2.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__2.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__2.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__2.f2);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__2 = cpy_r_r46;
    cpy_r_r47 = 1;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", -1, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    cpy_r_r48 = CPyModule_builtins;
    cpy_r_r49 = CPyStatics[5]; /* 'ValueError' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 57, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    cpy_r_r51 = CPy_ExceptionMatches(cpy_r_r50);
    CPy_DecRef(cpy_r_r50);
    if (!cpy_r_r51) goto CPyL78;
    cpy_r_r52 = CPy_GetExcValue();
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_e != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_e);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_e = cpy_r_r52;
    cpy_r_r53 = 1;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 57, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    cpy_r_r54 = CPyStatics[6]; /* 'error creating execution cursor' */
    cpy_r_r55 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_e;
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "e", 59, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    CPy_INCREF(cpy_r_r55);
CPyL56: ;
    cpy_r_r56 = PyObject_Str(cpy_r_r55);
    CPy_DecRef(cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 59, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    cpy_r_r57 = PyUnicode_Contains(cpy_r_r56, cpy_r_r54);
    CPy_DecRef(cpy_r_r56);
    cpy_r_r58 = cpy_r_r57 >= 0;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 59, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    cpy_r_r59 = cpy_r_r57;
    if (!cpy_r_r59) goto CPyL67;
    cpy_r_r60 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "block", 59, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    CPy_INCREF(cpy_r_r60);
CPyL60: ;
    cpy_r_r61 = CPyStatics[409]; /* 0 */
    cpy_r_r62 = PyObject_RichCompare(cpy_r_r60, cpy_r_r61, 2);
    CPy_DecRef(cpy_r_r60);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 59, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    if (unlikely(!PyBool_Check(cpy_r_r62))) {
        CPy_TypeError("bool", cpy_r_r62); cpy_r_r63 = 2;
    } else
        cpy_r_r63 = cpy_r_r62 == Py_True;
    CPy_DecRef(cpy_r_r62);
    if (unlikely(cpy_r_r63 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 59, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    if (!cpy_r_r63) goto CPyL67;
    cpy_r_r64 = CPyStatics[410]; /* -1 */
    cpy_r_r65 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__2;
    if (unlikely(cpy_r_r65.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "__mypyc_temp__2", -1, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    CPy_INCREF(cpy_r_r65.f0);
    CPy_INCREF(cpy_r_r65.f1);
    CPy_INCREF(cpy_r_r65.f2);
CPyL64: ;
    CPy_RestoreExcInfo(cpy_r_r65);
    CPy_DecRef(cpy_r_r65.f0);
    CPy_DecRef(cpy_r_r65.f1);
    CPy_DecRef(cpy_r_r65.f2);
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r66 = 1;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 60, CPyStatic__nonce___globals);
        goto CPyL80;
    } else
        goto CPyL112;
CPyL65: ;
    CPyGen_SetStopIterationValue(cpy_r_r64);
    if (!0) goto CPyL87;
    CPy_Unreachable();
CPyL67: ;
    cpy_r_r67 = CPyStatics[7]; /* 'For ' */
    cpy_r_r68 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_address;
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "address", 61, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    CPy_INCREF(cpy_r_r68);
CPyL68: ;
    cpy_r_r69 = PyObject_Str(cpy_r_r68);
    CPy_DecRef(cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 61, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    cpy_r_r70 = CPyStatics[8]; /* ' at ' */
    cpy_r_r71 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "block", 61, CPyStatic__nonce___globals);
        goto CPyL113;
    }
    CPy_INCREF(cpy_r_r71);
CPyL70: ;
    cpy_r_r72 = PyObject_Str(cpy_r_r71);
    CPy_DecRef(cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 61, CPyStatic__nonce___globals);
        goto CPyL113;
    }
    cpy_r_r73 = CPyStatics[9]; /* ': ' */
    cpy_r_r74 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->_e;
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", "get_nonce_at_block_env", "e", 61, CPyStatic__nonce___globals);
        goto CPyL114;
    }
    CPy_INCREF(cpy_r_r74);
CPyL72: ;
    cpy_r_r75 = PyObject_Str(cpy_r_r74);
    CPy_DecRef(cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 61, CPyStatic__nonce___globals);
        goto CPyL114;
    }
    cpy_r_r76 = CPyStr_Build(6, cpy_r_r67, cpy_r_r69, cpy_r_r70, cpy_r_r72, cpy_r_r73, cpy_r_r75);
    CPy_DecRef(cpy_r_r69);
    CPy_DecRef(cpy_r_r72);
    CPy_DecRef(cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 61, CPyStatic__nonce___globals);
        goto CPyL80;
    }
    cpy_r_r77 = CPyModule_builtins;
    cpy_r_r78 = CPyStatics[5]; /* 'ValueError' */
    cpy_r_r79 = CPyObject_GetAttr(cpy_r_r77, cpy_r_r78);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 61, CPyStatic__nonce___globals);
        goto CPyL115;
    }
    PyObject *cpy_r_r80[1] = {cpy_r_r76};
    cpy_r_r81 = (PyObject **)&cpy_r_r80;
    cpy_r_r82 = PyObject_Vectorcall(cpy_r_r79, cpy_r_r81, 1, 0);
    CPy_DecRef(cpy_r_r79);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 61, CPyStatic__nonce___globals);
        goto CPyL115;
    }
    CPy_DecRef(cpy_r_r76);
    CPy_Raise(cpy_r_r82);
    CPy_DecRef(cpy_r_r82);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 61, CPyStatic__nonce___globals);
        goto CPyL80;
    } else
        goto CPyL116;
CPyL77: ;
    CPy_Unreachable();
CPyL78: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL80;
    } else
        goto CPyL117;
CPyL79: ;
    CPy_Unreachable();
CPyL80: ;
    cpy_r_r83 = ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r2)->___mypyc_temp__2;
    if (unlikely(cpy_r_r83.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__2' of 'get_nonce_at_block_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r83.f0);
        CPy_INCREF(cpy_r_r83.f1);
        CPy_INCREF(cpy_r_r83.f2);
    }
    CPy_DecRef(cpy_r_r2);
    if (unlikely(cpy_r_r83.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", -1, CPyStatic__nonce___globals);
        goto CPyL87;
    }
CPyL81: ;
    CPy_RestoreExcInfo(cpy_r_r83);
    CPy_DecRef(cpy_r_r83.f0);
    CPy_DecRef(cpy_r_r83.f1);
    CPy_DecRef(cpy_r_r83.f2);
    cpy_r_r84 = CPy_KeepPropagating();
    if (!cpy_r_r84) goto CPyL87;
    CPy_Unreachable();
CPyL83: ;
    cpy_r_r85 = cpy_r_r3 == 0;
    if (cpy_r_r85) goto CPyL118;
    cpy_r_r86 = cpy_r_r3 == 2;
    CPyTagged_DECREF(cpy_r_r3);
    if (cpy_r_r86) {
        goto CPyL20;
    } else
        goto CPyL119;
CPyL85: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r87 = 0;
    if (unlikely(!cpy_r_r87)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
        goto CPyL87;
    }
    CPy_Unreachable();
CPyL87: ;
    cpy_r_r88 = NULL;
    return cpy_r_r88;
CPyL88: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL87;
CPyL89: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL87;
CPyL90: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL3;
CPyL91: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL51;
CPyL92: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r6);
    goto CPyL51;
CPyL93: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    goto CPyL8;
CPyL94: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL9;
CPyL95: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    goto CPyL51;
CPyL96: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL15;
CPyL97: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL24;
CPyL98: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL19;
CPyL99: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL22;
CPyL100: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL32;
CPyL101: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r20);
    goto CPyL32;
CPyL102: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL32;
CPyL103: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL34;
CPyL104: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_arg);
    goto CPyL51;
CPyL105: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL38;
CPyL106: ;
    CPy_DecRef(cpy_r_r39);
    goto CPyL51;
CPyL107: ;
    CPy_DecRef(cpy_r_r39);
    CPy_DecRef(cpy_r_r40);
    goto CPyL51;
CPyL108: ;
    CPy_DecRef(cpy_r_r39);
    CPy_DecRef(cpy_r_r41);
    goto CPyL51;
CPyL109: ;
    CPy_DECREF(cpy_r_r43);
    goto CPyL47;
CPyL110: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL51;
CPyL111: ;
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL49;
CPyL112: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL65;
CPyL113: ;
    CPy_DecRef(cpy_r_r69);
    goto CPyL80;
CPyL114: ;
    CPy_DecRef(cpy_r_r69);
    CPy_DecRef(cpy_r_r72);
    goto CPyL80;
CPyL115: ;
    CPy_DecRef(cpy_r_r76);
    goto CPyL80;
CPyL116: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL77;
CPyL117: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL79;
CPyL118: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL2;
CPyL119: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL85;
}

PyObject *CPyPy__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", "arg", 0};
    static CPyArg_Parser parser = {"OOOO:__mypyc_generator_helper__", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value;
    PyObject *obj_traceback;
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_type = obj_type;
    PyObject *arg_value = obj_value;
    PyObject *arg_traceback = obj_traceback;
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_nonce_at_block_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__nonce___get_nonce_at_block_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_nonce_at_block_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_nonce_at_block_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_nonce_at_block_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__next__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_nonce_at_block_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__nonce___get_nonce_at_block_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_nonce_at_block_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_nonce_at_block_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__nonce___get_nonce_at_block_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "send", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_nonce_at_block_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__nonce___get_nonce_at_block_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_nonce_at_block_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_nonce_at_block_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_nonce_at_block_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__iter__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_nonce_at_block_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy__nonce___get_nonce_at_block_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_nonce_at_block_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_nonce_at_block_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef__nonce___get_nonce_at_block_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "throw", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_nonce_at_block_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[10]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef__nonce___get_nonce_at_block_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[11]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp1);
    PyObject *__tmp2 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp2);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy__nonce___get_nonce_at_block_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_nonce_at_block_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_nonce_at_block_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_nonce_at_block_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "close", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_nonce_at_block_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__nonce___get_nonce_at_block_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_nonce_at_block_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_nonce_at_block_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_nonce_at_block_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__await__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_nonce_at_block(PyObject *cpy_r_address, PyObject *cpy_r_block) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    cpy_r_r0 = CPyDef__nonce___get_nonce_at_block_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_address);
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r0)->_address != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r0)->_address);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r0)->_address = cpy_r_address;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_block);
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r0)->_block != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r0)->_block);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r0)->_block = cpy_r_block;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
        goto CPyL8;
    }
    cpy_r_r3 = CPyDef__nonce___get_nonce_at_block_gen();
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
        goto CPyL8;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_genObject *)cpy_r_r3)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce___get_nonce_at_block_genObject *)cpy_r_r3)->___mypyc_env__);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_genObject *)cpy_r_r3)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
        goto CPyL9;
    }
    if (((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_nonce_at_block_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r5 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
        goto CPyL10;
    }
    return cpy_r_r3;
CPyL7: ;
    cpy_r_r6 = NULL;
    return cpy_r_r6;
CPyL8: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL7;
CPyL9: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r3);
    goto CPyL7;
CPyL10: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL7;
}

PyObject *CPyPy__nonce___get_nonce_at_block(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"address", "block", 0};
    static CPyArg_Parser parser = {"OO:get_nonce_at_block", kwlist, 0};
    PyObject *obj_address;
    PyObject *obj_block;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_address, &obj_block)) {
        return NULL;
    }
    PyObject *arg_address = obj_address;
    PyObject *arg_block = obj_block;
    PyObject *retval = CPyDef__nonce___get_nonce_at_block(arg_address, arg_block);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_nonce_at_block", 34, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T3OOO cpy_r_r10;
    tuple_T3OOO cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    CPyTagged cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject **cpy_r_r31;
    PyObject *cpy_r_r32;
    char cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    char cpy_r_r44;
    tuple_T3OOO cpy_r_r45;
    char cpy_r_r46;
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    char cpy_r_r49;
    tuple_T3OOO cpy_r_r50;
    tuple_T3OOO cpy_r_r51;
    tuple_T3OOO cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    char cpy_r_r58;
    PyObject *cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    char cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    char cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    int64_t cpy_r_r69;
    CPyTagged cpy_r_r70;
    char cpy_r_r71;
    PyObject *cpy_r_r72;
    char cpy_r_r73;
    PyObject *cpy_r_r74;
    CPyTagged cpy_r_r75;
    tuple_T3CIO cpy_r_r76;
    CPyTagged cpy_r_r77;
    char cpy_r_r78;
    char cpy_r_r79;
    PyObject *cpy_r_r80;
    CPyTagged cpy_r_r81;
    char cpy_r_r82;
    CPyTagged cpy_r_r83;
    CPyTagged cpy_r_r84;
    int64_t cpy_r_r85;
    char cpy_r_r86;
    int64_t cpy_r_r87;
    char cpy_r_r88;
    char cpy_r_r89;
    char cpy_r_r90;
    char cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    char cpy_r_r94;
    CPyTagged cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    int32_t cpy_r_r99;
    char cpy_r_r100;
    char cpy_r_r101;
    CPyTagged cpy_r_r102;
    PyObject *cpy_r_r103;
    char cpy_r_r104;
    CPyTagged cpy_r_r105;
    CPyTagged cpy_r_r106;
    int64_t cpy_r_r107;
    char cpy_r_r108;
    char cpy_r_r109;
    char cpy_r_r110;
    char cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    char cpy_r_r114;
    CPyTagged cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    int32_t cpy_r_r119;
    char cpy_r_r120;
    char cpy_r_r121;
    CPyTagged cpy_r_r122;
    PyObject *cpy_r_r123;
    char cpy_r_r124;
    PyObject *cpy_r_r125;
    CPyTagged cpy_r_r126;
    char cpy_r_r127;
    char cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    char cpy_r_r131;
    PyObject *cpy_r_r132;
    char cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    char cpy_r_r139;
    PyObject *cpy_r_r140;
    char cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    char cpy_r_r144;
    PyObject *cpy_r_r145;
    char cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    char cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    char cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    char cpy_r_r161;
    PyObject *cpy_r_r162;
    char cpy_r_r163;
    tuple_T3OOO cpy_r_r164;
    char cpy_r_r165;
    PyObject **cpy_r_r166;
    PyObject *cpy_r_r167;
    char cpy_r_r168;
    tuple_T3OOO cpy_r_r169;
    tuple_T3OOO cpy_r_r170;
    tuple_T3OOO cpy_r_r171;
    char cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    char cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    CPyTagged cpy_r_r180;
    CPyTagged cpy_r_r181;
    char cpy_r_r182;
    CPyTagged cpy_r_r183;
    int64_t cpy_r_r184;
    char cpy_r_r185;
    int64_t cpy_r_r186;
    char cpy_r_r187;
    char cpy_r_r188;
    char cpy_r_r189;
    char cpy_r_r190;
    PyObject *cpy_r_r191;
    CPyTagged cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    CPyTagged cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    char cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    char cpy_r_r204;
    PyObject *cpy_r_r205;
    char cpy_r_r206;
    tuple_T3OOO cpy_r_r207;
    char cpy_r_r208;
    PyObject **cpy_r_r209;
    PyObject *cpy_r_r210;
    char cpy_r_r211;
    tuple_T3OOO cpy_r_r212;
    tuple_T3OOO cpy_r_r213;
    tuple_T3OOO cpy_r_r214;
    char cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    tuple_T2OO cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    char cpy_r_r223;
    PyObject *cpy_r_r224;
    char cpy_r_r225;
    tuple_T3OOO cpy_r_r226;
    char cpy_r_r227;
    char cpy_r_r228;
    tuple_T3OOO cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject **cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    char cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    char cpy_r_r245;
    PyObject *cpy_r_r246;
    char cpy_r_r247;
    tuple_T3OOO cpy_r_r248;
    char cpy_r_r249;
    PyObject **cpy_r_r250;
    PyObject *cpy_r_r251;
    char cpy_r_r252;
    tuple_T3OOO cpy_r_r253;
    tuple_T3OOO cpy_r_r254;
    tuple_T3OOO cpy_r_r255;
    char cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    int32_t cpy_r_r260;
    char cpy_r_r261;
    char cpy_r_r262;
    tuple_T3OOO cpy_r_r263;
    tuple_T3OOO cpy_r_r264;
    char cpy_r_r265;
    tuple_T3OOO cpy_r_r266;
    tuple_T3OOO cpy_r_r267;
    char cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject **cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    char cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject *cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    char cpy_r_r282;
    PyObject *cpy_r_r283;
    char cpy_r_r284;
    tuple_T3OOO cpy_r_r285;
    char cpy_r_r286;
    PyObject **cpy_r_r287;
    PyObject *cpy_r_r288;
    char cpy_r_r289;
    tuple_T3OOO cpy_r_r290;
    tuple_T3OOO cpy_r_r291;
    tuple_T3OOO cpy_r_r292;
    char cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    char cpy_r_r297;
    CPyTagged cpy_r_r298;
    char cpy_r_r299;
    PyObject *cpy_r_r300;
    char cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject **cpy_r_r304;
    PyObject *cpy_r_r305;
    char cpy_r_r306;
    char cpy_r_r307;
    PyObject *cpy_r_r308;
    PyObject *cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    char cpy_r_r312;
    PyObject *cpy_r_r313;
    PyObject *cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    char cpy_r_r318;
    PyObject *cpy_r_r319;
    char cpy_r_r320;
    tuple_T3OOO cpy_r_r321;
    char cpy_r_r322;
    PyObject **cpy_r_r323;
    PyObject *cpy_r_r324;
    char cpy_r_r325;
    tuple_T3OOO cpy_r_r326;
    tuple_T3OOO cpy_r_r327;
    tuple_T3OOO cpy_r_r328;
    char cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject *cpy_r_r332;
    CPyTagged cpy_r_r333;
    char cpy_r_r334;
    CPyTagged cpy_r_r335;
    CPyTagged cpy_r_r336;
    int64_t cpy_r_r337;
    char cpy_r_r338;
    int64_t cpy_r_r339;
    char cpy_r_r340;
    char cpy_r_r341;
    char cpy_r_r342;
    char cpy_r_r343;
    PyObject *cpy_r_r344;
    char cpy_r_r345;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    PyObject *cpy_r_r348;
    PyObject *cpy_r_r349;
    CPyTagged cpy_r_r350;
    double cpy_r_r351;
    char cpy_r_r352;
    CPyTagged cpy_r_r353;
    PyObject *cpy_r_r354;
    char cpy_r_r355;
    CPyTagged cpy_r_r356;
    PyObject *cpy_r_r357;
    PyObject *cpy_r_r358;
    char cpy_r_r359;
    char cpy_r_r360;
    CPyTagged cpy_r_r361;
    char cpy_r_r362;
    PyObject *cpy_r_r363;
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    CPyTagged cpy_r_r366;
    PyObject *cpy_r_r367;
    tuple_T4OOIO cpy_r_r368;
    PyObject *cpy_r_r369;
    char cpy_r_r370;
    PyObject *cpy_r_r371;
    PyObject *cpy_r_r372;
    PyObject **cpy_r_r374;
    PyObject *cpy_r_r375;
    PyObject *cpy_r_r376;
    PyObject *cpy_r_r377;
    PyObject *cpy_r_r378;
    PyObject *cpy_r_r379;
    CPyTagged cpy_r_r380;
    PyObject *cpy_r_r381;
    PyObject *cpy_r_r382;
    PyObject *cpy_r_r383;
    char cpy_r_r384;
    PyObject *cpy_r_r385;
    PyObject *cpy_r_r386;
    PyObject *cpy_r_r387;
    PyObject *cpy_r_r388;
    PyObject *cpy_r_r389;
    char cpy_r_r390;
    PyObject *cpy_r_r391;
    char cpy_r_r392;
    tuple_T3OOO cpy_r_r393;
    char cpy_r_r394;
    PyObject **cpy_r_r395;
    PyObject *cpy_r_r396;
    char cpy_r_r397;
    tuple_T3OOO cpy_r_r398;
    tuple_T3OOO cpy_r_r399;
    tuple_T3OOO cpy_r_r400;
    char cpy_r_r401;
    PyObject *cpy_r_r402;
    PyObject *cpy_r_r403;
    PyObject *cpy_r_r404;
    CPyTagged cpy_r_r405;
    char cpy_r_r406;
    CPyTagged cpy_r_r407;
    CPyTagged cpy_r_r408;
    int64_t cpy_r_r409;
    char cpy_r_r410;
    int64_t cpy_r_r411;
    char cpy_r_r412;
    char cpy_r_r413;
    char cpy_r_r414;
    char cpy_r_r415;
    char cpy_r_r416;
    PyObject *cpy_r_r417;
    char cpy_r_r418;
    PyObject *cpy_r_r419;
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    double cpy_r_r422;
    char cpy_r_r423;
    CPyTagged cpy_r_r424;
    PyObject *cpy_r_r425;
    PyObject *cpy_r_r426;
    char cpy_r_r427;
    char cpy_r_r428;
    CPyTagged cpy_r_r429;
    char cpy_r_r430;
    PyObject *cpy_r_r431;
    PyObject *cpy_r_r432;
    PyObject *cpy_r_r433;
    CPyTagged cpy_r_r434;
    PyObject *cpy_r_r435;
    tuple_T4OOIO cpy_r_r436;
    PyObject *cpy_r_r437;
    char cpy_r_r438;
    PyObject *cpy_r_r439;
    PyObject *cpy_r_r440;
    PyObject **cpy_r_r442;
    PyObject *cpy_r_r443;
    char cpy_r_r444;
    CPyTagged cpy_r_r445;
    char cpy_r_r446;
    PyObject *cpy_r_r447;
    CPyTagged cpy_r_r448;
    PyObject *cpy_r_r449;
    PyObject *cpy_r_r450;
    tuple_T3IOO cpy_r_r451;
    PyObject *cpy_r_r452;
    char cpy_r_r453;
    PyObject *cpy_r_r454;
    PyObject *cpy_r_r455;
    PyObject **cpy_r_r457;
    PyObject *cpy_r_r458;
    PyObject *cpy_r_r459;
    char cpy_r_r460;
    PyObject *cpy_r_r461;
    char cpy_r_r462;
    char cpy_r_r463;
    char cpy_r_r464;
    char cpy_r_r465;
    char cpy_r_r466;
    char cpy_r_r467;
    char cpy_r_r468;
    char cpy_r_r469;
    char cpy_r_r470;
    char cpy_r_r471;
    PyObject *cpy_r_r472;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = NULL;
    cpy_r_r3 = cpy_r_r2;
    cpy_r_r4 = NULL;
    cpy_r_r5 = cpy_r_r4;
    cpy_r_r6 = NULL;
    cpy_r_r7 = cpy_r_r6;
    cpy_r_r8 = NULL;
    cpy_r_r9 = cpy_r_r8;
    tuple_T3OOO __tmp3 = { NULL, NULL, NULL };
    cpy_r_r10 = __tmp3;
    cpy_r_r11 = cpy_r_r10;
    cpy_r_r12 = NULL;
    cpy_r_r13 = cpy_r_r12;
    cpy_r_r14 = NULL;
    cpy_r_r15 = cpy_r_r14;
    cpy_r_r16 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_gen", "__mypyc_env__", 64, CPyStatic__nonce___globals);
        goto CPyL465;
    }
    CPy_INCREF_NO_IMM(cpy_r_r16);
CPyL1: ;
    cpy_r_r17 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__;
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_next_label__", 64, CPyStatic__nonce___globals);
        goto CPyL466;
    }
    CPyTagged_INCREF(cpy_r_r17);
    goto CPyL454;
CPyL2: ;
    cpy_r_r18 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r19 = cpy_r_type != cpy_r_r18;
    if (cpy_r_r19) {
        goto CPyL467;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r20 = CPyStatic__nonce___locks;
    if (unlikely(cpy_r_r20 == NULL)) {
        goto CPyL468;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"locks\" was not set");
    cpy_r_r21 = 0;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r22 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 68, CPyStatic__nonce___globals);
        goto CPyL469;
    }
    CPy_INCREF(cpy_r_r22);
CPyL9: ;
    cpy_r_r23 = CPyDict_GetItem(cpy_r_r20, cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL469;
    }
    cpy_r_r24 = PyObject_Type(cpy_r_r23);
    cpy_r_r25 = CPyStatics[12]; /* '__aexit__' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL470;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__3 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__3);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__3 = cpy_r_r26;
    cpy_r_r27 = 1;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL470;
    }
    cpy_r_r28 = CPyStatics[13]; /* '__aenter__' */
    cpy_r_r29 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r28);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL471;
    }
    PyObject *cpy_r_r30[1] = {cpy_r_r23};
    cpy_r_r31 = (PyObject **)&cpy_r_r30;
    cpy_r_r32 = PyObject_Vectorcall(cpy_r_r29, cpy_r_r31, 1, 0);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL471;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__4 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__4);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__4 = cpy_r_r23;
    cpy_r_r33 = 1;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL472;
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__5 = 1;
    cpy_r_r34 = 1;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL472;
    }
    cpy_r_r35 = CPy_GetCoro(cpy_r_r32);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL469;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__6 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__6);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__6 = cpy_r_r35;
    cpy_r_r36 = 1;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL469;
    }
    cpy_r_r37 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__6;
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__6", -1, CPyStatic__nonce___globals);
        goto CPyL469;
    }
    CPy_INCREF(cpy_r_r37);
CPyL19: ;
    cpy_r_r38 = CPyIter_Next(cpy_r_r37);
    CPy_DECREF(cpy_r_r37);
    if (cpy_r_r38 == NULL) {
        goto CPyL473;
    } else
        goto CPyL22;
CPyL20: ;
    cpy_r_r39 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL474;
    }
    cpy_r_r40 = cpy_r_r39;
    CPy_DECREF(cpy_r_r40);
    goto CPyL45;
CPyL22: ;
    cpy_r_r41 = cpy_r_r38;
CPyL23: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ = 2;
    cpy_r_r42 = 1;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL475;
    } else
        goto CPyL476;
CPyL24: ;
    return cpy_r_r41;
CPyL25: ;
    cpy_r_r43 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r44 = cpy_r_type != cpy_r_r43;
    if (!cpy_r_r44) goto CPyL28;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL29;
    } else
        goto CPyL477;
CPyL27: ;
    CPy_Unreachable();
CPyL28: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL40;
CPyL29: ;
    cpy_r_r45 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__7.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__7.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__7.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__7.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__7 = cpy_r_r45;
    cpy_r_r46 = 1;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL478;
    }
    cpy_r_r47 = (PyObject **)&cpy_r_r1;
    cpy_r_r48 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__6;
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__6", -1, CPyStatic__nonce___globals);
        goto CPyL478;
    }
    CPy_INCREF(cpy_r_r48);
CPyL31: ;
    cpy_r_r49 = CPy_YieldFromErrorHandle(cpy_r_r48, cpy_r_r47);
    CPy_DecRef(cpy_r_r48);
    if (unlikely(cpy_r_r49 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL478;
    }
    if (cpy_r_r49) goto CPyL35;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r41 = cpy_r_r1;
    cpy_r_r50 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__7;
    if (unlikely(cpy_r_r50.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__7", -1, CPyStatic__nonce___globals);
        goto CPyL479;
    }
    CPy_INCREF(cpy_r_r50.f0);
    CPy_INCREF(cpy_r_r50.f1);
    CPy_INCREF(cpy_r_r50.f2);
CPyL34: ;
    CPy_RestoreExcInfo(cpy_r_r50);
    CPy_DecRef(cpy_r_r50.f0);
    CPy_DecRef(cpy_r_r50.f1);
    CPy_DecRef(cpy_r_r50.f2);
    goto CPyL23;
CPyL35: ;
    cpy_r_r40 = cpy_r_r1;
    CPy_DecRef(cpy_r_r40);
    cpy_r_r51 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__7;
    if (unlikely(cpy_r_r51.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__7", -1, CPyStatic__nonce___globals);
        goto CPyL480;
    }
    CPy_INCREF(cpy_r_r51.f0);
    CPy_INCREF(cpy_r_r51.f1);
    CPy_INCREF(cpy_r_r51.f2);
CPyL36: ;
    CPy_RestoreExcInfo(cpy_r_r51);
    CPy_DecRef(cpy_r_r51.f0);
    CPy_DecRef(cpy_r_r51.f1);
    CPy_DecRef(cpy_r_r51.f2);
    goto CPyL45;
CPyL37: ;
    cpy_r_r52 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__7;
    if (unlikely(cpy_r_r52.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__7' of 'get_block_for_nonce_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r52.f0);
        CPy_INCREF(cpy_r_r52.f1);
        CPy_INCREF(cpy_r_r52.f2);
    }
    CPy_DecRef(cpy_r_r16);
    if (unlikely(cpy_r_r52.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL464;
    }
CPyL38: ;
    CPy_RestoreExcInfo(cpy_r_r52);
    CPy_DecRef(cpy_r_r52.f0);
    CPy_DecRef(cpy_r_r52.f1);
    CPy_DecRef(cpy_r_r52.f2);
    cpy_r_r53 = CPy_KeepPropagating();
    if (!cpy_r_r53) goto CPyL464;
    CPy_Unreachable();
CPyL40: ;
    cpy_r_r54 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__6;
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__6", -1, CPyStatic__nonce___globals);
        goto CPyL481;
    }
    CPy_INCREF(cpy_r_r54);
CPyL41: ;
    cpy_r_r55 = CPyIter_Send(cpy_r_r54, cpy_r_arg);
    CPy_DECREF(cpy_r_r54);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r55 == NULL) goto CPyL482;
    cpy_r_r41 = cpy_r_r55;
    goto CPyL23;
CPyL43: ;
    cpy_r_r56 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL474;
    }
    cpy_r_r40 = cpy_r_r56;
    CPy_DECREF(cpy_r_r40);
CPyL45: ;
    cpy_r_r57 = Py_None;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query = cpy_r_r57;
    cpy_r_r58 = 1;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 69, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r59 = Py_None;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query = cpy_r_r59;
    cpy_r_r60 = 1;
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 70, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r61 = CPyStatic__nonce___nonces;
    if (unlikely(cpy_r_r61 == NULL)) {
        goto CPyL484;
    } else
        goto CPyL50;
CPyL48: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"nonces\" was not set");
    cpy_r_r62 = 0;
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 73, CPyStatic__nonce___globals);
        goto CPyL203;
    } else
        goto CPyL485;
CPyL49: ;
    CPy_Unreachable();
CPyL50: ;
    cpy_r_r63 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 73, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r63);
CPyL51: ;
    cpy_r_r64 = CPyDict_GetItem(cpy_r_r61, cpy_r_r63);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 73, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    if (likely(PyDict_Check(cpy_r_r64)))
        cpy_r_r65 = cpy_r_r64;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 73, CPyStatic__nonce___globals, "dict", cpy_r_r64);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r65);
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__8 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__8);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__8 = cpy_r_r65;
    cpy_r_r66 = 1;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL486;
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__9 = 0;
    cpy_r_r67 = 1;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL486;
    }
    cpy_r_r68 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__8;
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__8", 73, CPyStatic__nonce___globals);
        goto CPyL486;
    }
    CPy_INCREF(cpy_r_r68);
CPyL56: ;
    cpy_r_r69 = PyDict_Size(cpy_r_r68);
    CPy_DECREF(cpy_r_r68);
    cpy_r_r70 = cpy_r_r69 << 1;
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__10 = cpy_r_r70;
    cpy_r_r71 = 1;
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL486;
    }
    cpy_r_r72 = CPyDict_GetKeysIter(cpy_r_r65);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 73, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__11 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__11);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__11 = cpy_r_r72;
    cpy_r_r73 = 1;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL483;
    }
CPyL59: ;
    cpy_r_r74 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__11;
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__11", 73, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r74);
CPyL60: ;
    cpy_r_r75 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__9;
    if (unlikely(cpy_r_r75 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__9", 73, CPyStatic__nonce___globals);
        goto CPyL487;
    }
CPyL61: ;
    cpy_r_r76 = CPyDict_NextKey(cpy_r_r74, cpy_r_r75);
    CPy_DECREF(cpy_r_r74);
    cpy_r_r77 = cpy_r_r76.f1;
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__9 = cpy_r_r77;
    cpy_r_r78 = 1;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 73, CPyStatic__nonce___globals);
        goto CPyL488;
    }
    cpy_r_r79 = cpy_r_r76.f0;
    if (!cpy_r_r79) goto CPyL489;
    cpy_r_r80 = cpy_r_r76.f2;
    CPy_INCREF(cpy_r_r80);
    CPy_DECREF(cpy_r_r76.f2);
    if (likely(PyLong_Check(cpy_r_r80)))
        cpy_r_r81 = CPyTagged_FromObject(cpy_r_r80);
    else {
        CPy_TypeError("int", cpy_r_r80); cpy_r_r81 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r80);
    if (unlikely(cpy_r_r81 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 73, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_n != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_n);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_n = cpy_r_r81;
    cpy_r_r82 = 1;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 73, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r83 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_n;
    if (unlikely(cpy_r_r83 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "n", 74, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPyTagged_INCREF(cpy_r_r83);
CPyL66: ;
    cpy_r_r84 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_nonce;
    if (unlikely(cpy_r_r84 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "nonce", 74, CPyStatic__nonce___globals);
        goto CPyL490;
    }
    CPyTagged_INCREF(cpy_r_r84);
CPyL67: ;
    cpy_r_r85 = cpy_r_r83 & 1;
    cpy_r_r86 = cpy_r_r85 != 0;
    if (cpy_r_r86) goto CPyL69;
    cpy_r_r87 = cpy_r_r84 & 1;
    cpy_r_r88 = cpy_r_r87 != 0;
    if (!cpy_r_r88) goto CPyL70;
CPyL69: ;
    cpy_r_r89 = CPyTagged_IsLt_(cpy_r_r83, cpy_r_r84);
    cpy_r_r90 = cpy_r_r89;
    goto CPyL71;
CPyL70: ;
    cpy_r_r91 = (Py_ssize_t)cpy_r_r83 < (Py_ssize_t)cpy_r_r84;
    cpy_r_r90 = cpy_r_r91;
CPyL71: ;
    CPyTagged_DECREF(cpy_r_r83);
    CPyTagged_DECREF(cpy_r_r84);
    if (!cpy_r_r90) goto CPyL81;
    cpy_r_r92 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query;
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "highest_known_nonce_lt_query", 75, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r92);
CPyL73: ;
    cpy_r_r93 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r94 = cpy_r_r92 == cpy_r_r93;
    CPy_DECREF(cpy_r_r92);
    if (cpy_r_r94) goto CPyL79;
    cpy_r_r95 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_n;
    if (unlikely(cpy_r_r95 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "n", 75, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPyTagged_INCREF(cpy_r_r95);
CPyL75: ;
    cpy_r_r96 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query;
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "highest_known_nonce_lt_query", 75, CPyStatic__nonce___globals);
        goto CPyL491;
    }
    CPy_INCREF(cpy_r_r96);
CPyL76: ;
    cpy_r_r97 = CPyTagged_StealAsObject(cpy_r_r95);
    cpy_r_r98 = PyObject_RichCompare(cpy_r_r97, cpy_r_r96, 4);
    CPy_DECREF(cpy_r_r97);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 75, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r99 = PyObject_IsTrue(cpy_r_r98);
    CPy_DECREF(cpy_r_r98);
    cpy_r_r100 = cpy_r_r99 >= 0;
    if (unlikely(!cpy_r_r100)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 75, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r101 = cpy_r_r99;
    if (!cpy_r_r101) goto CPyL96;
CPyL79: ;
    cpy_r_r102 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_n;
    if (unlikely(cpy_r_r102 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "n", 76, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPyTagged_INCREF(cpy_r_r102);
CPyL80: ;
    cpy_r_r103 = CPyTagged_StealAsObject(cpy_r_r102);
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query = cpy_r_r103;
    cpy_r_r104 = 1;
    if (unlikely(!cpy_r_r104)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 76, CPyStatic__nonce___globals);
        goto CPyL483;
    } else
        goto CPyL96;
CPyL81: ;
    cpy_r_r105 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_n;
    if (unlikely(cpy_r_r105 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "n", 77, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPyTagged_INCREF(cpy_r_r105);
CPyL82: ;
    cpy_r_r106 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_nonce;
    if (unlikely(cpy_r_r106 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "nonce", 77, CPyStatic__nonce___globals);
        goto CPyL492;
    }
    CPyTagged_INCREF(cpy_r_r106);
CPyL83: ;
    cpy_r_r107 = cpy_r_r105 & 1;
    cpy_r_r108 = cpy_r_r107 != 0;
    if (!cpy_r_r108) goto CPyL85;
    cpy_r_r109 = CPyTagged_IsEq_(cpy_r_r105, cpy_r_r106);
    cpy_r_r110 = cpy_r_r109;
    goto CPyL86;
CPyL85: ;
    cpy_r_r111 = cpy_r_r105 == cpy_r_r106;
    cpy_r_r110 = cpy_r_r111;
CPyL86: ;
    CPyTagged_DECREF(cpy_r_r105);
    CPyTagged_DECREF(cpy_r_r106);
    if (cpy_r_r110) goto CPyL96;
    cpy_r_r112 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query;
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lowest_known_nonce_gt_query", 79, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r112);
CPyL88: ;
    cpy_r_r113 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r114 = cpy_r_r112 == cpy_r_r113;
    CPy_DECREF(cpy_r_r112);
    if (cpy_r_r114) goto CPyL94;
    cpy_r_r115 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_n;
    if (unlikely(cpy_r_r115 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "n", 79, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPyTagged_INCREF(cpy_r_r115);
CPyL90: ;
    cpy_r_r116 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query;
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lowest_known_nonce_gt_query", 79, CPyStatic__nonce___globals);
        goto CPyL493;
    }
    CPy_INCREF(cpy_r_r116);
CPyL91: ;
    cpy_r_r117 = CPyTagged_StealAsObject(cpy_r_r115);
    cpy_r_r118 = PyObject_RichCompare(cpy_r_r117, cpy_r_r116, 0);
    CPy_DECREF(cpy_r_r117);
    CPy_DECREF(cpy_r_r116);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 79, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r119 = PyObject_IsTrue(cpy_r_r118);
    CPy_DECREF(cpy_r_r118);
    cpy_r_r120 = cpy_r_r119 >= 0;
    if (unlikely(!cpy_r_r120)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 79, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r121 = cpy_r_r119;
    if (!cpy_r_r121) goto CPyL96;
CPyL94: ;
    cpy_r_r122 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_n;
    if (unlikely(cpy_r_r122 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "n", 80, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPyTagged_INCREF(cpy_r_r122);
CPyL95: ;
    cpy_r_r123 = CPyTagged_StealAsObject(cpy_r_r122);
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query = cpy_r_r123;
    cpy_r_r124 = 1;
    if (unlikely(!cpy_r_r124)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 80, CPyStatic__nonce___globals);
        goto CPyL483;
    }
CPyL96: ;
    cpy_r_r125 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__8;
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__8", 73, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r125);
CPyL97: ;
    cpy_r_r126 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__10;
    if (unlikely(cpy_r_r126 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__10", 73, CPyStatic__nonce___globals);
        goto CPyL494;
    }
CPyL98: ;
    cpy_r_r127 = CPyDict_CheckSize(cpy_r_r125, cpy_r_r126);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(!cpy_r_r127)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 73, CPyStatic__nonce___globals);
        goto CPyL483;
    } else
        goto CPyL59;
CPyL99: ;
    cpy_r_r128 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r128)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 73, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r129 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query;
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "highest_known_nonce_lt_query", 82, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r129);
CPyL101: ;
    cpy_r_r130 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r131 = cpy_r_r129 != cpy_r_r130;
    CPy_DECREF(cpy_r_r129);
    if (!cpy_r_r131) goto CPyL111;
    cpy_r_r132 = CPyStatic__nonce___nonces;
    if (unlikely(cpy_r_r132 == NULL)) {
        goto CPyL495;
    } else
        goto CPyL105;
CPyL103: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"nonces\" was not set");
    cpy_r_r133 = 0;
    if (unlikely(!cpy_r_r133)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 83, CPyStatic__nonce___globals);
        goto CPyL203;
    } else
        goto CPyL496;
CPyL104: ;
    CPy_Unreachable();
CPyL105: ;
    cpy_r_r134 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 83, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r134);
CPyL106: ;
    cpy_r_r135 = CPyDict_GetItem(cpy_r_r132, cpy_r_r134);
    CPy_DECREF(cpy_r_r134);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 83, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    if (likely(PyDict_Check(cpy_r_r135)))
        cpy_r_r136 = cpy_r_r135;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 83, CPyStatic__nonce___globals, "dict", cpy_r_r135);
        goto CPyL483;
    }
    cpy_r_r137 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_highest_known_nonce_lt_query;
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "highest_known_nonce_lt_query", 83, CPyStatic__nonce___globals);
        goto CPyL497;
    }
    CPy_INCREF(cpy_r_r137);
CPyL109: ;
    cpy_r_r138 = CPyDict_GetItem(cpy_r_r136, cpy_r_r137);
    CPy_DECREF(cpy_r_r136);
    CPy_DECREF(cpy_r_r137);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 83, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo = cpy_r_r138;
    cpy_r_r139 = 1;
    if (unlikely(!cpy_r_r139)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 83, CPyStatic__nonce___globals);
        goto CPyL483;
    } else
        goto CPyL112;
CPyL111: ;
    cpy_r_r140 = CPyStatics[409]; /* 0 */
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo = cpy_r_r140;
    cpy_r_r141 = 1;
    if (unlikely(!cpy_r_r141)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 85, CPyStatic__nonce___globals);
        goto CPyL483;
    }
CPyL112: ;
    cpy_r_r142 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query;
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lowest_known_nonce_gt_query", 87, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r142);
CPyL113: ;
    cpy_r_r143 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r144 = cpy_r_r142 != cpy_r_r143;
    CPy_DECREF(cpy_r_r142);
    if (cpy_r_r144) {
        goto CPyL498;
    } else
        goto CPyL123;
CPyL114: ;
    cpy_r_r145 = CPyStatic__nonce___nonces;
    if (unlikely(cpy_r_r145 == NULL)) {
        goto CPyL499;
    } else
        goto CPyL117;
CPyL115: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"nonces\" was not set");
    cpy_r_r146 = 0;
    if (unlikely(!cpy_r_r146)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 88, CPyStatic__nonce___globals);
        goto CPyL203;
    } else
        goto CPyL500;
CPyL116: ;
    CPy_Unreachable();
CPyL117: ;
    cpy_r_r147 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 88, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    CPy_INCREF(cpy_r_r147);
CPyL118: ;
    cpy_r_r148 = CPyDict_GetItem(cpy_r_r145, cpy_r_r147);
    CPy_DECREF(cpy_r_r147);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 88, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    if (likely(PyDict_Check(cpy_r_r148)))
        cpy_r_r149 = cpy_r_r148;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 88, CPyStatic__nonce___globals, "dict", cpy_r_r148);
        goto CPyL501;
    }
    cpy_r_r150 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lowest_known_nonce_gt_query;
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lowest_known_nonce_gt_query", 88, CPyStatic__nonce___globals);
        goto CPyL502;
    }
    CPy_INCREF(cpy_r_r150);
CPyL121: ;
    cpy_r_r151 = CPyDict_GetItem(cpy_r_r149, cpy_r_r150);
    CPy_DECREF(cpy_r_r149);
    CPy_DECREF(cpy_r_r150);
    if (unlikely(cpy_r_r151 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 88, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi = cpy_r_r151;
    cpy_r_r152 = 1;
    if (unlikely(!cpy_r_r152)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 88, CPyStatic__nonce___globals);
        goto CPyL501;
    } else
        goto CPyL154;
CPyL123: ;
    cpy_r_r153 = CPyDef__nonce___get_block_number();
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 90, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r154 = CPy_GetCoro(cpy_r_r153);
    CPy_DECREF(cpy_r_r153);
    if (unlikely(cpy_r_r154 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 90, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__12 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__12);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__12 = cpy_r_r154;
    cpy_r_r155 = 1;
    if (unlikely(!cpy_r_r155)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    cpy_r_r156 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__12;
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__12", -1, CPyStatic__nonce___globals);
        goto CPyL483;
    }
    CPy_INCREF(cpy_r_r156);
CPyL127: ;
    cpy_r_r157 = CPyIter_Next(cpy_r_r156);
    CPy_DECREF(cpy_r_r156);
    if (cpy_r_r157 == NULL) {
        goto CPyL503;
    } else
        goto CPyL130;
CPyL128: ;
    cpy_r_r158 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r158 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 90, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    cpy_r_r159 = cpy_r_r158;
    goto CPyL153;
CPyL130: ;
    cpy_r_r160 = cpy_r_r157;
CPyL131: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ = 4;
    cpy_r_r161 = 1;
    if (unlikely(!cpy_r_r161)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 90, CPyStatic__nonce___globals);
        goto CPyL504;
    } else
        goto CPyL505;
CPyL132: ;
    return cpy_r_r160;
CPyL133: ;
    cpy_r_r162 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r163 = cpy_r_type != cpy_r_r162;
    if (!cpy_r_r163) goto CPyL136;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 90, CPyStatic__nonce___globals);
        goto CPyL137;
    } else
        goto CPyL506;
CPyL135: ;
    CPy_Unreachable();
CPyL136: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL148;
CPyL137: ;
    cpy_r_r164 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__13.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__13.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__13.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__13.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__13 = cpy_r_r164;
    cpy_r_r165 = 1;
    if (unlikely(!cpy_r_r165)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL507;
    }
    cpy_r_r166 = (PyObject **)&cpy_r_r3;
    cpy_r_r167 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__12;
    if (unlikely(cpy_r_r167 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__12", -1, CPyStatic__nonce___globals);
        goto CPyL507;
    }
    CPy_INCREF(cpy_r_r167);
CPyL139: ;
    cpy_r_r168 = CPy_YieldFromErrorHandle(cpy_r_r167, cpy_r_r166);
    CPy_DecRef(cpy_r_r167);
    if (unlikely(cpy_r_r168 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 90, CPyStatic__nonce___globals);
        goto CPyL507;
    }
    if (cpy_r_r168) goto CPyL143;
    CPy_INCREF(cpy_r_r3);
    cpy_r_r160 = cpy_r_r3;
    cpy_r_r169 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__13;
    if (unlikely(cpy_r_r169.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__13", -1, CPyStatic__nonce___globals);
        goto CPyL508;
    }
    CPy_INCREF(cpy_r_r169.f0);
    CPy_INCREF(cpy_r_r169.f1);
    CPy_INCREF(cpy_r_r169.f2);
CPyL142: ;
    CPy_RestoreExcInfo(cpy_r_r169);
    CPy_DecRef(cpy_r_r169.f0);
    CPy_DecRef(cpy_r_r169.f1);
    CPy_DecRef(cpy_r_r169.f2);
    goto CPyL131;
CPyL143: ;
    cpy_r_r159 = cpy_r_r3;
    cpy_r_r170 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__13;
    if (unlikely(cpy_r_r170.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__13", -1, CPyStatic__nonce___globals);
        goto CPyL509;
    }
    CPy_INCREF(cpy_r_r170.f0);
    CPy_INCREF(cpy_r_r170.f1);
    CPy_INCREF(cpy_r_r170.f2);
CPyL144: ;
    CPy_RestoreExcInfo(cpy_r_r170);
    CPy_DecRef(cpy_r_r170.f0);
    CPy_DecRef(cpy_r_r170.f1);
    CPy_DecRef(cpy_r_r170.f2);
    goto CPyL153;
CPyL145: ;
    cpy_r_r171 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__13;
    if (unlikely(cpy_r_r171.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__13", -1, CPyStatic__nonce___globals);
        goto CPyL203;
    }
    CPy_INCREF(cpy_r_r171.f0);
    CPy_INCREF(cpy_r_r171.f1);
    CPy_INCREF(cpy_r_r171.f2);
CPyL146: ;
    CPy_RestoreExcInfo(cpy_r_r171);
    CPy_DecRef(cpy_r_r171.f0);
    CPy_DecRef(cpy_r_r171.f1);
    CPy_DecRef(cpy_r_r171.f2);
    cpy_r_r172 = CPy_KeepPropagating();
    if (!cpy_r_r172) {
        goto CPyL203;
    } else
        goto CPyL510;
CPyL147: ;
    CPy_Unreachable();
CPyL148: ;
    cpy_r_r173 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__12;
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__12", -1, CPyStatic__nonce___globals);
        goto CPyL511;
    }
    CPy_INCREF(cpy_r_r173);
CPyL149: ;
    cpy_r_r174 = CPyIter_Send(cpy_r_r173, cpy_r_arg);
    CPy_DECREF(cpy_r_r173);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r174 == NULL) goto CPyL512;
    cpy_r_r160 = cpy_r_r174;
    goto CPyL131;
CPyL151: ;
    cpy_r_r175 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 90, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    cpy_r_r159 = cpy_r_r175;
CPyL153: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi = cpy_r_r159;
    cpy_r_r176 = 1;
    if (unlikely(!cpy_r_r176)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 90, CPyStatic__nonce___globals);
        goto CPyL501;
    }
CPyL154: ;
    cpy_r_r177 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi;
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "hi", 93, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    CPy_INCREF(cpy_r_r177);
CPyL155: ;
    cpy_r_r178 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 93, CPyStatic__nonce___globals);
        goto CPyL513;
    }
    CPy_INCREF(cpy_r_r178);
CPyL156: ;
    cpy_r_r179 = PyNumber_Subtract(cpy_r_r177, cpy_r_r178);
    CPy_DECREF(cpy_r_r177);
    CPy_DECREF(cpy_r_r178);
    if (unlikely(cpy_r_r179 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 93, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    if (likely(PyLong_Check(cpy_r_r179)))
        cpy_r_r180 = CPyTagged_FromObject(cpy_r_r179);
    else {
        CPy_TypeError("int", cpy_r_r179); cpy_r_r180 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r179);
    if (unlikely(cpy_r_r180 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 93, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    cpy_r_r181 = CPyTagged_Add(cpy_r_r180, 2);
    CPyTagged_DECREF(cpy_r_r180);
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_range_size != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_range_size);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_range_size = cpy_r_r181;
    cpy_r_r182 = 1;
    if (unlikely(!cpy_r_r182)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 93, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    cpy_r_r183 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_range_size;
    if (unlikely(cpy_r_r183 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "range_size", 94, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    CPyTagged_INCREF(cpy_r_r183);
CPyL160: ;
    cpy_r_r184 = cpy_r_r183 & 1;
    cpy_r_r185 = cpy_r_r184 != 0;
    if (cpy_r_r185) goto CPyL162;
    cpy_r_r186 = 8 & 1;
    cpy_r_r187 = cpy_r_r186 != 0;
    if (!cpy_r_r187) goto CPyL163;
CPyL162: ;
    cpy_r_r188 = CPyTagged_IsLt_(8, cpy_r_r183);
    cpy_r_r189 = cpy_r_r188;
    goto CPyL164;
CPyL163: ;
    cpy_r_r190 = (Py_ssize_t)cpy_r_r183 > (Py_ssize_t)8;
    cpy_r_r189 = cpy_r_r190;
CPyL164: ;
    CPyTagged_DECREF(cpy_r_r183);
    if (!cpy_r_r189) goto CPyL514;
    cpy_r_r191 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 95, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    CPy_INCREF(cpy_r_r191);
CPyL166: ;
    cpy_r_r192 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_nonce;
    if (unlikely(cpy_r_r192 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "nonce", 95, CPyStatic__nonce___globals);
        goto CPyL515;
    }
    CPyTagged_INCREF(cpy_r_r192);
CPyL167: ;
    cpy_r_r193 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 95, CPyStatic__nonce___globals);
        goto CPyL516;
    }
    CPy_INCREF(cpy_r_r193);
CPyL168: ;
    cpy_r_r194 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi;
    if (unlikely(cpy_r_r194 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "hi", 95, CPyStatic__nonce___globals);
        goto CPyL517;
    }
    CPy_INCREF(cpy_r_r194);
CPyL169: ;
    cpy_r_r195 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_range_size;
    if (unlikely(cpy_r_r195 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "range_size", 95, CPyStatic__nonce___globals);
        goto CPyL518;
    }
    CPyTagged_INCREF(cpy_r_r195);
CPyL170: ;
    cpy_r_r196 = CPyDef__nonce____get_area(cpy_r_r191, cpy_r_r192, cpy_r_r193, cpy_r_r194, cpy_r_r195);
    CPy_DECREF(cpy_r_r191);
    CPyTagged_DECREF(cpy_r_r192);
    CPy_DECREF(cpy_r_r193);
    CPy_DECREF(cpy_r_r194);
    CPyTagged_DECREF(cpy_r_r195);
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    cpy_r_r197 = CPy_GetCoro(cpy_r_r196);
    CPy_DECREF(cpy_r_r196);
    if (unlikely(cpy_r_r197 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__14 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__14);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__14 = cpy_r_r197;
    cpy_r_r198 = 1;
    if (unlikely(!cpy_r_r198)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    cpy_r_r199 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__14;
    if (unlikely(cpy_r_r199 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__14", -1, CPyStatic__nonce___globals);
        goto CPyL501;
    }
    CPy_INCREF(cpy_r_r199);
CPyL174: ;
    cpy_r_r200 = CPyIter_Next(cpy_r_r199);
    CPy_DECREF(cpy_r_r199);
    if (cpy_r_r200 == NULL) {
        goto CPyL519;
    } else
        goto CPyL177;
CPyL175: ;
    cpy_r_r201 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r201 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
        goto CPyL203;
    }
    cpy_r_r202 = cpy_r_r201;
    goto CPyL200;
CPyL177: ;
    cpy_r_r203 = cpy_r_r200;
CPyL178: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ = 6;
    cpy_r_r204 = 1;
    if (unlikely(!cpy_r_r204)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
        goto CPyL520;
    } else
        goto CPyL521;
CPyL179: ;
    return cpy_r_r203;
CPyL180: ;
    cpy_r_r205 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r206 = cpy_r_type != cpy_r_r205;
    if (!cpy_r_r206) goto CPyL183;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
        goto CPyL184;
    } else
        goto CPyL522;
CPyL182: ;
    CPy_Unreachable();
CPyL183: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL195;
CPyL184: ;
    cpy_r_r207 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__15.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__15.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__15.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__15.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__15 = cpy_r_r207;
    cpy_r_r208 = 1;
    if (unlikely(!cpy_r_r208)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL523;
    }
    cpy_r_r209 = (PyObject **)&cpy_r_r5;
    cpy_r_r210 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__14;
    if (unlikely(cpy_r_r210 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__14", -1, CPyStatic__nonce___globals);
        goto CPyL523;
    }
    CPy_INCREF(cpy_r_r210);
CPyL186: ;
    cpy_r_r211 = CPy_YieldFromErrorHandle(cpy_r_r210, cpy_r_r209);
    CPy_DecRef(cpy_r_r210);
    if (unlikely(cpy_r_r211 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
        goto CPyL523;
    }
    if (cpy_r_r211) goto CPyL190;
    CPy_INCREF(cpy_r_r5);
    cpy_r_r203 = cpy_r_r5;
    cpy_r_r212 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__15;
    if (unlikely(cpy_r_r212.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__15", -1, CPyStatic__nonce___globals);
        goto CPyL524;
    }
    CPy_INCREF(cpy_r_r212.f0);
    CPy_INCREF(cpy_r_r212.f1);
    CPy_INCREF(cpy_r_r212.f2);
CPyL189: ;
    CPy_RestoreExcInfo(cpy_r_r212);
    CPy_DecRef(cpy_r_r212.f0);
    CPy_DecRef(cpy_r_r212.f1);
    CPy_DecRef(cpy_r_r212.f2);
    goto CPyL178;
CPyL190: ;
    cpy_r_r202 = cpy_r_r5;
    cpy_r_r213 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__15;
    if (unlikely(cpy_r_r213.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__15", -1, CPyStatic__nonce___globals);
        goto CPyL525;
    }
    CPy_INCREF(cpy_r_r213.f0);
    CPy_INCREF(cpy_r_r213.f1);
    CPy_INCREF(cpy_r_r213.f2);
CPyL191: ;
    CPy_RestoreExcInfo(cpy_r_r213);
    CPy_DecRef(cpy_r_r213.f0);
    CPy_DecRef(cpy_r_r213.f1);
    CPy_DecRef(cpy_r_r213.f2);
    goto CPyL200;
CPyL192: ;
    cpy_r_r214 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__15;
    if (unlikely(cpy_r_r214.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__15", -1, CPyStatic__nonce___globals);
        goto CPyL203;
    }
    CPy_INCREF(cpy_r_r214.f0);
    CPy_INCREF(cpy_r_r214.f1);
    CPy_INCREF(cpy_r_r214.f2);
CPyL193: ;
    CPy_RestoreExcInfo(cpy_r_r214);
    CPy_DecRef(cpy_r_r214.f0);
    CPy_DecRef(cpy_r_r214.f1);
    CPy_DecRef(cpy_r_r214.f2);
    cpy_r_r215 = CPy_KeepPropagating();
    if (!cpy_r_r215) {
        goto CPyL203;
    } else
        goto CPyL526;
CPyL194: ;
    CPy_Unreachable();
CPyL195: ;
    cpy_r_r216 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__14;
    if (unlikely(cpy_r_r216 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__14", -1, CPyStatic__nonce___globals);
        goto CPyL527;
    }
    CPy_INCREF(cpy_r_r216);
CPyL196: ;
    cpy_r_r217 = CPyIter_Send(cpy_r_r216, cpy_r_arg);
    CPy_DECREF(cpy_r_r216);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r217 == NULL) goto CPyL528;
    cpy_r_r203 = cpy_r_r217;
    goto CPyL178;
CPyL198: ;
    cpy_r_r218 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r218 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
        goto CPyL203;
    }
    cpy_r_r202 = cpy_r_r218;
CPyL200: ;
    PyObject *__tmp4;
    if (unlikely(!(PyTuple_Check(cpy_r_r202) && PyTuple_GET_SIZE(cpy_r_r202) == 2))) {
        __tmp4 = NULL;
        goto __LL5;
    }
    __tmp4 = PyTuple_GET_ITEM(cpy_r_r202, 0);
    if (__tmp4 == NULL) goto __LL5;
    __tmp4 = PyTuple_GET_ITEM(cpy_r_r202, 1);
    if (__tmp4 == NULL) goto __LL5;
    __tmp4 = cpy_r_r202;
__LL5: ;
    if (unlikely(__tmp4 == NULL)) {
        CPy_TypeError("tuple[object, object]", cpy_r_r202); cpy_r_r219 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp6 = PyTuple_GET_ITEM(cpy_r_r202, 0);
        CPy_INCREF(__tmp6);
        PyObject *__tmp7;
        __tmp7 = __tmp6;
        cpy_r_r219.f0 = __tmp7;
        PyObject *__tmp8 = PyTuple_GET_ITEM(cpy_r_r202, 1);
        CPy_INCREF(__tmp8);
        PyObject *__tmp9;
        __tmp9 = __tmp8;
        cpy_r_r219.f1 = __tmp9;
    }
    CPy_DECREF(cpy_r_r202);
    if (unlikely(cpy_r_r219.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
        goto CPyL203;
    }
    cpy_r_r220 = cpy_r_r219.f0;
    cpy_r_r221 = cpy_r_r219.f1;
    cpy_r_r222 = cpy_r_r220;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo = cpy_r_r222;
    cpy_r_r223 = 1;
    if (unlikely(!cpy_r_r223)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
        goto CPyL203;
    }
    cpy_r_r224 = cpy_r_r221;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi = cpy_r_r224;
    cpy_r_r225 = 1;
    if (unlikely(!cpy_r_r225)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 95, CPyStatic__nonce___globals);
    } else
        goto CPyL529;
CPyL203: ;
    cpy_r_r226 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__16.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__16.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__16.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__16.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__16 = cpy_r_r226;
    cpy_r_r227 = 1;
    if (unlikely(!cpy_r_r227)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL530;
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__5 = 0;
    cpy_r_r228 = 1;
    if (unlikely(!cpy_r_r228)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL530;
    }
    cpy_r_r229 = CPy_GetExcInfo();
    cpy_r_r230 = cpy_r_r229.f0;
    CPy_INCREF(cpy_r_r230);
    cpy_r_r231 = cpy_r_r229.f1;
    CPy_INCREF(cpy_r_r231);
    cpy_r_r232 = cpy_r_r229.f2;
    CPy_INCREF(cpy_r_r232);
    CPy_DecRef(cpy_r_r229.f0);
    CPy_DecRef(cpy_r_r229.f1);
    CPy_DecRef(cpy_r_r229.f2);
    cpy_r_r233 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__3;
    if (unlikely(cpy_r_r233 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__3", -1, CPyStatic__nonce___globals);
        goto CPyL531;
    }
    CPy_INCREF(cpy_r_r233);
CPyL206: ;
    cpy_r_r234 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__4;
    if (unlikely(cpy_r_r234 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__4", -1, CPyStatic__nonce___globals);
        goto CPyL532;
    }
    CPy_INCREF(cpy_r_r234);
CPyL207: ;
    PyObject *cpy_r_r235[4] = {cpy_r_r234, cpy_r_r230, cpy_r_r231, cpy_r_r232};
    cpy_r_r236 = (PyObject **)&cpy_r_r235;
    cpy_r_r237 = PyObject_Vectorcall(cpy_r_r233, cpy_r_r236, 4, 0);
    CPy_DecRef(cpy_r_r233);
    if (unlikely(cpy_r_r237 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL533;
    }
    CPy_DecRef(cpy_r_r234);
    CPy_DecRef(cpy_r_r230);
    CPy_DecRef(cpy_r_r231);
    CPy_DecRef(cpy_r_r232);
    cpy_r_r238 = CPy_GetCoro(cpy_r_r237);
    CPy_DecRef(cpy_r_r237);
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL530;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__17 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__17);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__17 = cpy_r_r238;
    cpy_r_r239 = 1;
    if (unlikely(!cpy_r_r239)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL530;
    }
    cpy_r_r240 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__17;
    if (unlikely(cpy_r_r240 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__17", -1, CPyStatic__nonce___globals);
        goto CPyL530;
    }
    CPy_INCREF(cpy_r_r240);
CPyL211: ;
    cpy_r_r241 = CPyIter_Next(cpy_r_r240);
    CPy_DecRef(cpy_r_r240);
    if (cpy_r_r241 == NULL) {
        goto CPyL534;
    } else
        goto CPyL214;
CPyL212: ;
    cpy_r_r242 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r242 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL243;
    }
    cpy_r_r243 = cpy_r_r242;
    goto CPyL237;
CPyL214: ;
    cpy_r_r244 = cpy_r_r241;
CPyL215: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ = 8;
    cpy_r_r245 = 1;
    if (unlikely(!cpy_r_r245)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL535;
    } else
        goto CPyL536;
CPyL216: ;
    return cpy_r_r244;
CPyL217: ;
    cpy_r_r246 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r247 = cpy_r_type != cpy_r_r246;
    if (!cpy_r_r247) goto CPyL220;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL221;
    } else
        goto CPyL537;
CPyL219: ;
    CPy_Unreachable();
CPyL220: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL232;
CPyL221: ;
    cpy_r_r248 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__18.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__18.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__18.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__18.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__18 = cpy_r_r248;
    cpy_r_r249 = 1;
    if (unlikely(!cpy_r_r249)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL538;
    }
    cpy_r_r250 = (PyObject **)&cpy_r_r7;
    cpy_r_r251 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__17;
    if (unlikely(cpy_r_r251 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__17", -1, CPyStatic__nonce___globals);
        goto CPyL538;
    }
    CPy_INCREF(cpy_r_r251);
CPyL223: ;
    cpy_r_r252 = CPy_YieldFromErrorHandle(cpy_r_r251, cpy_r_r250);
    CPy_DecRef(cpy_r_r251);
    if (unlikely(cpy_r_r252 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL538;
    }
    if (cpy_r_r252) goto CPyL227;
    CPy_INCREF(cpy_r_r7);
    cpy_r_r244 = cpy_r_r7;
    cpy_r_r253 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__18;
    if (unlikely(cpy_r_r253.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__18", -1, CPyStatic__nonce___globals);
        goto CPyL539;
    }
    CPy_INCREF(cpy_r_r253.f0);
    CPy_INCREF(cpy_r_r253.f1);
    CPy_INCREF(cpy_r_r253.f2);
CPyL226: ;
    CPy_RestoreExcInfo(cpy_r_r253);
    CPy_DecRef(cpy_r_r253.f0);
    CPy_DecRef(cpy_r_r253.f1);
    CPy_DecRef(cpy_r_r253.f2);
    goto CPyL215;
CPyL227: ;
    cpy_r_r243 = cpy_r_r7;
    cpy_r_r254 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__18;
    if (unlikely(cpy_r_r254.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__18", -1, CPyStatic__nonce___globals);
        goto CPyL540;
    }
    CPy_INCREF(cpy_r_r254.f0);
    CPy_INCREF(cpy_r_r254.f1);
    CPy_INCREF(cpy_r_r254.f2);
CPyL228: ;
    CPy_RestoreExcInfo(cpy_r_r254);
    CPy_DecRef(cpy_r_r254.f0);
    CPy_DecRef(cpy_r_r254.f1);
    CPy_DecRef(cpy_r_r254.f2);
    goto CPyL237;
CPyL229: ;
    cpy_r_r255 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__18;
    if (unlikely(cpy_r_r255.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__18", -1, CPyStatic__nonce___globals);
        goto CPyL243;
    }
    CPy_INCREF(cpy_r_r255.f0);
    CPy_INCREF(cpy_r_r255.f1);
    CPy_INCREF(cpy_r_r255.f2);
CPyL230: ;
    CPy_RestoreExcInfo(cpy_r_r255);
    CPy_DecRef(cpy_r_r255.f0);
    CPy_DecRef(cpy_r_r255.f1);
    CPy_DecRef(cpy_r_r255.f2);
    cpy_r_r256 = CPy_KeepPropagating();
    if (!cpy_r_r256) {
        goto CPyL243;
    } else
        goto CPyL541;
CPyL231: ;
    CPy_Unreachable();
CPyL232: ;
    cpy_r_r257 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__17;
    if (unlikely(cpy_r_r257 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__17", -1, CPyStatic__nonce___globals);
        goto CPyL542;
    }
    CPy_INCREF(cpy_r_r257);
CPyL233: ;
    cpy_r_r258 = CPyIter_Send(cpy_r_r257, cpy_r_arg);
    CPy_DECREF(cpy_r_r257);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r258 == NULL) goto CPyL543;
    cpy_r_r244 = cpy_r_r258;
    goto CPyL215;
CPyL235: ;
    cpy_r_r259 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r259 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL243;
    }
    cpy_r_r243 = cpy_r_r259;
CPyL237: ;
    cpy_r_r260 = PyObject_IsTrue(cpy_r_r243);
    CPy_DECREF(cpy_r_r243);
    cpy_r_r261 = cpy_r_r260 >= 0;
    if (unlikely(!cpy_r_r261)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL243;
    }
    cpy_r_r262 = cpy_r_r260;
    if (cpy_r_r262) goto CPyL241;
    CPy_Reraise();
    if (!0) {
        goto CPyL243;
    } else
        goto CPyL544;
CPyL240: ;
    CPy_Unreachable();
CPyL241: ;
    cpy_r_r263 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__16;
    if (unlikely(cpy_r_r263.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__16", -1, CPyStatic__nonce___globals);
        goto CPyL247;
    }
    CPy_INCREF(cpy_r_r263.f0);
    CPy_INCREF(cpy_r_r263.f1);
    CPy_INCREF(cpy_r_r263.f2);
CPyL242: ;
    CPy_RestoreExcInfo(cpy_r_r263);
    CPy_DECREF(cpy_r_r263.f0);
    CPy_DECREF(cpy_r_r263.f1);
    CPy_DECREF(cpy_r_r263.f2);
    goto CPyL246;
CPyL243: ;
    cpy_r_r264 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__16;
    if (unlikely(cpy_r_r264.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__16", -1, CPyStatic__nonce___globals);
        goto CPyL247;
    }
    CPy_INCREF(cpy_r_r264.f0);
    CPy_INCREF(cpy_r_r264.f1);
    CPy_INCREF(cpy_r_r264.f2);
CPyL244: ;
    CPy_RestoreExcInfo(cpy_r_r264);
    CPy_DECREF(cpy_r_r264.f0);
    CPy_DECREF(cpy_r_r264.f1);
    CPy_DECREF(cpy_r_r264.f2);
    cpy_r_r265 = CPy_KeepPropagating();
    if (!cpy_r_r265) {
        goto CPyL247;
    } else
        goto CPyL545;
CPyL245: ;
    CPy_Unreachable();
CPyL246: ;
    tuple_T3OOO __tmp10 = { NULL, NULL, NULL };
    cpy_r_r266 = __tmp10;
    cpy_r_r11 = cpy_r_r266;
    goto CPyL248;
CPyL247: ;
    cpy_r_r267 = CPy_CatchError();
    cpy_r_r11 = cpy_r_r267;
CPyL248: ;
    cpy_r_r268 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__5;
    if (unlikely(cpy_r_r268 == 2)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__5", -1, CPyStatic__nonce___globals);
        goto CPyL546;
    }
CPyL249: ;
    if (!cpy_r_r268) goto CPyL547;
CPyL250: ;
    cpy_r_r269 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r270 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__3;
    if (unlikely(cpy_r_r270 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__3", -1, CPyStatic__nonce___globals);
        goto CPyL546;
    }
    CPy_INCREF(cpy_r_r270);
CPyL251: ;
    cpy_r_r271 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__4;
    if (unlikely(cpy_r_r271 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__4", -1, CPyStatic__nonce___globals);
        goto CPyL548;
    }
    CPy_INCREF(cpy_r_r271);
CPyL252: ;
    PyObject *cpy_r_r272[4] = {cpy_r_r271, cpy_r_r269, cpy_r_r269, cpy_r_r269};
    cpy_r_r273 = (PyObject **)&cpy_r_r272;
    cpy_r_r274 = PyObject_Vectorcall(cpy_r_r270, cpy_r_r273, 4, 0);
    CPy_DECREF(cpy_r_r270);
    if (unlikely(cpy_r_r274 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL549;
    }
    CPy_DECREF(cpy_r_r271);
    cpy_r_r275 = CPy_GetCoro(cpy_r_r274);
    CPy_DECREF(cpy_r_r274);
    if (unlikely(cpy_r_r275 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL546;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__19 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__19);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__19 = cpy_r_r275;
    cpy_r_r276 = 1;
    if (unlikely(!cpy_r_r276)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL546;
    }
    cpy_r_r277 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__19;
    if (unlikely(cpy_r_r277 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__19", -1, CPyStatic__nonce___globals);
        goto CPyL546;
    }
    CPy_INCREF(cpy_r_r277);
CPyL256: ;
    cpy_r_r278 = CPyIter_Next(cpy_r_r277);
    CPy_DECREF(cpy_r_r277);
    if (cpy_r_r278 == NULL) {
        goto CPyL550;
    } else
        goto CPyL259;
CPyL257: ;
    cpy_r_r279 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r279 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL551;
    }
    cpy_r_r280 = cpy_r_r279;
    CPy_DECREF(cpy_r_r280);
    goto CPyL282;
CPyL259: ;
    cpy_r_r281 = cpy_r_r278;
CPyL260: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ = 10;
    cpy_r_r282 = 1;
    if (unlikely(!cpy_r_r282)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL552;
    } else
        goto CPyL553;
CPyL261: ;
    return cpy_r_r281;
CPyL262: ;
    cpy_r_r283 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r284 = cpy_r_type != cpy_r_r283;
    if (!cpy_r_r284) goto CPyL265;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL266;
    } else
        goto CPyL554;
CPyL264: ;
    CPy_Unreachable();
CPyL265: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL277;
CPyL266: ;
    cpy_r_r285 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__20.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__20.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__20.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__20.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__20 = cpy_r_r285;
    cpy_r_r286 = 1;
    if (unlikely(!cpy_r_r286)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL555;
    }
    cpy_r_r287 = (PyObject **)&cpy_r_r9;
    cpy_r_r288 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__19;
    if (unlikely(cpy_r_r288 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__19", -1, CPyStatic__nonce___globals);
        goto CPyL555;
    }
    CPy_INCREF(cpy_r_r288);
CPyL268: ;
    cpy_r_r289 = CPy_YieldFromErrorHandle(cpy_r_r288, cpy_r_r287);
    CPy_DecRef(cpy_r_r288);
    if (unlikely(cpy_r_r289 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL555;
    }
    if (cpy_r_r289) goto CPyL272;
    CPy_INCREF(cpy_r_r9);
    cpy_r_r281 = cpy_r_r9;
    cpy_r_r290 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__20;
    if (unlikely(cpy_r_r290.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__20", -1, CPyStatic__nonce___globals);
        goto CPyL556;
    }
    CPy_INCREF(cpy_r_r290.f0);
    CPy_INCREF(cpy_r_r290.f1);
    CPy_INCREF(cpy_r_r290.f2);
CPyL271: ;
    CPy_RestoreExcInfo(cpy_r_r290);
    CPy_DecRef(cpy_r_r290.f0);
    CPy_DecRef(cpy_r_r290.f1);
    CPy_DecRef(cpy_r_r290.f2);
    goto CPyL260;
CPyL272: ;
    cpy_r_r280 = cpy_r_r9;
    CPy_DecRef(cpy_r_r280);
    cpy_r_r291 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__20;
    if (unlikely(cpy_r_r291.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__20", -1, CPyStatic__nonce___globals);
        goto CPyL557;
    }
    CPy_INCREF(cpy_r_r291.f0);
    CPy_INCREF(cpy_r_r291.f1);
    CPy_INCREF(cpy_r_r291.f2);
CPyL273: ;
    CPy_RestoreExcInfo(cpy_r_r291);
    CPy_DecRef(cpy_r_r291.f0);
    CPy_DecRef(cpy_r_r291.f1);
    CPy_DecRef(cpy_r_r291.f2);
    goto CPyL282;
CPyL274: ;
    cpy_r_r292 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__20;
    if (unlikely(cpy_r_r292.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__20' of 'get_block_for_nonce_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r292.f0);
        CPy_INCREF(cpy_r_r292.f1);
        CPy_INCREF(cpy_r_r292.f2);
    }
    CPy_DecRef(cpy_r_r16);
    if (unlikely(cpy_r_r292.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL285;
    }
CPyL275: ;
    CPy_RestoreExcInfo(cpy_r_r292);
    CPy_DecRef(cpy_r_r292.f0);
    CPy_DecRef(cpy_r_r292.f1);
    CPy_DecRef(cpy_r_r292.f2);
    cpy_r_r293 = CPy_KeepPropagating();
    if (!cpy_r_r293) {
        goto CPyL285;
    } else
        goto CPyL558;
CPyL276: ;
    CPy_Unreachable();
CPyL277: ;
    cpy_r_r294 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__19;
    if (unlikely(cpy_r_r294 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__19", -1, CPyStatic__nonce___globals);
        goto CPyL559;
    }
    CPy_INCREF(cpy_r_r294);
CPyL278: ;
    cpy_r_r295 = CPyIter_Send(cpy_r_r294, cpy_r_arg);
    CPy_DECREF(cpy_r_r294);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r295 == NULL) goto CPyL560;
    cpy_r_r281 = cpy_r_r295;
    goto CPyL260;
CPyL280: ;
    cpy_r_r296 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 68, CPyStatic__nonce___globals);
        goto CPyL551;
    }
    cpy_r_r280 = cpy_r_r296;
    CPy_DECREF(cpy_r_r280);
CPyL282: ;
    if (cpy_r_r11.f0 == NULL) {
        goto CPyL289;
    } else
        goto CPyL561;
CPyL283: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL285;
    } else
        goto CPyL562;
CPyL284: ;
    CPy_Unreachable();
CPyL285: ;
    if (cpy_r_r11.f0 == NULL) goto CPyL287;
    CPy_RestoreExcInfo(cpy_r_r11);
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
CPyL287: ;
    cpy_r_r297 = CPy_KeepPropagating();
    if (!cpy_r_r297) goto CPyL464;
    CPy_Unreachable();
CPyL289: ;
    cpy_r_r298 = CPyStatic__nonce___DEBUG;
    if (unlikely(cpy_r_r298 == CPY_INT_TAG)) {
        goto CPyL563;
    } else
        goto CPyL292;
CPyL290: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"DEBUG\" was not set");
    cpy_r_r299 = 0;
    if (unlikely(!cpy_r_r299)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 97, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL292: ;
    cpy_r_r300 = CPyStatic__nonce___logger_is_enabled;
    if (unlikely(cpy_r_r300 == NULL)) {
        goto CPyL564;
    } else
        goto CPyL295;
CPyL293: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"logger_is_enabled\" was not set");
    cpy_r_r301 = 0;
    if (unlikely(!cpy_r_r301)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 97, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL295: ;
    CPyTagged_INCREF(cpy_r_r298);
    cpy_r_r302 = CPyTagged_StealAsObject(cpy_r_r298);
    PyObject *cpy_r_r303[1] = {cpy_r_r302};
    cpy_r_r304 = (PyObject **)&cpy_r_r303;
    cpy_r_r305 = PyObject_Vectorcall(cpy_r_r300, cpy_r_r304, 1, 0);
    if (unlikely(cpy_r_r305 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 97, CPyStatic__nonce___globals);
        goto CPyL565;
    }
    CPy_DECREF(cpy_r_r302);
    if (unlikely(!PyBool_Check(cpy_r_r305))) {
        CPy_TypeError("bool", cpy_r_r305); cpy_r_r306 = 2;
    } else
        cpy_r_r306 = cpy_r_r305 == Py_True;
    CPy_DECREF(cpy_r_r305);
    if (unlikely(cpy_r_r306 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 97, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_debug_logs_enabled = cpy_r_r306;
    cpy_r_r307 = 1;
    if (unlikely(!cpy_r_r307)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 97, CPyStatic__nonce___globals);
        goto CPyL566;
    }
CPyL298: ;
    if (!1) goto CPyL567;
    cpy_r_r308 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r308 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 99, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r308);
CPyL300: ;
    cpy_r_r309 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r309 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 99, CPyStatic__nonce___globals);
        goto CPyL568;
    }
    CPy_INCREF(cpy_r_r309);
CPyL301: ;
    cpy_r_r310 = CPyDef__nonce___get_nonce_at_block(cpy_r_r308, cpy_r_r309);
    CPy_DECREF(cpy_r_r308);
    CPy_DECREF(cpy_r_r309);
    if (unlikely(cpy_r_r310 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 99, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r311 = CPy_GetCoro(cpy_r_r310);
    CPy_DECREF(cpy_r_r310);
    if (unlikely(cpy_r_r311 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 99, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__21 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__21);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__21 = cpy_r_r311;
    cpy_r_r312 = 1;
    if (unlikely(!cpy_r_r312)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r313 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__21;
    if (unlikely(cpy_r_r313 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__21", -1, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r313);
CPyL305: ;
    cpy_r_r314 = CPyIter_Next(cpy_r_r313);
    CPy_DECREF(cpy_r_r313);
    if (cpy_r_r314 != NULL) goto CPyL308;
    cpy_r_r315 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r315 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 99, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r316 = cpy_r_r315;
    goto CPyL331;
CPyL308: ;
    cpy_r_r317 = cpy_r_r314;
CPyL309: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ = 12;
    cpy_r_r318 = 1;
    if (unlikely(!cpy_r_r318)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 99, CPyStatic__nonce___globals);
        goto CPyL569;
    } else
        goto CPyL570;
CPyL310: ;
    return cpy_r_r317;
CPyL311: ;
    cpy_r_r319 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r320 = cpy_r_type != cpy_r_r319;
    if (!cpy_r_r320) goto CPyL314;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 99, CPyStatic__nonce___globals);
        goto CPyL315;
    } else
        goto CPyL571;
CPyL313: ;
    CPy_Unreachable();
CPyL314: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL326;
CPyL315: ;
    cpy_r_r321 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__22.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__22.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__22.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__22.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__22 = cpy_r_r321;
    cpy_r_r322 = 1;
    if (unlikely(!cpy_r_r322)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL572;
    }
    cpy_r_r323 = (PyObject **)&cpy_r_r13;
    cpy_r_r324 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__21;
    if (unlikely(cpy_r_r324 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__21", -1, CPyStatic__nonce___globals);
        goto CPyL572;
    }
    CPy_INCREF(cpy_r_r324);
CPyL317: ;
    cpy_r_r325 = CPy_YieldFromErrorHandle(cpy_r_r324, cpy_r_r323);
    CPy_DecRef(cpy_r_r324);
    if (unlikely(cpy_r_r325 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 99, CPyStatic__nonce___globals);
        goto CPyL572;
    }
    if (cpy_r_r325) goto CPyL321;
    CPy_INCREF(cpy_r_r13);
    cpy_r_r317 = cpy_r_r13;
    cpy_r_r326 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__22;
    if (unlikely(cpy_r_r326.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__22", -1, CPyStatic__nonce___globals);
        goto CPyL573;
    }
    CPy_INCREF(cpy_r_r326.f0);
    CPy_INCREF(cpy_r_r326.f1);
    CPy_INCREF(cpy_r_r326.f2);
CPyL320: ;
    CPy_RestoreExcInfo(cpy_r_r326);
    CPy_DecRef(cpy_r_r326.f0);
    CPy_DecRef(cpy_r_r326.f1);
    CPy_DecRef(cpy_r_r326.f2);
    goto CPyL309;
CPyL321: ;
    CPy_INCREF(cpy_r_r13);
    cpy_r_r316 = cpy_r_r13;
    cpy_r_r327 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__22;
    if (unlikely(cpy_r_r327.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__22", -1, CPyStatic__nonce___globals);
        goto CPyL574;
    }
    CPy_INCREF(cpy_r_r327.f0);
    CPy_INCREF(cpy_r_r327.f1);
    CPy_INCREF(cpy_r_r327.f2);
CPyL322: ;
    CPy_RestoreExcInfo(cpy_r_r327);
    CPy_DecRef(cpy_r_r327.f0);
    CPy_DecRef(cpy_r_r327.f1);
    CPy_DecRef(cpy_r_r327.f2);
    goto CPyL331;
CPyL323: ;
    cpy_r_r328 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__22;
    if (unlikely(cpy_r_r328.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__22' of 'get_block_for_nonce_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r328.f0);
        CPy_INCREF(cpy_r_r328.f1);
        CPy_INCREF(cpy_r_r328.f2);
    }
    CPy_DecRef(cpy_r_r16);
    if (unlikely(cpy_r_r328.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL464;
    }
CPyL324: ;
    CPy_RestoreExcInfo(cpy_r_r328);
    CPy_DecRef(cpy_r_r328.f0);
    CPy_DecRef(cpy_r_r328.f1);
    CPy_DecRef(cpy_r_r328.f2);
    cpy_r_r329 = CPy_KeepPropagating();
    if (!cpy_r_r329) goto CPyL464;
    CPy_Unreachable();
CPyL326: ;
    cpy_r_r330 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__21;
    if (unlikely(cpy_r_r330 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__21", -1, CPyStatic__nonce___globals);
        goto CPyL575;
    }
    CPy_INCREF(cpy_r_r330);
CPyL327: ;
    cpy_r_r331 = CPyIter_Send(cpy_r_r330, cpy_r_arg);
    CPy_DECREF(cpy_r_r330);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r331 == NULL) goto CPyL329;
    cpy_r_r317 = cpy_r_r331;
    goto CPyL309;
CPyL329: ;
    cpy_r_r332 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r332 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 99, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r316 = cpy_r_r332;
CPyL331: ;
    if (likely(PyLong_Check(cpy_r_r316)))
        cpy_r_r333 = CPyTagged_FromObject(cpy_r_r316);
    else {
        CPy_TypeError("int", cpy_r_r316); cpy_r_r333 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r316);
    if (unlikely(cpy_r_r333 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 99, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->__nonce != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->__nonce);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->__nonce = cpy_r_r333;
    cpy_r_r334 = 1;
    if (unlikely(!cpy_r_r334)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 99, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r335 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->__nonce;
    if (unlikely(cpy_r_r335 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "_nonce", 101, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPyTagged_INCREF(cpy_r_r335);
CPyL334: ;
    cpy_r_r336 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_nonce;
    if (unlikely(cpy_r_r336 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "nonce", 101, CPyStatic__nonce___globals);
        goto CPyL576;
    }
    CPyTagged_INCREF(cpy_r_r336);
CPyL335: ;
    cpy_r_r337 = cpy_r_r335 & 1;
    cpy_r_r338 = cpy_r_r337 != 0;
    if (cpy_r_r338) goto CPyL337;
    cpy_r_r339 = cpy_r_r336 & 1;
    cpy_r_r340 = cpy_r_r339 != 0;
    if (!cpy_r_r340) goto CPyL338;
CPyL337: ;
    cpy_r_r341 = CPyTagged_IsLt_(cpy_r_r335, cpy_r_r336);
    cpy_r_r342 = cpy_r_r341;
    goto CPyL339;
CPyL338: ;
    cpy_r_r343 = (Py_ssize_t)cpy_r_r335 < (Py_ssize_t)cpy_r_r336;
    cpy_r_r342 = cpy_r_r343;
CPyL339: ;
    CPyTagged_DECREF(cpy_r_r335);
    CPyTagged_DECREF(cpy_r_r336);
    if (!cpy_r_r342) goto CPyL369;
    cpy_r_r344 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r344 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 102, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r344);
CPyL341: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_old_lo != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_old_lo);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_old_lo = cpy_r_r344;
    cpy_r_r345 = 1;
    if (unlikely(!cpy_r_r345)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 102, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r346 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r346 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 103, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r346);
CPyL343: ;
    cpy_r_r347 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi;
    if (unlikely(cpy_r_r347 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "hi", 103, CPyStatic__nonce___globals);
        goto CPyL577;
    }
    CPy_INCREF(cpy_r_r347);
CPyL344: ;
    cpy_r_r348 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r348 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 103, CPyStatic__nonce___globals);
        goto CPyL578;
    }
    CPy_INCREF(cpy_r_r348);
CPyL345: ;
    cpy_r_r349 = PyNumber_Subtract(cpy_r_r347, cpy_r_r348);
    CPy_DECREF(cpy_r_r347);
    CPy_DECREF(cpy_r_r348);
    if (unlikely(cpy_r_r349 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 103, CPyStatic__nonce___globals);
        goto CPyL577;
    }
    if (likely(PyLong_Check(cpy_r_r349)))
        cpy_r_r350 = CPyTagged_FromObject(cpy_r_r349);
    else {
        CPy_TypeError("int", cpy_r_r349); cpy_r_r350 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r349);
    if (unlikely(cpy_r_r350 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 103, CPyStatic__nonce___globals);
        goto CPyL577;
    }
    cpy_r_r351 = CPyTagged_TrueDivide(cpy_r_r350, 4);
    CPyTagged_DECREF(cpy_r_r350);
    cpy_r_r352 = cpy_r_r351 == -113.0;
    if (unlikely(cpy_r_r352)) goto CPyL349;
CPyL348: ;
    cpy_r_r353 = CPyTagged_FromFloat(cpy_r_r351);
    if (unlikely(cpy_r_r353 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 103, CPyStatic__nonce___globals);
        goto CPyL577;
    } else
        goto CPyL350;
CPyL349: ;
    cpy_r_r354 = PyErr_Occurred();
    if (unlikely(cpy_r_r354 != NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 103, CPyStatic__nonce___globals);
        goto CPyL577;
    } else
        goto CPyL348;
CPyL350: ;
    cpy_r_r355 = cpy_r_r353 != 0;
    if (!cpy_r_r355) goto CPyL579;
    cpy_r_r356 = cpy_r_r353;
    goto CPyL353;
CPyL352: ;
    cpy_r_r356 = 2;
CPyL353: ;
    cpy_r_r357 = CPyTagged_StealAsObject(cpy_r_r356);
    cpy_r_r358 = PyNumber_InPlaceAdd(cpy_r_r346, cpy_r_r357);
    CPy_DECREF(cpy_r_r346);
    CPy_DECREF(cpy_r_r357);
    if (unlikely(cpy_r_r358 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 103, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo = cpy_r_r358;
    cpy_r_r359 = 1;
    if (unlikely(!cpy_r_r359)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 103, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r360 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_debug_logs_enabled;
    if (unlikely(cpy_r_r360 == 2)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "debug_logs_enabled", 104, CPyStatic__nonce___globals);
        goto CPyL566;
    }
CPyL356: ;
    if (!cpy_r_r360) goto CPyL298;
CPyL357: ;
    cpy_r_r361 = CPyStatic__nonce___DEBUG;
    if (unlikely(cpy_r_r361 == CPY_INT_TAG)) {
        goto CPyL580;
    } else
        goto CPyL360;
CPyL358: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"DEBUG\" was not set");
    cpy_r_r362 = 0;
    if (unlikely(!cpy_r_r362)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 106, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL360: ;
    cpy_r_r363 = CPyStatics[14]; /* 'Nonce for %s at %s is %s, checking higher block %s' */
    cpy_r_r364 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r364 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 108, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r364);
CPyL361: ;
    cpy_r_r365 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_old_lo;
    if (unlikely(cpy_r_r365 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "old_lo", 108, CPyStatic__nonce___globals);
        goto CPyL581;
    }
    CPy_INCREF(cpy_r_r365);
CPyL362: ;
    cpy_r_r366 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->__nonce;
    if (unlikely(cpy_r_r366 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "_nonce", 108, CPyStatic__nonce___globals);
        goto CPyL582;
    }
    CPyTagged_INCREF(cpy_r_r366);
CPyL363: ;
    cpy_r_r367 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r367 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 108, CPyStatic__nonce___globals);
        goto CPyL583;
    }
    CPy_INCREF(cpy_r_r367);
CPyL364: ;
    cpy_r_r368.f0 = cpy_r_r364;
    cpy_r_r368.f1 = cpy_r_r365;
    cpy_r_r368.f2 = cpy_r_r366;
    cpy_r_r368.f3 = cpy_r_r367;
    cpy_r_r369 = CPyStatic__nonce_____log;
    if (unlikely(cpy_r_r369 == NULL)) {
        goto CPyL584;
    } else
        goto CPyL367;
CPyL365: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"__log\" was not set");
    cpy_r_r370 = 0;
    if (unlikely(!cpy_r_r370)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 105, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL367: ;
    CPyTagged_INCREF(cpy_r_r361);
    cpy_r_r371 = CPyTagged_StealAsObject(cpy_r_r361);
    cpy_r_r372 = PyTuple_New(4);
    if (unlikely(cpy_r_r372 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp11 = cpy_r_r368.f0;
    PyTuple_SET_ITEM(cpy_r_r372, 0, __tmp11);
    PyObject *__tmp12 = cpy_r_r368.f1;
    PyTuple_SET_ITEM(cpy_r_r372, 1, __tmp12);
    PyObject *__tmp13 = CPyTagged_StealAsObject(cpy_r_r368.f2);
    PyTuple_SET_ITEM(cpy_r_r372, 2, __tmp13);
    PyObject *__tmp14 = cpy_r_r368.f3;
    PyTuple_SET_ITEM(cpy_r_r372, 3, __tmp14);
    PyObject *cpy_r_r373[3] = {cpy_r_r371, cpy_r_r363, cpy_r_r372};
    cpy_r_r374 = (PyObject **)&cpy_r_r373;
    cpy_r_r375 = PyObject_Vectorcall(cpy_r_r369, cpy_r_r374, 3, 0);
    if (unlikely(cpy_r_r375 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 105, CPyStatic__nonce___globals);
        goto CPyL585;
    } else
        goto CPyL586;
CPyL368: ;
    CPy_DECREF(cpy_r_r371);
    CPy_DECREF(cpy_r_r372);
    goto CPyL298;
CPyL369: ;
    cpy_r_r376 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r376 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 112, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r376);
CPyL370: ;
    cpy_r_r377 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r377 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 112, CPyStatic__nonce___globals);
        goto CPyL587;
    }
    CPy_INCREF(cpy_r_r377);
CPyL371: ;
    cpy_r_r378 = CPyStatics[408]; /* 1 */
    cpy_r_r379 = PyNumber_Subtract(cpy_r_r377, cpy_r_r378);
    CPy_DECREF(cpy_r_r377);
    if (unlikely(cpy_r_r379 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL587;
    }
    if (likely(PyLong_Check(cpy_r_r379)))
        cpy_r_r380 = CPyTagged_FromObject(cpy_r_r379);
    else {
        CPy_TypeError("int", cpy_r_r379); cpy_r_r380 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r379);
    if (unlikely(cpy_r_r380 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL587;
    }
    cpy_r_r381 = CPyTagged_StealAsObject(cpy_r_r380);
    cpy_r_r382 = CPyDef__nonce___get_nonce_at_block(cpy_r_r376, cpy_r_r381);
    CPy_DECREF(cpy_r_r376);
    CPy_DECREF(cpy_r_r381);
    if (unlikely(cpy_r_r382 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r383 = CPy_GetCoro(cpy_r_r382);
    CPy_DECREF(cpy_r_r382);
    if (unlikely(cpy_r_r383 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__23 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__23);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__23 = cpy_r_r383;
    cpy_r_r384 = 1;
    if (unlikely(!cpy_r_r384)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r385 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__23;
    if (unlikely(cpy_r_r385 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__23", -1, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r385);
CPyL377: ;
    cpy_r_r386 = CPyIter_Next(cpy_r_r385);
    CPy_DECREF(cpy_r_r385);
    if (cpy_r_r386 != NULL) goto CPyL380;
    cpy_r_r387 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r387 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r388 = cpy_r_r387;
    goto CPyL403;
CPyL380: ;
    cpy_r_r389 = cpy_r_r386;
CPyL381: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ = 14;
    cpy_r_r390 = 1;
    if (unlikely(!cpy_r_r390)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL588;
    } else
        goto CPyL589;
CPyL382: ;
    return cpy_r_r389;
CPyL383: ;
    cpy_r_r391 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r392 = cpy_r_type != cpy_r_r391;
    if (!cpy_r_r392) goto CPyL386;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL387;
    } else
        goto CPyL590;
CPyL385: ;
    CPy_Unreachable();
CPyL386: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL398;
CPyL387: ;
    cpy_r_r393 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__24.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__24.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__24.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__24.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__24 = cpy_r_r393;
    cpy_r_r394 = 1;
    if (unlikely(!cpy_r_r394)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL591;
    }
    cpy_r_r395 = (PyObject **)&cpy_r_r15;
    cpy_r_r396 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__23;
    if (unlikely(cpy_r_r396 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__23", -1, CPyStatic__nonce___globals);
        goto CPyL591;
    }
    CPy_INCREF(cpy_r_r396);
CPyL389: ;
    cpy_r_r397 = CPy_YieldFromErrorHandle(cpy_r_r396, cpy_r_r395);
    CPy_DecRef(cpy_r_r396);
    if (unlikely(cpy_r_r397 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL591;
    }
    if (cpy_r_r397) goto CPyL393;
    CPy_INCREF(cpy_r_r15);
    cpy_r_r389 = cpy_r_r15;
    cpy_r_r398 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__24;
    if (unlikely(cpy_r_r398.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__24", -1, CPyStatic__nonce___globals);
        goto CPyL592;
    }
    CPy_INCREF(cpy_r_r398.f0);
    CPy_INCREF(cpy_r_r398.f1);
    CPy_INCREF(cpy_r_r398.f2);
CPyL392: ;
    CPy_RestoreExcInfo(cpy_r_r398);
    CPy_DecRef(cpy_r_r398.f0);
    CPy_DecRef(cpy_r_r398.f1);
    CPy_DecRef(cpy_r_r398.f2);
    goto CPyL381;
CPyL393: ;
    CPy_INCREF(cpy_r_r15);
    cpy_r_r388 = cpy_r_r15;
    cpy_r_r399 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__24;
    if (unlikely(cpy_r_r399.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__24", -1, CPyStatic__nonce___globals);
        goto CPyL593;
    }
    CPy_INCREF(cpy_r_r399.f0);
    CPy_INCREF(cpy_r_r399.f1);
    CPy_INCREF(cpy_r_r399.f2);
CPyL394: ;
    CPy_RestoreExcInfo(cpy_r_r399);
    CPy_DecRef(cpy_r_r399.f0);
    CPy_DecRef(cpy_r_r399.f1);
    CPy_DecRef(cpy_r_r399.f2);
    goto CPyL403;
CPyL395: ;
    cpy_r_r400 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__24;
    if (unlikely(cpy_r_r400.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__24' of 'get_block_for_nonce_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r400.f0);
        CPy_INCREF(cpy_r_r400.f1);
        CPy_INCREF(cpy_r_r400.f2);
    }
    CPy_DecRef(cpy_r_r16);
    if (unlikely(cpy_r_r400.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", -1, CPyStatic__nonce___globals);
        goto CPyL464;
    }
CPyL396: ;
    CPy_RestoreExcInfo(cpy_r_r400);
    CPy_DecRef(cpy_r_r400.f0);
    CPy_DecRef(cpy_r_r400.f1);
    CPy_DecRef(cpy_r_r400.f2);
    cpy_r_r401 = CPy_KeepPropagating();
    if (!cpy_r_r401) goto CPyL464;
    CPy_Unreachable();
CPyL398: ;
    cpy_r_r402 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_temp__23;
    if (unlikely(cpy_r_r402 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "__mypyc_temp__23", -1, CPyStatic__nonce___globals);
        goto CPyL594;
    }
    CPy_INCREF(cpy_r_r402);
CPyL399: ;
    cpy_r_r403 = CPyIter_Send(cpy_r_r402, cpy_r_arg);
    CPy_DECREF(cpy_r_r402);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r403 == NULL) goto CPyL401;
    cpy_r_r389 = cpy_r_r403;
    goto CPyL381;
CPyL401: ;
    cpy_r_r404 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r404 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r388 = cpy_r_r404;
CPyL403: ;
    if (likely(PyLong_Check(cpy_r_r388)))
        cpy_r_r405 = CPyTagged_FromObject(cpy_r_r388);
    else {
        CPy_TypeError("int", cpy_r_r388); cpy_r_r405 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r388);
    if (unlikely(cpy_r_r405 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_prev_block_nonce != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_prev_block_nonce);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_prev_block_nonce = cpy_r_r405;
    cpy_r_r406 = 1;
    if (unlikely(!cpy_r_r406)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 112, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r407 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_prev_block_nonce;
    if (unlikely(cpy_r_r407 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "prev_block_nonce", 113, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPyTagged_INCREF(cpy_r_r407);
CPyL406: ;
    cpy_r_r408 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_nonce;
    if (unlikely(cpy_r_r408 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "nonce", 113, CPyStatic__nonce___globals);
        goto CPyL595;
    }
    CPyTagged_INCREF(cpy_r_r408);
CPyL407: ;
    cpy_r_r409 = cpy_r_r407 & 1;
    cpy_r_r410 = cpy_r_r409 != 0;
    if (cpy_r_r410) goto CPyL409;
    cpy_r_r411 = cpy_r_r408 & 1;
    cpy_r_r412 = cpy_r_r411 != 0;
    if (!cpy_r_r412) goto CPyL410;
CPyL409: ;
    cpy_r_r413 = CPyTagged_IsLt_(cpy_r_r407, cpy_r_r408);
    cpy_r_r414 = cpy_r_r413 ^ 1;
    cpy_r_r415 = cpy_r_r414;
    goto CPyL411;
CPyL410: ;
    cpy_r_r416 = (Py_ssize_t)cpy_r_r407 >= (Py_ssize_t)cpy_r_r408;
    cpy_r_r415 = cpy_r_r416;
CPyL411: ;
    CPyTagged_DECREF(cpy_r_r407);
    CPyTagged_DECREF(cpy_r_r408);
    if (!cpy_r_r415) goto CPyL596;
    cpy_r_r417 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r417 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 114, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r417);
CPyL413: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi = cpy_r_r417;
    cpy_r_r418 = 1;
    if (unlikely(!cpy_r_r418)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 114, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r419 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r419 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 115, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r419);
CPyL415: ;
    cpy_r_r420 = CPyStatics[411]; /* 2 */
    cpy_r_r421 = PyNumber_TrueDivide(cpy_r_r419, cpy_r_r420);
    CPy_DECREF(cpy_r_r419);
    if (unlikely(cpy_r_r421 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 115, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r422 = PyFloat_AsDouble(cpy_r_r421);
    if (cpy_r_r422 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r421); cpy_r_r422 = -113.0;
    }
    CPy_DECREF(cpy_r_r421);
    cpy_r_r423 = cpy_r_r422 == -113.0;
    if (unlikely(cpy_r_r423)) goto CPyL418;
CPyL417: ;
    cpy_r_r424 = CPyTagged_FromFloat(cpy_r_r422);
    if (unlikely(cpy_r_r424 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 115, CPyStatic__nonce___globals);
        goto CPyL566;
    } else
        goto CPyL419;
CPyL418: ;
    cpy_r_r425 = PyErr_Occurred();
    if (unlikely(cpy_r_r425 != NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 115, CPyStatic__nonce___globals);
        goto CPyL566;
    } else
        goto CPyL417;
CPyL419: ;
    cpy_r_r426 = CPyTagged_StealAsObject(cpy_r_r424);
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo = cpy_r_r426;
    cpy_r_r427 = 1;
    if (unlikely(!cpy_r_r427)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 115, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    cpy_r_r428 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_debug_logs_enabled;
    if (unlikely(cpy_r_r428 == 2)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "debug_logs_enabled", 116, CPyStatic__nonce___globals);
        goto CPyL566;
    }
CPyL421: ;
    if (!cpy_r_r428) goto CPyL298;
CPyL422: ;
    cpy_r_r429 = CPyStatic__nonce___DEBUG;
    if (unlikely(cpy_r_r429 == CPY_INT_TAG)) {
        goto CPyL597;
    } else
        goto CPyL425;
CPyL423: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"DEBUG\" was not set");
    cpy_r_r430 = 0;
    if (unlikely(!cpy_r_r430)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 118, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL425: ;
    cpy_r_r431 = CPyStatics[15]; /* 'Nonce for %s at %s is %s, checking lower block %s' */
    cpy_r_r432 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r432 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 120, CPyStatic__nonce___globals);
        goto CPyL566;
    }
    CPy_INCREF(cpy_r_r432);
CPyL426: ;
    cpy_r_r433 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_hi;
    if (unlikely(cpy_r_r433 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "hi", 120, CPyStatic__nonce___globals);
        goto CPyL598;
    }
    CPy_INCREF(cpy_r_r433);
CPyL427: ;
    cpy_r_r434 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->__nonce;
    if (unlikely(cpy_r_r434 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "_nonce", 120, CPyStatic__nonce___globals);
        goto CPyL599;
    }
    CPyTagged_INCREF(cpy_r_r434);
CPyL428: ;
    cpy_r_r435 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r435 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 120, CPyStatic__nonce___globals);
        goto CPyL600;
    }
    CPy_INCREF(cpy_r_r435);
CPyL429: ;
    cpy_r_r436.f0 = cpy_r_r432;
    cpy_r_r436.f1 = cpy_r_r433;
    cpy_r_r436.f2 = cpy_r_r434;
    cpy_r_r436.f3 = cpy_r_r435;
    cpy_r_r437 = CPyStatic__nonce_____log;
    if (unlikely(cpy_r_r437 == NULL)) {
        goto CPyL601;
    } else
        goto CPyL432;
CPyL430: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"__log\" was not set");
    cpy_r_r438 = 0;
    if (unlikely(!cpy_r_r438)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 117, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL432: ;
    CPyTagged_INCREF(cpy_r_r429);
    cpy_r_r439 = CPyTagged_StealAsObject(cpy_r_r429);
    cpy_r_r440 = PyTuple_New(4);
    if (unlikely(cpy_r_r440 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp15 = cpy_r_r436.f0;
    PyTuple_SET_ITEM(cpy_r_r440, 0, __tmp15);
    PyObject *__tmp16 = cpy_r_r436.f1;
    PyTuple_SET_ITEM(cpy_r_r440, 1, __tmp16);
    PyObject *__tmp17 = CPyTagged_StealAsObject(cpy_r_r436.f2);
    PyTuple_SET_ITEM(cpy_r_r440, 2, __tmp17);
    PyObject *__tmp18 = cpy_r_r436.f3;
    PyTuple_SET_ITEM(cpy_r_r440, 3, __tmp18);
    PyObject *cpy_r_r441[3] = {cpy_r_r439, cpy_r_r431, cpy_r_r440};
    cpy_r_r442 = (PyObject **)&cpy_r_r441;
    cpy_r_r443 = PyObject_Vectorcall(cpy_r_r437, cpy_r_r442, 3, 0);
    if (unlikely(cpy_r_r443 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 117, CPyStatic__nonce___globals);
        goto CPyL602;
    } else
        goto CPyL603;
CPyL433: ;
    CPy_DECREF(cpy_r_r439);
    CPy_DECREF(cpy_r_r440);
    goto CPyL298;
CPyL434: ;
    cpy_r_r444 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_debug_logs_enabled;
    if (unlikely(cpy_r_r444 == 2)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "debug_logs_enabled", 124, CPyStatic__nonce___globals);
        goto CPyL604;
    }
CPyL435: ;
    if (!cpy_r_r444) goto CPyL447;
CPyL436: ;
    cpy_r_r445 = CPyStatic__nonce___DEBUG;
    if (unlikely(cpy_r_r445 == CPY_INT_TAG)) {
        goto CPyL605;
    } else
        goto CPyL439;
CPyL437: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"DEBUG\" was not set");
    cpy_r_r446 = 0;
    if (unlikely(!cpy_r_r446)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 125, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL439: ;
    cpy_r_r447 = CPyStatics[16]; /* 'Found nonce %s for %s at block %s' */
    cpy_r_r448 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_nonce;
    if (unlikely(cpy_r_r448 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "nonce", 125, CPyStatic__nonce___globals);
        goto CPyL604;
    }
    CPyTagged_INCREF(cpy_r_r448);
CPyL440: ;
    cpy_r_r449 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_address;
    if (unlikely(cpy_r_r449 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "address", 125, CPyStatic__nonce___globals);
        goto CPyL606;
    }
    CPy_INCREF(cpy_r_r449);
CPyL441: ;
    cpy_r_r450 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r450 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 125, CPyStatic__nonce___globals);
        goto CPyL607;
    }
    CPy_INCREF(cpy_r_r450);
CPyL442: ;
    cpy_r_r451.f0 = cpy_r_r448;
    cpy_r_r451.f1 = cpy_r_r449;
    cpy_r_r451.f2 = cpy_r_r450;
    cpy_r_r452 = CPyStatic__nonce_____log;
    if (unlikely(cpy_r_r452 == NULL)) {
        goto CPyL608;
    } else
        goto CPyL445;
CPyL443: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"__log\" was not set");
    cpy_r_r453 = 0;
    if (unlikely(!cpy_r_r453)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 125, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL445: ;
    CPyTagged_INCREF(cpy_r_r445);
    cpy_r_r454 = CPyTagged_StealAsObject(cpy_r_r445);
    cpy_r_r455 = PyTuple_New(3);
    if (unlikely(cpy_r_r455 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp19 = CPyTagged_StealAsObject(cpy_r_r451.f0);
    PyTuple_SET_ITEM(cpy_r_r455, 0, __tmp19);
    PyObject *__tmp20 = cpy_r_r451.f1;
    PyTuple_SET_ITEM(cpy_r_r455, 1, __tmp20);
    PyObject *__tmp21 = cpy_r_r451.f2;
    PyTuple_SET_ITEM(cpy_r_r455, 2, __tmp21);
    PyObject *cpy_r_r456[3] = {cpy_r_r454, cpy_r_r447, cpy_r_r455};
    cpy_r_r457 = (PyObject **)&cpy_r_r456;
    cpy_r_r458 = PyObject_Vectorcall(cpy_r_r452, cpy_r_r457, 3, 0);
    if (unlikely(cpy_r_r458 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 125, CPyStatic__nonce___globals);
        goto CPyL609;
    } else
        goto CPyL610;
CPyL446: ;
    CPy_DECREF(cpy_r_r454);
    CPy_DECREF(cpy_r_r455);
CPyL447: ;
    cpy_r_r459 = ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->_lo;
    if (unlikely(cpy_r_r459 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", "get_block_for_nonce_env", "lo", 127, CPyStatic__nonce___globals);
        goto CPyL604;
    }
    CPy_INCREF(cpy_r_r459);
CPyL448: ;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ = -2;
    cpy_r_r460 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r16);
    if (unlikely(!cpy_r_r460)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 127, CPyStatic__nonce___globals);
        goto CPyL611;
    }
    CPyGen_SetStopIterationValue(cpy_r_r459);
    CPy_DECREF(cpy_r_r459);
    if (!0) goto CPyL464;
    CPy_Unreachable();
CPyL451: ;
    cpy_r_r461 = Py_None;
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r16)->___mypyc_next_label__ = -2;
    cpy_r_r462 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r16);
    if (unlikely(!cpy_r_r462)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPyGen_SetStopIterationValue(cpy_r_r461);
    if (!0) goto CPyL464;
    CPy_Unreachable();
CPyL454: ;
    cpy_r_r463 = cpy_r_r17 == 0;
    if (cpy_r_r463) goto CPyL612;
    cpy_r_r464 = cpy_r_r17 == 2;
    if (cpy_r_r464) {
        goto CPyL613;
    } else
        goto CPyL614;
CPyL456: ;
    cpy_r_r465 = cpy_r_r17 == 4;
    if (cpy_r_r465) {
        goto CPyL615;
    } else
        goto CPyL616;
CPyL457: ;
    cpy_r_r466 = cpy_r_r17 == 6;
    if (cpy_r_r466) {
        goto CPyL617;
    } else
        goto CPyL618;
CPyL458: ;
    cpy_r_r467 = cpy_r_r17 == 8;
    if (cpy_r_r467) {
        goto CPyL619;
    } else
        goto CPyL620;
CPyL459: ;
    cpy_r_r468 = cpy_r_r17 == 10;
    if (cpy_r_r468) {
        goto CPyL621;
    } else
        goto CPyL622;
CPyL460: ;
    cpy_r_r469 = cpy_r_r17 == 12;
    if (cpy_r_r469) goto CPyL623;
    cpy_r_r470 = cpy_r_r17 == 14;
    CPyTagged_DECREF(cpy_r_r17);
    if (cpy_r_r470) {
        goto CPyL383;
    } else
        goto CPyL624;
CPyL462: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r471 = 0;
    if (unlikely(!cpy_r_r471)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
        goto CPyL464;
    }
    CPy_Unreachable();
CPyL464: ;
    cpy_r_r472 = NULL;
    return cpy_r_r472;
CPyL465: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11.f0);
    CPy_XDecRef(cpy_r_r11.f1);
    CPy_XDecRef(cpy_r_r11.f2);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    goto CPyL464;
CPyL466: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r11.f0);
    CPy_XDecRef(cpy_r_r11.f1);
    CPy_XDecRef(cpy_r_r11.f2);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL464;
CPyL467: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL3;
CPyL468: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL6;
CPyL469: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL464;
CPyL470: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r24);
    goto CPyL464;
CPyL471: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r23);
    goto CPyL464;
CPyL472: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r32);
    goto CPyL464;
CPyL473: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL20;
CPyL474: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL464;
CPyL475: ;
    CPy_DecRef(cpy_r_r41);
    goto CPyL29;
CPyL476: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL24;
CPyL477: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL27;
CPyL478: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    goto CPyL37;
CPyL479: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r41);
    goto CPyL37;
CPyL480: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    goto CPyL37;
CPyL481: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_arg);
    goto CPyL464;
CPyL482: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL43;
CPyL483: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    goto CPyL203;
CPyL484: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    goto CPyL48;
CPyL485: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL49;
CPyL486: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r65);
    goto CPyL203;
CPyL487: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r74);
    goto CPyL203;
CPyL488: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r76.f2);
    goto CPyL203;
CPyL489: ;
    CPy_DECREF(cpy_r_r76.f2);
    goto CPyL99;
CPyL490: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r83);
    goto CPyL203;
CPyL491: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r95);
    goto CPyL203;
CPyL492: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r105);
    goto CPyL203;
CPyL493: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r115);
    goto CPyL203;
CPyL494: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r125);
    goto CPyL203;
CPyL495: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    goto CPyL103;
CPyL496: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL104;
CPyL497: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r136);
    goto CPyL203;
CPyL498: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL114;
CPyL499: ;
    CPy_XDecRef(cpy_r_r5);
    goto CPyL115;
CPyL500: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL116;
CPyL501: ;
    CPy_XDecRef(cpy_r_r5);
    goto CPyL203;
CPyL502: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r149);
    goto CPyL203;
CPyL503: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL128;
CPyL504: ;
    CPy_DecRef(cpy_r_r160);
    goto CPyL137;
CPyL505: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL132;
CPyL506: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL135;
CPyL507: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    goto CPyL145;
CPyL508: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r160);
    goto CPyL145;
CPyL509: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r159);
    goto CPyL145;
CPyL510: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL147;
CPyL511: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_arg);
    goto CPyL203;
CPyL512: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL151;
CPyL513: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r177);
    goto CPyL203;
CPyL514: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    goto CPyL246;
CPyL515: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r191);
    goto CPyL203;
CPyL516: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r191);
    CPyTagged_DecRef(cpy_r_r192);
    goto CPyL203;
CPyL517: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r191);
    CPyTagged_DecRef(cpy_r_r192);
    CPy_DecRef(cpy_r_r193);
    goto CPyL203;
CPyL518: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r191);
    CPyTagged_DecRef(cpy_r_r192);
    CPy_DecRef(cpy_r_r193);
    CPy_DecRef(cpy_r_r194);
    goto CPyL203;
CPyL519: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL175;
CPyL520: ;
    CPy_DecRef(cpy_r_r203);
    goto CPyL184;
CPyL521: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL179;
CPyL522: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL182;
CPyL523: ;
    CPy_XDecRef(cpy_r_r5);
    goto CPyL192;
CPyL524: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r203);
    goto CPyL192;
CPyL525: ;
    CPy_DecRef(cpy_r_r202);
    goto CPyL192;
CPyL526: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL194;
CPyL527: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_arg);
    goto CPyL203;
CPyL528: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL198;
CPyL529: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL246;
CPyL530: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL243;
CPyL531: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r230);
    CPy_DecRef(cpy_r_r231);
    CPy_DecRef(cpy_r_r232);
    goto CPyL243;
CPyL532: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r230);
    CPy_DecRef(cpy_r_r231);
    CPy_DecRef(cpy_r_r232);
    CPy_DecRef(cpy_r_r233);
    goto CPyL243;
CPyL533: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r230);
    CPy_DecRef(cpy_r_r231);
    CPy_DecRef(cpy_r_r232);
    CPy_DecRef(cpy_r_r234);
    goto CPyL243;
CPyL534: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL212;
CPyL535: ;
    CPy_DecRef(cpy_r_r244);
    goto CPyL221;
CPyL536: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL216;
CPyL537: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL219;
CPyL538: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL229;
CPyL539: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r244);
    goto CPyL229;
CPyL540: ;
    CPy_DecRef(cpy_r_r243);
    goto CPyL229;
CPyL541: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL231;
CPyL542: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_arg);
    goto CPyL243;
CPyL543: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL235;
CPyL544: ;
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL240;
CPyL545: ;
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL245;
CPyL546: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL285;
CPyL547: ;
    CPy_XDECREF(cpy_r_r9);
    goto CPyL282;
CPyL548: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r270);
    goto CPyL285;
CPyL549: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r271);
    goto CPyL285;
CPyL550: ;
    CPy_XDECREF(cpy_r_r9);
    goto CPyL257;
CPyL551: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL285;
CPyL552: ;
    CPy_DecRef(cpy_r_r281);
    goto CPyL266;
CPyL553: ;
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL261;
CPyL554: ;
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL264;
CPyL555: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    goto CPyL274;
CPyL556: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r281);
    goto CPyL274;
CPyL557: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    goto CPyL274;
CPyL558: ;
    CPy_XDecRef(cpy_r_r11.f0);
    CPy_XDecRef(cpy_r_r11.f1);
    CPy_XDecRef(cpy_r_r11.f2);
    goto CPyL276;
CPyL559: ;
    CPy_XDecRef(cpy_r_r9);
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_arg);
    goto CPyL285;
CPyL560: ;
    CPy_XDECREF(cpy_r_r9);
    goto CPyL280;
CPyL561: ;
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL283;
CPyL562: ;
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
    goto CPyL284;
CPyL563: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL290;
CPyL564: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL293;
CPyL565: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r302);
    goto CPyL464;
CPyL566: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL464;
CPyL567: ;
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    goto CPyL451;
CPyL568: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r308);
    goto CPyL464;
CPyL569: ;
    CPy_DecRef(cpy_r_r317);
    goto CPyL315;
CPyL570: ;
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL310;
CPyL571: ;
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL313;
CPyL572: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    goto CPyL323;
CPyL573: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r317);
    goto CPyL323;
CPyL574: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r316);
    goto CPyL323;
CPyL575: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_arg);
    goto CPyL464;
CPyL576: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r335);
    goto CPyL464;
CPyL577: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r346);
    goto CPyL464;
CPyL578: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r346);
    CPy_DecRef(cpy_r_r347);
    goto CPyL464;
CPyL579: ;
    CPyTagged_DECREF(cpy_r_r353);
    goto CPyL352;
CPyL580: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL358;
CPyL581: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r364);
    goto CPyL464;
CPyL582: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r364);
    CPy_DecRef(cpy_r_r365);
    goto CPyL464;
CPyL583: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r364);
    CPy_DecRef(cpy_r_r365);
    CPyTagged_DecRef(cpy_r_r366);
    goto CPyL464;
CPyL584: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r368.f0);
    CPy_DecRef(cpy_r_r368.f1);
    CPyTagged_DecRef(cpy_r_r368.f2);
    CPy_DecRef(cpy_r_r368.f3);
    goto CPyL365;
CPyL585: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r371);
    CPy_DecRef(cpy_r_r372);
    goto CPyL464;
CPyL586: ;
    CPy_DECREF(cpy_r_r375);
    goto CPyL368;
CPyL587: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r376);
    goto CPyL464;
CPyL588: ;
    CPy_DecRef(cpy_r_r389);
    goto CPyL387;
CPyL589: ;
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL382;
CPyL590: ;
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL385;
CPyL591: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    goto CPyL395;
CPyL592: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r389);
    goto CPyL395;
CPyL593: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r388);
    goto CPyL395;
CPyL594: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_arg);
    goto CPyL464;
CPyL595: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r407);
    goto CPyL464;
CPyL596: ;
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    goto CPyL434;
CPyL597: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL423;
CPyL598: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r432);
    goto CPyL464;
CPyL599: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r432);
    CPy_DecRef(cpy_r_r433);
    goto CPyL464;
CPyL600: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r432);
    CPy_DecRef(cpy_r_r433);
    CPyTagged_DecRef(cpy_r_r434);
    goto CPyL464;
CPyL601: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r436.f0);
    CPy_DecRef(cpy_r_r436.f1);
    CPyTagged_DecRef(cpy_r_r436.f2);
    CPy_DecRef(cpy_r_r436.f3);
    goto CPyL430;
CPyL602: ;
    CPy_XDecRef(cpy_r_r13);
    CPy_XDecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r439);
    CPy_DecRef(cpy_r_r440);
    goto CPyL464;
CPyL603: ;
    CPy_DECREF(cpy_r_r443);
    goto CPyL433;
CPyL604: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL464;
CPyL605: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL437;
CPyL606: ;
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r448);
    goto CPyL464;
CPyL607: ;
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r448);
    CPy_DecRef(cpy_r_r449);
    goto CPyL464;
CPyL608: ;
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r451.f0);
    CPy_DecRef(cpy_r_r451.f1);
    CPy_DecRef(cpy_r_r451.f2);
    goto CPyL443;
CPyL609: ;
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r454);
    CPy_DecRef(cpy_r_r455);
    goto CPyL464;
CPyL610: ;
    CPy_DECREF(cpy_r_r458);
    goto CPyL446;
CPyL611: ;
    CPy_DecRef(cpy_r_r459);
    goto CPyL464;
CPyL612: ;
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
    CPyTagged_DECREF(cpy_r_r17);
    goto CPyL2;
CPyL613: ;
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
    CPyTagged_DECREF(cpy_r_r17);
    goto CPyL25;
CPyL614: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL456;
CPyL615: ;
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
    CPyTagged_DECREF(cpy_r_r17);
    goto CPyL133;
CPyL616: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL457;
CPyL617: ;
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
    CPyTagged_DECREF(cpy_r_r17);
    goto CPyL180;
CPyL618: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL458;
CPyL619: ;
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
    CPyTagged_DECREF(cpy_r_r17);
    goto CPyL217;
CPyL620: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL459;
CPyL621: ;
    CPyTagged_DECREF(cpy_r_r17);
    goto CPyL262;
CPyL622: ;
    CPy_XDECREF(cpy_r_r9);
    CPy_XDECREF(cpy_r_r11.f0);
    CPy_XDECREF(cpy_r_r11.f1);
    CPy_XDECREF(cpy_r_r11.f2);
    goto CPyL460;
CPyL623: ;
    CPyTagged_DECREF(cpy_r_r17);
    goto CPyL311;
CPyL624: ;
    CPy_XDECREF(cpy_r_r13);
    CPy_XDECREF(cpy_r_r15);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL462;
}

PyObject *CPyPy__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", "arg", 0};
    static CPyArg_Parser parser = {"OOOO:__mypyc_generator_helper__", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value;
    PyObject *obj_traceback;
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_type = obj_type;
    PyObject *arg_value = obj_value;
    PyObject *arg_traceback = obj_traceback;
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_for_nonce_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__nonce___get_block_for_nonce_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_for_nonce_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_for_nonce_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_block_for_nonce_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__next__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_for_nonce_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__nonce___get_block_for_nonce_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_for_nonce_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_for_nonce_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__nonce___get_block_for_nonce_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "send", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_for_nonce_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__nonce___get_block_for_nonce_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_for_nonce_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_for_nonce_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_block_for_nonce_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__iter__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_for_nonce_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy__nonce___get_block_for_nonce_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_for_nonce_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_for_nonce_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef__nonce___get_block_for_nonce_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "throw", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_for_nonce_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[10]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef__nonce___get_block_for_nonce_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[11]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp22 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp22);
    PyObject *__tmp23 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp23);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy__nonce___get_block_for_nonce_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_for_nonce_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_for_nonce_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_block_for_nonce_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "close", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_for_nonce_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__nonce___get_block_for_nonce_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_for_nonce_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_for_nonce_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_block_for_nonce_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__await__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_for_nonce(PyObject *cpy_r_address, CPyTagged cpy_r_nonce) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    cpy_r_r0 = CPyDef__nonce___get_block_for_nonce_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_address);
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r0)->_address != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r0)->_address);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r0)->_address = cpy_r_address;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
        goto CPyL8;
    }
    CPyTagged_INCREF(cpy_r_nonce);
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r0)->_nonce != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r0)->_nonce);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r0)->_nonce = cpy_r_nonce;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
        goto CPyL8;
    }
    cpy_r_r3 = CPyDef__nonce___get_block_for_nonce_gen();
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
        goto CPyL8;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_genObject *)cpy_r_r3)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce___get_block_for_nonce_genObject *)cpy_r_r3)->___mypyc_env__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_genObject *)cpy_r_r3)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
        goto CPyL9;
    }
    if (((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_for_nonce_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r5 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
        goto CPyL10;
    }
    return cpy_r_r3;
CPyL7: ;
    cpy_r_r6 = NULL;
    return cpy_r_r6;
CPyL8: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL7;
CPyL9: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r3);
    goto CPyL7;
CPyL10: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL7;
}

PyObject *CPyPy__nonce___get_block_for_nonce(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"address", "nonce", 0};
    static CPyArg_Parser parser = {"OO:get_block_for_nonce", kwlist, 0};
    PyObject *obj_address;
    PyObject *obj_nonce;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_address, &obj_nonce)) {
        return NULL;
    }
    PyObject *arg_address = obj_address;
    CPyTagged arg_nonce;
    if (likely(PyLong_Check(obj_nonce)))
        arg_nonce = CPyTagged_BorrowFromObject(obj_nonce);
    else {
        CPy_TypeError("int", obj_nonce); goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_block_for_nonce(arg_address, arg_nonce);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_for_nonce", 64, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce____get_area_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    CPyTagged cpy_r_r6;
    CPyTagged cpy_r_r7;
    char cpy_r_r8;
    CPyTagged cpy_r_r9;
    CPyTagged cpy_r_r10;
    CPyTagged cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    CPyTagged cpy_r_r15;
    char cpy_r_r16;
    CPyTagged cpy_r_r17;
    char cpy_r_r18;
    CPyTagged cpy_r_r19;
    char cpy_r_r20;
    CPyTagged cpy_r_r21;
    CPyTagged cpy_r_r22;
    int64_t cpy_r_r23;
    char cpy_r_r24;
    int64_t cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    CPyTagged cpy_r_r31;
    CPyTagged cpy_r_r32;
    CPyTagged cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    CPyTagged cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    int32_t cpy_r_r39;
    char cpy_r_r40;
    CPyTagged cpy_r_r41;
    CPyTagged cpy_r_r42;
    char cpy_r_r43;
    char cpy_r_r44;
    PyObject *cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    CPyPtr cpy_r_r48;
    int64_t cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_r53;
    CPyPtr cpy_r_r54;
    int64_t cpy_r_r55;
    CPyTagged cpy_r_r56;
    CPyTagged cpy_r_r57;
    char cpy_r_r58;
    PyObject *cpy_r_r59;
    CPyTagged cpy_r_r60;
    int64_t cpy_r_r61;
    CPyPtr cpy_r_r62;
    CPyPtr cpy_r_r63;
    int64_t cpy_r_r64;
    CPyPtr cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    CPyTagged cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    char cpy_r_r72;
    CPyTagged cpy_r_r73;
    CPyTagged cpy_r_r74;
    char cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    char cpy_r_r78;
    PyObject **cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    char cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    char cpy_r_r89;
    PyObject *cpy_r_r90;
    char cpy_r_r91;
    tuple_T3OOO cpy_r_r92;
    char cpy_r_r93;
    PyObject **cpy_r_r94;
    PyObject *cpy_r_r95;
    char cpy_r_r96;
    tuple_T3OOO cpy_r_r97;
    tuple_T3OOO cpy_r_r98;
    tuple_T3OOO cpy_r_r99;
    char cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    char cpy_r_r105;
    PyObject *cpy_r_r106;
    char cpy_r_r107;
    char cpy_r_r108;
    PyObject *cpy_r_r109;
    char cpy_r_r110;
    char cpy_r_r111;
    PyObject *cpy_r_r112;
    CPyPtr cpy_r_r113;
    int64_t cpy_r_r114;
    CPyTagged cpy_r_r115;
    CPyTagged cpy_r_r116;
    char cpy_r_r117;
    PyObject *cpy_r_r118;
    CPyPtr cpy_r_r119;
    int64_t cpy_r_r120;
    CPyTagged cpy_r_r121;
    CPyTagged cpy_r_r122;
    char cpy_r_r123;
    PyObject *cpy_r_r124;
    CPyTagged cpy_r_r125;
    int64_t cpy_r_r126;
    CPyPtr cpy_r_r127;
    CPyPtr cpy_r_r128;
    int64_t cpy_r_r129;
    CPyPtr cpy_r_r130;
    PyObject *cpy_r_r131;
    char cpy_r_r132;
    PyObject *cpy_r_r133;
    CPyTagged cpy_r_r134;
    int64_t cpy_r_r135;
    CPyPtr cpy_r_r136;
    CPyPtr cpy_r_r137;
    int64_t cpy_r_r138;
    CPyPtr cpy_r_r139;
    PyObject *cpy_r_r140;
    CPyTagged cpy_r_r141;
    char cpy_r_r142;
    CPyTagged cpy_r_r143;
    CPyTagged cpy_r_r144;
    int64_t cpy_r_r145;
    char cpy_r_r146;
    int64_t cpy_r_r147;
    char cpy_r_r148;
    char cpy_r_r149;
    char cpy_r_r150;
    char cpy_r_r151;
    char cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    tuple_T2OO cpy_r_r155;
    PyObject *cpy_r_r156;
    char cpy_r_r157;
    PyObject *cpy_r_r158;
    char cpy_r_r159;
    CPyTagged cpy_r_r160;
    CPyTagged cpy_r_r161;
    char cpy_r_r162;
    CPyTagged cpy_r_r163;
    CPyTagged cpy_r_r164;
    char cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    tuple_T2OO cpy_r_r168;
    PyObject *cpy_r_r169;
    char cpy_r_r170;
    char cpy_r_r171;
    char cpy_r_r172;
    char cpy_r_r173;
    PyObject *cpy_r_r174;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((eth_portfolio____loaders____nonce____get_area_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_gen", "__mypyc_env__", 130, CPyStatic__nonce___globals);
        goto CPyL138;
    }
    CPy_INCREF_NO_IMM(cpy_r_r2);
CPyL1: ;
    cpy_r_r3 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__;
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_next_label__", 130, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPyTagged_INCREF(cpy_r_r3);
    goto CPyL133;
CPyL2: ;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_type != cpy_r_r4;
    if (cpy_r_r5) {
        goto CPyL140;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL137;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r6 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_range_size;
    if (unlikely(cpy_r_r6 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "range_size", 137, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPyTagged_INCREF(cpy_r_r6);
CPyL6: ;
    cpy_r_r7 = CPyDef__nonce____get_num_chunks(cpy_r_r6);
    CPyTagged_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 137, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_num_chunks != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_num_chunks);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_num_chunks = cpy_r_r7;
    cpy_r_r8 = 1;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 137, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r9 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_range_size;
    if (unlikely(cpy_r_r9 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "range_size", 138, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPyTagged_INCREF(cpy_r_r9);
CPyL9: ;
    cpy_r_r10 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_num_chunks;
    if (unlikely(cpy_r_r10 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "num_chunks", 138, CPyStatic__nonce___globals);
        goto CPyL141;
    }
    CPyTagged_INCREF(cpy_r_r10);
CPyL10: ;
    cpy_r_r11 = CPyTagged_FloorDivide(cpy_r_r9, cpy_r_r10);
    CPyTagged_DECREF(cpy_r_r9);
    CPyTagged_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 138, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_chunk_size != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_chunk_size);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_chunk_size = cpy_r_r11;
    cpy_r_r12 = 1;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 138, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r13 = PyList_New(0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__25 != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__25);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__25 = cpy_r_r13;
    cpy_r_r14 = 1;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r15 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_num_chunks;
    if (unlikely(cpy_r_r15 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "num_chunks", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPyTagged_INCREF(cpy_r_r15);
CPyL15: ;
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__26 != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__26);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__26 = cpy_r_r15;
    cpy_r_r16 = 1;
    if (unlikely(!cpy_r_r16)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r17 = 0;
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__27 != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__27);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__27 = cpy_r_r17;
    cpy_r_r18 = 1;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r19 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__27;
    if (unlikely(cpy_r_r19 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__27", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPyTagged_INCREF(cpy_r_r19);
CPyL18: ;
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_i != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_i);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_i = cpy_r_r19;
    cpy_r_r20 = 1;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
CPyL19: ;
    cpy_r_r21 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__27;
    if (unlikely(cpy_r_r21 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__27", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPyTagged_INCREF(cpy_r_r21);
CPyL20: ;
    cpy_r_r22 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__26;
    if (unlikely(cpy_r_r22 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__26", 139, CPyStatic__nonce___globals);
        goto CPyL142;
    }
    CPyTagged_INCREF(cpy_r_r22);
CPyL21: ;
    cpy_r_r23 = cpy_r_r21 & 1;
    cpy_r_r24 = cpy_r_r23 != 0;
    if (cpy_r_r24) goto CPyL23;
    cpy_r_r25 = cpy_r_r22 & 1;
    cpy_r_r26 = cpy_r_r25 != 0;
    if (!cpy_r_r26) goto CPyL24;
CPyL23: ;
    cpy_r_r27 = CPyTagged_IsLt_(cpy_r_r21, cpy_r_r22);
    cpy_r_r28 = cpy_r_r27;
    goto CPyL25;
CPyL24: ;
    cpy_r_r29 = (Py_ssize_t)cpy_r_r21 < (Py_ssize_t)cpy_r_r22;
    cpy_r_r28 = cpy_r_r29;
CPyL25: ;
    CPyTagged_DECREF(cpy_r_r21);
    CPyTagged_DECREF(cpy_r_r22);
    if (!cpy_r_r28) goto CPyL36;
    cpy_r_r30 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_lo;
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "lo", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPy_INCREF(cpy_r_r30);
CPyL27: ;
    cpy_r_r31 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_i;
    if (unlikely(cpy_r_r31 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "i", 139, CPyStatic__nonce___globals);
        goto CPyL143;
    }
    CPyTagged_INCREF(cpy_r_r31);
CPyL28: ;
    cpy_r_r32 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_chunk_size;
    if (unlikely(cpy_r_r32 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "chunk_size", 139, CPyStatic__nonce___globals);
        goto CPyL144;
    }
    CPyTagged_INCREF(cpy_r_r32);
CPyL29: ;
    cpy_r_r33 = CPyTagged_Multiply(cpy_r_r31, cpy_r_r32);
    CPyTagged_DECREF(cpy_r_r31);
    CPyTagged_DECREF(cpy_r_r32);
    cpy_r_r34 = CPyTagged_StealAsObject(cpy_r_r33);
    cpy_r_r35 = PyNumber_Add(cpy_r_r30, cpy_r_r34);
    CPy_DECREF(cpy_r_r30);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    if (likely(PyLong_Check(cpy_r_r35)))
        cpy_r_r36 = CPyTagged_FromObject(cpy_r_r35);
    else {
        CPy_TypeError("int", cpy_r_r35); cpy_r_r36 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r36 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r37 = CPyTagged_StealAsObject(cpy_r_r36);
    cpy_r_r38 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__25;
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__25", -1, CPyStatic__nonce___globals);
        goto CPyL145;
    }
    CPy_INCREF_NO_IMM(cpy_r_r38);
CPyL32: ;
    cpy_r_r39 = PyList_Append(cpy_r_r38, cpy_r_r37);
    CPy_DECREF_NO_IMM(cpy_r_r38);
    CPy_DECREF(cpy_r_r37);
    cpy_r_r40 = cpy_r_r39 >= 0;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r41 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__27;
    if (unlikely(cpy_r_r41 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__27", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPyTagged_INCREF(cpy_r_r41);
CPyL34: ;
    cpy_r_r42 = CPyTagged_Add(cpy_r_r41, 2);
    CPyTagged_DECREF(cpy_r_r41);
    CPyTagged_INCREF(cpy_r_r42);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__27 != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__27);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__27 = cpy_r_r42;
    cpy_r_r43 = 1;
    if (unlikely(!cpy_r_r43)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 139, CPyStatic__nonce___globals);
        goto CPyL146;
    }
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_i != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_i);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_i = cpy_r_r42;
    cpy_r_r44 = 1;
    if (unlikely(!cpy_r_r44)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    } else
        goto CPyL19;
CPyL36: ;
    cpy_r_r45 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__25;
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__25", -1, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPy_INCREF_NO_IMM(cpy_r_r45);
CPyL37: ;
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_points != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_points);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_points = cpy_r_r45;
    cpy_r_r46 = 1;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 139, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r47 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_points;
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "points", 140, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPy_INCREF_NO_IMM(cpy_r_r47);
CPyL39: ;
    cpy_r_r48 = (CPyPtr)&((PyVarObject *)cpy_r_r47)->ob_size;
    cpy_r_r49 = *(int64_t *)cpy_r_r48;
    cpy_r_r50 = PyList_New(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL147;
    }
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__28 != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__28);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__28 = cpy_r_r47;
    cpy_r_r51 = 1;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL148;
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__29 = 0;
    cpy_r_r52 = 1;
    if (unlikely(!cpy_r_r52)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL148;
    }
CPyL42: ;
    cpy_r_r53 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__28;
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__28", 140, CPyStatic__nonce___globals);
        goto CPyL148;
    }
    CPy_INCREF_NO_IMM(cpy_r_r53);
CPyL43: ;
    cpy_r_r54 = (CPyPtr)&((PyVarObject *)cpy_r_r53)->ob_size;
    cpy_r_r55 = *(int64_t *)cpy_r_r54;
    CPy_DECREF_NO_IMM(cpy_r_r53);
    cpy_r_r56 = cpy_r_r55 << 1;
    cpy_r_r57 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r57 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__29", 140, CPyStatic__nonce___globals);
        goto CPyL148;
    }
CPyL44: ;
    cpy_r_r58 = (Py_ssize_t)cpy_r_r57 < (Py_ssize_t)cpy_r_r56;
    if (!cpy_r_r58) goto CPyL55;
    cpy_r_r59 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__28;
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__28", 140, CPyStatic__nonce___globals);
        goto CPyL148;
    }
    CPy_INCREF_NO_IMM(cpy_r_r59);
CPyL46: ;
    cpy_r_r60 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r60 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__29", 140, CPyStatic__nonce___globals);
        goto CPyL149;
    }
CPyL47: ;
    cpy_r_r61 = (Py_ssize_t)cpy_r_r60 >> 1;
    cpy_r_r62 = (CPyPtr)&((PyListObject *)cpy_r_r59)->ob_item;
    cpy_r_r63 = *(CPyPtr *)cpy_r_r62;
    cpy_r_r64 = cpy_r_r61 * 8;
    cpy_r_r65 = cpy_r_r63 + cpy_r_r64;
    cpy_r_r66 = *(PyObject * *)cpy_r_r65;
    CPy_INCREF(cpy_r_r66);
    CPy_DECREF_NO_IMM(cpy_r_r59);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_point != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_point);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_point = cpy_r_r66;
    cpy_r_r67 = 1;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL148;
    }
    cpy_r_r68 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r68 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__29", -1, CPyStatic__nonce___globals);
        goto CPyL148;
    }
CPyL49: ;
    cpy_r_r69 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_address;
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "address", 140, CPyStatic__nonce___globals);
        goto CPyL148;
    }
    CPy_INCREF(cpy_r_r69);
CPyL50: ;
    cpy_r_r70 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_point;
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "point", 140, CPyStatic__nonce___globals);
        goto CPyL150;
    }
    CPy_INCREF(cpy_r_r70);
CPyL51: ;
    cpy_r_r71 = CPyDef__nonce___get_nonce_at_block(cpy_r_r69, cpy_r_r70);
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL148;
    }
    cpy_r_r72 = CPyList_SetItemUnsafe(cpy_r_r50, cpy_r_r68, cpy_r_r71);
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL148;
    }
    cpy_r_r73 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__29;
    if (unlikely(cpy_r_r73 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__29", 140, CPyStatic__nonce___globals);
        goto CPyL148;
    }
CPyL54: ;
    cpy_r_r74 = cpy_r_r73 + 2;
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__29 = cpy_r_r74;
    cpy_r_r75 = 1;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL148;
    } else
        goto CPyL42;
CPyL55: ;
    cpy_r_r76 = PyObject_GetIter(cpy_r_r50);
    CPy_DECREF_NO_IMM(cpy_r_r50);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r77 = CPyStatic__nonce___igather;
    if (unlikely(cpy_r_r77 == NULL)) {
        goto CPyL151;
    } else
        goto CPyL59;
CPyL57: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"igather\" was not set");
    cpy_r_r78 = 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL137;
    }
    CPy_Unreachable();
CPyL59: ;
    PyObject *cpy_r_r79[1] = {cpy_r_r76};
    cpy_r_r80 = (PyObject **)&cpy_r_r79;
    cpy_r_r81 = PyObject_Vectorcall(cpy_r_r77, cpy_r_r80, 1, 0);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL152;
    }
    CPy_DECREF(cpy_r_r76);
    cpy_r_r82 = CPy_GetCoro(cpy_r_r81);
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__30 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__30);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__30 = cpy_r_r82;
    cpy_r_r83 = 1;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    cpy_r_r84 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__30;
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__30", -1, CPyStatic__nonce___globals);
        goto CPyL139;
    }
    CPy_INCREF(cpy_r_r84);
CPyL63: ;
    cpy_r_r85 = CPyIter_Next(cpy_r_r84);
    CPy_DECREF(cpy_r_r84);
    if (cpy_r_r85 == NULL) {
        goto CPyL153;
    } else
        goto CPyL66;
CPyL64: ;
    cpy_r_r86 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    cpy_r_r87 = cpy_r_r86;
    goto CPyL89;
CPyL66: ;
    cpy_r_r88 = cpy_r_r85;
CPyL67: ;
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__ = 2;
    cpy_r_r89 = 1;
    if (unlikely(!cpy_r_r89)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL155;
    } else
        goto CPyL156;
CPyL68: ;
    return cpy_r_r88;
CPyL69: ;
    cpy_r_r90 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r91 = cpy_r_type != cpy_r_r90;
    if (!cpy_r_r91) goto CPyL72;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL73;
    } else
        goto CPyL157;
CPyL71: ;
    CPy_Unreachable();
CPyL72: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL84;
CPyL73: ;
    cpy_r_r92 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__31.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__31.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__31.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__31.f2);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__31 = cpy_r_r92;
    cpy_r_r93 = 1;
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL158;
    }
    cpy_r_r94 = (PyObject **)&cpy_r_r1;
    cpy_r_r95 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__30;
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__30", -1, CPyStatic__nonce___globals);
        goto CPyL158;
    }
    CPy_INCREF(cpy_r_r95);
CPyL75: ;
    cpy_r_r96 = CPy_YieldFromErrorHandle(cpy_r_r95, cpy_r_r94);
    CPy_DecRef(cpy_r_r95);
    if (unlikely(cpy_r_r96 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL158;
    }
    if (cpy_r_r96) goto CPyL79;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r88 = cpy_r_r1;
    cpy_r_r97 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__31;
    if (unlikely(cpy_r_r97.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__31", -1, CPyStatic__nonce___globals);
        goto CPyL159;
    }
    CPy_INCREF(cpy_r_r97.f0);
    CPy_INCREF(cpy_r_r97.f1);
    CPy_INCREF(cpy_r_r97.f2);
CPyL78: ;
    CPy_RestoreExcInfo(cpy_r_r97);
    CPy_DecRef(cpy_r_r97.f0);
    CPy_DecRef(cpy_r_r97.f1);
    CPy_DecRef(cpy_r_r97.f2);
    goto CPyL67;
CPyL79: ;
    cpy_r_r87 = cpy_r_r1;
    cpy_r_r98 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__31;
    if (unlikely(cpy_r_r98.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__31", -1, CPyStatic__nonce___globals);
        goto CPyL160;
    }
    CPy_INCREF(cpy_r_r98.f0);
    CPy_INCREF(cpy_r_r98.f1);
    CPy_INCREF(cpy_r_r98.f2);
CPyL80: ;
    CPy_RestoreExcInfo(cpy_r_r98);
    CPy_DecRef(cpy_r_r98.f0);
    CPy_DecRef(cpy_r_r98.f1);
    CPy_DecRef(cpy_r_r98.f2);
    goto CPyL89;
CPyL81: ;
    cpy_r_r99 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__31;
    if (unlikely(cpy_r_r99.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__31' of '_get_area_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r99.f0);
        CPy_INCREF(cpy_r_r99.f1);
        CPy_INCREF(cpy_r_r99.f2);
    }
    CPy_DecRef(cpy_r_r2);
    if (unlikely(cpy_r_r99.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL137;
    }
CPyL82: ;
    CPy_RestoreExcInfo(cpy_r_r99);
    CPy_DecRef(cpy_r_r99.f0);
    CPy_DecRef(cpy_r_r99.f1);
    CPy_DecRef(cpy_r_r99.f2);
    cpy_r_r100 = CPy_KeepPropagating();
    if (!cpy_r_r100) goto CPyL137;
    CPy_Unreachable();
CPyL84: ;
    cpy_r_r101 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__30;
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__30", -1, CPyStatic__nonce___globals);
        goto CPyL161;
    }
    CPy_INCREF(cpy_r_r101);
CPyL85: ;
    cpy_r_r102 = CPyIter_Send(cpy_r_r101, cpy_r_arg);
    CPy_DECREF(cpy_r_r101);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r102 == NULL) goto CPyL162;
    cpy_r_r88 = cpy_r_r102;
    goto CPyL67;
CPyL87: ;
    cpy_r_r103 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    cpy_r_r87 = cpy_r_r103;
CPyL89: ;
    if (likely(PyList_Check(cpy_r_r87)))
        cpy_r_r104 = cpy_r_r87;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals, "list", cpy_r_r87);
        goto CPyL154;
    }
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_nonces != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_nonces);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_nonces = cpy_r_r104;
    cpy_r_r105 = 1;
    if (unlikely(!cpy_r_r105)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 140, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    cpy_r_r106 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_points;
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "points", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPy_INCREF_NO_IMM(cpy_r_r106);
CPyL92: ;
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__32 != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__32);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__32 = cpy_r_r106;
    cpy_r_r107 = 1;
    if (unlikely(!cpy_r_r107)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__33 = 0;
    cpy_r_r108 = 1;
    if (unlikely(!cpy_r_r108)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    cpy_r_r109 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_nonces;
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "nonces", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPy_INCREF_NO_IMM(cpy_r_r109);
CPyL95: ;
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__34 != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__34);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__34 = cpy_r_r109;
    cpy_r_r110 = 1;
    if (unlikely(!cpy_r_r110)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__35 = 0;
    cpy_r_r111 = 1;
    if (unlikely(!cpy_r_r111)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", -1, CPyStatic__nonce___globals);
        goto CPyL154;
    }
CPyL97: ;
    cpy_r_r112 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__32;
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__32", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPy_INCREF_NO_IMM(cpy_r_r112);
CPyL98: ;
    cpy_r_r113 = (CPyPtr)&((PyVarObject *)cpy_r_r112)->ob_size;
    cpy_r_r114 = *(int64_t *)cpy_r_r113;
    CPy_DECREF_NO_IMM(cpy_r_r112);
    cpy_r_r115 = cpy_r_r114 << 1;
    cpy_r_r116 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__33;
    if (unlikely(cpy_r_r116 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__33", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
CPyL99: ;
    cpy_r_r117 = (Py_ssize_t)cpy_r_r116 < (Py_ssize_t)cpy_r_r115;
    if (!cpy_r_r117) goto CPyL128;
    cpy_r_r118 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__34;
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__34", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPy_INCREF_NO_IMM(cpy_r_r118);
CPyL101: ;
    cpy_r_r119 = (CPyPtr)&((PyVarObject *)cpy_r_r118)->ob_size;
    cpy_r_r120 = *(int64_t *)cpy_r_r119;
    CPy_DECREF_NO_IMM(cpy_r_r118);
    cpy_r_r121 = cpy_r_r120 << 1;
    cpy_r_r122 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__35;
    if (unlikely(cpy_r_r122 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__35", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
CPyL102: ;
    cpy_r_r123 = (Py_ssize_t)cpy_r_r122 < (Py_ssize_t)cpy_r_r121;
    if (!cpy_r_r123) goto CPyL128;
    cpy_r_r124 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__32;
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__32", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPy_INCREF_NO_IMM(cpy_r_r124);
CPyL104: ;
    cpy_r_r125 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__33;
    if (unlikely(cpy_r_r125 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__33", 141, CPyStatic__nonce___globals);
        goto CPyL163;
    }
CPyL105: ;
    cpy_r_r126 = (Py_ssize_t)cpy_r_r125 >> 1;
    cpy_r_r127 = (CPyPtr)&((PyListObject *)cpy_r_r124)->ob_item;
    cpy_r_r128 = *(CPyPtr *)cpy_r_r127;
    cpy_r_r129 = cpy_r_r126 * 8;
    cpy_r_r130 = cpy_r_r128 + cpy_r_r129;
    cpy_r_r131 = *(PyObject * *)cpy_r_r130;
    CPy_INCREF(cpy_r_r131);
    CPy_DECREF_NO_IMM(cpy_r_r124);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_block != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_block);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_block = cpy_r_r131;
    cpy_r_r132 = 1;
    if (unlikely(!cpy_r_r132)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    cpy_r_r133 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__34;
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__34", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPy_INCREF_NO_IMM(cpy_r_r133);
CPyL107: ;
    cpy_r_r134 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__35;
    if (unlikely(cpy_r_r134 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__35", 141, CPyStatic__nonce___globals);
        goto CPyL164;
    }
CPyL108: ;
    cpy_r_r135 = (Py_ssize_t)cpy_r_r134 >> 1;
    cpy_r_r136 = (CPyPtr)&((PyListObject *)cpy_r_r133)->ob_item;
    cpy_r_r137 = *(CPyPtr *)cpy_r_r136;
    cpy_r_r138 = cpy_r_r135 * 8;
    cpy_r_r139 = cpy_r_r137 + cpy_r_r138;
    cpy_r_r140 = *(PyObject * *)cpy_r_r139;
    CPy_INCREF(cpy_r_r140);
    CPy_DECREF_NO_IMM(cpy_r_r133);
    if (likely(PyLong_Check(cpy_r_r140)))
        cpy_r_r141 = CPyTagged_FromObject(cpy_r_r140);
    else {
        CPy_TypeError("int", cpy_r_r140); cpy_r_r141 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r140);
    if (unlikely(cpy_r_r141 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_n != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_n);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_n = cpy_r_r141;
    cpy_r_r142 = 1;
    if (unlikely(!cpy_r_r142)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    cpy_r_r143 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_n;
    if (unlikely(cpy_r_r143 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "n", 142, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPyTagged_INCREF(cpy_r_r143);
CPyL111: ;
    cpy_r_r144 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_nonce;
    if (unlikely(cpy_r_r144 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "nonce", 142, CPyStatic__nonce___globals);
        goto CPyL165;
    }
    CPyTagged_INCREF(cpy_r_r144);
CPyL112: ;
    cpy_r_r145 = cpy_r_r143 & 1;
    cpy_r_r146 = cpy_r_r145 != 0;
    if (cpy_r_r146) goto CPyL114;
    cpy_r_r147 = cpy_r_r144 & 1;
    cpy_r_r148 = cpy_r_r147 != 0;
    if (!cpy_r_r148) goto CPyL115;
CPyL114: ;
    cpy_r_r149 = CPyTagged_IsLt_(cpy_r_r143, cpy_r_r144);
    cpy_r_r150 = cpy_r_r149 ^ 1;
    cpy_r_r151 = cpy_r_r150;
    goto CPyL116;
CPyL115: ;
    cpy_r_r152 = (Py_ssize_t)cpy_r_r143 >= (Py_ssize_t)cpy_r_r144;
    cpy_r_r151 = cpy_r_r152;
CPyL116: ;
    CPyTagged_DECREF(cpy_r_r143);
    CPyTagged_DECREF(cpy_r_r144);
    if (!cpy_r_r151) goto CPyL122;
    cpy_r_r153 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_lo;
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "lo", 143, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r153);
CPyL118: ;
    cpy_r_r154 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r154 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "block", 143, CPyStatic__nonce___globals);
        goto CPyL166;
    }
    CPy_INCREF(cpy_r_r154);
CPyL119: ;
    cpy_r_r155.f0 = cpy_r_r153;
    cpy_r_r155.f1 = cpy_r_r154;
    cpy_r_r156 = PyTuple_New(2);
    if (unlikely(cpy_r_r156 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp24 = cpy_r_r155.f0;
    PyTuple_SET_ITEM(cpy_r_r156, 0, __tmp24);
    PyObject *__tmp25 = cpy_r_r155.f1;
    PyTuple_SET_ITEM(cpy_r_r156, 1, __tmp25);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r157 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r2);
    if (unlikely(!cpy_r_r157)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 143, CPyStatic__nonce___globals);
        goto CPyL167;
    }
    CPyGen_SetStopIterationValue(cpy_r_r156);
    CPy_DECREF(cpy_r_r156);
    if (!0) goto CPyL137;
    CPy_Unreachable();
CPyL122: ;
    cpy_r_r158 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r158 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "block", 144, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r158);
CPyL123: ;
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_lo != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_lo);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_lo = cpy_r_r158;
    cpy_r_r159 = 1;
    if (unlikely(!cpy_r_r159)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 144, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    cpy_r_r160 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__33;
    if (unlikely(cpy_r_r160 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__33", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
CPyL125: ;
    cpy_r_r161 = cpy_r_r160 + 2;
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__33 = cpy_r_r161;
    cpy_r_r162 = 1;
    if (unlikely(!cpy_r_r162)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    cpy_r_r163 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__35;
    if (unlikely(cpy_r_r163 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "__mypyc_temp__35", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    }
CPyL127: ;
    cpy_r_r164 = cpy_r_r163 + 2;
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_temp__35 = cpy_r_r164;
    cpy_r_r165 = 1;
    if (unlikely(!cpy_r_r165)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 141, CPyStatic__nonce___globals);
        goto CPyL154;
    } else
        goto CPyL97;
CPyL128: ;
    cpy_r_r166 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_lo;
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "lo", 145, CPyStatic__nonce___globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r166);
CPyL129: ;
    cpy_r_r167 = ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->_hi;
    if (unlikely(cpy_r_r167 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "_get_area", "_get_area_env", "hi", 145, CPyStatic__nonce___globals);
        goto CPyL168;
    }
    CPy_INCREF(cpy_r_r167);
CPyL130: ;
    cpy_r_r168.f0 = cpy_r_r166;
    cpy_r_r168.f1 = cpy_r_r167;
    cpy_r_r169 = PyTuple_New(2);
    if (unlikely(cpy_r_r169 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp26 = cpy_r_r168.f0;
    PyTuple_SET_ITEM(cpy_r_r169, 0, __tmp26);
    PyObject *__tmp27 = cpy_r_r168.f1;
    PyTuple_SET_ITEM(cpy_r_r169, 1, __tmp27);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r170 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r2);
    if (unlikely(!cpy_r_r170)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 145, CPyStatic__nonce___globals);
        goto CPyL169;
    }
    CPyGen_SetStopIterationValue(cpy_r_r169);
    CPy_DECREF(cpy_r_r169);
    if (!0) goto CPyL137;
    CPy_Unreachable();
CPyL133: ;
    cpy_r_r171 = cpy_r_r3 == 0;
    if (cpy_r_r171) goto CPyL170;
    cpy_r_r172 = cpy_r_r3 == 2;
    CPyTagged_DECREF(cpy_r_r3);
    if (cpy_r_r172) {
        goto CPyL69;
    } else
        goto CPyL171;
CPyL135: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r173 = 0;
    if (unlikely(!cpy_r_r173)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL137;
    }
    CPy_Unreachable();
CPyL137: ;
    cpy_r_r174 = NULL;
    return cpy_r_r174;
CPyL138: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL137;
CPyL139: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL137;
CPyL140: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL3;
CPyL141: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r9);
    goto CPyL137;
CPyL142: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r21);
    goto CPyL137;
CPyL143: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r30);
    goto CPyL137;
CPyL144: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r30);
    CPyTagged_DecRef(cpy_r_r31);
    goto CPyL137;
CPyL145: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r37);
    goto CPyL137;
CPyL146: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r42);
    goto CPyL137;
CPyL147: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r47);
    goto CPyL137;
CPyL148: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r50);
    goto CPyL137;
CPyL149: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r50);
    CPy_DecRef(cpy_r_r59);
    goto CPyL137;
CPyL150: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r50);
    CPy_DecRef(cpy_r_r69);
    goto CPyL137;
CPyL151: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r76);
    goto CPyL57;
CPyL152: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r76);
    goto CPyL137;
CPyL153: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL64;
CPyL154: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL137;
CPyL155: ;
    CPy_DecRef(cpy_r_r88);
    goto CPyL73;
CPyL156: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL68;
CPyL157: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL71;
CPyL158: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL81;
CPyL159: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r88);
    goto CPyL81;
CPyL160: ;
    CPy_DecRef(cpy_r_r87);
    goto CPyL81;
CPyL161: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_arg);
    goto CPyL137;
CPyL162: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL87;
CPyL163: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r124);
    goto CPyL137;
CPyL164: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r133);
    goto CPyL137;
CPyL165: ;
    CPy_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r143);
    goto CPyL137;
CPyL166: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r153);
    goto CPyL137;
CPyL167: ;
    CPy_DecRef(cpy_r_r156);
    goto CPyL137;
CPyL168: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r166);
    goto CPyL137;
CPyL169: ;
    CPy_DecRef(cpy_r_r169);
    goto CPyL137;
CPyL170: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL2;
CPyL171: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL135;
}

PyObject *CPyPy__nonce____get_area_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", "arg", 0};
    static CPyArg_Parser parser = {"OOOO:__mypyc_generator_helper__", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value;
    PyObject *obj_traceback;
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_type = obj_type;
    PyObject *arg_value = obj_value;
    PyObject *arg_traceback = obj_traceback;
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__nonce____get_area_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce____get_area_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__nonce____get_area_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__nonce____get_area_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce____get_area_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce._get_area_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce____get_area_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__next__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce____get_area_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__nonce____get_area_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__nonce____get_area_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce____get_area_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce._get_area_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__nonce____get_area_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "send", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce____get_area_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__nonce____get_area_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce____get_area_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce._get_area_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce____get_area_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__iter__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce____get_area_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef__nonce____get_area_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy__nonce____get_area_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce____get_area_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce._get_area_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef__nonce____get_area_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "throw", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce____get_area_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[10]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef__nonce____get_area_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[11]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp28 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp28);
    PyObject *__tmp29 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp29);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy__nonce____get_area_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce____get_area_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce._get_area_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce____get_area_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "close", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce____get_area_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__nonce____get_area_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce____get_area_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce._get_area_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce____get_area_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__await__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce____get_area(PyObject *cpy_r_address, CPyTagged cpy_r_nonce, PyObject *cpy_r_lo, PyObject *cpy_r_hi, CPyTagged cpy_r_range_size) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    cpy_r_r0 = CPyDef__nonce____get_area_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_address);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_address != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_address);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_address = cpy_r_address;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL11;
    }
    CPyTagged_INCREF(cpy_r_nonce);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_nonce != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_nonce);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_nonce = cpy_r_nonce;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL11;
    }
    CPy_INCREF(cpy_r_lo);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_lo != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_lo);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_lo = cpy_r_lo;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL11;
    }
    CPy_INCREF(cpy_r_hi);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_hi != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_hi);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_hi = cpy_r_hi;
    cpy_r_r4 = 1;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL11;
    }
    CPyTagged_INCREF(cpy_r_range_size);
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_range_size != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_range_size);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->_range_size = cpy_r_range_size;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL11;
    }
    cpy_r_r6 = CPyDef__nonce____get_area_gen();
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL11;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
    if (((eth_portfolio____loaders____nonce____get_area_genObject *)cpy_r_r6)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce____get_area_genObject *)cpy_r_r6)->___mypyc_env__);
    }
    ((eth_portfolio____loaders____nonce____get_area_genObject *)cpy_r_r6)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL12;
    }
    if (((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce____get_area_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r8 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
        goto CPyL13;
    }
    return cpy_r_r6;
CPyL10: ;
    cpy_r_r9 = NULL;
    return cpy_r_r9;
CPyL11: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL10;
CPyL12: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r6);
    goto CPyL10;
CPyL13: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL10;
}

PyObject *CPyPy__nonce____get_area(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"address", "nonce", "lo", "hi", "range_size", 0};
    static CPyArg_Parser parser = {"OOOOO:_get_area", kwlist, 0};
    PyObject *obj_address;
    PyObject *obj_nonce;
    PyObject *obj_lo;
    PyObject *obj_hi;
    PyObject *obj_range_size;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_address, &obj_nonce, &obj_lo, &obj_hi, &obj_range_size)) {
        return NULL;
    }
    PyObject *arg_address = obj_address;
    CPyTagged arg_nonce;
    if (likely(PyLong_Check(obj_nonce)))
        arg_nonce = CPyTagged_BorrowFromObject(obj_nonce);
    else {
        CPy_TypeError("int", obj_nonce); goto fail;
    }
    PyObject *arg_lo = obj_lo;
    PyObject *arg_hi = obj_hi;
    CPyTagged arg_range_size;
    if (likely(PyLong_Check(obj_range_size)))
        arg_range_size = CPyTagged_BorrowFromObject(obj_range_size);
    else {
        CPy_TypeError("int", obj_range_size); goto fail;
    }
    PyObject *retval = CPyDef__nonce____get_area(arg_address, arg_nonce, arg_lo, arg_hi, arg_range_size);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_area", 130, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce____update_nonces(PyObject *cpy_r_address, CPyTagged cpy_r_nonce, PyObject *cpy_r_block) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    int32_t cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    cpy_r_r0 = CPyStatic__nonce___nonces;
    if (likely(cpy_r_r0 != NULL)) goto CPyL3;
    PyErr_SetString(PyExc_NameError, "value for final name \"nonces\" was not set");
    cpy_r_r1 = 0;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 150, CPyStatic__nonce___globals);
        goto CPyL16;
    }
    CPy_Unreachable();
CPyL3: ;
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_address);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 150, CPyStatic__nonce___globals);
        goto CPyL16;
    }
    if (likely(PyDict_Check(cpy_r_r2)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 150, CPyStatic__nonce___globals, "dict", cpy_r_r2);
        goto CPyL16;
    }
    CPyTagged_INCREF(cpy_r_nonce);
    cpy_r_r4 = CPyTagged_StealAsObject(cpy_r_nonce);
    cpy_r_r5 = CPyDict_GetItem(cpy_r_r3, cpy_r_r4);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 150, CPyStatic__nonce___globals);
        goto CPyL16;
    }
    cpy_r_r6 = PyObject_RichCompare(cpy_r_block, cpy_r_r5, 4);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 150, CPyStatic__nonce___globals);
        goto CPyL16;
    }
    if (unlikely(!PyBool_Check(cpy_r_r6))) {
        CPy_TypeError("bool", cpy_r_r6); cpy_r_r7 = 2;
    } else
        cpy_r_r7 = cpy_r_r6 == Py_True;
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 150, CPyStatic__nonce___globals);
        goto CPyL16;
    }
    if (!cpy_r_r7) goto CPyL15;
    cpy_r_r8 = CPyStatic__nonce___nonces;
    if (likely(cpy_r_r8 != NULL)) goto CPyL12;
    PyErr_SetString(PyExc_NameError, "value for final name \"nonces\" was not set");
    cpy_r_r9 = 0;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 151, CPyStatic__nonce___globals);
        goto CPyL16;
    }
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r10 = CPyDict_GetItem(cpy_r_r8, cpy_r_address);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 151, CPyStatic__nonce___globals);
        goto CPyL16;
    }
    if (likely(PyDict_Check(cpy_r_r10)))
        cpy_r_r11 = cpy_r_r10;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 151, CPyStatic__nonce___globals, "dict", cpy_r_r10);
        goto CPyL16;
    }
    CPyTagged_INCREF(cpy_r_nonce);
    cpy_r_r12 = CPyTagged_StealAsObject(cpy_r_nonce);
    cpy_r_r13 = CPyDict_SetItem(cpy_r_r11, cpy_r_r12, cpy_r_block);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r14 = cpy_r_r13 >= 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 151, CPyStatic__nonce___globals);
        goto CPyL16;
    }
CPyL15: ;
    cpy_r_r15 = Py_None;
    return cpy_r_r15;
CPyL16: ;
    cpy_r_r16 = NULL;
    return cpy_r_r16;
}

PyObject *CPyPy__nonce____update_nonces(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"address", "nonce", "block", 0};
    static CPyArg_Parser parser = {"OOO:_update_nonces", kwlist, 0};
    PyObject *obj_address;
    PyObject *obj_nonce;
    PyObject *obj_block;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_address, &obj_nonce, &obj_block)) {
        return NULL;
    }
    PyObject *arg_address = obj_address;
    CPyTagged arg_nonce;
    if (likely(PyLong_Check(obj_nonce)))
        arg_nonce = CPyTagged_BorrowFromObject(obj_nonce);
    else {
        CPy_TypeError("int", obj_nonce); goto fail;
    }
    PyObject *arg_block = obj_block;
    PyObject *retval = CPyDef__nonce____update_nonces(arg_address, arg_nonce, arg_block);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_update_nonces", 148, CPyStatic__nonce___globals);
    return NULL;
}

CPyTagged CPyDef__nonce____get_num_chunks(CPyTagged cpy_r_range_size) {
    int64_t cpy_r_r0;
    char cpy_r_r1;
    int64_t cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    int64_t cpy_r_r7;
    char cpy_r_r8;
    int64_t cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    char cpy_r_r13;
    int64_t cpy_r_r14;
    char cpy_r_r15;
    int64_t cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    int64_t cpy_r_r21;
    char cpy_r_r22;
    int64_t cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    int64_t cpy_r_r28;
    char cpy_r_r29;
    int64_t cpy_r_r30;
    char cpy_r_r31;
    char cpy_r_r32;
    char cpy_r_r33;
    char cpy_r_r34;
    int64_t cpy_r_r35;
    char cpy_r_r36;
    int64_t cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    char cpy_r_r40;
    char cpy_r_r41;
    int64_t cpy_r_r42;
    char cpy_r_r43;
    int64_t cpy_r_r44;
    char cpy_r_r45;
    char cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    int64_t cpy_r_r49;
    char cpy_r_r50;
    int64_t cpy_r_r51;
    char cpy_r_r52;
    char cpy_r_r53;
    char cpy_r_r54;
    char cpy_r_r55;
    int64_t cpy_r_r56;
    char cpy_r_r57;
    int64_t cpy_r_r58;
    char cpy_r_r59;
    char cpy_r_r60;
    char cpy_r_r61;
    char cpy_r_r62;
    int64_t cpy_r_r63;
    char cpy_r_r64;
    int64_t cpy_r_r65;
    char cpy_r_r66;
    char cpy_r_r67;
    char cpy_r_r68;
    char cpy_r_r69;
    cpy_r_r0 = cpy_r_range_size & 1;
    cpy_r_r1 = cpy_r_r0 != 0;
    if (cpy_r_r1) goto CPyL2;
    cpy_r_r2 = 8192 & 1;
    cpy_r_r3 = cpy_r_r2 != 0;
    if (!cpy_r_r3) goto CPyL3;
CPyL2: ;
    cpy_r_r4 = CPyTagged_IsLt_(cpy_r_range_size, 8192);
    cpy_r_r5 = cpy_r_r4 ^ 1;
    if (cpy_r_r5) {
        goto CPyL4;
    } else
        goto CPyL5;
CPyL3: ;
    cpy_r_r6 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)8192;
    if (!cpy_r_r6) goto CPyL5;
CPyL4: ;
    return 200;
CPyL5: ;
    cpy_r_r7 = cpy_r_range_size & 1;
    cpy_r_r8 = cpy_r_r7 != 0;
    if (cpy_r_r8) goto CPyL7;
    cpy_r_r9 = 4096 & 1;
    cpy_r_r10 = cpy_r_r9 != 0;
    if (!cpy_r_r10) goto CPyL8;
CPyL7: ;
    cpy_r_r11 = CPyTagged_IsLt_(cpy_r_range_size, 4096);
    cpy_r_r12 = cpy_r_r11 ^ 1;
    if (cpy_r_r12) {
        goto CPyL9;
    } else
        goto CPyL10;
CPyL8: ;
    cpy_r_r13 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)4096;
    if (!cpy_r_r13) goto CPyL10;
CPyL9: ;
    return 160;
CPyL10: ;
    cpy_r_r14 = cpy_r_range_size & 1;
    cpy_r_r15 = cpy_r_r14 != 0;
    if (cpy_r_r15) goto CPyL12;
    cpy_r_r16 = 2048 & 1;
    cpy_r_r17 = cpy_r_r16 != 0;
    if (!cpy_r_r17) goto CPyL13;
CPyL12: ;
    cpy_r_r18 = CPyTagged_IsLt_(cpy_r_range_size, 2048);
    cpy_r_r19 = cpy_r_r18 ^ 1;
    if (cpy_r_r19) {
        goto CPyL14;
    } else
        goto CPyL15;
CPyL13: ;
    cpy_r_r20 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)2048;
    if (!cpy_r_r20) goto CPyL15;
CPyL14: ;
    return 80;
CPyL15: ;
    cpy_r_r21 = cpy_r_range_size & 1;
    cpy_r_r22 = cpy_r_r21 != 0;
    if (cpy_r_r22) goto CPyL17;
    cpy_r_r23 = 1024 & 1;
    cpy_r_r24 = cpy_r_r23 != 0;
    if (!cpy_r_r24) goto CPyL18;
CPyL17: ;
    cpy_r_r25 = CPyTagged_IsLt_(cpy_r_range_size, 1024);
    cpy_r_r26 = cpy_r_r25 ^ 1;
    if (cpy_r_r26) {
        goto CPyL19;
    } else
        goto CPyL20;
CPyL18: ;
    cpy_r_r27 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)1024;
    if (!cpy_r_r27) goto CPyL20;
CPyL19: ;
    return 40;
CPyL20: ;
    cpy_r_r28 = cpy_r_range_size & 1;
    cpy_r_r29 = cpy_r_r28 != 0;
    if (cpy_r_r29) goto CPyL22;
    cpy_r_r30 = 512 & 1;
    cpy_r_r31 = cpy_r_r30 != 0;
    if (!cpy_r_r31) goto CPyL23;
CPyL22: ;
    cpy_r_r32 = CPyTagged_IsLt_(cpy_r_range_size, 512);
    cpy_r_r33 = cpy_r_r32 ^ 1;
    if (cpy_r_r33) {
        goto CPyL24;
    } else
        goto CPyL25;
CPyL23: ;
    cpy_r_r34 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)512;
    if (!cpy_r_r34) goto CPyL25;
CPyL24: ;
    return 20;
CPyL25: ;
    cpy_r_r35 = cpy_r_range_size & 1;
    cpy_r_r36 = cpy_r_r35 != 0;
    if (cpy_r_r36) goto CPyL27;
    cpy_r_r37 = 256 & 1;
    cpy_r_r38 = cpy_r_r37 != 0;
    if (!cpy_r_r38) goto CPyL28;
CPyL27: ;
    cpy_r_r39 = CPyTagged_IsLt_(cpy_r_range_size, 256);
    cpy_r_r40 = cpy_r_r39 ^ 1;
    if (cpy_r_r40) {
        goto CPyL29;
    } else
        goto CPyL30;
CPyL28: ;
    cpy_r_r41 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)256;
    if (!cpy_r_r41) goto CPyL30;
CPyL29: ;
    return 16;
CPyL30: ;
    cpy_r_r42 = cpy_r_range_size & 1;
    cpy_r_r43 = cpy_r_r42 != 0;
    if (cpy_r_r43) goto CPyL32;
    cpy_r_r44 = 128 & 1;
    cpy_r_r45 = cpy_r_r44 != 0;
    if (!cpy_r_r45) goto CPyL33;
CPyL32: ;
    cpy_r_r46 = CPyTagged_IsLt_(cpy_r_range_size, 128);
    cpy_r_r47 = cpy_r_r46 ^ 1;
    if (cpy_r_r47) {
        goto CPyL34;
    } else
        goto CPyL35;
CPyL33: ;
    cpy_r_r48 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)128;
    if (!cpy_r_r48) goto CPyL35;
CPyL34: ;
    return 12;
CPyL35: ;
    cpy_r_r49 = cpy_r_range_size & 1;
    cpy_r_r50 = cpy_r_r49 != 0;
    if (cpy_r_r50) goto CPyL37;
    cpy_r_r51 = 64 & 1;
    cpy_r_r52 = cpy_r_r51 != 0;
    if (!cpy_r_r52) goto CPyL38;
CPyL37: ;
    cpy_r_r53 = CPyTagged_IsLt_(cpy_r_range_size, 64);
    cpy_r_r54 = cpy_r_r53 ^ 1;
    if (cpy_r_r54) {
        goto CPyL39;
    } else
        goto CPyL40;
CPyL38: ;
    cpy_r_r55 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)64;
    if (!cpy_r_r55) goto CPyL40;
CPyL39: ;
    return 10;
CPyL40: ;
    cpy_r_r56 = cpy_r_range_size & 1;
    cpy_r_r57 = cpy_r_r56 != 0;
    if (cpy_r_r57) goto CPyL42;
    cpy_r_r58 = 32 & 1;
    cpy_r_r59 = cpy_r_r58 != 0;
    if (!cpy_r_r59) goto CPyL43;
CPyL42: ;
    cpy_r_r60 = CPyTagged_IsLt_(cpy_r_range_size, 32);
    cpy_r_r61 = cpy_r_r60 ^ 1;
    if (cpy_r_r61) {
        goto CPyL44;
    } else
        goto CPyL45;
CPyL43: ;
    cpy_r_r62 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)32;
    if (!cpy_r_r62) goto CPyL45;
CPyL44: ;
    return 8;
CPyL45: ;
    cpy_r_r63 = cpy_r_range_size & 1;
    cpy_r_r64 = cpy_r_r63 != 0;
    if (cpy_r_r64) goto CPyL47;
    cpy_r_r65 = 16 & 1;
    cpy_r_r66 = cpy_r_r65 != 0;
    if (!cpy_r_r66) goto CPyL48;
CPyL47: ;
    cpy_r_r67 = CPyTagged_IsLt_(cpy_r_range_size, 16);
    cpy_r_r68 = cpy_r_r67 ^ 1;
    if (cpy_r_r68) {
        goto CPyL49;
    } else
        goto CPyL50;
CPyL48: ;
    cpy_r_r69 = (Py_ssize_t)cpy_r_range_size >= (Py_ssize_t)16;
    if (!cpy_r_r69) goto CPyL50;
CPyL49: ;
    return 6;
CPyL50: ;
    return 4;
}

PyObject *CPyPy__nonce____get_num_chunks(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"range_size", 0};
    static CPyArg_Parser parser = {"O:_get_num_chunks", kwlist, 0};
    PyObject *obj_range_size;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_range_size)) {
        return NULL;
    }
    CPyTagged arg_range_size;
    if (likely(PyLong_Check(obj_range_size)))
        arg_range_size = CPyTagged_BorrowFromObject(obj_range_size);
    else {
        CPy_TypeError("int", obj_range_size); goto fail;
    }
    CPyTagged retval = CPyDef__nonce____get_num_chunks(arg_range_size);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "_get_num_chunks", 154, CPyStatic__nonce___globals);
    return NULL;
}

char CPyDef__nonce___BlockCache_____mypyc_defaults_setup(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    cpy_r_r0 = CPyModule_asyncio;
    cpy_r_r1 = CPyStatics[17]; /* 'Lock' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = PyObject_Vectorcall(cpy_r_r2, 0, 0, 0);
    CPy_DECREF(cpy_r_r2);
    if (cpy_r_r3 == NULL) goto CPyL3;
    ((eth_portfolio____loaders____nonce___BlockCacheObject *)cpy_r___mypyc_self__)->_lock = cpy_r_r3;
    ((eth_portfolio____loaders____nonce___BlockCacheObject *)cpy_r___mypyc_self__)->_ttl = 5.0;
    return 1;
CPyL3: ;
    cpy_r_r4 = 2;
    return cpy_r_r4;
}

PyObject *CPyPy__nonce___BlockCache_____mypyc_defaults_setup(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__mypyc_defaults_setup", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___BlockCache))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.BlockCache", obj___mypyc_self__); 
        goto fail;
    }
    char retval = CPyDef__nonce___BlockCache_____mypyc_defaults_setup(arg___mypyc_self__);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__mypyc_defaults_setup", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_number_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    tuple_T3OOO cpy_r_r8;
    tuple_T3OOO cpy_r_r9;
    PyObject *cpy_r_r10;
    CPyTagged cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    double cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    int32_t cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject **cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    tuple_T3OOO cpy_r_r57;
    char cpy_r_r58;
    PyObject **cpy_r_r59;
    PyObject *cpy_r_r60;
    char cpy_r_r61;
    tuple_T3OOO cpy_r_r62;
    tuple_T3OOO cpy_r_r63;
    tuple_T3OOO cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    char cpy_r_r70;
    PyObject *cpy_r_r71;
    double cpy_r_r72;
    char cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    int32_t cpy_r_r82;
    char cpy_r_r83;
    char cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    char cpy_r_r88;
    PyObject *cpy_r_r89;
    char cpy_r_r90;
    PyObject *cpy_r_r91;
    double cpy_r_r92;
    char cpy_r_r93;
    char cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    char cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    char cpy_r_r108;
    PyObject *cpy_r_r109;
    char cpy_r_r110;
    tuple_T3OOO cpy_r_r111;
    char cpy_r_r112;
    PyObject **cpy_r_r113;
    PyObject *cpy_r_r114;
    char cpy_r_r115;
    tuple_T3OOO cpy_r_r116;
    tuple_T3OOO cpy_r_r117;
    tuple_T3OOO cpy_r_r118;
    char cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    char cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    int32_t cpy_r_r126;
    char cpy_r_r127;
    double cpy_r_r128;
    char cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    int32_t cpy_r_r133;
    char cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    char cpy_r_r137;
    tuple_T3OOO cpy_r_r138;
    char cpy_r_r139;
    char cpy_r_r140;
    tuple_T3OOO cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject **cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    char cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    char cpy_r_r157;
    PyObject *cpy_r_r158;
    char cpy_r_r159;
    tuple_T3OOO cpy_r_r160;
    char cpy_r_r161;
    PyObject **cpy_r_r162;
    PyObject *cpy_r_r163;
    char cpy_r_r164;
    tuple_T3OOO cpy_r_r165;
    tuple_T3OOO cpy_r_r166;
    tuple_T3OOO cpy_r_r167;
    char cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    int32_t cpy_r_r172;
    char cpy_r_r173;
    char cpy_r_r174;
    tuple_T3OOO cpy_r_r175;
    tuple_T3OOO cpy_r_r176;
    char cpy_r_r177;
    PyObject *cpy_r_r178;
    char cpy_r_r179;
    tuple_T3OOO cpy_r_r180;
    PyObject *cpy_r_r181;
    char cpy_r_r182;
    tuple_T3OOO cpy_r_r183;
    char cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject **cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    char cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    char cpy_r_r198;
    PyObject *cpy_r_r199;
    char cpy_r_r200;
    tuple_T3OOO cpy_r_r201;
    char cpy_r_r202;
    PyObject **cpy_r_r203;
    PyObject *cpy_r_r204;
    char cpy_r_r205;
    tuple_T3OOO cpy_r_r206;
    tuple_T3OOO cpy_r_r207;
    tuple_T3OOO cpy_r_r208;
    char cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    char cpy_r_r215;
    char cpy_r_r216;
    PyObject *cpy_r_r217;
    char cpy_r_r218;
    char cpy_r_r219;
    char cpy_r_r220;
    char cpy_r_r221;
    char cpy_r_r222;
    char cpy_r_r223;
    char cpy_r_r224;
    PyObject *cpy_r_r225;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = NULL;
    cpy_r_r3 = cpy_r_r2;
    cpy_r_r4 = NULL;
    cpy_r_r5 = cpy_r_r4;
    cpy_r_r6 = NULL;
    cpy_r_r7 = cpy_r_r6;
    tuple_T3OOO __tmp30 = { NULL, NULL, NULL };
    cpy_r_r8 = __tmp30;
    cpy_r_r9 = cpy_r_r8;
    cpy_r_r10 = ((eth_portfolio____loaders____nonce___get_block_number_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_gen", "__mypyc_env__", 187, CPyStatic__nonce___globals);
        goto CPyL221;
    }
    CPy_INCREF_NO_IMM(cpy_r_r10);
CPyL1: ;
    cpy_r_r11 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__;
    if (unlikely(cpy_r_r11 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_next_label__", 187, CPyStatic__nonce___globals);
        goto CPyL222;
    }
    CPyTagged_INCREF(cpy_r_r11);
    goto CPyL213;
CPyL2: ;
    cpy_r_r12 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r13 = cpy_r_type != cpy_r_r12;
    if (cpy_r_r13) {
        goto CPyL223;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 187, CPyStatic__nonce___globals);
        goto CPyL220;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r14 = CPyStatic__nonce___now;
    if (unlikely(cpy_r_r14 == NULL)) {
        goto CPyL224;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"now\" was not set");
    cpy_r_r15 = 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 188, CPyStatic__nonce___globals);
        goto CPyL220;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r16 = PyObject_Vectorcall(cpy_r_r14, 0, 0, 0);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 188, CPyStatic__nonce___globals);
        goto CPyL225;
    }
    cpy_r_r17 = PyFloat_AsDouble(cpy_r_r16);
    if (cpy_r_r17 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r16); cpy_r_r17 = -113.0;
    }
    CPy_DECREF(cpy_r_r16);
    cpy_r_r18 = cpy_r_r17 == -113.0;
    if (unlikely(cpy_r_r18)) goto CPyL11;
CPyL10: ;
    cpy_r_r19 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r20 = CPyStatics[18]; /* 'updated_at' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 188, CPyStatic__nonce___globals);
        goto CPyL225;
    } else
        goto CPyL12;
CPyL11: ;
    cpy_r_r22 = PyErr_Occurred();
    if (unlikely(cpy_r_r22 != NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 188, CPyStatic__nonce___globals);
        goto CPyL225;
    } else
        goto CPyL10;
CPyL12: ;
    cpy_r_r23 = PyFloat_FromDouble(cpy_r_r17);
    cpy_r_r24 = PyNumber_Subtract(cpy_r_r23, cpy_r_r21);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 188, CPyStatic__nonce___globals);
        goto CPyL225;
    }
    cpy_r_r25 = PyFloat_FromDouble(5.0);
    cpy_r_r26 = PyObject_RichCompare(cpy_r_r24, cpy_r_r25, 0);
    CPy_DECREF(cpy_r_r24);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 188, CPyStatic__nonce___globals);
        goto CPyL225;
    }
    cpy_r_r27 = PyObject_IsTrue(cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r28 = cpy_r_r27 >= 0;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 188, CPyStatic__nonce___globals);
        goto CPyL225;
    }
    cpy_r_r29 = cpy_r_r27;
    if (cpy_r_r29) {
        goto CPyL226;
    } else
        goto CPyL20;
CPyL16: ;
    cpy_r_r30 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r31 = CPyStatics[19]; /* 'block' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 189, CPyStatic__nonce___globals);
        goto CPyL227;
    }
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ = -2;
    cpy_r_r33 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r10);
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 189, CPyStatic__nonce___globals);
        goto CPyL228;
    }
    CPyGen_SetStopIterationValue(cpy_r_r32);
    CPy_DECREF(cpy_r_r32);
    if (!0) goto CPyL220;
    CPy_Unreachable();
CPyL20: ;
    cpy_r_r34 = CPyStatic__nonce___BlockCache___lock;
    if (unlikely(cpy_r_r34 == NULL)) {
        goto CPyL229;
    } else
        goto CPyL23;
CPyL21: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"lock\" was not set");
    cpy_r_r35 = 0;
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL220;
    }
    CPy_Unreachable();
CPyL23: ;
    cpy_r_r36 = PyObject_Type(cpy_r_r34);
    cpy_r_r37 = CPyStatics[12]; /* '__aexit__' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL230;
    }
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__36 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__36);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__36 = cpy_r_r38;
    cpy_r_r39 = 1;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL230;
    }
    cpy_r_r40 = CPyStatics[13]; /* '__aenter__' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r40);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL225;
    }
    PyObject *cpy_r_r42[1] = {cpy_r_r34};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = PyObject_Vectorcall(cpy_r_r41, cpy_r_r43, 1, 0);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL225;
    }
    CPy_INCREF(cpy_r_r34);
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__37 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__37);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__37 = cpy_r_r34;
    cpy_r_r45 = 1;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL231;
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__38 = 1;
    cpy_r_r46 = 1;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL231;
    }
    cpy_r_r47 = CPy_GetCoro(cpy_r_r44);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL225;
    }
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__39 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__39);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__39 = cpy_r_r47;
    cpy_r_r48 = 1;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL225;
    }
    cpy_r_r49 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__39;
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__39", -1, CPyStatic__nonce___globals);
        goto CPyL225;
    }
    CPy_INCREF(cpy_r_r49);
CPyL32: ;
    cpy_r_r50 = CPyIter_Next(cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (cpy_r_r50 == NULL) {
        goto CPyL232;
    } else
        goto CPyL35;
CPyL33: ;
    cpy_r_r51 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL233;
    }
    cpy_r_r52 = cpy_r_r51;
    CPy_DECREF(cpy_r_r52);
    goto CPyL58;
CPyL35: ;
    cpy_r_r53 = cpy_r_r50;
CPyL36: ;
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ = 2;
    cpy_r_r54 = 1;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL234;
    } else
        goto CPyL235;
CPyL37: ;
    return cpy_r_r53;
CPyL38: ;
    cpy_r_r55 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r56 = cpy_r_type != cpy_r_r55;
    if (!cpy_r_r56) goto CPyL41;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL42;
    } else
        goto CPyL236;
CPyL40: ;
    CPy_Unreachable();
CPyL41: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL53;
CPyL42: ;
    cpy_r_r57 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__40.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__40.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__40.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__40.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__40 = cpy_r_r57;
    cpy_r_r58 = 1;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL237;
    }
    cpy_r_r59 = (PyObject **)&cpy_r_r1;
    cpy_r_r60 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__39;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__39", -1, CPyStatic__nonce___globals);
        goto CPyL237;
    }
    CPy_INCREF(cpy_r_r60);
CPyL44: ;
    cpy_r_r61 = CPy_YieldFromErrorHandle(cpy_r_r60, cpy_r_r59);
    CPy_DecRef(cpy_r_r60);
    if (unlikely(cpy_r_r61 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL237;
    }
    if (cpy_r_r61) goto CPyL48;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r53 = cpy_r_r1;
    cpy_r_r62 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__40;
    if (unlikely(cpy_r_r62.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__40", -1, CPyStatic__nonce___globals);
        goto CPyL238;
    }
    CPy_INCREF(cpy_r_r62.f0);
    CPy_INCREF(cpy_r_r62.f1);
    CPy_INCREF(cpy_r_r62.f2);
CPyL47: ;
    CPy_RestoreExcInfo(cpy_r_r62);
    CPy_DecRef(cpy_r_r62.f0);
    CPy_DecRef(cpy_r_r62.f1);
    CPy_DecRef(cpy_r_r62.f2);
    goto CPyL36;
CPyL48: ;
    cpy_r_r52 = cpy_r_r1;
    CPy_DecRef(cpy_r_r52);
    cpy_r_r63 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__40;
    if (unlikely(cpy_r_r63.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__40", -1, CPyStatic__nonce___globals);
        goto CPyL239;
    }
    CPy_INCREF(cpy_r_r63.f0);
    CPy_INCREF(cpy_r_r63.f1);
    CPy_INCREF(cpy_r_r63.f2);
CPyL49: ;
    CPy_RestoreExcInfo(cpy_r_r63);
    CPy_DecRef(cpy_r_r63.f0);
    CPy_DecRef(cpy_r_r63.f1);
    CPy_DecRef(cpy_r_r63.f2);
    goto CPyL58;
CPyL50: ;
    cpy_r_r64 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__40;
    if (unlikely(cpy_r_r64.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__40' of 'get_block_number_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r64.f0);
        CPy_INCREF(cpy_r_r64.f1);
        CPy_INCREF(cpy_r_r64.f2);
    }
    CPy_DecRef(cpy_r_r10);
    if (unlikely(cpy_r_r64.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL220;
    }
CPyL51: ;
    CPy_RestoreExcInfo(cpy_r_r64);
    CPy_DecRef(cpy_r_r64.f0);
    CPy_DecRef(cpy_r_r64.f1);
    CPy_DecRef(cpy_r_r64.f2);
    cpy_r_r65 = CPy_KeepPropagating();
    if (!cpy_r_r65) goto CPyL220;
    CPy_Unreachable();
CPyL53: ;
    cpy_r_r66 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__39;
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__39", -1, CPyStatic__nonce___globals);
        goto CPyL240;
    }
    CPy_INCREF(cpy_r_r66);
CPyL54: ;
    cpy_r_r67 = CPyIter_Send(cpy_r_r66, cpy_r_arg);
    CPy_DECREF(cpy_r_r66);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r67 == NULL) goto CPyL241;
    cpy_r_r53 = cpy_r_r67;
    goto CPyL36;
CPyL56: ;
    cpy_r_r68 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL233;
    }
    cpy_r_r52 = cpy_r_r68;
    CPy_DECREF(cpy_r_r52);
CPyL58: ;
    cpy_r_r69 = CPyStatic__nonce___now;
    if (unlikely(cpy_r_r69 == NULL)) {
        goto CPyL242;
    } else
        goto CPyL61;
CPyL59: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"now\" was not set");
    cpy_r_r70 = 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 191, CPyStatic__nonce___globals);
        goto CPyL116;
    } else
        goto CPyL243;
CPyL60: ;
    CPy_Unreachable();
CPyL61: ;
    cpy_r_r71 = PyObject_Vectorcall(cpy_r_r69, 0, 0, 0);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 191, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    cpy_r_r72 = PyFloat_AsDouble(cpy_r_r71);
    if (cpy_r_r72 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r71); cpy_r_r72 = -113.0;
    }
    CPy_DECREF(cpy_r_r71);
    cpy_r_r73 = cpy_r_r72 == -113.0;
    if (unlikely(cpy_r_r73)) goto CPyL64;
CPyL63: ;
    cpy_r_r74 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r75 = CPyStatics[18]; /* 'updated_at' */
    cpy_r_r76 = CPyObject_GetAttr(cpy_r_r74, cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 191, CPyStatic__nonce___globals);
        goto CPyL244;
    } else
        goto CPyL65;
CPyL64: ;
    cpy_r_r77 = PyErr_Occurred();
    if (unlikely(cpy_r_r77 != NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 191, CPyStatic__nonce___globals);
        goto CPyL244;
    } else
        goto CPyL63;
CPyL65: ;
    cpy_r_r78 = PyFloat_FromDouble(cpy_r_r72);
    cpy_r_r79 = PyNumber_Subtract(cpy_r_r78, cpy_r_r76);
    CPy_DECREF(cpy_r_r78);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 191, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    cpy_r_r80 = PyFloat_FromDouble(5.0);
    cpy_r_r81 = PyObject_RichCompare(cpy_r_r79, cpy_r_r80, 0);
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 191, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    cpy_r_r82 = PyObject_IsTrue(cpy_r_r81);
    CPy_DECREF(cpy_r_r81);
    cpy_r_r83 = cpy_r_r82 >= 0;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 191, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    cpy_r_r84 = cpy_r_r82;
    if (cpy_r_r84) {
        goto CPyL245;
    } else
        goto CPyL71;
CPyL69: ;
    cpy_r_r85 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r86 = CPyStatics[19]; /* 'block' */
    cpy_r_r87 = CPyObject_GetAttr(cpy_r_r85, cpy_r_r86);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 192, CPyStatic__nonce___globals);
        goto CPyL116;
    }
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41 = cpy_r_r87;
    cpy_r_r88 = 1;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 192, CPyStatic__nonce___globals);
        goto CPyL116;
    } else
        goto CPyL246;
CPyL71: ;
    cpy_r_r89 = CPyStatic__nonce___now;
    if (unlikely(cpy_r_r89 == NULL)) {
        goto CPyL247;
    } else
        goto CPyL74;
CPyL72: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"now\" was not set");
    cpy_r_r90 = 0;
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 193, CPyStatic__nonce___globals);
        goto CPyL116;
    } else
        goto CPyL248;
CPyL73: ;
    CPy_Unreachable();
CPyL74: ;
    cpy_r_r91 = PyObject_Vectorcall(cpy_r_r89, 0, 0, 0);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 193, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    cpy_r_r92 = PyFloat_AsDouble(cpy_r_r91);
    if (cpy_r_r92 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r91); cpy_r_r92 = -113.0;
    }
    CPy_DECREF(cpy_r_r91);
    cpy_r_r93 = cpy_r_r92 == -113.0;
    if (unlikely(cpy_r_r93)) goto CPyL77;
CPyL76: ;
    if (unlikely(cpy_r_r92 == -113.0)) {
        ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->bitmap |= 1;
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->_ts = cpy_r_r92;
    cpy_r_r94 = 1;
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 193, CPyStatic__nonce___globals);
        goto CPyL244;
    } else
        goto CPyL78;
CPyL77: ;
    cpy_r_r95 = PyErr_Occurred();
    if (unlikely(cpy_r_r95 != NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 193, CPyStatic__nonce___globals);
        goto CPyL244;
    } else
        goto CPyL76;
CPyL78: ;
    cpy_r_r96 = CPyModule_dank_mids;
    cpy_r_r97 = CPyStatics[20]; /* 'eth' */
    cpy_r_r98 = CPyObject_GetAttr(cpy_r_r96, cpy_r_r97);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    cpy_r_r99 = CPyStatics[21]; /* 'block_number' */
    cpy_r_r100 = CPyObject_GetAttr(cpy_r_r98, cpy_r_r99);
    CPy_DECREF(cpy_r_r98);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    cpy_r_r101 = CPy_GetCoro(cpy_r_r100);
    CPy_DECREF(cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__42 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__42);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__42 = cpy_r_r101;
    cpy_r_r102 = 1;
    if (unlikely(!cpy_r_r102)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    cpy_r_r103 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__42;
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__42", -1, CPyStatic__nonce___globals);
        goto CPyL244;
    }
    CPy_INCREF(cpy_r_r103);
CPyL83: ;
    cpy_r_r104 = CPyIter_Next(cpy_r_r103);
    CPy_DECREF(cpy_r_r103);
    if (cpy_r_r104 == NULL) {
        goto CPyL249;
    } else
        goto CPyL86;
CPyL84: ;
    cpy_r_r105 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL116;
    }
    cpy_r_r106 = cpy_r_r105;
    goto CPyL109;
CPyL86: ;
    cpy_r_r107 = cpy_r_r104;
CPyL87: ;
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ = 4;
    cpy_r_r108 = 1;
    if (unlikely(!cpy_r_r108)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL250;
    } else
        goto CPyL251;
CPyL88: ;
    return cpy_r_r107;
CPyL89: ;
    cpy_r_r109 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r110 = cpy_r_type != cpy_r_r109;
    if (!cpy_r_r110) goto CPyL92;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL93;
    } else
        goto CPyL252;
CPyL91: ;
    CPy_Unreachable();
CPyL92: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL104;
CPyL93: ;
    cpy_r_r111 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__43.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__43.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__43.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__43.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__43 = cpy_r_r111;
    cpy_r_r112 = 1;
    if (unlikely(!cpy_r_r112)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL253;
    }
    cpy_r_r113 = (PyObject **)&cpy_r_r3;
    cpy_r_r114 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__42;
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__42", -1, CPyStatic__nonce___globals);
        goto CPyL253;
    }
    CPy_INCREF(cpy_r_r114);
CPyL95: ;
    cpy_r_r115 = CPy_YieldFromErrorHandle(cpy_r_r114, cpy_r_r113);
    CPy_DecRef(cpy_r_r114);
    if (unlikely(cpy_r_r115 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL253;
    }
    if (cpy_r_r115) goto CPyL99;
    CPy_INCREF(cpy_r_r3);
    cpy_r_r107 = cpy_r_r3;
    cpy_r_r116 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__43;
    if (unlikely(cpy_r_r116.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__43", -1, CPyStatic__nonce___globals);
        goto CPyL254;
    }
    CPy_INCREF(cpy_r_r116.f0);
    CPy_INCREF(cpy_r_r116.f1);
    CPy_INCREF(cpy_r_r116.f2);
CPyL98: ;
    CPy_RestoreExcInfo(cpy_r_r116);
    CPy_DecRef(cpy_r_r116.f0);
    CPy_DecRef(cpy_r_r116.f1);
    CPy_DecRef(cpy_r_r116.f2);
    goto CPyL87;
CPyL99: ;
    cpy_r_r106 = cpy_r_r3;
    cpy_r_r117 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__43;
    if (unlikely(cpy_r_r117.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__43", -1, CPyStatic__nonce___globals);
        goto CPyL255;
    }
    CPy_INCREF(cpy_r_r117.f0);
    CPy_INCREF(cpy_r_r117.f1);
    CPy_INCREF(cpy_r_r117.f2);
CPyL100: ;
    CPy_RestoreExcInfo(cpy_r_r117);
    CPy_DecRef(cpy_r_r117.f0);
    CPy_DecRef(cpy_r_r117.f1);
    CPy_DecRef(cpy_r_r117.f2);
    goto CPyL109;
CPyL101: ;
    cpy_r_r118 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__43;
    if (unlikely(cpy_r_r118.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__43", -1, CPyStatic__nonce___globals);
        goto CPyL116;
    }
    CPy_INCREF(cpy_r_r118.f0);
    CPy_INCREF(cpy_r_r118.f1);
    CPy_INCREF(cpy_r_r118.f2);
CPyL102: ;
    CPy_RestoreExcInfo(cpy_r_r118);
    CPy_DecRef(cpy_r_r118.f0);
    CPy_DecRef(cpy_r_r118.f1);
    CPy_DecRef(cpy_r_r118.f2);
    cpy_r_r119 = CPy_KeepPropagating();
    if (!cpy_r_r119) {
        goto CPyL116;
    } else
        goto CPyL256;
CPyL103: ;
    CPy_Unreachable();
CPyL104: ;
    cpy_r_r120 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__42;
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__42", -1, CPyStatic__nonce___globals);
        goto CPyL257;
    }
    CPy_INCREF(cpy_r_r120);
CPyL105: ;
    cpy_r_r121 = CPyIter_Send(cpy_r_r120, cpy_r_arg);
    CPy_DECREF(cpy_r_r120);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r121 == NULL) goto CPyL258;
    cpy_r_r107 = cpy_r_r121;
    goto CPyL87;
CPyL107: ;
    cpy_r_r122 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL116;
    }
    cpy_r_r106 = cpy_r_r122;
CPyL109: ;
    CPy_INCREF(cpy_r_r106);
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->_block != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->_block);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->_block = cpy_r_r106;
    cpy_r_r123 = 1;
    if (unlikely(!cpy_r_r123)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL259;
    }
    cpy_r_r124 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r125 = CPyStatics[19]; /* 'block' */
    cpy_r_r126 = PyObject_SetAttr(cpy_r_r124, cpy_r_r125, cpy_r_r106);
    CPy_DECREF(cpy_r_r106);
    cpy_r_r127 = cpy_r_r126 >= 0;
    if (unlikely(!cpy_r_r127)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 194, CPyStatic__nonce___globals);
        goto CPyL116;
    }
    cpy_r_r128 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->_ts;
    if (unlikely(cpy_r_r128 == -113.0) && !(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'ts' of 'get_block_number_env' undefined");
    }
    cpy_r_r129 = cpy_r_r128 == -113.0;
    if (unlikely(cpy_r_r129)) goto CPyL113;
CPyL112: ;
    cpy_r_r130 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r131 = CPyStatics[18]; /* 'updated_at' */
    cpy_r_r132 = PyFloat_FromDouble(cpy_r_r128);
    cpy_r_r133 = PyObject_SetAttr(cpy_r_r130, cpy_r_r131, cpy_r_r132);
    CPy_DECREF(cpy_r_r132);
    cpy_r_r134 = cpy_r_r133 >= 0;
    if (unlikely(!cpy_r_r134)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 195, CPyStatic__nonce___globals);
        goto CPyL116;
    } else
        goto CPyL114;
CPyL113: ;
    cpy_r_r135 = PyErr_Occurred();
    if (unlikely(cpy_r_r135 != NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 195, CPyStatic__nonce___globals);
        goto CPyL116;
    } else
        goto CPyL112;
CPyL114: ;
    cpy_r_r136 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->_block;
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "block", 196, CPyStatic__nonce___globals);
        goto CPyL116;
    }
    CPy_INCREF(cpy_r_r136);
CPyL115: ;
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41 = cpy_r_r136;
    cpy_r_r137 = 1;
    if (unlikely(!cpy_r_r137)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 196, CPyStatic__nonce___globals);
    } else
        goto CPyL260;
CPyL116: ;
    cpy_r_r138 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__44.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__44.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__44.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__44.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__44 = cpy_r_r138;
    cpy_r_r139 = 1;
    if (unlikely(!cpy_r_r139)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL261;
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__38 = 0;
    cpy_r_r140 = 1;
    if (unlikely(!cpy_r_r140)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL261;
    }
    cpy_r_r141 = CPy_GetExcInfo();
    cpy_r_r142 = cpy_r_r141.f0;
    CPy_INCREF(cpy_r_r142);
    cpy_r_r143 = cpy_r_r141.f1;
    CPy_INCREF(cpy_r_r143);
    cpy_r_r144 = cpy_r_r141.f2;
    CPy_INCREF(cpy_r_r144);
    CPy_DecRef(cpy_r_r141.f0);
    CPy_DecRef(cpy_r_r141.f1);
    CPy_DecRef(cpy_r_r141.f2);
    cpy_r_r145 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__36;
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__36", -1, CPyStatic__nonce___globals);
        goto CPyL262;
    }
    CPy_INCREF(cpy_r_r145);
CPyL119: ;
    cpy_r_r146 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__37;
    if (unlikely(cpy_r_r146 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__37", -1, CPyStatic__nonce___globals);
        goto CPyL263;
    }
    CPy_INCREF(cpy_r_r146);
CPyL120: ;
    PyObject *cpy_r_r147[4] = {cpy_r_r146, cpy_r_r142, cpy_r_r143, cpy_r_r144};
    cpy_r_r148 = (PyObject **)&cpy_r_r147;
    cpy_r_r149 = PyObject_Vectorcall(cpy_r_r145, cpy_r_r148, 4, 0);
    CPy_DecRef(cpy_r_r145);
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL264;
    }
    CPy_DecRef(cpy_r_r146);
    CPy_DecRef(cpy_r_r142);
    CPy_DecRef(cpy_r_r143);
    CPy_DecRef(cpy_r_r144);
    cpy_r_r150 = CPy_GetCoro(cpy_r_r149);
    CPy_DecRef(cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL261;
    }
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__45 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__45);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__45 = cpy_r_r150;
    cpy_r_r151 = 1;
    if (unlikely(!cpy_r_r151)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL261;
    }
    cpy_r_r152 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__45;
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__45", -1, CPyStatic__nonce___globals);
        goto CPyL261;
    }
    CPy_INCREF(cpy_r_r152);
CPyL124: ;
    cpy_r_r153 = CPyIter_Next(cpy_r_r152);
    CPy_DecRef(cpy_r_r152);
    if (cpy_r_r153 == NULL) {
        goto CPyL265;
    } else
        goto CPyL127;
CPyL125: ;
    cpy_r_r154 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r154 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL156;
    }
    cpy_r_r155 = cpy_r_r154;
    goto CPyL150;
CPyL127: ;
    cpy_r_r156 = cpy_r_r153;
CPyL128: ;
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ = 6;
    cpy_r_r157 = 1;
    if (unlikely(!cpy_r_r157)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL266;
    } else
        goto CPyL267;
CPyL129: ;
    return cpy_r_r156;
CPyL130: ;
    cpy_r_r158 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r159 = cpy_r_type != cpy_r_r158;
    if (!cpy_r_r159) goto CPyL133;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL134;
    } else
        goto CPyL268;
CPyL132: ;
    CPy_Unreachable();
CPyL133: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL145;
CPyL134: ;
    cpy_r_r160 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__46.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__46.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__46.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__46.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__46 = cpy_r_r160;
    cpy_r_r161 = 1;
    if (unlikely(!cpy_r_r161)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL269;
    }
    cpy_r_r162 = (PyObject **)&cpy_r_r5;
    cpy_r_r163 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__45;
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__45", -1, CPyStatic__nonce___globals);
        goto CPyL269;
    }
    CPy_INCREF(cpy_r_r163);
CPyL136: ;
    cpy_r_r164 = CPy_YieldFromErrorHandle(cpy_r_r163, cpy_r_r162);
    CPy_DecRef(cpy_r_r163);
    if (unlikely(cpy_r_r164 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL269;
    }
    if (cpy_r_r164) goto CPyL140;
    CPy_INCREF(cpy_r_r5);
    cpy_r_r156 = cpy_r_r5;
    cpy_r_r165 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__46;
    if (unlikely(cpy_r_r165.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__46", -1, CPyStatic__nonce___globals);
        goto CPyL270;
    }
    CPy_INCREF(cpy_r_r165.f0);
    CPy_INCREF(cpy_r_r165.f1);
    CPy_INCREF(cpy_r_r165.f2);
CPyL139: ;
    CPy_RestoreExcInfo(cpy_r_r165);
    CPy_DecRef(cpy_r_r165.f0);
    CPy_DecRef(cpy_r_r165.f1);
    CPy_DecRef(cpy_r_r165.f2);
    goto CPyL128;
CPyL140: ;
    cpy_r_r155 = cpy_r_r5;
    cpy_r_r166 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__46;
    if (unlikely(cpy_r_r166.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__46", -1, CPyStatic__nonce___globals);
        goto CPyL271;
    }
    CPy_INCREF(cpy_r_r166.f0);
    CPy_INCREF(cpy_r_r166.f1);
    CPy_INCREF(cpy_r_r166.f2);
CPyL141: ;
    CPy_RestoreExcInfo(cpy_r_r166);
    CPy_DecRef(cpy_r_r166.f0);
    CPy_DecRef(cpy_r_r166.f1);
    CPy_DecRef(cpy_r_r166.f2);
    goto CPyL150;
CPyL142: ;
    cpy_r_r167 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__46;
    if (unlikely(cpy_r_r167.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__46", -1, CPyStatic__nonce___globals);
        goto CPyL156;
    }
    CPy_INCREF(cpy_r_r167.f0);
    CPy_INCREF(cpy_r_r167.f1);
    CPy_INCREF(cpy_r_r167.f2);
CPyL143: ;
    CPy_RestoreExcInfo(cpy_r_r167);
    CPy_DecRef(cpy_r_r167.f0);
    CPy_DecRef(cpy_r_r167.f1);
    CPy_DecRef(cpy_r_r167.f2);
    cpy_r_r168 = CPy_KeepPropagating();
    if (!cpy_r_r168) {
        goto CPyL156;
    } else
        goto CPyL272;
CPyL144: ;
    CPy_Unreachable();
CPyL145: ;
    cpy_r_r169 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__45;
    if (unlikely(cpy_r_r169 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__45", -1, CPyStatic__nonce___globals);
        goto CPyL273;
    }
    CPy_INCREF(cpy_r_r169);
CPyL146: ;
    cpy_r_r170 = CPyIter_Send(cpy_r_r169, cpy_r_arg);
    CPy_DECREF(cpy_r_r169);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r170 == NULL) goto CPyL274;
    cpy_r_r156 = cpy_r_r170;
    goto CPyL128;
CPyL148: ;
    cpy_r_r171 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL156;
    }
    cpy_r_r155 = cpy_r_r171;
CPyL150: ;
    cpy_r_r172 = PyObject_IsTrue(cpy_r_r155);
    CPy_DECREF(cpy_r_r155);
    cpy_r_r173 = cpy_r_r172 >= 0;
    if (unlikely(!cpy_r_r173)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL156;
    }
    cpy_r_r174 = cpy_r_r172;
    if (cpy_r_r174) goto CPyL154;
    CPy_Reraise();
    if (!0) {
        goto CPyL156;
    } else
        goto CPyL275;
CPyL153: ;
    CPy_Unreachable();
CPyL154: ;
    cpy_r_r175 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__44;
    if (unlikely(cpy_r_r175.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__44", -1, CPyStatic__nonce___globals);
        goto CPyL161;
    }
    CPy_INCREF(cpy_r_r175.f0);
    CPy_INCREF(cpy_r_r175.f1);
    CPy_INCREF(cpy_r_r175.f2);
CPyL155: ;
    CPy_RestoreExcInfo(cpy_r_r175);
    CPy_DECREF(cpy_r_r175.f0);
    CPy_DECREF(cpy_r_r175.f1);
    CPy_DECREF(cpy_r_r175.f2);
    goto CPyL159;
CPyL156: ;
    cpy_r_r176 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__44;
    if (unlikely(cpy_r_r176.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__44", -1, CPyStatic__nonce___globals);
        goto CPyL161;
    }
    CPy_INCREF(cpy_r_r176.f0);
    CPy_INCREF(cpy_r_r176.f1);
    CPy_INCREF(cpy_r_r176.f2);
CPyL157: ;
    CPy_RestoreExcInfo(cpy_r_r176);
    CPy_DECREF(cpy_r_r176.f0);
    CPy_DECREF(cpy_r_r176.f1);
    CPy_DECREF(cpy_r_r176.f2);
    cpy_r_r177 = CPy_KeepPropagating();
    if (!cpy_r_r177) {
        goto CPyL161;
    } else
        goto CPyL276;
CPyL158: ;
    CPy_Unreachable();
CPyL159: ;
    cpy_r_r178 = NULL;
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41 = cpy_r_r178;
    cpy_r_r179 = 1;
    if (unlikely(!cpy_r_r179)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL277;
    }
CPyL160: ;
    tuple_T3OOO __tmp31 = { NULL, NULL, NULL };
    cpy_r_r180 = __tmp31;
    cpy_r_r9 = cpy_r_r180;
    goto CPyL163;
CPyL161: ;
    cpy_r_r181 = NULL;
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41 = cpy_r_r181;
    cpy_r_r182 = 1;
    if (unlikely(!cpy_r_r182)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL277;
    }
    cpy_r_r183 = CPy_CatchError();
    cpy_r_r9 = cpy_r_r183;
CPyL163: ;
    cpy_r_r184 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__38;
    if (unlikely(cpy_r_r184 == 2)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__38", -1, CPyStatic__nonce___globals);
        goto CPyL278;
    }
CPyL164: ;
    if (!cpy_r_r184) goto CPyL279;
CPyL165: ;
    cpy_r_r185 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r186 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__36;
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__36", -1, CPyStatic__nonce___globals);
        goto CPyL278;
    }
    CPy_INCREF(cpy_r_r186);
CPyL166: ;
    cpy_r_r187 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__37;
    if (unlikely(cpy_r_r187 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__37", -1, CPyStatic__nonce___globals);
        goto CPyL280;
    }
    CPy_INCREF(cpy_r_r187);
CPyL167: ;
    PyObject *cpy_r_r188[4] = {cpy_r_r187, cpy_r_r185, cpy_r_r185, cpy_r_r185};
    cpy_r_r189 = (PyObject **)&cpy_r_r188;
    cpy_r_r190 = PyObject_Vectorcall(cpy_r_r186, cpy_r_r189, 4, 0);
    CPy_DECREF(cpy_r_r186);
    if (unlikely(cpy_r_r190 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL281;
    }
    CPy_DECREF(cpy_r_r187);
    cpy_r_r191 = CPy_GetCoro(cpy_r_r190);
    CPy_DECREF(cpy_r_r190);
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL278;
    }
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__47 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__47);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__47 = cpy_r_r191;
    cpy_r_r192 = 1;
    if (unlikely(!cpy_r_r192)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL278;
    }
    cpy_r_r193 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__47;
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__47", -1, CPyStatic__nonce___globals);
        goto CPyL278;
    }
    CPy_INCREF(cpy_r_r193);
CPyL171: ;
    cpy_r_r194 = CPyIter_Next(cpy_r_r193);
    CPy_DECREF(cpy_r_r193);
    if (cpy_r_r194 == NULL) {
        goto CPyL282;
    } else
        goto CPyL174;
CPyL172: ;
    cpy_r_r195 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r195 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL283;
    }
    cpy_r_r196 = cpy_r_r195;
    CPy_DECREF(cpy_r_r196);
    goto CPyL197;
CPyL174: ;
    cpy_r_r197 = cpy_r_r194;
CPyL175: ;
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ = 8;
    cpy_r_r198 = 1;
    if (unlikely(!cpy_r_r198)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL284;
    } else
        goto CPyL285;
CPyL176: ;
    return cpy_r_r197;
CPyL177: ;
    cpy_r_r199 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r200 = cpy_r_type != cpy_r_r199;
    if (!cpy_r_r200) goto CPyL180;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL181;
    } else
        goto CPyL286;
CPyL179: ;
    CPy_Unreachable();
CPyL180: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL192;
CPyL181: ;
    cpy_r_r201 = CPy_CatchError();
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__48.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__48.f0);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__48.f1);
        CPy_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__48.f2);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__48 = cpy_r_r201;
    cpy_r_r202 = 1;
    if (unlikely(!cpy_r_r202)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL287;
    }
    cpy_r_r203 = (PyObject **)&cpy_r_r7;
    cpy_r_r204 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__47;
    if (unlikely(cpy_r_r204 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__47", -1, CPyStatic__nonce___globals);
        goto CPyL287;
    }
    CPy_INCREF(cpy_r_r204);
CPyL183: ;
    cpy_r_r205 = CPy_YieldFromErrorHandle(cpy_r_r204, cpy_r_r203);
    CPy_DecRef(cpy_r_r204);
    if (unlikely(cpy_r_r205 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL287;
    }
    if (cpy_r_r205) goto CPyL187;
    CPy_INCREF(cpy_r_r7);
    cpy_r_r197 = cpy_r_r7;
    cpy_r_r206 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__48;
    if (unlikely(cpy_r_r206.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__48", -1, CPyStatic__nonce___globals);
        goto CPyL288;
    }
    CPy_INCREF(cpy_r_r206.f0);
    CPy_INCREF(cpy_r_r206.f1);
    CPy_INCREF(cpy_r_r206.f2);
CPyL186: ;
    CPy_RestoreExcInfo(cpy_r_r206);
    CPy_DecRef(cpy_r_r206.f0);
    CPy_DecRef(cpy_r_r206.f1);
    CPy_DecRef(cpy_r_r206.f2);
    goto CPyL175;
CPyL187: ;
    cpy_r_r196 = cpy_r_r7;
    CPy_DecRef(cpy_r_r196);
    cpy_r_r207 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__48;
    if (unlikely(cpy_r_r207.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__48", -1, CPyStatic__nonce___globals);
        goto CPyL189;
    }
    CPy_INCREF(cpy_r_r207.f0);
    CPy_INCREF(cpy_r_r207.f1);
    CPy_INCREF(cpy_r_r207.f2);
CPyL188: ;
    CPy_RestoreExcInfo(cpy_r_r207);
    CPy_DecRef(cpy_r_r207.f0);
    CPy_DecRef(cpy_r_r207.f1);
    CPy_DecRef(cpy_r_r207.f2);
    goto CPyL197;
CPyL189: ;
    cpy_r_r208 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__48;
    if (unlikely(cpy_r_r208.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__48' of 'get_block_number_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r208.f0);
        CPy_INCREF(cpy_r_r208.f1);
        CPy_INCREF(cpy_r_r208.f2);
    }
    CPy_DecRef(cpy_r_r10);
    if (unlikely(cpy_r_r208.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL206;
    }
CPyL190: ;
    CPy_RestoreExcInfo(cpy_r_r208);
    CPy_DecRef(cpy_r_r208.f0);
    CPy_DecRef(cpy_r_r208.f1);
    CPy_DecRef(cpy_r_r208.f2);
    cpy_r_r209 = CPy_KeepPropagating();
    if (!cpy_r_r209) {
        goto CPyL206;
    } else
        goto CPyL289;
CPyL191: ;
    CPy_Unreachable();
CPyL192: ;
    cpy_r_r210 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__47;
    if (unlikely(cpy_r_r210 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__47", -1, CPyStatic__nonce___globals);
        goto CPyL290;
    }
    CPy_INCREF(cpy_r_r210);
CPyL193: ;
    cpy_r_r211 = CPyIter_Send(cpy_r_r210, cpy_r_arg);
    CPy_DECREF(cpy_r_r210);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r211 == NULL) goto CPyL291;
    cpy_r_r197 = cpy_r_r211;
    goto CPyL175;
CPyL195: ;
    cpy_r_r212 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r212 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 190, CPyStatic__nonce___globals);
        goto CPyL283;
    }
    cpy_r_r196 = cpy_r_r212;
    CPy_DECREF(cpy_r_r196);
CPyL197: ;
    if (cpy_r_r9.f0 == NULL) {
        goto CPyL200;
    } else
        goto CPyL292;
CPyL198: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL206;
    } else
        goto CPyL293;
CPyL199: ;
    CPy_Unreachable();
CPyL200: ;
    cpy_r_r213 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41;
    if (unlikely(cpy_r_r213 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__41", -1, CPyStatic__nonce___globals);
        goto CPyL227;
    }
    CPy_INCREF(cpy_r_r213);
CPyL201: ;
    if (cpy_r_r213 == NULL) {
        goto CPyL210;
    } else
        goto CPyL294;
CPyL202: ;
    cpy_r_r214 = ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_temp__41;
    if (unlikely(cpy_r_r214 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/_nonce.py", "get_block_number", "get_block_number_env", "__mypyc_temp__41", -1, CPyStatic__nonce___globals);
        goto CPyL227;
    }
    CPy_INCREF(cpy_r_r214);
CPyL203: ;
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ = -2;
    cpy_r_r215 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r10);
    if (unlikely(!cpy_r_r215)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", -1, CPyStatic__nonce___globals);
        goto CPyL295;
    }
    CPyGen_SetStopIterationValue(cpy_r_r214);
    CPy_DECREF(cpy_r_r214);
    if (!0) goto CPyL220;
    CPy_Unreachable();
CPyL206: ;
    if (cpy_r_r9.f0 == NULL) goto CPyL208;
    CPy_RestoreExcInfo(cpy_r_r9);
    CPy_XDECREF(cpy_r_r9.f0);
    CPy_XDECREF(cpy_r_r9.f1);
    CPy_XDECREF(cpy_r_r9.f2);
CPyL208: ;
    cpy_r_r216 = CPy_KeepPropagating();
    if (!cpy_r_r216) goto CPyL220;
    CPy_Unreachable();
CPyL210: ;
    cpy_r_r217 = Py_None;
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r10)->___mypyc_next_label__ = -2;
    cpy_r_r218 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r10);
    if (unlikely(!cpy_r_r218)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 187, CPyStatic__nonce___globals);
        goto CPyL220;
    }
    CPyGen_SetStopIterationValue(cpy_r_r217);
    if (!0) goto CPyL220;
    CPy_Unreachable();
CPyL213: ;
    cpy_r_r219 = cpy_r_r11 == 0;
    if (cpy_r_r219) goto CPyL296;
    cpy_r_r220 = cpy_r_r11 == 2;
    if (cpy_r_r220) {
        goto CPyL297;
    } else
        goto CPyL298;
CPyL215: ;
    cpy_r_r221 = cpy_r_r11 == 4;
    if (cpy_r_r221) {
        goto CPyL299;
    } else
        goto CPyL300;
CPyL216: ;
    cpy_r_r222 = cpy_r_r11 == 6;
    if (cpy_r_r222) {
        goto CPyL301;
    } else
        goto CPyL302;
CPyL217: ;
    cpy_r_r223 = cpy_r_r11 == 8;
    CPyTagged_DECREF(cpy_r_r11);
    if (cpy_r_r223) {
        goto CPyL177;
    } else
        goto CPyL303;
CPyL218: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r224 = 0;
    if (unlikely(!cpy_r_r224)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 187, CPyStatic__nonce___globals);
        goto CPyL220;
    }
    CPy_Unreachable();
CPyL220: ;
    cpy_r_r225 = NULL;
    return cpy_r_r225;
CPyL221: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9.f0);
    CPy_XDecRef(cpy_r_r9.f1);
    CPy_XDecRef(cpy_r_r9.f2);
    goto CPyL220;
CPyL222: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_XDecRef(cpy_r_r9.f0);
    CPy_XDecRef(cpy_r_r9.f1);
    CPy_XDecRef(cpy_r_r9.f2);
    CPy_DecRef(cpy_r_r10);
    goto CPyL220;
CPyL223: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL3;
CPyL224: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL6;
CPyL225: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL220;
CPyL226: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    goto CPyL16;
CPyL227: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL220;
CPyL228: ;
    CPy_DecRef(cpy_r_r32);
    goto CPyL220;
CPyL229: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL21;
CPyL230: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r36);
    goto CPyL220;
CPyL231: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r44);
    goto CPyL220;
CPyL232: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL33;
CPyL233: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL220;
CPyL234: ;
    CPy_DecRef(cpy_r_r53);
    goto CPyL42;
CPyL235: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL37;
CPyL236: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL40;
CPyL237: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    goto CPyL50;
CPyL238: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r53);
    goto CPyL50;
CPyL239: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    goto CPyL50;
CPyL240: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_arg);
    goto CPyL220;
CPyL241: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL56;
CPyL242: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL59;
CPyL243: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL60;
CPyL244: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL116;
CPyL245: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL69;
CPyL246: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL160;
CPyL247: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL72;
CPyL248: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL73;
CPyL249: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL84;
CPyL250: ;
    CPy_DecRef(cpy_r_r107);
    goto CPyL93;
CPyL251: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL88;
CPyL252: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL91;
CPyL253: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL101;
CPyL254: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r107);
    goto CPyL101;
CPyL255: ;
    CPy_DecRef(cpy_r_r106);
    goto CPyL101;
CPyL256: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL103;
CPyL257: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_arg);
    goto CPyL116;
CPyL258: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL107;
CPyL259: ;
    CPy_DecRef(cpy_r_r106);
    goto CPyL116;
CPyL260: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL160;
CPyL261: ;
    CPy_XDecRef(cpy_r_r5);
    goto CPyL156;
CPyL262: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r142);
    CPy_DecRef(cpy_r_r143);
    CPy_DecRef(cpy_r_r144);
    goto CPyL156;
CPyL263: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r142);
    CPy_DecRef(cpy_r_r143);
    CPy_DecRef(cpy_r_r144);
    CPy_DecRef(cpy_r_r145);
    goto CPyL156;
CPyL264: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r142);
    CPy_DecRef(cpy_r_r143);
    CPy_DecRef(cpy_r_r144);
    CPy_DecRef(cpy_r_r146);
    goto CPyL156;
CPyL265: ;
    CPy_XDecRef(cpy_r_r5);
    goto CPyL125;
CPyL266: ;
    CPy_DecRef(cpy_r_r156);
    goto CPyL134;
CPyL267: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL129;
CPyL268: ;
    CPy_XDECREF(cpy_r_r5);
    CPy_XDECREF(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL132;
CPyL269: ;
    CPy_XDecRef(cpy_r_r5);
    goto CPyL142;
CPyL270: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r156);
    goto CPyL142;
CPyL271: ;
    CPy_DecRef(cpy_r_r155);
    goto CPyL142;
CPyL272: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL144;
CPyL273: ;
    CPy_XDecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_arg);
    goto CPyL156;
CPyL274: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL148;
CPyL275: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL153;
CPyL276: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL158;
CPyL277: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL220;
CPyL278: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL206;
CPyL279: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL197;
CPyL280: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r186);
    goto CPyL206;
CPyL281: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r187);
    goto CPyL206;
CPyL282: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL172;
CPyL283: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL206;
CPyL284: ;
    CPy_DecRef(cpy_r_r197);
    goto CPyL181;
CPyL285: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9.f0);
    CPy_XDECREF(cpy_r_r9.f1);
    CPy_XDECREF(cpy_r_r9.f2);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL176;
CPyL286: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9.f0);
    CPy_XDECREF(cpy_r_r9.f1);
    CPy_XDECREF(cpy_r_r9.f2);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL179;
CPyL287: ;
    CPy_XDecRef(cpy_r_r7);
    goto CPyL189;
CPyL288: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r197);
    goto CPyL189;
CPyL289: ;
    CPy_XDecRef(cpy_r_r9.f0);
    CPy_XDecRef(cpy_r_r9.f1);
    CPy_XDecRef(cpy_r_r9.f2);
    goto CPyL191;
CPyL290: ;
    CPy_XDecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_arg);
    goto CPyL206;
CPyL291: ;
    CPy_XDECREF(cpy_r_r7);
    goto CPyL195;
CPyL292: ;
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL198;
CPyL293: ;
    CPy_XDECREF(cpy_r_r9.f0);
    CPy_XDECREF(cpy_r_r9.f1);
    CPy_XDECREF(cpy_r_r9.f2);
    goto CPyL199;
CPyL294: ;
    CPy_DECREF(cpy_r_r213);
    goto CPyL202;
CPyL295: ;
    CPy_DecRef(cpy_r_r214);
    goto CPyL220;
CPyL296: ;
    CPy_XDECREF(cpy_r_r9.f0);
    CPy_XDECREF(cpy_r_r9.f1);
    CPy_XDECREF(cpy_r_r9.f2);
    CPyTagged_DECREF(cpy_r_r11);
    goto CPyL2;
CPyL297: ;
    CPy_XDECREF(cpy_r_r9.f0);
    CPy_XDECREF(cpy_r_r9.f1);
    CPy_XDECREF(cpy_r_r9.f2);
    CPyTagged_DECREF(cpy_r_r11);
    goto CPyL38;
CPyL298: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL215;
CPyL299: ;
    CPy_XDECREF(cpy_r_r9.f0);
    CPy_XDECREF(cpy_r_r9.f1);
    CPy_XDECREF(cpy_r_r9.f2);
    CPyTagged_DECREF(cpy_r_r11);
    goto CPyL89;
CPyL300: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL216;
CPyL301: ;
    CPy_XDECREF(cpy_r_r9.f0);
    CPy_XDECREF(cpy_r_r9.f1);
    CPy_XDECREF(cpy_r_r9.f2);
    CPyTagged_DECREF(cpy_r_r11);
    goto CPyL130;
CPyL302: ;
    CPy_XDECREF(cpy_r_r5);
    goto CPyL217;
CPyL303: ;
    CPy_XDECREF(cpy_r_r7);
    CPy_XDECREF(cpy_r_r9.f0);
    CPy_XDECREF(cpy_r_r9.f1);
    CPy_XDECREF(cpy_r_r9.f2);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    goto CPyL218;
}

PyObject *CPyPy__nonce___get_block_number_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", "arg", 0};
    static CPyArg_Parser parser = {"OOOO:__mypyc_generator_helper__", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value;
    PyObject *obj_traceback;
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_type = obj_type;
    PyObject *arg_value = obj_value;
    PyObject *arg_traceback = obj_traceback;
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__nonce___get_block_number_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 187, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_number_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__nonce___get_block_number_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__nonce___get_block_number_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_number_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_number_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_block_number_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__next__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_number_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef__nonce___get_block_number_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy__nonce___get_block_number_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_number_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_number_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef__nonce___get_block_number_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "send", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_number_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__nonce___get_block_number_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_number_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_number_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_block_number_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__iter__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_number_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef__nonce___get_block_number_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy__nonce___get_block_number_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_number_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_number_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef__nonce___get_block_number_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "throw", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_number_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[10]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef__nonce___get_block_number_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[11]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp32 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp32);
    PyObject *__tmp33 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp33);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy__nonce___get_block_number_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_number_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_number_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_block_number_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "close", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_number_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy__nonce___get_block_number_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType__nonce___get_block_number_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders._nonce.get_block_number_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef__nonce___get_block_number_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "__await__", -1, CPyStatic__nonce___globals);
    return NULL;
}

PyObject *CPyDef__nonce___get_block_number(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyDef__nonce___get_block_number_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 187, CPyStatic__nonce___globals);
        goto CPyL5;
    }
    cpy_r_r1 = CPyDef__nonce___get_block_number_gen();
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 187, CPyStatic__nonce___globals);
        goto CPyL6;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
    if (((eth_portfolio____loaders____nonce___get_block_number_genObject *)cpy_r_r1)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders____nonce___get_block_number_genObject *)cpy_r_r1)->___mypyc_env__);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_genObject *)cpy_r_r1)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 187, CPyStatic__nonce___globals);
        goto CPyL7;
    }
    if (((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders____nonce___get_block_number_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r3 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 187, CPyStatic__nonce___globals);
        goto CPyL8;
    }
    return cpy_r_r1;
CPyL5: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL5;
CPyL7: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL5;
CPyL8: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL5;
}

PyObject *CPyPy__nonce___get_block_number(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":get_block_number", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *retval = CPyDef__nonce___get_block_number();
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "get_block_number", 187, CPyStatic__nonce___globals);
    return NULL;
}

char CPyDef__nonce_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    PyObject **cpy_r_r6;
    void *cpy_r_r8;
    void *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r28;
    PyObject **cpy_r_r29;
    void *cpy_r_r31;
    void *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    int32_t cpy_r_r56;
    char cpy_r_r57;
    PyObject *cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    int32_t cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    int32_t cpy_r_r72;
    char cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    int32_t cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    int32_t cpy_r_r82;
    char cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    tuple_T2OO cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    int32_t cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    tuple_T2OO cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    int32_t cpy_r_r114;
    char cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject **cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    int32_t cpy_r_r126;
    char cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject **cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    int32_t cpy_r_r140;
    char cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    int32_t cpy_r_r149;
    char cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    int32_t cpy_r_r156;
    char cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    int32_t cpy_r_r163;
    char cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    char cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    int32_t cpy_r_r174;
    char cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    int32_t cpy_r_r178;
    char cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    int32_t cpy_r_r183;
    char cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    int32_t cpy_r_r188;
    char cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    int32_t cpy_r_r196;
    char cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    int32_t cpy_r_r201;
    char cpy_r_r202;
    char cpy_r_r203;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[22]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", -1, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_asyncio;
    cpy_r_r6 = (PyObject **)&CPyModule_logging;
    PyObject **cpy_r_r7[2] = {cpy_r_r5, cpy_r_r6};
    cpy_r_r8 = (void *)&cpy_r_r7;
    int64_t cpy_r_r9[2] = {1, 2};
    cpy_r_r10 = (void *)&cpy_r_r9;
    cpy_r_r11 = CPyStatics[422]; /* (('asyncio', 'asyncio', 'asyncio'),
                                    ('logging', 'logging', 'logging')) */
    cpy_r_r12 = CPyStatic__nonce___globals;
    cpy_r_r13 = CPyStatics[25]; /* 'eth_portfolio/_loaders/_nonce.py' */
    cpy_r_r14 = CPyStatics[26]; /* '<module>' */
    cpy_r_r15 = CPyImport_ImportMany(cpy_r_r11, cpy_r_r8, cpy_r_r12, cpy_r_r13, cpy_r_r14, cpy_r_r10);
    if (!cpy_r_r15) goto CPyL64;
    cpy_r_r16 = CPyStatics[423]; /* ('defaultdict',) */
    cpy_r_r17 = CPyStatics[27]; /* 'collections' */
    cpy_r_r18 = CPyStatic__nonce___globals;
    cpy_r_r19 = CPyImport_ImportFromMany(cpy_r_r17, cpy_r_r16, cpy_r_r16, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 3, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyModule_collections = cpy_r_r19;
    CPy_INCREF(CPyModule_collections);
    CPy_DECREF(cpy_r_r19);
    cpy_r_r20 = CPyStatics[424]; /* ('time',) */
    cpy_r_r21 = CPyStatics[28]; /* 'time' */
    cpy_r_r22 = CPyStatic__nonce___globals;
    cpy_r_r23 = CPyImport_ImportFromMany(cpy_r_r21, cpy_r_r20, cpy_r_r20, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 4, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyModule_time = cpy_r_r23;
    CPy_INCREF(CPyModule_time);
    CPy_DECREF(cpy_r_r23);
    cpy_r_r24 = CPyStatics[425]; /* ('ClassVar', 'DefaultDict', 'Dict', 'Final', 'Tuple',
                                    'final') */
    cpy_r_r25 = CPyStatics[35]; /* 'typing' */
    cpy_r_r26 = CPyStatic__nonce___globals;
    cpy_r_r27 = CPyImport_ImportFromMany(cpy_r_r25, cpy_r_r24, cpy_r_r24, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 5, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyModule_typing = cpy_r_r27;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r28 = (PyObject **)&CPyModule_a_sync;
    cpy_r_r29 = (PyObject **)&CPyModule_dank_mids;
    PyObject **cpy_r_r30[2] = {cpy_r_r28, cpy_r_r29};
    cpy_r_r31 = (void *)&cpy_r_r30;
    int64_t cpy_r_r32[2] = {7, 8};
    cpy_r_r33 = (void *)&cpy_r_r32;
    cpy_r_r34 = CPyStatics[428]; /* (('a_sync', 'a_sync', 'a_sync'),
                                    ('dank_mids', 'dank_mids', 'dank_mids')) */
    cpy_r_r35 = CPyStatic__nonce___globals;
    cpy_r_r36 = CPyStatics[25]; /* 'eth_portfolio/_loaders/_nonce.py' */
    cpy_r_r37 = CPyStatics[26]; /* '<module>' */
    cpy_r_r38 = CPyImport_ImportMany(cpy_r_r34, cpy_r_r31, cpy_r_r35, cpy_r_r36, cpy_r_r37, cpy_r_r33);
    if (!cpy_r_r38) goto CPyL64;
    cpy_r_r39 = CPyStatics[429]; /* ('BlockNumber', 'ChecksumAddress') */
    cpy_r_r40 = CPyStatics[40]; /* 'eth_typing' */
    cpy_r_r41 = CPyStatic__nonce___globals;
    cpy_r_r42 = CPyImport_ImportFromMany(cpy_r_r40, cpy_r_r39, cpy_r_r39, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 9, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyModule_eth_typing = cpy_r_r42;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r43 = CPyStatics[430]; /* ('utils',) */
    cpy_r_r44 = CPyStatics[42]; /* 'eth_portfolio._loaders' */
    cpy_r_r45 = CPyStatic__nonce___globals;
    cpy_r_r46 = CPyImport_ImportFromMany(cpy_r_r44, cpy_r_r43, cpy_r_r43, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 11, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyModule_eth_portfolio____loaders = cpy_r_r46;
    CPy_INCREF(CPyModule_eth_portfolio____loaders);
    CPy_DECREF(cpy_r_r46);
    cpy_r_r47 = CPyStatics[43]; /* 'eth_portfolio.nonces' */
    cpy_r_r48 = CPyModule_logging;
    cpy_r_r49 = CPyStatics[44]; /* 'getLogger' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 14, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    PyObject *cpy_r_r51[1] = {cpy_r_r47};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = PyObject_Vectorcall(cpy_r_r50, cpy_r_r52, 1, 0);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 14, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyStatic__nonce___logger = cpy_r_r53;
    CPy_INCREF(CPyStatic__nonce___logger);
    cpy_r_r54 = CPyStatic__nonce___globals;
    cpy_r_r55 = CPyStatics[45]; /* 'logger' */
    cpy_r_r56 = CPyDict_SetItem(cpy_r_r54, cpy_r_r55, cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    cpy_r_r57 = cpy_r_r56 >= 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 14, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r58 = CPyStatic__nonce___logger;
    if (likely(cpy_r_r58 != NULL)) goto CPyL16;
    PyErr_SetString(PyExc_NameError, "value for final name \"logger\" was not set");
    cpy_r_r59 = 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 15, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL16: ;
    cpy_r_r60 = CPyStatics[46]; /* 'isEnabledFor' */
    cpy_r_r61 = CPyObject_GetAttr(cpy_r_r58, cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 15, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyStatic__nonce___logger_is_enabled = cpy_r_r61;
    CPy_INCREF(CPyStatic__nonce___logger_is_enabled);
    cpy_r_r62 = CPyStatic__nonce___globals;
    cpy_r_r63 = CPyStatics[47]; /* 'logger_is_enabled' */
    cpy_r_r64 = CPyDict_SetItem(cpy_r_r62, cpy_r_r63, cpy_r_r61);
    CPy_DECREF(cpy_r_r61);
    cpy_r_r65 = cpy_r_r64 >= 0;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 15, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r66 = CPyStatic__nonce___logger;
    if (likely(cpy_r_r66 != NULL)) goto CPyL21;
    PyErr_SetString(PyExc_NameError, "value for final name \"logger\" was not set");
    cpy_r_r67 = 0;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 16, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL21: ;
    cpy_r_r68 = CPyStatics[48]; /* '_log' */
    cpy_r_r69 = CPyObject_GetAttr(cpy_r_r66, cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 16, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyStatic__nonce_____log = cpy_r_r69;
    CPy_INCREF(CPyStatic__nonce_____log);
    cpy_r_r70 = CPyStatic__nonce___globals;
    cpy_r_r71 = CPyStatics[49]; /* '__log' */
    cpy_r_r72 = CPyDict_SetItem(cpy_r_r70, cpy_r_r71, cpy_r_r69);
    CPy_DECREF(cpy_r_r69);
    cpy_r_r73 = cpy_r_r72 >= 0;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 16, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyStatic__nonce___DEBUG = 20;
    cpy_r_r74 = CPyStatic__nonce___globals;
    cpy_r_r75 = CPyStatics[50]; /* 'DEBUG' */
    cpy_r_r76 = CPyStatics[412]; /* 10 */
    cpy_r_r77 = CPyDict_SetItem(cpy_r_r74, cpy_r_r75, cpy_r_r76);
    cpy_r_r78 = cpy_r_r77 >= 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 18, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r79 = (PyObject *)&PyLong_Type;
    cpy_r_r80 = CPyStatic__nonce___globals;
    cpy_r_r81 = CPyStatics[51]; /* 'Nonce' */
    cpy_r_r82 = CPyDict_SetItem(cpy_r_r80, cpy_r_r81, cpy_r_r79);
    cpy_r_r83 = cpy_r_r82 >= 0;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 20, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r84 = CPyStatic__nonce___globals;
    cpy_r_r85 = CPyStatics[30]; /* 'DefaultDict' */
    cpy_r_r86 = CPyDict_GetItem(cpy_r_r84, cpy_r_r85);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 21, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r87 = CPyStatic__nonce___globals;
    cpy_r_r88 = CPyStatics[51]; /* 'Nonce' */
    cpy_r_r89 = CPyDict_GetItem(cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 21, CPyStatic__nonce___globals);
        goto CPyL65;
    }
    cpy_r_r90 = CPyStatic__nonce___globals;
    cpy_r_r91 = CPyStatics[38]; /* 'BlockNumber' */
    cpy_r_r92 = CPyDict_GetItem(cpy_r_r90, cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 21, CPyStatic__nonce___globals);
        goto CPyL66;
    }
    cpy_r_r93.f0 = cpy_r_r89;
    cpy_r_r93.f1 = cpy_r_r92;
    cpy_r_r94 = PyTuple_New(2);
    if (unlikely(cpy_r_r94 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp34 = cpy_r_r93.f0;
    PyTuple_SET_ITEM(cpy_r_r94, 0, __tmp34);
    PyObject *__tmp35 = cpy_r_r93.f1;
    PyTuple_SET_ITEM(cpy_r_r94, 1, __tmp35);
    cpy_r_r95 = PyObject_GetItem(cpy_r_r86, cpy_r_r94);
    CPy_DECREF(cpy_r_r86);
    CPy_DECREF(cpy_r_r94);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 21, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r96 = CPyStatic__nonce___globals;
    cpy_r_r97 = CPyStatics[52]; /* 'AccountNonces' */
    cpy_r_r98 = CPyDict_SetItem(cpy_r_r96, cpy_r_r97, cpy_r_r95);
    CPy_DECREF(cpy_r_r95);
    cpy_r_r99 = cpy_r_r98 >= 0;
    if (unlikely(!cpy_r_r99)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 21, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r100 = CPyStatic__nonce___globals;
    cpy_r_r101 = CPyStatics[30]; /* 'DefaultDict' */
    cpy_r_r102 = CPyDict_GetItem(cpy_r_r100, cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 22, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r103 = CPyStatic__nonce___globals;
    cpy_r_r104 = CPyStatics[39]; /* 'ChecksumAddress' */
    cpy_r_r105 = CPyDict_GetItem(cpy_r_r103, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 22, CPyStatic__nonce___globals);
        goto CPyL67;
    }
    cpy_r_r106 = CPyStatic__nonce___globals;
    cpy_r_r107 = CPyStatics[52]; /* 'AccountNonces' */
    cpy_r_r108 = CPyDict_GetItem(cpy_r_r106, cpy_r_r107);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 22, CPyStatic__nonce___globals);
        goto CPyL68;
    }
    cpy_r_r109.f0 = cpy_r_r105;
    cpy_r_r109.f1 = cpy_r_r108;
    cpy_r_r110 = PyTuple_New(2);
    if (unlikely(cpy_r_r110 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp36 = cpy_r_r109.f0;
    PyTuple_SET_ITEM(cpy_r_r110, 0, __tmp36);
    PyObject *__tmp37 = cpy_r_r109.f1;
    PyTuple_SET_ITEM(cpy_r_r110, 1, __tmp37);
    cpy_r_r111 = PyObject_GetItem(cpy_r_r102, cpy_r_r110);
    CPy_DECREF(cpy_r_r102);
    CPy_DECREF(cpy_r_r110);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 22, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r112 = CPyStatic__nonce___globals;
    cpy_r_r113 = CPyStatics[53]; /* 'GlobalNonces' */
    cpy_r_r114 = CPyDict_SetItem(cpy_r_r112, cpy_r_r113, cpy_r_r111);
    CPy_DECREF(cpy_r_r111);
    cpy_r_r115 = cpy_r_r114 >= 0;
    if (unlikely(!cpy_r_r115)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 22, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r116 = CPyDef__nonce_____mypyc_lambda__0_obj();
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 24, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r117 = CPyStatic__nonce___globals;
    cpy_r_r118 = CPyStatics[3]; /* 'defaultdict' */
    cpy_r_r119 = CPyDict_GetItem(cpy_r_r117, cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 24, CPyStatic__nonce___globals);
        goto CPyL69;
    }
    PyObject *cpy_r_r120[1] = {cpy_r_r116};
    cpy_r_r121 = (PyObject **)&cpy_r_r120;
    cpy_r_r122 = PyObject_Vectorcall(cpy_r_r119, cpy_r_r121, 1, 0);
    CPy_DECREF(cpy_r_r119);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 24, CPyStatic__nonce___globals);
        goto CPyL69;
    }
    CPy_DECREF_NO_IMM(cpy_r_r116);
    if (likely(PyDict_Check(cpy_r_r122)))
        cpy_r_r123 = cpy_r_r122;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 24, CPyStatic__nonce___globals, "dict", cpy_r_r122);
        goto CPyL64;
    }
    CPyStatic__nonce___nonces = cpy_r_r123;
    CPy_INCREF(CPyStatic__nonce___nonces);
    cpy_r_r124 = CPyStatic__nonce___globals;
    cpy_r_r125 = CPyStatics[54]; /* 'nonces' */
    cpy_r_r126 = CPyDict_SetItem(cpy_r_r124, cpy_r_r125, cpy_r_r123);
    CPy_DECREF(cpy_r_r123);
    cpy_r_r127 = cpy_r_r126 >= 0;
    if (unlikely(!cpy_r_r127)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 24, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r128 = CPyModule_asyncio;
    cpy_r_r129 = CPyStatics[17]; /* 'Lock' */
    cpy_r_r130 = CPyObject_GetAttr(cpy_r_r128, cpy_r_r129);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 25, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r131 = CPyStatic__nonce___globals;
    cpy_r_r132 = CPyStatics[3]; /* 'defaultdict' */
    cpy_r_r133 = CPyDict_GetItem(cpy_r_r131, cpy_r_r132);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 25, CPyStatic__nonce___globals);
        goto CPyL70;
    }
    PyObject *cpy_r_r134[1] = {cpy_r_r130};
    cpy_r_r135 = (PyObject **)&cpy_r_r134;
    cpy_r_r136 = PyObject_Vectorcall(cpy_r_r133, cpy_r_r135, 1, 0);
    CPy_DECREF(cpy_r_r133);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 25, CPyStatic__nonce___globals);
        goto CPyL70;
    }
    CPy_DECREF(cpy_r_r130);
    if (likely(PyDict_Check(cpy_r_r136)))
        cpy_r_r137 = cpy_r_r136;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 25, CPyStatic__nonce___globals, "dict", cpy_r_r136);
        goto CPyL64;
    }
    CPyStatic__nonce___locks = cpy_r_r137;
    CPy_INCREF(CPyStatic__nonce___locks);
    cpy_r_r138 = CPyStatic__nonce___globals;
    cpy_r_r139 = CPyStatics[55]; /* 'locks' */
    cpy_r_r140 = CPyDict_SetItem(cpy_r_r138, cpy_r_r139, cpy_r_r137);
    CPy_DECREF(cpy_r_r137);
    cpy_r_r141 = cpy_r_r140 >= 0;
    if (unlikely(!cpy_r_r141)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 25, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r142 = CPyModule_dank_mids;
    cpy_r_r143 = CPyStatics[20]; /* 'eth' */
    cpy_r_r144 = CPyObject_GetAttr(cpy_r_r142, cpy_r_r143);
    if (unlikely(cpy_r_r144 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 27, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r145 = CPyStatics[56]; /* 'get_transaction_count' */
    cpy_r_r146 = CPyObject_GetAttr(cpy_r_r144, cpy_r_r145);
    CPy_DECREF(cpy_r_r144);
    if (unlikely(cpy_r_r146 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 27, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyStatic__nonce___get_transaction_count = cpy_r_r146;
    CPy_INCREF(CPyStatic__nonce___get_transaction_count);
    cpy_r_r147 = CPyStatic__nonce___globals;
    cpy_r_r148 = CPyStatics[56]; /* 'get_transaction_count' */
    cpy_r_r149 = CPyDict_SetItem(cpy_r_r147, cpy_r_r148, cpy_r_r146);
    CPy_DECREF(cpy_r_r146);
    cpy_r_r150 = cpy_r_r149 >= 0;
    if (unlikely(!cpy_r_r150)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 27, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r151 = CPyModule_a_sync;
    cpy_r_r152 = CPyStatics[57]; /* 'igather' */
    cpy_r_r153 = CPyObject_GetAttr(cpy_r_r151, cpy_r_r152);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 29, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyStatic__nonce___igather = cpy_r_r153;
    CPy_INCREF(CPyStatic__nonce___igather);
    cpy_r_r154 = CPyStatic__nonce___globals;
    cpy_r_r155 = CPyStatics[57]; /* 'igather' */
    cpy_r_r156 = CPyDict_SetItem(cpy_r_r154, cpy_r_r155, cpy_r_r153);
    CPy_DECREF(cpy_r_r153);
    cpy_r_r157 = cpy_r_r156 >= 0;
    if (unlikely(!cpy_r_r157)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 29, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r158 = CPyStatic__nonce___globals;
    cpy_r_r159 = CPyStatics[28]; /* 'time' */
    cpy_r_r160 = CPyDict_GetItem(cpy_r_r158, cpy_r_r159);
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 31, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    CPyStatic__nonce___now = cpy_r_r160;
    CPy_INCREF(CPyStatic__nonce___now);
    cpy_r_r161 = CPyStatic__nonce___globals;
    cpy_r_r162 = CPyStatics[58]; /* 'now' */
    cpy_r_r163 = CPyDict_SetItem(cpy_r_r161, cpy_r_r162, cpy_r_r160);
    CPy_DECREF(cpy_r_r160);
    cpy_r_r164 = cpy_r_r163 >= 0;
    if (unlikely(!cpy_r_r164)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 31, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r165 = NULL;
    cpy_r_r166 = CPyStatics[59]; /* 'eth_portfolio._loaders._nonce' */
    cpy_r_r167 = (PyObject *)CPyType__nonce___BlockCache_template;
    cpy_r_r168 = CPyType_FromTemplate(cpy_r_r167, cpy_r_r165, cpy_r_r166);
    if (unlikely(cpy_r_r168 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 180, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r169 = CPyDef__nonce___BlockCache_trait_vtable_setup();
    if (unlikely(cpy_r_r169 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", -1, CPyStatic__nonce___globals);
        goto CPyL71;
    }
    cpy_r_r170 = CPyStatics[60]; /* '__mypyc_attrs__' */
    cpy_r_r171 = CPyStatics[61]; /* 'lock' */
    cpy_r_r172 = CPyStatics[62]; /* 'ttl' */
    cpy_r_r173 = PyTuple_Pack(2, cpy_r_r171, cpy_r_r172);
    if (unlikely(cpy_r_r173 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 180, CPyStatic__nonce___globals);
        goto CPyL71;
    }
    cpy_r_r174 = PyObject_SetAttr(cpy_r_r168, cpy_r_r170, cpy_r_r173);
    CPy_DECREF(cpy_r_r173);
    cpy_r_r175 = cpy_r_r174 >= 0;
    if (unlikely(!cpy_r_r175)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 180, CPyStatic__nonce___globals);
        goto CPyL71;
    }
    CPyType__nonce___BlockCache = (PyTypeObject *)cpy_r_r168;
    CPy_INCREF(CPyType__nonce___BlockCache);
    cpy_r_r176 = CPyStatic__nonce___globals;
    cpy_r_r177 = CPyStatics[63]; /* 'BlockCache' */
    cpy_r_r178 = CPyDict_SetItem(cpy_r_r176, cpy_r_r177, cpy_r_r168);
    CPy_DECREF(cpy_r_r168);
    cpy_r_r179 = cpy_r_r178 >= 0;
    if (unlikely(!cpy_r_r179)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 180, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r180 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r181 = CPyStatics[19]; /* 'block' */
    cpy_r_r182 = CPyStatics[409]; /* 0 */
    cpy_r_r183 = PyObject_SetAttr(cpy_r_r180, cpy_r_r181, cpy_r_r182);
    cpy_r_r184 = cpy_r_r183 >= 0;
    if (unlikely(!cpy_r_r184)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 181, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r185 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r186 = CPyStatics[18]; /* 'updated_at' */
    cpy_r_r187 = PyFloat_FromDouble(0.0);
    cpy_r_r188 = PyObject_SetAttr(cpy_r_r185, cpy_r_r186, cpy_r_r187);
    CPy_DECREF(cpy_r_r187);
    cpy_r_r189 = cpy_r_r188 >= 0;
    if (unlikely(!cpy_r_r189)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 182, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r190 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r191 = CPyModule_asyncio;
    cpy_r_r192 = CPyStatics[17]; /* 'Lock' */
    cpy_r_r193 = CPyObject_GetAttr(cpy_r_r191, cpy_r_r192);
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 183, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r194 = PyObject_Vectorcall(cpy_r_r193, 0, 0, 0);
    CPy_DECREF(cpy_r_r193);
    if (unlikely(cpy_r_r194 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 183, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    cpy_r_r195 = CPyStatics[61]; /* 'lock' */
    cpy_r_r196 = PyObject_SetAttr(cpy_r_r190, cpy_r_r195, cpy_r_r194);
    cpy_r_r197 = cpy_r_r196 >= 0;
    if (unlikely(!cpy_r_r197)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 183, CPyStatic__nonce___globals);
        goto CPyL72;
    }
    CPyStatic__nonce___BlockCache___lock = cpy_r_r194;
    CPy_INCREF(CPyStatic__nonce___BlockCache___lock);
    CPy_DECREF(cpy_r_r194);
    cpy_r_r198 = (PyObject *)CPyType__nonce___BlockCache;
    cpy_r_r199 = CPyStatics[62]; /* 'ttl' */
    cpy_r_r200 = PyFloat_FromDouble(5.0);
    cpy_r_r201 = PyObject_SetAttr(cpy_r_r198, cpy_r_r199, cpy_r_r200);
    CPy_DECREF(cpy_r_r200);
    cpy_r_r202 = cpy_r_r201 >= 0;
    if (unlikely(!cpy_r_r202)) {
        CPy_AddTraceback("eth_portfolio/_loaders/_nonce.py", "<module>", 184, CPyStatic__nonce___globals);
        goto CPyL64;
    }
    return 1;
CPyL64: ;
    cpy_r_r203 = 2;
    return cpy_r_r203;
CPyL65: ;
    CPy_DecRef(cpy_r_r86);
    goto CPyL64;
CPyL66: ;
    CPy_DecRef(cpy_r_r86);
    CPy_DecRef(cpy_r_r89);
    goto CPyL64;
CPyL67: ;
    CPy_DecRef(cpy_r_r102);
    goto CPyL64;
CPyL68: ;
    CPy_DecRef(cpy_r_r102);
    CPy_DecRef(cpy_r_r105);
    goto CPyL64;
CPyL69: ;
    CPy_DecRef(cpy_r_r116);
    goto CPyL64;
CPyL70: ;
    CPy_DecRef(cpy_r_r130);
    goto CPyL64;
CPyL71: ;
    CPy_DecRef(cpy_r_r168);
    goto CPyL64;
CPyL72: ;
    CPy_DecRef(cpy_r_r194);
    goto CPyL64;
}

static PyObject *balances___load_token_balance_env_setup(PyTypeObject *type);
PyObject *CPyDef_balances___load_token_balance_env(void);

static PyObject *
balances___load_token_balance_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_balances___load_token_balance_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return balances___load_token_balance_env_setup(type);
}

static int
balances___load_token_balance_env_traverse(eth_portfolio____loaders___balances___load_token_balance_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_token);
    Py_VISIT(self->_address);
    Py_VISIT(self->_block);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->___mypyc_temp__0);
    Py_VISIT(self->___mypyc_temp__1.f0);
    Py_VISIT(self->___mypyc_temp__1.f1);
    Py_VISIT(self->___mypyc_temp__1.f2);
    Py_VISIT(self->_balance);
    Py_VISIT(self->___mypyc_temp__2.f0);
    Py_VISIT(self->___mypyc_temp__2.f1);
    Py_VISIT(self->___mypyc_temp__2.f2);
    Py_VISIT(self->_token_address);
    Py_VISIT(self->___mypyc_temp__3);
    Py_VISIT(self->___mypyc_temp__4.f0);
    Py_VISIT(self->___mypyc_temp__4.f1);
    Py_VISIT(self->___mypyc_temp__4.f2);
    Py_VISIT(self->_price);
    return 0;
}

static int
balances___load_token_balance_env_clear(eth_portfolio____loaders___balances___load_token_balance_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_token);
    Py_CLEAR(self->_address);
    Py_CLEAR(self->_block);
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___mypyc_temp__0);
    Py_CLEAR(self->___mypyc_temp__1.f0);
    Py_CLEAR(self->___mypyc_temp__1.f1);
    Py_CLEAR(self->___mypyc_temp__1.f2);
    Py_CLEAR(self->_balance);
    Py_CLEAR(self->___mypyc_temp__2.f0);
    Py_CLEAR(self->___mypyc_temp__2.f1);
    Py_CLEAR(self->___mypyc_temp__2.f2);
    Py_CLEAR(self->_token_address);
    Py_CLEAR(self->___mypyc_temp__3);
    Py_CLEAR(self->___mypyc_temp__4.f0);
    Py_CLEAR(self->___mypyc_temp__4.f1);
    Py_CLEAR(self->___mypyc_temp__4.f2);
    Py_CLEAR(self->_price);
    return 0;
}

static void
balances___load_token_balance_env_dealloc(eth_portfolio____loaders___balances___load_token_balance_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, balances___load_token_balance_env_dealloc)
    balances___load_token_balance_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem balances___load_token_balance_env_vtable[1];
static bool
CPyDef_balances___load_token_balance_env_trait_vtable_setup(void)
{
    CPyVTableItem balances___load_token_balance_env_vtable_scratch[] = {
        NULL
    };
    memcpy(balances___load_token_balance_env_vtable, balances___load_token_balance_env_vtable_scratch, sizeof(balances___load_token_balance_env_vtable));
    return 1;
}

static PyMethodDef balances___load_token_balance_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_balances___load_token_balance_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "load_token_balance_env",
    .tp_new = balances___load_token_balance_env_new,
    .tp_dealloc = (destructor)balances___load_token_balance_env_dealloc,
    .tp_traverse = (traverseproc)balances___load_token_balance_env_traverse,
    .tp_clear = (inquiry)balances___load_token_balance_env_clear,
    .tp_methods = balances___load_token_balance_env_methods,
    .tp_basicsize = sizeof(eth_portfolio____loaders___balances___load_token_balance_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_balances___load_token_balance_env_template = &CPyType_balances___load_token_balance_env_template_;

static PyObject *
balances___load_token_balance_env_setup(PyTypeObject *type)
{
    eth_portfolio____loaders___balances___load_token_balance_envObject *self;
    self = (eth_portfolio____loaders___balances___load_token_balance_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = balances___load_token_balance_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__1 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__2 = (tuple_T3OOO) { NULL, NULL, NULL };
    self->___mypyc_temp__4 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_balances___load_token_balance_env(void)
{
    PyObject *self = balances___load_token_balance_env_setup(CPyType_balances___load_token_balance_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods balances___load_token_balance_gen_as_async = {
    .am_await = CPyDef_balances___load_token_balance_gen_____await__,
};
static PyObject *balances___load_token_balance_gen_setup(PyTypeObject *type);
PyObject *CPyDef_balances___load_token_balance_gen(void);

static PyObject *
balances___load_token_balance_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_balances___load_token_balance_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return balances___load_token_balance_gen_setup(type);
}

static int
balances___load_token_balance_gen_traverse(eth_portfolio____loaders___balances___load_token_balance_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
balances___load_token_balance_gen_clear(eth_portfolio____loaders___balances___load_token_balance_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
balances___load_token_balance_gen_dealloc(eth_portfolio____loaders___balances___load_token_balance_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, balances___load_token_balance_gen_dealloc)
    balances___load_token_balance_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem balances___load_token_balance_gen_vtable[7];
static bool
CPyDef_balances___load_token_balance_gen_trait_vtable_setup(void)
{
    CPyVTableItem balances___load_token_balance_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_balances___load_token_balance_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_balances___load_token_balance_gen_____next__,
        (CPyVTableItem)CPyDef_balances___load_token_balance_gen___send,
        (CPyVTableItem)CPyDef_balances___load_token_balance_gen_____iter__,
        (CPyVTableItem)CPyDef_balances___load_token_balance_gen___throw,
        (CPyVTableItem)CPyDef_balances___load_token_balance_gen___close,
        (CPyVTableItem)CPyDef_balances___load_token_balance_gen_____await__,
    };
    memcpy(balances___load_token_balance_gen_vtable, balances___load_token_balance_gen_vtable_scratch, sizeof(balances___load_token_balance_gen_vtable));
    return 1;
}

static PyMethodDef balances___load_token_balance_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy_balances___load_token_balance_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy_balances___load_token_balance_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy_balances___load_token_balance_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy_balances___load_token_balance_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy_balances___load_token_balance_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy_balances___load_token_balance_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy_balances___load_token_balance_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_balances___load_token_balance_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "load_token_balance_gen",
    .tp_new = balances___load_token_balance_gen_new,
    .tp_dealloc = (destructor)balances___load_token_balance_gen_dealloc,
    .tp_traverse = (traverseproc)balances___load_token_balance_gen_traverse,
    .tp_clear = (inquiry)balances___load_token_balance_gen_clear,
    .tp_methods = balances___load_token_balance_gen_methods,
    .tp_iter = CPyDef_balances___load_token_balance_gen_____iter__,
    .tp_iternext = CPyDef_balances___load_token_balance_gen_____next__,
    .tp_as_async = &balances___load_token_balance_gen_as_async,
    .tp_basicsize = sizeof(eth_portfolio____loaders___balances___load_token_balance_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_balances___load_token_balance_gen_template = &CPyType_balances___load_token_balance_gen_template_;

static PyObject *
balances___load_token_balance_gen_setup(PyTypeObject *type)
{
    eth_portfolio____loaders___balances___load_token_balance_genObject *self;
    self = (eth_portfolio____loaders___balances___load_token_balance_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = balances___load_token_balance_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_balances___load_token_balance_gen(void)
{
    PyObject *self = balances___load_token_balance_gen_setup(CPyType_balances___load_token_balance_gen);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef balancesmodule_methods[] = {
    {"load_token_balance", (PyCFunction)CPyPy_balances___load_token_balance, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef balancesmodule = {
    PyModuleDef_HEAD_INIT,
    "eth_portfolio._loaders.balances",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    balancesmodule_methods
};

PyObject *CPyInit_eth_portfolio____loaders___balances(void)
{
    PyObject* modname = NULL;
    if (CPyModule_eth_portfolio____loaders___balances_internal) {
        Py_INCREF(CPyModule_eth_portfolio____loaders___balances_internal);
        return CPyModule_eth_portfolio____loaders___balances_internal;
    }
    CPyModule_eth_portfolio____loaders___balances_internal = PyModule_Create(&balancesmodule);
    if (unlikely(CPyModule_eth_portfolio____loaders___balances_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_eth_portfolio____loaders___balances_internal, "__name__");
    CPyStatic_balances___globals = PyModule_GetDict(CPyModule_eth_portfolio____loaders___balances_internal);
    if (unlikely(CPyStatic_balances___globals == NULL))
        goto fail;
    CPyType_balances___load_token_balance_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_balances___load_token_balance_env_template, NULL, modname);
    if (unlikely(!CPyType_balances___load_token_balance_env))
        goto fail;
    CPyType_balances___load_token_balance_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_balances___load_token_balance_gen_template, NULL, modname);
    if (unlikely(!CPyType_balances___load_token_balance_gen))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_balances_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_eth_portfolio____loaders___balances_internal;
    fail:
    Py_CLEAR(CPyModule_eth_portfolio____loaders___balances_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_balances____ZERO);
    CPyStatic_balances____ZERO = NULL;
    CPy_XDECREF(CPyStatic_balances___logger);
    CPyStatic_balances___logger = NULL;
    CPy_XDECREF(CPyStatic_balances___log_warning);
    CPyStatic_balances___log_warning = NULL;
    Py_CLEAR(CPyType_balances___load_token_balance_env);
    Py_CLEAR(CPyType_balances___load_token_balance_gen);
    return NULL;
}

PyObject *CPyDef_balances___load_token_balance_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    CPyTagged cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    tuple_T3OOO cpy_r_r27;
    char cpy_r_r28;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    tuple_T3OOO cpy_r_r32;
    tuple_T3OOO cpy_r_r33;
    tuple_T3OOO cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
    tuple_T3OOO cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    char cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    char cpy_r_r55;
    tuple_T3OOO cpy_r_r56;
    tuple_T3OOO cpy_r_r57;
    char cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    char cpy_r_r62;
    PyObject *cpy_r_r63;
    int32_t cpy_r_r64;
    char cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject **cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    char cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject **cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    char cpy_r_r92;
    PyObject *cpy_r_r93;
    char cpy_r_r94;
    tuple_T3OOO cpy_r_r95;
    char cpy_r_r96;
    PyObject **cpy_r_r97;
    PyObject *cpy_r_r98;
    char cpy_r_r99;
    tuple_T3OOO cpy_r_r100;
    tuple_T3OOO cpy_r_r101;
    tuple_T3OOO cpy_r_r102;
    char cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    char cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject **cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    char cpy_r_r118;
    PyObject *cpy_r_r119;
    char cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject **cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject **cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject **cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject **cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    char cpy_r_r153;
    char cpy_r_r154;
    char cpy_r_r155;
    char cpy_r_r156;
    char cpy_r_r157;
    PyObject *cpy_r_r158;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = NULL;
    cpy_r_r3 = cpy_r_r2;
    cpy_r_r4 = ((eth_portfolio____loaders___balances___load_token_balance_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_gen", "__mypyc_env__", 21, CPyStatic_balances___globals);
        goto CPyL137;
    }
    CPy_INCREF_NO_IMM(cpy_r_r4);
CPyL1: ;
    cpy_r_r5 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__;
    if (unlikely(cpy_r_r5 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_next_label__", 21, CPyStatic_balances___globals);
        goto CPyL138;
    }
    CPyTagged_INCREF(cpy_r_r5);
    goto CPyL131;
CPyL2: ;
    cpy_r_r6 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r7 = cpy_r_type != cpy_r_r6;
    if (cpy_r_r7) {
        goto CPyL139;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
        goto CPyL136;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r8 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_token;
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "token", 45, CPyStatic_balances___globals);
        goto CPyL140;
    }
    CPy_INCREF(cpy_r_r8);
CPyL6: ;
    cpy_r_r9 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_address;
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "address", 45, CPyStatic_balances___globals);
        goto CPyL141;
    }
    CPy_INCREF(cpy_r_r9);
CPyL7: ;
    cpy_r_r10 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_block;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "block", 45, CPyStatic_balances___globals);
        goto CPyL142;
    }
    CPy_INCREF(cpy_r_r10);
CPyL8: ;
    cpy_r_r11 = CPyStatics[64]; /* 'balance_of_readable' */
    cpy_r_r12 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r13[4] = {cpy_r_r8, cpy_r_r9, cpy_r_r10, cpy_r_r12};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = CPyStatics[431]; /* ('sync',) */
    cpy_r_r16 = PyObject_VectorcallMethod(cpy_r_r11, cpy_r_r14, 9223372036854775811ULL, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 45, CPyStatic_balances___globals);
        goto CPyL143;
    }
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r10);
    cpy_r_r17 = CPy_GetCoro(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 45, CPyStatic_balances___globals);
        goto CPyL140;
    }
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__0);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__0 = cpy_r_r17;
    cpy_r_r18 = 1;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", -1, CPyStatic_balances___globals);
        goto CPyL140;
    }
    cpy_r_r19 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__0;
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__0", -1, CPyStatic_balances___globals);
        goto CPyL140;
    }
    CPy_INCREF(cpy_r_r19);
CPyL12: ;
    cpy_r_r20 = CPyIter_Next(cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    if (cpy_r_r20 == NULL) {
        goto CPyL144;
    } else
        goto CPyL15;
CPyL13: ;
    cpy_r_r21 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 45, CPyStatic_balances___globals);
        goto CPyL39;
    }
    cpy_r_r22 = cpy_r_r21;
    goto CPyL38;
CPyL15: ;
    cpy_r_r23 = cpy_r_r20;
CPyL16: ;
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__ = 2;
    cpy_r_r24 = 1;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 45, CPyStatic_balances___globals);
        goto CPyL145;
    } else
        goto CPyL146;
CPyL17: ;
    return cpy_r_r23;
CPyL18: ;
    cpy_r_r25 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r26 = cpy_r_type != cpy_r_r25;
    if (!cpy_r_r26) goto CPyL21;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 45, CPyStatic_balances___globals);
        goto CPyL22;
    } else
        goto CPyL147;
CPyL20: ;
    CPy_Unreachable();
CPyL21: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL33;
CPyL22: ;
    cpy_r_r27 = CPy_CatchError();
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__1.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__1.f0);
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__1.f1);
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__1.f2);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__1 = cpy_r_r27;
    cpy_r_r28 = 1;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", -1, CPyStatic_balances___globals);
        goto CPyL148;
    }
    cpy_r_r29 = (PyObject **)&cpy_r_r1;
    cpy_r_r30 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__0;
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__0", -1, CPyStatic_balances___globals);
        goto CPyL148;
    }
    CPy_INCREF(cpy_r_r30);
CPyL24: ;
    cpy_r_r31 = CPy_YieldFromErrorHandle(cpy_r_r30, cpy_r_r29);
    CPy_DecRef(cpy_r_r30);
    if (unlikely(cpy_r_r31 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 45, CPyStatic_balances___globals);
        goto CPyL148;
    }
    if (cpy_r_r31) goto CPyL28;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r23 = cpy_r_r1;
    cpy_r_r32 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__1;
    if (unlikely(cpy_r_r32.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__1", -1, CPyStatic_balances___globals);
        goto CPyL149;
    }
    CPy_INCREF(cpy_r_r32.f0);
    CPy_INCREF(cpy_r_r32.f1);
    CPy_INCREF(cpy_r_r32.f2);
CPyL27: ;
    CPy_RestoreExcInfo(cpy_r_r32);
    CPy_DecRef(cpy_r_r32.f0);
    CPy_DecRef(cpy_r_r32.f1);
    CPy_DecRef(cpy_r_r32.f2);
    goto CPyL16;
CPyL28: ;
    cpy_r_r22 = cpy_r_r1;
    cpy_r_r33 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__1;
    if (unlikely(cpy_r_r33.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__1", -1, CPyStatic_balances___globals);
        goto CPyL150;
    }
    CPy_INCREF(cpy_r_r33.f0);
    CPy_INCREF(cpy_r_r33.f1);
    CPy_INCREF(cpy_r_r33.f2);
CPyL29: ;
    CPy_RestoreExcInfo(cpy_r_r33);
    CPy_DecRef(cpy_r_r33.f0);
    CPy_DecRef(cpy_r_r33.f1);
    CPy_DecRef(cpy_r_r33.f2);
    goto CPyL38;
CPyL30: ;
    cpy_r_r34 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__1;
    if (unlikely(cpy_r_r34.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__1", -1, CPyStatic_balances___globals);
        goto CPyL39;
    }
    CPy_INCREF(cpy_r_r34.f0);
    CPy_INCREF(cpy_r_r34.f1);
    CPy_INCREF(cpy_r_r34.f2);
CPyL31: ;
    CPy_RestoreExcInfo(cpy_r_r34);
    CPy_DecRef(cpy_r_r34.f0);
    CPy_DecRef(cpy_r_r34.f1);
    CPy_DecRef(cpy_r_r34.f2);
    cpy_r_r35 = CPy_KeepPropagating();
    if (!cpy_r_r35) {
        goto CPyL39;
    } else
        goto CPyL151;
CPyL32: ;
    CPy_Unreachable();
CPyL33: ;
    cpy_r_r36 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__0;
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__0", -1, CPyStatic_balances___globals);
        goto CPyL152;
    }
    CPy_INCREF(cpy_r_r36);
CPyL34: ;
    cpy_r_r37 = CPyIter_Send(cpy_r_r36, cpy_r_arg);
    CPy_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r37 == NULL) goto CPyL153;
    cpy_r_r23 = cpy_r_r37;
    goto CPyL16;
CPyL36: ;
    cpy_r_r38 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 45, CPyStatic_balances___globals);
        goto CPyL39;
    }
    cpy_r_r22 = cpy_r_r38;
CPyL38: ;
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_balance != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_balance);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_balance = cpy_r_r22;
    cpy_r_r39 = 1;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 45, CPyStatic_balances___globals);
    } else
        goto CPyL58;
CPyL39: ;
    cpy_r_r40 = CPy_CatchError();
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__2.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__2.f0);
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__2.f1);
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__2.f2);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__2 = cpy_r_r40;
    cpy_r_r41 = 1;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", -1, CPyStatic_balances___globals);
        goto CPyL154;
    }
    cpy_r_r42 = CPyModule_y;
    cpy_r_r43 = CPyStatics[66]; /* 'NonStandardERC20' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_r42, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 46, CPyStatic_balances___globals);
        goto CPyL154;
    }
    cpy_r_r45 = CPy_ExceptionMatches(cpy_r_r44);
    CPy_DecRef(cpy_r_r44);
    if (!cpy_r_r45) goto CPyL155;
    cpy_r_r46 = CPyStatics[67]; /* 'NonStandardERC20 exc for %s' */
    cpy_r_r47 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_token;
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "token", 47, CPyStatic_balances___globals);
        goto CPyL154;
    }
    CPy_INCREF(cpy_r_r47);
CPyL43: ;
    cpy_r_r48 = CPyStatic_balances___log_warning;
    if (unlikely(cpy_r_r48 == NULL)) {
        goto CPyL156;
    } else
        goto CPyL46;
CPyL44: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"log_warning\" was not set");
    cpy_r_r49 = 0;
    if (unlikely(!cpy_r_r49)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 47, CPyStatic_balances___globals);
        goto CPyL55;
    } else
        goto CPyL157;
CPyL45: ;
    CPy_Unreachable();
CPyL46: ;
    PyObject *cpy_r_r50[2] = {cpy_r_r46, cpy_r_r47};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = PyObject_Vectorcall(cpy_r_r48, cpy_r_r51, 2, 0);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 47, CPyStatic_balances___globals);
        goto CPyL158;
    } else
        goto CPyL159;
CPyL47: ;
    CPy_DecRef(cpy_r_r47);
    cpy_r_r53 = CPyStatic_balances____ZERO;
    if (unlikely(cpy_r_r53 == NULL)) {
        goto CPyL160;
    } else
        goto CPyL50;
CPyL48: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_ZERO\" was not set");
    cpy_r_r54 = 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 48, CPyStatic_balances___globals);
        goto CPyL55;
    } else
        goto CPyL161;
CPyL49: ;
    CPy_Unreachable();
CPyL50: ;
    CPy_INCREF(cpy_r_r53);
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_balance != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_balance);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_balance = cpy_r_r53;
    cpy_r_r55 = 1;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 48, CPyStatic_balances___globals);
        goto CPyL154;
    } else
        goto CPyL53;
CPyL51: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL55;
    } else
        goto CPyL162;
CPyL52: ;
    CPy_Unreachable();
CPyL53: ;
    cpy_r_r56 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__2;
    if (unlikely(cpy_r_r56.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__2", -1, CPyStatic_balances___globals);
        goto CPyL163;
    }
    CPy_INCREF(cpy_r_r56.f0);
    CPy_INCREF(cpy_r_r56.f1);
    CPy_INCREF(cpy_r_r56.f2);
CPyL54: ;
    CPy_RestoreExcInfo(cpy_r_r56);
    CPy_DecRef(cpy_r_r56.f0);
    CPy_DecRef(cpy_r_r56.f1);
    CPy_DecRef(cpy_r_r56.f2);
    goto CPyL58;
CPyL55: ;
    cpy_r_r57 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__2;
    if (unlikely(cpy_r_r57.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__2' of 'load_token_balance_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r57.f0);
        CPy_INCREF(cpy_r_r57.f1);
        CPy_INCREF(cpy_r_r57.f2);
    }
    CPy_DecRef(cpy_r_r4);
    if (unlikely(cpy_r_r57.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", -1, CPyStatic_balances___globals);
        goto CPyL136;
    }
CPyL56: ;
    CPy_RestoreExcInfo(cpy_r_r57);
    CPy_DecRef(cpy_r_r57.f0);
    CPy_DecRef(cpy_r_r57.f1);
    CPy_DecRef(cpy_r_r57.f2);
    cpy_r_r58 = CPy_KeepPropagating();
    if (!cpy_r_r58) goto CPyL136;
    CPy_Unreachable();
CPyL58: ;
    cpy_r_r59 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_token;
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "token", 49, CPyStatic_balances___globals);
        goto CPyL163;
    }
    CPy_INCREF(cpy_r_r59);
CPyL59: ;
    cpy_r_r60 = CPyStatics[68]; /* 'address' */
    cpy_r_r61 = CPyObject_GetAttr(cpy_r_r59, cpy_r_r60);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 49, CPyStatic_balances___globals);
        goto CPyL163;
    }
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_token_address != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_token_address);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_token_address = cpy_r_r61;
    cpy_r_r62 = 1;
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 49, CPyStatic_balances___globals);
        goto CPyL163;
    }
    cpy_r_r63 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_balance;
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "balance", 50, CPyStatic_balances___globals);
        goto CPyL163;
    }
    CPy_INCREF(cpy_r_r63);
CPyL62: ;
    cpy_r_r64 = PyObject_IsTrue(cpy_r_r63);
    CPy_DECREF(cpy_r_r63);
    cpy_r_r65 = cpy_r_r64 >= 0;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 50, CPyStatic_balances___globals);
        goto CPyL163;
    }
    cpy_r_r66 = cpy_r_r64;
    if (cpy_r_r66) {
        goto CPyL71;
    } else
        goto CPyL164;
CPyL64: ;
    cpy_r_r67 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_token_address;
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "token_address", 51, CPyStatic_balances___globals);
        goto CPyL165;
    }
    CPy_INCREF(cpy_r_r67);
CPyL65: ;
    cpy_r_r68 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_block;
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "block", 51, CPyStatic_balances___globals);
        goto CPyL166;
    }
    CPy_INCREF(cpy_r_r68);
CPyL66: ;
    cpy_r_r69 = CPyStatic_balances___globals;
    cpy_r_r70 = CPyStatics[69]; /* 'Balance' */
    cpy_r_r71 = CPyDict_GetItem(cpy_r_r69, cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 51, CPyStatic_balances___globals);
        goto CPyL167;
    }
    PyObject *cpy_r_r72[2] = {cpy_r_r67, cpy_r_r68};
    cpy_r_r73 = (PyObject **)&cpy_r_r72;
    cpy_r_r74 = CPyStatics[432]; /* ('token', 'block') */
    cpy_r_r75 = PyObject_Vectorcall(cpy_r_r71, cpy_r_r73, 0, cpy_r_r74);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 51, CPyStatic_balances___globals);
        goto CPyL167;
    }
    CPy_DECREF(cpy_r_r67);
    CPy_DECREF(cpy_r_r68);
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__ = -2;
    cpy_r_r76 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r4);
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 51, CPyStatic_balances___globals);
        goto CPyL168;
    }
    CPyGen_SetStopIterationValue(cpy_r_r75);
    CPy_DECREF(cpy_r_r75);
    if (!0) goto CPyL136;
    CPy_Unreachable();
CPyL71: ;
    cpy_r_r77 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_token_address;
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "token_address", 52, CPyStatic_balances___globals);
        goto CPyL163;
    }
    CPy_INCREF(cpy_r_r77);
CPyL72: ;
    cpy_r_r78 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_block;
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "block", 52, CPyStatic_balances___globals);
        goto CPyL169;
    }
    CPy_INCREF(cpy_r_r78);
CPyL73: ;
    cpy_r_r79 = CPyStatic_balances___globals;
    cpy_r_r80 = CPyStatics[71]; /* '_get_price' */
    cpy_r_r81 = CPyDict_GetItem(cpy_r_r79, cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 52, CPyStatic_balances___globals);
        goto CPyL170;
    }
    PyObject *cpy_r_r82[2] = {cpy_r_r77, cpy_r_r78};
    cpy_r_r83 = (PyObject **)&cpy_r_r82;
    cpy_r_r84 = PyObject_Vectorcall(cpy_r_r81, cpy_r_r83, 2, 0);
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 52, CPyStatic_balances___globals);
        goto CPyL170;
    }
    CPy_DECREF(cpy_r_r77);
    CPy_DECREF(cpy_r_r78);
    cpy_r_r85 = CPy_GetCoro(cpy_r_r84);
    CPy_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 52, CPyStatic_balances___globals);
        goto CPyL163;
    }
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__3 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__3);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__3 = cpy_r_r85;
    cpy_r_r86 = 1;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", -1, CPyStatic_balances___globals);
        goto CPyL163;
    }
    cpy_r_r87 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__3;
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__3", -1, CPyStatic_balances___globals);
        goto CPyL163;
    }
    CPy_INCREF(cpy_r_r87);
CPyL78: ;
    cpy_r_r88 = CPyIter_Next(cpy_r_r87);
    CPy_DECREF(cpy_r_r87);
    if (cpy_r_r88 == NULL) {
        goto CPyL171;
    } else
        goto CPyL81;
CPyL79: ;
    cpy_r_r89 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 52, CPyStatic_balances___globals);
        goto CPyL165;
    }
    cpy_r_r90 = cpy_r_r89;
    goto CPyL104;
CPyL81: ;
    cpy_r_r91 = cpy_r_r88;
CPyL82: ;
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__ = 4;
    cpy_r_r92 = 1;
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 52, CPyStatic_balances___globals);
        goto CPyL172;
    } else
        goto CPyL173;
CPyL83: ;
    return cpy_r_r91;
CPyL84: ;
    cpy_r_r93 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r94 = cpy_r_type != cpy_r_r93;
    if (!cpy_r_r94) goto CPyL87;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 52, CPyStatic_balances___globals);
        goto CPyL88;
    } else
        goto CPyL174;
CPyL86: ;
    CPy_Unreachable();
CPyL87: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL99;
CPyL88: ;
    cpy_r_r95 = CPy_CatchError();
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__4.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__4.f0);
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__4.f1);
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__4.f2);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__4 = cpy_r_r95;
    cpy_r_r96 = 1;
    if (unlikely(!cpy_r_r96)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", -1, CPyStatic_balances___globals);
        goto CPyL175;
    }
    cpy_r_r97 = (PyObject **)&cpy_r_r3;
    cpy_r_r98 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__3;
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__3", -1, CPyStatic_balances___globals);
        goto CPyL175;
    }
    CPy_INCREF(cpy_r_r98);
CPyL90: ;
    cpy_r_r99 = CPy_YieldFromErrorHandle(cpy_r_r98, cpy_r_r97);
    CPy_DecRef(cpy_r_r98);
    if (unlikely(cpy_r_r99 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 52, CPyStatic_balances___globals);
        goto CPyL175;
    }
    if (cpy_r_r99) goto CPyL94;
    CPy_INCREF(cpy_r_r3);
    cpy_r_r91 = cpy_r_r3;
    cpy_r_r100 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__4;
    if (unlikely(cpy_r_r100.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__4", -1, CPyStatic_balances___globals);
        goto CPyL176;
    }
    CPy_INCREF(cpy_r_r100.f0);
    CPy_INCREF(cpy_r_r100.f1);
    CPy_INCREF(cpy_r_r100.f2);
CPyL93: ;
    CPy_RestoreExcInfo(cpy_r_r100);
    CPy_DecRef(cpy_r_r100.f0);
    CPy_DecRef(cpy_r_r100.f1);
    CPy_DecRef(cpy_r_r100.f2);
    goto CPyL82;
CPyL94: ;
    cpy_r_r90 = cpy_r_r3;
    cpy_r_r101 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__4;
    if (unlikely(cpy_r_r101.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__4", -1, CPyStatic_balances___globals);
        goto CPyL177;
    }
    CPy_INCREF(cpy_r_r101.f0);
    CPy_INCREF(cpy_r_r101.f1);
    CPy_INCREF(cpy_r_r101.f2);
CPyL95: ;
    CPy_RestoreExcInfo(cpy_r_r101);
    CPy_DecRef(cpy_r_r101.f0);
    CPy_DecRef(cpy_r_r101.f1);
    CPy_DecRef(cpy_r_r101.f2);
    goto CPyL104;
CPyL96: ;
    cpy_r_r102 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__4;
    if (unlikely(cpy_r_r102.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__4' of 'load_token_balance_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r102.f0);
        CPy_INCREF(cpy_r_r102.f1);
        CPy_INCREF(cpy_r_r102.f2);
    }
    CPy_DecRef(cpy_r_r4);
    if (unlikely(cpy_r_r102.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", -1, CPyStatic_balances___globals);
        goto CPyL136;
    }
CPyL97: ;
    CPy_RestoreExcInfo(cpy_r_r102);
    CPy_DecRef(cpy_r_r102.f0);
    CPy_DecRef(cpy_r_r102.f1);
    CPy_DecRef(cpy_r_r102.f2);
    cpy_r_r103 = CPy_KeepPropagating();
    if (!cpy_r_r103) goto CPyL136;
    CPy_Unreachable();
CPyL99: ;
    cpy_r_r104 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_temp__3;
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "__mypyc_temp__3", -1, CPyStatic_balances___globals);
        goto CPyL178;
    }
    CPy_INCREF(cpy_r_r104);
CPyL100: ;
    cpy_r_r105 = CPyIter_Send(cpy_r_r104, cpy_r_arg);
    CPy_DECREF(cpy_r_r104);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r105 == NULL) goto CPyL179;
    cpy_r_r91 = cpy_r_r105;
    goto CPyL82;
CPyL102: ;
    cpy_r_r106 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 52, CPyStatic_balances___globals);
        goto CPyL165;
    }
    cpy_r_r90 = cpy_r_r106;
CPyL104: ;
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_price != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_price);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_price = cpy_r_r90;
    cpy_r_r107 = 1;
    if (unlikely(!cpy_r_r107)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 52, CPyStatic_balances___globals);
        goto CPyL165;
    }
    cpy_r_r108 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_balance;
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "balance", 54, CPyStatic_balances___globals);
        goto CPyL165;
    }
    CPy_INCREF(cpy_r_r108);
CPyL106: ;
    cpy_r_r109 = CPyModule_builtins;
    cpy_r_r110 = CPyStatics[72]; /* 'round' */
    cpy_r_r111 = CPyObject_GetAttr(cpy_r_r109, cpy_r_r110);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 54, CPyStatic_balances___globals);
        goto CPyL180;
    }
    cpy_r_r112 = CPyStatics[413]; /* 18 */
    PyObject *cpy_r_r113[2] = {cpy_r_r108, cpy_r_r112};
    cpy_r_r114 = (PyObject **)&cpy_r_r113;
    cpy_r_r115 = PyObject_Vectorcall(cpy_r_r111, cpy_r_r114, 2, 0);
    CPy_DECREF(cpy_r_r111);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 54, CPyStatic_balances___globals);
        goto CPyL180;
    }
    CPy_DECREF(cpy_r_r108);
    cpy_r_r116 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_price;
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "price", 55, CPyStatic_balances___globals);
        goto CPyL181;
    }
    CPy_INCREF(cpy_r_r116);
CPyL109: ;
    cpy_r_r117 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r118 = cpy_r_r116 == cpy_r_r117;
    CPy_DECREF(cpy_r_r116);
    if (!cpy_r_r118) goto CPyL114;
    cpy_r_r119 = CPyStatic_balances____ZERO;
    if (unlikely(cpy_r_r119 == NULL)) {
        goto CPyL182;
    } else
        goto CPyL113;
CPyL111: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"_ZERO\" was not set");
    cpy_r_r120 = 0;
    if (unlikely(!cpy_r_r120)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 55, CPyStatic_balances___globals);
        goto CPyL136;
    }
    CPy_Unreachable();
CPyL113: ;
    CPy_INCREF(cpy_r_r119);
    cpy_r_r121 = cpy_r_r119;
    goto CPyL124;
CPyL114: ;
    cpy_r_r122 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_balance;
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "balance", 55, CPyStatic_balances___globals);
        goto CPyL181;
    }
    CPy_INCREF(cpy_r_r122);
CPyL115: ;
    cpy_r_r123 = CPyStatic_balances___globals;
    cpy_r_r124 = CPyStatics[73]; /* 'Decimal' */
    cpy_r_r125 = CPyDict_GetItem(cpy_r_r123, cpy_r_r124);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 55, CPyStatic_balances___globals);
        goto CPyL183;
    }
    PyObject *cpy_r_r126[1] = {cpy_r_r122};
    cpy_r_r127 = (PyObject **)&cpy_r_r126;
    cpy_r_r128 = PyObject_Vectorcall(cpy_r_r125, cpy_r_r127, 1, 0);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 55, CPyStatic_balances___globals);
        goto CPyL183;
    }
    CPy_DECREF(cpy_r_r122);
    cpy_r_r129 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_price;
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "price", 55, CPyStatic_balances___globals);
        goto CPyL184;
    }
    CPy_INCREF(cpy_r_r129);
CPyL118: ;
    cpy_r_r130 = CPyStatic_balances___globals;
    cpy_r_r131 = CPyStatics[73]; /* 'Decimal' */
    cpy_r_r132 = CPyDict_GetItem(cpy_r_r130, cpy_r_r131);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 55, CPyStatic_balances___globals);
        goto CPyL185;
    }
    PyObject *cpy_r_r133[1] = {cpy_r_r129};
    cpy_r_r134 = (PyObject **)&cpy_r_r133;
    cpy_r_r135 = PyObject_Vectorcall(cpy_r_r132, cpy_r_r134, 1, 0);
    CPy_DECREF(cpy_r_r132);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 55, CPyStatic_balances___globals);
        goto CPyL185;
    }
    CPy_DECREF(cpy_r_r129);
    cpy_r_r136 = PyNumber_Multiply(cpy_r_r128, cpy_r_r135);
    CPy_DECREF(cpy_r_r128);
    CPy_DECREF(cpy_r_r135);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 55, CPyStatic_balances___globals);
        goto CPyL181;
    }
    cpy_r_r137 = CPyModule_builtins;
    cpy_r_r138 = CPyStatics[72]; /* 'round' */
    cpy_r_r139 = CPyObject_GetAttr(cpy_r_r137, cpy_r_r138);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 55, CPyStatic_balances___globals);
        goto CPyL186;
    }
    cpy_r_r140 = CPyStatics[413]; /* 18 */
    PyObject *cpy_r_r141[2] = {cpy_r_r136, cpy_r_r140};
    cpy_r_r142 = (PyObject **)&cpy_r_r141;
    cpy_r_r143 = PyObject_Vectorcall(cpy_r_r139, cpy_r_r142, 2, 0);
    CPy_DECREF(cpy_r_r139);
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 55, CPyStatic_balances___globals);
        goto CPyL186;
    }
    CPy_DECREF(cpy_r_r136);
    cpy_r_r121 = cpy_r_r143;
CPyL124: ;
    cpy_r_r144 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_token_address;
    if (unlikely(cpy_r_r144 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "token_address", 56, CPyStatic_balances___globals);
        goto CPyL187;
    }
    CPy_INCREF(cpy_r_r144);
CPyL125: ;
    cpy_r_r145 = ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->_block;
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/balances.py", "load_token_balance", "load_token_balance_env", "block", 57, CPyStatic_balances___globals);
        goto CPyL188;
    }
    CPy_INCREF(cpy_r_r145);
CPyL126: ;
    cpy_r_r146 = CPyStatic_balances___globals;
    cpy_r_r147 = CPyStatics[69]; /* 'Balance' */
    cpy_r_r148 = CPyDict_GetItem(cpy_r_r146, cpy_r_r147);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 53, CPyStatic_balances___globals);
        goto CPyL189;
    }
    PyObject *cpy_r_r149[4] = {cpy_r_r115, cpy_r_r121, cpy_r_r144, cpy_r_r145};
    cpy_r_r150 = (PyObject **)&cpy_r_r149;
    cpy_r_r151 = CPyStatics[433]; /* ('balance', 'usd_value', 'token', 'block') */
    cpy_r_r152 = PyObject_Vectorcall(cpy_r_r148, cpy_r_r150, 0, cpy_r_r151);
    CPy_DECREF(cpy_r_r148);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 53, CPyStatic_balances___globals);
        goto CPyL189;
    }
    CPy_DECREF(cpy_r_r115);
    CPy_DECREF(cpy_r_r121);
    CPy_DECREF(cpy_r_r144);
    CPy_DECREF(cpy_r_r145);
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r4)->___mypyc_next_label__ = -2;
    cpy_r_r153 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r4);
    if (unlikely(!cpy_r_r153)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 53, CPyStatic_balances___globals);
        goto CPyL190;
    }
    CPyGen_SetStopIterationValue(cpy_r_r152);
    CPy_DECREF(cpy_r_r152);
    if (!0) goto CPyL136;
    CPy_Unreachable();
CPyL131: ;
    cpy_r_r154 = cpy_r_r5 == 0;
    if (cpy_r_r154) goto CPyL191;
    cpy_r_r155 = cpy_r_r5 == 2;
    if (cpy_r_r155) {
        goto CPyL192;
    } else
        goto CPyL193;
CPyL133: ;
    cpy_r_r156 = cpy_r_r5 == 4;
    CPyTagged_DECREF(cpy_r_r5);
    if (cpy_r_r156) {
        goto CPyL84;
    } else
        goto CPyL194;
CPyL134: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r157 = 0;
    if (unlikely(!cpy_r_r157)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
        goto CPyL136;
    }
    CPy_Unreachable();
CPyL136: ;
    cpy_r_r158 = NULL;
    return cpy_r_r158;
CPyL137: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    goto CPyL136;
CPyL138: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL136;
CPyL139: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF_NO_IMM(cpy_r_r4);
    goto CPyL3;
CPyL140: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL39;
CPyL141: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r8);
    goto CPyL39;
CPyL142: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    goto CPyL39;
CPyL143: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    goto CPyL39;
CPyL144: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL13;
CPyL145: ;
    CPy_DecRef(cpy_r_r23);
    goto CPyL22;
CPyL146: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF_NO_IMM(cpy_r_r4);
    goto CPyL17;
CPyL147: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF_NO_IMM(cpy_r_r4);
    goto CPyL20;
CPyL148: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL30;
CPyL149: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r23);
    goto CPyL30;
CPyL150: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL30;
CPyL151: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL32;
CPyL152: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_arg);
    goto CPyL39;
CPyL153: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL36;
CPyL154: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL55;
CPyL155: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL51;
CPyL156: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r47);
    goto CPyL44;
CPyL157: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL45;
CPyL158: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r47);
    goto CPyL55;
CPyL159: ;
    CPy_DecRef(cpy_r_r52);
    goto CPyL47;
CPyL160: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL48;
CPyL161: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL49;
CPyL162: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL52;
CPyL163: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL136;
CPyL164: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL64;
CPyL165: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL136;
CPyL166: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r67);
    goto CPyL136;
CPyL167: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r67);
    CPy_DecRef(cpy_r_r68);
    goto CPyL136;
CPyL168: ;
    CPy_DecRef(cpy_r_r75);
    goto CPyL136;
CPyL169: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r77);
    goto CPyL136;
CPyL170: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r78);
    goto CPyL136;
CPyL171: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL79;
CPyL172: ;
    CPy_DecRef(cpy_r_r91);
    goto CPyL88;
CPyL173: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF_NO_IMM(cpy_r_r4);
    goto CPyL83;
CPyL174: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF_NO_IMM(cpy_r_r4);
    goto CPyL86;
CPyL175: ;
    CPy_XDecRef(cpy_r_r3);
    goto CPyL96;
CPyL176: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r91);
    goto CPyL96;
CPyL177: ;
    CPy_DecRef(cpy_r_r90);
    goto CPyL96;
CPyL178: ;
    CPy_XDecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_arg);
    goto CPyL136;
CPyL179: ;
    CPy_XDECREF(cpy_r_r3);
    goto CPyL102;
CPyL180: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r108);
    goto CPyL136;
CPyL181: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r115);
    goto CPyL136;
CPyL182: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r115);
    goto CPyL111;
CPyL183: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r122);
    goto CPyL136;
CPyL184: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r128);
    goto CPyL136;
CPyL185: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r128);
    CPy_DecRef(cpy_r_r129);
    goto CPyL136;
CPyL186: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r136);
    goto CPyL136;
CPyL187: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r121);
    goto CPyL136;
CPyL188: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r121);
    CPy_DecRef(cpy_r_r144);
    goto CPyL136;
CPyL189: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r115);
    CPy_DecRef(cpy_r_r121);
    CPy_DecRef(cpy_r_r144);
    CPy_DecRef(cpy_r_r145);
    goto CPyL136;
CPyL190: ;
    CPy_DecRef(cpy_r_r152);
    goto CPyL136;
CPyL191: ;
    CPyTagged_DECREF(cpy_r_r5);
    goto CPyL2;
CPyL192: ;
    CPyTagged_DECREF(cpy_r_r5);
    goto CPyL18;
CPyL193: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL133;
CPyL194: ;
    CPy_XDECREF(cpy_r_r3);
    CPy_DECREF_NO_IMM(cpy_r_r4);
    goto CPyL134;
}

PyObject *CPyPy_balances___load_token_balance_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", "arg", 0};
    static CPyArg_Parser parser = {"OOOO:__mypyc_generator_helper__", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value;
    PyObject *obj_traceback;
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_type = obj_type;
    PyObject *arg_value = obj_value;
    PyObject *arg_traceback = obj_traceback;
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_balances___load_token_balance_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
    return NULL;
}

PyObject *CPyDef_balances___load_token_balance_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_balances___load_token_balance_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_balances___load_token_balance_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_balances___load_token_balance_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.balances.load_token_balance_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_balances___load_token_balance_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "__next__", -1, CPyStatic_balances___globals);
    return NULL;
}

PyObject *CPyDef_balances___load_token_balance_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_balances___load_token_balance_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_balances___load_token_balance_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_balances___load_token_balance_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.balances.load_token_balance_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_balances___load_token_balance_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "send", -1, CPyStatic_balances___globals);
    return NULL;
}

PyObject *CPyDef_balances___load_token_balance_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_balances___load_token_balance_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_balances___load_token_balance_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.balances.load_token_balance_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_balances___load_token_balance_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "__iter__", -1, CPyStatic_balances___globals);
    return NULL;
}

PyObject *CPyDef_balances___load_token_balance_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef_balances___load_token_balance_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy_balances___load_token_balance_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_balances___load_token_balance_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.balances.load_token_balance_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef_balances___load_token_balance_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "throw", -1, CPyStatic_balances___globals);
    return NULL;
}

PyObject *CPyDef_balances___load_token_balance_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[10]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_balances___load_token_balance_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[11]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp38 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp38);
    PyObject *__tmp39 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp39);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy_balances___load_token_balance_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_balances___load_token_balance_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.balances.load_token_balance_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_balances___load_token_balance_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "close", -1, CPyStatic_balances___globals);
    return NULL;
}

PyObject *CPyDef_balances___load_token_balance_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_balances___load_token_balance_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_balances___load_token_balance_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.balances.load_token_balance_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_balances___load_token_balance_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "__await__", -1, CPyStatic_balances___globals);
    return NULL;
}

PyObject *CPyDef_balances___load_token_balance(PyObject *cpy_r_token, PyObject *cpy_r_address, PyObject *cpy_r_block) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    cpy_r_r0 = CPyDef_balances___load_token_balance_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_token);
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->_token != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->_token);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->_token = cpy_r_token;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
        goto CPyL9;
    }
    CPy_INCREF(cpy_r_address);
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->_address != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->_address);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->_address = cpy_r_address;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
        goto CPyL9;
    }
    CPy_INCREF(cpy_r_block);
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->_block != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->_block);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->_block = cpy_r_block;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
        goto CPyL9;
    }
    cpy_r_r4 = CPyDef_balances___load_token_balance_gen();
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
        goto CPyL9;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
    if (((eth_portfolio____loaders___balances___load_token_balance_genObject *)cpy_r_r4)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders___balances___load_token_balance_genObject *)cpy_r_r4)->___mypyc_env__);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_genObject *)cpy_r_r4)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
        goto CPyL10;
    }
    if (((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders___balances___load_token_balance_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r6 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
        goto CPyL11;
    }
    return cpy_r_r4;
CPyL8: ;
    cpy_r_r7 = NULL;
    return cpy_r_r7;
CPyL9: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL8;
CPyL10: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    goto CPyL8;
CPyL11: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL8;
}

PyObject *CPyPy_balances___load_token_balance(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"token", "address", "block", 0};
    static CPyArg_Parser parser = {"OOO:load_token_balance", kwlist, 0};
    PyObject *obj_token;
    PyObject *obj_address;
    PyObject *obj_block;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_token, &obj_address, &obj_block)) {
        return NULL;
    }
    PyObject *arg_token = obj_token;
    PyObject *arg_address;
    if (PyUnicode_Check(obj_address))
        arg_address = obj_address;
    else {
        arg_address = NULL;
    }
    if (arg_address != NULL) goto __LL40;
    arg_address = obj_address;
    if (arg_address != NULL) goto __LL40;
    CPy_TypeError("union[str, object]", obj_address); 
    goto fail;
__LL40: ;
    PyObject *arg_block;
    if (PyLong_Check(obj_block))
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL41;
    arg_block = obj_block;
    if (arg_block != NULL) goto __LL41;
    CPy_TypeError("union[int, object]", obj_block); 
    goto fail;
__LL41: ;
    PyObject *retval = CPyDef_balances___load_token_balance(arg_token, arg_address, arg_block);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "load_token_balance", 21, CPyStatic_balances___globals);
    return NULL;
}

char CPyDef_balances_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r23;
    void *cpy_r_r25;
    void *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject **cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    int32_t cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    int32_t cpy_r_r76;
    char cpy_r_r77;
    PyObject *cpy_r_r78;
    char cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    int32_t cpy_r_r84;
    char cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject **cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    int32_t cpy_r_r97;
    char cpy_r_r98;
    char cpy_r_r99;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[22]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", -1, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_logging;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[434]; /* (('logging', 'logging', 'logging'),) */
    cpy_r_r11 = CPyStatic_balances___globals;
    cpy_r_r12 = CPyStatics[76]; /* 'eth_portfolio/_loaders/balances.py' */
    cpy_r_r13 = CPyStatics[26]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL30;
    cpy_r_r15 = CPyStatics[435]; /* ('InvalidOperation',) */
    cpy_r_r16 = CPyStatics[78]; /* 'decimal' */
    cpy_r_r17 = CPyStatic_balances___globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 2, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyModule_decimal = cpy_r_r18;
    CPy_INCREF(CPyModule_decimal);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[436]; /* ('Final',) */
    cpy_r_r20 = CPyStatics[35]; /* 'typing' */
    cpy_r_r21 = CPyStatic_balances___globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 3, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyModule_typing = cpy_r_r22;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = (PyObject **)&CPyModule_y;
    PyObject **cpy_r_r24[1] = {cpy_r_r23};
    cpy_r_r25 = (void *)&cpy_r_r24;
    int64_t cpy_r_r26[1] = {5};
    cpy_r_r27 = (void *)&cpy_r_r26;
    cpy_r_r28 = CPyStatics[438]; /* (('y', 'y', 'y'),) */
    cpy_r_r29 = CPyStatic_balances___globals;
    cpy_r_r30 = CPyStatics[76]; /* 'eth_portfolio/_loaders/balances.py' */
    cpy_r_r31 = CPyStatics[26]; /* '<module>' */
    cpy_r_r32 = CPyImport_ImportMany(cpy_r_r28, cpy_r_r25, cpy_r_r29, cpy_r_r30, cpy_r_r31, cpy_r_r27);
    if (!cpy_r_r32) goto CPyL30;
    cpy_r_r33 = CPyStatics[439]; /* ('stuck_coro_debugger',) */
    cpy_r_r34 = CPyStatics[81]; /* 'y._decorators' */
    cpy_r_r35 = CPyStatic_balances___globals;
    cpy_r_r36 = CPyImport_ImportFromMany(cpy_r_r34, cpy_r_r33, cpy_r_r33, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 6, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyModule_y____decorators = cpy_r_r36;
    CPy_INCREF(CPyModule_y____decorators);
    CPy_DECREF(cpy_r_r36);
    cpy_r_r37 = CPyStatics[440]; /* ('Address', 'Block') */
    cpy_r_r38 = CPyStatics[84]; /* 'y.datatypes' */
    cpy_r_r39 = CPyStatic_balances___globals;
    cpy_r_r40 = CPyImport_ImportFromMany(cpy_r_r38, cpy_r_r37, cpy_r_r37, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 7, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyModule_y___datatypes = cpy_r_r40;
    CPy_INCREF(CPyModule_y___datatypes);
    CPy_DECREF(cpy_r_r40);
    cpy_r_r41 = CPyStatics[441]; /* ('Decimal',) */
    cpy_r_r42 = CPyStatics[85]; /* 'eth_portfolio._decimal' */
    cpy_r_r43 = CPyStatic_balances___globals;
    cpy_r_r44 = CPyImport_ImportFromMany(cpy_r_r42, cpy_r_r41, cpy_r_r41, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 9, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyModule_eth_portfolio____decimal = cpy_r_r44;
    CPy_INCREF(CPyModule_eth_portfolio____decimal);
    CPy_DECREF(cpy_r_r44);
    cpy_r_r45 = CPyStatics[442]; /* ('_get_price',) */
    cpy_r_r46 = CPyStatics[86]; /* 'eth_portfolio._utils' */
    cpy_r_r47 = CPyStatic_balances___globals;
    cpy_r_r48 = CPyImport_ImportFromMany(cpy_r_r46, cpy_r_r45, cpy_r_r45, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 10, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyModule_eth_portfolio____utils = cpy_r_r48;
    CPy_INCREF(CPyModule_eth_portfolio____utils);
    CPy_DECREF(cpy_r_r48);
    cpy_r_r49 = CPyStatics[443]; /* ('Balance',) */
    cpy_r_r50 = CPyStatics[87]; /* 'eth_portfolio.typing' */
    cpy_r_r51 = CPyStatic_balances___globals;
    cpy_r_r52 = CPyImport_ImportFromMany(cpy_r_r50, cpy_r_r49, cpy_r_r49, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 11, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyModule_eth_portfolio___typing = cpy_r_r52;
    CPy_INCREF(CPyModule_eth_portfolio___typing);
    CPy_DECREF(cpy_r_r52);
    cpy_r_r53 = CPyStatic_balances___globals;
    cpy_r_r54 = CPyStatics[73]; /* 'Decimal' */
    cpy_r_r55 = CPyDict_GetItem(cpy_r_r53, cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 14, CPyStatic_balances___globals);
        goto CPyL30;
    }
    cpy_r_r56 = CPyStatics[409]; /* 0 */
    PyObject *cpy_r_r57[1] = {cpy_r_r56};
    cpy_r_r58 = (PyObject **)&cpy_r_r57;
    cpy_r_r59 = PyObject_Vectorcall(cpy_r_r55, cpy_r_r58, 1, 0);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 14, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyStatic_balances____ZERO = cpy_r_r59;
    CPy_INCREF(CPyStatic_balances____ZERO);
    cpy_r_r60 = CPyStatic_balances___globals;
    cpy_r_r61 = CPyStatics[88]; /* '_ZERO' */
    cpy_r_r62 = CPyDict_SetItem(cpy_r_r60, cpy_r_r61, cpy_r_r59);
    CPy_DECREF(cpy_r_r59);
    cpy_r_r63 = cpy_r_r62 >= 0;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 14, CPyStatic_balances___globals);
        goto CPyL30;
    }
    cpy_r_r64 = CPyStatic_balances___globals;
    cpy_r_r65 = CPyStatics[89]; /* '__name__' */
    cpy_r_r66 = CPyDict_GetItem(cpy_r_r64, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 16, CPyStatic_balances___globals);
        goto CPyL30;
    }
    if (likely(PyUnicode_Check(cpy_r_r66)))
        cpy_r_r67 = cpy_r_r66;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_loaders/balances.py", "<module>", 16, CPyStatic_balances___globals, "str", cpy_r_r66);
        goto CPyL30;
    }
    cpy_r_r68 = CPyModule_logging;
    cpy_r_r69 = CPyStatics[44]; /* 'getLogger' */
    cpy_r_r70 = CPyObject_GetAttr(cpy_r_r68, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 16, CPyStatic_balances___globals);
        goto CPyL31;
    }
    PyObject *cpy_r_r71[1] = {cpy_r_r67};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = PyObject_Vectorcall(cpy_r_r70, cpy_r_r72, 1, 0);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 16, CPyStatic_balances___globals);
        goto CPyL31;
    }
    CPy_DECREF(cpy_r_r67);
    CPyStatic_balances___logger = cpy_r_r73;
    CPy_INCREF(CPyStatic_balances___logger);
    cpy_r_r74 = CPyStatic_balances___globals;
    cpy_r_r75 = CPyStatics[45]; /* 'logger' */
    cpy_r_r76 = CPyDict_SetItem(cpy_r_r74, cpy_r_r75, cpy_r_r73);
    CPy_DECREF(cpy_r_r73);
    cpy_r_r77 = cpy_r_r76 >= 0;
    if (unlikely(!cpy_r_r77)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 16, CPyStatic_balances___globals);
        goto CPyL30;
    }
    cpy_r_r78 = CPyStatic_balances___logger;
    if (likely(cpy_r_r78 != NULL)) goto CPyL23;
    PyErr_SetString(PyExc_NameError, "value for final name \"logger\" was not set");
    cpy_r_r79 = 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 17, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPy_Unreachable();
CPyL23: ;
    cpy_r_r80 = CPyStatics[90]; /* 'warning' */
    cpy_r_r81 = CPyObject_GetAttr(cpy_r_r78, cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 17, CPyStatic_balances___globals);
        goto CPyL30;
    }
    CPyStatic_balances___log_warning = cpy_r_r81;
    CPy_INCREF(CPyStatic_balances___log_warning);
    cpy_r_r82 = CPyStatic_balances___globals;
    cpy_r_r83 = CPyStatics[91]; /* 'log_warning' */
    cpy_r_r84 = CPyDict_SetItem(cpy_r_r82, cpy_r_r83, cpy_r_r81);
    CPy_DECREF(cpy_r_r81);
    cpy_r_r85 = cpy_r_r84 >= 0;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 17, CPyStatic_balances___globals);
        goto CPyL30;
    }
    cpy_r_r86 = CPyStatic_balances___globals;
    cpy_r_r87 = CPyStatics[92]; /* 'load_token_balance' */
    cpy_r_r88 = CPyDict_GetItem(cpy_r_r86, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 20, CPyStatic_balances___globals);
        goto CPyL30;
    }
    cpy_r_r89 = CPyStatic_balances___globals;
    cpy_r_r90 = CPyStatics[80]; /* 'stuck_coro_debugger' */
    cpy_r_r91 = CPyDict_GetItem(cpy_r_r89, cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 20, CPyStatic_balances___globals);
        goto CPyL32;
    }
    PyObject *cpy_r_r92[1] = {cpy_r_r88};
    cpy_r_r93 = (PyObject **)&cpy_r_r92;
    cpy_r_r94 = PyObject_Vectorcall(cpy_r_r91, cpy_r_r93, 1, 0);
    CPy_DECREF(cpy_r_r91);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 20, CPyStatic_balances___globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_r88);
    cpy_r_r95 = CPyStatic_balances___globals;
    cpy_r_r96 = CPyStatics[92]; /* 'load_token_balance' */
    cpy_r_r97 = CPyDict_SetItem(cpy_r_r95, cpy_r_r96, cpy_r_r94);
    CPy_DECREF(cpy_r_r94);
    cpy_r_r98 = cpy_r_r97 >= 0;
    if (unlikely(!cpy_r_r98)) {
        CPy_AddTraceback("eth_portfolio/_loaders/balances.py", "<module>", 20, CPyStatic_balances___globals);
        goto CPyL30;
    }
    return 1;
CPyL30: ;
    cpy_r_r99 = 2;
    return cpy_r_r99;
CPyL31: ;
    CPy_DecRef(cpy_r_r67);
    goto CPyL30;
CPyL32: ;
    CPy_DecRef(cpy_r_r88);
    goto CPyL30;
}

static PyObject *utils____get_transaction_receipt_env_setup(PyTypeObject *type);
PyObject *CPyDef_utils____get_transaction_receipt_env(void);

static PyObject *
utils____get_transaction_receipt_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_utils____get_transaction_receipt_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return utils____get_transaction_receipt_env_setup(type);
}

static int
utils____get_transaction_receipt_env_traverse(eth_portfolio____loaders___utils____get_transaction_receipt_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_txhash);
    Py_VISIT(self->_type);
    Py_VISIT(self->_value);
    Py_VISIT(self->_traceback);
    Py_VISIT(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        Py_VISIT(CPyTagged_LongAsObject(self->___mypyc_next_label__));
    }
    Py_VISIT(self->___mypyc_temp__0);
    Py_VISIT(self->___mypyc_temp__1.f0);
    Py_VISIT(self->___mypyc_temp__1.f1);
    Py_VISIT(self->___mypyc_temp__1.f2);
    return 0;
}

static int
utils____get_transaction_receipt_env_clear(eth_portfolio____loaders___utils____get_transaction_receipt_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_txhash);
    Py_CLEAR(self->_type);
    Py_CLEAR(self->_value);
    Py_CLEAR(self->_traceback);
    Py_CLEAR(self->_arg);
    if (CPyTagged_CheckLong(self->___mypyc_next_label__)) {
        CPyTagged __tmp = self->___mypyc_next_label__;
        self->___mypyc_next_label__ = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->___mypyc_temp__0);
    Py_CLEAR(self->___mypyc_temp__1.f0);
    Py_CLEAR(self->___mypyc_temp__1.f1);
    Py_CLEAR(self->___mypyc_temp__1.f2);
    return 0;
}

static void
utils____get_transaction_receipt_env_dealloc(eth_portfolio____loaders___utils____get_transaction_receipt_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, utils____get_transaction_receipt_env_dealloc)
    utils____get_transaction_receipt_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem utils____get_transaction_receipt_env_vtable[1];
static bool
CPyDef_utils____get_transaction_receipt_env_trait_vtable_setup(void)
{
    CPyVTableItem utils____get_transaction_receipt_env_vtable_scratch[] = {
        NULL
    };
    memcpy(utils____get_transaction_receipt_env_vtable, utils____get_transaction_receipt_env_vtable_scratch, sizeof(utils____get_transaction_receipt_env_vtable));
    return 1;
}

static PyMethodDef utils____get_transaction_receipt_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_utils____get_transaction_receipt_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_get_transaction_receipt_env",
    .tp_new = utils____get_transaction_receipt_env_new,
    .tp_dealloc = (destructor)utils____get_transaction_receipt_env_dealloc,
    .tp_traverse = (traverseproc)utils____get_transaction_receipt_env_traverse,
    .tp_clear = (inquiry)utils____get_transaction_receipt_env_clear,
    .tp_methods = utils____get_transaction_receipt_env_methods,
    .tp_basicsize = sizeof(eth_portfolio____loaders___utils____get_transaction_receipt_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_utils____get_transaction_receipt_env_template = &CPyType_utils____get_transaction_receipt_env_template_;

static PyObject *
utils____get_transaction_receipt_env_setup(PyTypeObject *type)
{
    eth_portfolio____loaders___utils____get_transaction_receipt_envObject *self;
    self = (eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = utils____get_transaction_receipt_env_vtable;
    self->___mypyc_next_label__ = CPY_INT_TAG;
    self->___mypyc_temp__1 = (tuple_T3OOO) { NULL, NULL, NULL };
    return (PyObject *)self;
}

PyObject *CPyDef_utils____get_transaction_receipt_env(void)
{
    PyObject *self = utils____get_transaction_receipt_env_setup(CPyType_utils____get_transaction_receipt_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyAsyncMethods utils____get_transaction_receipt_gen_as_async = {
    .am_await = CPyDef_utils____get_transaction_receipt_gen_____await__,
};
static PyObject *utils____get_transaction_receipt_gen_setup(PyTypeObject *type);
PyObject *CPyDef_utils____get_transaction_receipt_gen(void);

static PyObject *
utils____get_transaction_receipt_gen_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_utils____get_transaction_receipt_gen) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return utils____get_transaction_receipt_gen_setup(type);
}

static int
utils____get_transaction_receipt_gen_traverse(eth_portfolio____loaders___utils____get_transaction_receipt_genObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    return 0;
}

static int
utils____get_transaction_receipt_gen_clear(eth_portfolio____loaders___utils____get_transaction_receipt_genObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    return 0;
}

static void
utils____get_transaction_receipt_gen_dealloc(eth_portfolio____loaders___utils____get_transaction_receipt_genObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, utils____get_transaction_receipt_gen_dealloc)
    utils____get_transaction_receipt_gen_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem utils____get_transaction_receipt_gen_vtable[7];
static bool
CPyDef_utils____get_transaction_receipt_gen_trait_vtable_setup(void)
{
    CPyVTableItem utils____get_transaction_receipt_gen_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_utils____get_transaction_receipt_gen_____mypyc_generator_helper__,
        (CPyVTableItem)CPyDef_utils____get_transaction_receipt_gen_____next__,
        (CPyVTableItem)CPyDef_utils____get_transaction_receipt_gen___send,
        (CPyVTableItem)CPyDef_utils____get_transaction_receipt_gen_____iter__,
        (CPyVTableItem)CPyDef_utils____get_transaction_receipt_gen___throw,
        (CPyVTableItem)CPyDef_utils____get_transaction_receipt_gen___close,
        (CPyVTableItem)CPyDef_utils____get_transaction_receipt_gen_____await__,
    };
    memcpy(utils____get_transaction_receipt_gen_vtable, utils____get_transaction_receipt_gen_vtable_scratch, sizeof(utils____get_transaction_receipt_gen_vtable));
    return 1;
}

static PyMethodDef utils____get_transaction_receipt_gen_methods[] = {
    {"__mypyc_generator_helper__",
     (PyCFunction)CPyPy_utils____get_transaction_receipt_gen_____mypyc_generator_helper__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__next__",
     (PyCFunction)CPyPy_utils____get_transaction_receipt_gen_____next__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"send",
     (PyCFunction)CPyPy_utils____get_transaction_receipt_gen___send,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__iter__",
     (PyCFunction)CPyPy_utils____get_transaction_receipt_gen_____iter__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"throw",
     (PyCFunction)CPyPy_utils____get_transaction_receipt_gen___throw,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"close",
     (PyCFunction)CPyPy_utils____get_transaction_receipt_gen___close,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__await__",
     (PyCFunction)CPyPy_utils____get_transaction_receipt_gen_____await__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_utils____get_transaction_receipt_gen_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_get_transaction_receipt_gen",
    .tp_new = utils____get_transaction_receipt_gen_new,
    .tp_dealloc = (destructor)utils____get_transaction_receipt_gen_dealloc,
    .tp_traverse = (traverseproc)utils____get_transaction_receipt_gen_traverse,
    .tp_clear = (inquiry)utils____get_transaction_receipt_gen_clear,
    .tp_methods = utils____get_transaction_receipt_gen_methods,
    .tp_iter = CPyDef_utils____get_transaction_receipt_gen_____iter__,
    .tp_iternext = CPyDef_utils____get_transaction_receipt_gen_____next__,
    .tp_as_async = &utils____get_transaction_receipt_gen_as_async,
    .tp_basicsize = sizeof(eth_portfolio____loaders___utils____get_transaction_receipt_genObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_utils____get_transaction_receipt_gen_template = &CPyType_utils____get_transaction_receipt_gen_template_;

static PyObject *
utils____get_transaction_receipt_gen_setup(PyTypeObject *type)
{
    eth_portfolio____loaders___utils____get_transaction_receipt_genObject *self;
    self = (eth_portfolio____loaders___utils____get_transaction_receipt_genObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = utils____get_transaction_receipt_gen_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_utils____get_transaction_receipt_gen(void)
{
    PyObject *self = utils____get_transaction_receipt_gen_setup(CPyType_utils____get_transaction_receipt_gen);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef utilsmodule_methods[] = {
    {"_get_transaction_receipt", (PyCFunction)CPyPy_utils____get_transaction_receipt, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef utilsmodule = {
    PyModuleDef_HEAD_INIT,
    "eth_portfolio._loaders.utils",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    utilsmodule_methods
};

PyObject *CPyInit_eth_portfolio____loaders___utils(void)
{
    PyObject* modname = NULL;
    if (CPyModule_eth_portfolio____loaders___utils_internal) {
        Py_INCREF(CPyModule_eth_portfolio____loaders___utils_internal);
        return CPyModule_eth_portfolio____loaders___utils_internal;
    }
    CPyModule_eth_portfolio____loaders___utils_internal = PyModule_Create(&utilsmodule);
    if (unlikely(CPyModule_eth_portfolio____loaders___utils_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_eth_portfolio____loaders___utils_internal, "__name__");
    CPyStatic_utils___globals = PyModule_GetDict(CPyModule_eth_portfolio____loaders___utils_internal);
    if (unlikely(CPyStatic_utils___globals == NULL))
        goto fail;
    CPyType_utils____get_transaction_receipt_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_utils____get_transaction_receipt_env_template, NULL, modname);
    if (unlikely(!CPyType_utils____get_transaction_receipt_env))
        goto fail;
    CPyType_utils____get_transaction_receipt_gen = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_utils____get_transaction_receipt_gen_template, NULL, modname);
    if (unlikely(!CPyType_utils____get_transaction_receipt_gen))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_utils_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_eth_portfolio____loaders___utils_internal;
    fail:
    Py_CLEAR(CPyModule_eth_portfolio____loaders___utils_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_utils___Raw);
    CPyStatic_utils___Raw = NULL;
    CPy_XDECREF(CPyStatic_utils___get_transaction_receipt);
    CPyStatic_utils___get_transaction_receipt = NULL;
    CPy_XDECREF(CPyStatic_utils_____get_transaction_receipt);
    CPyStatic_utils_____get_transaction_receipt = NULL;
    Py_CLEAR(CPyType_utils____get_transaction_receipt_env);
    Py_CLEAR(CPyType_utils____get_transaction_receipt_gen);
    return NULL;
}

PyObject *CPyDef_utils____get_transaction_receipt_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    tuple_T3OOO cpy_r_r26;
    char cpy_r_r27;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    tuple_T3OOO cpy_r_r31;
    tuple_T3OOO cpy_r_r32;
    tuple_T3OOO cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    char cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    cpy_r_r0 = NULL;
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = ((eth_portfolio____loaders___utils____get_transaction_receipt_genObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", "_get_transaction_receipt_gen", "__mypyc_env__", 19, CPyStatic_utils___globals);
        goto CPyL50;
    }
    CPy_INCREF_NO_IMM(cpy_r_r2);
CPyL1: ;
    cpy_r_r3 = ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_next_label__;
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AttributeError("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", "_get_transaction_receipt_env", "__mypyc_next_label__", 19, CPyStatic_utils___globals);
        goto CPyL51;
    }
    CPyTagged_INCREF(cpy_r_r3);
    goto CPyL45;
CPyL2: ;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_type != cpy_r_r4;
    if (cpy_r_r5) {
        goto CPyL52;
    } else
        goto CPyL5;
CPyL3: ;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 19, CPyStatic_utils___globals);
        goto CPyL49;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r6 = ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->_txhash;
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", "_get_transaction_receipt_env", "txhash", 45, CPyStatic_utils___globals);
        goto CPyL51;
    }
    CPy_INCREF(cpy_r_r6);
CPyL6: ;
    cpy_r_r7 = CPyStatic_utils___Raw;
    if (unlikely(cpy_r_r7 == NULL)) {
        goto CPyL53;
    } else
        goto CPyL9;
CPyL7: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"Raw\" was not set");
    cpy_r_r8 = 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL49;
    }
    CPy_Unreachable();
CPyL9: ;
    cpy_r_r9 = CPyStatic_utils_____get_transaction_receipt;
    if (unlikely(cpy_r_r9 == NULL)) {
        goto CPyL54;
    } else
        goto CPyL12;
CPyL10: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"__get_transaction_receipt\" was not set");
    cpy_r_r10 = 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL49;
    }
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r11 = Py_None;
    PyObject *cpy_r_r12[3] = {cpy_r_r6, cpy_r_r7, cpy_r_r11};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = CPyStatics[444]; /* ('decode_to', 'decode_hook') */
    cpy_r_r15 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r13, 1, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL55;
    }
    CPy_DECREF(cpy_r_r6);
    cpy_r_r16 = CPy_GetCoro(cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL51;
    }
    if (((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__0);
    }
    ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__0 = cpy_r_r16;
    cpy_r_r17 = 1;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", -1, CPyStatic_utils___globals);
        goto CPyL51;
    }
    cpy_r_r18 = ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", "_get_transaction_receipt_env", "__mypyc_temp__0", -1, CPyStatic_utils___globals);
        goto CPyL51;
    }
    CPy_INCREF(cpy_r_r18);
CPyL16: ;
    cpy_r_r19 = CPyIter_Next(cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    if (cpy_r_r19 == NULL) {
        goto CPyL56;
    } else
        goto CPyL19;
CPyL17: ;
    cpy_r_r20 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL57;
    }
    cpy_r_r21 = cpy_r_r20;
    goto CPyL42;
CPyL19: ;
    cpy_r_r22 = cpy_r_r19;
CPyL20: ;
    if (((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_next_label__ = 2;
    cpy_r_r23 = 1;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL58;
    } else
        goto CPyL59;
CPyL21: ;
    return cpy_r_r22;
CPyL22: ;
    cpy_r_r24 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r25 = cpy_r_type != cpy_r_r24;
    if (!cpy_r_r25) goto CPyL25;
    CPyErr_SetObjectAndTraceback(cpy_r_type, cpy_r_value, cpy_r_traceback);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL26;
    } else
        goto CPyL60;
CPyL24: ;
    CPy_Unreachable();
CPyL25: ;
    CPy_INCREF(cpy_r_arg);
    goto CPyL37;
CPyL26: ;
    cpy_r_r26 = CPy_CatchError();
    if (((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__1.f0 != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__1.f0);
        CPy_DECREF(((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__1.f1);
        CPy_DECREF(((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__1.f2);
    }
    ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__1 = cpy_r_r26;
    cpy_r_r27 = 1;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", -1, CPyStatic_utils___globals);
        goto CPyL61;
    }
    cpy_r_r28 = (PyObject **)&cpy_r_r1;
    cpy_r_r29 = ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", "_get_transaction_receipt_env", "__mypyc_temp__0", -1, CPyStatic_utils___globals);
        goto CPyL61;
    }
    CPy_INCREF(cpy_r_r29);
CPyL28: ;
    cpy_r_r30 = CPy_YieldFromErrorHandle(cpy_r_r29, cpy_r_r28);
    CPy_DecRef(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL61;
    }
    if (cpy_r_r30) goto CPyL32;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r22 = cpy_r_r1;
    cpy_r_r31 = ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r31.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", "_get_transaction_receipt_env", "__mypyc_temp__1", -1, CPyStatic_utils___globals);
        goto CPyL62;
    }
    CPy_INCREF(cpy_r_r31.f0);
    CPy_INCREF(cpy_r_r31.f1);
    CPy_INCREF(cpy_r_r31.f2);
CPyL31: ;
    CPy_RestoreExcInfo(cpy_r_r31);
    CPy_DecRef(cpy_r_r31.f0);
    CPy_DecRef(cpy_r_r31.f1);
    CPy_DecRef(cpy_r_r31.f2);
    goto CPyL20;
CPyL32: ;
    cpy_r_r21 = cpy_r_r1;
    cpy_r_r32 = ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r32.f0 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", "_get_transaction_receipt_env", "__mypyc_temp__1", -1, CPyStatic_utils___globals);
        goto CPyL63;
    }
    CPy_INCREF(cpy_r_r32.f0);
    CPy_INCREF(cpy_r_r32.f1);
    CPy_INCREF(cpy_r_r32.f2);
CPyL33: ;
    CPy_RestoreExcInfo(cpy_r_r32);
    CPy_DecRef(cpy_r_r32.f0);
    CPy_DecRef(cpy_r_r32.f1);
    CPy_DecRef(cpy_r_r32.f2);
    goto CPyL42;
CPyL34: ;
    cpy_r_r33 = ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__1;
    if (unlikely(cpy_r_r33.f0 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute '__mypyc_temp__1' of '_get_transaction_receipt_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r33.f0);
        CPy_INCREF(cpy_r_r33.f1);
        CPy_INCREF(cpy_r_r33.f2);
    }
    CPy_DecRef(cpy_r_r2);
    if (unlikely(cpy_r_r33.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", -1, CPyStatic_utils___globals);
        goto CPyL49;
    }
CPyL35: ;
    CPy_RestoreExcInfo(cpy_r_r33);
    CPy_DecRef(cpy_r_r33.f0);
    CPy_DecRef(cpy_r_r33.f1);
    CPy_DecRef(cpy_r_r33.f2);
    cpy_r_r34 = CPy_KeepPropagating();
    if (!cpy_r_r34) goto CPyL49;
    CPy_Unreachable();
CPyL37: ;
    cpy_r_r35 = ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_temp__0;
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AttributeError("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", "_get_transaction_receipt_env", "__mypyc_temp__0", -1, CPyStatic_utils___globals);
        goto CPyL64;
    }
    CPy_INCREF(cpy_r_r35);
CPyL38: ;
    cpy_r_r36 = CPyIter_Send(cpy_r_r35, cpy_r_arg);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_arg);
    if (cpy_r_r36 == NULL) goto CPyL65;
    cpy_r_r22 = cpy_r_r36;
    goto CPyL20;
CPyL40: ;
    cpy_r_r37 = CPy_FetchStopIterationValue();
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL57;
    }
    cpy_r_r21 = cpy_r_r37;
CPyL42: ;
    if (((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r2)->___mypyc_next_label__ = -2;
    cpy_r_r38 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r2);
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 45, CPyStatic_utils___globals);
        goto CPyL66;
    }
    CPyGen_SetStopIterationValue(cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    if (!0) goto CPyL49;
    CPy_Unreachable();
CPyL45: ;
    cpy_r_r39 = cpy_r_r3 == 0;
    if (cpy_r_r39) goto CPyL67;
    cpy_r_r40 = cpy_r_r3 == 2;
    CPyTagged_DECREF(cpy_r_r3);
    if (cpy_r_r40) {
        goto CPyL22;
    } else
        goto CPyL68;
CPyL47: ;
    PyErr_SetNone(PyExc_StopIteration);
    cpy_r_r41 = 0;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 19, CPyStatic_utils___globals);
        goto CPyL49;
    }
    CPy_Unreachable();
CPyL49: ;
    cpy_r_r42 = NULL;
    return cpy_r_r42;
CPyL50: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL49;
CPyL51: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL49;
CPyL52: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL3;
CPyL53: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    goto CPyL7;
CPyL54: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    goto CPyL10;
CPyL55: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    goto CPyL49;
CPyL56: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL17;
CPyL57: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL49;
CPyL58: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL26;
CPyL59: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL21;
CPyL60: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL24;
CPyL61: ;
    CPy_XDecRef(cpy_r_r1);
    goto CPyL34;
CPyL62: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r22);
    goto CPyL34;
CPyL63: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL34;
CPyL64: ;
    CPy_XDecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_arg);
    goto CPyL49;
CPyL65: ;
    CPy_XDECREF(cpy_r_r1);
    goto CPyL40;
CPyL66: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL49;
CPyL67: ;
    CPyTagged_DECREF(cpy_r_r3);
    goto CPyL2;
CPyL68: ;
    CPy_XDECREF(cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r2);
    goto CPyL47;
}

PyObject *CPyPy_utils____get_transaction_receipt_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", "arg", 0};
    static CPyArg_Parser parser = {"OOOO:__mypyc_generator_helper__", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value;
    PyObject *obj_traceback;
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_type = obj_type;
    PyObject *arg_value = obj_value;
    PyObject *arg_traceback = obj_traceback;
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_utils____get_transaction_receipt_gen_____mypyc_generator_helper__(arg___mypyc_self__, arg_type, arg_value, arg_traceback, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 19, CPyStatic_utils___globals);
    return NULL;
}

PyObject *CPyDef_utils____get_transaction_receipt_gen_____next__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_utils____get_transaction_receipt_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_utils____get_transaction_receipt_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__next__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_utils____get_transaction_receipt_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.utils._get_transaction_receipt_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_utils____get_transaction_receipt_gen_____next__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "__next__", -1, CPyStatic_utils___globals);
    return NULL;
}

PyObject *CPyDef_utils____get_transaction_receipt_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyDef_utils____get_transaction_receipt_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_r0, cpy_r_r0, cpy_r_r0, cpy_r_arg);
    if (cpy_r_r1 == NULL) goto CPyL2;
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_utils____get_transaction_receipt_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"arg", 0};
    static CPyArg_Parser parser = {"O:send", kwlist, 0};
    PyObject *obj_arg;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_arg)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_utils____get_transaction_receipt_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.utils._get_transaction_receipt_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_arg = obj_arg;
    PyObject *retval = CPyDef_utils____get_transaction_receipt_gen___send(arg___mypyc_self__, arg_arg);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "send", -1, CPyStatic_utils___globals);
    return NULL;
}

PyObject *CPyDef_utils____get_transaction_receipt_gen_____iter__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_utils____get_transaction_receipt_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__iter__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_utils____get_transaction_receipt_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.utils._get_transaction_receipt_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_utils____get_transaction_receipt_gen_____iter__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "__iter__", -1, CPyStatic_utils___globals);
    return NULL;
}

PyObject *CPyDef_utils____get_transaction_receipt_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    if (cpy_r_value != NULL) goto CPyL7;
    CPy_INCREF(cpy_r_r0);
    cpy_r_value = cpy_r_r0;
CPyL2: ;
    if (cpy_r_traceback != NULL) goto CPyL8;
    CPy_INCREF(cpy_r_r0);
    cpy_r_traceback = cpy_r_r0;
CPyL4: ;
    cpy_r_r1 = CPyDef_utils____get_transaction_receipt_gen_____mypyc_generator_helper__(cpy_r___mypyc_self__, cpy_r_type, cpy_r_value, cpy_r_traceback, cpy_r_r0);
    CPy_DECREF(cpy_r_value);
    CPy_DECREF(cpy_r_traceback);
    if (cpy_r_r1 == NULL) goto CPyL6;
    return cpy_r_r1;
CPyL6: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
CPyL7: ;
    CPy_INCREF(cpy_r_value);
    goto CPyL2;
CPyL8: ;
    CPy_INCREF(cpy_r_traceback);
    goto CPyL4;
}

PyObject *CPyPy_utils____get_transaction_receipt_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"type", "value", "traceback", 0};
    static CPyArg_Parser parser = {"O|OO:throw", kwlist, 0};
    PyObject *obj_type;
    PyObject *obj_value = NULL;
    PyObject *obj_traceback = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_type, &obj_value, &obj_traceback)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_utils____get_transaction_receipt_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.utils._get_transaction_receipt_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *arg_type = obj_type;
    PyObject *arg_value;
    if (obj_value == NULL) {
        arg_value = NULL;
    } else {
        arg_value = obj_value; 
    }
    PyObject *arg_traceback;
    if (obj_traceback == NULL) {
        arg_traceback = NULL;
    } else {
        arg_traceback = obj_traceback; 
    }
    PyObject *retval = CPyDef_utils____get_transaction_receipt_gen___throw(arg___mypyc_self__, arg_type, arg_value, arg_traceback);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "throw", -1, CPyStatic_utils___globals);
    return NULL;
}

PyObject *CPyDef_utils____get_transaction_receipt_gen___close(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3OOO cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    tuple_T2OO cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[10]; /* 'GeneratorExit' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL3;
    cpy_r_r3 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = CPyDef_utils____get_transaction_receipt_gen___throw(cpy_r___mypyc_self__, cpy_r_r2, cpy_r_r3, cpy_r_r4);
    if (cpy_r_r5 != NULL) goto CPyL11;
CPyL3: ;
    cpy_r_r6 = CPy_CatchError();
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[11]; /* 'StopIteration' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL12;
    cpy_r_r10.f0 = cpy_r_r2;
    cpy_r_r10.f1 = cpy_r_r9;
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp42 = cpy_r_r10.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp42);
    PyObject *__tmp43 = cpy_r_r10.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp43);
    cpy_r_r12 = CPy_ExceptionMatches(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r12) goto CPyL13;
    CPy_RestoreExcInfo(cpy_r_r6);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    cpy_r_r13 = (PyObject *)&_Py_NoneStruct;
    CPy_INCREF(cpy_r_r13);
    return cpy_r_r13;
CPyL6: ;
    CPy_Reraise();
    if (!0) goto CPyL10;
    CPy_Unreachable();
CPyL8: ;
    PyErr_SetString(PyExc_RuntimeError, "generator ignored GeneratorExit");
    cpy_r_r14 = 0;
    if (!cpy_r_r14) goto CPyL10;
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL11: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL10;
CPyL13: ;
    CPy_DECREF(cpy_r_r6.f0);
    CPy_DECREF(cpy_r_r6.f1);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL6;
}

PyObject *CPyPy_utils____get_transaction_receipt_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":close", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_utils____get_transaction_receipt_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.utils._get_transaction_receipt_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_utils____get_transaction_receipt_gen___close(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "close", -1, CPyStatic_utils___globals);
    return NULL;
}

PyObject *CPyDef_utils____get_transaction_receipt_gen_____await__(PyObject *cpy_r___mypyc_self__) {
    CPy_INCREF_NO_IMM(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
}

PyObject *CPyPy_utils____get_transaction_receipt_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__await__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_utils____get_transaction_receipt_gen))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio._loaders.utils._get_transaction_receipt_gen", obj___mypyc_self__); 
        goto fail;
    }
    PyObject *retval = CPyDef_utils____get_transaction_receipt_gen_____await__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "__await__", -1, CPyStatic_utils___globals);
    return NULL;
}

PyObject *CPyDef_utils____get_transaction_receipt(PyObject *cpy_r_txhash) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    cpy_r_r0 = CPyDef_utils____get_transaction_receipt_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 19, CPyStatic_utils___globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_txhash);
    if (((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r0)->_txhash != NULL) {
        CPy_DECREF(((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r0)->_txhash);
    }
    ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r0)->_txhash = cpy_r_txhash;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 19, CPyStatic_utils___globals);
        goto CPyL7;
    }
    cpy_r_r2 = CPyDef_utils____get_transaction_receipt_gen();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 19, CPyStatic_utils___globals);
        goto CPyL7;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
    if (((eth_portfolio____loaders___utils____get_transaction_receipt_genObject *)cpy_r_r2)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((eth_portfolio____loaders___utils____get_transaction_receipt_genObject *)cpy_r_r2)->___mypyc_env__);
    }
    ((eth_portfolio____loaders___utils____get_transaction_receipt_genObject *)cpy_r_r2)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 19, CPyStatic_utils___globals);
        goto CPyL8;
    }
    if (((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r0)->___mypyc_next_label__ != CPY_INT_TAG) {
        CPyTagged_DECREF(((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r0)->___mypyc_next_label__);
    }
    ((eth_portfolio____loaders___utils____get_transaction_receipt_envObject *)cpy_r_r0)->___mypyc_next_label__ = 0;
    cpy_r_r4 = 1;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 19, CPyStatic_utils___globals);
        goto CPyL9;
    }
    return cpy_r_r2;
CPyL6: ;
    cpy_r_r5 = NULL;
    return cpy_r_r5;
CPyL7: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL6;
CPyL8: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    goto CPyL6;
CPyL9: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL6;
}

PyObject *CPyPy_utils____get_transaction_receipt(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"txhash", 0};
    static CPyArg_Parser parser = {"O:_get_transaction_receipt", kwlist, 0};
    PyObject *obj_txhash;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_txhash)) {
        return NULL;
    }
    PyObject *arg_txhash = obj_txhash;
    PyObject *retval = CPyDef_utils____get_transaction_receipt(arg_txhash);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "_get_transaction_receipt", 19, CPyStatic_utils___globals);
    return NULL;
}

char CPyDef_utils_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r9;
    PyObject **cpy_r_r10;
    PyObject **cpy_r_r11;
    void *cpy_r_r13;
    void *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    int32_t cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    tuple_T3OOO cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    int32_t cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject **cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject **cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject **cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject **cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject **cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    int32_t cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject **cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    int32_t cpy_r_r112;
    char cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    int32_t cpy_r_r121;
    char cpy_r_r122;
    char cpy_r_r123;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[22]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", -1, CPyStatic_utils___globals);
        goto CPyL35;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[436]; /* ('Final',) */
    cpy_r_r6 = CPyStatics[35]; /* 'typing' */
    cpy_r_r7 = CPyStatic_utils___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 1, CPyStatic_utils___globals);
        goto CPyL35;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = (PyObject **)&CPyModule_dank_mids;
    cpy_r_r10 = (PyObject **)&CPyModule_eth_retry;
    cpy_r_r11 = (PyObject **)&CPyModule_msgspec;
    PyObject **cpy_r_r12[3] = {cpy_r_r9, cpy_r_r10, cpy_r_r11};
    cpy_r_r13 = (void *)&cpy_r_r12;
    int64_t cpy_r_r14[3] = {3, 4, 5};
    cpy_r_r15 = (void *)&cpy_r_r14;
    cpy_r_r16 = CPyStatics[447]; /* (('dank_mids', 'dank_mids', 'dank_mids'),
                                    ('eth_retry', 'eth_retry', 'eth_retry'),
                                    ('msgspec', 'msgspec', 'msgspec')) */
    cpy_r_r17 = CPyStatic_utils___globals;
    cpy_r_r18 = CPyStatics[97]; /* 'eth_portfolio/_loaders/utils.py' */
    cpy_r_r19 = CPyStatics[26]; /* '<module>' */
    cpy_r_r20 = CPyImport_ImportMany(cpy_r_r16, cpy_r_r13, cpy_r_r17, cpy_r_r18, cpy_r_r19, cpy_r_r15);
    if (!cpy_r_r20) goto CPyL35;
    cpy_r_r21 = CPyStatics[448]; /* ('SmartProcessingQueue',) */
    cpy_r_r22 = CPyStatics[36]; /* 'a_sync' */
    cpy_r_r23 = CPyStatic_utils___globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 6, CPyStatic_utils___globals);
        goto CPyL35;
    }
    CPyModule_a_sync = cpy_r_r24;
    CPy_INCREF(CPyModule_a_sync);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r25 = CPyStatics[449]; /* ('alru_cache',) */
    cpy_r_r26 = CPyStatics[100]; /* 'async_lru' */
    cpy_r_r27 = CPyStatic_utils___globals;
    cpy_r_r28 = CPyImport_ImportFromMany(cpy_r_r26, cpy_r_r25, cpy_r_r25, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 7, CPyStatic_utils___globals);
        goto CPyL35;
    }
    CPyModule_async_lru = cpy_r_r28;
    CPy_INCREF(CPyModule_async_lru);
    CPy_DECREF(cpy_r_r28);
    cpy_r_r29 = CPyStatics[450]; /* ('HexStr',) */
    cpy_r_r30 = CPyStatics[40]; /* 'eth_typing' */
    cpy_r_r31 = CPyStatic_utils___globals;
    cpy_r_r32 = CPyImport_ImportFromMany(cpy_r_r30, cpy_r_r29, cpy_r_r29, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 8, CPyStatic_utils___globals);
        goto CPyL35;
    }
    CPyModule_eth_typing = cpy_r_r32;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r33 = CPyStatics[439]; /* ('stuck_coro_debugger',) */
    cpy_r_r34 = CPyStatics[81]; /* 'y._decorators' */
    cpy_r_r35 = CPyStatic_utils___globals;
    cpy_r_r36 = CPyImport_ImportFromMany(cpy_r_r34, cpy_r_r33, cpy_r_r33, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 9, CPyStatic_utils___globals);
        goto CPyL35;
    }
    CPyModule_y____decorators = cpy_r_r36;
    CPy_INCREF(CPyModule_y____decorators);
    CPy_DECREF(cpy_r_r36);
    cpy_r_r37 = CPyModule_msgspec;
    cpy_r_r38 = CPyStatics[102]; /* 'Raw' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 12, CPyStatic_utils___globals);
        goto CPyL35;
    }
    CPyStatic_utils___Raw = cpy_r_r39;
    CPy_INCREF(CPyStatic_utils___Raw);
    cpy_r_r40 = CPyStatic_utils___globals;
    cpy_r_r41 = CPyStatics[102]; /* 'Raw' */
    cpy_r_r42 = CPyDict_SetItem(cpy_r_r40, cpy_r_r41, cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    cpy_r_r43 = cpy_r_r42 >= 0;
    if (unlikely(!cpy_r_r43)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 12, CPyStatic_utils___globals);
        goto CPyL35;
    }
    cpy_r_r44 = CPyStatic_utils___globals;
    cpy_r_r45 = CPyStatics[98]; /* 'SmartProcessingQueue' */
    cpy_r_r46 = CPyDict_GetItem(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 13, CPyStatic_utils___globals);
        goto CPyL35;
    }
    cpy_r_r47 = CPyStatic_utils___globals;
    cpy_r_r48 = CPyStatics[101]; /* 'HexStr' */
    cpy_r_r49 = CPyDict_GetItem(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 13, CPyStatic_utils___globals);
        goto CPyL36;
    }
    cpy_r_r50 = PyList_New(0);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 13, CPyStatic_utils___globals);
        goto CPyL37;
    }
    cpy_r_r51 = CPyModule_msgspec;
    cpy_r_r52 = CPyStatics[102]; /* 'Raw' */
    cpy_r_r53 = CPyObject_GetAttr(cpy_r_r51, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 13, CPyStatic_utils___globals);
        goto CPyL38;
    }
    cpy_r_r54.f0 = cpy_r_r49;
    cpy_r_r54.f1 = cpy_r_r50;
    cpy_r_r54.f2 = cpy_r_r53;
    cpy_r_r55 = PyTuple_New(3);
    if (unlikely(cpy_r_r55 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp44 = cpy_r_r54.f0;
    PyTuple_SET_ITEM(cpy_r_r55, 0, __tmp44);
    PyObject *__tmp45 = cpy_r_r54.f1;
    PyTuple_SET_ITEM(cpy_r_r55, 1, __tmp45);
    PyObject *__tmp46 = cpy_r_r54.f2;
    PyTuple_SET_ITEM(cpy_r_r55, 2, __tmp46);
    cpy_r_r56 = PyObject_GetItem(cpy_r_r46, cpy_r_r55);
    CPy_DECREF(cpy_r_r46);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 13, CPyStatic_utils___globals);
        goto CPyL35;
    }
    cpy_r_r57 = CPyStatic_utils___globals;
    cpy_r_r58 = CPyStatics[103]; /* 'TxReceiptQueue' */
    cpy_r_r59 = CPyDict_SetItem(cpy_r_r57, cpy_r_r58, cpy_r_r56);
    CPy_DECREF(cpy_r_r56);
    cpy_r_r60 = cpy_r_r59 >= 0;
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 13, CPyStatic_utils___globals);
        goto CPyL35;
    }
    cpy_r_r61 = CPyStatic_utils___globals;
    cpy_r_r62 = CPyStatics[104]; /* '_get_transaction_receipt' */
    cpy_r_r63 = CPyDict_GetItem(cpy_r_r61, cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 16, CPyStatic_utils___globals);
        goto CPyL35;
    }
    cpy_r_r64 = CPyStatic_utils___globals;
    cpy_r_r65 = CPyStatics[80]; /* 'stuck_coro_debugger' */
    cpy_r_r66 = CPyDict_GetItem(cpy_r_r64, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 18, CPyStatic_utils___globals);
        goto CPyL39;
    }
    PyObject *cpy_r_r67[1] = {cpy_r_r63};
    cpy_r_r68 = (PyObject **)&cpy_r_r67;
    cpy_r_r69 = PyObject_Vectorcall(cpy_r_r66, cpy_r_r68, 1, 0);
    CPy_DECREF(cpy_r_r66);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 16, CPyStatic_utils___globals);
        goto CPyL39;
    }
    CPy_DECREF(cpy_r_r63);
    cpy_r_r70 = CPyStatic_utils___globals;
    cpy_r_r71 = CPyStatics[99]; /* 'alru_cache' */
    cpy_r_r72 = CPyDict_GetItem(cpy_r_r70, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 17, CPyStatic_utils___globals);
        goto CPyL40;
    }
    cpy_r_r73 = Py_None;
    cpy_r_r74 = CPyStatics[414]; /* 3600 */
    PyObject *cpy_r_r75[2] = {cpy_r_r73, cpy_r_r74};
    cpy_r_r76 = (PyObject **)&cpy_r_r75;
    cpy_r_r77 = CPyStatics[451]; /* ('maxsize', 'ttl') */
    cpy_r_r78 = PyObject_Vectorcall(cpy_r_r72, cpy_r_r76, 0, cpy_r_r77);
    CPy_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 17, CPyStatic_utils___globals);
        goto CPyL40;
    }
    PyObject *cpy_r_r79[1] = {cpy_r_r69};
    cpy_r_r80 = (PyObject **)&cpy_r_r79;
    cpy_r_r81 = PyObject_Vectorcall(cpy_r_r78, cpy_r_r80, 1, 0);
    CPy_DECREF(cpy_r_r78);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 16, CPyStatic_utils___globals);
        goto CPyL40;
    }
    CPy_DECREF(cpy_r_r69);
    cpy_r_r82 = CPyModule_eth_retry;
    cpy_r_r83 = CPyStatics[106]; /* 'auto_retry' */
    cpy_r_r84 = CPyObject_GetAttr(cpy_r_r82, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 16, CPyStatic_utils___globals);
        goto CPyL41;
    }
    cpy_r_r85 = CPyStatics[408]; /* 1 */
    cpy_r_r86 = CPyStatics[415]; /* 3 */
    cpy_r_r87 = CPyStatics[416]; /* 20 */
    cpy_r_r88 = CPyStatics[408]; /* 1 */
    PyObject *cpy_r_r89[4] = {cpy_r_r85, cpy_r_r86, cpy_r_r87, cpy_r_r88};
    cpy_r_r90 = (PyObject **)&cpy_r_r89;
    cpy_r_r91 = CPyStatics[452]; /* ('min_sleep_time', 'max_sleep_time', 'max_retries',
                                    'suppress_logs') */
    cpy_r_r92 = PyObject_Vectorcall(cpy_r_r84, cpy_r_r90, 0, cpy_r_r91);
    CPy_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 16, CPyStatic_utils___globals);
        goto CPyL41;
    }
    PyObject *cpy_r_r93[1] = {cpy_r_r81};
    cpy_r_r94 = (PyObject **)&cpy_r_r93;
    cpy_r_r95 = PyObject_Vectorcall(cpy_r_r92, cpy_r_r94, 1, 0);
    CPy_DECREF(cpy_r_r92);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 16, CPyStatic_utils___globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r81);
    cpy_r_r96 = CPyStatic_utils___globals;
    cpy_r_r97 = CPyStatics[104]; /* '_get_transaction_receipt' */
    cpy_r_r98 = CPyDict_SetItem(cpy_r_r96, cpy_r_r97, cpy_r_r95);
    CPy_DECREF(cpy_r_r95);
    cpy_r_r99 = cpy_r_r98 >= 0;
    if (unlikely(!cpy_r_r99)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 16, CPyStatic_utils___globals);
        goto CPyL35;
    }
    cpy_r_r100 = CPyStatic_utils___globals;
    cpy_r_r101 = CPyStatics[104]; /* '_get_transaction_receipt' */
    cpy_r_r102 = CPyDict_GetItem(cpy_r_r100, cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 49, CPyStatic_utils___globals);
        goto CPyL35;
    }
    cpy_r_r103 = CPyStatic_utils___globals;
    cpy_r_r104 = CPyStatics[98]; /* 'SmartProcessingQueue' */
    cpy_r_r105 = CPyDict_GetItem(cpy_r_r103, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 48, CPyStatic_utils___globals);
        goto CPyL42;
    }
    cpy_r_r106 = CPyStatics[417]; /* 5000 */
    PyObject *cpy_r_r107[2] = {cpy_r_r102, cpy_r_r106};
    cpy_r_r108 = (PyObject **)&cpy_r_r107;
    cpy_r_r109 = PyObject_Vectorcall(cpy_r_r105, cpy_r_r108, 2, 0);
    CPy_DECREF(cpy_r_r105);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 48, CPyStatic_utils___globals);
        goto CPyL42;
    }
    CPy_DECREF(cpy_r_r102);
    CPyStatic_utils___get_transaction_receipt = cpy_r_r109;
    CPy_INCREF(CPyStatic_utils___get_transaction_receipt);
    cpy_r_r110 = CPyStatic_utils___globals;
    cpy_r_r111 = CPyStatics[111]; /* 'get_transaction_receipt' */
    cpy_r_r112 = CPyDict_SetItem(cpy_r_r110, cpy_r_r111, cpy_r_r109);
    CPy_DECREF(cpy_r_r109);
    cpy_r_r113 = cpy_r_r112 >= 0;
    if (unlikely(!cpy_r_r113)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 48, CPyStatic_utils___globals);
        goto CPyL35;
    }
    cpy_r_r114 = CPyModule_dank_mids;
    cpy_r_r115 = CPyStatics[20]; /* 'eth' */
    cpy_r_r116 = CPyObject_GetAttr(cpy_r_r114, cpy_r_r115);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 68, CPyStatic_utils___globals);
        goto CPyL35;
    }
    cpy_r_r117 = CPyStatics[111]; /* 'get_transaction_receipt' */
    cpy_r_r118 = CPyObject_GetAttr(cpy_r_r116, cpy_r_r117);
    CPy_DECREF(cpy_r_r116);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 68, CPyStatic_utils___globals);
        goto CPyL35;
    }
    CPyStatic_utils_____get_transaction_receipt = cpy_r_r118;
    CPy_INCREF(CPyStatic_utils_____get_transaction_receipt);
    cpy_r_r119 = CPyStatic_utils___globals;
    cpy_r_r120 = CPyStatics[112]; /* '__get_transaction_receipt' */
    cpy_r_r121 = CPyDict_SetItem(cpy_r_r119, cpy_r_r120, cpy_r_r118);
    CPy_DECREF(cpy_r_r118);
    cpy_r_r122 = cpy_r_r121 >= 0;
    if (unlikely(!cpy_r_r122)) {
        CPy_AddTraceback("eth_portfolio/_loaders/utils.py", "<module>", 68, CPyStatic_utils___globals);
        goto CPyL35;
    }
    return 1;
CPyL35: ;
    cpy_r_r123 = 2;
    return cpy_r_r123;
CPyL36: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL35;
CPyL37: ;
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r49);
    goto CPyL35;
CPyL38: ;
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r49);
    CPy_DecRef(cpy_r_r50);
    goto CPyL35;
CPyL39: ;
    CPy_DecRef(cpy_r_r63);
    goto CPyL35;
CPyL40: ;
    CPy_DecRef(cpy_r_r69);
    goto CPyL35;
CPyL41: ;
    CPy_DecRef(cpy_r_r81);
    goto CPyL35;
CPyL42: ;
    CPy_DecRef(cpy_r_r102);
    goto CPyL35;
}
static PyMethodDef _argspecmodule_methods[] = {
    {"get_args_type", (PyCFunction)CPyPy__argspec___get_args_type, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_kwargs_type", (PyCFunction)CPyPy__argspec___get_kwargs_type, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_return_type", (PyCFunction)CPyPy__argspec___get_return_type, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_types", (PyCFunction)CPyPy__argspec___get_types, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _argspecmodule = {
    PyModuleDef_HEAD_INIT,
    "eth_portfolio._argspec",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    _argspecmodule_methods
};

PyObject *CPyInit_eth_portfolio____argspec(void)
{
    PyObject* modname = NULL;
    if (CPyModule_eth_portfolio____argspec_internal) {
        Py_INCREF(CPyModule_eth_portfolio____argspec_internal);
        return CPyModule_eth_portfolio____argspec_internal;
    }
    CPyModule_eth_portfolio____argspec_internal = PyModule_Create(&_argspecmodule);
    if (unlikely(CPyModule_eth_portfolio____argspec_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_eth_portfolio____argspec_internal, "__name__");
    CPyStatic__argspec___globals = PyModule_GetDict(CPyModule_eth_portfolio____argspec_internal);
    if (unlikely(CPyStatic__argspec___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__argspec_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_eth_portfolio____argspec_internal;
    fail:
    Py_CLEAR(CPyModule_eth_portfolio____argspec_internal);
    Py_CLEAR(modname);
    return NULL;
}

PyObject *CPyDef__argspec___get_args_type(PyObject *cpy_r_sample) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    CPyTagged cpy_r_r10;
    CPyPtr cpy_r_r11;
    int64_t cpy_r_r12;
    CPyTagged cpy_r_r13;
    char cpy_r_r14;
    int64_t cpy_r_r15;
    CPyPtr cpy_r_r16;
    CPyPtr cpy_r_r17;
    int64_t cpy_r_r18;
    CPyPtr cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    int32_t cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    int32_t cpy_r_r31;
    char cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    int32_t cpy_r_r41;
    char cpy_r_r42;
    CPyTagged cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    cpy_r_r0 = CPyStatic__argspec___globals;
    cpy_r_r1 = CPyStatics[113]; /* 'getfullargspec' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 8, CPyStatic__argspec___globals);
        goto CPyL33;
    }
    PyObject *cpy_r_r3[1] = {cpy_r_sample};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_Vectorcall(cpy_r_r2, cpy_r_r4, 1, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 8, CPyStatic__argspec___globals);
        goto CPyL33;
    }
    if (likely(PyTuple_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_args_type", 8, CPyStatic__argspec___globals, "tuple", cpy_r_r5);
        goto CPyL33;
    }
    cpy_r_r7 = PyDict_New();
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 9, CPyStatic__argspec___globals);
        goto CPyL34;
    }
    cpy_r_r8 = CPySequenceTuple_GetItem(cpy_r_r6, 0);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 11, CPyStatic__argspec___globals);
        goto CPyL35;
    }
    if (likely(PyList_Check(cpy_r_r8)))
        cpy_r_r9 = cpy_r_r8;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_args_type", 11, CPyStatic__argspec___globals, "list", cpy_r_r8);
        goto CPyL35;
    }
    cpy_r_r10 = 0;
CPyL7: ;
    cpy_r_r11 = (CPyPtr)&((PyVarObject *)cpy_r_r9)->ob_size;
    cpy_r_r12 = *(int64_t *)cpy_r_r11;
    cpy_r_r13 = cpy_r_r12 << 1;
    cpy_r_r14 = (Py_ssize_t)cpy_r_r10 < (Py_ssize_t)cpy_r_r13;
    if (!cpy_r_r14) goto CPyL36;
    cpy_r_r15 = (Py_ssize_t)cpy_r_r10 >> 1;
    cpy_r_r16 = (CPyPtr)&((PyListObject *)cpy_r_r9)->ob_item;
    cpy_r_r17 = *(CPyPtr *)cpy_r_r16;
    cpy_r_r18 = cpy_r_r15 * 8;
    cpy_r_r19 = cpy_r_r17 + cpy_r_r18;
    cpy_r_r20 = *(PyObject * *)cpy_r_r19;
    CPy_INCREF(cpy_r_r20);
    if (likely(PyUnicode_Check(cpy_r_r20)))
        cpy_r_r21 = cpy_r_r20;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_args_type", 9, CPyStatic__argspec___globals, "str", cpy_r_r20);
        goto CPyL37;
    }
    cpy_r_r22 = CPyStatics[114]; /* 'self' */
    cpy_r_r23 = PyUnicode_Compare(cpy_r_r21, cpy_r_r22);
    cpy_r_r24 = cpy_r_r23 == -1;
    if (!cpy_r_r24) goto CPyL12;
    cpy_r_r25 = PyErr_Occurred();
    cpy_r_r26 = cpy_r_r25 != NULL;
    if (!cpy_r_r26) goto CPyL12;
    cpy_r_r27 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 12, CPyStatic__argspec___globals);
        goto CPyL38;
    }
CPyL12: ;
    cpy_r_r28 = cpy_r_r23 != 0;
    if (!cpy_r_r28) goto CPyL39;
    cpy_r_r29 = CPySequenceTuple_GetItem(cpy_r_r6, 12);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 10, CPyStatic__argspec___globals);
        goto CPyL38;
    }
    if (likely(PyDict_Check(cpy_r_r29)))
        cpy_r_r30 = cpy_r_r29;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_args_type", 10, CPyStatic__argspec___globals, "dict", cpy_r_r29);
        goto CPyL38;
    }
    cpy_r_r31 = PyDict_Contains(cpy_r_r30, cpy_r_r21);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r32 = cpy_r_r31 >= 0;
    if (unlikely(!cpy_r_r32)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 10, CPyStatic__argspec___globals);
        goto CPyL38;
    }
    cpy_r_r33 = cpy_r_r31;
    if (!cpy_r_r33) goto CPyL21;
    cpy_r_r34 = CPySequenceTuple_GetItem(cpy_r_r6, 12);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 10, CPyStatic__argspec___globals);
        goto CPyL38;
    }
    if (likely(PyDict_Check(cpy_r_r34)))
        cpy_r_r35 = cpy_r_r34;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_args_type", 10, CPyStatic__argspec___globals, "dict", cpy_r_r34);
        goto CPyL38;
    }
    cpy_r_r36 = CPyDict_GetItem(cpy_r_r35, cpy_r_r21);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 10, CPyStatic__argspec___globals);
        goto CPyL38;
    }
    cpy_r_r37 = cpy_r_r36;
    goto CPyL23;
CPyL21: ;
    cpy_r_r38 = CPyStatic__argspec___globals;
    cpy_r_r39 = CPyStatics[115]; /* 'Any' */
    cpy_r_r40 = CPyDict_GetItem(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 10, CPyStatic__argspec___globals);
        goto CPyL38;
    }
    cpy_r_r37 = cpy_r_r40;
CPyL23: ;
    cpy_r_r41 = CPyDict_SetItem(cpy_r_r7, cpy_r_r21, cpy_r_r37);
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r37);
    cpy_r_r42 = cpy_r_r41 >= 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 9, CPyStatic__argspec___globals);
        goto CPyL37;
    }
CPyL24: ;
    cpy_r_r43 = cpy_r_r10 + 2;
    cpy_r_r10 = cpy_r_r43;
    goto CPyL7;
CPyL25: ;
    cpy_r_r44 = CPyDict_ValuesView(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 14, CPyStatic__argspec___globals);
        goto CPyL33;
    }
    cpy_r_r45 = (PyObject *)&PyTuple_Type;
    cpy_r_r46 = PyList_New(0);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 14, CPyStatic__argspec___globals);
        goto CPyL40;
    }
    cpy_r_r47 = CPyList_Extend(cpy_r_r46, cpy_r_r44);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 14, CPyStatic__argspec___globals);
        goto CPyL41;
    } else
        goto CPyL42;
CPyL28: ;
    cpy_r_r48 = PyList_AsTuple(cpy_r_r46);
    CPy_DECREF_NO_IMM(cpy_r_r46);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 14, CPyStatic__argspec___globals);
        goto CPyL33;
    }
    cpy_r_r49 = PyDict_New();
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 14, CPyStatic__argspec___globals);
        goto CPyL43;
    }
    cpy_r_r50 = PyObject_Call(cpy_r_r45, cpy_r_r48, cpy_r_r49);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 14, CPyStatic__argspec___globals);
        goto CPyL33;
    }
    if (likely(PyTuple_Check(cpy_r_r50)))
        cpy_r_r51 = cpy_r_r50;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_args_type", 14, CPyStatic__argspec___globals, "tuple", cpy_r_r50);
        goto CPyL33;
    }
    return cpy_r_r51;
CPyL33: ;
    cpy_r_r52 = NULL;
    return cpy_r_r52;
CPyL34: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL33;
CPyL35: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    goto CPyL33;
CPyL36: ;
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF_NO_IMM(cpy_r_r9);
    goto CPyL25;
CPyL37: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r9);
    goto CPyL33;
CPyL38: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r21);
    goto CPyL33;
CPyL39: ;
    CPy_DECREF(cpy_r_r21);
    goto CPyL24;
CPyL40: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL33;
CPyL41: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL33;
CPyL42: ;
    CPy_DECREF(cpy_r_r47);
    goto CPyL28;
CPyL43: ;
    CPy_DecRef(cpy_r_r48);
    goto CPyL33;
}

PyObject *CPyPy__argspec___get_args_type(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"sample", 0};
    static CPyArg_Parser parser = {"O:get_args_type", kwlist, 0};
    PyObject *obj_sample;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_sample)) {
        return NULL;
    }
    PyObject *arg_sample = obj_sample;
    PyObject *retval = CPyDef__argspec___get_args_type(arg_sample);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_argspec.py", "get_args_type", 7, CPyStatic__argspec___globals);
    return NULL;
}

PyObject *CPyDef__argspec___get_kwargs_type(PyObject *cpy_r_sample) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    CPyPtr cpy_r_r9;
    int64_t cpy_r_r10;
    CPyTagged cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    int32_t cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    CPyTagged cpy_r_r23;
    CPyTagged cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    CPyTagged cpy_r_r30;
    CPyPtr cpy_r_r31;
    int64_t cpy_r_r32;
    CPyTagged cpy_r_r33;
    char cpy_r_r34;
    int64_t cpy_r_r35;
    CPyPtr cpy_r_r36;
    CPyPtr cpy_r_r37;
    int64_t cpy_r_r38;
    CPyPtr cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    int32_t cpy_r_r44;
    char cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    CPyTagged cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    char cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    tuple_T2OO cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    tuple_T3OOO cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    cpy_r_r0 = CPyStatic__argspec___globals;
    cpy_r_r1 = CPyStatics[113]; /* 'getfullargspec' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 18, CPyStatic__argspec___globals);
        goto CPyL67;
    }
    PyObject *cpy_r_r3[1] = {cpy_r_sample};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_Vectorcall(cpy_r_r2, cpy_r_r4, 1, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 18, CPyStatic__argspec___globals);
        goto CPyL67;
    }
    if (likely(PyTuple_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 18, CPyStatic__argspec___globals, "tuple", cpy_r_r5);
        goto CPyL67;
    }
    cpy_r_r7 = CPySequenceTuple_GetItem(cpy_r_r6, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 19, CPyStatic__argspec___globals);
        goto CPyL68;
    }
    if (likely(PyList_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 19, CPyStatic__argspec___globals, "list", cpy_r_r7);
        goto CPyL68;
    }
    cpy_r_r9 = (CPyPtr)&((PyVarObject *)cpy_r_r8)->ob_size;
    cpy_r_r10 = *(int64_t *)cpy_r_r9;
    CPy_DECREF_NO_IMM(cpy_r_r8);
    cpy_r_r11 = cpy_r_r10 << 1;
    cpy_r_r12 = CPySequenceTuple_GetItem(cpy_r_r6, 6);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 19, CPyStatic__argspec___globals);
        goto CPyL68;
    }
    if (PyTuple_Check(cpy_r_r12))
        cpy_r_r13 = cpy_r_r12;
    else {
        cpy_r_r13 = NULL;
    }
    if (cpy_r_r13 != NULL) goto __LL47;
    if (cpy_r_r12 == Py_None)
        cpy_r_r13 = cpy_r_r12;
    else {
        cpy_r_r13 = NULL;
    }
    if (cpy_r_r13 != NULL) goto __LL47;
    CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 19, CPyStatic__argspec___globals, "tuple or None", cpy_r_r12);
    goto CPyL68;
__LL47: ;
    cpy_r_r14 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r15 = cpy_r_r13 != cpy_r_r14;
    if (!cpy_r_r15) goto CPyL69;
    CPy_INCREF(cpy_r_r13);
    if (likely(cpy_r_r13 != Py_None))
        cpy_r_r16 = cpy_r_r13;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 19, CPyStatic__argspec___globals, "tuple", cpy_r_r13);
        goto CPyL70;
    }
    cpy_r_r17 = PyObject_IsTrue(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r18 = cpy_r_r17 >= 0;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 19, CPyStatic__argspec___globals);
        goto CPyL70;
    }
    cpy_r_r19 = cpy_r_r17;
    if (!cpy_r_r19) goto CPyL69;
    if (PyTuple_Check(cpy_r_r13))
        cpy_r_r20 = cpy_r_r13;
    else {
        cpy_r_r20 = NULL;
    }
    if (cpy_r_r20 != NULL) goto __LL48;
    if (PyList_Check(cpy_r_r13))
        cpy_r_r20 = cpy_r_r13;
    else {
        cpy_r_r20 = NULL;
    }
    if (cpy_r_r20 != NULL) goto __LL48;
    CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 19, CPyStatic__argspec___globals, "union[tuple, list]", cpy_r_r13);
    goto CPyL68;
__LL48: ;
    cpy_r_r21 = cpy_r_r20;
    goto CPyL15;
CPyL13: ;
    cpy_r_r22 = PyList_New(0);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 19, CPyStatic__argspec___globals);
        goto CPyL68;
    }
    cpy_r_r21 = cpy_r_r22;
CPyL15: ;
    cpy_r_r23 = CPyObject_Size(cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r23 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 19, CPyStatic__argspec___globals);
        goto CPyL68;
    }
    cpy_r_r24 = CPyTagged_Subtract(cpy_r_r11, cpy_r_r23);
    CPyTagged_DECREF(cpy_r_r23);
    cpy_r_r25 = CPySequenceTuple_GetItem(cpy_r_r6, 0);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 20, CPyStatic__argspec___globals);
        goto CPyL71;
    }
    if (likely(PyList_Check(cpy_r_r25)))
        cpy_r_r26 = cpy_r_r25;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 20, CPyStatic__argspec___globals, "list", cpy_r_r25);
        goto CPyL71;
    }
    cpy_r_r27 = CPyList_GetSlice(cpy_r_r26, cpy_r_r24, 9223372036854775806LL);
    CPy_DECREF_NO_IMM(cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 20, CPyStatic__argspec___globals);
        goto CPyL71;
    }
    if (likely(PyList_Check(cpy_r_r27)))
        cpy_r_r28 = cpy_r_r27;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 20, CPyStatic__argspec___globals, "list", cpy_r_r27);
        goto CPyL71;
    }
    cpy_r_r29 = PyDict_New();
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 21, CPyStatic__argspec___globals);
        goto CPyL72;
    }
    cpy_r_r30 = 0;
CPyL22: ;
    cpy_r_r31 = (CPyPtr)&((PyVarObject *)cpy_r_r28)->ob_size;
    cpy_r_r32 = *(int64_t *)cpy_r_r31;
    cpy_r_r33 = cpy_r_r32 << 1;
    cpy_r_r34 = (Py_ssize_t)cpy_r_r30 < (Py_ssize_t)cpy_r_r33;
    if (!cpy_r_r34) goto CPyL73;
    cpy_r_r35 = (Py_ssize_t)cpy_r_r30 >> 1;
    cpy_r_r36 = (CPyPtr)&((PyListObject *)cpy_r_r28)->ob_item;
    cpy_r_r37 = *(CPyPtr *)cpy_r_r36;
    cpy_r_r38 = cpy_r_r35 * 8;
    cpy_r_r39 = cpy_r_r37 + cpy_r_r38;
    cpy_r_r40 = *(PyObject * *)cpy_r_r39;
    CPy_INCREF(cpy_r_r40);
    if (likely(PyUnicode_Check(cpy_r_r40)))
        cpy_r_r41 = cpy_r_r40;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 21, CPyStatic__argspec___globals, "str", cpy_r_r40);
        goto CPyL74;
    }
    cpy_r_r42 = CPySequenceTuple_GetItem(cpy_r_r6, 12);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 22, CPyStatic__argspec___globals);
        goto CPyL75;
    }
    if (likely(PyDict_Check(cpy_r_r42)))
        cpy_r_r43 = cpy_r_r42;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 22, CPyStatic__argspec___globals, "dict", cpy_r_r42);
        goto CPyL75;
    }
    cpy_r_r44 = PyDict_Contains(cpy_r_r43, cpy_r_r41);
    CPy_DECREF(cpy_r_r43);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 22, CPyStatic__argspec___globals);
        goto CPyL75;
    }
    cpy_r_r46 = cpy_r_r44;
    if (!cpy_r_r46) goto CPyL32;
    cpy_r_r47 = CPySequenceTuple_GetItem(cpy_r_r6, 12);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 22, CPyStatic__argspec___globals);
        goto CPyL75;
    }
    if (likely(PyDict_Check(cpy_r_r47)))
        cpy_r_r48 = cpy_r_r47;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 22, CPyStatic__argspec___globals, "dict", cpy_r_r47);
        goto CPyL75;
    }
    cpy_r_r49 = CPyDict_GetItem(cpy_r_r48, cpy_r_r41);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 22, CPyStatic__argspec___globals);
        goto CPyL75;
    }
    cpy_r_r50 = cpy_r_r49;
    goto CPyL34;
CPyL32: ;
    cpy_r_r51 = CPyStatic__argspec___globals;
    cpy_r_r52 = CPyStatics[115]; /* 'Any' */
    cpy_r_r53 = CPyDict_GetItem(cpy_r_r51, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 22, CPyStatic__argspec___globals);
        goto CPyL75;
    }
    cpy_r_r50 = cpy_r_r53;
CPyL34: ;
    cpy_r_r54 = CPyDict_SetItem(cpy_r_r29, cpy_r_r41, cpy_r_r50);
    CPy_DECREF(cpy_r_r41);
    CPy_DECREF(cpy_r_r50);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 21, CPyStatic__argspec___globals);
        goto CPyL74;
    }
    cpy_r_r56 = cpy_r_r30 + 2;
    cpy_r_r30 = cpy_r_r56;
    goto CPyL22;
CPyL36: ;
    cpy_r_r57 = CPyDict_ValuesView(cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 25, CPyStatic__argspec___globals);
        goto CPyL76;
    }
    cpy_r_r58 = (PyObject *)&PyList_Type;
    cpy_r_r59 = PyList_New(0);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 25, CPyStatic__argspec___globals);
        goto CPyL77;
    }
    cpy_r_r60 = CPyList_Extend(cpy_r_r59, cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 25, CPyStatic__argspec___globals);
        goto CPyL78;
    } else
        goto CPyL79;
CPyL39: ;
    cpy_r_r61 = PyList_AsTuple(cpy_r_r59);
    CPy_DECREF_NO_IMM(cpy_r_r59);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 25, CPyStatic__argspec___globals);
        goto CPyL76;
    }
    cpy_r_r62 = PyDict_New();
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 25, CPyStatic__argspec___globals);
        goto CPyL80;
    }
    cpy_r_r63 = PyObject_Call(cpy_r_r58, cpy_r_r61, cpy_r_r62);
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 25, CPyStatic__argspec___globals);
        goto CPyL76;
    }
    if (likely(PyList_Check(cpy_r_r63)))
        cpy_r_r64 = cpy_r_r63;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 25, CPyStatic__argspec___globals, "list", cpy_r_r63);
        goto CPyL76;
    }
    cpy_r_r65 = cpy_r_r24 == 2;
    if (cpy_r_r65) {
        goto CPyL81;
    } else
        goto CPyL49;
CPyL44: ;
    cpy_r_r66 = CPyStatic__argspec___globals;
    cpy_r_r67 = CPyStatics[33]; /* 'Tuple' */
    cpy_r_r68 = CPyDict_GetItem(cpy_r_r66, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 27, CPyStatic__argspec___globals);
        goto CPyL82;
    }
    cpy_r_r69 = CPyList_GetItemShort(cpy_r_r64, 0);
    CPy_DECREF_NO_IMM(cpy_r_r64);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 27, CPyStatic__argspec___globals);
        goto CPyL83;
    }
    cpy_r_r70 = PyObject_GetItem(cpy_r_r68, cpy_r_r69);
    CPy_DECREF(cpy_r_r68);
    CPy_DECREF(cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 27, CPyStatic__argspec___globals);
        goto CPyL67;
    }
    if (likely(PyTuple_Check(cpy_r_r70)))
        cpy_r_r71 = cpy_r_r70;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 27, CPyStatic__argspec___globals, "tuple", cpy_r_r70);
        goto CPyL67;
    }
    return cpy_r_r71;
CPyL49: ;
    cpy_r_r72 = cpy_r_r24 == 4;
    if (cpy_r_r72) {
        goto CPyL84;
    } else
        goto CPyL56;
CPyL50: ;
    cpy_r_r73 = CPyStatic__argspec___globals;
    cpy_r_r74 = CPyStatics[33]; /* 'Tuple' */
    cpy_r_r75 = CPyDict_GetItem(cpy_r_r73, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 29, CPyStatic__argspec___globals);
        goto CPyL82;
    }
    cpy_r_r76 = CPyList_GetItemShort(cpy_r_r64, 0);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 29, CPyStatic__argspec___globals);
        goto CPyL85;
    }
    cpy_r_r77 = CPyList_GetItemShort(cpy_r_r64, 2);
    CPy_DECREF_NO_IMM(cpy_r_r64);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 29, CPyStatic__argspec___globals);
        goto CPyL86;
    }
    cpy_r_r78.f0 = cpy_r_r76;
    cpy_r_r78.f1 = cpy_r_r77;
    cpy_r_r79 = PyTuple_New(2);
    if (unlikely(cpy_r_r79 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp49 = cpy_r_r78.f0;
    PyTuple_SET_ITEM(cpy_r_r79, 0, __tmp49);
    PyObject *__tmp50 = cpy_r_r78.f1;
    PyTuple_SET_ITEM(cpy_r_r79, 1, __tmp50);
    cpy_r_r80 = PyObject_GetItem(cpy_r_r75, cpy_r_r79);
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 29, CPyStatic__argspec___globals);
        goto CPyL67;
    }
    if (likely(PyTuple_Check(cpy_r_r80)))
        cpy_r_r81 = cpy_r_r80;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 29, CPyStatic__argspec___globals, "tuple", cpy_r_r80);
        goto CPyL67;
    }
    return cpy_r_r81;
CPyL56: ;
    cpy_r_r82 = cpy_r_r24 == 6;
    CPyTagged_DECREF(cpy_r_r24);
    if (!cpy_r_r82) goto CPyL87;
    cpy_r_r83 = CPyStatic__argspec___globals;
    cpy_r_r84 = CPyStatics[33]; /* 'Tuple' */
    cpy_r_r85 = CPyDict_GetItem(cpy_r_r83, cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 31, CPyStatic__argspec___globals);
        goto CPyL82;
    }
    cpy_r_r86 = CPyList_GetItemShort(cpy_r_r64, 0);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 31, CPyStatic__argspec___globals);
        goto CPyL88;
    }
    cpy_r_r87 = CPyList_GetItemShort(cpy_r_r64, 2);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 31, CPyStatic__argspec___globals);
        goto CPyL89;
    }
    cpy_r_r88 = CPyList_GetItemShort(cpy_r_r64, 4);
    CPy_DECREF_NO_IMM(cpy_r_r64);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 31, CPyStatic__argspec___globals);
        goto CPyL90;
    }
    cpy_r_r89.f0 = cpy_r_r86;
    cpy_r_r89.f1 = cpy_r_r87;
    cpy_r_r89.f2 = cpy_r_r88;
    cpy_r_r90 = PyTuple_New(3);
    if (unlikely(cpy_r_r90 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp51 = cpy_r_r89.f0;
    PyTuple_SET_ITEM(cpy_r_r90, 0, __tmp51);
    PyObject *__tmp52 = cpy_r_r89.f1;
    PyTuple_SET_ITEM(cpy_r_r90, 1, __tmp52);
    PyObject *__tmp53 = cpy_r_r89.f2;
    PyTuple_SET_ITEM(cpy_r_r90, 2, __tmp53);
    cpy_r_r91 = PyObject_GetItem(cpy_r_r85, cpy_r_r90);
    CPy_DECREF(cpy_r_r85);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 31, CPyStatic__argspec___globals);
        goto CPyL67;
    }
    if (likely(PyTuple_Check(cpy_r_r91)))
        cpy_r_r92 = cpy_r_r91;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 31, CPyStatic__argspec___globals, "tuple", cpy_r_r91);
        goto CPyL67;
    }
    return cpy_r_r92;
CPyL64: ;
    cpy_r_r93 = CPyStatic__argspec___globals;
    cpy_r_r94 = CPyStatics[115]; /* 'Any' */
    cpy_r_r95 = CPyDict_GetItem(cpy_r_r93, cpy_r_r94);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 33, CPyStatic__argspec___globals);
        goto CPyL67;
    }
    if (likely(PyTuple_Check(cpy_r_r95)))
        cpy_r_r96 = cpy_r_r95;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 33, CPyStatic__argspec___globals, "tuple", cpy_r_r95);
        goto CPyL67;
    }
    return cpy_r_r96;
CPyL67: ;
    cpy_r_r97 = NULL;
    return cpy_r_r97;
CPyL68: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL67;
CPyL69: ;
    CPy_DECREF(cpy_r_r13);
    goto CPyL13;
CPyL70: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r13);
    goto CPyL67;
CPyL71: ;
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r24);
    goto CPyL67;
CPyL72: ;
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r28);
    goto CPyL67;
CPyL73: ;
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF_NO_IMM(cpy_r_r28);
    goto CPyL36;
CPyL74: ;
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r29);
    goto CPyL67;
CPyL75: ;
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    goto CPyL67;
CPyL76: ;
    CPyTagged_DecRef(cpy_r_r24);
    goto CPyL67;
CPyL77: ;
    CPyTagged_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r57);
    goto CPyL67;
CPyL78: ;
    CPyTagged_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r59);
    goto CPyL67;
CPyL79: ;
    CPy_DECREF(cpy_r_r60);
    goto CPyL39;
CPyL80: ;
    CPyTagged_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r61);
    goto CPyL67;
CPyL81: ;
    CPyTagged_DECREF(cpy_r_r24);
    goto CPyL44;
CPyL82: ;
    CPy_DecRef(cpy_r_r64);
    goto CPyL67;
CPyL83: ;
    CPy_DecRef(cpy_r_r68);
    goto CPyL67;
CPyL84: ;
    CPyTagged_DECREF(cpy_r_r24);
    goto CPyL50;
CPyL85: ;
    CPy_DecRef(cpy_r_r64);
    CPy_DecRef(cpy_r_r75);
    goto CPyL67;
CPyL86: ;
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r76);
    goto CPyL67;
CPyL87: ;
    CPy_DECREF_NO_IMM(cpy_r_r64);
    goto CPyL64;
CPyL88: ;
    CPy_DecRef(cpy_r_r64);
    CPy_DecRef(cpy_r_r85);
    goto CPyL67;
CPyL89: ;
    CPy_DecRef(cpy_r_r64);
    CPy_DecRef(cpy_r_r85);
    CPy_DecRef(cpy_r_r86);
    goto CPyL67;
CPyL90: ;
    CPy_DecRef(cpy_r_r85);
    CPy_DecRef(cpy_r_r86);
    CPy_DecRef(cpy_r_r87);
    goto CPyL67;
}

PyObject *CPyPy__argspec___get_kwargs_type(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"sample", 0};
    static CPyArg_Parser parser = {"O:get_kwargs_type", kwlist, 0};
    PyObject *obj_sample;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_sample)) {
        return NULL;
    }
    PyObject *arg_sample = obj_sample;
    PyObject *retval = CPyDef__argspec___get_kwargs_type(arg_sample);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_argspec.py", "get_kwargs_type", 17, CPyStatic__argspec___globals);
    return NULL;
}

PyObject *CPyDef__argspec___get_return_type(PyObject *cpy_r_sample) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    cpy_r_r0 = CPyStatic__argspec___globals;
    cpy_r_r1 = CPyStatics[113]; /* 'getfullargspec' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_return_type", 37, CPyStatic__argspec___globals);
        goto CPyL14;
    }
    PyObject *cpy_r_r3[1] = {cpy_r_sample};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_Vectorcall(cpy_r_r2, cpy_r_r4, 1, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_return_type", 37, CPyStatic__argspec___globals);
        goto CPyL14;
    }
    if (likely(PyTuple_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_return_type", 37, CPyStatic__argspec___globals, "tuple", cpy_r_r5);
        goto CPyL14;
    }
    cpy_r_r7 = CPyStatics[116]; /* 'return' */
    cpy_r_r8 = CPySequenceTuple_GetItem(cpy_r_r6, 12);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_return_type", 38, CPyStatic__argspec___globals);
        goto CPyL15;
    }
    if (likely(PyDict_Check(cpy_r_r8)))
        cpy_r_r9 = cpy_r_r8;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_return_type", 38, CPyStatic__argspec___globals, "dict", cpy_r_r8);
        goto CPyL15;
    }
    cpy_r_r10 = PyDict_Contains(cpy_r_r9, cpy_r_r7);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_return_type", 38, CPyStatic__argspec___globals);
        goto CPyL15;
    }
    cpy_r_r12 = cpy_r_r10;
    if (!cpy_r_r12) goto CPyL16;
    cpy_r_r13 = CPySequenceTuple_GetItem(cpy_r_r6, 12);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_return_type", 38, CPyStatic__argspec___globals);
        goto CPyL14;
    }
    if (likely(PyDict_Check(cpy_r_r13)))
        cpy_r_r14 = cpy_r_r13;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_argspec.py", "get_return_type", 38, CPyStatic__argspec___globals, "dict", cpy_r_r13);
        goto CPyL14;
    }
    cpy_r_r15 = CPyStatics[116]; /* 'return' */
    cpy_r_r16 = CPyDict_GetItem(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_return_type", 38, CPyStatic__argspec___globals);
        goto CPyL14;
    }
    cpy_r_r17 = cpy_r_r16;
    goto CPyL13;
CPyL11: ;
    cpy_r_r18 = CPyStatic__argspec___globals;
    cpy_r_r19 = CPyStatics[115]; /* 'Any' */
    cpy_r_r20 = CPyDict_GetItem(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_return_type", 38, CPyStatic__argspec___globals);
        goto CPyL14;
    }
    cpy_r_r17 = cpy_r_r20;
CPyL13: ;
    return cpy_r_r17;
CPyL14: ;
    cpy_r_r21 = NULL;
    return cpy_r_r21;
CPyL15: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL14;
CPyL16: ;
    CPy_DECREF(cpy_r_r6);
    goto CPyL11;
}

PyObject *CPyPy__argspec___get_return_type(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"sample", 0};
    static CPyArg_Parser parser = {"O:get_return_type", kwlist, 0};
    PyObject *obj_sample;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_sample)) {
        return NULL;
    }
    PyObject *arg_sample = obj_sample;
    PyObject *retval = CPyDef__argspec___get_return_type(arg_sample);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio/_argspec.py", "get_return_type", 36, CPyStatic__argspec___globals);
    return NULL;
}

tuple_T3OOO CPyDef__argspec___get_types(PyObject *cpy_r_sample) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    tuple_T3OOO cpy_r_r3;
    tuple_T3OOO cpy_r_r4;
    tuple_T3OOO cpy_r_r5;
    cpy_r_r0 = CPyDef__argspec___get_args_type(cpy_r_sample);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_types", 42, CPyStatic__argspec___globals);
        goto CPyL4;
    }
    cpy_r_r1 = CPyDef__argspec___get_kwargs_type(cpy_r_sample);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_types", 42, CPyStatic__argspec___globals);
        goto CPyL5;
    }
    cpy_r_r2 = CPyDef__argspec___get_return_type(cpy_r_sample);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "get_types", 42, CPyStatic__argspec___globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_r0);
    CPy_INCREF(cpy_r_r1);
    CPy_INCREF(cpy_r_r2);
    cpy_r_r3.f0 = cpy_r_r0;
    cpy_r_r3.f1 = cpy_r_r1;
    cpy_r_r3.f2 = cpy_r_r2;
    CPy_DECREF(cpy_r_r3.f0);
    CPy_DECREF(cpy_r_r3.f1);
    CPy_DECREF(cpy_r_r3.f2);
    cpy_r_r4.f0 = cpy_r_r0;
    cpy_r_r4.f1 = cpy_r_r1;
    cpy_r_r4.f2 = cpy_r_r2;
    return cpy_r_r4;
CPyL4: ;
    tuple_T3OOO __tmp54 = { NULL, NULL, NULL };
    cpy_r_r5 = __tmp54;
    return cpy_r_r5;
CPyL5: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL4;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL4;
}

PyObject *CPyPy__argspec___get_types(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"sample", 0};
    static CPyArg_Parser parser = {"O:get_types", kwlist, 0};
    PyObject *obj_sample;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_sample)) {
        return NULL;
    }
    PyObject *arg_sample = obj_sample;
    tuple_T3OOO retval = CPyDef__argspec___get_types(arg_sample);
    if (retval.f0 == NULL) {
        return NULL;
    }
    PyObject *retbox = PyTuple_New(3);
    if (unlikely(retbox == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp55 = retval.f0;
    PyTuple_SET_ITEM(retbox, 0, __tmp55);
    PyObject *__tmp56 = retval.f1;
    PyTuple_SET_ITEM(retbox, 1, __tmp56);
    PyObject *__tmp57 = retval.f2;
    PyTuple_SET_ITEM(retbox, 2, __tmp57);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio/_argspec.py", "get_types", 41, CPyStatic__argspec___globals);
    return NULL;
}

char CPyDef__argspec_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[22]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "<module>", -1, CPyStatic__argspec___globals);
        goto CPyL6;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[453]; /* ('getfullargspec',) */
    cpy_r_r6 = CPyStatics[117]; /* 'inspect' */
    cpy_r_r7 = CPyStatic__argspec___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "<module>", 1, CPyStatic__argspec___globals);
        goto CPyL6;
    }
    CPyModule_inspect = cpy_r_r8;
    CPy_INCREF(CPyModule_inspect);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[454]; /* ('Any', 'Callable', 'List', 'Tuple', 'Type') */
    cpy_r_r10 = CPyStatics[35]; /* 'typing' */
    cpy_r_r11 = CPyStatic__argspec___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_argspec.py", "<module>", 2, CPyStatic__argspec___globals);
        goto CPyL6;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    return 1;
CPyL6: ;
    cpy_r_r13 = 2;
    return cpy_r_r13;
}
static PyMethodDef _configmodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _configmodule = {
    PyModuleDef_HEAD_INIT,
    "eth_portfolio._config",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    _configmodule_methods
};

PyObject *CPyInit_eth_portfolio____config(void)
{
    PyObject* modname = NULL;
    if (CPyModule_eth_portfolio____config_internal) {
        Py_INCREF(CPyModule_eth_portfolio____config_internal);
        return CPyModule_eth_portfolio____config_internal;
    }
    CPyModule_eth_portfolio____config_internal = PyModule_Create(&_configmodule);
    if (unlikely(CPyModule_eth_portfolio____config_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_eth_portfolio____config_internal, "__name__");
    CPyStatic__config___globals = PyModule_GetDict(CPyModule_eth_portfolio____config_internal);
    if (unlikely(CPyStatic__config___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__config_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_eth_portfolio____config_internal;
    fail:
    Py_CLEAR(CPyModule_eth_portfolio____config_internal);
    Py_CLEAR(modname);
    CPyTagged_XDECREF(CPyStatic__config___REORG_BUFFER);
    CPyStatic__config___REORG_BUFFER = CPY_INT_TAG;
    return NULL;
}

char CPyDef__config_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    CPyTagged cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    int32_t cpy_r_r36;
    char cpy_r_r37;
    char cpy_r_r38;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[22]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_config.py", "<module>", -1, CPyStatic__config___globals);
        goto CPyL11;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_os;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[456]; /* (('os', 'os', 'os'),) */
    cpy_r_r11 = CPyStatic__config___globals;
    cpy_r_r12 = CPyStatics[122]; /* 'eth_portfolio/_config.py' */
    cpy_r_r13 = CPyStatics[26]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL11;
    cpy_r_r15 = CPyStatics[436]; /* ('Final',) */
    cpy_r_r16 = CPyStatics[35]; /* 'typing' */
    cpy_r_r17 = CPyStatic__config___globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_config.py", "<module>", 2, CPyStatic__config___globals);
        goto CPyL11;
    }
    CPyModule_typing = cpy_r_r18;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyModule_os;
    cpy_r_r20 = CPyStatics[123]; /* 'environ' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_config.py", "<module>", 4, CPyStatic__config___globals);
        goto CPyL11;
    }
    cpy_r_r22 = CPyStatics[124]; /* 'REORG_BUFFER' */
    cpy_r_r23 = CPyStatics[125]; /* 'get' */
    cpy_r_r24 = CPyStatics[418]; /* 30 */
    PyObject *cpy_r_r25[3] = {cpy_r_r21, cpy_r_r22, cpy_r_r24};
    cpy_r_r26 = (PyObject **)&cpy_r_r25;
    cpy_r_r27 = PyObject_VectorcallMethod(cpy_r_r23, cpy_r_r26, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_config.py", "<module>", 4, CPyStatic__config___globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r21);
    cpy_r_r28 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r29[1] = {cpy_r_r27};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = PyObject_Vectorcall(cpy_r_r28, cpy_r_r30, 1, 0);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_config.py", "<module>", 4, CPyStatic__config___globals);
        goto CPyL13;
    }
    CPy_DECREF(cpy_r_r27);
    if (likely(PyLong_Check(cpy_r_r31)))
        cpy_r_r32 = CPyTagged_FromObject(cpy_r_r31);
    else {
        CPy_TypeError("int", cpy_r_r31); cpy_r_r32 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/_config.py", "<module>", 4, CPyStatic__config___globals);
        goto CPyL11;
    }
    CPyStatic__config___REORG_BUFFER = cpy_r_r32;
    CPyTagged_INCREF(CPyStatic__config___REORG_BUFFER);
    cpy_r_r33 = CPyStatic__config___globals;
    cpy_r_r34 = CPyStatics[124]; /* 'REORG_BUFFER' */
    cpy_r_r35 = CPyTagged_StealAsObject(cpy_r_r32);
    cpy_r_r36 = CPyDict_SetItem(cpy_r_r33, cpy_r_r34, cpy_r_r35);
    CPy_DECREF(cpy_r_r35);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("eth_portfolio/_config.py", "<module>", 4, CPyStatic__config___globals);
        goto CPyL11;
    }
    return 1;
CPyL11: ;
    cpy_r_r38 = 2;
    return cpy_r_r38;
CPyL12: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL11;
CPyL13: ;
    CPy_DecRef(cpy_r_r27);
    goto CPyL11;
}
static PyMethodDef _shitcoinsmodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _shitcoinsmodule = {
    PyModuleDef_HEAD_INIT,
    "eth_portfolio._shitcoins",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    _shitcoinsmodule_methods
};

PyObject *CPyInit_eth_portfolio____shitcoins(void)
{
    PyObject* modname = NULL;
    if (CPyModule_eth_portfolio____shitcoins_internal) {
        Py_INCREF(CPyModule_eth_portfolio____shitcoins_internal);
        return CPyModule_eth_portfolio____shitcoins_internal;
    }
    CPyModule_eth_portfolio____shitcoins_internal = PyModule_Create(&_shitcoinsmodule);
    if (unlikely(CPyModule_eth_portfolio____shitcoins_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_eth_portfolio____shitcoins_internal, "__name__");
    CPyStatic__shitcoins___globals = PyModule_GetDict(CPyModule_eth_portfolio____shitcoins_internal);
    if (unlikely(CPyStatic__shitcoins___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__shitcoins_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_eth_portfolio____shitcoins_internal;
    fail:
    Py_CLEAR(CPyModule_eth_portfolio____shitcoins_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic__shitcoins___shitcoins);
    CPyStatic__shitcoins___shitcoins = NULL;
    return NULL;
}

char CPyDef__shitcoins_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    CPyPtr cpy_r_r243;
    CPyPtr cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    CPyPtr cpy_r_r258;
    CPyPtr cpy_r_r259;
    CPyPtr cpy_r_r260;
    CPyPtr cpy_r_r261;
    CPyPtr cpy_r_r262;
    CPyPtr cpy_r_r263;
    CPyPtr cpy_r_r264;
    CPyPtr cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_r272;
    PyObject *cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject *cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    PyObject *cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    int32_t cpy_r_r292;
    char cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject **cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject *cpy_r_r303;
    int32_t cpy_r_r304;
    char cpy_r_r305;
    PyObject *cpy_r_r306;
    char cpy_r_r307;
    CPyTagged cpy_r_r308;
    int64_t cpy_r_r309;
    CPyTagged cpy_r_r310;
    PyObject *cpy_r_r311;
    tuple_T4CIOO cpy_r_r312;
    CPyTagged cpy_r_r313;
    char cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    PyObject *cpy_r_r318;
    PyObject *cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    int32_t cpy_r_r322;
    char cpy_r_r323;
    int32_t cpy_r_r324;
    char cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    PyObject *cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject *cpy_r_r332;
    PyObject *cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    CPyPtr cpy_r_r339;
    int64_t cpy_r_r340;
    PyObject *cpy_r_r341;
    CPyTagged cpy_r_r342;
    CPyPtr cpy_r_r343;
    int64_t cpy_r_r344;
    CPyTagged cpy_r_r345;
    char cpy_r_r346;
    int64_t cpy_r_r347;
    CPyPtr cpy_r_r348;
    CPyPtr cpy_r_r349;
    int64_t cpy_r_r350;
    CPyPtr cpy_r_r351;
    PyObject *cpy_r_r352;
    PyObject *cpy_r_r353;
    PyObject *cpy_r_r354;
    PyObject *cpy_r_r355;
    PyObject *cpy_r_r356;
    PyObject *cpy_r_r357;
    PyObject *cpy_r_r358;
    PyObject **cpy_r_r360;
    PyObject *cpy_r_r361;
    char cpy_r_r362;
    CPyTagged cpy_r_r363;
    int32_t cpy_r_r364;
    char cpy_r_r365;
    char cpy_r_r366;
    char cpy_r_r367;
    char cpy_r_r368;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[22]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", -1, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[423]; /* ('defaultdict',) */
    cpy_r_r6 = CPyStatics[27]; /* 'collections' */
    cpy_r_r7 = CPyStatic__shitcoins___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 1, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    CPyModule_collections = cpy_r_r8;
    CPy_INCREF(CPyModule_collections);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[457]; /* ('DefaultDict', 'Final', 'Set') */
    cpy_r_r10 = CPyStatics[35]; /* 'typing' */
    cpy_r_r11 = CPyStatic__shitcoins___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 2, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[458]; /* ('ChecksumAddress',) */
    cpy_r_r14 = CPyStatics[40]; /* 'eth_typing' */
    cpy_r_r15 = CPyStatic__shitcoins___globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 4, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    CPyModule_eth_typing = cpy_r_r16;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[459]; /* ('Network', 'convert') */
    cpy_r_r18 = CPyStatics[79]; /* 'y' */
    cpy_r_r19 = CPyStatic__shitcoins___globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 5, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    CPyModule_y = cpy_r_r20;
    CPy_INCREF(CPyModule_y);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatic__shitcoins___globals;
    cpy_r_r22 = CPyStatics[127]; /* 'Network' */
    cpy_r_r23 = CPyDict_GetItem(cpy_r_r21, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 8, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    cpy_r_r24 = CPyStatics[129]; /* 'Mainnet' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 8, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    cpy_r_r26 = CPyStatics[130]; /* '0xb8ac53AFCCEBc44AaC33D0C30E2Ae0783E7fde5f' */
    cpy_r_r27 = CPyStatics[131]; /* '0xe397ef3E332256F38983ffaE987158da3e18c5Ec' */
    cpy_r_r28 = CPyStatics[132]; /* '0x7452E3fC2fE611C6B7761c6c393BECe059881aC7' */
    cpy_r_r29 = CPyStatics[133]; /* '0x4ab16CDc82a4eA4727Ab40caee1bb46622C13641' */
    cpy_r_r30 = CPyStatics[134]; /* '0x471c3A7f132bc94938516CB2Bf6f02C7521D2797' */
    cpy_r_r31 = CPyStatics[135]; /* '0x106EebF11F34ECCcaD59c1CA9398d828765f64f8' */
    cpy_r_r32 = CPyStatics[136]; /* '0x634a31d5DB29F2a646bADAd27bb7b1E5A78FD316' */
    cpy_r_r33 = CPyStatics[137]; /* '0xF673623e8507551BDe72290E909c7E184A4799a3' */
    cpy_r_r34 = CPyStatics[138]; /* '0x269641A320F8465eF4e710F51Dc6e6862D7E8A77' */
    cpy_r_r35 = CPyStatics[139]; /* '0x956F824B5a37673c6fC4a6904186cB3BA499349B' */
    cpy_r_r36 = CPyStatics[140]; /* '0xBFA9180729f1c549334080005Ca37093593fB7Aa' */
    cpy_r_r37 = CPyStatics[141]; /* '0x643695D282f6BA237afe27FFE0Acd89a86b50d3e' */
    cpy_r_r38 = CPyStatics[142]; /* '0xCfB0Ef3e179427316FBD7F0D0296F173762BeEE0' */
    cpy_r_r39 = CPyStatics[143]; /* '0xfAFe8a7c0A9b3807CC1df0DEB0BA0B5a5fb7A872' */
    cpy_r_r40 = CPyStatics[144]; /* '0xdf66B9727553fB9Bfa417699CB8F60425d62d1E3' */
    cpy_r_r41 = CPyStatics[145]; /* '0x68Ca006dB91312Cd60a2238Ce775bE5F9f738bBa' */
    cpy_r_r42 = CPyStatics[146]; /* '0xBCCBeDAb3Bf6FA1cfC3e2d07Aa5ce4A282864D6E' */
    cpy_r_r43 = CPyStatics[147]; /* '0x26004d228fC8A32c5bd1a106108c8647A455B04a' */
    cpy_r_r44 = CPyStatics[148]; /* '0x635701CC5fE41FE8AbD02aa74Beb02e3540E9BB2' */
    cpy_r_r45 = CPyStatics[149]; /* '0xf8358bd95dcA48187e3F4BE05847F3593776C086' */
    cpy_r_r46 = CPyStatics[150]; /* '0x459176FDC68C945B6bb23eB946eee62457041567' */
    cpy_r_r47 = CPyStatics[151]; /* '0xf55F8aA8F3d777f1aB3A4ae9E269C8D7B73078De' */
    cpy_r_r48 = CPyStatics[152]; /* '0x434d5875534D19fC7105281Cf61dbfd1C93c8cb1' */
    cpy_r_r49 = CPyStatics[153]; /* '0x908599FDf490b73D171B57731bd4Ca95b7F0DE6a' */
    cpy_r_r50 = CPyStatics[154]; /* '0x4709099BE25D156578405132d66aeBfC2e12937A' */
    cpy_r_r51 = CPyStatics[155]; /* '0x82315517d61ecf47f9A78705127934F3d431cB21' */
    cpy_r_r52 = CPyStatics[156]; /* '0x2B000332CD291eF558aF76298A4d6F6001E4e015' */
    cpy_r_r53 = CPyStatics[157]; /* '0x163F4D81d86ac282A0F0F94D9FE3E0321ACcfd37' */
    cpy_r_r54 = CPyStatics[158]; /* '0x660235331d2FA5FeB7a49F31556B0Be31f02560D' */
    cpy_r_r55 = CPyStatics[159]; /* '0x696F33F4dd9BE5538483f63308453D2D67D07331' */
    cpy_r_r56 = CPyStatics[160]; /* '0xcbbadd74b3bb09836d97d91050e13E06089ba485' */
    cpy_r_r57 = CPyStatics[161]; /* '0xE0c31b3e341E7EF3C04eB14E58802b88a80A45A1' */
    cpy_r_r58 = CPyStatics[162]; /* '0xA6D74802a2222d5cCe5eA0531159ed878943b54c' */
    cpy_r_r59 = CPyStatics[163]; /* '0xcAB80A2bf07BECaF8d48168081352ea873B8Db91' */
    cpy_r_r60 = CPyStatics[164]; /* '0x72B12aec69dA93357f2B69aCf33d5B75cF17575B' */
    cpy_r_r61 = CPyStatics[165]; /* '0xA4C8A13FeE3b19718E45d678C071bDE3e33A7302' */
    cpy_r_r62 = CPyStatics[166]; /* '0x579e4ca5888eD1420492988BF75E26D9e7B4C535' */
    cpy_r_r63 = CPyStatics[167]; /* '0xB80216D5b4eec2BEc74eF10e5d3814Fec6Fd8af0' */
    cpy_r_r64 = CPyStatics[168]; /* '0x6A007E207E50B4C6B2ADCFc6a873F6e698645fE3' */
    cpy_r_r65 = CPyStatics[169]; /* '0x84d12988D71244a8937a9816037BeB3e61E17FdD' */
    cpy_r_r66 = CPyStatics[170]; /* '0x0734E85525Ca6838fe48EC6EB29b9d457F254F73' */
    cpy_r_r67 = CPyStatics[171]; /* '0xa10c97bF5629340A35c41a8AA308af0804750605' */
    cpy_r_r68 = CPyStatics[172]; /* '0x69D732F50e248D4B825d524fEDEB0D7Ce3d76352' */
    cpy_r_r69 = CPyStatics[173]; /* '0xAF0b2fBeDd5d1Fda457580FB3DAbAD1F5C8bBC36' */
    cpy_r_r70 = CPyStatics[174]; /* '0xbadb4170Cd3309680477Fc81D527101cbB4000EE' */
    cpy_r_r71 = CPyStatics[175]; /* '0x7841479c5976b8184DBcde9a7a5113901b233EfB' */
    cpy_r_r72 = CPyStatics[176]; /* '0x1e4A0ADFC2e9bf2Dfd041Bc89405538d0D5A077a' */
    cpy_r_r73 = CPyStatics[177]; /* '0xb07de4b2989E180F8907B8C7e617637C26cE2776' */
    cpy_r_r74 = CPyStatics[178]; /* '0xa9517B2E61a57350D6555665292dBC632C76adFe' */
    cpy_r_r75 = CPyStatics[179]; /* '0x38715Ab4b9d4e00890773D7338d94778b0dFc0a8' */
    cpy_r_r76 = CPyStatics[180]; /* '0x6171136E82a2f1bAA2494c69528f599467EfeA20' */
    cpy_r_r77 = CPyStatics[181]; /* '0x9Ee582c42F88CAA5e7BCDE2e86e69Af3Cf5FCe40' */
    cpy_r_r78 = CPyStatics[182]; /* '0xFD1860C9d602236214652a21753731F9acD2C362' */
    cpy_r_r79 = CPyStatics[183]; /* '0x0Fd23DaB8723b1Fd5e7c3d74Baa624B443423b6B' */
    cpy_r_r80 = CPyStatics[184]; /* '0xe0736F3F455F1DBD29Bf6F8346EAd22f5CF78d08' */
    cpy_r_r81 = CPyStatics[185]; /* '0x7F57A01fc540ca3A26345C4903B9a220aD048196' */
    cpy_r_r82 = CPyStatics[148]; /* '0x635701CC5fE41FE8AbD02aa74Beb02e3540E9BB2' */
    cpy_r_r83 = CPyStatics[186]; /* '0xF709642622729feafC8bf0934679706df49d8A30' */
    cpy_r_r84 = CPyStatics[187]; /* '0x0bF377fb3b5F1dD601e693B8fAF6b0bD249f37D3' */
    cpy_r_r85 = CPyStatics[188]; /* '0xBf5fB1563ef58ba41325454ca61Cc3D62bd40744' */
    cpy_r_r86 = CPyStatics[189]; /* '0x54fd62228C6e1234fd5Fded28555CA963Dcf6d26' */
    cpy_r_r87 = CPyStatics[190]; /* '0xA36Ceec605d81aE74268Fda28A5c0Bd10b1D1f7C' */
    cpy_r_r88 = CPyStatics[191]; /* '0xF9d25EB4C75ed744596392cf89074aFaA43614a8' */
    cpy_r_r89 = CPyStatics[192]; /* '0x1412ECa9dc7daEf60451e3155bB8Dbf9DA349933' */
    cpy_r_r90 = CPyStatics[193]; /* '0x1fc4DB3e7f9124bAAFB7B34346dB7931Dad621C2' */
    cpy_r_r91 = CPyStatics[194]; /* '0x120aA018634F555484c088c8da80F75Aa07E004F' */
    cpy_r_r92 = CPyStatics[195]; /* '0xeDe11D3d5dd7D5454844f6f121cc106bF1144a45' */
    cpy_r_r93 = CPyStatics[196]; /* '0x875bf9be244970B8572DD042053508bF758371Ee' */
    cpy_r_r94 = CPyStatics[197]; /* '0x070C0147884D7CF984aFBC2Eb6F3428A39b5E229' */
    cpy_r_r95 = CPyStatics[198]; /* '0xb0B1d4732eFE32AEA466ED6BC3c79181eD4810c4' */
    cpy_r_r96 = CPyStatics[199]; /* '0xCf39B7793512F03f2893C16459fd72E65D2Ed00c' */
    cpy_r_r97 = CPyStatics[200]; /* '0x89532890c2959e836C1Bca52309356841238b8B7' */
    cpy_r_r98 = CPyStatics[201]; /* '0xD1B0c350f73E6f7Cd5c9978b82B46a59aE9aD524' */
    cpy_r_r99 = CPyStatics[202]; /* '0x17a10104CBC1eD155D083eaD9FCF5C3440bb50e8' */
    cpy_r_r100 = CPyStatics[203]; /* '0x8eB3FecAAA963C86d9b49004d9f28092f1Db3D6c' */
    cpy_r_r101 = CPyStatics[204]; /* '0x52bbca3B24c1c1ac050fF4546F37AA88282aaE22' */
    cpy_r_r102 = CPyStatics[205]; /* '0xECF0dE4C8498Cfd686E4702D955426b22d812d6B' */
    cpy_r_r103 = CPyStatics[206]; /* '0xF01f7A348681776c1FC9A066c6973882B693cdC6' */
    cpy_r_r104 = CPyStatics[207]; /* '0x0e1CD6d2715432e4DBedFE969b0Eb2867FF61d5b' */
    cpy_r_r105 = CPyStatics[208]; /* '0x174Cd3359C6a4E6B64D2995Da4E2E4631379526E' */
    cpy_r_r106 = CPyStatics[209]; /* '0x85E199607eb8aEef775Ae6424b42d20616267852' */
    cpy_r_r107 = CPyStatics[210]; /* '0x4D57c67C8Bab0Fb3A0a0A35B904FBff4E5450521' */
    cpy_r_r108 = CPyStatics[211]; /* '0x884a886D17a64852d18e5921fA7A05ae2954C9Bb' */
    cpy_r_r109 = CPyStatics[212]; /* '0xbB5c3B198f6def369bFB6AC7A34BB08eA49a0770' */
    cpy_r_r110 = CPyStatics[213]; /* '0x5be480Aa056ec274e5aE970d7A75dF0c9620F6F8' */
    cpy_r_r111 = CPyStatics[214]; /* '0xA1f76F1c94078f7d2E05152DC3e31dED819dfDC0' */
    cpy_r_r112 = CPyStatics[215]; /* '0xCE3F076D0ADa9f913a24F42dEAB82e4b851B87d6' */
    cpy_r_r113 = CPyStatics[216]; /* '0xB215F3927192181eBCD79227c70c10015Ff10df3' */
    cpy_r_r114 = CPyStatics[217]; /* '0x37843BC944eDBb0477df943d9061D359004a4e70' */
    cpy_r_r115 = CPyStatics[218]; /* '0x9A7ddeE20b61EA4f4812665EdF39dD157a66E873' */
    cpy_r_r116 = CPyStatics[219]; /* '0xfcBe0B695c13257bd43D64f09Db433034E90033D' */
    cpy_r_r117 = CPyStatics[220]; /* '0x7d09A736c5FB1Db357dE04A07DEB22D5829DA26F' */
    cpy_r_r118 = CPyStatics[221]; /* '0x6Ac9cA5710Ba6B985b46fd5282a59eBbea3434d4' */
    cpy_r_r119 = CPyStatics[222]; /* '0xD6619A3E925472a8d7822Cc6A49B76b3554A3498' */
    cpy_r_r120 = CPyStatics[223]; /* '0x338C1E2B51C4E818765a887584e7041EF9070aef' */
    cpy_r_r121 = CPyStatics[224]; /* '0x83D473D1acD97Aa45A97c3b778fB5714e7e4c604' */
    cpy_r_r122 = CPyStatics[225]; /* '0x5bb38F4899797f03141782E9d2130C12769c0CCc' */
    cpy_r_r123 = CPyStatics[226]; /* '0x1F7B20004eBd7E258b9f45568cE789fC5d2140fb' */
    cpy_r_r124 = CPyStatics[227]; /* '0x92Aeed8027735C41605577b45A69429Bd7f729f9' */
    cpy_r_r125 = CPyStatics[228]; /* '0x8A801C334ebaC763822a0D85a595AeC6Da59C232' */
    cpy_r_r126 = CPyStatics[229]; /* '0xd5b0Bd07864C0aaCC3b6Cd5e63C68c62C0F263d2' */
    cpy_r_r127 = CPyStatics[230]; /* '0x2b23BF339F5cc3393a558373E0A73a576F0838D3' */
    cpy_r_r128 = CPyStatics[231]; /* '0x7B2e238FB48ee7322664B9C26bb3ACedBfCC1f70' */
    cpy_r_r129 = CPyStatics[232]; /* '0x08918171758171A13050cdE6Cc6eB90172Af5737' */
    cpy_r_r130 = CPyStatics[233]; /* '0x9398c448728738039b91687919262194899D3f27' */
    cpy_r_r131 = CPyStatics[234]; /* '0x0A527683c3154F5F9E1b4203Ef4d05962b2411bf' */
    cpy_r_r132 = CPyStatics[235]; /* '0xe3C6F9D0d731C2Eb6B6D3eBFb6732fCd26a365d0' */
    cpy_r_r133 = CPyStatics[236]; /* '0x6cF0B5A20B2d4b55e6b752d7016275B892035652' */
    cpy_r_r134 = CPyStatics[237]; /* '0x98d1c76831c0aBEa30e3dac8628BD72d6B0E3dd2' */
    cpy_r_r135 = CPyStatics[238]; /* '0x4C6fDc0476B2FE0daFf0B5824c3A918673d6014E' */
    cpy_r_r136 = CPyStatics[239]; /* '0xC6d3D201530a6D4aD9dFbAAd39C5f68A9A470a69' */
    cpy_r_r137 = CPyStatics[240]; /* '0x525fC44CBE181C1108c209091B5EEc5a5028190d' */
    cpy_r_r138 = CPyStatics[241]; /* '0x7d1a6a4f806A4a64AD32e7F2350E176eA6B9a1F6' */
    cpy_r_r139 = CPyStatics[242]; /* '0x75E34A4A04d5f5F7Fc01801d2d287d64D882529B' */
    cpy_r_r140 = CPyStatics[243]; /* '0x8F49cB69ee13974D6396FC26B0c0D78044FCb3A7' */
    cpy_r_r141 = CPyStatics[244]; /* '0xB688d06d858E092EBB145394a1BA08C7a10E1F56' */
    cpy_r_r142 = CPyStatics[245]; /* '0x154C5875b1B0DB1794f88D003730DaD160E6b38e' */
    cpy_r_r143 = CPyStatics[246]; /* '0x11068577AE36897fFaB0024F010247B9129459E6' */
    cpy_r_r144 = CPyStatics[247]; /* '0xBA89375bAE9b3DE92442e9C037d4303A6e4FB086' */
    cpy_r_r145 = CPyStatics[248]; /* '0xcDbd4089C2F98DA715e52127680f87aFdB183A2e' */
    cpy_r_r146 = CPyStatics[249]; /* '0x3a3a4d2d9755283D9e25105B042C5f45BC0Edf05' */
    cpy_r_r147 = CPyStatics[250]; /* '0x70c18F2fDcb00d27494f767503874788e35c9940' */
    cpy_r_r148 = CPyStatics[251]; /* '0xF511123fdf2F13811abf4edDb493860101471729' */
    cpy_r_r149 = CPyStatics[252]; /* '0x830Cbe766EE470B67F77ea62a56246863F75f376' */
    cpy_r_r150 = CPyStatics[253]; /* '0x76988Eb5d8a81F44919d87328c36179FdCca044a' */
    cpy_r_r151 = CPyStatics[254]; /* '0xa6DE609807c7258A0D34F5307c1808F062A59794' */
    cpy_r_r152 = CPyStatics[255]; /* '0x698068C6a369b1BF04D516f5fE48424797973DCf' */
    cpy_r_r153 = CPyStatics[256]; /* '0xbEb3c5F7f4F8dB708BcfaC4D0fDcDb0bEd285741' */
    cpy_r_r154 = CPyStatics[257]; /* '0xCdC94877E4164D2e915fC5E8310155D661A995F1' */
    cpy_r_r155 = CPyStatics[258]; /* '0x5D80A8D8CB80696073e82407968600A37e1dd780' */
    cpy_r_r156 = CPyStatics[259]; /* '0x19383F024BA4c06e44D11a8B8BB7ebF87faB184C' */
    cpy_r_r157 = CPyStatics[260]; /* '0xF5b2C59F6DB42FFCdFC1625999C81fDF17953384' */
    cpy_r_r158 = CPyStatics[261]; /* '0xdb83eC9EEAC2b3CF8Eb282f91c73C38159578697' */
    cpy_r_r159 = CPyStatics[262]; /* '0x2F30E0F6B484eF6Be57b6435e34687018ff8Cb4D' */
    cpy_r_r160 = CPyStatics[263]; /* '0x242a705E8AF8A24B7EB30f3DbAF899eB25E3D76A' */
    cpy_r_r161 = CPyStatics[264]; /* '0x2f848B4A2B5dfC3b9e4Eb229551c0887E6348653' */
    cpy_r_r162 = CPyStatics[265]; /* '0x0795619E02716a81ac9EF6E55363D538DA104e57' */
    cpy_r_r163 = CPyStatics[266]; /* '0x6D9541ba0f1039d0f8636b4f39D20A8a7464f357' */
    cpy_r_r164 = CPyStatics[267]; /* '0x1C3d9Db84e0EEE4744893A7FAeE6187F31E39539' */
    cpy_r_r165 = CPyStatics[268]; /* '0x3654746Ce159BA2FCDF926133D51ecBb85f19288' */
    cpy_r_r166 = CPyStatics[269]; /* '0x67542502245eb5DF64eF7Ea776199CeB79401058' */
    cpy_r_r167 = CPyStatics[270]; /* '0x0951490Cec0261F60Ff0C42DE7F62488Cc8313D8' */
    cpy_r_r168 = CPyStatics[245]; /* '0x154C5875b1B0DB1794f88D003730DaD160E6b38e' */
    cpy_r_r169 = CPyStatics[271]; /* '0xcdBb37f84bf94492b44e26d1F990285401e5423e' */
    cpy_r_r170 = CPyStatics[272]; /* '0x53d345839E7dF5a6c8Cf590C5c703AE255E44816' */
    cpy_r_r171 = CPyStatics[273]; /* '0xCCCCee7d9B0f18ab16b217A794D2671549F1A895' */
    cpy_r_r172 = CPyStatics[274]; /* '0xc6a76f7ad66d0e6Ccd1AaAd6e7568c9bd55Dce62' */
    cpy_r_r173 = CPyStatics[275]; /* '0xB4d4334eB5a251cbE5cC7Afb0Ba26119aCE62281' */
    cpy_r_r174 = CPyStatics[276]; /* '0xE5c5AE39B98eFd9D3c9E0F2a5457D98fFA4b0b46' */
    cpy_r_r175 = CPyStatics[277]; /* '0x2Ec109a0ceFEC70661a242a8B54cae8f45630397' */
    cpy_r_r176 = CPyStatics[278]; /* '0x11d666B9C8fa057774324a9bFe6B53eB8d23079f' */
    cpy_r_r177 = CPyStatics[279]; /* '0x0598BEf845934d83463cEaDd8C86F0801e2Ee058' */
    cpy_r_r178 = CPyStatics[280]; /* '0xAcDfe439652F78750AFCe1BbA2cB9068EDb4e69c' */
    cpy_r_r179 = CPyStatics[281]; /* '0xd3cc310DD7b94D6Ef06615f73A3029A67d935c5E' */
    cpy_r_r180 = CPyStatics[282]; /* '0x0C6D7f5a8c122aCB941aCb95cb99C2cdE893b7a7' */
    cpy_r_r181 = CPyStatics[283]; /* '0xCBd85ffF5106a42d622be7F9e528DB0bfF07Da8A' */
    cpy_r_r182 = CPyStatics[284]; /* '0x22e810C6aed30FA93C2D2B62F456E5f78e8918e1' */
    cpy_r_r183 = CPyStatics[285]; /* '0xc750d0c91DD5f2D3964931FF5dC42B2bB3e008C1' */
    cpy_r_r184 = CPyStatics[286]; /* '0x6284C089D6944df1ba61bd56618AEba07D1d6136' */
    cpy_r_r185 = CPyStatics[287]; /* '0x4E654E3A532a386329bde5f01D0AC7995Ab94c07' */
    cpy_r_r186 = CPyStatics[288]; /* '0x570EC272F07c563860477DCAfB04a04FFd2979a1' */
    cpy_r_r187 = CPyStatics[289]; /* '0xEcd8eDb13Cd68707579D5EC891A24C03B8d5E831' */
    cpy_r_r188 = CPyStatics[290]; /* '0x5D6434D533922d60F1eeec913f680C5daF31cB9A' */
    cpy_r_r189 = CPyStatics[291]; /* '0x15B8adFa95e841a55867495F07B8102329546987' */
    cpy_r_r190 = CPyStatics[292]; /* '0xFe0bb2ae94BF11de9773DECb413b4a6a241cBCd0' */
    cpy_r_r191 = CPyStatics[293]; /* '0x4d3D07f4E7a154c32D36bBcBE2Ea64E0B6F98440' */
    cpy_r_r192 = CPyStatics[294]; /* '0xEea2fEf22353282fb760d27EA7A1E2f06B3F442d' */
    cpy_r_r193 = CPyStatics[295]; /* '0x218Ae209BEc57eeFa9149789aE09388459bC91d1' */
    cpy_r_r194 = CPyStatics[296]; /* '0x4639FFC90b0fD6Dffb57Af712109bfa419afaEB5' */
    cpy_r_r195 = CPyStatics[297]; /* '0x39dDC0a04F0E1F2830f3f1FEc414cD6E23168beE' */
    cpy_r_r196 = CPyStatics[298]; /* '0x4a41775Da459B38e641141e4C696DF10EC1f4983' */
    cpy_r_r197 = CPyStatics[299]; /* '0x72C07D9151DcE2ea862595487ef7e21cC312e564' */
    cpy_r_r198 = CPyStatics[300]; /* '0xE00cD9B8ebb503E4bE266983EfC6158fCFfe0004' */
    cpy_r_r199 = CPyStatics[301]; /* '0x46DDf95a62b0F2eF6dc4e70717f36172a595517F' */
    cpy_r_r200 = CPyStatics[302]; /* '0x7cfa05320D83A20980Ac76B91a3A11981877Ef3A' */
    cpy_r_r201 = CPyStatics[303]; /* '0xbbaC5B019876534c3C399F56E150684c5015F670' */
    cpy_r_r202 = CPyStatics[304]; /* '0x2840a9fC9ad15738c762e404300761eC828aFFCb' */
    cpy_r_r203 = CPyStatics[305]; /* '0xC1c8c49b0405f6CFfBA5351179bEFB2d8a2c776c' */
    cpy_r_r204 = CPyStatics[306]; /* '0xcB56B36Ef3d4E5C3b7d2fbC4f4Ee5d525893a555' */
    cpy_r_r205 = CPyStatics[307]; /* '0x5807daC5CC59F02dFA88154dE7F9f2174C263814' */
    cpy_r_r206 = CPyStatics[308]; /* '0x6545B409acdD7e1BE14C835B5c3B826C5d312D02' */
    cpy_r_r207 = CPyStatics[309]; /* '0xdF781bBA6F9EefB1A74bb39f6DF5e282c5976636' */
    cpy_r_r208 = CPyStatics[310]; /* '0x85D385244D41ac914484FD6fbBaB177c10A86e79' */
    cpy_r_r209 = CPyStatics[311]; /* '0xa51a8578052EdEB4Ced5333A5e058860d9E7a35b' */
    cpy_r_r210 = CPyStatics[312]; /* '0x7a6b87D7a874Fce4c2d923b09C0E09e4936bcF57' */
    cpy_r_r211 = CPyStatics[313]; /* '0xFabb91ae9318082505c2c6d7acD9d521d4eDDEFf' */
    cpy_r_r212 = CPyStatics[307]; /* '0x5807daC5CC59F02dFA88154dE7F9f2174C263814' */
    cpy_r_r213 = CPyStatics[314]; /* '0x4Fe8CEdb3f76Ed69b4914958B80Cf9c6D4E3b416' */
    cpy_r_r214 = CPyStatics[315]; /* '0xa75Fa7DEa69aBd84C9812919039Cb33e2092aab6' */
    cpy_r_r215 = CPyStatics[316]; /* '0x37dC2fD3A38fd3E898299E754C19772A67f1912B' */
    cpy_r_r216 = CPyStatics[317]; /* '0x445A32D3095D1ea8951180B0fD6004258beB72F3' */
    cpy_r_r217 = CPyStatics[318]; /* '0xBD3E4E06074F6bBDfa8B24Ba0736db4DE77EAF0A' */
    cpy_r_r218 = CPyStatics[319]; /* '0xAba86342C3f57E002F47F6eb38099A577312F2e8' */
    cpy_r_r219 = CPyStatics[320]; /* '0x94C4bfDD351A2EeA9d57e602C2a24d6Fe823Fd1a' */
    cpy_r_r220 = CPyStatics[321]; /* '0xAfF006725DeeAF5BF6750A6C7c98D9e70cB189a4' */
    cpy_r_r221 = CPyStatics[322]; /* '0x98a7800EB17e1A0e2b2A4b69e83c58F4535F2180' */
    cpy_r_r222 = CPyStatics[323]; /* '0xdC5BCA9992191c900D7A7F5b8e1b3e4161d1aa51' */
    cpy_r_r223 = CPyStatics[324]; /* '0xd27255AA153ae470419B0198fa61e892a612aFE8' */
    cpy_r_r224 = CPyStatics[325]; /* '0xbADbe6619c0563c60E62C7409681440a80391a27' */
    cpy_r_r225 = CPyStatics[326]; /* '0xf84f908E78f9295b53883AD9ACa38F86d513f03F' */
    cpy_r_r226 = CPyStatics[327]; /* '0x20Dd160716b0387220Eea7B9951bDb51B3728DC4' */
    cpy_r_r227 = CPyStatics[328]; /* '0xd91AdE7B3c349815e427cf678837cC12F72d1d38' */
    cpy_r_r228 = CPyStatics[329]; /* '0xa362389216664668bC195f6BF1940d3754914219' */
    cpy_r_r229 = CPyStatics[330]; /* '0x9257Cf49802E00048A30a6429e9c4d86210F4253' */
    cpy_r_r230 = CPyStatics[331]; /* '0x6b1b80b4b3228060EA21C292a3b9c576691Ca6cC' */
    cpy_r_r231 = CPyStatics[332]; /* '0x225795bb6D20773a4A34c682Ae8457D00C80F955' */
    cpy_r_r232 = CPyStatics[333]; /* '0x25741E94782d3EaA7fb0A02D78256bf065AEC3B9' */
    cpy_r_r233 = CPyStatics[334]; /* '0x3C78E3391C47fB9310BDB9085955934E1622442f' */
    cpy_r_r234 = CPyStatics[335]; /* '0x1f186De364a56e741Fcb188d37a393d409D08AeA' */
    CPy_INCREF(cpy_r_r26);
    CPy_INCREF(cpy_r_r27);
    CPy_INCREF(cpy_r_r28);
    CPy_INCREF(cpy_r_r29);
    CPy_INCREF(cpy_r_r30);
    CPy_INCREF(cpy_r_r31);
    CPy_INCREF(cpy_r_r32);
    CPy_INCREF(cpy_r_r33);
    CPy_INCREF(cpy_r_r34);
    CPy_INCREF(cpy_r_r35);
    CPy_INCREF(cpy_r_r36);
    CPy_INCREF(cpy_r_r37);
    CPy_INCREF(cpy_r_r38);
    CPy_INCREF(cpy_r_r39);
    CPy_INCREF(cpy_r_r40);
    CPy_INCREF(cpy_r_r41);
    CPy_INCREF(cpy_r_r42);
    CPy_INCREF(cpy_r_r43);
    CPy_INCREF(cpy_r_r44);
    CPy_INCREF(cpy_r_r45);
    CPy_INCREF(cpy_r_r46);
    CPy_INCREF(cpy_r_r47);
    CPy_INCREF(cpy_r_r48);
    CPy_INCREF(cpy_r_r49);
    CPy_INCREF(cpy_r_r50);
    CPy_INCREF(cpy_r_r51);
    CPy_INCREF(cpy_r_r52);
    CPy_INCREF(cpy_r_r53);
    CPy_INCREF(cpy_r_r54);
    CPy_INCREF(cpy_r_r55);
    CPy_INCREF(cpy_r_r56);
    CPy_INCREF(cpy_r_r57);
    CPy_INCREF(cpy_r_r58);
    CPy_INCREF(cpy_r_r59);
    CPy_INCREF(cpy_r_r60);
    CPy_INCREF(cpy_r_r61);
    CPy_INCREF(cpy_r_r62);
    CPy_INCREF(cpy_r_r63);
    CPy_INCREF(cpy_r_r64);
    CPy_INCREF(cpy_r_r65);
    CPy_INCREF(cpy_r_r66);
    CPy_INCREF(cpy_r_r67);
    CPy_INCREF(cpy_r_r68);
    CPy_INCREF(cpy_r_r69);
    CPy_INCREF(cpy_r_r70);
    CPy_INCREF(cpy_r_r71);
    CPy_INCREF(cpy_r_r72);
    CPy_INCREF(cpy_r_r73);
    CPy_INCREF(cpy_r_r74);
    CPy_INCREF(cpy_r_r75);
    CPy_INCREF(cpy_r_r76);
    CPy_INCREF(cpy_r_r77);
    CPy_INCREF(cpy_r_r78);
    CPy_INCREF(cpy_r_r79);
    CPy_INCREF(cpy_r_r80);
    CPy_INCREF(cpy_r_r81);
    CPy_INCREF(cpy_r_r82);
    CPy_INCREF(cpy_r_r83);
    CPy_INCREF(cpy_r_r84);
    CPy_INCREF(cpy_r_r85);
    CPy_INCREF(cpy_r_r86);
    CPy_INCREF(cpy_r_r87);
    CPy_INCREF(cpy_r_r88);
    CPy_INCREF(cpy_r_r89);
    CPy_INCREF(cpy_r_r90);
    CPy_INCREF(cpy_r_r91);
    CPy_INCREF(cpy_r_r92);
    CPy_INCREF(cpy_r_r93);
    CPy_INCREF(cpy_r_r94);
    CPy_INCREF(cpy_r_r95);
    CPy_INCREF(cpy_r_r96);
    CPy_INCREF(cpy_r_r97);
    CPy_INCREF(cpy_r_r98);
    CPy_INCREF(cpy_r_r99);
    CPy_INCREF(cpy_r_r100);
    CPy_INCREF(cpy_r_r101);
    CPy_INCREF(cpy_r_r102);
    CPy_INCREF(cpy_r_r103);
    CPy_INCREF(cpy_r_r104);
    CPy_INCREF(cpy_r_r105);
    CPy_INCREF(cpy_r_r106);
    CPy_INCREF(cpy_r_r107);
    CPy_INCREF(cpy_r_r108);
    CPy_INCREF(cpy_r_r109);
    CPy_INCREF(cpy_r_r110);
    CPy_INCREF(cpy_r_r111);
    CPy_INCREF(cpy_r_r112);
    CPy_INCREF(cpy_r_r113);
    CPy_INCREF(cpy_r_r114);
    CPy_INCREF(cpy_r_r115);
    CPy_INCREF(cpy_r_r116);
    CPy_INCREF(cpy_r_r117);
    CPy_INCREF(cpy_r_r118);
    CPy_INCREF(cpy_r_r119);
    CPy_INCREF(cpy_r_r120);
    CPy_INCREF(cpy_r_r121);
    CPy_INCREF(cpy_r_r122);
    CPy_INCREF(cpy_r_r123);
    CPy_INCREF(cpy_r_r124);
    CPy_INCREF(cpy_r_r125);
    CPy_INCREF(cpy_r_r126);
    CPy_INCREF(cpy_r_r127);
    CPy_INCREF(cpy_r_r128);
    CPy_INCREF(cpy_r_r129);
    CPy_INCREF(cpy_r_r130);
    CPy_INCREF(cpy_r_r131);
    CPy_INCREF(cpy_r_r132);
    CPy_INCREF(cpy_r_r133);
    CPy_INCREF(cpy_r_r134);
    CPy_INCREF(cpy_r_r135);
    CPy_INCREF(cpy_r_r136);
    CPy_INCREF(cpy_r_r137);
    CPy_INCREF(cpy_r_r138);
    CPy_INCREF(cpy_r_r139);
    CPy_INCREF(cpy_r_r140);
    CPy_INCREF(cpy_r_r141);
    CPy_INCREF(cpy_r_r142);
    CPy_INCREF(cpy_r_r143);
    CPy_INCREF(cpy_r_r144);
    CPy_INCREF(cpy_r_r145);
    CPy_INCREF(cpy_r_r146);
    CPy_INCREF(cpy_r_r147);
    CPy_INCREF(cpy_r_r148);
    CPy_INCREF(cpy_r_r149);
    CPy_INCREF(cpy_r_r150);
    CPy_INCREF(cpy_r_r151);
    CPy_INCREF(cpy_r_r152);
    CPy_INCREF(cpy_r_r153);
    CPy_INCREF(cpy_r_r154);
    CPy_INCREF(cpy_r_r155);
    CPy_INCREF(cpy_r_r156);
    CPy_INCREF(cpy_r_r157);
    CPy_INCREF(cpy_r_r158);
    CPy_INCREF(cpy_r_r159);
    CPy_INCREF(cpy_r_r160);
    CPy_INCREF(cpy_r_r161);
    CPy_INCREF(cpy_r_r162);
    CPy_INCREF(cpy_r_r163);
    CPy_INCREF(cpy_r_r164);
    CPy_INCREF(cpy_r_r165);
    CPy_INCREF(cpy_r_r166);
    CPy_INCREF(cpy_r_r167);
    CPy_INCREF(cpy_r_r168);
    CPy_INCREF(cpy_r_r169);
    CPy_INCREF(cpy_r_r170);
    CPy_INCREF(cpy_r_r171);
    CPy_INCREF(cpy_r_r172);
    CPy_INCREF(cpy_r_r173);
    CPy_INCREF(cpy_r_r174);
    CPy_INCREF(cpy_r_r175);
    CPy_INCREF(cpy_r_r176);
    CPy_INCREF(cpy_r_r177);
    CPy_INCREF(cpy_r_r178);
    CPy_INCREF(cpy_r_r179);
    CPy_INCREF(cpy_r_r180);
    CPy_INCREF(cpy_r_r181);
    CPy_INCREF(cpy_r_r182);
    CPy_INCREF(cpy_r_r183);
    CPy_INCREF(cpy_r_r184);
    CPy_INCREF(cpy_r_r185);
    CPy_INCREF(cpy_r_r186);
    CPy_INCREF(cpy_r_r187);
    CPy_INCREF(cpy_r_r188);
    CPy_INCREF(cpy_r_r189);
    CPy_INCREF(cpy_r_r190);
    CPy_INCREF(cpy_r_r191);
    CPy_INCREF(cpy_r_r192);
    CPy_INCREF(cpy_r_r193);
    CPy_INCREF(cpy_r_r194);
    CPy_INCREF(cpy_r_r195);
    CPy_INCREF(cpy_r_r196);
    CPy_INCREF(cpy_r_r197);
    CPy_INCREF(cpy_r_r198);
    CPy_INCREF(cpy_r_r199);
    CPy_INCREF(cpy_r_r200);
    CPy_INCREF(cpy_r_r201);
    CPy_INCREF(cpy_r_r202);
    CPy_INCREF(cpy_r_r203);
    CPy_INCREF(cpy_r_r204);
    CPy_INCREF(cpy_r_r205);
    CPy_INCREF(cpy_r_r206);
    CPy_INCREF(cpy_r_r207);
    CPy_INCREF(cpy_r_r208);
    CPy_INCREF(cpy_r_r209);
    CPy_INCREF(cpy_r_r210);
    CPy_INCREF(cpy_r_r211);
    CPy_INCREF(cpy_r_r212);
    CPy_INCREF(cpy_r_r213);
    CPy_INCREF(cpy_r_r214);
    CPy_INCREF(cpy_r_r215);
    CPy_INCREF(cpy_r_r216);
    CPy_INCREF(cpy_r_r217);
    CPy_INCREF(cpy_r_r218);
    CPy_INCREF(cpy_r_r219);
    CPy_INCREF(cpy_r_r220);
    CPy_INCREF(cpy_r_r221);
    CPy_INCREF(cpy_r_r222);
    CPy_INCREF(cpy_r_r223);
    CPy_INCREF(cpy_r_r224);
    CPy_INCREF(cpy_r_r225);
    CPy_INCREF(cpy_r_r226);
    CPy_INCREF(cpy_r_r227);
    CPy_INCREF(cpy_r_r228);
    CPy_INCREF(cpy_r_r229);
    CPy_INCREF(cpy_r_r230);
    CPy_INCREF(cpy_r_r231);
    CPy_INCREF(cpy_r_r232);
    CPy_INCREF(cpy_r_r233);
    CPy_INCREF(cpy_r_r234);
    cpy_r_r235 = CPyList_Build(209, cpy_r_r26, cpy_r_r27, cpy_r_r28, cpy_r_r29, cpy_r_r30, cpy_r_r31, cpy_r_r32, cpy_r_r33, cpy_r_r34, cpy_r_r35, cpy_r_r36, cpy_r_r37, cpy_r_r38, cpy_r_r39, cpy_r_r40, cpy_r_r41, cpy_r_r42, cpy_r_r43, cpy_r_r44, cpy_r_r45, cpy_r_r46, cpy_r_r47, cpy_r_r48, cpy_r_r49, cpy_r_r50, cpy_r_r51, cpy_r_r52, cpy_r_r53, cpy_r_r54, cpy_r_r55, cpy_r_r56, cpy_r_r57, cpy_r_r58, cpy_r_r59, cpy_r_r60, cpy_r_r61, cpy_r_r62, cpy_r_r63, cpy_r_r64, cpy_r_r65, cpy_r_r66, cpy_r_r67, cpy_r_r68, cpy_r_r69, cpy_r_r70, cpy_r_r71, cpy_r_r72, cpy_r_r73, cpy_r_r74, cpy_r_r75, cpy_r_r76, cpy_r_r77, cpy_r_r78, cpy_r_r79, cpy_r_r80, cpy_r_r81, cpy_r_r82, cpy_r_r83, cpy_r_r84, cpy_r_r85, cpy_r_r86, cpy_r_r87, cpy_r_r88, cpy_r_r89, cpy_r_r90, cpy_r_r91, cpy_r_r92, cpy_r_r93, cpy_r_r94, cpy_r_r95, cpy_r_r96, cpy_r_r97, cpy_r_r98, cpy_r_r99, cpy_r_r100, cpy_r_r101, cpy_r_r102, cpy_r_r103, cpy_r_r104, cpy_r_r105, cpy_r_r106, cpy_r_r107, cpy_r_r108, cpy_r_r109, cpy_r_r110, cpy_r_r111, cpy_r_r112, cpy_r_r113, cpy_r_r114, cpy_r_r115, cpy_r_r116, cpy_r_r117, cpy_r_r118, cpy_r_r119, cpy_r_r120, cpy_r_r121, cpy_r_r122, cpy_r_r123, cpy_r_r124, cpy_r_r125, cpy_r_r126, cpy_r_r127, cpy_r_r128, cpy_r_r129, cpy_r_r130, cpy_r_r131, cpy_r_r132, cpy_r_r133, cpy_r_r134, cpy_r_r135, cpy_r_r136, cpy_r_r137, cpy_r_r138, cpy_r_r139, cpy_r_r140, cpy_r_r141, cpy_r_r142, cpy_r_r143, cpy_r_r144, cpy_r_r145, cpy_r_r146, cpy_r_r147, cpy_r_r148, cpy_r_r149, cpy_r_r150, cpy_r_r151, cpy_r_r152, cpy_r_r153, cpy_r_r154, cpy_r_r155, cpy_r_r156, cpy_r_r157, cpy_r_r158, cpy_r_r159, cpy_r_r160, cpy_r_r161, cpy_r_r162, cpy_r_r163, cpy_r_r164, cpy_r_r165, cpy_r_r166, cpy_r_r167, cpy_r_r168, cpy_r_r169, cpy_r_r170, cpy_r_r171, cpy_r_r172, cpy_r_r173, cpy_r_r174, cpy_r_r175, cpy_r_r176, cpy_r_r177, cpy_r_r178, cpy_r_r179, cpy_r_r180, cpy_r_r181, cpy_r_r182, cpy_r_r183, cpy_r_r184, cpy_r_r185, cpy_r_r186, cpy_r_r187, cpy_r_r188, cpy_r_r189, cpy_r_r190, cpy_r_r191, cpy_r_r192, cpy_r_r193, cpy_r_r194, cpy_r_r195, cpy_r_r196, cpy_r_r197, cpy_r_r198, cpy_r_r199, cpy_r_r200, cpy_r_r201, cpy_r_r202, cpy_r_r203, cpy_r_r204, cpy_r_r205, cpy_r_r206, cpy_r_r207, cpy_r_r208, cpy_r_r209, cpy_r_r210, cpy_r_r211, cpy_r_r212, cpy_r_r213, cpy_r_r214, cpy_r_r215, cpy_r_r216, cpy_r_r217, cpy_r_r218, cpy_r_r219, cpy_r_r220, cpy_r_r221, cpy_r_r222, cpy_r_r223, cpy_r_r224, cpy_r_r225, cpy_r_r226, cpy_r_r227, cpy_r_r228, cpy_r_r229, cpy_r_r230, cpy_r_r231, cpy_r_r232, cpy_r_r233, cpy_r_r234);
    if (unlikely(cpy_r_r235 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 8, CPyStatic__shitcoins___globals);
        goto CPyL54;
    }
    cpy_r_r236 = CPyStatic__shitcoins___globals;
    cpy_r_r237 = CPyStatics[127]; /* 'Network' */
    cpy_r_r238 = CPyDict_GetItem(cpy_r_r236, cpy_r_r237);
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 230, CPyStatic__shitcoins___globals);
        goto CPyL55;
    }
    cpy_r_r239 = CPyStatics[336]; /* 'Fantom' */
    cpy_r_r240 = CPyObject_GetAttr(cpy_r_r238, cpy_r_r239);
    CPy_DECREF(cpy_r_r238);
    if (unlikely(cpy_r_r240 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 230, CPyStatic__shitcoins___globals);
        goto CPyL55;
    }
    cpy_r_r241 = CPyStatics[337]; /* '0x630277E37fd2Ddf81e4683f3692dD817aa6225Cb' */
    cpy_r_r242 = PyList_New(1);
    if (unlikely(cpy_r_r242 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 230, CPyStatic__shitcoins___globals);
        goto CPyL56;
    }
    cpy_r_r243 = (CPyPtr)&((PyListObject *)cpy_r_r242)->ob_item;
    cpy_r_r244 = *(CPyPtr *)cpy_r_r243;
    CPy_INCREF(cpy_r_r241);
    *(PyObject * *)cpy_r_r244 = cpy_r_r241;
    cpy_r_r245 = CPyStatic__shitcoins___globals;
    cpy_r_r246 = CPyStatics[127]; /* 'Network' */
    cpy_r_r247 = CPyDict_GetItem(cpy_r_r245, cpy_r_r246);
    if (unlikely(cpy_r_r247 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 234, CPyStatic__shitcoins___globals);
        goto CPyL57;
    }
    cpy_r_r248 = CPyStatics[338]; /* 'Optimism' */
    cpy_r_r249 = CPyObject_GetAttr(cpy_r_r247, cpy_r_r248);
    CPy_DECREF(cpy_r_r247);
    if (unlikely(cpy_r_r249 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 234, CPyStatic__shitcoins___globals);
        goto CPyL57;
    }
    cpy_r_r250 = CPyStatics[339]; /* '0x168fbA6072EE467931484a418EDeb5FcC1B9fb79' */
    cpy_r_r251 = CPyStatics[340]; /* '0x04788E66B9D884969538e4e35a0D57e9e022c799' */
    cpy_r_r252 = CPyStatics[341]; /* '0x6Cad3dE073FD85567c0Df84063c8990855710677' */
    cpy_r_r253 = CPyStatics[342]; /* '0x109390594d0ef9B40B4B745Cac6ceCf37a179417' */
    cpy_r_r254 = CPyStatics[343]; /* '0x87f4b57E2d3c8C9dCD85aD9dA80129f92754b19f' */
    cpy_r_r255 = CPyStatics[344]; /* '0x1828Bff08BD244F7990edDCd9B19cc654b33cDB4' */
    cpy_r_r256 = CPyStatics[345]; /* '0xd8dAE0aD69F4aDB507dB0C3e56Ec94942D470450' */
    cpy_r_r257 = PyList_New(7);
    if (unlikely(cpy_r_r257 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 234, CPyStatic__shitcoins___globals);
        goto CPyL58;
    }
    cpy_r_r258 = (CPyPtr)&((PyListObject *)cpy_r_r257)->ob_item;
    cpy_r_r259 = *(CPyPtr *)cpy_r_r258;
    CPy_INCREF(cpy_r_r250);
    *(PyObject * *)cpy_r_r259 = cpy_r_r250;
    CPy_INCREF(cpy_r_r251);
    cpy_r_r260 = cpy_r_r259 + 8;
    *(PyObject * *)cpy_r_r260 = cpy_r_r251;
    CPy_INCREF(cpy_r_r252);
    cpy_r_r261 = cpy_r_r259 + 16;
    *(PyObject * *)cpy_r_r261 = cpy_r_r252;
    CPy_INCREF(cpy_r_r253);
    cpy_r_r262 = cpy_r_r259 + 24;
    *(PyObject * *)cpy_r_r262 = cpy_r_r253;
    CPy_INCREF(cpy_r_r254);
    cpy_r_r263 = cpy_r_r259 + 32;
    *(PyObject * *)cpy_r_r263 = cpy_r_r254;
    CPy_INCREF(cpy_r_r255);
    cpy_r_r264 = cpy_r_r259 + 40;
    *(PyObject * *)cpy_r_r264 = cpy_r_r255;
    CPy_INCREF(cpy_r_r256);
    cpy_r_r265 = cpy_r_r259 + 48;
    *(PyObject * *)cpy_r_r265 = cpy_r_r256;
    cpy_r_r266 = CPyStatic__shitcoins___globals;
    cpy_r_r267 = CPyStatics[127]; /* 'Network' */
    cpy_r_r268 = CPyDict_GetItem(cpy_r_r266, cpy_r_r267);
    if (unlikely(cpy_r_r268 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 243, CPyStatic__shitcoins___globals);
        goto CPyL59;
    }
    cpy_r_r269 = CPyStatics[346]; /* 'Arbitrum' */
    cpy_r_r270 = CPyObject_GetAttr(cpy_r_r268, cpy_r_r269);
    CPy_DECREF(cpy_r_r268);
    if (unlikely(cpy_r_r270 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 243, CPyStatic__shitcoins___globals);
        goto CPyL59;
    }
    cpy_r_r271 = CPyStatics[347]; /* '0xA57D85481B9ecD864F542Ea37bAA79A101a4f599' */
    cpy_r_r272 = CPyStatics[348]; /* '0x73fcaFc42ABB43A408bdE4b37eAfCCDadCB2b554' */
    cpy_r_r273 = CPyStatics[349]; /* '0x13577D823114697289cf85d3f563a21417022e7C' */
    cpy_r_r274 = CPyStatics[350]; /* '0xb8f2A48362371F7B4E88460BD4B3B5dba48A344f' */
    cpy_r_r275 = CPyStatics[351]; /* '0x184deAc2B1052AcB020Fa5159683733be3447699' */
    cpy_r_r276 = CPyStatics[352]; /* '0xBE9460b50f515169E14545aaddF60B3C9dB7e5Fb' */
    cpy_r_r277 = CPyStatics[353]; /* '0x8fb95D642C19a9C5C9138C5b444455A69196F2EC' */
    cpy_r_r278 = CPyStatics[354]; /* '0x1d7edf990Cd21eaB14aA55f8d06a386c73D24B5B' */
    cpy_r_r279 = CPyStatics[355]; /* '0x96C708e060CdC5B8C6Ac6a015db0b10833F74157' */
    cpy_r_r280 = CPyStatics[356]; /* '0x4dB2207C2cf35aA5ecFE61c5d098Bb3e3Ed1a7B0' */
    cpy_r_r281 = CPyStatics[357]; /* '0x17c074e90372aC53FF98cA24c3745E6E38717C14' */
    cpy_r_r282 = CPyStatics[358]; /* '0xA4468e55c5723C2346484f6a01da7b8826EEeC1b' */
    cpy_r_r283 = CPyStatics[359]; /* '0xdf109e2b175038c66e074BfEacF37D7b0f3e426c' */
    cpy_r_r284 = CPyStatics[360]; /* '0xeCd434A1391c208C3Cf4D8aa0e91FCd7B84D2B91' */
    cpy_r_r285 = CPyStatics[361]; /* '0xef7aA9F26F586a96F3C7E2E5308296aAD56E7F30' */
    cpy_r_r286 = CPyStatics[362]; /* '0xd8b86C2d30101848Ffb9eB0D4019b94De13374CC' */
    cpy_r_r287 = CPyStatics[363]; /* '0x43566AeD154526E2d62B60Fc9d31C98d4feaf99c' */
    CPy_INCREF(cpy_r_r271);
    CPy_INCREF(cpy_r_r272);
    CPy_INCREF(cpy_r_r273);
    CPy_INCREF(cpy_r_r274);
    CPy_INCREF(cpy_r_r275);
    CPy_INCREF(cpy_r_r276);
    CPy_INCREF(cpy_r_r277);
    CPy_INCREF(cpy_r_r278);
    CPy_INCREF(cpy_r_r279);
    CPy_INCREF(cpy_r_r280);
    CPy_INCREF(cpy_r_r281);
    CPy_INCREF(cpy_r_r282);
    CPy_INCREF(cpy_r_r283);
    CPy_INCREF(cpy_r_r284);
    CPy_INCREF(cpy_r_r285);
    CPy_INCREF(cpy_r_r286);
    CPy_INCREF(cpy_r_r287);
    cpy_r_r288 = CPyList_Build(17, cpy_r_r271, cpy_r_r272, cpy_r_r273, cpy_r_r274, cpy_r_r275, cpy_r_r276, cpy_r_r277, cpy_r_r278, cpy_r_r279, cpy_r_r280, cpy_r_r281, cpy_r_r282, cpy_r_r283, cpy_r_r284, cpy_r_r285, cpy_r_r286, cpy_r_r287);
    if (unlikely(cpy_r_r288 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 243, CPyStatic__shitcoins___globals);
        goto CPyL60;
    }
    cpy_r_r289 = CPyDict_Build(4, cpy_r_r25, cpy_r_r235, cpy_r_r240, cpy_r_r242, cpy_r_r249, cpy_r_r257, cpy_r_r270, cpy_r_r288);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF_NO_IMM(cpy_r_r235);
    CPy_DECREF(cpy_r_r240);
    CPy_DECREF_NO_IMM(cpy_r_r242);
    CPy_DECREF(cpy_r_r249);
    CPy_DECREF_NO_IMM(cpy_r_r257);
    CPy_DECREF(cpy_r_r270);
    CPy_DECREF_NO_IMM(cpy_r_r288);
    if (unlikely(cpy_r_r289 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 7, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    CPyStatic__shitcoins___shitcoins = cpy_r_r289;
    CPy_INCREF(CPyStatic__shitcoins___shitcoins);
    cpy_r_r290 = CPyStatic__shitcoins___globals;
    cpy_r_r291 = CPyStatics[364]; /* 'shitcoins' */
    cpy_r_r292 = CPyDict_SetItem(cpy_r_r290, cpy_r_r291, cpy_r_r289);
    CPy_DECREF(cpy_r_r289);
    cpy_r_r293 = cpy_r_r292 >= 0;
    if (unlikely(!cpy_r_r293)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 7, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    cpy_r_r294 = (PyObject *)&PySet_Type;
    cpy_r_r295 = CPyStatic__shitcoins___globals;
    cpy_r_r296 = CPyStatics[3]; /* 'defaultdict' */
    cpy_r_r297 = CPyDict_GetItem(cpy_r_r295, cpy_r_r296);
    if (unlikely(cpy_r_r297 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 264, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    PyObject *cpy_r_r298[1] = {cpy_r_r294};
    cpy_r_r299 = (PyObject **)&cpy_r_r298;
    cpy_r_r300 = PyObject_Vectorcall(cpy_r_r297, cpy_r_r299, 1, 0);
    CPy_DECREF(cpy_r_r297);
    if (unlikely(cpy_r_r300 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 264, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    if (likely(PyDict_Check(cpy_r_r300)))
        cpy_r_r301 = cpy_r_r300;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_shitcoins.py", "<module>", 264, CPyStatic__shitcoins___globals, "dict", cpy_r_r300);
        goto CPyL53;
    }
    cpy_r_r302 = CPyStatic__shitcoins___globals;
    cpy_r_r303 = CPyStatics[365]; /* 'SHITCOINS' */
    cpy_r_r304 = CPyDict_SetItem(cpy_r_r302, cpy_r_r303, cpy_r_r301);
    CPy_DECREF(cpy_r_r301);
    cpy_r_r305 = cpy_r_r304 >= 0;
    if (unlikely(!cpy_r_r305)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 264, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    cpy_r_r306 = CPyStatic__shitcoins___shitcoins;
    if (likely(cpy_r_r306 != NULL)) goto CPyL28;
    PyErr_SetString(PyExc_NameError, "value for final name \"shitcoins\" was not set");
    cpy_r_r307 = 0;
    if (unlikely(!cpy_r_r307)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 267, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r308 = 0;
    cpy_r_r309 = PyDict_Size(cpy_r_r306);
    cpy_r_r310 = cpy_r_r309 << 1;
    cpy_r_r311 = CPyDict_GetItemsIter(cpy_r_r306);
    if (unlikely(cpy_r_r311 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 267, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
CPyL29: ;
    cpy_r_r312 = CPyDict_NextItem(cpy_r_r311, cpy_r_r308);
    cpy_r_r313 = cpy_r_r312.f1;
    cpy_r_r308 = cpy_r_r313;
    cpy_r_r314 = cpy_r_r312.f0;
    if (!cpy_r_r314) goto CPyL61;
    cpy_r_r315 = cpy_r_r312.f2;
    CPy_INCREF(cpy_r_r315);
    cpy_r_r316 = cpy_r_r312.f3;
    CPy_INCREF(cpy_r_r316);
    CPy_DECREF(cpy_r_r312.f2);
    CPy_DECREF(cpy_r_r312.f3);
    if (likely(PyList_Check(cpy_r_r316)))
        cpy_r_r317 = cpy_r_r316;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_shitcoins.py", "<module>", 267, CPyStatic__shitcoins___globals, "list", cpy_r_r316);
        goto CPyL62;
    }
    cpy_r_r318 = CPyStatic__shitcoins___globals;
    cpy_r_r319 = CPyStatics[366]; /* 'chain' */
    cpy_r_r320 = CPyStatic__shitcoins___globals;
    cpy_r_r321 = CPyStatics[367]; /* 'tokens' */
    cpy_r_r322 = CPyDict_SetItem(cpy_r_r318, cpy_r_r319, cpy_r_r315);
    CPy_DECREF(cpy_r_r315);
    cpy_r_r323 = cpy_r_r322 >= 0;
    if (unlikely(!cpy_r_r323)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 267, CPyStatic__shitcoins___globals);
        goto CPyL63;
    }
    cpy_r_r324 = CPyDict_SetItem(cpy_r_r320, cpy_r_r321, cpy_r_r317);
    CPy_DECREF_NO_IMM(cpy_r_r317);
    cpy_r_r325 = cpy_r_r324 >= 0;
    if (unlikely(!cpy_r_r325)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 267, CPyStatic__shitcoins___globals);
        goto CPyL64;
    }
    cpy_r_r326 = CPyStatic__shitcoins___globals;
    cpy_r_r327 = CPyStatics[365]; /* 'SHITCOINS' */
    cpy_r_r328 = CPyDict_GetItem(cpy_r_r326, cpy_r_r327);
    if (unlikely(cpy_r_r328 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL64;
    }
    if (likely(PyDict_Check(cpy_r_r328)))
        cpy_r_r329 = cpy_r_r328;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals, "dict", cpy_r_r328);
        goto CPyL64;
    }
    cpy_r_r330 = CPyStatic__shitcoins___globals;
    cpy_r_r331 = CPyStatics[366]; /* 'chain' */
    cpy_r_r332 = CPyDict_GetItem(cpy_r_r330, cpy_r_r331);
    if (unlikely(cpy_r_r332 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL65;
    }
    cpy_r_r333 = CPyDict_GetItem(cpy_r_r329, cpy_r_r332);
    CPy_DECREF(cpy_r_r329);
    CPy_DECREF(cpy_r_r332);
    if (unlikely(cpy_r_r333 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL64;
    }
    if (likely(PySet_Check(cpy_r_r333)))
        cpy_r_r334 = cpy_r_r333;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals, "set", cpy_r_r333);
        goto CPyL64;
    }
    cpy_r_r335 = CPyStatic__shitcoins___globals;
    cpy_r_r336 = CPyStatics[367]; /* 'tokens' */
    cpy_r_r337 = CPyDict_GetItem(cpy_r_r335, cpy_r_r336);
    if (unlikely(cpy_r_r337 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL66;
    }
    if (likely(PyList_Check(cpy_r_r337)))
        cpy_r_r338 = cpy_r_r337;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals, "list", cpy_r_r337);
        goto CPyL66;
    }
    cpy_r_r339 = (CPyPtr)&((PyVarObject *)cpy_r_r338)->ob_size;
    cpy_r_r340 = *(int64_t *)cpy_r_r339;
    cpy_r_r341 = PyList_New(cpy_r_r340);
    if (unlikely(cpy_r_r341 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL67;
    }
    cpy_r_r342 = 0;
CPyL42: ;
    cpy_r_r343 = (CPyPtr)&((PyVarObject *)cpy_r_r338)->ob_size;
    cpy_r_r344 = *(int64_t *)cpy_r_r343;
    cpy_r_r345 = cpy_r_r344 << 1;
    cpy_r_r346 = (Py_ssize_t)cpy_r_r342 < (Py_ssize_t)cpy_r_r345;
    if (!cpy_r_r346) goto CPyL68;
    cpy_r_r347 = (Py_ssize_t)cpy_r_r342 >> 1;
    cpy_r_r348 = (CPyPtr)&((PyListObject *)cpy_r_r338)->ob_item;
    cpy_r_r349 = *(CPyPtr *)cpy_r_r348;
    cpy_r_r350 = cpy_r_r347 * 8;
    cpy_r_r351 = cpy_r_r349 + cpy_r_r350;
    cpy_r_r352 = *(PyObject * *)cpy_r_r351;
    CPy_INCREF(cpy_r_r352);
    if (likely(PyUnicode_Check(cpy_r_r352)))
        cpy_r_r353 = cpy_r_r352;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals, "str", cpy_r_r352);
        goto CPyL69;
    }
    cpy_r_r354 = CPyStatic__shitcoins___globals;
    cpy_r_r355 = CPyStatics[128]; /* 'convert' */
    cpy_r_r356 = CPyDict_GetItem(cpy_r_r354, cpy_r_r355);
    if (unlikely(cpy_r_r356 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL70;
    }
    cpy_r_r357 = CPyStatics[368]; /* 'to_address' */
    cpy_r_r358 = CPyObject_GetAttr(cpy_r_r356, cpy_r_r357);
    CPy_DECREF(cpy_r_r356);
    if (unlikely(cpy_r_r358 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL70;
    }
    PyObject *cpy_r_r359[1] = {cpy_r_r353};
    cpy_r_r360 = (PyObject **)&cpy_r_r359;
    cpy_r_r361 = PyObject_Vectorcall(cpy_r_r358, cpy_r_r360, 1, 0);
    CPy_DECREF(cpy_r_r358);
    if (unlikely(cpy_r_r361 == NULL)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL70;
    }
    CPy_DECREF(cpy_r_r353);
    cpy_r_r362 = CPyList_SetItemUnsafe(cpy_r_r341, cpy_r_r342, cpy_r_r361);
    if (unlikely(!cpy_r_r362)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL69;
    }
    cpy_r_r363 = cpy_r_r342 + 2;
    cpy_r_r342 = cpy_r_r363;
    goto CPyL42;
CPyL49: ;
    cpy_r_r364 = _PySet_Update(cpy_r_r334, cpy_r_r341);
    CPy_DECREF(cpy_r_r334);
    CPy_DECREF_NO_IMM(cpy_r_r341);
    cpy_r_r365 = cpy_r_r364 >= 0;
    if (unlikely(!cpy_r_r365)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 268, CPyStatic__shitcoins___globals);
        goto CPyL64;
    }
    cpy_r_r366 = CPyDict_CheckSize(cpy_r_r306, cpy_r_r310);
    if (unlikely(!cpy_r_r366)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 267, CPyStatic__shitcoins___globals);
        goto CPyL64;
    } else
        goto CPyL29;
CPyL51: ;
    cpy_r_r367 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r367)) {
        CPy_AddTraceback("eth_portfolio/_shitcoins.py", "<module>", 267, CPyStatic__shitcoins___globals);
        goto CPyL53;
    }
    return 1;
CPyL53: ;
    cpy_r_r368 = 2;
    return cpy_r_r368;
CPyL54: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL53;
CPyL55: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r235);
    goto CPyL53;
CPyL56: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r235);
    CPy_DecRef(cpy_r_r240);
    goto CPyL53;
CPyL57: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r235);
    CPy_DecRef(cpy_r_r240);
    CPy_DecRef(cpy_r_r242);
    goto CPyL53;
CPyL58: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r235);
    CPy_DecRef(cpy_r_r240);
    CPy_DecRef(cpy_r_r242);
    CPy_DecRef(cpy_r_r249);
    goto CPyL53;
CPyL59: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r235);
    CPy_DecRef(cpy_r_r240);
    CPy_DecRef(cpy_r_r242);
    CPy_DecRef(cpy_r_r249);
    CPy_DecRef(cpy_r_r257);
    goto CPyL53;
CPyL60: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r235);
    CPy_DecRef(cpy_r_r240);
    CPy_DecRef(cpy_r_r242);
    CPy_DecRef(cpy_r_r249);
    CPy_DecRef(cpy_r_r257);
    CPy_DecRef(cpy_r_r270);
    goto CPyL53;
CPyL61: ;
    CPy_DECREF(cpy_r_r311);
    CPy_DECREF(cpy_r_r312.f2);
    CPy_DECREF(cpy_r_r312.f3);
    goto CPyL51;
CPyL62: ;
    CPy_DecRef(cpy_r_r311);
    CPy_DecRef(cpy_r_r315);
    goto CPyL53;
CPyL63: ;
    CPy_DecRef(cpy_r_r311);
    CPy_DecRef(cpy_r_r317);
    goto CPyL53;
CPyL64: ;
    CPy_DecRef(cpy_r_r311);
    goto CPyL53;
CPyL65: ;
    CPy_DecRef(cpy_r_r311);
    CPy_DecRef(cpy_r_r329);
    goto CPyL53;
CPyL66: ;
    CPy_DecRef(cpy_r_r311);
    CPy_DecRef(cpy_r_r334);
    goto CPyL53;
CPyL67: ;
    CPy_DecRef(cpy_r_r311);
    CPy_DecRef(cpy_r_r334);
    CPy_DecRef(cpy_r_r338);
    goto CPyL53;
CPyL68: ;
    CPy_DECREF_NO_IMM(cpy_r_r338);
    goto CPyL49;
CPyL69: ;
    CPy_DecRef(cpy_r_r311);
    CPy_DecRef(cpy_r_r334);
    CPy_DecRef(cpy_r_r338);
    CPy_DecRef(cpy_r_r341);
    goto CPyL53;
CPyL70: ;
    CPy_DecRef(cpy_r_r311);
    CPy_DecRef(cpy_r_r334);
    CPy_DecRef(cpy_r_r338);
    CPy_DecRef(cpy_r_r341);
    CPy_DecRef(cpy_r_r353);
    goto CPyL53;
}
static PyMethodDef constantsmodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef constantsmodule = {
    PyModuleDef_HEAD_INIT,
    "eth_portfolio.constants",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    constantsmodule_methods
};

PyObject *CPyInit_eth_portfolio___constants(void)
{
    PyObject* modname = NULL;
    if (CPyModule_eth_portfolio___constants_internal) {
        Py_INCREF(CPyModule_eth_portfolio___constants_internal);
        return CPyModule_eth_portfolio___constants_internal;
    }
    CPyModule_eth_portfolio___constants_internal = PyModule_Create(&constantsmodule);
    if (unlikely(CPyModule_eth_portfolio___constants_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_eth_portfolio___constants_internal, "__name__");
    CPyStatic_constants___globals = PyModule_GetDict(CPyModule_eth_portfolio___constants_internal);
    if (unlikely(CPyStatic_constants___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_constants_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_eth_portfolio___constants_internal;
    fail:
    Py_CLEAR(CPyModule_eth_portfolio___constants_internal);
    Py_CLEAR(modname);
    CPyTagged_XDECREF(CPyStatic_constants___NUM_WALLETS);
    CPyStatic_constants___NUM_WALLETS = CPY_INT_TAG;
    CPy_XDECREF_NO_IMM(CPyStatic_constants___ADDRESSES);
    CPyStatic_constants___ADDRESSES = NULL;
    CPy_XDECREF_NO_IMM(CPyStatic_constants___TRANSFER_SIGS);
    CPyStatic_constants___TRANSFER_SIGS = NULL;
    CPy_XDECREF(CPyStatic_constants___ETH_LIKE);
    CPyStatic_constants___ETH_LIKE = NULL;
    CPy_XDECREF(CPyStatic_constants___BTC_LIKE);
    CPyStatic_constants___BTC_LIKE = NULL;
    CPy_XDECREF(CPyStatic_constants___INTL_STABLECOINS);
    CPyStatic_constants___INTL_STABLECOINS = NULL;
    return NULL;
}

char CPyDef_constants_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    int32_t cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    int32_t cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject **cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject **cpy_r_r48;
    PyObject *cpy_r_r49;
    CPyTagged cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    CPyTagged cpy_r_r58;
    char cpy_r_r59;
    CPyTagged cpy_r_r60;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r61;
    char cpy_r_r62;
    int64_t cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject **cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    int32_t cpy_r_r79;
    char cpy_r_r80;
    CPyTagged cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject **cpy_r_r94;
    PyObject *cpy_r_r95;
    int32_t cpy_r_r96;
    char cpy_r_r97;
    char cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    int32_t cpy_r_r101;
    char cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    CPyPtr cpy_r_r106;
    CPyPtr cpy_r_r107;
    CPyPtr cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    int32_t cpy_r_r111;
    char cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    int32_t cpy_r_r131;
    char cpy_r_r132;
    int32_t cpy_r_r133;
    char cpy_r_r134;
    int32_t cpy_r_r135;
    char cpy_r_r136;
    int32_t cpy_r_r137;
    char cpy_r_r138;
    int32_t cpy_r_r139;
    char cpy_r_r140;
    int32_t cpy_r_r141;
    char cpy_r_r142;
    int32_t cpy_r_r143;
    char cpy_r_r144;
    int32_t cpy_r_r145;
    char cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    CPyTagged cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    int32_t cpy_r_r159;
    char cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    int32_t cpy_r_r175;
    char cpy_r_r176;
    int32_t cpy_r_r177;
    char cpy_r_r178;
    int32_t cpy_r_r179;
    char cpy_r_r180;
    int32_t cpy_r_r181;
    char cpy_r_r182;
    int32_t cpy_r_r183;
    char cpy_r_r184;
    int32_t cpy_r_r185;
    char cpy_r_r186;
    int32_t cpy_r_r187;
    char cpy_r_r188;
    int32_t cpy_r_r189;
    char cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    CPyTagged cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    int32_t cpy_r_r203;
    char cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    int32_t cpy_r_r221;
    char cpy_r_r222;
    int32_t cpy_r_r223;
    char cpy_r_r224;
    int32_t cpy_r_r225;
    char cpy_r_r226;
    int32_t cpy_r_r227;
    char cpy_r_r228;
    int32_t cpy_r_r229;
    char cpy_r_r230;
    int32_t cpy_r_r231;
    char cpy_r_r232;
    int32_t cpy_r_r233;
    char cpy_r_r234;
    int32_t cpy_r_r235;
    char cpy_r_r236;
    int32_t cpy_r_r237;
    char cpy_r_r238;
    int32_t cpy_r_r239;
    char cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    CPyTagged cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    int32_t cpy_r_r253;
    char cpy_r_r254;
    char cpy_r_r255;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[22]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", -1, CPyStatic_constants___globals);
        goto CPyL103;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_os;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[456]; /* (('os', 'os', 'os'),) */
    cpy_r_r11 = CPyStatic_constants___globals;
    cpy_r_r12 = CPyStatics[369]; /* 'eth_portfolio/constants.py' */
    cpy_r_r13 = CPyStatics[26]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL103;
    cpy_r_r15 = CPyStatics[436]; /* ('Final',) */
    cpy_r_r16 = CPyStatics[35]; /* 'typing' */
    cpy_r_r17 = CPyStatic_constants___globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 2, CPyStatic_constants___globals);
        goto CPyL103;
    }
    CPyModule_typing = cpy_r_r18;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[460]; /* ('chain',) */
    cpy_r_r20 = CPyStatics[370]; /* 'brownie' */
    cpy_r_r21 = CPyStatic_constants___globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 4, CPyStatic_constants___globals);
        goto CPyL103;
    }
    CPyModule_brownie = cpy_r_r22;
    CPy_INCREF(CPyModule_brownie);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatics[461]; /* ('Network', 'convert', 'weth') */
    cpy_r_r24 = CPyStatics[79]; /* 'y' */
    cpy_r_r25 = CPyStatic_constants___globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 5, CPyStatic_constants___globals);
        goto CPyL103;
    }
    CPyModule_y = cpy_r_r26;
    CPy_INCREF(CPyModule_y);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r27 = CPyStatics[372]; /* '0xddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef' */
    cpy_r_r28 = CPyStatic_constants___globals;
    cpy_r_r29 = CPyStatics[373]; /* 'ERC20_TRANSFER_EVENT_HASH' */
    cpy_r_r30 = CPyDict_SetItem(cpy_r_r28, cpy_r_r29, cpy_r_r27);
    cpy_r_r31 = cpy_r_r30 >= 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 8, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r32 = CPyStatics[374]; /* '0xe19260aff97b920c7df27010903aeb9c8d2be5d310a2c67824cf3f15396e4c16' */
    cpy_r_r33 = CPyStatic_constants___globals;
    cpy_r_r34 = CPyStatics[375]; /* 'ERC677_TRANSFER_EVENT_HASH' */
    cpy_r_r35 = CPyDict_SetItem(cpy_r_r33, cpy_r_r34, cpy_r_r32);
    cpy_r_r36 = cpy_r_r35 >= 0;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 11, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r37 = CPyModule_os;
    cpy_r_r38 = CPyStatics[123]; /* 'environ' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 14, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r40 = CPyStatics[376]; /* 'NUM_WALLETS' */
    cpy_r_r41 = CPyStatics[377]; /* '10' */
    cpy_r_r42 = CPyStatics[125]; /* 'get' */
    PyObject *cpy_r_r43[3] = {cpy_r_r39, cpy_r_r40, cpy_r_r41};
    cpy_r_r44 = (PyObject **)&cpy_r_r43;
    cpy_r_r45 = PyObject_VectorcallMethod(cpy_r_r42, cpy_r_r44, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 14, CPyStatic_constants___globals);
        goto CPyL104;
    }
    CPy_DECREF(cpy_r_r39);
    cpy_r_r46 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r47[1] = {cpy_r_r45};
    cpy_r_r48 = (PyObject **)&cpy_r_r47;
    cpy_r_r49 = PyObject_Vectorcall(cpy_r_r46, cpy_r_r48, 1, 0);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 14, CPyStatic_constants___globals);
        goto CPyL105;
    }
    CPy_DECREF(cpy_r_r45);
    if (likely(PyLong_Check(cpy_r_r49)))
        cpy_r_r50 = CPyTagged_FromObject(cpy_r_r49);
    else {
        CPy_TypeError("int", cpy_r_r49); cpy_r_r50 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 14, CPyStatic_constants___globals);
        goto CPyL103;
    }
    CPyStatic_constants___NUM_WALLETS = cpy_r_r50;
    CPyTagged_INCREF(CPyStatic_constants___NUM_WALLETS);
    cpy_r_r51 = CPyStatic_constants___globals;
    cpy_r_r52 = CPyStatics[376]; /* 'NUM_WALLETS' */
    cpy_r_r53 = CPyTagged_StealAsObject(cpy_r_r50);
    cpy_r_r54 = CPyDict_SetItem(cpy_r_r51, cpy_r_r52, cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 14, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r56 = PyList_New(0);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 15, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r57 = PySet_New(NULL);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 17, CPyStatic_constants___globals);
        goto CPyL106;
    }
    cpy_r_r58 = CPyStatic_constants___NUM_WALLETS;
    if (unlikely(cpy_r_r58 == CPY_INT_TAG)) {
        goto CPyL107;
    } else
        goto CPyL19;
CPyL17: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"NUM_WALLETS\" was not set");
    cpy_r_r59 = 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 17, CPyStatic_constants___globals);
        goto CPyL103;
    }
    CPy_Unreachable();
CPyL19: ;
    cpy_r_r60 = 0;
    CPyTagged_INCREF(cpy_r_r60);
    cpy_r_i = cpy_r_r60;
CPyL20: ;
    cpy_r_r61 = cpy_r_r60 & 1;
    cpy_r_r62 = cpy_r_r61 != 0;
    if (cpy_r_r62) goto CPyL22;
    cpy_r_r63 = cpy_r_r58 & 1;
    cpy_r_r64 = cpy_r_r63 != 0;
    if (!cpy_r_r64) goto CPyL23;
CPyL22: ;
    cpy_r_r65 = CPyTagged_IsLt_(cpy_r_r60, cpy_r_r58);
    if (cpy_r_r65) {
        goto CPyL24;
    } else
        goto CPyL108;
CPyL23: ;
    cpy_r_r66 = (Py_ssize_t)cpy_r_r60 < (Py_ssize_t)cpy_r_r58;
    if (!cpy_r_r66) goto CPyL108;
CPyL24: ;
    cpy_r_r67 = CPyModule_os;
    cpy_r_r68 = CPyStatics[123]; /* 'environ' */
    cpy_r_r69 = CPyObject_GetAttr(cpy_r_r67, cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 17, CPyStatic_constants___globals);
        goto CPyL109;
    }
    cpy_r_r70 = CPyStatics[378]; /* 'PORTFOLIO_ADDRESS_' */
    cpy_r_r71 = CPyTagged_Str(cpy_r_i);
    CPyTagged_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 17, CPyStatic_constants___globals);
        goto CPyL110;
    }
    cpy_r_r72 = CPyStr_Build(2, cpy_r_r70, cpy_r_r71);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 17, CPyStatic_constants___globals);
        goto CPyL110;
    }
    cpy_r_r73 = CPyStatics[125]; /* 'get' */
    cpy_r_r74 = Py_None;
    PyObject *cpy_r_r75[3] = {cpy_r_r69, cpy_r_r72, cpy_r_r74};
    cpy_r_r76 = (PyObject **)&cpy_r_r75;
    cpy_r_r77 = PyObject_VectorcallMethod(cpy_r_r73, cpy_r_r76, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 17, CPyStatic_constants___globals);
        goto CPyL111;
    }
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r72);
    if (PyUnicode_Check(cpy_r_r77))
        cpy_r_r78 = cpy_r_r77;
    else {
        cpy_r_r78 = NULL;
    }
    if (cpy_r_r78 != NULL) goto __LL58;
    if (cpy_r_r77 == Py_None)
        cpy_r_r78 = cpy_r_r77;
    else {
        cpy_r_r78 = NULL;
    }
    if (cpy_r_r78 != NULL) goto __LL58;
    CPy_TypeErrorTraceback("eth_portfolio/constants.py", "<module>", 17, CPyStatic_constants___globals, "str or None", cpy_r_r77);
    goto CPyL112;
__LL58: ;
    cpy_r_r79 = PySet_Add(cpy_r_r57, cpy_r_r78);
    CPy_DECREF(cpy_r_r78);
    cpy_r_r80 = cpy_r_r79 >= 0;
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 17, CPyStatic_constants___globals);
        goto CPyL112;
    }
    cpy_r_r81 = CPyTagged_Add(cpy_r_r60, 2);
    CPyTagged_DECREF(cpy_r_r60);
    CPyTagged_INCREF(cpy_r_r81);
    cpy_r_r60 = cpy_r_r81;
    cpy_r_i = cpy_r_r81;
    goto CPyL20;
CPyL31: ;
    cpy_r_r82 = PyObject_GetIter(cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 15, CPyStatic_constants___globals);
        goto CPyL106;
    }
CPyL32: ;
    cpy_r_r83 = PyIter_Next(cpy_r_r82);
    if (cpy_r_r83 == NULL) goto CPyL113;
    if (PyUnicode_Check(cpy_r_r83))
        cpy_r_r84 = cpy_r_r83;
    else {
        cpy_r_r84 = NULL;
    }
    if (cpy_r_r84 != NULL) goto __LL59;
    if (cpy_r_r83 == Py_None)
        cpy_r_r84 = cpy_r_r83;
    else {
        cpy_r_r84 = NULL;
    }
    if (cpy_r_r84 != NULL) goto __LL59;
    CPy_TypeErrorTraceback("eth_portfolio/constants.py", "<module>", 15, CPyStatic_constants___globals, "str or None", cpy_r_r83);
    goto CPyL114;
__LL59: ;
    cpy_r_r85 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r86 = cpy_r_r84 != cpy_r_r85;
    if (!cpy_r_r86) goto CPyL115;
    if (likely(cpy_r_r84 != Py_None))
        cpy_r_r87 = cpy_r_r84;
    else {
        CPy_TypeErrorTraceback("eth_portfolio/constants.py", "<module>", 16, CPyStatic_constants___globals, "str", cpy_r_r84);
        goto CPyL114;
    }
    cpy_r_r88 = CPyStatic_constants___globals;
    cpy_r_r89 = CPyStatics[128]; /* 'convert' */
    cpy_r_r90 = CPyDict_GetItem(cpy_r_r88, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 16, CPyStatic_constants___globals);
        goto CPyL116;
    }
    cpy_r_r91 = CPyStatics[368]; /* 'to_address' */
    cpy_r_r92 = CPyObject_GetAttr(cpy_r_r90, cpy_r_r91);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 16, CPyStatic_constants___globals);
        goto CPyL116;
    }
    PyObject *cpy_r_r93[1] = {cpy_r_r87};
    cpy_r_r94 = (PyObject **)&cpy_r_r93;
    cpy_r_r95 = PyObject_Vectorcall(cpy_r_r92, cpy_r_r94, 1, 0);
    CPy_DECREF(cpy_r_r92);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 16, CPyStatic_constants___globals);
        goto CPyL116;
    }
    CPy_DECREF(cpy_r_r87);
    cpy_r_r96 = PyList_Append(cpy_r_r56, cpy_r_r95);
    CPy_DECREF(cpy_r_r95);
    cpy_r_r97 = cpy_r_r96 >= 0;
    if (unlikely(!cpy_r_r97)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 15, CPyStatic_constants___globals);
        goto CPyL114;
    } else
        goto CPyL32;
CPyL40: ;
    cpy_r_r98 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r98)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 15, CPyStatic_constants___globals);
        goto CPyL106;
    }
    CPyStatic_constants___ADDRESSES = cpy_r_r56;
    CPy_INCREF_NO_IMM(CPyStatic_constants___ADDRESSES);
    cpy_r_r99 = CPyStatic_constants___globals;
    cpy_r_r100 = CPyStatics[379]; /* 'ADDRESSES' */
    cpy_r_r101 = CPyDict_SetItem(cpy_r_r99, cpy_r_r100, cpy_r_r56);
    CPy_DECREF_NO_IMM(cpy_r_r56);
    cpy_r_r102 = cpy_r_r101 >= 0;
    if (unlikely(!cpy_r_r102)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 15, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r103 = CPyStatics[372]; /* '0xddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef' */
    cpy_r_r104 = CPyStatics[374]; /* '0xe19260aff97b920c7df27010903aeb9c8d2be5d310a2c67824cf3f15396e4c16' */
    cpy_r_r105 = PyList_New(2);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 21, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r106 = (CPyPtr)&((PyListObject *)cpy_r_r105)->ob_item;
    cpy_r_r107 = *(CPyPtr *)cpy_r_r106;
    CPy_INCREF(cpy_r_r103);
    *(PyObject * *)cpy_r_r107 = cpy_r_r103;
    CPy_INCREF(cpy_r_r104);
    cpy_r_r108 = cpy_r_r107 + 8;
    *(PyObject * *)cpy_r_r108 = cpy_r_r104;
    CPyStatic_constants___TRANSFER_SIGS = cpy_r_r105;
    CPy_INCREF_NO_IMM(CPyStatic_constants___TRANSFER_SIGS);
    cpy_r_r109 = CPyStatic_constants___globals;
    cpy_r_r110 = CPyStatics[380]; /* 'TRANSFER_SIGS' */
    cpy_r_r111 = CPyDict_SetItem(cpy_r_r109, cpy_r_r110, cpy_r_r105);
    CPy_DECREF_NO_IMM(cpy_r_r105);
    cpy_r_r112 = cpy_r_r111 >= 0;
    if (unlikely(!cpy_r_r112)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 21, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r113 = CPyStatic_constants___globals;
    cpy_r_r114 = CPyStatics[127]; /* 'Network' */
    cpy_r_r115 = CPyDict_GetItem(cpy_r_r113, cpy_r_r114);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r116 = CPyStatics[129]; /* 'Mainnet' */
    cpy_r_r117 = CPyObject_GetAttr(cpy_r_r115, cpy_r_r116);
    CPy_DECREF(cpy_r_r115);
    if (unlikely(cpy_r_r117 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r118 = CPyStatics[381]; /* 'ETH' */
    cpy_r_r119 = CPyStatic_constants___globals;
    cpy_r_r120 = CPyStatics[371]; /* 'weth' */
    cpy_r_r121 = CPyDict_GetItem(cpy_r_r119, cpy_r_r120);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 26, CPyStatic_constants___globals);
        goto CPyL117;
    }
    cpy_r_r122 = CPyStatics[68]; /* 'address' */
    cpy_r_r123 = CPyObject_GetAttr(cpy_r_r121, cpy_r_r122);
    CPy_DECREF(cpy_r_r121);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 26, CPyStatic_constants___globals);
        goto CPyL117;
    }
    cpy_r_r124 = CPyStatics[382]; /* '0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE' */
    cpy_r_r125 = CPyStatics[383]; /* '0x5e74C9036fb86BD7eCdcb084a0673EFc32eA31cb' */
    cpy_r_r126 = CPyStatics[382]; /* '0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE' */
    cpy_r_r127 = CPyStatics[384]; /* '0xae7ab96520DE3A18E5e111B5EaAb095312D7fE84' */
    cpy_r_r128 = CPyStatics[385]; /* '0x9559Aaa82d9649C7A7b220E7c461d2E74c9a3593' */
    cpy_r_r129 = CPyStatics[386]; /* '0xE95A203B1a91a908F9B9CE46459d101078c2c3cb' */
    cpy_r_r130 = PySet_New(NULL);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL118;
    }
    cpy_r_r131 = PySet_Add(cpy_r_r130, cpy_r_r118);
    cpy_r_r132 = cpy_r_r131 >= 0;
    if (unlikely(!cpy_r_r132)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL119;
    }
    cpy_r_r133 = PySet_Add(cpy_r_r130, cpy_r_r123);
    CPy_DECREF(cpy_r_r123);
    cpy_r_r134 = cpy_r_r133 >= 0;
    if (unlikely(!cpy_r_r134)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL120;
    }
    cpy_r_r135 = PySet_Add(cpy_r_r130, cpy_r_r124);
    cpy_r_r136 = cpy_r_r135 >= 0;
    if (unlikely(!cpy_r_r136)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL120;
    }
    cpy_r_r137 = PySet_Add(cpy_r_r130, cpy_r_r125);
    cpy_r_r138 = cpy_r_r137 >= 0;
    if (unlikely(!cpy_r_r138)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL120;
    }
    cpy_r_r139 = PySet_Add(cpy_r_r130, cpy_r_r126);
    cpy_r_r140 = cpy_r_r139 >= 0;
    if (unlikely(!cpy_r_r140)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL120;
    }
    cpy_r_r141 = PySet_Add(cpy_r_r130, cpy_r_r127);
    cpy_r_r142 = cpy_r_r141 >= 0;
    if (unlikely(!cpy_r_r142)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL120;
    }
    cpy_r_r143 = PySet_Add(cpy_r_r130, cpy_r_r128);
    cpy_r_r144 = cpy_r_r143 >= 0;
    if (unlikely(!cpy_r_r144)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL120;
    }
    cpy_r_r145 = PySet_Add(cpy_r_r130, cpy_r_r129);
    cpy_r_r146 = cpy_r_r145 >= 0;
    if (unlikely(!cpy_r_r146)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 24, CPyStatic_constants___globals);
        goto CPyL120;
    }
    cpy_r_r147 = CPyDict_Build(1, cpy_r_r117, cpy_r_r130);
    CPy_DECREF(cpy_r_r117);
    CPy_DECREF(cpy_r_r130);
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 23, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r148 = CPyStatic_constants___globals;
    cpy_r_r149 = CPyStatics[366]; /* 'chain' */
    cpy_r_r150 = CPyDict_GetItem(cpy_r_r148, cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 34, CPyStatic_constants___globals);
        goto CPyL121;
    }
    cpy_r_r151 = CPyStatics[387]; /* 'id' */
    cpy_r_r152 = CPyObject_GetAttr(cpy_r_r150, cpy_r_r151);
    CPy_DECREF(cpy_r_r150);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 34, CPyStatic_constants___globals);
        goto CPyL121;
    }
    if (likely(PyLong_Check(cpy_r_r152)))
        cpy_r_r153 = CPyTagged_FromObject(cpy_r_r152);
    else {
        CPy_TypeError("int", cpy_r_r152); cpy_r_r153 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r152);
    if (unlikely(cpy_r_r153 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 34, CPyStatic_constants___globals);
        goto CPyL121;
    }
    cpy_r_r154 = PySet_New(NULL);
    if (unlikely(cpy_r_r154 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 34, CPyStatic_constants___globals);
        goto CPyL122;
    }
    cpy_r_r155 = CPyTagged_StealAsObject(cpy_r_r153);
    cpy_r_r156 = CPyDict_Get(cpy_r_r147, cpy_r_r155, cpy_r_r154);
    CPy_DECREF(cpy_r_r147);
    CPy_DECREF(cpy_r_r155);
    CPy_DECREF(cpy_r_r154);
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 23, CPyStatic_constants___globals);
        goto CPyL103;
    }
    CPyStatic_constants___ETH_LIKE = cpy_r_r156;
    CPy_INCREF(CPyStatic_constants___ETH_LIKE);
    cpy_r_r157 = CPyStatic_constants___globals;
    cpy_r_r158 = CPyStatics[388]; /* 'ETH_LIKE' */
    cpy_r_r159 = CPyDict_SetItem(cpy_r_r157, cpy_r_r158, cpy_r_r156);
    CPy_DECREF(cpy_r_r156);
    cpy_r_r160 = cpy_r_r159 >= 0;
    if (unlikely(!cpy_r_r160)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 23, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r161 = CPyStatic_constants___globals;
    cpy_r_r162 = CPyStatics[127]; /* 'Network' */
    cpy_r_r163 = CPyDict_GetItem(cpy_r_r161, cpy_r_r162);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r164 = CPyStatics[129]; /* 'Mainnet' */
    cpy_r_r165 = CPyObject_GetAttr(cpy_r_r163, cpy_r_r164);
    CPy_DECREF(cpy_r_r163);
    if (unlikely(cpy_r_r165 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r166 = CPyStatics[389]; /* '0xEB4C2781e4ebA804CE9a9803C67d0893436bB27D' */
    cpy_r_r167 = CPyStatics[390]; /* '0x2260FAC5E5542a773Aa44fBCfeDf7C193bc2C599' */
    cpy_r_r168 = CPyStatics[391]; /* '0xfE18be6b3Bd88A2D2A7f928d00292E7a9963CfC6' */
    cpy_r_r169 = CPyStatics[392]; /* '0x8064d9Ae6cDf087b1bcd5BDf3531bD5d8C537a68' */
    cpy_r_r170 = CPyStatics[393]; /* '0x9BE89D2a4cd102D8Fecc6BF9dA793be995C22541' */
    cpy_r_r171 = CPyStatics[394]; /* '0x0316EB71485b0Ab14103307bf65a021042c6d380' */
    cpy_r_r172 = CPyStatics[395]; /* '0x5228a22e72ccC52d415EcFd199F99D0665E7733b' */
    cpy_r_r173 = CPyStatics[396]; /* '0x8dAEBADE922dF735c38C80C7eBD708Af50815fAa' */
    cpy_r_r174 = PySet_New(NULL);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL123;
    }
    cpy_r_r175 = PySet_Add(cpy_r_r174, cpy_r_r166);
    cpy_r_r176 = cpy_r_r175 >= 0;
    if (unlikely(!cpy_r_r176)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL124;
    }
    cpy_r_r177 = PySet_Add(cpy_r_r174, cpy_r_r167);
    cpy_r_r178 = cpy_r_r177 >= 0;
    if (unlikely(!cpy_r_r178)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL124;
    }
    cpy_r_r179 = PySet_Add(cpy_r_r174, cpy_r_r168);
    cpy_r_r180 = cpy_r_r179 >= 0;
    if (unlikely(!cpy_r_r180)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL124;
    }
    cpy_r_r181 = PySet_Add(cpy_r_r174, cpy_r_r169);
    cpy_r_r182 = cpy_r_r181 >= 0;
    if (unlikely(!cpy_r_r182)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL124;
    }
    cpy_r_r183 = PySet_Add(cpy_r_r174, cpy_r_r170);
    cpy_r_r184 = cpy_r_r183 >= 0;
    if (unlikely(!cpy_r_r184)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL124;
    }
    cpy_r_r185 = PySet_Add(cpy_r_r174, cpy_r_r171);
    cpy_r_r186 = cpy_r_r185 >= 0;
    if (unlikely(!cpy_r_r186)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL124;
    }
    cpy_r_r187 = PySet_Add(cpy_r_r174, cpy_r_r172);
    cpy_r_r188 = cpy_r_r187 >= 0;
    if (unlikely(!cpy_r_r188)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL124;
    }
    cpy_r_r189 = PySet_Add(cpy_r_r174, cpy_r_r173);
    cpy_r_r190 = cpy_r_r189 >= 0;
    if (unlikely(!cpy_r_r190)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 37, CPyStatic_constants___globals);
        goto CPyL124;
    }
    cpy_r_r191 = CPyDict_Build(1, cpy_r_r165, cpy_r_r174);
    CPy_DECREF(cpy_r_r165);
    CPy_DECREF(cpy_r_r174);
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 36, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r192 = CPyStatic_constants___globals;
    cpy_r_r193 = CPyStatics[366]; /* 'chain' */
    cpy_r_r194 = CPyDict_GetItem(cpy_r_r192, cpy_r_r193);
    if (unlikely(cpy_r_r194 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 47, CPyStatic_constants___globals);
        goto CPyL125;
    }
    cpy_r_r195 = CPyStatics[387]; /* 'id' */
    cpy_r_r196 = CPyObject_GetAttr(cpy_r_r194, cpy_r_r195);
    CPy_DECREF(cpy_r_r194);
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 47, CPyStatic_constants___globals);
        goto CPyL125;
    }
    if (likely(PyLong_Check(cpy_r_r196)))
        cpy_r_r197 = CPyTagged_FromObject(cpy_r_r196);
    else {
        CPy_TypeError("int", cpy_r_r196); cpy_r_r197 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r196);
    if (unlikely(cpy_r_r197 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 47, CPyStatic_constants___globals);
        goto CPyL125;
    }
    cpy_r_r198 = PySet_New(NULL);
    if (unlikely(cpy_r_r198 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 47, CPyStatic_constants___globals);
        goto CPyL126;
    }
    cpy_r_r199 = CPyTagged_StealAsObject(cpy_r_r197);
    cpy_r_r200 = CPyDict_Get(cpy_r_r191, cpy_r_r199, cpy_r_r198);
    CPy_DECREF(cpy_r_r191);
    CPy_DECREF(cpy_r_r199);
    CPy_DECREF(cpy_r_r198);
    if (unlikely(cpy_r_r200 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 36, CPyStatic_constants___globals);
        goto CPyL103;
    }
    CPyStatic_constants___BTC_LIKE = cpy_r_r200;
    CPy_INCREF(CPyStatic_constants___BTC_LIKE);
    cpy_r_r201 = CPyStatic_constants___globals;
    cpy_r_r202 = CPyStatics[397]; /* 'BTC_LIKE' */
    cpy_r_r203 = CPyDict_SetItem(cpy_r_r201, cpy_r_r202, cpy_r_r200);
    CPy_DECREF(cpy_r_r200);
    cpy_r_r204 = cpy_r_r203 >= 0;
    if (unlikely(!cpy_r_r204)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 36, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r205 = CPyStatic_constants___globals;
    cpy_r_r206 = CPyStatics[127]; /* 'Network' */
    cpy_r_r207 = CPyDict_GetItem(cpy_r_r205, cpy_r_r206);
    if (unlikely(cpy_r_r207 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r208 = CPyStatics[129]; /* 'Mainnet' */
    cpy_r_r209 = CPyObject_GetAttr(cpy_r_r207, cpy_r_r208);
    CPy_DECREF(cpy_r_r207);
    if (unlikely(cpy_r_r209 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r210 = CPyStatics[398]; /* '0xD71eCFF9342A5Ced620049e616c5035F1dB98620' */
    cpy_r_r211 = CPyStatics[399]; /* '0xC581b735A1688071A1746c968e0798D642EDE491' */
    cpy_r_r212 = CPyStatics[400]; /* '0xdB25f211AB05b1c97D595516F45794528a807ad8' */
    cpy_r_r213 = CPyStatics[401]; /* '0x96E61422b6A9bA0e068B6c5ADd4fFaBC6a4aae27' */
    cpy_r_r214 = CPyStatics[402]; /* '0x269895a3dF4D73b077Fc823dD6dA1B95f72Aaf9B' */
    cpy_r_r215 = CPyStatics[403]; /* '0x3F1B0278A9ee595635B61817630cC19DE792f506' */
    cpy_r_r216 = CPyStatics[404]; /* '0x97fe22E7341a0Cd8Db6F6C021A24Dc8f4DAD855F' */
    cpy_r_r217 = CPyStatics[405]; /* '0xF6b1C627e95BFc3c1b4c9B825a032Ff0fBf3e07d' */
    cpy_r_r218 = CPyStatics[406]; /* '0x0F83287FF768D1c1e17a42F44d644D7F22e8ee1d' */
    cpy_r_r219 = CPyStatics[402]; /* '0x269895a3dF4D73b077Fc823dD6dA1B95f72Aaf9B' */
    cpy_r_r220 = PySet_New(NULL);
    if (unlikely(cpy_r_r220 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL127;
    }
    cpy_r_r221 = PySet_Add(cpy_r_r220, cpy_r_r210);
    cpy_r_r222 = cpy_r_r221 >= 0;
    if (unlikely(!cpy_r_r222)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r223 = PySet_Add(cpy_r_r220, cpy_r_r211);
    cpy_r_r224 = cpy_r_r223 >= 0;
    if (unlikely(!cpy_r_r224)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r225 = PySet_Add(cpy_r_r220, cpy_r_r212);
    cpy_r_r226 = cpy_r_r225 >= 0;
    if (unlikely(!cpy_r_r226)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r227 = PySet_Add(cpy_r_r220, cpy_r_r213);
    cpy_r_r228 = cpy_r_r227 >= 0;
    if (unlikely(!cpy_r_r228)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r229 = PySet_Add(cpy_r_r220, cpy_r_r214);
    cpy_r_r230 = cpy_r_r229 >= 0;
    if (unlikely(!cpy_r_r230)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r231 = PySet_Add(cpy_r_r220, cpy_r_r215);
    cpy_r_r232 = cpy_r_r231 >= 0;
    if (unlikely(!cpy_r_r232)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r233 = PySet_Add(cpy_r_r220, cpy_r_r216);
    cpy_r_r234 = cpy_r_r233 >= 0;
    if (unlikely(!cpy_r_r234)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r235 = PySet_Add(cpy_r_r220, cpy_r_r217);
    cpy_r_r236 = cpy_r_r235 >= 0;
    if (unlikely(!cpy_r_r236)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r237 = PySet_Add(cpy_r_r220, cpy_r_r218);
    cpy_r_r238 = cpy_r_r237 >= 0;
    if (unlikely(!cpy_r_r238)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r239 = PySet_Add(cpy_r_r220, cpy_r_r219);
    cpy_r_r240 = cpy_r_r239 >= 0;
    if (unlikely(!cpy_r_r240)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 50, CPyStatic_constants___globals);
        goto CPyL128;
    }
    cpy_r_r241 = CPyDict_Build(1, cpy_r_r209, cpy_r_r220);
    CPy_DECREF(cpy_r_r209);
    CPy_DECREF(cpy_r_r220);
    if (unlikely(cpy_r_r241 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 49, CPyStatic_constants___globals);
        goto CPyL103;
    }
    cpy_r_r242 = CPyStatic_constants___globals;
    cpy_r_r243 = CPyStatics[366]; /* 'chain' */
    cpy_r_r244 = CPyDict_GetItem(cpy_r_r242, cpy_r_r243);
    if (unlikely(cpy_r_r244 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 62, CPyStatic_constants___globals);
        goto CPyL129;
    }
    cpy_r_r245 = CPyStatics[387]; /* 'id' */
    cpy_r_r246 = CPyObject_GetAttr(cpy_r_r244, cpy_r_r245);
    CPy_DECREF(cpy_r_r244);
    if (unlikely(cpy_r_r246 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 62, CPyStatic_constants___globals);
        goto CPyL129;
    }
    if (likely(PyLong_Check(cpy_r_r246)))
        cpy_r_r247 = CPyTagged_FromObject(cpy_r_r246);
    else {
        CPy_TypeError("int", cpy_r_r246); cpy_r_r247 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r246);
    if (unlikely(cpy_r_r247 == CPY_INT_TAG)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 62, CPyStatic_constants___globals);
        goto CPyL129;
    }
    cpy_r_r248 = PySet_New(NULL);
    if (unlikely(cpy_r_r248 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 62, CPyStatic_constants___globals);
        goto CPyL130;
    }
    cpy_r_r249 = CPyTagged_StealAsObject(cpy_r_r247);
    cpy_r_r250 = CPyDict_Get(cpy_r_r241, cpy_r_r249, cpy_r_r248);
    CPy_DECREF(cpy_r_r241);
    CPy_DECREF(cpy_r_r249);
    CPy_DECREF(cpy_r_r248);
    if (unlikely(cpy_r_r250 == NULL)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 49, CPyStatic_constants___globals);
        goto CPyL103;
    }
    CPyStatic_constants___INTL_STABLECOINS = cpy_r_r250;
    CPy_INCREF(CPyStatic_constants___INTL_STABLECOINS);
    cpy_r_r251 = CPyStatic_constants___globals;
    cpy_r_r252 = CPyStatics[407]; /* 'INTL_STABLECOINS' */
    cpy_r_r253 = CPyDict_SetItem(cpy_r_r251, cpy_r_r252, cpy_r_r250);
    CPy_DECREF(cpy_r_r250);
    cpy_r_r254 = cpy_r_r253 >= 0;
    if (unlikely(!cpy_r_r254)) {
        CPy_AddTraceback("eth_portfolio/constants.py", "<module>", 49, CPyStatic_constants___globals);
        goto CPyL103;
    }
    return 1;
CPyL103: ;
    cpy_r_r255 = 2;
    return cpy_r_r255;
CPyL104: ;
    CPy_DecRef(cpy_r_r39);
    goto CPyL103;
CPyL105: ;
    CPy_DecRef(cpy_r_r45);
    goto CPyL103;
CPyL106: ;
    CPy_DecRef(cpy_r_r56);
    goto CPyL103;
CPyL107: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r57);
    goto CPyL17;
CPyL108: ;
    CPyTagged_DECREF(cpy_r_r60);
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL31;
CPyL109: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r57);
    CPyTagged_DecRef(cpy_r_r60);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL103;
CPyL110: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r57);
    CPyTagged_DecRef(cpy_r_r60);
    CPy_DecRef(cpy_r_r69);
    goto CPyL103;
CPyL111: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r57);
    CPyTagged_DecRef(cpy_r_r60);
    CPy_DecRef(cpy_r_r69);
    CPy_DecRef(cpy_r_r72);
    goto CPyL103;
CPyL112: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r57);
    CPyTagged_DecRef(cpy_r_r60);
    goto CPyL103;
CPyL113: ;
    CPy_DECREF(cpy_r_r82);
    goto CPyL40;
CPyL114: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r82);
    goto CPyL103;
CPyL115: ;
    CPy_DECREF(cpy_r_r84);
    goto CPyL32;
CPyL116: ;
    CPy_DecRef(cpy_r_r56);
    CPy_DecRef(cpy_r_r82);
    CPy_DecRef(cpy_r_r87);
    goto CPyL103;
CPyL117: ;
    CPy_DecRef(cpy_r_r117);
    goto CPyL103;
CPyL118: ;
    CPy_DecRef(cpy_r_r117);
    CPy_DecRef(cpy_r_r123);
    goto CPyL103;
CPyL119: ;
    CPy_DecRef(cpy_r_r117);
    CPy_DecRef(cpy_r_r123);
    CPy_DecRef(cpy_r_r130);
    goto CPyL103;
CPyL120: ;
    CPy_DecRef(cpy_r_r117);
    CPy_DecRef(cpy_r_r130);
    goto CPyL103;
CPyL121: ;
    CPy_DecRef(cpy_r_r147);
    goto CPyL103;
CPyL122: ;
    CPy_DecRef(cpy_r_r147);
    CPyTagged_DecRef(cpy_r_r153);
    goto CPyL103;
CPyL123: ;
    CPy_DecRef(cpy_r_r165);
    goto CPyL103;
CPyL124: ;
    CPy_DecRef(cpy_r_r165);
    CPy_DecRef(cpy_r_r174);
    goto CPyL103;
CPyL125: ;
    CPy_DecRef(cpy_r_r191);
    goto CPyL103;
CPyL126: ;
    CPy_DecRef(cpy_r_r191);
    CPyTagged_DecRef(cpy_r_r197);
    goto CPyL103;
CPyL127: ;
    CPy_DecRef(cpy_r_r209);
    goto CPyL103;
CPyL128: ;
    CPy_DecRef(cpy_r_r209);
    CPy_DecRef(cpy_r_r220);
    goto CPyL103;
CPyL129: ;
    CPy_DecRef(cpy_r_r241);
    goto CPyL103;
CPyL130: ;
    CPy_DecRef(cpy_r_r241);
    CPyTagged_DecRef(cpy_r_r247);
    goto CPyL103;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_eth_portfolio____loaders____nonce = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_asyncio = Py_None;
    CPyModule_logging = Py_None;
    CPyModule_collections = Py_None;
    CPyModule_time = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_a_sync = Py_None;
    CPyModule_dank_mids = Py_None;
    CPyModule_eth_typing = Py_None;
    CPyModule_eth_portfolio____loaders = Py_None;
    CPyModule_eth_portfolio____loaders___balances = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_logging = Py_None;
    CPyModule_decimal = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_y = Py_None;
    CPyModule_y____decorators = Py_None;
    CPyModule_y___datatypes = Py_None;
    CPyModule_eth_portfolio____decimal = Py_None;
    CPyModule_eth_portfolio____utils = Py_None;
    CPyModule_eth_portfolio___typing = Py_None;
    CPyModule_eth_portfolio____loaders___utils = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_dank_mids = Py_None;
    CPyModule_eth_retry = Py_None;
    CPyModule_msgspec = Py_None;
    CPyModule_a_sync = Py_None;
    CPyModule_async_lru = Py_None;
    CPyModule_eth_typing = Py_None;
    CPyModule_y____decorators = Py_None;
    CPyModule_eth_portfolio____argspec = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_inspect = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_eth_portfolio____config = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_os = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_eth_portfolio____shitcoins = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_collections = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_eth_typing = Py_None;
    CPyModule_y = Py_None;
    CPyModule_eth_portfolio___constants = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_os = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_brownie = Py_None;
    CPyModule_y = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[462];
const char * const CPyLit_Str[] = {
    "\003\vdefaultdict\020block_identifier\nValueError",
    "\005\037error creating execution cursor\004For \004 at \002: \rGeneratorExit",
    "\003\rStopIteration\t__aexit__\n__aenter__",
    "\0012Nonce for %s at %s is %s, checking higher block %s",
    "\0011Nonce for %s at %s is %s, checking lower block %s",
    "\005!Found nonce %s for %s at block %s\004Lock\nupdated_at\005block\003eth",
    "\004\fblock_number\bbuiltins\aasyncio\alogging",
    "\005 eth_portfolio/_loaders/_nonce.py\b<module>\vcollections\004time\bClassVar",
    "\b\vDefaultDict\004Dict\005Final\005Tuple\005final\006typing\006a_sync\tdank_mids",
    "\005\vBlockNumber\017ChecksumAddress\neth_typing\005utils\026eth_portfolio._loaders",
    "\005\024eth_portfolio.nonces\tgetLogger\006logger\fisEnabledFor\021logger_is_enabled",
    "\b\004_log\005__log\005DEBUG\005Nonce\rAccountNonces\fGlobalNonces\006nonces\005locks",
    "\004\025get_transaction_count\aigather\003now\035eth_portfolio._loaders._nonce",
    "\006\017__mypyc_attrs__\004lock\003ttl\nBlockCache\023balance_of_readable\004sync",
    "\005\020NonStandardERC20\033NonStandardERC20 exc for %s\aaddress\aBalance\005token",
    "\005\n_get_price\005round\aDecimal\abalance\tusd_value",
    "\004\"eth_portfolio/_loaders/balances.py\020InvalidOperation\adecimal\001y",
    "\005\023stuck_coro_debugger\ry._decorators\aAddress\005Block\vy.datatypes",
    "\003\026eth_portfolio._decimal\024eth_portfolio._utils\024eth_portfolio.typing",
    "\006\005_ZERO\b__name__\awarning\vlog_warning\022load_token_balance\tdecode_to",
    "\004\vdecode_hook\teth_retry\amsgspec\037eth_portfolio/_loaders/utils.py",
    "\006\024SmartProcessingQueue\nalru_cache\tasync_lru\006HexStr\003Raw\016TxReceiptQueue",
    "\004\030_get_transaction_receipt\amaxsize\nauto_retry\016min_sleep_time",
    "\004\016max_sleep_time\vmax_retries\rsuppress_logs\027get_transaction_receipt",
    "\006\031__get_transaction_receipt\016getfullargspec\004self\003Any\006return\ainspect",
    "\a\bCallable\004List\004Type\002os\030eth_portfolio/_config.py\aenviron\fREORG_BUFFER",
    "\005\003get\003Set\aNetwork\aconvert\aMainnet",
    "\001*0xb8ac53AFCCEBc44AaC33D0C30E2Ae0783E7fde5f",
    "\001*0xe397ef3E332256F38983ffaE987158da3e18c5Ec",
    "\001*0x7452E3fC2fE611C6B7761c6c393BECe059881aC7",
    "\001*0x4ab16CDc82a4eA4727Ab40caee1bb46622C13641",
    "\001*0x471c3A7f132bc94938516CB2Bf6f02C7521D2797",
    "\001*0x106EebF11F34ECCcaD59c1CA9398d828765f64f8",
    "\001*0x634a31d5DB29F2a646bADAd27bb7b1E5A78FD316",
    "\001*0xF673623e8507551BDe72290E909c7E184A4799a3",
    "\001*0x269641A320F8465eF4e710F51Dc6e6862D7E8A77",
    "\001*0x956F824B5a37673c6fC4a6904186cB3BA499349B",
    "\001*0xBFA9180729f1c549334080005Ca37093593fB7Aa",
    "\001*0x643695D282f6BA237afe27FFE0Acd89a86b50d3e",
    "\001*0xCfB0Ef3e179427316FBD7F0D0296F173762BeEE0",
    "\001*0xfAFe8a7c0A9b3807CC1df0DEB0BA0B5a5fb7A872",
    "\001*0xdf66B9727553fB9Bfa417699CB8F60425d62d1E3",
    "\001*0x68Ca006dB91312Cd60a2238Ce775bE5F9f738bBa",
    "\001*0xBCCBeDAb3Bf6FA1cfC3e2d07Aa5ce4A282864D6E",
    "\001*0x26004d228fC8A32c5bd1a106108c8647A455B04a",
    "\001*0x635701CC5fE41FE8AbD02aa74Beb02e3540E9BB2",
    "\001*0xf8358bd95dcA48187e3F4BE05847F3593776C086",
    "\001*0x459176FDC68C945B6bb23eB946eee62457041567",
    "\001*0xf55F8aA8F3d777f1aB3A4ae9E269C8D7B73078De",
    "\001*0x434d5875534D19fC7105281Cf61dbfd1C93c8cb1",
    "\001*0x908599FDf490b73D171B57731bd4Ca95b7F0DE6a",
    "\001*0x4709099BE25D156578405132d66aeBfC2e12937A",
    "\001*0x82315517d61ecf47f9A78705127934F3d431cB21",
    "\001*0x2B000332CD291eF558aF76298A4d6F6001E4e015",
    "\001*0x163F4D81d86ac282A0F0F94D9FE3E0321ACcfd37",
    "\001*0x660235331d2FA5FeB7a49F31556B0Be31f02560D",
    "\001*0x696F33F4dd9BE5538483f63308453D2D67D07331",
    "\001*0xcbbadd74b3bb09836d97d91050e13E06089ba485",
    "\001*0xE0c31b3e341E7EF3C04eB14E58802b88a80A45A1",
    "\001*0xA6D74802a2222d5cCe5eA0531159ed878943b54c",
    "\001*0xcAB80A2bf07BECaF8d48168081352ea873B8Db91",
    "\001*0x72B12aec69dA93357f2B69aCf33d5B75cF17575B",
    "\001*0xA4C8A13FeE3b19718E45d678C071bDE3e33A7302",
    "\001*0x579e4ca5888eD1420492988BF75E26D9e7B4C535",
    "\001*0xB80216D5b4eec2BEc74eF10e5d3814Fec6Fd8af0",
    "\001*0x6A007E207E50B4C6B2ADCFc6a873F6e698645fE3",
    "\001*0x84d12988D71244a8937a9816037BeB3e61E17FdD",
    "\001*0x0734E85525Ca6838fe48EC6EB29b9d457F254F73",
    "\001*0xa10c97bF5629340A35c41a8AA308af0804750605",
    "\001*0x69D732F50e248D4B825d524fEDEB0D7Ce3d76352",
    "\001*0xAF0b2fBeDd5d1Fda457580FB3DAbAD1F5C8bBC36",
    "\001*0xbadb4170Cd3309680477Fc81D527101cbB4000EE",
    "\001*0x7841479c5976b8184DBcde9a7a5113901b233EfB",
    "\001*0x1e4A0ADFC2e9bf2Dfd041Bc89405538d0D5A077a",
    "\001*0xb07de4b2989E180F8907B8C7e617637C26cE2776",
    "\001*0xa9517B2E61a57350D6555665292dBC632C76adFe",
    "\001*0x38715Ab4b9d4e00890773D7338d94778b0dFc0a8",
    "\001*0x6171136E82a2f1bAA2494c69528f599467EfeA20",
    "\001*0x9Ee582c42F88CAA5e7BCDE2e86e69Af3Cf5FCe40",
    "\001*0xFD1860C9d602236214652a21753731F9acD2C362",
    "\001*0x0Fd23DaB8723b1Fd5e7c3d74Baa624B443423b6B",
    "\001*0xe0736F3F455F1DBD29Bf6F8346EAd22f5CF78d08",
    "\001*0x7F57A01fc540ca3A26345C4903B9a220aD048196",
    "\001*0xF709642622729feafC8bf0934679706df49d8A30",
    "\001*0x0bF377fb3b5F1dD601e693B8fAF6b0bD249f37D3",
    "\001*0xBf5fB1563ef58ba41325454ca61Cc3D62bd40744",
    "\001*0x54fd62228C6e1234fd5Fded28555CA963Dcf6d26",
    "\001*0xA36Ceec605d81aE74268Fda28A5c0Bd10b1D1f7C",
    "\001*0xF9d25EB4C75ed744596392cf89074aFaA43614a8",
    "\001*0x1412ECa9dc7daEf60451e3155bB8Dbf9DA349933",
    "\001*0x1fc4DB3e7f9124bAAFB7B34346dB7931Dad621C2",
    "\001*0x120aA018634F555484c088c8da80F75Aa07E004F",
    "\001*0xeDe11D3d5dd7D5454844f6f121cc106bF1144a45",
    "\001*0x875bf9be244970B8572DD042053508bF758371Ee",
    "\001*0x070C0147884D7CF984aFBC2Eb6F3428A39b5E229",
    "\001*0xb0B1d4732eFE32AEA466ED6BC3c79181eD4810c4",
    "\001*0xCf39B7793512F03f2893C16459fd72E65D2Ed00c",
    "\001*0x89532890c2959e836C1Bca52309356841238b8B7",
    "\001*0xD1B0c350f73E6f7Cd5c9978b82B46a59aE9aD524",
    "\001*0x17a10104CBC1eD155D083eaD9FCF5C3440bb50e8",
    "\001*0x8eB3FecAAA963C86d9b49004d9f28092f1Db3D6c",
    "\001*0x52bbca3B24c1c1ac050fF4546F37AA88282aaE22",
    "\001*0xECF0dE4C8498Cfd686E4702D955426b22d812d6B",
    "\001*0xF01f7A348681776c1FC9A066c6973882B693cdC6",
    "\001*0x0e1CD6d2715432e4DBedFE969b0Eb2867FF61d5b",
    "\001*0x174Cd3359C6a4E6B64D2995Da4E2E4631379526E",
    "\001*0x85E199607eb8aEef775Ae6424b42d20616267852",
    "\001*0x4D57c67C8Bab0Fb3A0a0A35B904FBff4E5450521",
    "\001*0x884a886D17a64852d18e5921fA7A05ae2954C9Bb",
    "\001*0xbB5c3B198f6def369bFB6AC7A34BB08eA49a0770",
    "\001*0x5be480Aa056ec274e5aE970d7A75dF0c9620F6F8",
    "\001*0xA1f76F1c94078f7d2E05152DC3e31dED819dfDC0",
    "\001*0xCE3F076D0ADa9f913a24F42dEAB82e4b851B87d6",
    "\001*0xB215F3927192181eBCD79227c70c10015Ff10df3",
    "\001*0x37843BC944eDBb0477df943d9061D359004a4e70",
    "\001*0x9A7ddeE20b61EA4f4812665EdF39dD157a66E873",
    "\001*0xfcBe0B695c13257bd43D64f09Db433034E90033D",
    "\001*0x7d09A736c5FB1Db357dE04A07DEB22D5829DA26F",
    "\001*0x6Ac9cA5710Ba6B985b46fd5282a59eBbea3434d4",
    "\001*0xD6619A3E925472a8d7822Cc6A49B76b3554A3498",
    "\001*0x338C1E2B51C4E818765a887584e7041EF9070aef",
    "\001*0x83D473D1acD97Aa45A97c3b778fB5714e7e4c604",
    "\001*0x5bb38F4899797f03141782E9d2130C12769c0CCc",
    "\001*0x1F7B20004eBd7E258b9f45568cE789fC5d2140fb",
    "\001*0x92Aeed8027735C41605577b45A69429Bd7f729f9",
    "\001*0x8A801C334ebaC763822a0D85a595AeC6Da59C232",
    "\001*0xd5b0Bd07864C0aaCC3b6Cd5e63C68c62C0F263d2",
    "\001*0x2b23BF339F5cc3393a558373E0A73a576F0838D3",
    "\001*0x7B2e238FB48ee7322664B9C26bb3ACedBfCC1f70",
    "\001*0x08918171758171A13050cdE6Cc6eB90172Af5737",
    "\001*0x9398c448728738039b91687919262194899D3f27",
    "\001*0x0A527683c3154F5F9E1b4203Ef4d05962b2411bf",
    "\001*0xe3C6F9D0d731C2Eb6B6D3eBFb6732fCd26a365d0",
    "\001*0x6cF0B5A20B2d4b55e6b752d7016275B892035652",
    "\001*0x98d1c76831c0aBEa30e3dac8628BD72d6B0E3dd2",
    "\001*0x4C6fDc0476B2FE0daFf0B5824c3A918673d6014E",
    "\001*0xC6d3D201530a6D4aD9dFbAAd39C5f68A9A470a69",
    "\001*0x525fC44CBE181C1108c209091B5EEc5a5028190d",
    "\001*0x7d1a6a4f806A4a64AD32e7F2350E176eA6B9a1F6",
    "\001*0x75E34A4A04d5f5F7Fc01801d2d287d64D882529B",
    "\001*0x8F49cB69ee13974D6396FC26B0c0D78044FCb3A7",
    "\001*0xB688d06d858E092EBB145394a1BA08C7a10E1F56",
    "\001*0x154C5875b1B0DB1794f88D003730DaD160E6b38e",
    "\001*0x11068577AE36897fFaB0024F010247B9129459E6",
    "\001*0xBA89375bAE9b3DE92442e9C037d4303A6e4FB086",
    "\001*0xcDbd4089C2F98DA715e52127680f87aFdB183A2e",
    "\001*0x3a3a4d2d9755283D9e25105B042C5f45BC0Edf05",
    "\001*0x70c18F2fDcb00d27494f767503874788e35c9940",
    "\001*0xF511123fdf2F13811abf4edDb493860101471729",
    "\001*0x830Cbe766EE470B67F77ea62a56246863F75f376",
    "\001*0x76988Eb5d8a81F44919d87328c36179FdCca044a",
    "\001*0xa6DE609807c7258A0D34F5307c1808F062A59794",
    "\001*0x698068C6a369b1BF04D516f5fE48424797973DCf",
    "\001*0xbEb3c5F7f4F8dB708BcfaC4D0fDcDb0bEd285741",
    "\001*0xCdC94877E4164D2e915fC5E8310155D661A995F1",
    "\001*0x5D80A8D8CB80696073e82407968600A37e1dd780",
    "\001*0x19383F024BA4c06e44D11a8B8BB7ebF87faB184C",
    "\001*0xF5b2C59F6DB42FFCdFC1625999C81fDF17953384",
    "\001*0xdb83eC9EEAC2b3CF8Eb282f91c73C38159578697",
    "\001*0x2F30E0F6B484eF6Be57b6435e34687018ff8Cb4D",
    "\001*0x242a705E8AF8A24B7EB30f3DbAF899eB25E3D76A",
    "\001*0x2f848B4A2B5dfC3b9e4Eb229551c0887E6348653",
    "\001*0x0795619E02716a81ac9EF6E55363D538DA104e57",
    "\001*0x6D9541ba0f1039d0f8636b4f39D20A8a7464f357",
    "\001*0x1C3d9Db84e0EEE4744893A7FAeE6187F31E39539",
    "\001*0x3654746Ce159BA2FCDF926133D51ecBb85f19288",
    "\001*0x67542502245eb5DF64eF7Ea776199CeB79401058",
    "\001*0x0951490Cec0261F60Ff0C42DE7F62488Cc8313D8",
    "\001*0xcdBb37f84bf94492b44e26d1F990285401e5423e",
    "\001*0x53d345839E7dF5a6c8Cf590C5c703AE255E44816",
    "\001*0xCCCCee7d9B0f18ab16b217A794D2671549F1A895",
    "\001*0xc6a76f7ad66d0e6Ccd1AaAd6e7568c9bd55Dce62",
    "\001*0xB4d4334eB5a251cbE5cC7Afb0Ba26119aCE62281",
    "\001*0xE5c5AE39B98eFd9D3c9E0F2a5457D98fFA4b0b46",
    "\001*0x2Ec109a0ceFEC70661a242a8B54cae8f45630397",
    "\001*0x11d666B9C8fa057774324a9bFe6B53eB8d23079f",
    "\001*0x0598BEf845934d83463cEaDd8C86F0801e2Ee058",
    "\001*0xAcDfe439652F78750AFCe1BbA2cB9068EDb4e69c",
    "\001*0xd3cc310DD7b94D6Ef06615f73A3029A67d935c5E",
    "\001*0x0C6D7f5a8c122aCB941aCb95cb99C2cdE893b7a7",
    "\001*0xCBd85ffF5106a42d622be7F9e528DB0bfF07Da8A",
    "\001*0x22e810C6aed30FA93C2D2B62F456E5f78e8918e1",
    "\001*0xc750d0c91DD5f2D3964931FF5dC42B2bB3e008C1",
    "\001*0x6284C089D6944df1ba61bd56618AEba07D1d6136",
    "\001*0x4E654E3A532a386329bde5f01D0AC7995Ab94c07",
    "\001*0x570EC272F07c563860477DCAfB04a04FFd2979a1",
    "\001*0xEcd8eDb13Cd68707579D5EC891A24C03B8d5E831",
    "\001*0x5D6434D533922d60F1eeec913f680C5daF31cB9A",
    "\001*0x15B8adFa95e841a55867495F07B8102329546987",
    "\001*0xFe0bb2ae94BF11de9773DECb413b4a6a241cBCd0",
    "\001*0x4d3D07f4E7a154c32D36bBcBE2Ea64E0B6F98440",
    "\001*0xEea2fEf22353282fb760d27EA7A1E2f06B3F442d",
    "\001*0x218Ae209BEc57eeFa9149789aE09388459bC91d1",
    "\001*0x4639FFC90b0fD6Dffb57Af712109bfa419afaEB5",
    "\001*0x39dDC0a04F0E1F2830f3f1FEc414cD6E23168beE",
    "\001*0x4a41775Da459B38e641141e4C696DF10EC1f4983",
    "\001*0x72C07D9151DcE2ea862595487ef7e21cC312e564",
    "\001*0xE00cD9B8ebb503E4bE266983EfC6158fCFfe0004",
    "\001*0x46DDf95a62b0F2eF6dc4e70717f36172a595517F",
    "\001*0x7cfa05320D83A20980Ac76B91a3A11981877Ef3A",
    "\001*0xbbaC5B019876534c3C399F56E150684c5015F670",
    "\001*0x2840a9fC9ad15738c762e404300761eC828aFFCb",
    "\001*0xC1c8c49b0405f6CFfBA5351179bEFB2d8a2c776c",
    "\001*0xcB56B36Ef3d4E5C3b7d2fbC4f4Ee5d525893a555",
    "\001*0x5807daC5CC59F02dFA88154dE7F9f2174C263814",
    "\001*0x6545B409acdD7e1BE14C835B5c3B826C5d312D02",
    "\001*0xdF781bBA6F9EefB1A74bb39f6DF5e282c5976636",
    "\001*0x85D385244D41ac914484FD6fbBaB177c10A86e79",
    "\001*0xa51a8578052EdEB4Ced5333A5e058860d9E7a35b",
    "\001*0x7a6b87D7a874Fce4c2d923b09C0E09e4936bcF57",
    "\001*0xFabb91ae9318082505c2c6d7acD9d521d4eDDEFf",
    "\001*0x4Fe8CEdb3f76Ed69b4914958B80Cf9c6D4E3b416",
    "\001*0xa75Fa7DEa69aBd84C9812919039Cb33e2092aab6",
    "\001*0x37dC2fD3A38fd3E898299E754C19772A67f1912B",
    "\001*0x445A32D3095D1ea8951180B0fD6004258beB72F3",
    "\001*0xBD3E4E06074F6bBDfa8B24Ba0736db4DE77EAF0A",
    "\001*0xAba86342C3f57E002F47F6eb38099A577312F2e8",
    "\001*0x94C4bfDD351A2EeA9d57e602C2a24d6Fe823Fd1a",
    "\001*0xAfF006725DeeAF5BF6750A6C7c98D9e70cB189a4",
    "\001*0x98a7800EB17e1A0e2b2A4b69e83c58F4535F2180",
    "\001*0xdC5BCA9992191c900D7A7F5b8e1b3e4161d1aa51",
    "\001*0xd27255AA153ae470419B0198fa61e892a612aFE8",
    "\001*0xbADbe6619c0563c60E62C7409681440a80391a27",
    "\001*0xf84f908E78f9295b53883AD9ACa38F86d513f03F",
    "\001*0x20Dd160716b0387220Eea7B9951bDb51B3728DC4",
    "\001*0xd91AdE7B3c349815e427cf678837cC12F72d1d38",
    "\001*0xa362389216664668bC195f6BF1940d3754914219",
    "\001*0x9257Cf49802E00048A30a6429e9c4d86210F4253",
    "\001*0x6b1b80b4b3228060EA21C292a3b9c576691Ca6cC",
    "\001*0x225795bb6D20773a4A34c682Ae8457D00C80F955",
    "\001*0x25741E94782d3EaA7fb0A02D78256bf065AEC3B9",
    "\001*0x3C78E3391C47fB9310BDB9085955934E1622442f",
    "\002*0x1f186De364a56e741Fcb188d37a393d409D08AeA\006Fantom",
    "\002*0x630277E37fd2Ddf81e4683f3692dD817aa6225Cb\bOptimism",
    "\001*0x168fbA6072EE467931484a418EDeb5FcC1B9fb79",
    "\001*0x04788E66B9D884969538e4e35a0D57e9e022c799",
    "\001*0x6Cad3dE073FD85567c0Df84063c8990855710677",
    "\001*0x109390594d0ef9B40B4B745Cac6ceCf37a179417",
    "\001*0x87f4b57E2d3c8C9dCD85aD9dA80129f92754b19f",
    "\001*0x1828Bff08BD244F7990edDCd9B19cc654b33cDB4",
    "\002*0xd8dAE0aD69F4aDB507dB0C3e56Ec94942D470450\bArbitrum",
    "\001*0xA57D85481B9ecD864F542Ea37bAA79A101a4f599",
    "\001*0x73fcaFc42ABB43A408bdE4b37eAfCCDadCB2b554",
    "\001*0x13577D823114697289cf85d3f563a21417022e7C",
    "\001*0xb8f2A48362371F7B4E88460BD4B3B5dba48A344f",
    "\001*0x184deAc2B1052AcB020Fa5159683733be3447699",
    "\001*0xBE9460b50f515169E14545aaddF60B3C9dB7e5Fb",
    "\001*0x8fb95D642C19a9C5C9138C5b444455A69196F2EC",
    "\001*0x1d7edf990Cd21eaB14aA55f8d06a386c73D24B5B",
    "\001*0x96C708e060CdC5B8C6Ac6a015db0b10833F74157",
    "\001*0x4dB2207C2cf35aA5ecFE61c5d098Bb3e3Ed1a7B0",
    "\001*0x17c074e90372aC53FF98cA24c3745E6E38717C14",
    "\001*0xA4468e55c5723C2346484f6a01da7b8826EEeC1b",
    "\001*0xdf109e2b175038c66e074BfEacF37D7b0f3e426c",
    "\001*0xeCd434A1391c208C3Cf4D8aa0e91FCd7B84D2B91",
    "\001*0xef7aA9F26F586a96F3C7E2E5308296aAD56E7F30",
    "\001*0xd8b86C2d30101848Ffb9eB0D4019b94De13374CC",
    "\004*0x43566AeD154526E2d62B60Fc9d31C98d4feaf99c\tshitcoins\tSHITCOINS\005chain",
    "\005\006tokens\nto_address\032eth_portfolio/constants.py\abrownie\004weth",
    "\001B0xddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef",
    "\001\031ERC20_TRANSFER_EVENT_HASH",
    "\001B0xe19260aff97b920c7df27010903aeb9c8d2be5d310a2c67824cf3f15396e4c16",
    "\004\032ERC677_TRANSFER_EVENT_HASH\vNUM_WALLETS\00210\022PORTFOLIO_ADDRESS_",
    "\003\tADDRESSES\rTRANSFER_SIGS\003ETH",
    "\001*0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE",
    "\001*0x5e74C9036fb86BD7eCdcb084a0673EFc32eA31cb",
    "\001*0xae7ab96520DE3A18E5e111B5EaAb095312D7fE84",
    "\001*0x9559Aaa82d9649C7A7b220E7c461d2E74c9a3593",
    "\003*0xE95A203B1a91a908F9B9CE46459d101078c2c3cb\002id\bETH_LIKE",
    "\001*0xEB4C2781e4ebA804CE9a9803C67d0893436bB27D",
    "\001*0x2260FAC5E5542a773Aa44fBCfeDf7C193bc2C599",
    "\001*0xfE18be6b3Bd88A2D2A7f928d00292E7a9963CfC6",
    "\001*0x8064d9Ae6cDf087b1bcd5BDf3531bD5d8C537a68",
    "\001*0x9BE89D2a4cd102D8Fecc6BF9dA793be995C22541",
    "\001*0x0316EB71485b0Ab14103307bf65a021042c6d380",
    "\001*0x5228a22e72ccC52d415EcFd199F99D0665E7733b",
    "\002*0x8dAEBADE922dF735c38C80C7eBD708Af50815fAa\bBTC_LIKE",
    "\001*0xD71eCFF9342A5Ced620049e616c5035F1dB98620",
    "\001*0xC581b735A1688071A1746c968e0798D642EDE491",
    "\001*0xdB25f211AB05b1c97D595516F45794528a807ad8",
    "\001*0x96E61422b6A9bA0e068B6c5ADd4fFaBC6a4aae27",
    "\001*0x269895a3dF4D73b077Fc823dD6dA1B95f72Aaf9B",
    "\001*0x3F1B0278A9ee595635B61817630cC19DE792f506",
    "\001*0x97fe22E7341a0Cd8Db6F6C021A24Dc8f4DAD855F",
    "\001*0xF6b1C627e95BFc3c1b4c9B825a032Ff0fBf3e07d",
    "\002*0x0F83287FF768D1c1e17a42F44d644D7F22e8ee1d\020INTL_STABLECOINS",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\v1\0000\000-1\0002\00010\00018\0003600\0003\00020\0005000\00030",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    43, 1, 4, 3, 23, 23, 23, 3, 24, 24, 24, 2, 420, 421, 1, 3, 1, 28, 6,
    29, 30, 31, 32, 33, 34, 3, 36, 36, 36, 3, 37, 37, 37, 2, 426, 427, 2,
    38, 39, 1, 41, 1, 65, 2, 70, 19, 4, 74, 75, 70, 19, 1, 421, 1, 77, 1,
    32, 3, 79, 79, 79, 1, 437, 1, 80, 2, 82, 83, 1, 73, 1, 71, 1, 69, 2,
    93, 94, 3, 95, 95, 95, 3, 96, 96, 96, 3, 427, 445, 446, 1, 98, 1, 99,
    1, 101, 2, 105, 62, 4, 107, 108, 109, 110, 1, 113, 5, 115, 118, 119,
    33, 120, 3, 121, 121, 121, 1, 455, 3, 30, 32, 126, 1, 39, 2, 127, 128,
    1, 366, 3, 127, 128, 371
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_eth_portfolio____loaders____nonce_internal = NULL;
CPyModule *CPyModule_eth_portfolio____loaders____nonce;
PyObject *CPyStatic__nonce___globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_asyncio;
CPyModule *CPyModule_logging;
CPyModule *CPyModule_collections;
CPyModule *CPyModule_time;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_a_sync;
CPyModule *CPyModule_dank_mids;
CPyModule *CPyModule_eth_typing;
CPyModule *CPyModule_eth_portfolio____loaders;
CPyModule *CPyModule_eth_portfolio____loaders___balances_internal = NULL;
CPyModule *CPyModule_eth_portfolio____loaders___balances;
PyObject *CPyStatic_balances___globals;
CPyModule *CPyModule_decimal;
CPyModule *CPyModule_y;
CPyModule *CPyModule_y____decorators;
CPyModule *CPyModule_y___datatypes;
CPyModule *CPyModule_eth_portfolio____decimal;
CPyModule *CPyModule_eth_portfolio____utils;
CPyModule *CPyModule_eth_portfolio___typing;
CPyModule *CPyModule_eth_portfolio____loaders___utils_internal = NULL;
CPyModule *CPyModule_eth_portfolio____loaders___utils;
PyObject *CPyStatic_utils___globals;
CPyModule *CPyModule_eth_retry;
CPyModule *CPyModule_msgspec;
CPyModule *CPyModule_async_lru;
CPyModule *CPyModule_eth_portfolio____argspec_internal = NULL;
CPyModule *CPyModule_eth_portfolio____argspec;
PyObject *CPyStatic__argspec___globals;
CPyModule *CPyModule_inspect;
CPyModule *CPyModule_eth_portfolio____config_internal = NULL;
CPyModule *CPyModule_eth_portfolio____config;
PyObject *CPyStatic__config___globals;
CPyModule *CPyModule_os;
CPyModule *CPyModule_eth_portfolio____shitcoins_internal = NULL;
CPyModule *CPyModule_eth_portfolio____shitcoins;
PyObject *CPyStatic__shitcoins___globals;
CPyModule *CPyModule_eth_portfolio___constants_internal = NULL;
CPyModule *CPyModule_eth_portfolio___constants;
PyObject *CPyStatic_constants___globals;
CPyModule *CPyModule_brownie;
PyObject *CPyStatic__nonce___logger = NULL;
PyObject *CPyStatic__nonce___logger_is_enabled = NULL;
PyObject *CPyStatic__nonce_____log = NULL;
CPyTagged CPyStatic__nonce___DEBUG = CPY_INT_TAG;
PyObject *CPyStatic__nonce___nonces = NULL;
PyObject *CPyStatic__nonce___locks = NULL;
PyObject *CPyStatic__nonce___get_transaction_count = NULL;
PyObject *CPyStatic__nonce___igather = NULL;
PyObject *CPyStatic__nonce___now = NULL;
PyObject *CPyStatic__nonce___BlockCache___lock = NULL;
PyTypeObject *CPyType__nonce___BlockCache;
PyObject *CPyDef__nonce___BlockCache(void);
PyTypeObject *CPyType__nonce_____mypyc_lambda__0_obj;
PyObject *CPyDef__nonce_____mypyc_lambda__0_obj(void);
PyTypeObject *CPyType__nonce___get_nonce_at_block_env;
PyObject *CPyDef__nonce___get_nonce_at_block_env(void);
PyTypeObject *CPyType__nonce___get_nonce_at_block_gen;
PyObject *CPyDef__nonce___get_nonce_at_block_gen(void);
PyTypeObject *CPyType__nonce___get_block_for_nonce_env;
PyObject *CPyDef__nonce___get_block_for_nonce_env(void);
PyTypeObject *CPyType__nonce___get_block_for_nonce_gen;
PyObject *CPyDef__nonce___get_block_for_nonce_gen(void);
PyTypeObject *CPyType__nonce____get_area_env;
PyObject *CPyDef__nonce____get_area_env(void);
PyTypeObject *CPyType__nonce____get_area_gen;
PyObject *CPyDef__nonce____get_area_gen(void);
PyTypeObject *CPyType__nonce___get_block_number_env;
PyObject *CPyDef__nonce___get_block_number_env(void);
PyTypeObject *CPyType__nonce___get_block_number_gen;
PyObject *CPyDef__nonce___get_block_number_gen(void);
PyObject *CPyDef__nonce_____mypyc_lambda__0_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy__nonce_____mypyc_lambda__0_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce_____mypyc_lambda__0_obj_____call__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce_____mypyc_lambda__0_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_nonce_at_block_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_nonce_at_block_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_nonce_at_block_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy__nonce___get_nonce_at_block_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_nonce_at_block_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_nonce_at_block_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_nonce_at_block_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy__nonce___get_nonce_at_block_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_nonce_at_block_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_nonce_at_block_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_nonce_at_block_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_nonce_at_block_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_nonce_at_block(PyObject *cpy_r_address, PyObject *cpy_r_block);
PyObject *CPyPy__nonce___get_nonce_at_block(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_for_nonce_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_block_for_nonce_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_for_nonce_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy__nonce___get_block_for_nonce_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_for_nonce_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_block_for_nonce_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_for_nonce_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy__nonce___get_block_for_nonce_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_for_nonce_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_block_for_nonce_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_for_nonce_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_block_for_nonce_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_for_nonce(PyObject *cpy_r_address, CPyTagged cpy_r_nonce);
PyObject *CPyPy__nonce___get_block_for_nonce(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce____get_area_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy__nonce____get_area_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce____get_area_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce____get_area_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce____get_area_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy__nonce____get_area_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce____get_area_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce____get_area_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce____get_area_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy__nonce____get_area_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce____get_area_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce____get_area_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce____get_area_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce____get_area_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce____get_area(PyObject *cpy_r_address, CPyTagged cpy_r_nonce, PyObject *cpy_r_lo, PyObject *cpy_r_hi, CPyTagged cpy_r_range_size);
PyObject *CPyPy__nonce____get_area(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce____update_nonces(PyObject *cpy_r_address, CPyTagged cpy_r_nonce, PyObject *cpy_r_block);
PyObject *CPyPy__nonce____update_nonces(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef__nonce____get_num_chunks(CPyTagged cpy_r_range_size);
PyObject *CPyPy__nonce____get_num_chunks(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__nonce___BlockCache_____mypyc_defaults_setup(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___BlockCache_____mypyc_defaults_setup(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_number_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy__nonce___get_block_number_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_number_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_block_number_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_number_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy__nonce___get_block_number_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_number_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_block_number_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_number_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy__nonce___get_block_number_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_number_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_block_number_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_number_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy__nonce___get_block_number_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__nonce___get_block_number(void);
PyObject *CPyPy__nonce___get_block_number(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__nonce_____top_level__(void);
PyObject *CPyStatic_balances____ZERO = NULL;
PyObject *CPyStatic_balances___logger = NULL;
PyObject *CPyStatic_balances___log_warning = NULL;
PyTypeObject *CPyType_balances___load_token_balance_env;
PyObject *CPyDef_balances___load_token_balance_env(void);
PyTypeObject *CPyType_balances___load_token_balance_gen;
PyObject *CPyDef_balances___load_token_balance_gen(void);
PyObject *CPyDef_balances___load_token_balance_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy_balances___load_token_balance_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_balances___load_token_balance_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_balances___load_token_balance_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_balances___load_token_balance_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_balances___load_token_balance_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_balances___load_token_balance_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_balances___load_token_balance_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_balances___load_token_balance_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_balances___load_token_balance_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_balances___load_token_balance_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_balances___load_token_balance_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_balances___load_token_balance_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_balances___load_token_balance_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_balances___load_token_balance(PyObject *cpy_r_token, PyObject *cpy_r_address, PyObject *cpy_r_block);
PyObject *CPyPy_balances___load_token_balance(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_balances_____top_level__(void);
PyObject *CPyStatic_utils___Raw = NULL;
PyObject *CPyStatic_utils___get_transaction_receipt = NULL;
PyObject *CPyStatic_utils_____get_transaction_receipt = NULL;
PyTypeObject *CPyType_utils____get_transaction_receipt_env;
PyObject *CPyDef_utils____get_transaction_receipt_env(void);
PyTypeObject *CPyType_utils____get_transaction_receipt_gen;
PyObject *CPyDef_utils____get_transaction_receipt_gen(void);
PyObject *CPyDef_utils____get_transaction_receipt_gen_____mypyc_generator_helper__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
PyObject *CPyPy_utils____get_transaction_receipt_gen_____mypyc_generator_helper__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_utils____get_transaction_receipt_gen_____next__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_utils____get_transaction_receipt_gen_____next__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_utils____get_transaction_receipt_gen___send(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
PyObject *CPyPy_utils____get_transaction_receipt_gen___send(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_utils____get_transaction_receipt_gen_____iter__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_utils____get_transaction_receipt_gen_____iter__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_utils____get_transaction_receipt_gen___throw(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
PyObject *CPyPy_utils____get_transaction_receipt_gen___throw(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_utils____get_transaction_receipt_gen___close(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_utils____get_transaction_receipt_gen___close(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_utils____get_transaction_receipt_gen_____await__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_utils____get_transaction_receipt_gen_____await__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_utils____get_transaction_receipt(PyObject *cpy_r_txhash);
PyObject *CPyPy_utils____get_transaction_receipt(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_utils_____top_level__(void);
PyObject *CPyDef__argspec___get_args_type(PyObject *cpy_r_sample);
PyObject *CPyPy__argspec___get_args_type(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__argspec___get_kwargs_type(PyObject *cpy_r_sample);
PyObject *CPyPy__argspec___get_kwargs_type(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__argspec___get_return_type(PyObject *cpy_r_sample);
PyObject *CPyPy__argspec___get_return_type(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
tuple_T3OOO CPyDef__argspec___get_types(PyObject *cpy_r_sample);
PyObject *CPyPy__argspec___get_types(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__argspec_____top_level__(void);
CPyTagged CPyStatic__config___REORG_BUFFER = CPY_INT_TAG;
char CPyDef__config_____top_level__(void);
PyObject *CPyStatic__shitcoins___shitcoins = NULL;
char CPyDef__shitcoins_____top_level__(void);
CPyTagged CPyStatic_constants___NUM_WALLETS = CPY_INT_TAG;
PyObject *CPyStatic_constants___ADDRESSES = NULL;
PyObject *CPyStatic_constants___TRANSFER_SIGS = NULL;
PyObject *CPyStatic_constants___ETH_LIKE = NULL;
PyObject *CPyStatic_constants___BTC_LIKE = NULL;
PyObject *CPyStatic_constants___INTL_STABLECOINS = NULL;
char CPyDef_constants_____top_level__(void);

static struct export_table_5e40436d3861d2c108dc exports = {
    &CPyStatic__nonce___logger,
    &CPyStatic__nonce___logger_is_enabled,
    &CPyStatic__nonce_____log,
    &CPyStatic__nonce___DEBUG,
    &CPyStatic__nonce___nonces,
    &CPyStatic__nonce___locks,
    &CPyStatic__nonce___get_transaction_count,
    &CPyStatic__nonce___igather,
    &CPyStatic__nonce___now,
    &CPyStatic__nonce___BlockCache___lock,
    &CPyType__nonce___BlockCache,
    &CPyDef__nonce___BlockCache,
    &CPyType__nonce_____mypyc_lambda__0_obj,
    &CPyDef__nonce_____mypyc_lambda__0_obj,
    &CPyType__nonce___get_nonce_at_block_env,
    &CPyDef__nonce___get_nonce_at_block_env,
    &CPyType__nonce___get_nonce_at_block_gen,
    &CPyDef__nonce___get_nonce_at_block_gen,
    &CPyType__nonce___get_block_for_nonce_env,
    &CPyDef__nonce___get_block_for_nonce_env,
    &CPyType__nonce___get_block_for_nonce_gen,
    &CPyDef__nonce___get_block_for_nonce_gen,
    &CPyType__nonce____get_area_env,
    &CPyDef__nonce____get_area_env,
    &CPyType__nonce____get_area_gen,
    &CPyDef__nonce____get_area_gen,
    &CPyType__nonce___get_block_number_env,
    &CPyDef__nonce___get_block_number_env,
    &CPyType__nonce___get_block_number_gen,
    &CPyDef__nonce___get_block_number_gen,
    &CPyDef__nonce_____mypyc_lambda__0_obj_____get__,
    &CPyDef__nonce_____mypyc_lambda__0_obj_____call__,
    &CPyDef__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__,
    &CPyDef__nonce___get_nonce_at_block_gen_____next__,
    &CPyDef__nonce___get_nonce_at_block_gen___send,
    &CPyDef__nonce___get_nonce_at_block_gen_____iter__,
    &CPyDef__nonce___get_nonce_at_block_gen___throw,
    &CPyDef__nonce___get_nonce_at_block_gen___close,
    &CPyDef__nonce___get_nonce_at_block_gen_____await__,
    &CPyDef__nonce___get_nonce_at_block,
    &CPyDef__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__,
    &CPyDef__nonce___get_block_for_nonce_gen_____next__,
    &CPyDef__nonce___get_block_for_nonce_gen___send,
    &CPyDef__nonce___get_block_for_nonce_gen_____iter__,
    &CPyDef__nonce___get_block_for_nonce_gen___throw,
    &CPyDef__nonce___get_block_for_nonce_gen___close,
    &CPyDef__nonce___get_block_for_nonce_gen_____await__,
    &CPyDef__nonce___get_block_for_nonce,
    &CPyDef__nonce____get_area_gen_____mypyc_generator_helper__,
    &CPyDef__nonce____get_area_gen_____next__,
    &CPyDef__nonce____get_area_gen___send,
    &CPyDef__nonce____get_area_gen_____iter__,
    &CPyDef__nonce____get_area_gen___throw,
    &CPyDef__nonce____get_area_gen___close,
    &CPyDef__nonce____get_area_gen_____await__,
    &CPyDef__nonce____get_area,
    &CPyDef__nonce____update_nonces,
    &CPyDef__nonce____get_num_chunks,
    &CPyDef__nonce___BlockCache_____mypyc_defaults_setup,
    &CPyDef__nonce___get_block_number_gen_____mypyc_generator_helper__,
    &CPyDef__nonce___get_block_number_gen_____next__,
    &CPyDef__nonce___get_block_number_gen___send,
    &CPyDef__nonce___get_block_number_gen_____iter__,
    &CPyDef__nonce___get_block_number_gen___throw,
    &CPyDef__nonce___get_block_number_gen___close,
    &CPyDef__nonce___get_block_number_gen_____await__,
    &CPyDef__nonce___get_block_number,
    &CPyDef__nonce_____top_level__,
    &CPyStatic_balances____ZERO,
    &CPyStatic_balances___logger,
    &CPyStatic_balances___log_warning,
    &CPyType_balances___load_token_balance_env,
    &CPyDef_balances___load_token_balance_env,
    &CPyType_balances___load_token_balance_gen,
    &CPyDef_balances___load_token_balance_gen,
    &CPyDef_balances___load_token_balance_gen_____mypyc_generator_helper__,
    &CPyDef_balances___load_token_balance_gen_____next__,
    &CPyDef_balances___load_token_balance_gen___send,
    &CPyDef_balances___load_token_balance_gen_____iter__,
    &CPyDef_balances___load_token_balance_gen___throw,
    &CPyDef_balances___load_token_balance_gen___close,
    &CPyDef_balances___load_token_balance_gen_____await__,
    &CPyDef_balances___load_token_balance,
    &CPyDef_balances_____top_level__,
    &CPyStatic_utils___Raw,
    &CPyStatic_utils___get_transaction_receipt,
    &CPyStatic_utils_____get_transaction_receipt,
    &CPyType_utils____get_transaction_receipt_env,
    &CPyDef_utils____get_transaction_receipt_env,
    &CPyType_utils____get_transaction_receipt_gen,
    &CPyDef_utils____get_transaction_receipt_gen,
    &CPyDef_utils____get_transaction_receipt_gen_____mypyc_generator_helper__,
    &CPyDef_utils____get_transaction_receipt_gen_____next__,
    &CPyDef_utils____get_transaction_receipt_gen___send,
    &CPyDef_utils____get_transaction_receipt_gen_____iter__,
    &CPyDef_utils____get_transaction_receipt_gen___throw,
    &CPyDef_utils____get_transaction_receipt_gen___close,
    &CPyDef_utils____get_transaction_receipt_gen_____await__,
    &CPyDef_utils____get_transaction_receipt,
    &CPyDef_utils_____top_level__,
    &CPyDef__argspec___get_args_type,
    &CPyDef__argspec___get_kwargs_type,
    &CPyDef__argspec___get_return_type,
    &CPyDef__argspec___get_types,
    &CPyDef__argspec_____top_level__,
    &CPyStatic__config___REORG_BUFFER,
    &CPyDef__config_____top_level__,
    &CPyStatic__shitcoins___shitcoins,
    &CPyDef__shitcoins_____top_level__,
    &CPyStatic_constants___NUM_WALLETS,
    &CPyStatic_constants___ADDRESSES,
    &CPyStatic_constants___TRANSFER_SIGS,
    &CPyStatic_constants___ETH_LIKE,
    &CPyStatic_constants___BTC_LIKE,
    &CPyStatic_constants___INTL_STABLECOINS,
    &CPyDef_constants_____top_level__,
};

PyMODINIT_FUNC PyInit_5e40436d3861d2c108dc__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "5e40436d3861d2c108dc__mypyc", NULL, -1, NULL, NULL };
    int res;
    PyObject *capsule;
    PyObject *tmp;
    static PyObject *module;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&def);
    if (!module) {
        goto fail;
    }
    
    capsule = PyCapsule_New(&exports, "5e40436d3861d2c108dc__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_eth_portfolio____loaders____nonce(void);
    capsule = PyCapsule_New((void *)CPyInit_eth_portfolio____loaders____nonce, "5e40436d3861d2c108dc__mypyc.init_eth_portfolio____loaders____nonce", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_eth_portfolio____loaders____nonce", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_eth_portfolio____loaders___balances(void);
    capsule = PyCapsule_New((void *)CPyInit_eth_portfolio____loaders___balances, "5e40436d3861d2c108dc__mypyc.init_eth_portfolio____loaders___balances", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_eth_portfolio____loaders___balances", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_eth_portfolio____loaders___utils(void);
    capsule = PyCapsule_New((void *)CPyInit_eth_portfolio____loaders___utils, "5e40436d3861d2c108dc__mypyc.init_eth_portfolio____loaders___utils", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_eth_portfolio____loaders___utils", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_eth_portfolio____argspec(void);
    capsule = PyCapsule_New((void *)CPyInit_eth_portfolio____argspec, "5e40436d3861d2c108dc__mypyc.init_eth_portfolio____argspec", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_eth_portfolio____argspec", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_eth_portfolio____config(void);
    capsule = PyCapsule_New((void *)CPyInit_eth_portfolio____config, "5e40436d3861d2c108dc__mypyc.init_eth_portfolio____config", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_eth_portfolio____config", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_eth_portfolio____shitcoins(void);
    capsule = PyCapsule_New((void *)CPyInit_eth_portfolio____shitcoins, "5e40436d3861d2c108dc__mypyc.init_eth_portfolio____shitcoins", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_eth_portfolio____shitcoins", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_eth_portfolio___constants(void);
    capsule = PyCapsule_New((void *)CPyInit_eth_portfolio___constants, "5e40436d3861d2c108dc__mypyc.init_eth_portfolio___constants", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_eth_portfolio___constants", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
