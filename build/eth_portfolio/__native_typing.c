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
#include "__native_typing.h"
#include "__native_internal_typing.h"

static PyObject *CPyDunder___add__Balance(PyObject *obj_left, PyObject *obj_right) {
    if (PyObject_IsInstance(obj_left, (PyObject *)CPyType_Balance)) {
        PyObject *arg_left;
        if (likely(Py_TYPE(obj_left) == CPyType_Balance))
            arg_left = obj_left;
        else {
            goto typefail;
        }
        PyObject *arg_right;
        if (likely(Py_TYPE(obj_right) == CPyType_Balance))
            arg_right = obj_right;
        else {
            goto typefail;
        }
        return CPyDef_Balance_____add__(arg_left, arg_right);
    }
typefail: ;
    if (PyObject_IsInstance(obj_right, (PyObject *)CPyType_Balance)) {
        PyObject *arg_right;
        if (likely(Py_TYPE(obj_right) == CPyType_Balance))
            arg_right = obj_right;
        else {
            goto typefail2;
        }
        PyObject *arg_left;
        if (Py_TYPE(obj_left) == CPyType_Balance)
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL1;
        if (PyLong_Check(obj_left))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL1;
        goto typefail2;
__LL1: ;
        return CPyDef_Balance_____radd__(arg_right, arg_left);
    } else {
        _Py_IDENTIFIER(__radd__);
        return CPy_CallReverseOpMethod(obj_left, obj_right, "+", &PyId___radd__);
    }
typefail2: ;
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}
static int CPyDunder___bool__Balance(PyObject *self) {
    char val = CPyDef_Balance_____bool__(self);
    if (val == 2) {
        return -1;
    }
    return val;
}
static PyObject *CPyDunder___sub__Balance(PyObject *obj_left, PyObject *obj_right) {
    PyObject *arg_left;
    if (likely(Py_TYPE(obj_left) == CPyType_Balance))
        arg_left = obj_left;
    else {
        goto typefail;
    }
    PyObject *arg_right;
    if (likely(Py_TYPE(obj_right) == CPyType_Balance))
        arg_right = obj_right;
    else {
        goto typefail;
    }
    return CPyDef_Balance_____sub__(arg_left, arg_right);
typefail: ;
    _Py_IDENTIFIER(__rsub__);
    return CPy_CallReverseOpMethod(obj_left, obj_right, "-", &PyId___rsub__);
}
static PyNumberMethods Balance_as_number = {
    .nb_add = CPyDunder___add__Balance,
    .nb_bool = CPyDunder___bool__Balance,
    .nb_subtract = CPyDunder___sub__Balance,
};
static PyObject *Balance_setup(PyTypeObject *type);
PyObject *CPyDef_Balance(void);

static PyObject *
Balance_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_Balance) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return Balance_setup(type);
}

static int
Balance_traverse(eth_portfolio___typing___BalanceObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_balance);
    Py_VISIT(self->_usd_value);
    Py_VISIT(self->_token);
    Py_VISIT(self->_block);
    return 0;
}

static int
Balance_clear(eth_portfolio___typing___BalanceObject *self)
{
    Py_CLEAR(self->_balance);
    Py_CLEAR(self->_usd_value);
    Py_CLEAR(self->_token);
    Py_CLEAR(self->_block);
    return 0;
}

static void
Balance_dealloc(eth_portfolio___typing___BalanceObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, Balance_dealloc)
    Balance_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem Balance_vtable[6];
static bool
CPyDef_Balance_trait_vtable_setup(void)
{
    CPyVTableItem Balance_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_Balance___usd,
        (CPyVTableItem)CPyDef_Balance_____add__,
        (CPyVTableItem)CPyDef_Balance_____radd__,
        (CPyVTableItem)CPyDef_Balance_____sub__,
        (CPyVTableItem)CPyDef_Balance_____bool__,
        (CPyVTableItem)CPyDef_Balance_____mypyc_defaults_setup,
    };
    memcpy(Balance_vtable, Balance_vtable_scratch, sizeof(Balance_vtable));
    return 1;
}

static PyObject *
Balance_get_balance(eth_portfolio___typing___BalanceObject *self, void *closure);
static int
Balance_set_balance(eth_portfolio___typing___BalanceObject *self, PyObject *value, void *closure);
static PyObject *
Balance_get_usd_value(eth_portfolio___typing___BalanceObject *self, void *closure);
static int
Balance_set_usd_value(eth_portfolio___typing___BalanceObject *self, PyObject *value, void *closure);
static PyObject *
Balance_get_token(eth_portfolio___typing___BalanceObject *self, void *closure);
static int
Balance_set_token(eth_portfolio___typing___BalanceObject *self, PyObject *value, void *closure);
static PyObject *
Balance_get_block(eth_portfolio___typing___BalanceObject *self, void *closure);
static int
Balance_set_block(eth_portfolio___typing___BalanceObject *self, PyObject *value, void *closure);
static PyObject *
Balance_get_usd(eth_portfolio___typing___BalanceObject *self, void *closure);

static PyGetSetDef Balance_getseters[] = {
    {"balance",
     (getter)Balance_get_balance, (setter)Balance_set_balance,
     NULL, NULL},
    {"usd_value",
     (getter)Balance_get_usd_value, (setter)Balance_set_usd_value,
     NULL, NULL},
    {"token",
     (getter)Balance_get_token, (setter)Balance_set_token,
     NULL, NULL},
    {"block",
     (getter)Balance_get_block, (setter)Balance_set_block,
     NULL, NULL},
    {"usd",
     (getter)Balance_get_usd,
    NULL, NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef Balance_methods[] = {
    {"__add__",
     (PyCFunction)CPyPy_Balance_____add__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__radd__",
     (PyCFunction)CPyPy_Balance_____radd__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__sub__",
     (PyCFunction)CPyPy_Balance_____sub__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__bool__",
     (PyCFunction)CPyPy_Balance_____bool__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__mypyc_defaults_setup",
     (PyCFunction)CPyPy_Balance_____mypyc_defaults_setup,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_Balance_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Balance",
    .tp_new = Balance_new,
    .tp_dealloc = (destructor)Balance_dealloc,
    .tp_traverse = (traverseproc)Balance_traverse,
    .tp_clear = (inquiry)Balance_clear,
    .tp_getset = Balance_getseters,
    .tp_methods = Balance_methods,
    .tp_as_number = &Balance_as_number,
    .tp_basicsize = sizeof(eth_portfolio___typing___BalanceObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_Balance_template = &CPyType_Balance_template_;

static PyObject *
Balance_setup(PyTypeObject *type)
{
    eth_portfolio___typing___BalanceObject *self;
    self = (eth_portfolio___typing___BalanceObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = Balance_vtable;
    if (CPyDef_Balance_____mypyc_defaults_setup((PyObject *)self) == 0) {
        Py_DECREF(self);
        return NULL;
    }
    return (PyObject *)self;
}

PyObject *CPyDef_Balance(void)
{
    PyObject *self = Balance_setup(CPyType_Balance);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
Balance_get_balance(eth_portfolio___typing___BalanceObject *self, void *closure)
{
    if (unlikely(self->_balance == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'balance' of 'Balance' undefined");
        return NULL;
    }
    CPy_INCREF(self->_balance);
    PyObject *retval = self->_balance;
    return retval;
}

static int
Balance_set_balance(eth_portfolio___typing___BalanceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Balance' object attribute 'balance' cannot be deleted");
        return -1;
    }
    if (self->_balance != NULL) {
        CPy_DECREF(self->_balance);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_balance = tmp;
    return 0;
}

static PyObject *
Balance_get_usd_value(eth_portfolio___typing___BalanceObject *self, void *closure)
{
    if (unlikely(self->_usd_value == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'usd_value' of 'Balance' undefined");
        return NULL;
    }
    CPy_INCREF(self->_usd_value);
    PyObject *retval = self->_usd_value;
    return retval;
}

static int
Balance_set_usd_value(eth_portfolio___typing___BalanceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Balance' object attribute 'usd_value' cannot be deleted");
        return -1;
    }
    if (self->_usd_value != NULL) {
        CPy_DECREF(self->_usd_value);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_usd_value = tmp;
    return 0;
}

static PyObject *
Balance_get_token(eth_portfolio___typing___BalanceObject *self, void *closure)
{
    if (unlikely(self->_token == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'token' of 'Balance' undefined");
        return NULL;
    }
    CPy_INCREF(self->_token);
    PyObject *retval = self->_token;
    return retval;
}

static int
Balance_set_token(eth_portfolio___typing___BalanceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Balance' object attribute 'token' cannot be deleted");
        return -1;
    }
    if (self->_token != NULL) {
        CPy_DECREF(self->_token);
    }
    PyObject *tmp;
    tmp = value;
    if (tmp != NULL) goto __LL2;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL2;
    CPy_TypeError("object or None", value); 
    tmp = NULL;
__LL2: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_token = tmp;
    return 0;
}

static PyObject *
Balance_get_block(eth_portfolio___typing___BalanceObject *self, void *closure)
{
    if (unlikely(self->_block == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'block' of 'Balance' undefined");
        return NULL;
    }
    CPy_INCREF(self->_block);
    PyObject *retval = self->_block;
    return retval;
}

static int
Balance_set_block(eth_portfolio___typing___BalanceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Balance' object attribute 'block' cannot be deleted");
        return -1;
    }
    if (self->_block != NULL) {
        CPy_DECREF(self->_block);
    }
    PyObject *tmp;
    tmp = value;
    if (tmp != NULL) goto __LL3;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL3;
    CPy_TypeError("object or None", value); 
    tmp = NULL;
__LL3: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_block = tmp;
    return 0;
}

static PyObject *
Balance_get_usd(eth_portfolio___typing___BalanceObject *self, void *closure)
{
    return CPyDef_Balance___usd((PyObject *) self);
}

static PyObject *CPyDunder___add___SummableNonNumericMixin(PyObject *obj_left, PyObject *obj_right) {
    if (PyObject_IsInstance(obj_left, (PyObject *)CPyType__SummableNonNumericMixin)) {
        PyObject *arg_left;
        if (likely(PyObject_TypeCheck(obj_left, CPyType__SummableNonNumericMixin)))
            arg_left = obj_left;
        else {
            goto typefail;
        }
        PyObject *arg_right;
        if (likely(PyObject_TypeCheck(obj_right, CPyType__SummableNonNumericMixin)))
            arg_right = obj_right;
        else {
            goto typefail;
        }
        return CPyDef__SummableNonNumericMixin_____add__(arg_left, arg_right);
    }
typefail: ;
    if (PyObject_IsInstance(obj_right, (PyObject *)CPyType__SummableNonNumericMixin)) {
        PyObject *arg_right;
        if (likely(PyObject_TypeCheck(obj_right, CPyType__SummableNonNumericMixin)))
            arg_right = obj_right;
        else {
            goto typefail2;
        }
        PyObject *arg_left;
        if (PyObject_TypeCheck(obj_left, CPyType__SummableNonNumericMixin))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL4;
        if (PyLong_Check(obj_left))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL4;
        goto typefail2;
__LL4: ;
        return CPyDef__SummableNonNumericMixin_____radd__(arg_right, arg_left);
    } else {
        _Py_IDENTIFIER(__radd__);
        return CPy_CallReverseOpMethod(obj_left, obj_right, "+", &PyId___radd__);
    }
typefail2: ;
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}
static PyNumberMethods _SummableNonNumericMixin_as_number = {
    .nb_add = CPyDunder___add___SummableNonNumericMixin,
};
static PyObject *_SummableNonNumericMixin_setup(PyTypeObject *type);
PyObject *CPyDef__SummableNonNumericMixin(void);

static PyObject *
_SummableNonNumericMixin_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__SummableNonNumericMixin) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return _SummableNonNumericMixin_setup(type);
}

static int
_SummableNonNumericMixin_traverse(eth_portfolio___typing____SummableNonNumericMixinObject *self, visitproc visit, void *arg)
{
    return 0;
}

static int
_SummableNonNumericMixin_clear(eth_portfolio___typing____SummableNonNumericMixinObject *self)
{
    return 0;
}

static void
_SummableNonNumericMixin_dealloc(eth_portfolio___typing____SummableNonNumericMixinObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _SummableNonNumericMixin_dealloc)
    _SummableNonNumericMixin_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _SummableNonNumericMixin_vtable[2];
static bool
CPyDef__SummableNonNumericMixin_trait_vtable_setup(void)
{
    CPyVTableItem _SummableNonNumericMixin_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__SummableNonNumericMixin_____add__,
        (CPyVTableItem)CPyDef__SummableNonNumericMixin_____radd__,
    };
    memcpy(_SummableNonNumericMixin_vtable, _SummableNonNumericMixin_vtable_scratch, sizeof(_SummableNonNumericMixin_vtable));
    return 1;
}


static PyGetSetDef _SummableNonNumericMixin_getseters[] = {
    {NULL}  /* Sentinel */
};

static PyMethodDef _SummableNonNumericMixin_methods[] = {
    {"__add__",
     (PyCFunction)CPyPy__SummableNonNumericMixin_____add__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__radd__",
     (PyCFunction)CPyPy__SummableNonNumericMixin_____radd__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__SummableNonNumericMixin_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_SummableNonNumericMixin",
    .tp_new = _SummableNonNumericMixin_new,
    .tp_dealloc = (destructor)_SummableNonNumericMixin_dealloc,
    .tp_traverse = (traverseproc)_SummableNonNumericMixin_traverse,
    .tp_clear = (inquiry)_SummableNonNumericMixin_clear,
    .tp_getset = _SummableNonNumericMixin_getseters,
    .tp_methods = _SummableNonNumericMixin_methods,
    .tp_as_number = &_SummableNonNumericMixin_as_number,
    .tp_basicsize = sizeof(eth_portfolio___typing____SummableNonNumericMixinObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType__SummableNonNumericMixin_template = &CPyType__SummableNonNumericMixin_template_;

static PyObject *
_SummableNonNumericMixin_setup(PyTypeObject *type)
{
    eth_portfolio___typing____SummableNonNumericMixinObject *self;
    self = (eth_portfolio___typing____SummableNonNumericMixinObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _SummableNonNumericMixin_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef__SummableNonNumericMixin(void)
{
    PyObject *self = _SummableNonNumericMixin_setup(CPyType__SummableNonNumericMixin);
    if (self == NULL)
        return NULL;
    return self;
}


static int
TokenBalances_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *CPyDunder___getitem__TokenBalances(PyObject *obj_self, PyObject *obj_key) {
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        return NULL;
    }
    PyObject *arg_key = obj_key;
    return CPyDef_TokenBalances_____getitem__(arg_self, arg_key);
}
static int CPyDunder___setitem__TokenBalances(PyObject *obj_self, PyObject *obj_key, PyObject *obj_value) {
    if (obj_value == NULL) {
        PyObject *super = CPy_Super(CPyModule_builtins, obj_self);
        if (super == NULL) return -1;
        PyObject *result = PyObject_CallMethod(super, "__delitem__", "O", obj_key);
        Py_DECREF(super);
        Py_XDECREF(result);
        return result == NULL ? -1 : 0;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    PyObject *arg_value;
    if (likely(Py_TYPE(obj_value) == CPyType_Balance))
        arg_value = obj_value;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj_value); 
        goto fail;
    }
    char val = CPyDef_TokenBalances_____setitem__(arg_self, arg_key, arg_value);
    if (val == 2) {
        goto fail;
    }
    return 0;
fail: ;
    return -1;
}
static PyMappingMethods TokenBalances_as_mapping = {
    .mp_subscript = CPyDunder___getitem__TokenBalances,
    .mp_ass_subscript = CPyDunder___setitem__TokenBalances,
};
static PyObject *CPyDunder___add__TokenBalances(PyObject *obj_left, PyObject *obj_right) {
    if (PyObject_IsInstance(obj_left, (PyObject *)CPyType_TokenBalances)) {
        PyObject *arg_left;
        if (likely(Py_TYPE(obj_left) == CPyType_TokenBalances))
            arg_left = obj_left;
        else {
            goto typefail;
        }
        PyObject *arg_right;
        if (likely(Py_TYPE(obj_right) == CPyType_TokenBalances))
            arg_right = obj_right;
        else {
            goto typefail;
        }
        return CPyDef_TokenBalances_____add__(arg_left, arg_right);
    }
typefail: ;
    if (PyObject_IsInstance(obj_right, (PyObject *)CPyType_TokenBalances)) {
        PyObject *arg_right;
        if (likely(PyObject_TypeCheck(obj_right, CPyType__SummableNonNumericMixin)))
            arg_right = obj_right;
        else {
            goto typefail2;
        }
        PyObject *arg_left;
        if (PyObject_TypeCheck(obj_left, CPyType__SummableNonNumericMixin))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL5;
        if (PyLong_Check(obj_left))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL5;
        goto typefail2;
__LL5: ;
        return CPyDef__SummableNonNumericMixin_____radd__(arg_right, arg_left);
    } else {
        _Py_IDENTIFIER(__radd__);
        return CPy_CallReverseOpMethod(obj_left, obj_right, "+", &PyId___radd__);
    }
typefail2: ;
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}
static int CPyDunder___bool__TokenBalances(PyObject *self) {
    char val = CPyDef_TokenBalances_____bool__(self);
    if (val == 2) {
        return -1;
    }
    return val;
}
static PyObject *CPyDunder___sub__TokenBalances(PyObject *obj_left, PyObject *obj_right) {
    PyObject *arg_left;
    if (likely(Py_TYPE(obj_left) == CPyType_TokenBalances))
        arg_left = obj_left;
    else {
        goto typefail;
    }
    PyObject *arg_right;
    if (likely(Py_TYPE(obj_right) == CPyType_TokenBalances))
        arg_right = obj_right;
    else {
        goto typefail;
    }
    return CPyDef_TokenBalances_____sub__(arg_left, arg_right);
typefail: ;
    _Py_IDENTIFIER(__rsub__);
    return CPy_CallReverseOpMethod(obj_left, obj_right, "-", &PyId___rsub__);
}
static PyNumberMethods TokenBalances_as_number = {
    .nb_add = CPyDunder___add__TokenBalances,
    .nb_bool = CPyDunder___bool__TokenBalances,
    .nb_subtract = CPyDunder___sub__TokenBalances,
};
static PyObject *TokenBalances_setup(PyTypeObject *type);
PyObject *CPyDef_TokenBalances(PyObject *cpy_r_seed, PyObject *cpy_r_block);

static PyObject *
TokenBalances_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_TokenBalances) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = TokenBalances_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_TokenBalances_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
TokenBalances_traverse(eth_portfolio___typing___TokenBalancesObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_block);
    return 0;
}

static int
TokenBalances_clear(eth_portfolio___typing___TokenBalancesObject *self)
{
    Py_CLEAR(self->_block);
    return 0;
}

static void
TokenBalances_dealloc(eth_portfolio___typing___TokenBalancesObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, TokenBalances_dealloc)
    TokenBalances_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem TokenBalances_vtable[11];
static bool
CPyDef_TokenBalances_trait_vtable_setup(void)
{
    CPyVTableItem TokenBalances_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_TokenBalances_____add___3___SummableNonNumericMixin_glue,
        (CPyVTableItem)CPyDef__SummableNonNumericMixin_____radd__,
        (CPyVTableItem)CPyDef_TokenBalances_____init__,
        (CPyVTableItem)CPyDef_TokenBalances_____getitem__,
        (CPyVTableItem)CPyDef_TokenBalances_____setitem__,
        (CPyVTableItem)CPyDef_TokenBalances___dataframe,
        (CPyVTableItem)CPyDef_TokenBalances___sum_usd,
        (CPyVTableItem)CPyDef_TokenBalances_____bool__,
        (CPyVTableItem)CPyDef_TokenBalances_____repr__,
        (CPyVTableItem)CPyDef_TokenBalances_____add__,
        (CPyVTableItem)CPyDef_TokenBalances_____sub__,
    };
    memcpy(TokenBalances_vtable, TokenBalances_vtable_scratch, sizeof(TokenBalances_vtable));
    return 1;
}

static PyObject *
TokenBalances_get_block(eth_portfolio___typing___TokenBalancesObject *self, void *closure);
static int
TokenBalances_set_block(eth_portfolio___typing___TokenBalancesObject *self, PyObject *value, void *closure);
static PyObject *
TokenBalances_get_dataframe(eth_portfolio___typing___TokenBalancesObject *self, void *closure);

static PyGetSetDef TokenBalances_getseters[] = {
    {"block",
     (getter)TokenBalances_get_block, (setter)TokenBalances_set_block,
     NULL, NULL},
    {"dataframe",
     (getter)TokenBalances_get_dataframe,
    NULL, NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef TokenBalances_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_TokenBalances_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__getitem__",
     (PyCFunction)CPyPy_TokenBalances_____getitem__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setitem__",
     (PyCFunction)CPyPy_TokenBalances_____setitem__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"sum_usd",
     (PyCFunction)CPyPy_TokenBalances___sum_usd,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__bool__",
     (PyCFunction)CPyPy_TokenBalances_____bool__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__repr__",
     (PyCFunction)CPyPy_TokenBalances_____repr__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__add__",
     (PyCFunction)CPyPy_TokenBalances_____add__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__sub__",
     (PyCFunction)CPyPy_TokenBalances_____sub__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_TokenBalances_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "TokenBalances",
    .tp_new = TokenBalances_new,
    .tp_dealloc = (destructor)TokenBalances_dealloc,
    .tp_traverse = (traverseproc)TokenBalances_traverse,
    .tp_clear = (inquiry)TokenBalances_clear,
    .tp_getset = TokenBalances_getseters,
    .tp_methods = TokenBalances_methods,
    .tp_init = TokenBalances_init,
    .tp_repr = CPyDef_TokenBalances_____repr__,
    .tp_as_mapping = &TokenBalances_as_mapping,
    .tp_as_number = &TokenBalances_as_number,
    .tp_basicsize = sizeof(eth_portfolio___typing___TokenBalancesObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_TokenBalances_template = &CPyType_TokenBalances_template_;

static PyObject *
TokenBalances_setup(PyTypeObject *type)
{
    eth_portfolio___typing___TokenBalancesObject *self;
    self = (eth_portfolio___typing___TokenBalancesObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = TokenBalances_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_TokenBalances(PyObject *cpy_r_seed, PyObject *cpy_r_block)
{
    PyObject *self = TokenBalances_setup(CPyType_TokenBalances);
    if (self == NULL)
        return NULL;
    char res = CPyDef_TokenBalances_____init__(self, cpy_r_seed, cpy_r_block);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
TokenBalances_get_block(eth_portfolio___typing___TokenBalancesObject *self, void *closure)
{
    if (unlikely(self->_block == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'block' of 'TokenBalances' undefined");
        return NULL;
    }
    CPy_INCREF(self->_block);
    PyObject *retval = self->_block;
    return retval;
}

static int
TokenBalances_set_block(eth_portfolio___typing___TokenBalancesObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'TokenBalances' object attribute 'block' cannot be deleted");
        return -1;
    }
    if (self->_block != NULL) {
        CPy_DECREF(self->_block);
    }
    PyObject *tmp;
    if (PyLong_Check(value))
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL6;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL6;
    CPy_TypeError("int or None", value); 
    tmp = NULL;
__LL6: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_block = tmp;
    return 0;
}

static PyObject *
TokenBalances_get_dataframe(eth_portfolio___typing___TokenBalancesObject *self, void *closure)
{
    return CPyDef_TokenBalances___dataframe((PyObject *) self);
}

static int
RemoteTokenBalances_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return CPyPy_RemoteTokenBalances_____init__(self, args, kwds) != NULL ? 0 : -1;
}
static int CPyDunder___setitem__RemoteTokenBalances(PyObject *obj_self, PyObject *obj_protocol, PyObject *obj_value) {
    if (obj_value == NULL) {
        PyObject *super = CPy_Super(CPyModule_builtins, obj_self);
        if (super == NULL) return -1;
        PyObject *result = PyObject_CallMethod(super, "__delitem__", "O", obj_protocol);
        Py_DECREF(super);
        Py_XDECREF(result);
        return result == NULL ? -1 : 0;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_protocol;
    if (likely(PyUnicode_Check(obj_protocol)))
        arg_protocol = obj_protocol;
    else {
        CPy_TypeError("str", obj_protocol); 
        goto fail;
    }
    PyObject *arg_value;
    if (likely(Py_TYPE(obj_value) == CPyType_TokenBalances))
        arg_value = obj_value;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_value); 
        goto fail;
    }
    char val = CPyDef_RemoteTokenBalances_____setitem__(arg_self, arg_protocol, arg_value);
    if (val == 2) {
        goto fail;
    }
    return 0;
fail: ;
    return -1;
}
static PyMappingMethods RemoteTokenBalances_as_mapping = {
    .mp_ass_subscript = CPyDunder___setitem__RemoteTokenBalances,
};
static PyObject *CPyDunder___add__RemoteTokenBalances(PyObject *obj_left, PyObject *obj_right) {
    if (PyObject_IsInstance(obj_left, (PyObject *)CPyType_RemoteTokenBalances)) {
        PyObject *arg_left;
        if (likely(PyDict_Check(obj_left)))
            arg_left = obj_left;
        else {
            goto typefail;
        }
        PyObject *arg_right;
        if (likely(PyDict_Check(obj_right)))
            arg_right = obj_right;
        else {
            goto typefail;
        }
        PyObject *retbox = CPyDef_RemoteTokenBalances_____add__(arg_left, arg_right);
        if (retbox == Py_NotImplemented) {
            goto typefail;
        }
        return retbox;
    }
typefail: ;
    if (PyObject_IsInstance(obj_right, (PyObject *)CPyType_RemoteTokenBalances)) {
        PyObject *arg_right;
        if (likely(PyObject_TypeCheck(obj_right, CPyType__SummableNonNumericMixin)))
            arg_right = obj_right;
        else {
            goto typefail2;
        }
        PyObject *arg_left;
        if (PyObject_TypeCheck(obj_left, CPyType__SummableNonNumericMixin))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL7;
        if (PyLong_Check(obj_left))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL7;
        goto typefail2;
__LL7: ;
        return CPyDef__SummableNonNumericMixin_____radd__(arg_right, arg_left);
    } else {
        _Py_IDENTIFIER(__radd__);
        return CPy_CallReverseOpMethod(obj_left, obj_right, "+", &PyId___radd__);
    }
typefail2: ;
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}
static int CPyDunder___bool__RemoteTokenBalances(PyObject *self) {
    char val = CPyDef_RemoteTokenBalances_____bool__(self);
    if (val == 2) {
        return -1;
    }
    return val;
}
static PyObject *CPyDunder___sub__RemoteTokenBalances(PyObject *obj_left, PyObject *obj_right) {
    PyObject *arg_left;
    if (likely(PyDict_Check(obj_left)))
        arg_left = obj_left;
    else {
        goto typefail;
    }
    PyObject *arg_right;
    if (likely(PyDict_Check(obj_right)))
        arg_right = obj_right;
    else {
        goto typefail;
    }
    PyObject *retbox = CPyDef_RemoteTokenBalances_____sub__(arg_left, arg_right);
    if (retbox == Py_NotImplemented) {
        goto typefail;
    }
    return retbox;
typefail: ;
    _Py_IDENTIFIER(__rsub__);
    return CPy_CallReverseOpMethod(obj_left, obj_right, "-", &PyId___rsub__);
}
static PyNumberMethods RemoteTokenBalances_as_number = {
    .nb_add = CPyDunder___add__RemoteTokenBalances,
    .nb_bool = CPyDunder___bool__RemoteTokenBalances,
    .nb_subtract = CPyDunder___sub__RemoteTokenBalances,
};
static PyObject *
RemoteTokenBalances_get_dataframe(eth_portfolio___typing___RemoteTokenBalancesObject *self, void *closure);

static PyGetSetDef RemoteTokenBalances_getseters[] = {
    {"dataframe",
     (getter)RemoteTokenBalances_get_dataframe,
    NULL, NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef RemoteTokenBalances_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_RemoteTokenBalances_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setitem__",
     (PyCFunction)CPyPy_RemoteTokenBalances_____setitem__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"sum_usd",
     (PyCFunction)CPyPy_RemoteTokenBalances___sum_usd,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__bool__",
     (PyCFunction)CPyPy_RemoteTokenBalances_____bool__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__repr__",
     (PyCFunction)CPyPy_RemoteTokenBalances_____repr__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__add__",
     (PyCFunction)CPyPy_RemoteTokenBalances_____add__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__sub__",
     (PyCFunction)CPyPy_RemoteTokenBalances_____sub__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_RemoteTokenBalances_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "RemoteTokenBalances",
    .tp_getset = RemoteTokenBalances_getseters,
    .tp_methods = RemoteTokenBalances_methods,
    .tp_init = RemoteTokenBalances_init,
    .tp_repr = CPyDef_RemoteTokenBalances_____repr__,
    .tp_as_mapping = &RemoteTokenBalances_as_mapping,
    .tp_as_number = &RemoteTokenBalances_as_number,
    .tp_basicsize = sizeof(PyDictObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_RemoteTokenBalances_template = &CPyType_RemoteTokenBalances_template_;


static PyObject *
RemoteTokenBalances_get_dataframe(eth_portfolio___typing___RemoteTokenBalancesObject *self, void *closure)
{
    return CPyDef_RemoteTokenBalances___dataframe((PyObject *) self);
}

static int
WalletBalances_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return CPyPy_WalletBalances_____init__(self, args, kwds) != NULL ? 0 : -1;
}
static PyObject *CPyDunder___getitem__WalletBalances(PyObject *obj_self, PyObject *obj_key) {
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        return NULL;
    }
    PyObject *arg_key;
    if (likely(PyUnicode_Check(obj_key)))
        arg_key = obj_key;
    else {
        CPy_TypeError("str", obj_key); 
        return NULL;
    }
    return CPyDef_WalletBalances_____getitem__(arg_self, arg_key);
}
static int CPyDunder___setitem__WalletBalances(PyObject *obj_self, PyObject *obj_key, PyObject *obj_value) {
    if (obj_value == NULL) {
        PyObject *super = CPy_Super(CPyModule_builtins, obj_self);
        if (super == NULL) return -1;
        PyObject *result = PyObject_CallMethod(super, "__delitem__", "O", obj_key);
        Py_DECREF(super);
        Py_XDECREF(result);
        return result == NULL ? -1 : 0;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_key;
    if (likely(PyUnicode_Check(obj_key)))
        arg_key = obj_key;
    else {
        CPy_TypeError("str", obj_key); 
        goto fail;
    }
    PyObject *arg_value;
    if (Py_TYPE(obj_value) == CPyType_TokenBalances)
        arg_value = obj_value;
    else {
        arg_value = NULL;
    }
    if (arg_value != NULL) goto __LL8;
    if (PyDict_Check(obj_value))
        arg_value = obj_value;
    else {
        arg_value = NULL;
    }
    if (arg_value != NULL) goto __LL8;
    CPy_TypeError("union[eth_portfolio.typing.TokenBalances, dict]", obj_value); 
    goto fail;
__LL8: ;
    char val = CPyDef_WalletBalances_____setitem__(arg_self, arg_key, arg_value);
    if (val == 2) {
        goto fail;
    }
    return 0;
fail: ;
    return -1;
}
static PyMappingMethods WalletBalances_as_mapping = {
    .mp_subscript = CPyDunder___getitem__WalletBalances,
    .mp_ass_subscript = CPyDunder___setitem__WalletBalances,
};
static PyObject *CPyDunder___add__WalletBalances(PyObject *obj_left, PyObject *obj_right) {
    if (PyObject_IsInstance(obj_left, (PyObject *)CPyType_WalletBalances)) {
        PyObject *arg_left;
        if (likely(PyDict_Check(obj_left)))
            arg_left = obj_left;
        else {
            goto typefail;
        }
        PyObject *arg_right;
        if (likely(PyDict_Check(obj_right)))
            arg_right = obj_right;
        else {
            goto typefail;
        }
        PyObject *retbox = CPyDef_WalletBalances_____add__(arg_left, arg_right);
        if (retbox == Py_NotImplemented) {
            goto typefail;
        }
        return retbox;
    }
typefail: ;
    if (PyObject_IsInstance(obj_right, (PyObject *)CPyType_WalletBalances)) {
        PyObject *arg_right;
        if (likely(PyObject_TypeCheck(obj_right, CPyType__SummableNonNumericMixin)))
            arg_right = obj_right;
        else {
            goto typefail2;
        }
        PyObject *arg_left;
        if (PyObject_TypeCheck(obj_left, CPyType__SummableNonNumericMixin))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL9;
        if (PyLong_Check(obj_left))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL9;
        goto typefail2;
__LL9: ;
        return CPyDef__SummableNonNumericMixin_____radd__(arg_right, arg_left);
    } else {
        _Py_IDENTIFIER(__radd__);
        return CPy_CallReverseOpMethod(obj_left, obj_right, "+", &PyId___radd__);
    }
typefail2: ;
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}
static int CPyDunder___bool__WalletBalances(PyObject *self) {
    char val = CPyDef_WalletBalances_____bool__(self);
    if (val == 2) {
        return -1;
    }
    return val;
}
static PyObject *CPyDunder___sub__WalletBalances(PyObject *obj_left, PyObject *obj_right) {
    PyObject *arg_left;
    if (likely(PyDict_Check(obj_left)))
        arg_left = obj_left;
    else {
        goto typefail;
    }
    PyObject *arg_right;
    if (likely(PyDict_Check(obj_right)))
        arg_right = obj_right;
    else {
        goto typefail;
    }
    PyObject *retbox = CPyDef_WalletBalances_____sub__(arg_left, arg_right);
    if (retbox == Py_NotImplemented) {
        goto typefail;
    }
    return retbox;
typefail: ;
    _Py_IDENTIFIER(__rsub__);
    return CPy_CallReverseOpMethod(obj_left, obj_right, "-", &PyId___rsub__);
}
static PyNumberMethods WalletBalances_as_number = {
    .nb_add = CPyDunder___add__WalletBalances,
    .nb_bool = CPyDunder___bool__WalletBalances,
    .nb_subtract = CPyDunder___sub__WalletBalances,
};
static PyObject *
WalletBalances_get_assets(eth_portfolio___typing___WalletBalancesObject *self, void *closure);
static PyObject *
WalletBalances_get_debt(eth_portfolio___typing___WalletBalancesObject *self, void *closure);
static PyObject *
WalletBalances_get_external(eth_portfolio___typing___WalletBalancesObject *self, void *closure);
static PyObject *
WalletBalances_get_dataframe(eth_portfolio___typing___WalletBalancesObject *self, void *closure);

static PyGetSetDef WalletBalances_getseters[] = {
    {"assets",
     (getter)WalletBalances_get_assets,
    NULL, NULL, NULL},
    {"debt",
     (getter)WalletBalances_get_debt,
    NULL, NULL, NULL},
    {"external",
     (getter)WalletBalances_get_external,
    NULL, NULL, NULL},
    {"dataframe",
     (getter)WalletBalances_get_dataframe,
    NULL, NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef WalletBalances_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_WalletBalances_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"sum_usd",
     (PyCFunction)CPyPy_WalletBalances___sum_usd,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__bool__",
     (PyCFunction)CPyPy_WalletBalances_____bool__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__repr__",
     (PyCFunction)CPyPy_WalletBalances_____repr__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__add__",
     (PyCFunction)CPyPy_WalletBalances_____add__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__sub__",
     (PyCFunction)CPyPy_WalletBalances_____sub__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__getitem__",
     (PyCFunction)CPyPy_WalletBalances_____getitem__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setitem__",
     (PyCFunction)CPyPy_WalletBalances_____setitem__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__validatekey",
     (PyCFunction)CPyPy_WalletBalances_____validatekey,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__validateitem",
     (PyCFunction)CPyPy_WalletBalances_____validateitem,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_WalletBalances_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "WalletBalances",
    .tp_getset = WalletBalances_getseters,
    .tp_methods = WalletBalances_methods,
    .tp_init = WalletBalances_init,
    .tp_repr = CPyDef_WalletBalances_____repr__,
    .tp_as_mapping = &WalletBalances_as_mapping,
    .tp_as_number = &WalletBalances_as_number,
    .tp_basicsize = sizeof(PyDictObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_WalletBalances_template = &CPyType_WalletBalances_template_;


static PyObject *
WalletBalances_get_assets(eth_portfolio___typing___WalletBalancesObject *self, void *closure)
{
    return CPyDef_WalletBalances___assets((PyObject *) self);
}

static PyObject *
WalletBalances_get_debt(eth_portfolio___typing___WalletBalancesObject *self, void *closure)
{
    return CPyDef_WalletBalances___debt((PyObject *) self);
}

static PyObject *
WalletBalances_get_external(eth_portfolio___typing___WalletBalancesObject *self, void *closure)
{
    return CPyDef_WalletBalances___external((PyObject *) self);
}

static PyObject *
WalletBalances_get_dataframe(eth_portfolio___typing___WalletBalancesObject *self, void *closure)
{
    return CPyDef_WalletBalances___dataframe((PyObject *) self);
}

static int
PortfolioBalances_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static int CPyDunder___setitem__PortfolioBalances(PyObject *obj_self, PyObject *obj_key, PyObject *obj_value) {
    if (obj_value == NULL) {
        PyObject *super = CPy_Super(CPyModule_builtins, obj_self);
        if (super == NULL) return -1;
        PyObject *result = PyObject_CallMethod(super, "__delitem__", "O", obj_key);
        Py_DECREF(super);
        Py_XDECREF(result);
        return result == NULL ? -1 : 0;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    PyObject *arg_value;
    if (likely(PyDict_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("dict", obj_value); 
        goto fail;
    }
    char val = CPyDef_PortfolioBalances_____setitem__(arg_self, arg_key, arg_value);
    if (val == 2) {
        goto fail;
    }
    return 0;
fail: ;
    return -1;
}
static PyMappingMethods PortfolioBalances_as_mapping = {
    .mp_ass_subscript = CPyDunder___setitem__PortfolioBalances,
};
static PyObject *CPyDunder___add__PortfolioBalances(PyObject *obj_left, PyObject *obj_right) {
    if (PyObject_IsInstance(obj_left, (PyObject *)CPyType_PortfolioBalances)) {
        PyObject *arg_left;
        if (likely(Py_TYPE(obj_left) == CPyType_PortfolioBalances))
            arg_left = obj_left;
        else {
            goto typefail;
        }
        PyObject *arg_right;
        if (likely(Py_TYPE(obj_right) == CPyType_PortfolioBalances))
            arg_right = obj_right;
        else {
            goto typefail;
        }
        return CPyDef_PortfolioBalances_____add__(arg_left, arg_right);
    }
typefail: ;
    if (PyObject_IsInstance(obj_right, (PyObject *)CPyType_PortfolioBalances)) {
        PyObject *arg_right;
        if (likely(PyObject_TypeCheck(obj_right, CPyType__SummableNonNumericMixin)))
            arg_right = obj_right;
        else {
            goto typefail2;
        }
        PyObject *arg_left;
        if (PyObject_TypeCheck(obj_left, CPyType__SummableNonNumericMixin))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL10;
        if (PyLong_Check(obj_left))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL10;
        goto typefail2;
__LL10: ;
        return CPyDef__SummableNonNumericMixin_____radd__(arg_right, arg_left);
    } else {
        _Py_IDENTIFIER(__radd__);
        return CPy_CallReverseOpMethod(obj_left, obj_right, "+", &PyId___radd__);
    }
typefail2: ;
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}
static int CPyDunder___bool__PortfolioBalances(PyObject *self) {
    char val = CPyDef_PortfolioBalances_____bool__(self);
    if (val == 2) {
        return -1;
    }
    return val;
}
static PyObject *CPyDunder___sub__PortfolioBalances(PyObject *obj_left, PyObject *obj_right) {
    PyObject *arg_left;
    if (likely(Py_TYPE(obj_left) == CPyType_PortfolioBalances))
        arg_left = obj_left;
    else {
        goto typefail;
    }
    PyObject *arg_right;
    if (likely(Py_TYPE(obj_right) == CPyType_PortfolioBalances))
        arg_right = obj_right;
    else {
        goto typefail;
    }
    return CPyDef_PortfolioBalances_____sub__(arg_left, arg_right);
typefail: ;
    _Py_IDENTIFIER(__rsub__);
    return CPy_CallReverseOpMethod(obj_left, obj_right, "-", &PyId___rsub__);
}
static PyNumberMethods PortfolioBalances_as_number = {
    .nb_add = CPyDunder___add__PortfolioBalances,
    .nb_bool = CPyDunder___bool__PortfolioBalances,
    .nb_subtract = CPyDunder___sub__PortfolioBalances,
};
static PyObject *PortfolioBalances_setup(PyTypeObject *type);
PyObject *CPyDef_PortfolioBalances(PyObject *cpy_r_seed, PyObject *cpy_r_block);

static PyObject *
PortfolioBalances_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_PortfolioBalances) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = PortfolioBalances_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_PortfolioBalances_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
PortfolioBalances_traverse(eth_portfolio___typing___PortfolioBalancesObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_block);
    return 0;
}

static int
PortfolioBalances_clear(eth_portfolio___typing___PortfolioBalancesObject *self)
{
    Py_CLEAR(self->_block);
    return 0;
}

static void
PortfolioBalances_dealloc(eth_portfolio___typing___PortfolioBalancesObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, PortfolioBalances_dealloc)
    PortfolioBalances_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem PortfolioBalances_vtable[11];
static bool
CPyDef_PortfolioBalances_trait_vtable_setup(void)
{
    CPyVTableItem PortfolioBalances_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_PortfolioBalances_____add___3___SummableNonNumericMixin_glue,
        (CPyVTableItem)CPyDef__SummableNonNumericMixin_____radd__,
        (CPyVTableItem)CPyDef_PortfolioBalances_____init__,
        (CPyVTableItem)CPyDef_PortfolioBalances_____setitem__,
        (CPyVTableItem)CPyDef_PortfolioBalances___dataframe,
        (CPyVTableItem)CPyDef_PortfolioBalances___sum_usd,
        (CPyVTableItem)CPyDef_PortfolioBalances___inverted,
        (CPyVTableItem)CPyDef_PortfolioBalances_____bool__,
        (CPyVTableItem)CPyDef_PortfolioBalances_____repr__,
        (CPyVTableItem)CPyDef_PortfolioBalances_____add__,
        (CPyVTableItem)CPyDef_PortfolioBalances_____sub__,
    };
    memcpy(PortfolioBalances_vtable, PortfolioBalances_vtable_scratch, sizeof(PortfolioBalances_vtable));
    return 1;
}

static PyObject *
PortfolioBalances_get_block(eth_portfolio___typing___PortfolioBalancesObject *self, void *closure);
static int
PortfolioBalances_set_block(eth_portfolio___typing___PortfolioBalancesObject *self, PyObject *value, void *closure);
static PyObject *
PortfolioBalances_get_dataframe(eth_portfolio___typing___PortfolioBalancesObject *self, void *closure);
static PyObject *
PortfolioBalances_get_inverted(eth_portfolio___typing___PortfolioBalancesObject *self, void *closure);

static PyGetSetDef PortfolioBalances_getseters[] = {
    {"block",
     (getter)PortfolioBalances_get_block, (setter)PortfolioBalances_set_block,
     NULL, NULL},
    {"dataframe",
     (getter)PortfolioBalances_get_dataframe,
    NULL, NULL, NULL},
    {"inverted",
     (getter)PortfolioBalances_get_inverted,
    NULL, NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef PortfolioBalances_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_PortfolioBalances_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setitem__",
     (PyCFunction)CPyPy_PortfolioBalances_____setitem__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"sum_usd",
     (PyCFunction)CPyPy_PortfolioBalances___sum_usd,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__bool__",
     (PyCFunction)CPyPy_PortfolioBalances_____bool__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__repr__",
     (PyCFunction)CPyPy_PortfolioBalances_____repr__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__add__",
     (PyCFunction)CPyPy_PortfolioBalances_____add__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__sub__",
     (PyCFunction)CPyPy_PortfolioBalances_____sub__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_PortfolioBalances_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "PortfolioBalances",
    .tp_new = PortfolioBalances_new,
    .tp_dealloc = (destructor)PortfolioBalances_dealloc,
    .tp_traverse = (traverseproc)PortfolioBalances_traverse,
    .tp_clear = (inquiry)PortfolioBalances_clear,
    .tp_getset = PortfolioBalances_getseters,
    .tp_methods = PortfolioBalances_methods,
    .tp_init = PortfolioBalances_init,
    .tp_repr = CPyDef_PortfolioBalances_____repr__,
    .tp_as_mapping = &PortfolioBalances_as_mapping,
    .tp_as_number = &PortfolioBalances_as_number,
    .tp_basicsize = sizeof(eth_portfolio___typing___PortfolioBalancesObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_PortfolioBalances_template = &CPyType_PortfolioBalances_template_;

static PyObject *
PortfolioBalances_setup(PyTypeObject *type)
{
    eth_portfolio___typing___PortfolioBalancesObject *self;
    self = (eth_portfolio___typing___PortfolioBalancesObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = PortfolioBalances_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_PortfolioBalances(PyObject *cpy_r_seed, PyObject *cpy_r_block)
{
    PyObject *self = PortfolioBalances_setup(CPyType_PortfolioBalances);
    if (self == NULL)
        return NULL;
    char res = CPyDef_PortfolioBalances_____init__(self, cpy_r_seed, cpy_r_block);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
PortfolioBalances_get_block(eth_portfolio___typing___PortfolioBalancesObject *self, void *closure)
{
    if (unlikely(self->_block == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'block' of 'PortfolioBalances' undefined");
        return NULL;
    }
    CPy_INCREF(self->_block);
    PyObject *retval = self->_block;
    return retval;
}

static int
PortfolioBalances_set_block(eth_portfolio___typing___PortfolioBalancesObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'PortfolioBalances' object attribute 'block' cannot be deleted");
        return -1;
    }
    if (self->_block != NULL) {
        CPy_DECREF(self->_block);
    }
    PyObject *tmp;
    if (PyLong_Check(value))
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL11;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL11;
    CPy_TypeError("int or None", value); 
    tmp = NULL;
__LL11: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_block = tmp;
    return 0;
}

static PyObject *
PortfolioBalances_get_dataframe(eth_portfolio___typing___PortfolioBalancesObject *self, void *closure)
{
    return CPyDef_PortfolioBalances___dataframe((PyObject *) self);
}

static PyObject *
PortfolioBalances_get_inverted(eth_portfolio___typing___PortfolioBalancesObject *self, void *closure)
{
    return CPyDef_PortfolioBalances___inverted((PyObject *) self);
}

static int
WalletBalancesRaw_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *CPyDunder___add__WalletBalancesRaw(PyObject *obj_left, PyObject *obj_right) {
    if (PyObject_IsInstance(obj_left, (PyObject *)CPyType_WalletBalancesRaw)) {
        PyObject *arg_left;
        if (likely(Py_TYPE(obj_left) == CPyType_WalletBalancesRaw))
            arg_left = obj_left;
        else {
            goto typefail;
        }
        PyObject *arg_right;
        if (likely(Py_TYPE(obj_right) == CPyType_WalletBalancesRaw))
            arg_right = obj_right;
        else {
            goto typefail;
        }
        return CPyDef_WalletBalancesRaw_____add__(arg_left, arg_right);
    }
typefail: ;
    if (PyObject_IsInstance(obj_right, (PyObject *)CPyType_WalletBalancesRaw)) {
        PyObject *arg_right;
        if (likely(PyObject_TypeCheck(obj_right, CPyType__SummableNonNumericMixin)))
            arg_right = obj_right;
        else {
            goto typefail2;
        }
        PyObject *arg_left;
        if (PyObject_TypeCheck(obj_left, CPyType__SummableNonNumericMixin))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL12;
        if (PyLong_Check(obj_left))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL12;
        goto typefail2;
__LL12: ;
        return CPyDef__SummableNonNumericMixin_____radd__(arg_right, arg_left);
    } else {
        _Py_IDENTIFIER(__radd__);
        return CPy_CallReverseOpMethod(obj_left, obj_right, "+", &PyId___radd__);
    }
typefail2: ;
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}
static int CPyDunder___bool__WalletBalancesRaw(PyObject *self) {
    char val = CPyDef_WalletBalancesRaw_____bool__(self);
    if (val == 2) {
        return -1;
    }
    return val;
}
static PyObject *CPyDunder___sub__WalletBalancesRaw(PyObject *obj_left, PyObject *obj_right) {
    PyObject *arg_left;
    if (likely(Py_TYPE(obj_left) == CPyType_WalletBalancesRaw))
        arg_left = obj_left;
    else {
        goto typefail;
    }
    PyObject *arg_right;
    if (likely(Py_TYPE(obj_right) == CPyType_WalletBalancesRaw))
        arg_right = obj_right;
    else {
        goto typefail;
    }
    return CPyDef_WalletBalancesRaw_____sub__(arg_left, arg_right);
typefail: ;
    _Py_IDENTIFIER(__rsub__);
    return CPy_CallReverseOpMethod(obj_left, obj_right, "-", &PyId___rsub__);
}
static PyNumberMethods WalletBalancesRaw_as_number = {
    .nb_add = CPyDunder___add__WalletBalancesRaw,
    .nb_bool = CPyDunder___bool__WalletBalancesRaw,
    .nb_subtract = CPyDunder___sub__WalletBalancesRaw,
};
static PyObject *WalletBalancesRaw_setup(PyTypeObject *type);
PyObject *CPyDef_WalletBalancesRaw(PyObject *cpy_r_seed, PyObject *cpy_r_block);

static PyObject *
WalletBalancesRaw_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_WalletBalancesRaw) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = WalletBalancesRaw_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_WalletBalancesRaw_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
WalletBalancesRaw_traverse(eth_portfolio___typing___WalletBalancesRawObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_block);
    return 0;
}

static int
WalletBalancesRaw_clear(eth_portfolio___typing___WalletBalancesRawObject *self)
{
    Py_CLEAR(self->_block);
    return 0;
}

static void
WalletBalancesRaw_dealloc(eth_portfolio___typing___WalletBalancesRawObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, WalletBalancesRaw_dealloc)
    WalletBalancesRaw_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem WalletBalancesRaw_vtable[7];
static bool
CPyDef_WalletBalancesRaw_trait_vtable_setup(void)
{
    CPyVTableItem WalletBalancesRaw_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_WalletBalancesRaw_____add___3___SummableNonNumericMixin_glue,
        (CPyVTableItem)CPyDef__SummableNonNumericMixin_____radd__,
        (CPyVTableItem)CPyDef_WalletBalancesRaw_____init__,
        (CPyVTableItem)CPyDef_WalletBalancesRaw_____bool__,
        (CPyVTableItem)CPyDef_WalletBalancesRaw_____repr__,
        (CPyVTableItem)CPyDef_WalletBalancesRaw_____add__,
        (CPyVTableItem)CPyDef_WalletBalancesRaw_____sub__,
    };
    memcpy(WalletBalancesRaw_vtable, WalletBalancesRaw_vtable_scratch, sizeof(WalletBalancesRaw_vtable));
    return 1;
}

static PyObject *
WalletBalancesRaw_get_block(eth_portfolio___typing___WalletBalancesRawObject *self, void *closure);
static int
WalletBalancesRaw_set_block(eth_portfolio___typing___WalletBalancesRawObject *self, PyObject *value, void *closure);

static PyGetSetDef WalletBalancesRaw_getseters[] = {
    {"block",
     (getter)WalletBalancesRaw_get_block, (setter)WalletBalancesRaw_set_block,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef WalletBalancesRaw_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_WalletBalancesRaw_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__bool__",
     (PyCFunction)CPyPy_WalletBalancesRaw_____bool__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__repr__",
     (PyCFunction)CPyPy_WalletBalancesRaw_____repr__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__add__",
     (PyCFunction)CPyPy_WalletBalancesRaw_____add__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__sub__",
     (PyCFunction)CPyPy_WalletBalancesRaw_____sub__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_WalletBalancesRaw_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "WalletBalancesRaw",
    .tp_new = WalletBalancesRaw_new,
    .tp_dealloc = (destructor)WalletBalancesRaw_dealloc,
    .tp_traverse = (traverseproc)WalletBalancesRaw_traverse,
    .tp_clear = (inquiry)WalletBalancesRaw_clear,
    .tp_getset = WalletBalancesRaw_getseters,
    .tp_methods = WalletBalancesRaw_methods,
    .tp_init = WalletBalancesRaw_init,
    .tp_repr = CPyDef_WalletBalancesRaw_____repr__,
    .tp_as_number = &WalletBalancesRaw_as_number,
    .tp_basicsize = sizeof(eth_portfolio___typing___WalletBalancesRawObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_WalletBalancesRaw_template = &CPyType_WalletBalancesRaw_template_;

static PyObject *
WalletBalancesRaw_setup(PyTypeObject *type)
{
    eth_portfolio___typing___WalletBalancesRawObject *self;
    self = (eth_portfolio___typing___WalletBalancesRawObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = WalletBalancesRaw_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_WalletBalancesRaw(PyObject *cpy_r_seed, PyObject *cpy_r_block)
{
    PyObject *self = WalletBalancesRaw_setup(CPyType_WalletBalancesRaw);
    if (self == NULL)
        return NULL;
    char res = CPyDef_WalletBalancesRaw_____init__(self, cpy_r_seed, cpy_r_block);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
WalletBalancesRaw_get_block(eth_portfolio___typing___WalletBalancesRawObject *self, void *closure)
{
    if (unlikely(self->_block == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'block' of 'WalletBalancesRaw' undefined");
        return NULL;
    }
    CPy_INCREF(self->_block);
    PyObject *retval = self->_block;
    return retval;
}

static int
WalletBalancesRaw_set_block(eth_portfolio___typing___WalletBalancesRawObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'WalletBalancesRaw' object attribute 'block' cannot be deleted");
        return -1;
    }
    if (self->_block != NULL) {
        CPy_DECREF(self->_block);
    }
    PyObject *tmp;
    if (PyLong_Check(value))
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL13;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL13;
    CPy_TypeError("int or None", value); 
    tmp = NULL;
__LL13: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_block = tmp;
    return 0;
}

static int
PortfolioBalancesByCategory_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return CPyPy_PortfolioBalancesByCategory_____init__(self, args, kwds) != NULL ? 0 : -1;
}
static PyObject *CPyDunder___add__PortfolioBalancesByCategory(PyObject *obj_left, PyObject *obj_right) {
    if (PyObject_IsInstance(obj_left, (PyObject *)CPyType_PortfolioBalancesByCategory)) {
        PyObject *arg_left;
        if (likely(PyDict_Check(obj_left)))
            arg_left = obj_left;
        else {
            goto typefail;
        }
        PyObject *arg_right;
        if (likely(PyDict_Check(obj_right)))
            arg_right = obj_right;
        else {
            goto typefail;
        }
        PyObject *retbox = CPyDef_PortfolioBalancesByCategory_____add__(arg_left, arg_right);
        if (retbox == Py_NotImplemented) {
            goto typefail;
        }
        return retbox;
    }
typefail: ;
    if (PyObject_IsInstance(obj_right, (PyObject *)CPyType_PortfolioBalancesByCategory)) {
        PyObject *arg_right;
        if (likely(PyObject_TypeCheck(obj_right, CPyType__SummableNonNumericMixin)))
            arg_right = obj_right;
        else {
            goto typefail2;
        }
        PyObject *arg_left;
        if (PyObject_TypeCheck(obj_left, CPyType__SummableNonNumericMixin))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL14;
        if (PyLong_Check(obj_left))
            arg_left = obj_left;
        else {
            arg_left = NULL;
        }
        if (arg_left != NULL) goto __LL14;
        goto typefail2;
__LL14: ;
        return CPyDef__SummableNonNumericMixin_____radd__(arg_right, arg_left);
    } else {
        _Py_IDENTIFIER(__radd__);
        return CPy_CallReverseOpMethod(obj_left, obj_right, "+", &PyId___radd__);
    }
typefail2: ;
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}
static int CPyDunder___bool__PortfolioBalancesByCategory(PyObject *self) {
    char val = CPyDef_PortfolioBalancesByCategory_____bool__(self);
    if (val == 2) {
        return -1;
    }
    return val;
}
static PyObject *CPyDunder___sub__PortfolioBalancesByCategory(PyObject *obj_left, PyObject *obj_right) {
    PyObject *arg_left;
    if (likely(PyDict_Check(obj_left)))
        arg_left = obj_left;
    else {
        goto typefail;
    }
    PyObject *arg_right;
    if (likely(PyDict_Check(obj_right)))
        arg_right = obj_right;
    else {
        goto typefail;
    }
    PyObject *retbox = CPyDef_PortfolioBalancesByCategory_____sub__(arg_left, arg_right);
    if (retbox == Py_NotImplemented) {
        goto typefail;
    }
    return retbox;
typefail: ;
    _Py_IDENTIFIER(__rsub__);
    return CPy_CallReverseOpMethod(obj_left, obj_right, "-", &PyId___rsub__);
}
static PyNumberMethods PortfolioBalancesByCategory_as_number = {
    .nb_add = CPyDunder___add__PortfolioBalancesByCategory,
    .nb_bool = CPyDunder___bool__PortfolioBalancesByCategory,
    .nb_subtract = CPyDunder___sub__PortfolioBalancesByCategory,
};
static PyObject *
PortfolioBalancesByCategory_get_assets(eth_portfolio___typing___PortfolioBalancesByCategoryObject *self, void *closure);
static PyObject *
PortfolioBalancesByCategory_get_debt(eth_portfolio___typing___PortfolioBalancesByCategoryObject *self, void *closure);

static PyGetSetDef PortfolioBalancesByCategory_getseters[] = {
    {"assets",
     (getter)PortfolioBalancesByCategory_get_assets,
    NULL, NULL, NULL},
    {"debt",
     (getter)PortfolioBalancesByCategory_get_debt,
    NULL, NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef PortfolioBalancesByCategory_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_PortfolioBalancesByCategory_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"invert",
     (PyCFunction)CPyPy_PortfolioBalancesByCategory___invert,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__bool__",
     (PyCFunction)CPyPy_PortfolioBalancesByCategory_____bool__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__repr__",
     (PyCFunction)CPyPy_PortfolioBalancesByCategory_____repr__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__add__",
     (PyCFunction)CPyPy_PortfolioBalancesByCategory_____add__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__sub__",
     (PyCFunction)CPyPy_PortfolioBalancesByCategory_____sub__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_PortfolioBalancesByCategory_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "PortfolioBalancesByCategory",
    .tp_getset = PortfolioBalancesByCategory_getseters,
    .tp_methods = PortfolioBalancesByCategory_methods,
    .tp_init = PortfolioBalancesByCategory_init,
    .tp_repr = CPyDef_PortfolioBalancesByCategory_____repr__,
    .tp_as_number = &PortfolioBalancesByCategory_as_number,
    .tp_basicsize = sizeof(PyDictObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_PortfolioBalancesByCategory_template = &CPyType_PortfolioBalancesByCategory_template_;


static PyObject *
PortfolioBalancesByCategory_get_assets(eth_portfolio___typing___PortfolioBalancesByCategoryObject *self, void *closure)
{
    return CPyDef_PortfolioBalancesByCategory___assets((PyObject *) self);
}

static PyObject *
PortfolioBalancesByCategory_get_debt(eth_portfolio___typing___PortfolioBalancesByCategoryObject *self, void *closure)
{
    return CPyDef_PortfolioBalancesByCategory___debt((PyObject *) self);
}

static PyObject *__init___3_RemoteTokenBalances_env_setup(PyTypeObject *type);
PyObject *CPyDef___init___3_RemoteTokenBalances_env(void);

static PyObject *
__init___3_RemoteTokenBalances_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___init___3_RemoteTokenBalances_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __init___3_RemoteTokenBalances_env_setup(type);
}

static int
__init___3_RemoteTokenBalances_env_traverse(eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_block);
    Py_VISIT(self->_self);
    Py_VISIT(self->_seed);
    return 0;
}

static int
__init___3_RemoteTokenBalances_env_clear(eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_block);
    Py_CLEAR(self->_self);
    Py_CLEAR(self->_seed);
    return 0;
}

static void
__init___3_RemoteTokenBalances_env_dealloc(eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __init___3_RemoteTokenBalances_env_dealloc)
    __init___3_RemoteTokenBalances_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __init___3_RemoteTokenBalances_env_vtable[1];
static bool
CPyDef___init___3_RemoteTokenBalances_env_trait_vtable_setup(void)
{
    CPyVTableItem __init___3_RemoteTokenBalances_env_vtable_scratch[] = {
        NULL
    };
    memcpy(__init___3_RemoteTokenBalances_env_vtable, __init___3_RemoteTokenBalances_env_vtable_scratch, sizeof(__init___3_RemoteTokenBalances_env_vtable));
    return 1;
}

static PyMethodDef __init___3_RemoteTokenBalances_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___init___3_RemoteTokenBalances_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__init___RemoteTokenBalances_env",
    .tp_new = __init___3_RemoteTokenBalances_env_new,
    .tp_dealloc = (destructor)__init___3_RemoteTokenBalances_env_dealloc,
    .tp_traverse = (traverseproc)__init___3_RemoteTokenBalances_env_traverse,
    .tp_clear = (inquiry)__init___3_RemoteTokenBalances_env_clear,
    .tp_methods = __init___3_RemoteTokenBalances_env_methods,
    .tp_basicsize = sizeof(eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType___init___3_RemoteTokenBalances_env_template = &CPyType___init___3_RemoteTokenBalances_env_template_;

static PyObject *
__init___3_RemoteTokenBalances_env_setup(PyTypeObject *type)
{
    eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *self;
    self = (eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __init___3_RemoteTokenBalances_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef___init___3_RemoteTokenBalances_env(void)
{
    PyObject *self = __init___3_RemoteTokenBalances_env_setup(CPyType___init___3_RemoteTokenBalances_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get____mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__(self, instance, owner);
}
static PyObject *__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj(void);

static PyObject *
__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_setup(type);
}

static int
__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_traverse(eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_clear(eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_dealloc(eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_dealloc)
    __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__,
    };
    memcpy(__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_vtable, __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_vtable_scratch, sizeof(__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_vtable));
    return 1;
}

static PyObject *
__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_get___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *self, void *closure);
static int
__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_set___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *self, PyObject *value, void *closure);

static PyGetSetDef __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_get___3_mypyc_env__, (setter)__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__0___init___RemoteTokenBalances_obj",
    .tp_new = __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_clear,
    .tp_getset = __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_getseters,
    .tp_methods = __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj,
    .tp_basicsize = sizeof(eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject),
    .tp_vectorcall_offset = offsetof(eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_template = &CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_template_;

static PyObject *
__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_setup(PyTypeObject *type)
{
    eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *self;
    self = (eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj(void)
{
    PyObject *self = __mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_setup(CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_get___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of '__mypyc_lambda__0___init___RemoteTokenBalances_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
__mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_set___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'__mypyc_lambda__0___init___RemoteTokenBalances_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType___init___3_RemoteTokenBalances_env))
        tmp = value;
    else {
        CPy_TypeError("eth_portfolio.typing.__init___RemoteTokenBalances_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyObject *__init___3_PortfolioBalances_env_setup(PyTypeObject *type);
PyObject *CPyDef___init___3_PortfolioBalances_env(void);

static PyObject *
__init___3_PortfolioBalances_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___init___3_PortfolioBalances_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __init___3_PortfolioBalances_env_setup(type);
}

static int
__init___3_PortfolioBalances_env_traverse(eth_portfolio___typing_____init___3_PortfolioBalances_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_block);
    Py_VISIT(self->_self);
    Py_VISIT(self->_seed);
    return 0;
}

static int
__init___3_PortfolioBalances_env_clear(eth_portfolio___typing_____init___3_PortfolioBalances_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_block);
    Py_CLEAR(self->_self);
    Py_CLEAR(self->_seed);
    return 0;
}

static void
__init___3_PortfolioBalances_env_dealloc(eth_portfolio___typing_____init___3_PortfolioBalances_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __init___3_PortfolioBalances_env_dealloc)
    __init___3_PortfolioBalances_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __init___3_PortfolioBalances_env_vtable[1];
static bool
CPyDef___init___3_PortfolioBalances_env_trait_vtable_setup(void)
{
    CPyVTableItem __init___3_PortfolioBalances_env_vtable_scratch[] = {
        NULL
    };
    memcpy(__init___3_PortfolioBalances_env_vtable, __init___3_PortfolioBalances_env_vtable_scratch, sizeof(__init___3_PortfolioBalances_env_vtable));
    return 1;
}

static PyMethodDef __init___3_PortfolioBalances_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___init___3_PortfolioBalances_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__init___PortfolioBalances_env",
    .tp_new = __init___3_PortfolioBalances_env_new,
    .tp_dealloc = (destructor)__init___3_PortfolioBalances_env_dealloc,
    .tp_traverse = (traverseproc)__init___3_PortfolioBalances_env_traverse,
    .tp_clear = (inquiry)__init___3_PortfolioBalances_env_clear,
    .tp_methods = __init___3_PortfolioBalances_env_methods,
    .tp_basicsize = sizeof(eth_portfolio___typing_____init___3_PortfolioBalances_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType___init___3_PortfolioBalances_env_template = &CPyType___init___3_PortfolioBalances_env_template_;

static PyObject *
__init___3_PortfolioBalances_env_setup(PyTypeObject *type)
{
    eth_portfolio___typing_____init___3_PortfolioBalances_envObject *self;
    self = (eth_portfolio___typing_____init___3_PortfolioBalances_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __init___3_PortfolioBalances_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef___init___3_PortfolioBalances_env(void)
{
    PyObject *self = __init___3_PortfolioBalances_env_setup(CPyType___init___3_PortfolioBalances_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get____mypyc_lambda__1___3_init___3_PortfolioBalances_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__(self, instance, owner);
}
static PyObject *__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj(void);

static PyObject *
__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_setup(type);
}

static int
__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_traverse(eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_clear(eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_dealloc(eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_dealloc)
    __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__,
    };
    memcpy(__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_vtable, __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_vtable_scratch, sizeof(__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_vtable));
    return 1;
}

static PyObject *
__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_get___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *self, void *closure);
static int
__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_set___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *self, PyObject *value, void *closure);

static PyGetSetDef __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_get___3_mypyc_env__, (setter)__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__1___init___PortfolioBalances_obj",
    .tp_new = __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_clear,
    .tp_getset = __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_getseters,
    .tp_methods = __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__1___3_init___3_PortfolioBalances_obj,
    .tp_basicsize = sizeof(eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject),
    .tp_vectorcall_offset = offsetof(eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_template = &CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_template_;

static PyObject *
__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_setup(PyTypeObject *type)
{
    eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *self;
    self = (eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj(void)
{
    PyObject *self = __mypyc_lambda__1___3_init___3_PortfolioBalances_obj_setup(CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_get___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of '__mypyc_lambda__1___init___PortfolioBalances_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
__mypyc_lambda__1___3_init___3_PortfolioBalances_obj_set___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'__mypyc_lambda__1___init___PortfolioBalances_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType___init___3_PortfolioBalances_env))
        tmp = value;
    else {
        CPy_TypeError("eth_portfolio.typing.__init___PortfolioBalances_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyObject *__init___3_WalletBalancesRaw_env_setup(PyTypeObject *type);
PyObject *CPyDef___init___3_WalletBalancesRaw_env(void);

static PyObject *
__init___3_WalletBalancesRaw_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___init___3_WalletBalancesRaw_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __init___3_WalletBalancesRaw_env_setup(type);
}

static int
__init___3_WalletBalancesRaw_env_traverse(eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_block);
    Py_VISIT(self->_self);
    Py_VISIT(self->_seed);
    return 0;
}

static int
__init___3_WalletBalancesRaw_env_clear(eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_block);
    Py_CLEAR(self->_self);
    Py_CLEAR(self->_seed);
    return 0;
}

static void
__init___3_WalletBalancesRaw_env_dealloc(eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __init___3_WalletBalancesRaw_env_dealloc)
    __init___3_WalletBalancesRaw_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __init___3_WalletBalancesRaw_env_vtable[1];
static bool
CPyDef___init___3_WalletBalancesRaw_env_trait_vtable_setup(void)
{
    CPyVTableItem __init___3_WalletBalancesRaw_env_vtable_scratch[] = {
        NULL
    };
    memcpy(__init___3_WalletBalancesRaw_env_vtable, __init___3_WalletBalancesRaw_env_vtable_scratch, sizeof(__init___3_WalletBalancesRaw_env_vtable));
    return 1;
}

static PyMethodDef __init___3_WalletBalancesRaw_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___init___3_WalletBalancesRaw_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__init___WalletBalancesRaw_env",
    .tp_new = __init___3_WalletBalancesRaw_env_new,
    .tp_dealloc = (destructor)__init___3_WalletBalancesRaw_env_dealloc,
    .tp_traverse = (traverseproc)__init___3_WalletBalancesRaw_env_traverse,
    .tp_clear = (inquiry)__init___3_WalletBalancesRaw_env_clear,
    .tp_methods = __init___3_WalletBalancesRaw_env_methods,
    .tp_basicsize = sizeof(eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType___init___3_WalletBalancesRaw_env_template = &CPyType___init___3_WalletBalancesRaw_env_template_;

static PyObject *
__init___3_WalletBalancesRaw_env_setup(PyTypeObject *type)
{
    eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *self;
    self = (eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __init___3_WalletBalancesRaw_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef___init___3_WalletBalancesRaw_env(void)
{
    PyObject *self = __init___3_WalletBalancesRaw_env_setup(CPyType___init___3_WalletBalancesRaw_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get____mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__(self, instance, owner);
}
static PyObject *__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj(void);

static PyObject *
__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_setup(type);
}

static int
__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_traverse(eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_clear(eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_dealloc(eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_dealloc)
    __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__,
    };
    memcpy(__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_vtable, __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_vtable_scratch, sizeof(__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_vtable));
    return 1;
}

static PyObject *
__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_get___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *self, void *closure);
static int
__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_set___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *self, PyObject *value, void *closure);

static PyGetSetDef __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_get___3_mypyc_env__, (setter)__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__2___init___WalletBalancesRaw_obj",
    .tp_new = __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_clear,
    .tp_getset = __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_getseters,
    .tp_methods = __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj,
    .tp_basicsize = sizeof(eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject),
    .tp_vectorcall_offset = offsetof(eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_template = &CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_template_;

static PyObject *
__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_setup(PyTypeObject *type)
{
    eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *self;
    self = (eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj(void)
{
    PyObject *self = __mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_setup(CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_get___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of '__mypyc_lambda__2___init___WalletBalancesRaw_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
__mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_set___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'__mypyc_lambda__2___init___WalletBalancesRaw_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType___init___3_WalletBalancesRaw_env))
        tmp = value;
    else {
        CPy_TypeError("eth_portfolio.typing.__init___WalletBalancesRaw_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyObject *__init___3_PortfolioBalancesByCategory_env_setup(PyTypeObject *type);
PyObject *CPyDef___init___3_PortfolioBalancesByCategory_env(void);

static PyObject *
__init___3_PortfolioBalancesByCategory_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___init___3_PortfolioBalancesByCategory_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __init___3_PortfolioBalancesByCategory_env_setup(type);
}

static int
__init___3_PortfolioBalancesByCategory_env_traverse(eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_block);
    Py_VISIT(self->_self);
    Py_VISIT(self->_seed);
    return 0;
}

static int
__init___3_PortfolioBalancesByCategory_env_clear(eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_block);
    Py_CLEAR(self->_self);
    Py_CLEAR(self->_seed);
    return 0;
}

static void
__init___3_PortfolioBalancesByCategory_env_dealloc(eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __init___3_PortfolioBalancesByCategory_env_dealloc)
    __init___3_PortfolioBalancesByCategory_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __init___3_PortfolioBalancesByCategory_env_vtable[1];
static bool
CPyDef___init___3_PortfolioBalancesByCategory_env_trait_vtable_setup(void)
{
    CPyVTableItem __init___3_PortfolioBalancesByCategory_env_vtable_scratch[] = {
        NULL
    };
    memcpy(__init___3_PortfolioBalancesByCategory_env_vtable, __init___3_PortfolioBalancesByCategory_env_vtable_scratch, sizeof(__init___3_PortfolioBalancesByCategory_env_vtable));
    return 1;
}

static PyMethodDef __init___3_PortfolioBalancesByCategory_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___init___3_PortfolioBalancesByCategory_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__init___PortfolioBalancesByCategory_env",
    .tp_new = __init___3_PortfolioBalancesByCategory_env_new,
    .tp_dealloc = (destructor)__init___3_PortfolioBalancesByCategory_env_dealloc,
    .tp_traverse = (traverseproc)__init___3_PortfolioBalancesByCategory_env_traverse,
    .tp_clear = (inquiry)__init___3_PortfolioBalancesByCategory_env_clear,
    .tp_methods = __init___3_PortfolioBalancesByCategory_env_methods,
    .tp_basicsize = sizeof(eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType___init___3_PortfolioBalancesByCategory_env_template = &CPyType___init___3_PortfolioBalancesByCategory_env_template_;

static PyObject *
__init___3_PortfolioBalancesByCategory_env_setup(PyTypeObject *type)
{
    eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *self;
    self = (eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __init___3_PortfolioBalancesByCategory_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef___init___3_PortfolioBalancesByCategory_env(void)
{
    PyObject *self = __init___3_PortfolioBalancesByCategory_env_setup(CPyType___init___3_PortfolioBalancesByCategory_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__(self, instance, owner);
}
static PyObject *__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj(void);

static PyObject *
__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_setup(type);
}

static int
__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_traverse(eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_clear(eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_dealloc(eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_dealloc)
    __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__,
    };
    memcpy(__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_vtable, __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_vtable_scratch, sizeof(__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_vtable));
    return 1;
}

static PyObject *
__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_get___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *self, void *closure);
static int
__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_set___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *self, PyObject *value, void *closure);

static PyGetSetDef __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_get___3_mypyc_env__, (setter)__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__3___init___PortfolioBalancesByCategory_obj",
    .tp_new = __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_clear,
    .tp_getset = __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_getseters,
    .tp_methods = __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj,
    .tp_basicsize = sizeof(eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject),
    .tp_vectorcall_offset = offsetof(eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_template = &CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_template_;

static PyObject *
__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_setup(PyTypeObject *type)
{
    eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *self;
    self = (eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj(void)
{
    PyObject *self = __mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_setup(CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_get___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of '__mypyc_lambda__3___init___PortfolioBalancesByCategory_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
__mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_set___3_mypyc_env__(eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'__mypyc_lambda__3___init___PortfolioBalancesByCategory_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType___init___3_PortfolioBalancesByCategory_env))
        tmp = value;
    else {
        CPy_TypeError("eth_portfolio.typing.__init___PortfolioBalancesByCategory_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "eth_portfolio.typing",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyObject *CPyInit_eth_portfolio___typing(void)
{
    PyObject* modname = NULL;
    if (CPyModule_eth_portfolio___typing_internal) {
        Py_INCREF(CPyModule_eth_portfolio___typing_internal);
        return CPyModule_eth_portfolio___typing_internal;
    }
    CPyModule_eth_portfolio___typing_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_eth_portfolio___typing_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_eth_portfolio___typing_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_eth_portfolio___typing_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType___init___3_RemoteTokenBalances_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___init___3_RemoteTokenBalances_env_template, NULL, modname);
    if (unlikely(!CPyType___init___3_RemoteTokenBalances_env))
        goto fail;
    CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj))
        goto fail;
    CPyType___init___3_PortfolioBalances_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___init___3_PortfolioBalances_env_template, NULL, modname);
    if (unlikely(!CPyType___init___3_PortfolioBalances_env))
        goto fail;
    CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj))
        goto fail;
    CPyType___init___3_WalletBalancesRaw_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___init___3_WalletBalancesRaw_env_template, NULL, modname);
    if (unlikely(!CPyType___init___3_WalletBalancesRaw_env))
        goto fail;
    CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj))
        goto fail;
    CPyType___init___3_PortfolioBalancesByCategory_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___init___3_PortfolioBalancesByCategory_env_template, NULL, modname);
    if (unlikely(!CPyType___init___3_PortfolioBalancesByCategory_env))
        goto fail;
    CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_eth_portfolio___typing_internal;
    fail:
    Py_CLEAR(CPyModule_eth_portfolio___typing_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_Balance);
    Py_CLEAR(CPyType__SummableNonNumericMixin);
    Py_CLEAR(CPyType_TokenBalances);
    Py_CLEAR(CPyType_RemoteTokenBalances);
    Py_CLEAR(CPyType_WalletBalances);
    Py_CLEAR(CPyType_PortfolioBalances);
    Py_CLEAR(CPyType_WalletBalancesRaw);
    Py_CLEAR(CPyType_PortfolioBalancesByCategory);
    Py_CLEAR(CPyType___init___3_RemoteTokenBalances_env);
    Py_CLEAR(CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj);
    Py_CLEAR(CPyType___init___3_PortfolioBalances_env);
    Py_CLEAR(CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj);
    Py_CLEAR(CPyType___init___3_WalletBalancesRaw_env);
    Py_CLEAR(CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj);
    Py_CLEAR(CPyType___init___3_PortfolioBalancesByCategory_env);
    Py_CLEAR(CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj);
    return NULL;
}

PyObject *CPyDef_Balance___usd(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    cpy_r_r0 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_usd_value;
    CPy_INCREF(cpy_r_r0);
    return cpy_r_r0;
}

PyObject *CPyPy_Balance___usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":usd", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Balance))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_Balance___usd(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "usd", 98, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Balance_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
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
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    int32_t cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
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
    PyObject **cpy_r_r61;
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
    tuple_T3OOO cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    char cpy_r_r76;
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
    CPyPtr cpy_r_r89;
    CPyPtr cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    int32_t cpy_r_r94;
    char cpy_r_r95;
    char cpy_r_r96;
    PyObject *cpy_r_r97;
    cpy_r_r0 = (PyObject *)CPyType_Balance;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 129, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r11 = CPyStatics[6]; /* ' is not a `Balance` object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 129, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 129, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 129, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 129, CPyStatic_globals);
        goto CPyL52;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 129, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_token;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_token;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PyObject_RichCompare(cpy_r_r23, cpy_r_r24, 3);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 130, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r26 = PyObject_IsTrue(cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r27 = cpy_r_r26 >= 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 130, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r28 = cpy_r_r26;
    if (!cpy_r_r28) goto CPyL18;
    cpy_r_r29 = CPyStatics[8]; /* ('These Balance objects represent balances of different '
                                  'tokens (') */
    cpy_r_r30 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_token;
    CPy_INCREF(cpy_r_r30);
    cpy_r_r31 = PyObject_Str(cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 132, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r32 = CPyStatics[9]; /* ' and ' */
    cpy_r_r33 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_token;
    CPy_INCREF(cpy_r_r33);
    cpy_r_r34 = PyObject_Str(cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 132, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r35 = CPyStatics[10]; /* ')' */
    cpy_r_r36 = CPyStr_Build(5, cpy_r_r29, cpy_r_r31, cpy_r_r32, cpy_r_r34, cpy_r_r35);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 132, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r37 = CPyModule_builtins;
    cpy_r_r38 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 131, CPyStatic_globals);
        goto CPyL54;
    }
    PyObject *cpy_r_r40[1] = {cpy_r_r36};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = _PyObject_Vectorcall(cpy_r_r39, cpy_r_r41, 1, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 131, CPyStatic_globals);
        goto CPyL54;
    }
    CPy_DECREF(cpy_r_r36);
    CPy_Raise(cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 131, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r43 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r43);
    cpy_r_r44 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r44);
    cpy_r_r45 = PyObject_RichCompare(cpy_r_r43, cpy_r_r44, 3);
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 134, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r46 = PyObject_IsTrue(cpy_r_r45);
    CPy_DECREF(cpy_r_r45);
    cpy_r_r47 = cpy_r_r46 >= 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 134, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r48 = cpy_r_r46;
    if (!cpy_r_r48) goto CPyL28;
    cpy_r_r49 = CPyStatics[12]; /* ('These Balance objects represent balances from different '
                                   'blocks (') */
    cpy_r_r50 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r50);
    cpy_r_r51 = PyObject_Str(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 136, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r52 = CPyStatics[9]; /* ' and ' */
    cpy_r_r53 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r53);
    cpy_r_r54 = PyObject_Str(cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 136, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r55 = CPyStatics[10]; /* ')' */
    cpy_r_r56 = CPyStr_Build(5, cpy_r_r49, cpy_r_r51, cpy_r_r52, cpy_r_r54, cpy_r_r55);
    CPy_DECREF(cpy_r_r51);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 136, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r57 = CPyModule_builtins;
    cpy_r_r58 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r59 = CPyObject_GetAttr(cpy_r_r57, cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 135, CPyStatic_globals);
        goto CPyL56;
    }
    PyObject *cpy_r_r60[1] = {cpy_r_r56};
    cpy_r_r61 = (PyObject **)&cpy_r_r60;
    cpy_r_r62 = _PyObject_Vectorcall(cpy_r_r59, cpy_r_r61, 1, 0);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 135, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_DECREF(cpy_r_r56);
    CPy_Raise(cpy_r_r62);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 135, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r63 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_balance;
    CPy_INCREF(cpy_r_r63);
    cpy_r_r64 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_balance;
    CPy_INCREF(cpy_r_r64);
    cpy_r_r65 = PyNumber_Add(cpy_r_r63, cpy_r_r64);
    CPy_DECREF(cpy_r_r63);
    CPy_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 140, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL57;
CPyL29: ;
    cpy_r_r66 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_usd_value;
    CPy_INCREF(cpy_r_r66);
    cpy_r_r67 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_usd_value;
    CPy_INCREF(cpy_r_r67);
    cpy_r_r68 = PyNumber_Add(cpy_r_r66, cpy_r_r67);
    CPy_DECREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 141, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL58;
CPyL30: ;
    cpy_r_r69 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_token;
    CPy_INCREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r69);
    cpy_r_r70 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r70);
    CPy_DECREF(cpy_r_r70);
    cpy_r_r71 = CPyDef_Balance();
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 139, CPyStatic_globals);
        goto CPyL32;
    }
    return cpy_r_r71;
CPyL32: ;
    cpy_r_r72 = CPy_CatchError();
    cpy_r_r73 = CPyModule_builtins;
    cpy_r_r74 = CPyStatics[13]; /* 'Exception' */
    cpy_r_r75 = CPyObject_GetAttr(cpy_r_r73, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 145, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r76 = CPy_ExceptionMatches(cpy_r_r75);
    CPy_DecRef(cpy_r_r75);
    if (!cpy_r_r76) goto CPyL46;
    cpy_r_r77 = CPy_GetExcValue();
    cpy_r_r78 = CPyStatics[14]; /* 'Cannot add ' */
    cpy_r_r79 = PyObject_Str(cpy_r_self);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r80 = CPyStatics[9]; /* ' and ' */
    cpy_r_r81 = PyObject_Str(cpy_r_other);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r82 = CPyStatics[15]; /* ': ' */
    cpy_r_r83 = PyObject_Str(cpy_r_r77);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r84 = CPyStr_Build(6, cpy_r_r78, cpy_r_r79, cpy_r_r80, cpy_r_r81, cpy_r_r82, cpy_r_r83);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r81);
    CPy_DecRef(cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r85 = CPyStatics[16]; /* 'args' */
    cpy_r_r86 = CPyObject_GetAttr(cpy_r_r77, cpy_r_r85);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals);
        goto CPyL62;
    }
    if (likely(PyTuple_Check(cpy_r_r86)))
        cpy_r_r87 = cpy_r_r86;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals, "tuple", cpy_r_r86);
        goto CPyL62;
    }
    cpy_r_r88 = PyList_New(1);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r89 = (CPyPtr)&((PyListObject *)cpy_r_r88)->ob_item;
    cpy_r_r90 = *(CPyPtr *)cpy_r_r89;
    *(PyObject * *)cpy_r_r90 = cpy_r_r84;
    cpy_r_r91 = CPyList_Extend(cpy_r_r88, cpy_r_r87);
    CPy_DecRef(cpy_r_r87);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals);
        goto CPyL64;
    } else
        goto CPyL65;
CPyL42: ;
    cpy_r_r92 = PyList_AsTuple(cpy_r_r88);
    CPy_DecRef(cpy_r_r88);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r93 = CPyStatics[16]; /* 'args' */
    cpy_r_r94 = PyObject_SetAttr(cpy_r_r77, cpy_r_r93, cpy_r_r92);
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r92);
    cpy_r_r95 = cpy_r_r94 >= 0;
    if (unlikely(!cpy_r_r95)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 146, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Reraise();
    if (!0) {
        goto CPyL48;
    } else
        goto CPyL66;
CPyL45: ;
    CPy_Unreachable();
CPyL46: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL48;
    } else
        goto CPyL67;
CPyL47: ;
    CPy_Unreachable();
CPyL48: ;
    CPy_RestoreExcInfo(cpy_r_r72);
    CPy_DecRef(cpy_r_r72.f0);
    CPy_DecRef(cpy_r_r72.f1);
    CPy_DecRef(cpy_r_r72.f2);
    cpy_r_r96 = CPy_KeepPropagating();
    if (!cpy_r_r96) goto CPyL50;
    CPy_Unreachable();
CPyL50: ;
    cpy_r_r97 = NULL;
    return cpy_r_r97;
CPyL51: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL50;
CPyL52: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL50;
CPyL53: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL50;
CPyL54: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL50;
CPyL55: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL50;
CPyL56: ;
    CPy_DecRef(cpy_r_r56);
    goto CPyL50;
CPyL57: ;
    CPy_DECREF(cpy_r_r65);
    goto CPyL29;
CPyL58: ;
    CPy_DECREF(cpy_r_r68);
    goto CPyL30;
CPyL59: ;
    CPy_DecRef(cpy_r_r77);
    goto CPyL48;
CPyL60: ;
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r79);
    goto CPyL48;
CPyL61: ;
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r81);
    goto CPyL48;
CPyL62: ;
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r84);
    goto CPyL48;
CPyL63: ;
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r84);
    CPy_DecRef(cpy_r_r87);
    goto CPyL48;
CPyL64: ;
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r88);
    goto CPyL48;
CPyL65: ;
    CPy_DecRef(cpy_r_r91);
    goto CPyL42;
CPyL66: ;
    CPy_DecRef(cpy_r_r72.f0);
    CPy_DecRef(cpy_r_r72.f1);
    CPy_DecRef(cpy_r_r72.f2);
    goto CPyL45;
CPyL67: ;
    CPy_DecRef(cpy_r_r72.f0);
    CPy_DecRef(cpy_r_r72.f1);
    CPy_DecRef(cpy_r_r72.f2);
    goto CPyL47;
}

PyObject *CPyPy_Balance_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Balance))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(Py_TYPE(obj_other) == CPyType_Balance))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_Balance_____add__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 104, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Balance_____radd__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    cpy_r_r0 = CPyStatics[140]; /* 0 */
    cpy_r_r1 = PyObject_RichCompare(cpy_r_other, cpy_r_r0, 2);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__radd__", 169, CPyStatic_globals);
        goto CPyL8;
    }
    if (unlikely(!PyBool_Check(cpy_r_r1))) {
        CPy_TypeError("bool", cpy_r_r1); cpy_r_r2 = 2;
    } else
        cpy_r_r2 = cpy_r_r1 == Py_True;
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__radd__", 169, CPyStatic_globals);
        goto CPyL8;
    }
    if (!cpy_r_r2) goto CPyL4;
    CPy_INCREF(cpy_r_self);
    cpy_r_r3 = cpy_r_self;
    goto CPyL7;
CPyL4: ;
    CPy_INCREF(cpy_r_other);
    if (likely(Py_TYPE(cpy_r_other) == CPyType_Balance))
        cpy_r_r4 = cpy_r_other;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__radd__", 169, CPyStatic_globals, "eth_portfolio.typing.Balance", cpy_r_other);
        goto CPyL8;
    }
    cpy_r_r5 = CPyDef_Balance_____add__(cpy_r_self, cpy_r_r4);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__radd__", 169, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r3 = cpy_r_r5;
CPyL7: ;
    return cpy_r_r3;
CPyL8: ;
    cpy_r_r6 = NULL;
    return cpy_r_r6;
}

PyObject *CPyPy_Balance_____radd__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__radd__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Balance))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (Py_TYPE(obj_other) == CPyType_Balance)
        arg_other = obj_other;
    else {
        arg_other = NULL;
    }
    if (arg_other != NULL) goto __LL15;
    if (PyLong_Check(obj_other))
        arg_other = obj_other;
    else {
        arg_other = NULL;
    }
    if (arg_other != NULL) goto __LL15;
    CPy_TypeError("union[eth_portfolio.typing.Balance, int]", obj_other); 
    goto fail;
__LL15: ;
    PyObject *retval = CPyDef_Balance_____radd__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__radd__", 149, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Balance_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
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
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    int32_t cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
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
    PyObject **cpy_r_r61;
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
    tuple_T3OOO cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    char cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject **cpy_r_r87;
    PyObject *cpy_r_r88;
    char cpy_r_r89;
    PyObject *cpy_r_r90;
    cpy_r_r0 = (PyObject *)CPyType_Balance;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 194, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r11 = CPyStatics[17]; /* ' is not a `Balance` object.' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 194, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 194, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 194, CPyStatic_globals);
        goto CPyL47;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 194, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 194, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_token;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_token;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PyObject_RichCompare(cpy_r_r23, cpy_r_r24, 3);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 195, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r26 = PyObject_IsTrue(cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r27 = cpy_r_r26 >= 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 195, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r28 = cpy_r_r26;
    if (!cpy_r_r28) goto CPyL18;
    cpy_r_r29 = CPyStatics[8]; /* ('These Balance objects represent balances of different '
                                  'tokens (') */
    cpy_r_r30 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_token;
    CPy_INCREF(cpy_r_r30);
    cpy_r_r31 = PyObject_Str(cpy_r_r30);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 197, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r32 = CPyStatics[9]; /* ' and ' */
    cpy_r_r33 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_token;
    CPy_INCREF(cpy_r_r33);
    cpy_r_r34 = PyObject_Str(cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 197, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r35 = CPyStatics[10]; /* ')' */
    cpy_r_r36 = CPyStr_Build(5, cpy_r_r29, cpy_r_r31, cpy_r_r32, cpy_r_r34, cpy_r_r35);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 197, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r37 = CPyModule_builtins;
    cpy_r_r38 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 196, CPyStatic_globals);
        goto CPyL49;
    }
    PyObject *cpy_r_r40[1] = {cpy_r_r36};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = _PyObject_Vectorcall(cpy_r_r39, cpy_r_r41, 1, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 196, CPyStatic_globals);
        goto CPyL49;
    }
    CPy_DECREF(cpy_r_r36);
    CPy_Raise(cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 196, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r43 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r43);
    cpy_r_r44 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r44);
    cpy_r_r45 = PyObject_RichCompare(cpy_r_r43, cpy_r_r44, 3);
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 199, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r46 = PyObject_IsTrue(cpy_r_r45);
    CPy_DECREF(cpy_r_r45);
    cpy_r_r47 = cpy_r_r46 >= 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 199, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r48 = cpy_r_r46;
    if (!cpy_r_r48) goto CPyL28;
    cpy_r_r49 = CPyStatics[12]; /* ('These Balance objects represent balances from different '
                                   'blocks (') */
    cpy_r_r50 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r50);
    cpy_r_r51 = PyObject_Str(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 201, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r52 = CPyStatics[9]; /* ' and ' */
    cpy_r_r53 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r53);
    cpy_r_r54 = PyObject_Str(cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 201, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r55 = CPyStatics[10]; /* ')' */
    cpy_r_r56 = CPyStr_Build(5, cpy_r_r49, cpy_r_r51, cpy_r_r52, cpy_r_r54, cpy_r_r55);
    CPy_DECREF(cpy_r_r51);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 201, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r57 = CPyModule_builtins;
    cpy_r_r58 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r59 = CPyObject_GetAttr(cpy_r_r57, cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 200, CPyStatic_globals);
        goto CPyL51;
    }
    PyObject *cpy_r_r60[1] = {cpy_r_r56};
    cpy_r_r61 = (PyObject **)&cpy_r_r60;
    cpy_r_r62 = _PyObject_Vectorcall(cpy_r_r59, cpy_r_r61, 1, 0);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 200, CPyStatic_globals);
        goto CPyL51;
    }
    CPy_DECREF(cpy_r_r56);
    CPy_Raise(cpy_r_r62);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 200, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r63 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_balance;
    CPy_INCREF(cpy_r_r63);
    cpy_r_r64 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_balance;
    CPy_INCREF(cpy_r_r64);
    cpy_r_r65 = PyNumber_Subtract(cpy_r_r63, cpy_r_r64);
    CPy_DECREF(cpy_r_r63);
    CPy_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 205, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL52;
CPyL29: ;
    cpy_r_r66 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_usd_value;
    CPy_INCREF(cpy_r_r66);
    cpy_r_r67 = ((eth_portfolio___typing___BalanceObject *)cpy_r_other)->_usd_value;
    CPy_INCREF(cpy_r_r67);
    cpy_r_r68 = PyNumber_Subtract(cpy_r_r66, cpy_r_r67);
    CPy_DECREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 206, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL53;
CPyL30: ;
    cpy_r_r69 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_token;
    CPy_INCREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r69);
    cpy_r_r70 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r70);
    CPy_DECREF(cpy_r_r70);
    cpy_r_r71 = CPyDef_Balance();
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 204, CPyStatic_globals);
        goto CPyL32;
    }
    return cpy_r_r71;
CPyL32: ;
    cpy_r_r72 = CPy_CatchError();
    cpy_r_r73 = CPyModule_builtins;
    cpy_r_r74 = CPyStatics[13]; /* 'Exception' */
    cpy_r_r75 = CPyObject_GetAttr(cpy_r_r73, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 210, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r76 = CPy_ExceptionMatches(cpy_r_r75);
    CPy_DecRef(cpy_r_r75);
    if (!cpy_r_r76) goto CPyL41;
    cpy_r_r77 = CPy_GetExcValue();
    cpy_r_r78 = CPyStatics[18]; /* 'Cannot subtract ' */
    cpy_r_r79 = PyObject_Str(cpy_r_self);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 211, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r80 = CPyStatics[9]; /* ' and ' */
    cpy_r_r81 = PyObject_Str(cpy_r_other);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 211, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r82 = CPyStatics[15]; /* ': ' */
    cpy_r_r83 = PyObject_Str(cpy_r_r77);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 211, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r84 = CPyStr_Build(6, cpy_r_r78, cpy_r_r79, cpy_r_r80, cpy_r_r81, cpy_r_r82, cpy_r_r83);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r81);
    CPy_DecRef(cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 211, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r85 = CPyStatics[19]; /* '__class__' */
    PyObject *cpy_r_r86[2] = {cpy_r_r77, cpy_r_r84};
    cpy_r_r87 = (PyObject **)&cpy_r_r86;
    cpy_r_r88 = PyObject_VectorcallMethod(cpy_r_r85, cpy_r_r87, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 211, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r84);
    CPy_Raise(cpy_r_r88);
    CPy_DecRef(cpy_r_r88);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 211, CPyStatic_globals);
        goto CPyL43;
    } else
        goto CPyL58;
CPyL40: ;
    CPy_Unreachable();
CPyL41: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL43;
    } else
        goto CPyL59;
CPyL42: ;
    CPy_Unreachable();
CPyL43: ;
    CPy_RestoreExcInfo(cpy_r_r72);
    CPy_DecRef(cpy_r_r72.f0);
    CPy_DecRef(cpy_r_r72.f1);
    CPy_DecRef(cpy_r_r72.f2);
    cpy_r_r89 = CPy_KeepPropagating();
    if (!cpy_r_r89) goto CPyL45;
    CPy_Unreachable();
CPyL45: ;
    cpy_r_r90 = NULL;
    return cpy_r_r90;
CPyL46: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL45;
CPyL47: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL45;
CPyL48: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL45;
CPyL49: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL45;
CPyL50: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL45;
CPyL51: ;
    CPy_DecRef(cpy_r_r56);
    goto CPyL45;
CPyL52: ;
    CPy_DECREF(cpy_r_r65);
    goto CPyL29;
CPyL53: ;
    CPy_DECREF(cpy_r_r68);
    goto CPyL30;
CPyL54: ;
    CPy_DecRef(cpy_r_r77);
    goto CPyL43;
CPyL55: ;
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r79);
    goto CPyL43;
CPyL56: ;
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r81);
    goto CPyL43;
CPyL57: ;
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r84);
    goto CPyL43;
CPyL58: ;
    CPy_DecRef(cpy_r_r72.f0);
    CPy_DecRef(cpy_r_r72.f1);
    CPy_DecRef(cpy_r_r72.f2);
    goto CPyL40;
CPyL59: ;
    CPy_DecRef(cpy_r_r72.f0);
    CPy_DecRef(cpy_r_r72.f1);
    CPy_DecRef(cpy_r_r72.f2);
    goto CPyL42;
}

PyObject *CPyPy_Balance_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__sub__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Balance))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(Py_TYPE(obj_other) == CPyType_Balance))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_Balance_____sub__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 171, CPyStatic_globals);
    return NULL;
}

char CPyDef_Balance_____bool__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    cpy_r_r0 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_balance;
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = CPyStatics[140]; /* 0 */
    cpy_r_r2 = PyObject_RichCompare(cpy_r_r0, cpy_r_r1, 3);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 225, CPyStatic_globals);
        goto CPyL8;
    }
    if (unlikely(!PyBool_Check(cpy_r_r2))) {
        CPy_TypeError("bool", cpy_r_r2); cpy_r_r3 = 2;
    } else
        cpy_r_r3 = cpy_r_r2 == Py_True;
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 225, CPyStatic_globals);
        goto CPyL8;
    }
    if (!cpy_r_r3) goto CPyL4;
    cpy_r_r4 = cpy_r_r3;
    goto CPyL7;
CPyL4: ;
    cpy_r_r5 = ((eth_portfolio___typing___BalanceObject *)cpy_r_self)->_usd_value;
    CPy_INCREF(cpy_r_r5);
    cpy_r_r6 = CPyStatics[140]; /* 0 */
    cpy_r_r7 = PyObject_RichCompare(cpy_r_r5, cpy_r_r6, 3);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 225, CPyStatic_globals);
        goto CPyL8;
    }
    if (unlikely(!PyBool_Check(cpy_r_r7))) {
        CPy_TypeError("bool", cpy_r_r7); cpy_r_r8 = 2;
    } else
        cpy_r_r8 = cpy_r_r7 == Py_True;
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 225, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r4 = cpy_r_r8;
CPyL7: ;
    return cpy_r_r4;
CPyL8: ;
    cpy_r_r9 = 2;
    return cpy_r_r9;
}

PyObject *CPyPy_Balance_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__bool__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Balance))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj_self); 
        goto fail;
    }
    char retval = CPyDef_Balance_____bool__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 213, CPyStatic_globals);
    return NULL;
}

char CPyDef_Balance_____mypyc_defaults_setup(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[20]; /* 'Decimal' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL5;
    cpy_r_r3 = CPyStatics[140]; /* 0 */
    PyObject *cpy_r_r4[1] = {cpy_r_r3};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r2);
    if (cpy_r_r6 == NULL) goto CPyL5;
    ((eth_portfolio___typing___BalanceObject *)cpy_r___mypyc_self__)->_balance = cpy_r_r6;
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyStatics[20]; /* 'Decimal' */
    cpy_r_r9 = CPyDict_GetItem(cpy_r_r7, cpy_r_r8);
    if (cpy_r_r9 == NULL) goto CPyL5;
    cpy_r_r10 = CPyStatics[140]; /* 0 */
    PyObject *cpy_r_r11[1] = {cpy_r_r10};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r12, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (cpy_r_r13 == NULL) goto CPyL5;
    ((eth_portfolio___typing___BalanceObject *)cpy_r___mypyc_self__)->_usd_value = cpy_r_r13;
    cpy_r_r14 = Py_None;
    CPy_INCREF(cpy_r_r14);
    ((eth_portfolio___typing___BalanceObject *)cpy_r___mypyc_self__)->_token = cpy_r_r14;
    cpy_r_r15 = Py_None;
    CPy_INCREF(cpy_r_r15);
    ((eth_portfolio___typing___BalanceObject *)cpy_r___mypyc_self__)->_block = cpy_r_r15;
    return 1;
CPyL5: ;
    cpy_r_r16 = 2;
    return cpy_r_r16;
}

PyObject *CPyPy_Balance_____mypyc_defaults_setup(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__mypyc_defaults_setup", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__;
    if (likely(Py_TYPE(obj___mypyc_self__) == CPyType_Balance))
        arg___mypyc_self__ = obj___mypyc_self__;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj___mypyc_self__); 
        goto fail;
    }
    char retval = CPyDef_Balance_____mypyc_defaults_setup(arg___mypyc_self__);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__mypyc_defaults_setup", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__SummableNonNumericMixin_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[21]; /* 'NotImplementedError' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 254, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_Raise(cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 254, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_Unreachable();
CPyL3: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy__SummableNonNumericMixin_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyObject_TypeCheck(obj_self, CPyType__SummableNonNumericMixin)))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyObject_TypeCheck(obj_other, CPyType__SummableNonNumericMixin)))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef__SummableNonNumericMixin_____add__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 241, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef__SummableNonNumericMixin_____radd__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    cpy_r_r0 = CPyStatics[140]; /* 0 */
    cpy_r_r1 = PyObject_RichCompare(cpy_r_other, cpy_r_r0, 2);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__radd__", 280, CPyStatic_globals);
        goto CPyL8;
    }
    if (unlikely(!PyBool_Check(cpy_r_r1))) {
        CPy_TypeError("bool", cpy_r_r1); cpy_r_r2 = 2;
    } else
        cpy_r_r2 = cpy_r_r1 == Py_True;
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__radd__", 280, CPyStatic_globals);
        goto CPyL8;
    }
    if (!cpy_r_r2) goto CPyL4;
    CPy_INCREF(cpy_r_self);
    cpy_r_r3 = cpy_r_self;
    goto CPyL7;
CPyL4: ;
    CPy_INCREF(cpy_r_other);
    if (likely(PyObject_TypeCheck(cpy_r_other, CPyType__SummableNonNumericMixin)))
        cpy_r_r4 = cpy_r_other;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__radd__", 280, CPyStatic_globals, "eth_portfolio.typing._SummableNonNumericMixin", cpy_r_other);
        goto CPyL8;
    }
    cpy_r_r5 = CPY_GET_METHOD(cpy_r_self, CPyType__SummableNonNumericMixin, 0, eth_portfolio___typing____SummableNonNumericMixinObject, PyObject * (*)(PyObject *, PyObject *))(cpy_r_self, cpy_r_r4); /* __add__ */
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__radd__", 280, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r3 = cpy_r_r5;
CPyL7: ;
    return cpy_r_r3;
CPyL8: ;
    cpy_r_r6 = NULL;
    return cpy_r_r6;
}

PyObject *CPyPy__SummableNonNumericMixin_____radd__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__radd__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyObject_TypeCheck(obj_self, CPyType__SummableNonNumericMixin)))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (PyObject_TypeCheck(obj_other, CPyType__SummableNonNumericMixin))
        arg_other = obj_other;
    else {
        arg_other = NULL;
    }
    if (arg_other != NULL) goto __LL16;
    if (PyLong_Check(obj_other))
        arg_other = obj_other;
    else {
        arg_other = NULL;
    }
    if (arg_other != NULL) goto __LL16;
    CPy_TypeError("union[eth_portfolio.typing._SummableNonNumericMixin, int]", obj_other); 
    goto fail;
__LL16: ;
    PyObject *retval = CPyDef__SummableNonNumericMixin_____radd__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__radd__", 256, CPyStatic_globals);
    return NULL;
}

char CPyDef_TokenBalances_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    int32_t cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    CPyTagged cpy_r_r22;
    int64_t cpy_r_r23;
    CPyTagged cpy_r_r24;
    PyObject *cpy_r_r25;
    tuple_T4CIOO cpy_r_r26;
    CPyTagged cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_token;
    PyObject *cpy_r_balance;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    char cpy_r_r34;
    char cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_r37;
    int32_t cpy_r_r38;
    char cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    CPyTagged cpy_r_r42;
    CPyPtr cpy_r_r43;
    int64_t cpy_r_r44;
    CPyTagged cpy_r_r45;
    char cpy_r_r46;
    int64_t cpy_r_r47;
    CPyPtr cpy_r_r48;
    CPyPtr cpy_r_r49;
    int64_t cpy_r_r50;
    CPyPtr cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    char cpy_r_r57;
    PyObject *cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    char cpy_r_r63;
    CPyTagged cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    char cpy_r_r74;
    if (cpy_r_seed != NULL) goto CPyL49;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_seed = cpy_r_r0;
CPyL2: ;
    if (cpy_r_block != NULL) goto CPyL50;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_block = cpy_r_r1;
CPyL4: ;
    cpy_r_r2 = CPyModule_builtins;
    cpy_r_r3 = CPyStatics[22]; /* 'super' */
    cpy_r_r4 = CPyObject_GetAttr(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 308, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r5 = (PyObject *)CPyType_TokenBalances;
    PyObject *cpy_r_r6[2] = {cpy_r_r5, cpy_r_self};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r7, 2, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 308, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r9 = CPyStatics[23]; /* '__init__' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 308, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r11 = (PyObject *)CPyType_Balance;
    PyObject *cpy_r_r12[1] = {cpy_r_r11};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = _PyObject_Vectorcall(cpy_r_r10, cpy_r_r13, 1, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 308, CPyStatic_globals);
        goto CPyL51;
    } else
        goto CPyL52;
CPyL8: ;
    ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block = cpy_r_block;
    cpy_r_r15 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r16 = cpy_r_seed == cpy_r_r15;
    if (cpy_r_r16) {
        goto CPyL53;
    } else
        goto CPyL10;
CPyL9: ;
    return 1;
CPyL10: ;
    cpy_r_r17 = (PyObject *)&PyDict_Type;
    cpy_r_r18 = PyObject_IsInstance(cpy_r_seed, cpy_r_r17);
    cpy_r_r19 = cpy_r_r18 >= 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 312, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r20 = cpy_r_r18;
    if (!cpy_r_r20) goto CPyL21;
    if (likely(PyDict_Check(cpy_r_seed)))
        cpy_r_r21 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 313, CPyStatic_globals, "dict", cpy_r_seed);
        goto CPyL48;
    }
    cpy_r_r22 = 0;
    cpy_r_r23 = PyDict_Size(cpy_r_r21);
    cpy_r_r24 = cpy_r_r23 << 1;
    cpy_r_r25 = CPyDict_GetItemsIter(cpy_r_r21);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 313, CPyStatic_globals);
        goto CPyL55;
    }
CPyL14: ;
    cpy_r_r26 = CPyDict_NextItem(cpy_r_r25, cpy_r_r22);
    cpy_r_r27 = cpy_r_r26.f1;
    cpy_r_r22 = cpy_r_r27;
    cpy_r_r28 = cpy_r_r26.f0;
    if (!cpy_r_r28) goto CPyL56;
    cpy_r_r29 = cpy_r_r26.f2;
    CPy_INCREF(cpy_r_r29);
    cpy_r_r30 = cpy_r_r26.f3;
    CPy_INCREF(cpy_r_r30);
    CPy_DECREF(cpy_r_r26.f2);
    CPy_DECREF(cpy_r_r26.f3);
    cpy_r_token = cpy_r_r29;
    cpy_r_balance = cpy_r_r30;
    cpy_r_r31 = CPyDef_TokenBalances_____getitem__(cpy_r_self, cpy_r_token);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 314, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r32 = PyNumber_InPlaceAdd(cpy_r_r31, cpy_r_balance);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 314, CPyStatic_globals);
        goto CPyL58;
    }
    if (likely(Py_TYPE(cpy_r_r32) == CPyType_Balance))
        cpy_r_r33 = cpy_r_r32;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 314, CPyStatic_globals, "eth_portfolio.typing.Balance", cpy_r_r32);
        goto CPyL58;
    }
    cpy_r_r34 = CPyDef_TokenBalances_____setitem__(cpy_r_self, cpy_r_token, cpy_r_r33);
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r34 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 314, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r35 = CPyDict_CheckSize(cpy_r_r21, cpy_r_r24);
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 313, CPyStatic_globals);
        goto CPyL59;
    } else
        goto CPyL14;
CPyL20: ;
    cpy_r_r36 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 313, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL47;
CPyL21: ;
    cpy_r_r37 = (PyObject *)&PyList_Type;
    cpy_r_r38 = PyObject_IsInstance(cpy_r_seed, cpy_r_r37);
    cpy_r_r39 = cpy_r_r38 >= 0;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 315, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r40 = cpy_r_r38;
    if (!cpy_r_r40) goto CPyL41;
    if (likely(PyList_Check(cpy_r_seed)))
        cpy_r_r41 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 316, CPyStatic_globals, "list", cpy_r_seed);
        goto CPyL48;
    }
    cpy_r_r42 = 0;
CPyL25: ;
    cpy_r_r43 = (CPyPtr)&((PyVarObject *)cpy_r_r41)->ob_size;
    cpy_r_r44 = *(int64_t *)cpy_r_r43;
    cpy_r_r45 = cpy_r_r44 << 1;
    cpy_r_r46 = (Py_ssize_t)cpy_r_r42 < (Py_ssize_t)cpy_r_r45;
    if (!cpy_r_r46) goto CPyL60;
    cpy_r_r47 = (Py_ssize_t)cpy_r_r42 >> 1;
    cpy_r_r48 = (CPyPtr)&((PyListObject *)cpy_r_r41)->ob_item;
    cpy_r_r49 = *(CPyPtr *)cpy_r_r48;
    cpy_r_r50 = cpy_r_r47 * 8;
    cpy_r_r51 = cpy_r_r49 + cpy_r_r50;
    cpy_r_r52 = *(PyObject * *)cpy_r_r51;
    CPy_INCREF(cpy_r_r52);
    cpy_r_r53 = PyObject_GetIter(cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 316, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r54 = PyIter_Next(cpy_r_r53);
    if (cpy_r_r54 == NULL) {
        goto CPyL62;
    } else
        goto CPyL30;
CPyL28: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r55 = 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 316, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL30: ;
    cpy_r_token = cpy_r_r54;
    cpy_r_r56 = PyIter_Next(cpy_r_r53);
    if (cpy_r_r56 == NULL) {
        goto CPyL63;
    } else
        goto CPyL33;
CPyL31: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r57 = 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 316, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL33: ;
    cpy_r_balance = cpy_r_r56;
    cpy_r_r58 = PyIter_Next(cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    if (cpy_r_r58 == NULL) {
        goto CPyL36;
    } else
        goto CPyL64;
CPyL34: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r59 = 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 316, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL36: ;
    cpy_r_r60 = CPyDef_TokenBalances_____getitem__(cpy_r_self, cpy_r_token);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 317, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r61 = PyNumber_InPlaceAdd(cpy_r_r60, cpy_r_balance);
    CPy_DECREF(cpy_r_r60);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 317, CPyStatic_globals);
        goto CPyL66;
    }
    if (likely(Py_TYPE(cpy_r_r61) == CPyType_Balance))
        cpy_r_r62 = cpy_r_r61;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 317, CPyStatic_globals, "eth_portfolio.typing.Balance", cpy_r_r61);
        goto CPyL66;
    }
    cpy_r_r63 = CPyDef_TokenBalances_____setitem__(cpy_r_self, cpy_r_token, cpy_r_r62);
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(cpy_r_r63 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 317, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r64 = cpy_r_r42 + 2;
    cpy_r_r42 = cpy_r_r64;
    goto CPyL25;
CPyL41: ;
    cpy_r_r65 = PyObject_Str(cpy_r_seed);
    CPy_DECREF(cpy_r_seed);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 319, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r66 = CPyStatics[24]; /* ' is not a valid input for TokenBalances' */
    cpy_r_r67 = CPyStr_Build(2, cpy_r_r65, cpy_r_r66);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 319, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r68 = CPyModule_builtins;
    cpy_r_r69 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r70 = CPyObject_GetAttr(cpy_r_r68, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 319, CPyStatic_globals);
        goto CPyL67;
    }
    PyObject *cpy_r_r71[1] = {cpy_r_r67};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = _PyObject_Vectorcall(cpy_r_r70, cpy_r_r72, 1, 0);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 319, CPyStatic_globals);
        goto CPyL67;
    }
    CPy_DECREF(cpy_r_r67);
    CPy_Raise(cpy_r_r73);
    CPy_DECREF(cpy_r_r73);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 319, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_Unreachable();
CPyL47: ;
    return 1;
CPyL48: ;
    cpy_r_r74 = 2;
    return cpy_r_r74;
CPyL49: ;
    CPy_INCREF(cpy_r_seed);
    goto CPyL2;
CPyL50: ;
    CPy_INCREF(cpy_r_block);
    goto CPyL4;
CPyL51: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_block);
    goto CPyL48;
CPyL52: ;
    CPy_DECREF(cpy_r_r14);
    goto CPyL8;
CPyL53: ;
    CPy_DECREF(cpy_r_seed);
    goto CPyL9;
CPyL54: ;
    CPy_DecRef(cpy_r_seed);
    goto CPyL48;
CPyL55: ;
    CPy_DecRef(cpy_r_r21);
    goto CPyL48;
CPyL56: ;
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r26.f2);
    CPy_DECREF(cpy_r_r26.f3);
    goto CPyL20;
CPyL57: ;
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_balance);
    goto CPyL48;
CPyL58: ;
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_token);
    goto CPyL48;
CPyL59: ;
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r25);
    goto CPyL48;
CPyL60: ;
    CPy_DECREF(cpy_r_r41);
    goto CPyL47;
CPyL61: ;
    CPy_DecRef(cpy_r_r41);
    goto CPyL48;
CPyL62: ;
    CPy_DECREF(cpy_r_r41);
    CPy_DECREF(cpy_r_r53);
    goto CPyL28;
CPyL63: ;
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_r41);
    CPy_DECREF(cpy_r_r53);
    goto CPyL31;
CPyL64: ;
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_balance);
    CPy_DECREF(cpy_r_r41);
    CPy_DECREF(cpy_r_r58);
    goto CPyL34;
CPyL65: ;
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_balance);
    CPy_DecRef(cpy_r_r41);
    goto CPyL48;
CPyL66: ;
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_r41);
    goto CPyL48;
CPyL67: ;
    CPy_DecRef(cpy_r_r67);
    goto CPyL48;
}

PyObject *CPyPy_TokenBalances_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"seed", "block", 0};
    PyObject *obj_seed = NULL;
    PyObject *obj_block = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|O$O", "__init__", kwlist, &obj_seed, &obj_block)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_seed;
    if (obj_seed == NULL) {
        arg_seed = NULL;
        goto __LL17;
    }
    if (PyDict_Check(obj_seed))
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL17;
    arg_seed = obj_seed;
    if (arg_seed != NULL) goto __LL17;
    if (obj_seed == Py_None)
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL17;
    CPy_TypeError("union[dict, object, None]", obj_seed); 
    goto fail;
__LL17: ;
    PyObject *arg_block;
    if (obj_block == NULL) {
        arg_block = NULL;
        goto __LL18;
    }
    if (PyLong_Check(obj_block))
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL18;
    if (obj_block == Py_None)
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL18;
    CPy_TypeError("int or None", obj_block); 
    goto fail;
__LL18: ;
    char retval = CPyDef_TokenBalances_____init__(arg_self, arg_seed, arg_block);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 307, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_TokenBalances_____getitem__(PyObject *cpy_r_self, PyObject *cpy_r_key) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    int32_t cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    cpy_r_r0 = CPyStatics[25]; /* '__contains__' */
    PyObject *cpy_r_r1[2] = {cpy_r_self, cpy_r_key};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 322, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r4 = PyObject_IsTrue(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    cpy_r_r5 = cpy_r_r4 >= 0;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 322, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r6 = cpy_r_r4;
    if (!cpy_r_r6) goto CPyL8;
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[22]; /* 'super' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 322, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r10 = (PyObject *)CPyType_TokenBalances;
    PyObject *cpy_r_r11[2] = {cpy_r_r10, cpy_r_self};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r12, 2, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 322, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r14 = CPyStatics[26]; /* '__getitem__' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r13, cpy_r_r14);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 322, CPyStatic_globals);
        goto CPyL12;
    }
    PyObject *cpy_r_r16[1] = {cpy_r_key};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = _PyObject_Vectorcall(cpy_r_r15, cpy_r_r17, 1, 0);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 322, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r19 = cpy_r_r18;
    goto CPyL10;
CPyL8: ;
    cpy_r_r20 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyDef_Balance();
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 322, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r19 = cpy_r_r21;
CPyL10: ;
    if (likely(Py_TYPE(cpy_r_r19) == CPyType_Balance))
        cpy_r_r22 = cpy_r_r19;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__getitem__", 322, CPyStatic_globals, "eth_portfolio.typing.Balance", cpy_r_r19);
        goto CPyL12;
    }
    return cpy_r_r22;
CPyL12: ;
    cpy_r_r23 = NULL;
    return cpy_r_r23;
}

PyObject *CPyPy_TokenBalances_____getitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", 0};
    static CPyArg_Parser parser = {"O:__getitem__", kwlist, 0};
    PyObject *obj_key;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_key)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    PyObject *retval = CPyDef_TokenBalances_____getitem__(arg_self, arg_key);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 321, CPyStatic_globals);
    return NULL;
}

char CPyDef_TokenBalances_____setitem__(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    char cpy_r_r35;
    cpy_r_r0 = (PyObject *)CPyType_Balance;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_value)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[27]; /* 'value must be a `Balance` object. You passed ' */
    cpy_r_r6 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r7 = CPyStatics[3]; /* '' */
    cpy_r_r8 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r9[3] = {cpy_r_r6, cpy_r_value, cpy_r_r7};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = PyObject_VectorcallMethod(cpy_r_r8, cpy_r_r10, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 342, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 342, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    CPy_INCREF(cpy_r_r5);
    *(PyObject * *)cpy_r_r14 = cpy_r_r5;
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 342, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 342, CPyStatic_globals);
        goto CPyL15;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 342, CPyStatic_globals);
        goto CPyL15;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 342, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = CPyModule_builtins;
    cpy_r_r24 = CPyStatics[22]; /* 'super' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 343, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r26 = (PyObject *)CPyType_TokenBalances;
    PyObject *cpy_r_r27[2] = {cpy_r_r26, cpy_r_self};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = _PyObject_Vectorcall(cpy_r_r25, cpy_r_r28, 2, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 343, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r30 = CPyStatics[28]; /* '__setitem__' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 343, CPyStatic_globals);
        goto CPyL13;
    }
    PyObject *cpy_r_r32[2] = {cpy_r_key, cpy_r_value};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = _PyObject_Vectorcall(cpy_r_r31, cpy_r_r33, 2, 0);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 343, CPyStatic_globals);
        goto CPyL13;
    } else
        goto CPyL16;
CPyL12: ;
    return 1;
CPyL13: ;
    cpy_r_r35 = 2;
    return cpy_r_r35;
CPyL14: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL13;
CPyL15: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL13;
CPyL16: ;
    CPy_DECREF(cpy_r_r34);
    goto CPyL12;
}

PyObject *CPyPy_TokenBalances_____setitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", "value", 0};
    static CPyArg_Parser parser = {"OO:__setitem__", kwlist, 0};
    PyObject *obj_key;
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_key, &obj_value)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    PyObject *arg_value;
    if (likely(Py_TYPE(obj_value) == CPyType_Balance))
        arg_value = obj_value;
    else {
        CPy_TypeError("eth_portfolio.typing.Balance", obj_value); 
        goto fail;
    }
    char retval = CPyDef_TokenBalances_____setitem__(arg_self, arg_key, arg_value);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 324, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_TokenBalances___dataframe(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    int32_t cpy_r_r21;
    char cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject **cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    cpy_r_r0 = PyDict_New();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 354, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r1 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r2[1] = {cpy_r_self};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r3, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 356, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r5 = PyObject_GetIter(cpy_r_r4);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 354, CPyStatic_globals);
        goto CPyL27;
    }
CPyL3: ;
    cpy_r_r6 = PyIter_Next(cpy_r_r5);
    if (cpy_r_r6 == NULL) goto CPyL28;
    cpy_r_r7 = PyObject_GetIter(cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 354, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r8 = PyIter_Next(cpy_r_r7);
    if (cpy_r_r8 == NULL) {
        goto CPyL30;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r9 = 0;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 354, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r10 = PyIter_Next(cpy_r_r7);
    if (cpy_r_r10 == NULL) {
        goto CPyL31;
    } else
        goto CPyL11;
CPyL9: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r11 = 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 354, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r12 = PyIter_Next(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (cpy_r_r12 == NULL) {
        goto CPyL14;
    } else
        goto CPyL32;
CPyL12: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r13 = 0;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 354, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_Unreachable();
CPyL14: ;
    cpy_r_r14 = CPyStatics[30]; /* 'balance' */
    cpy_r_r15 = CPyStatics[30]; /* 'balance' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 355, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r17 = CPyStatics[31]; /* 'usd_value' */
    cpy_r_r18 = CPyStatics[31]; /* 'usd_value' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r18);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 355, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r20 = CPyDict_Build(2, cpy_r_r14, cpy_r_r16, cpy_r_r17, cpy_r_r19);
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 355, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r21 = CPyDict_SetItem(cpy_r_r0, cpy_r_r8, cpy_r_r20);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r22 = cpy_r_r21 >= 0;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 354, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL3;
CPyL18: ;
    cpy_r_r23 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 354, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r24 = CPyStatic_globals;
    cpy_r_r25 = CPyStatics[32]; /* 'DataFrame' */
    cpy_r_r26 = CPyDict_GetItem(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 353, CPyStatic_globals);
        goto CPyL27;
    }
    PyObject *cpy_r_r27[1] = {cpy_r_r0};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = _PyObject_Vectorcall(cpy_r_r26, cpy_r_r28, 1, 0);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 353, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_DECREF(cpy_r_r0);
    cpy_r_r30 = CPyStatics[33]; /* 'T' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 353, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r32 = CPyStatics[34]; /* 'reset_index' */
    cpy_r_r33 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r34[2] = {cpy_r_r31, cpy_r_r33};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = CPyStatics[141]; /* ('inplace',) */
    cpy_r_r37 = PyObject_VectorcallMethod(cpy_r_r32, cpy_r_r35, 9223372036854775809ULL, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 359, CPyStatic_globals);
        goto CPyL36;
    } else
        goto CPyL37;
CPyL23: ;
    cpy_r_r38 = CPyStatics[36]; /* 'index' */
    cpy_r_r39 = CPyStatics[37]; /* 'token' */
    cpy_r_r40 = CPyDict_Build(1, cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 360, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r41 = CPyStatics[38]; /* 'rename' */
    cpy_r_r42 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r43[3] = {cpy_r_r31, cpy_r_r40, cpy_r_r42};
    cpy_r_r44 = (PyObject **)&cpy_r_r43;
    cpy_r_r45 = CPyStatics[142]; /* ('columns', 'inplace') */
    cpy_r_r46 = PyObject_VectorcallMethod(cpy_r_r41, cpy_r_r44, 9223372036854775809ULL, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 360, CPyStatic_globals);
        goto CPyL38;
    } else
        goto CPyL39;
CPyL25: ;
    CPy_DECREF(cpy_r_r40);
    return cpy_r_r31;
CPyL26: ;
    cpy_r_r47 = NULL;
    return cpy_r_r47;
CPyL27: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL26;
CPyL28: ;
    CPy_DECREF(cpy_r_r5);
    goto CPyL18;
CPyL29: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    goto CPyL26;
CPyL30: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r7);
    goto CPyL6;
CPyL31: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r8);
    goto CPyL9;
CPyL32: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r12);
    goto CPyL12;
CPyL33: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r10);
    goto CPyL26;
CPyL34: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r16);
    goto CPyL26;
CPyL35: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r8);
    goto CPyL26;
CPyL36: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL26;
CPyL37: ;
    CPy_DECREF(cpy_r_r37);
    goto CPyL23;
CPyL38: ;
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r40);
    goto CPyL26;
CPyL39: ;
    CPy_DECREF(cpy_r_r46);
    goto CPyL25;
}

PyObject *CPyPy_TokenBalances___dataframe(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":dataframe", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_TokenBalances___dataframe(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 346, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_TokenBalances___sum_usd(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    cpy_r_r0 = CPyStatics[140]; /* 0 */
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = CPyStatics[40]; /* 'values' */
    PyObject *cpy_r_r3[1] = {cpy_r_self};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_VectorcallMethod(cpy_r_r2, cpy_r_r4, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 376, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r6 = PyObject_GetIter(cpy_r_r5);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 376, CPyStatic_globals);
        goto CPyL11;
    }
CPyL2: ;
    cpy_r_r7 = PyIter_Next(cpy_r_r6);
    if (cpy_r_r7 == NULL) goto CPyL12;
    cpy_r_r8 = CPyStatics[41]; /* 'usd' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 376, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r10 = PyNumber_Add(cpy_r_r1, cpy_r_r9);
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", -1, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r1 = cpy_r_r10;
    goto CPyL2;
CPyL6: ;
    cpy_r_r11 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 376, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r12 = CPyStatic_globals;
    cpy_r_r13 = CPyStatics[20]; /* 'Decimal' */
    cpy_r_r14 = CPyDict_GetItem(cpy_r_r12, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 376, CPyStatic_globals);
        goto CPyL11;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_r1};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r14, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 376, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r1);
    return cpy_r_r17;
CPyL10: ;
    cpy_r_r18 = NULL;
    return cpy_r_r18;
CPyL11: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL10;
CPyL12: ;
    CPy_DECREF(cpy_r_r6);
    goto CPyL6;
CPyL13: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r6);
    goto CPyL10;
CPyL14: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL10;
}

PyObject *CPyPy_TokenBalances___sum_usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":sum_usd", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_TokenBalances___sum_usd(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 363, CPyStatic_globals);
    return NULL;
}

char CPyDef_TokenBalances_____bool__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    cpy_r_r0 = CPyStatics[40]; /* 'values' */
    PyObject *cpy_r_r1[1] = {cpy_r_self};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 390, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[42]; /* 'any' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 390, CPyStatic_globals);
        goto CPyL6;
    }
    PyObject *cpy_r_r7[1] = {cpy_r_r3};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 1, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 390, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r3);
    if (unlikely(!PyBool_Check(cpy_r_r9))) {
        CPy_TypeError("bool", cpy_r_r9); cpy_r_r10 = 2;
    } else
        cpy_r_r10 = cpy_r_r9 == Py_True;
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 390, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r10;
CPyL5: ;
    cpy_r_r11 = 2;
    return cpy_r_r11;
CPyL6: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL5;
}

PyObject *CPyPy_TokenBalances_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__bool__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    char retval = CPyDef_TokenBalances_____bool__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 378, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_TokenBalances_____repr__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[43]; /* 'TokenBalances' */
    cpy_r_r1 = CPyDict_FromAny(cpy_r_self);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 399, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r2 = PyObject_Str(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 399, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r3 = CPyStr_Build(2, cpy_r_r0, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 399, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy_TokenBalances_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__repr__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_TokenBalances_____repr__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 392, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_TokenBalances_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
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
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_token;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_balance;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    int32_t cpy_r_r57;
    char cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject **cpy_r_r68;
    PyObject *cpy_r_r69;
    char cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject **cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    char cpy_r_r79;
    PyObject *cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    char cpy_r_r83;
    int32_t cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject **cpy_r_r89;
    PyObject *cpy_r_r90;
    int32_t cpy_r_r91;
    char cpy_r_r92;
    char cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject **cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject **cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject **cpy_r_r111;
    PyObject *cpy_r_r112;
    char cpy_r_r113;
    PyObject *cpy_r_r114;
    cpy_r_r0 = (PyObject *)CPyType_TokenBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 422, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r11 = CPyStatics[44]; /* ' is not a TokenBalances object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 422, CPyStatic_globals);
        goto CPyL70;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 422, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 422, CPyStatic_globals);
        goto CPyL71;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 422, CPyStatic_globals);
        goto CPyL71;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 422, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PyObject_RichCompare(cpy_r_r23, cpy_r_r24, 3);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 423, CPyStatic_globals);
        goto CPyL69;
    }
    if (unlikely(!PyBool_Check(cpy_r_r25))) {
        CPy_TypeError("bool", cpy_r_r25); cpy_r_r26 = 2;
    } else
        cpy_r_r26 = cpy_r_r25 == Py_True;
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 423, CPyStatic_globals);
        goto CPyL69;
    }
    if (!cpy_r_r26) goto CPyL18;
    cpy_r_r27 = CPyStatics[45]; /* 'These TokenBalances objects are not from the same block (' */
    cpy_r_r28 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r28);
    cpy_r_r29 = PyObject_Str(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 425, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r30 = CPyStatics[9]; /* ' and ' */
    cpy_r_r31 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r31);
    cpy_r_r32 = PyObject_Str(cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 425, CPyStatic_globals);
        goto CPyL72;
    }
    cpy_r_r33 = CPyStatics[10]; /* ')' */
    cpy_r_r34 = CPyStr_Build(5, cpy_r_r27, cpy_r_r29, cpy_r_r30, cpy_r_r32, cpy_r_r33);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 425, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 424, CPyStatic_globals);
        goto CPyL73;
    }
    PyObject *cpy_r_r38[1] = {cpy_r_r34};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r39, 1, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 424, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_DECREF(cpy_r_r34);
    CPy_Raise(cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 424, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r41 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42 = NULL;
    cpy_r_r43 = CPyDef_TokenBalances(cpy_r_r42, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 428, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r44 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r45[1] = {cpy_r_self};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = PyObject_VectorcallMethod(cpy_r_r44, cpy_r_r46, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 429, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r48 = PyObject_GetIter(cpy_r_r47);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 429, CPyStatic_globals);
        goto CPyL74;
    }
CPyL21: ;
    cpy_r_r49 = PyIter_Next(cpy_r_r48);
    if (cpy_r_r49 == NULL) goto CPyL75;
    cpy_r_r50 = PyObject_GetIter(cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 429, CPyStatic_globals);
        goto CPyL76;
    }
    cpy_r_r51 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r51 == NULL) {
        goto CPyL77;
    } else
        goto CPyL26;
CPyL24: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r52 = 0;
    if (unlikely(!cpy_r_r52)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 429, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_token = cpy_r_r51;
    cpy_r_r53 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r53 == NULL) {
        goto CPyL78;
    } else
        goto CPyL29;
CPyL27: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r54 = 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 429, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_Unreachable();
CPyL29: ;
    cpy_r_balance = cpy_r_r53;
    cpy_r_r55 = PyIter_Next(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (cpy_r_r55 == NULL) {
        goto CPyL32;
    } else
        goto CPyL79;
CPyL30: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r56 = 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 429, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_Unreachable();
CPyL32: ;
    cpy_r_r57 = PyObject_IsTrue(cpy_r_balance);
    cpy_r_r58 = cpy_r_r57 >= 0;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 429, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r59 = cpy_r_r57;
    if (!cpy_r_r59) goto CPyL81;
    cpy_r_r60 = CPyStatics[30]; /* 'balance' */
    cpy_r_r61 = CPyObject_GetAttr(cpy_r_balance, cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 433, CPyStatic_globals);
        goto CPyL80;
    } else
        goto CPyL82;
CPyL35: ;
    cpy_r_r62 = CPyStatics[31]; /* 'usd_value' */
    cpy_r_r63 = CPyObject_GetAttr(cpy_r_balance, cpy_r_r62);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 433, CPyStatic_globals);
        goto CPyL83;
    } else
        goto CPyL84;
CPyL36: ;
    cpy_r_r64 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r64);
    CPy_DECREF(cpy_r_r64);
    cpy_r_r65 = CPyDef_Balance();
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 433, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r66 = CPyStatics[46]; /* '_setitem_nochecksum' */
    PyObject *cpy_r_r67[3] = {cpy_r_r43, cpy_r_token, cpy_r_r65};
    cpy_r_r68 = (PyObject **)&cpy_r_r67;
    cpy_r_r69 = PyObject_VectorcallMethod(cpy_r_r66, cpy_r_r68, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 431, CPyStatic_globals);
        goto CPyL85;
    } else
        goto CPyL86;
CPyL38: ;
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_r65);
    goto CPyL21;
CPyL39: ;
    cpy_r_r70 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 429, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r71 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r72[1] = {cpy_r_other};
    cpy_r_r73 = (PyObject **)&cpy_r_r72;
    cpy_r_r74 = PyObject_VectorcallMethod(cpy_r_r71, cpy_r_r73, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 435, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r75 = PyObject_GetIter(cpy_r_r74);
    CPy_DECREF(cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 435, CPyStatic_globals);
        goto CPyL74;
    }
CPyL42: ;
    cpy_r_r76 = PyIter_Next(cpy_r_r75);
    if (cpy_r_r76 == NULL) goto CPyL87;
    cpy_r_r77 = PyObject_GetIter(cpy_r_r76);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 435, CPyStatic_globals);
        goto CPyL88;
    }
    cpy_r_r78 = PyIter_Next(cpy_r_r77);
    if (cpy_r_r78 == NULL) {
        goto CPyL89;
    } else
        goto CPyL47;
CPyL45: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r79 = 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 435, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_Unreachable();
CPyL47: ;
    cpy_r_token = cpy_r_r78;
    cpy_r_r80 = PyIter_Next(cpy_r_r77);
    if (cpy_r_r80 == NULL) {
        goto CPyL90;
    } else
        goto CPyL50;
CPyL48: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r81 = 0;
    if (unlikely(!cpy_r_r81)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 435, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_Unreachable();
CPyL50: ;
    cpy_r_balance = cpy_r_r80;
    cpy_r_r82 = PyIter_Next(cpy_r_r77);
    CPy_DECREF(cpy_r_r77);
    if (cpy_r_r82 == NULL) {
        goto CPyL53;
    } else
        goto CPyL91;
CPyL51: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r83 = 0;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 435, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_Unreachable();
CPyL53: ;
    cpy_r_r84 = PyObject_IsTrue(cpy_r_balance);
    cpy_r_r85 = cpy_r_r84 >= 0;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 429, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r86 = cpy_r_r84;
    if (!cpy_r_r86) goto CPyL93;
    cpy_r_r87 = CPyStatics[25]; /* '__contains__' */
    PyObject *cpy_r_r88[2] = {cpy_r_r43, cpy_r_token};
    cpy_r_r89 = (PyObject **)&cpy_r_r88;
    cpy_r_r90 = PyObject_VectorcallMethod(cpy_r_r87, cpy_r_r89, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 437, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r91 = PyObject_IsTrue(cpy_r_r90);
    CPy_DECREF(cpy_r_r90);
    cpy_r_r92 = cpy_r_r91 >= 0;
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 437, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r93 = cpy_r_r91;
    if (!cpy_r_r93) goto CPyL62;
    cpy_r_r94 = CPyStatics[47]; /* '_getitem_nochecksum' */
    PyObject *cpy_r_r95[2] = {cpy_r_r43, cpy_r_token};
    cpy_r_r96 = (PyObject **)&cpy_r_r95;
    cpy_r_r97 = PyObject_VectorcallMethod(cpy_r_r94, cpy_r_r96, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 439, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r98 = PyNumber_Add(cpy_r_r97, cpy_r_balance);
    CPy_DECREF(cpy_r_r97);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 439, CPyStatic_globals);
        goto CPyL94;
    }
    cpy_r_r99 = CPyStatics[46]; /* '_setitem_nochecksum' */
    PyObject *cpy_r_r100[3] = {cpy_r_r43, cpy_r_token, cpy_r_r98};
    cpy_r_r101 = (PyObject **)&cpy_r_r100;
    cpy_r_r102 = PyObject_VectorcallMethod(cpy_r_r99, cpy_r_r101, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 438, CPyStatic_globals);
        goto CPyL95;
    } else
        goto CPyL96;
CPyL61: ;
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_r98);
    goto CPyL42;
CPyL62: ;
    cpy_r_r103 = CPyStatics[30]; /* 'balance' */
    cpy_r_r104 = CPyObject_GetAttr(cpy_r_balance, cpy_r_r103);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 444, CPyStatic_globals);
        goto CPyL92;
    } else
        goto CPyL97;
CPyL63: ;
    cpy_r_r105 = CPyStatics[31]; /* 'usd_value' */
    cpy_r_r106 = CPyObject_GetAttr(cpy_r_balance, cpy_r_r105);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 444, CPyStatic_globals);
        goto CPyL94;
    } else
        goto CPyL98;
CPyL64: ;
    cpy_r_r107 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r107);
    CPy_DECREF(cpy_r_r107);
    cpy_r_r108 = CPyDef_Balance();
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 444, CPyStatic_globals);
        goto CPyL94;
    }
    cpy_r_r109 = CPyStatics[46]; /* '_setitem_nochecksum' */
    PyObject *cpy_r_r110[3] = {cpy_r_r43, cpy_r_token, cpy_r_r108};
    cpy_r_r111 = (PyObject **)&cpy_r_r110;
    cpy_r_r112 = PyObject_VectorcallMethod(cpy_r_r109, cpy_r_r111, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 442, CPyStatic_globals);
        goto CPyL99;
    } else
        goto CPyL100;
CPyL66: ;
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_r108);
    goto CPyL42;
CPyL67: ;
    cpy_r_r113 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r113)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 435, CPyStatic_globals);
        goto CPyL74;
    }
    return cpy_r_r43;
CPyL69: ;
    cpy_r_r114 = NULL;
    return cpy_r_r114;
CPyL70: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL69;
CPyL71: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL69;
CPyL72: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL69;
CPyL73: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL69;
CPyL74: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL69;
CPyL75: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL39;
CPyL76: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    goto CPyL69;
CPyL77: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    goto CPyL24;
CPyL78: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    CPy_DECREF(cpy_r_token);
    goto CPyL27;
CPyL79: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_balance);
    CPy_DECREF(cpy_r_r55);
    goto CPyL30;
CPyL80: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_balance);
    goto CPyL69;
CPyL81: ;
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_balance);
    goto CPyL21;
CPyL82: ;
    CPy_DECREF(cpy_r_r61);
    goto CPyL35;
CPyL83: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_token);
    goto CPyL69;
CPyL84: ;
    CPy_DECREF(cpy_r_r63);
    goto CPyL36;
CPyL85: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_r65);
    goto CPyL69;
CPyL86: ;
    CPy_DECREF(cpy_r_r69);
    goto CPyL38;
CPyL87: ;
    CPy_DECREF(cpy_r_r75);
    goto CPyL67;
CPyL88: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r75);
    goto CPyL69;
CPyL89: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r77);
    goto CPyL45;
CPyL90: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r77);
    goto CPyL48;
CPyL91: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_balance);
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r82);
    goto CPyL51;
CPyL92: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_balance);
    CPy_DecRef(cpy_r_r75);
    goto CPyL69;
CPyL93: ;
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_balance);
    goto CPyL42;
CPyL94: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_r75);
    goto CPyL69;
CPyL95: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r98);
    goto CPyL69;
CPyL96: ;
    CPy_DECREF(cpy_r_r102);
    goto CPyL61;
CPyL97: ;
    CPy_DECREF(cpy_r_r104);
    goto CPyL63;
CPyL98: ;
    CPy_DECREF(cpy_r_r106);
    goto CPyL64;
CPyL99: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r108);
    goto CPyL69;
CPyL100: ;
    CPy_DECREF(cpy_r_r112);
    goto CPyL66;
}

PyObject *CPyPy_TokenBalances_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(Py_TYPE(obj_other) == CPyType_TokenBalances))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_TokenBalances_____add__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 401, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_TokenBalances_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPy_INCREF(cpy_r_other);
    if (likely(Py_TYPE(cpy_r_other) == CPyType_TokenBalances))
        cpy_r_r0 = cpy_r_other;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", cpy_r_other); 
        cpy_r_r0 = NULL;
    }
    if (cpy_r_r0 == NULL) goto CPyL3;
    cpy_r_r1 = CPyDef_TokenBalances_____add__(cpy_r_self, cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL3;
    return cpy_r_r1;
CPyL3: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_TokenBalances_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add_____SummableNonNumericMixin_glue", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyObject_TypeCheck(obj_other, CPyType__SummableNonNumericMixin)))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_TokenBalances_____add___3___SummableNonNumericMixin_glue(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add_____SummableNonNumericMixin_glue", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_TokenBalances_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
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
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject **cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_token;
    PyObject *cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_balance;
    PyObject *cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    char cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    CPyTagged cpy_r_r62;
    int64_t cpy_r_r63;
    CPyTagged cpy_r_r64;
    PyObject *cpy_r_r65;
    tuple_T4CIOO cpy_r_r66;
    CPyTagged cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    int32_t cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    int32_t cpy_r_r75;
    char cpy_r_r76;
    char cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    cpy_r_r0 = (PyObject *)CPyType_TokenBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 469, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r11 = CPyStatics[44]; /* ' is not a TokenBalances object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 469, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 469, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 469, CPyStatic_globals);
        goto CPyL49;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 469, CPyStatic_globals);
        goto CPyL49;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 469, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PyObject_RichCompare(cpy_r_r23, cpy_r_r24, 3);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 470, CPyStatic_globals);
        goto CPyL47;
    }
    if (unlikely(!PyBool_Check(cpy_r_r25))) {
        CPy_TypeError("bool", cpy_r_r25); cpy_r_r26 = 2;
    } else
        cpy_r_r26 = cpy_r_r25 == Py_True;
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 470, CPyStatic_globals);
        goto CPyL47;
    }
    if (!cpy_r_r26) goto CPyL18;
    cpy_r_r27 = CPyStatics[45]; /* 'These TokenBalances objects are not from the same block (' */
    cpy_r_r28 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r28);
    cpy_r_r29 = PyObject_Str(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 472, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r30 = CPyStatics[9]; /* ' and ' */
    cpy_r_r31 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r31);
    cpy_r_r32 = PyObject_Str(cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 472, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r33 = CPyStatics[10]; /* ')' */
    cpy_r_r34 = CPyStr_Build(5, cpy_r_r27, cpy_r_r29, cpy_r_r30, cpy_r_r32, cpy_r_r33);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 472, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 471, CPyStatic_globals);
        goto CPyL51;
    }
    PyObject *cpy_r_r38[1] = {cpy_r_r34};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r39, 1, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 471, CPyStatic_globals);
        goto CPyL51;
    }
    CPy_DECREF(cpy_r_r34);
    CPy_Raise(cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 471, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r41 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42 = CPyDef_TokenBalances(cpy_r_self, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 475, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r43 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r44[1] = {cpy_r_other};
    cpy_r_r45 = (PyObject **)&cpy_r_r44;
    cpy_r_r46 = PyObject_VectorcallMethod(cpy_r_r43, cpy_r_r45, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 476, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r47 = PyObject_GetIter(cpy_r_r46);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 476, CPyStatic_globals);
        goto CPyL52;
    }
CPyL21: ;
    cpy_r_r48 = PyIter_Next(cpy_r_r47);
    if (cpy_r_r48 == NULL) goto CPyL53;
    cpy_r_r49 = PyObject_GetIter(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 476, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r50 = PyIter_Next(cpy_r_r49);
    if (cpy_r_r50 == NULL) {
        goto CPyL55;
    } else
        goto CPyL26;
CPyL24: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r51 = 0;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 476, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_token = cpy_r_r50;
    cpy_r_r52 = PyIter_Next(cpy_r_r49);
    if (cpy_r_r52 == NULL) {
        goto CPyL56;
    } else
        goto CPyL29;
CPyL27: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r53 = 0;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 476, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_Unreachable();
CPyL29: ;
    cpy_r_balance = cpy_r_r52;
    cpy_r_r54 = PyIter_Next(cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (cpy_r_r54 == NULL) {
        goto CPyL32;
    } else
        goto CPyL57;
CPyL30: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r55 = 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 476, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_Unreachable();
CPyL32: ;
    cpy_r_r56 = CPyDef_TokenBalances_____getitem__(cpy_r_r42, cpy_r_token);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 477, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r57 = PyNumber_InPlaceSubtract(cpy_r_r56, cpy_r_balance);
    CPy_DECREF(cpy_r_r56);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 477, CPyStatic_globals);
        goto CPyL59;
    }
    if (likely(Py_TYPE(cpy_r_r57) == CPyType_Balance))
        cpy_r_r58 = cpy_r_r57;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 477, CPyStatic_globals, "eth_portfolio.typing.Balance", cpy_r_r57);
        goto CPyL59;
    }
    cpy_r_r59 = CPyDef_TokenBalances_____setitem__(cpy_r_r42, cpy_r_token, cpy_r_r58);
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r59 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 477, CPyStatic_globals);
        goto CPyL54;
    } else
        goto CPyL21;
CPyL36: ;
    cpy_r_r60 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 476, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r61 = CPyDict_FromAny(cpy_r_r42);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 478, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r62 = 0;
    cpy_r_r63 = PyDict_Size(cpy_r_r61);
    cpy_r_r64 = cpy_r_r63 << 1;
    cpy_r_r65 = CPyDict_GetItemsIter(cpy_r_r61);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 478, CPyStatic_globals);
        goto CPyL60;
    }
CPyL39: ;
    cpy_r_r66 = CPyDict_NextItem(cpy_r_r65, cpy_r_r62);
    cpy_r_r67 = cpy_r_r66.f1;
    cpy_r_r62 = cpy_r_r67;
    cpy_r_r68 = cpy_r_r66.f0;
    if (!cpy_r_r68) goto CPyL61;
    cpy_r_r69 = cpy_r_r66.f2;
    CPy_INCREF(cpy_r_r69);
    cpy_r_r70 = cpy_r_r66.f3;
    CPy_INCREF(cpy_r_r70);
    CPy_DECREF(cpy_r_r66.f2);
    CPy_DECREF(cpy_r_r66.f3);
    if (likely(Py_TYPE(cpy_r_r70) == CPyType_Balance))
        cpy_r_r71 = cpy_r_r70;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 478, CPyStatic_globals, "eth_portfolio.typing.Balance", cpy_r_r70);
        goto CPyL62;
    }
    cpy_r_token = cpy_r_r69;
    cpy_r_balance = cpy_r_r71;
    cpy_r_r72 = PyObject_IsTrue(cpy_r_balance);
    CPy_DECREF(cpy_r_balance);
    cpy_r_r73 = cpy_r_r72 >= 0;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 476, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r74 = cpy_r_r72;
    if (cpy_r_r74) goto CPyL64;
    cpy_r_r75 = PyObject_DelItem(cpy_r_r42, cpy_r_token);
    CPy_DECREF(cpy_r_token);
    cpy_r_r76 = cpy_r_r75 >= 0;
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 480, CPyStatic_globals);
        goto CPyL65;
    }
CPyL44: ;
    cpy_r_r77 = CPyDict_CheckSize(cpy_r_r61, cpy_r_r64);
    if (unlikely(!cpy_r_r77)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 478, CPyStatic_globals);
        goto CPyL65;
    } else
        goto CPyL39;
CPyL45: ;
    cpy_r_r78 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 478, CPyStatic_globals);
        goto CPyL52;
    }
    return cpy_r_r42;
CPyL47: ;
    cpy_r_r79 = NULL;
    return cpy_r_r79;
CPyL48: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL47;
CPyL49: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL47;
CPyL50: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL47;
CPyL51: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL47;
CPyL52: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL47;
CPyL53: ;
    CPy_DECREF(cpy_r_r47);
    goto CPyL36;
CPyL54: ;
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_r47);
    goto CPyL47;
CPyL55: ;
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r47);
    CPy_DECREF(cpy_r_r49);
    goto CPyL24;
CPyL56: ;
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r47);
    CPy_DECREF(cpy_r_r49);
    CPy_DECREF(cpy_r_token);
    goto CPyL27;
CPyL57: ;
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r47);
    CPy_DECREF(cpy_r_token);
    CPy_DECREF(cpy_r_balance);
    CPy_DECREF(cpy_r_r54);
    goto CPyL30;
CPyL58: ;
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_r47);
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_balance);
    goto CPyL47;
CPyL59: ;
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_r47);
    CPy_DecRef(cpy_r_token);
    goto CPyL47;
CPyL60: ;
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_r61);
    goto CPyL47;
CPyL61: ;
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r65);
    CPy_DECREF(cpy_r_r66.f2);
    CPy_DECREF(cpy_r_r66.f3);
    goto CPyL45;
CPyL62: ;
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r65);
    CPy_DecRef(cpy_r_r69);
    goto CPyL47;
CPyL63: ;
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_token);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r65);
    goto CPyL47;
CPyL64: ;
    CPy_DECREF(cpy_r_token);
    goto CPyL44;
CPyL65: ;
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r65);
    goto CPyL47;
}

PyObject *CPyPy_TokenBalances_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__sub__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_TokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(Py_TYPE(obj_other) == CPyType_TokenBalances))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_TokenBalances_____sub__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 448, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = ((eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("eth_portfolio\\typing.py", "<lambda>", "__mypyc_lambda__0___init___RemoteTokenBalances_obj", "__mypyc_env__", 507, CPyStatic_globals);
        goto CPyL4;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *)cpy_r_r0)->_block;
    if (unlikely(cpy_r_r1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'block' of '__init___RemoteTokenBalances_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r1);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 507, CPyStatic_globals);
        goto CPyL4;
    }
CPyL2: ;
    cpy_r_r2 = NULL;
    cpy_r_r3 = CPyDef_TokenBalances(cpy_r_r2, cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 507, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__call__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, PyVectorcall_NARGS(nargs), kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *retval = CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 507, CPyStatic_globals);
    return NULL;
}

char CPyDef_RemoteTokenBalances_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    int32_t cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    int32_t cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    CPyTagged cpy_r_r29;
    int64_t cpy_r_r30;
    CPyTagged cpy_r_r31;
    PyObject *cpy_r_r32;
    tuple_T4CIOO cpy_r_r33;
    CPyTagged cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_remote;
    PyObject *cpy_r_token_balances;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
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
    PyObject **cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    int32_t cpy_r_r64;
    char cpy_r_r65;
    char cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    int32_t cpy_r_r69;
    char cpy_r_r70;
    char cpy_r_r71;
    PyObject *cpy_r_r72;
    CPyTagged cpy_r_r73;
    CPyPtr cpy_r_r74;
    int64_t cpy_r_r75;
    CPyTagged cpy_r_r76;
    char cpy_r_r77;
    int64_t cpy_r_r78;
    CPyPtr cpy_r_r79;
    CPyPtr cpy_r_r80;
    int64_t cpy_r_r81;
    CPyPtr cpy_r_r82;
    PyObject *cpy_r_r83;
    tuple_T2OO cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    char cpy_r_r92;
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
    PyObject **cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    int32_t cpy_r_r111;
    char cpy_r_r112;
    CPyTagged cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject **cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    CPyPtr cpy_r_r123;
    CPyPtr cpy_r_r124;
    CPyPtr cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject **cpy_r_r131;
    PyObject *cpy_r_r132;
    char cpy_r_r133;
    if (cpy_r_seed != NULL) goto CPyL75;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_seed = cpy_r_r0;
CPyL2: ;
    if (cpy_r_block != NULL) goto CPyL76;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_block = cpy_r_r1;
CPyL4: ;
    cpy_r_r2 = CPyDef___init___3_RemoteTokenBalances_env();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 506, CPyStatic_globals);
        goto CPyL77;
    }
    if (((eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *)cpy_r_r2)->_block != NULL) {
        CPy_DECREF(((eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *)cpy_r_r2)->_block);
    }
    ((eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *)cpy_r_r2)->_block = cpy_r_block;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 506, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[22]; /* 'super' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 507, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r7 = (PyObject *)CPyType_RemoteTokenBalances;
    PyObject *cpy_r_r8[2] = {cpy_r_r7, cpy_r_self};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r9, 2, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 507, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r11 = CPyStatics[23]; /* '__init__' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 507, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r13 = CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj();
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 507, CPyStatic_globals);
        goto CPyL79;
    }
    CPy_INCREF(cpy_r_r2);
    if (((eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *)cpy_r_r13)->___mypyc_env__ != NULL) {
        CPy_DECREF(((eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *)cpy_r_r13)->___mypyc_env__);
    }
    ((eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject *)cpy_r_r13)->___mypyc_env__ = cpy_r_r2;
    cpy_r_r14 = 1;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 507, CPyStatic_globals);
        goto CPyL80;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_r13};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 507, CPyStatic_globals);
        goto CPyL81;
    } else
        goto CPyL82;
CPyL12: ;
    CPy_DECREF(cpy_r_r13);
    cpy_r_r18 = ((eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r18 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'block' of '__init___RemoteTokenBalances_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r18);
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 508, CPyStatic_globals);
        goto CPyL83;
    }
CPyL13: ;
    cpy_r_r19 = CPyStatics[48]; /* 'block' */
    cpy_r_r20 = PyObject_SetAttr(cpy_r_self, cpy_r_r19, cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r21 = cpy_r_r20 >= 0;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 508, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r22 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r23 = cpy_r_seed == cpy_r_r22;
    if (cpy_r_r23) {
        goto CPyL84;
    } else
        goto CPyL16;
CPyL15: ;
    return 1;
CPyL16: ;
    cpy_r_r24 = (PyObject *)&PyDict_Type;
    cpy_r_r25 = PyObject_IsInstance(cpy_r_seed, cpy_r_r24);
    cpy_r_r26 = cpy_r_r25 >= 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 511, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r27 = cpy_r_r25;
    if (!cpy_r_r27) goto CPyL42;
    if (likely(PyDict_Check(cpy_r_seed)))
        cpy_r_r28 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 512, CPyStatic_globals, "dict", cpy_r_seed);
        goto CPyL74;
    }
    cpy_r_r29 = 0;
    cpy_r_r30 = PyDict_Size(cpy_r_r28);
    cpy_r_r31 = cpy_r_r30 << 1;
    cpy_r_r32 = CPyDict_GetItemsIter(cpy_r_r28);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 512, CPyStatic_globals);
        goto CPyL85;
    }
CPyL20: ;
    cpy_r_r33 = CPyDict_NextItem(cpy_r_r32, cpy_r_r29);
    cpy_r_r34 = cpy_r_r33.f1;
    cpy_r_r29 = cpy_r_r34;
    cpy_r_r35 = cpy_r_r33.f0;
    if (!cpy_r_r35) goto CPyL86;
    cpy_r_r36 = cpy_r_r33.f2;
    CPy_INCREF(cpy_r_r36);
    cpy_r_r37 = cpy_r_r33.f3;
    CPy_INCREF(cpy_r_r37);
    CPy_DECREF(cpy_r_r33.f2);
    CPy_DECREF(cpy_r_r33.f3);
    if (likely(PyUnicode_Check(cpy_r_r36)))
        cpy_r_r38 = cpy_r_r36;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 512, CPyStatic_globals, "str", cpy_r_r36);
        goto CPyL87;
    }
    if (likely(Py_TYPE(cpy_r_r37) == CPyType_TokenBalances))
        cpy_r_r39 = cpy_r_r37;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 512, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r37);
        goto CPyL88;
    }
    cpy_r_remote = cpy_r_r38;
    cpy_r_token_balances = cpy_r_r39;
    cpy_r_r40 = CPyStatics[48]; /* 'block' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_self, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 513, CPyStatic_globals);
        goto CPyL89;
    }
    if (PyLong_Check(cpy_r_r41))
        cpy_r_r42 = cpy_r_r41;
    else {
        cpy_r_r42 = NULL;
    }
    if (cpy_r_r42 != NULL) goto __LL19;
    if (cpy_r_r41 == Py_None)
        cpy_r_r42 = cpy_r_r41;
    else {
        cpy_r_r42 = NULL;
    }
    if (cpy_r_r42 != NULL) goto __LL19;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 513, CPyStatic_globals, "int or None", cpy_r_r41);
    goto CPyL89;
__LL19: ;
    cpy_r_r43 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_token_balances)->_block;
    CPy_INCREF(cpy_r_r43);
    cpy_r_r44 = PyObject_RichCompare(cpy_r_r42, cpy_r_r43, 3);
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 513, CPyStatic_globals);
        goto CPyL89;
    }
    if (unlikely(!PyBool_Check(cpy_r_r44))) {
        CPy_TypeError("bool", cpy_r_r44); cpy_r_r45 = 2;
    } else
        cpy_r_r45 = cpy_r_r44 == Py_True;
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 513, CPyStatic_globals);
        goto CPyL89;
    }
    if (cpy_r_r45) {
        goto CPyL90;
    } else
        goto CPyL37;
CPyL28: ;
    cpy_r_r46 = CPyStatics[49]; /* 'These objects are not from the same block (' */
    cpy_r_r47 = CPyStatics[48]; /* 'block' */
    cpy_r_r48 = CPyObject_GetAttr(cpy_r_self, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 515, CPyStatic_globals);
        goto CPyL91;
    }
    if (PyLong_Check(cpy_r_r48))
        cpy_r_r49 = cpy_r_r48;
    else {
        cpy_r_r49 = NULL;
    }
    if (cpy_r_r49 != NULL) goto __LL20;
    if (cpy_r_r48 == Py_None)
        cpy_r_r49 = cpy_r_r48;
    else {
        cpy_r_r49 = NULL;
    }
    if (cpy_r_r49 != NULL) goto __LL20;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 515, CPyStatic_globals, "int or None", cpy_r_r48);
    goto CPyL91;
__LL20: ;
    cpy_r_r50 = PyObject_Str(cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 515, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r51 = CPyStatics[9]; /* ' and ' */
    cpy_r_r52 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_token_balances)->_block;
    CPy_INCREF(cpy_r_r52);
    CPy_DECREF(cpy_r_token_balances);
    cpy_r_r53 = PyObject_Str(cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 515, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r54 = CPyStatics[10]; /* ')' */
    cpy_r_r55 = CPyStr_Build(5, cpy_r_r46, cpy_r_r50, cpy_r_r51, cpy_r_r53, cpy_r_r54);
    CPy_DECREF(cpy_r_r50);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 515, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r56 = CPyModule_builtins;
    cpy_r_r57 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r58 = CPyObject_GetAttr(cpy_r_r56, cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 514, CPyStatic_globals);
        goto CPyL93;
    }
    PyObject *cpy_r_r59[1] = {cpy_r_r55};
    cpy_r_r60 = (PyObject **)&cpy_r_r59;
    cpy_r_r61 = _PyObject_Vectorcall(cpy_r_r58, cpy_r_r60, 1, 0);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 514, CPyStatic_globals);
        goto CPyL93;
    }
    CPy_DECREF(cpy_r_r55);
    CPy_Raise(cpy_r_r61);
    CPy_DECREF(cpy_r_r61);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 514, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL37: ;
    cpy_r_r62 = CPyDict_GetItem(cpy_r_self, cpy_r_remote);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 517, CPyStatic_globals);
        goto CPyL89;
    }
    cpy_r_r63 = PyNumber_InPlaceAdd(cpy_r_r62, cpy_r_token_balances);
    CPy_DECREF(cpy_r_r62);
    CPy_DECREF(cpy_r_token_balances);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 517, CPyStatic_globals);
        goto CPyL94;
    }
    cpy_r_r64 = CPyDict_SetItem(cpy_r_self, cpy_r_remote, cpy_r_r63);
    CPy_DECREF(cpy_r_remote);
    CPy_DECREF(cpy_r_r63);
    cpy_r_r65 = cpy_r_r64 >= 0;
    if (unlikely(!cpy_r_r65)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 517, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r66 = CPyDict_CheckSize(cpy_r_r28, cpy_r_r31);
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 512, CPyStatic_globals);
        goto CPyL95;
    } else
        goto CPyL20;
CPyL41: ;
    cpy_r_r67 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 512, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL73;
CPyL42: ;
    cpy_r_r68 = (PyObject *)&PyList_Type;
    cpy_r_r69 = PyObject_IsInstance(cpy_r_seed, cpy_r_r68);
    cpy_r_r70 = cpy_r_r69 >= 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 518, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r71 = cpy_r_r69;
    if (!cpy_r_r71) goto CPyL66;
    if (likely(PyList_Check(cpy_r_seed)))
        cpy_r_r72 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 519, CPyStatic_globals, "list", cpy_r_seed);
        goto CPyL74;
    }
    cpy_r_r73 = 0;
CPyL46: ;
    cpy_r_r74 = (CPyPtr)&((PyVarObject *)cpy_r_r72)->ob_size;
    cpy_r_r75 = *(int64_t *)cpy_r_r74;
    cpy_r_r76 = cpy_r_r75 << 1;
    cpy_r_r77 = (Py_ssize_t)cpy_r_r73 < (Py_ssize_t)cpy_r_r76;
    if (!cpy_r_r77) goto CPyL96;
    cpy_r_r78 = (Py_ssize_t)cpy_r_r73 >> 1;
    cpy_r_r79 = (CPyPtr)&((PyListObject *)cpy_r_r72)->ob_item;
    cpy_r_r80 = *(CPyPtr *)cpy_r_r79;
    cpy_r_r81 = cpy_r_r78 * 8;
    cpy_r_r82 = cpy_r_r80 + cpy_r_r81;
    cpy_r_r83 = *(PyObject * *)cpy_r_r82;
    CPy_INCREF(cpy_r_r83);
    PyObject *__tmp21;
    if (unlikely(!(PyTuple_Check(cpy_r_r83) && PyTuple_GET_SIZE(cpy_r_r83) == 2))) {
        __tmp21 = NULL;
        goto __LL22;
    }
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r83, 0))))
        __tmp21 = PyTuple_GET_ITEM(cpy_r_r83, 0);
    else {
        __tmp21 = NULL;
    }
    if (__tmp21 == NULL) goto __LL22;
    if (likely(Py_TYPE(PyTuple_GET_ITEM(cpy_r_r83, 1)) == CPyType_TokenBalances))
        __tmp21 = PyTuple_GET_ITEM(cpy_r_r83, 1);
    else {
        __tmp21 = NULL;
    }
    if (__tmp21 == NULL) goto __LL22;
    __tmp21 = cpy_r_r83;
__LL22: ;
    if (unlikely(__tmp21 == NULL)) {
        CPy_TypeError("tuple[str, eth_portfolio.typing.TokenBalances]", cpy_r_r83); cpy_r_r84 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp23 = PyTuple_GET_ITEM(cpy_r_r83, 0);
        CPy_INCREF(__tmp23);
        PyObject *__tmp24;
        if (likely(PyUnicode_Check(__tmp23)))
            __tmp24 = __tmp23;
        else {
            CPy_TypeError("str", __tmp23); 
            __tmp24 = NULL;
        }
        cpy_r_r84.f0 = __tmp24;
        PyObject *__tmp25 = PyTuple_GET_ITEM(cpy_r_r83, 1);
        CPy_INCREF(__tmp25);
        PyObject *__tmp26;
        if (likely(Py_TYPE(__tmp25) == CPyType_TokenBalances))
            __tmp26 = __tmp25;
        else {
            CPy_TypeError("eth_portfolio.typing.TokenBalances", __tmp25); 
            __tmp26 = NULL;
        }
        cpy_r_r84.f1 = __tmp26;
    }
    CPy_DECREF(cpy_r_r83);
    if (unlikely(cpy_r_r84.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 519, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r85 = cpy_r_r84.f0;
    CPy_INCREF(cpy_r_r85);
    cpy_r_remote = cpy_r_r85;
    cpy_r_r86 = cpy_r_r84.f1;
    CPy_INCREF(cpy_r_r86);
    CPy_DECREF(cpy_r_r84.f0);
    CPy_DECREF(cpy_r_r84.f1);
    cpy_r_token_balances = cpy_r_r86;
    cpy_r_r87 = CPyStatics[48]; /* 'block' */
    cpy_r_r88 = CPyObject_GetAttr(cpy_r_self, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 520, CPyStatic_globals);
        goto CPyL98;
    }
    if (PyLong_Check(cpy_r_r88))
        cpy_r_r89 = cpy_r_r88;
    else {
        cpy_r_r89 = NULL;
    }
    if (cpy_r_r89 != NULL) goto __LL27;
    if (cpy_r_r88 == Py_None)
        cpy_r_r89 = cpy_r_r88;
    else {
        cpy_r_r89 = NULL;
    }
    if (cpy_r_r89 != NULL) goto __LL27;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 520, CPyStatic_globals, "int or None", cpy_r_r88);
    goto CPyL98;
__LL27: ;
    cpy_r_r90 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_token_balances)->_block;
    CPy_INCREF(cpy_r_r90);
    cpy_r_r91 = PyObject_RichCompare(cpy_r_r89, cpy_r_r90, 3);
    CPy_DECREF(cpy_r_r89);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 520, CPyStatic_globals);
        goto CPyL98;
    }
    if (unlikely(!PyBool_Check(cpy_r_r91))) {
        CPy_TypeError("bool", cpy_r_r91); cpy_r_r92 = 2;
    } else
        cpy_r_r92 = cpy_r_r91 == Py_True;
    CPy_DECREF(cpy_r_r91);
    if (unlikely(cpy_r_r92 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 520, CPyStatic_globals);
        goto CPyL98;
    }
    if (cpy_r_r92) {
        goto CPyL99;
    } else
        goto CPyL62;
CPyL53: ;
    cpy_r_r93 = CPyStatics[49]; /* 'These objects are not from the same block (' */
    cpy_r_r94 = CPyStatics[48]; /* 'block' */
    cpy_r_r95 = CPyObject_GetAttr(cpy_r_self, cpy_r_r94);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 522, CPyStatic_globals);
        goto CPyL91;
    }
    if (PyLong_Check(cpy_r_r95))
        cpy_r_r96 = cpy_r_r95;
    else {
        cpy_r_r96 = NULL;
    }
    if (cpy_r_r96 != NULL) goto __LL28;
    if (cpy_r_r95 == Py_None)
        cpy_r_r96 = cpy_r_r95;
    else {
        cpy_r_r96 = NULL;
    }
    if (cpy_r_r96 != NULL) goto __LL28;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 522, CPyStatic_globals, "int or None", cpy_r_r95);
    goto CPyL91;
__LL28: ;
    cpy_r_r97 = PyObject_Str(cpy_r_r96);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 522, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r98 = CPyStatics[9]; /* ' and ' */
    cpy_r_r99 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_token_balances)->_block;
    CPy_INCREF(cpy_r_r99);
    CPy_DECREF(cpy_r_token_balances);
    cpy_r_r100 = PyObject_Str(cpy_r_r99);
    CPy_DECREF(cpy_r_r99);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 522, CPyStatic_globals);
        goto CPyL100;
    }
    cpy_r_r101 = CPyStatics[10]; /* ')' */
    cpy_r_r102 = CPyStr_Build(5, cpy_r_r93, cpy_r_r97, cpy_r_r98, cpy_r_r100, cpy_r_r101);
    CPy_DECREF(cpy_r_r97);
    CPy_DECREF(cpy_r_r100);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 522, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r103 = CPyModule_builtins;
    cpy_r_r104 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r105 = CPyObject_GetAttr(cpy_r_r103, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 521, CPyStatic_globals);
        goto CPyL101;
    }
    PyObject *cpy_r_r106[1] = {cpy_r_r102};
    cpy_r_r107 = (PyObject **)&cpy_r_r106;
    cpy_r_r108 = _PyObject_Vectorcall(cpy_r_r105, cpy_r_r107, 1, 0);
    CPy_DECREF(cpy_r_r105);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 521, CPyStatic_globals);
        goto CPyL101;
    }
    CPy_DECREF(cpy_r_r102);
    CPy_Raise(cpy_r_r108);
    CPy_DECREF(cpy_r_r108);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 521, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL62: ;
    cpy_r_r109 = CPyDict_GetItem(cpy_r_self, cpy_r_remote);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 524, CPyStatic_globals);
        goto CPyL98;
    }
    cpy_r_r110 = PyNumber_InPlaceAdd(cpy_r_r109, cpy_r_token_balances);
    CPy_DECREF(cpy_r_r109);
    CPy_DECREF(cpy_r_token_balances);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 524, CPyStatic_globals);
        goto CPyL102;
    }
    cpy_r_r111 = CPyDict_SetItem(cpy_r_self, cpy_r_remote, cpy_r_r110);
    CPy_DECREF(cpy_r_remote);
    CPy_DECREF(cpy_r_r110);
    cpy_r_r112 = cpy_r_r111 >= 0;
    if (unlikely(!cpy_r_r112)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 524, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r113 = cpy_r_r73 + 2;
    cpy_r_r73 = cpy_r_r113;
    goto CPyL46;
CPyL66: ;
    cpy_r_r114 = CPyStatics[3]; /* '' */
    cpy_r_r115 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r116 = CPyStatics[3]; /* '' */
    cpy_r_r117 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r118[3] = {cpy_r_r115, cpy_r_seed, cpy_r_r116};
    cpy_r_r119 = (PyObject **)&cpy_r_r118;
    cpy_r_r120 = PyObject_VectorcallMethod(cpy_r_r117, cpy_r_r119, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 526, CPyStatic_globals);
        goto CPyL83;
    }
    CPy_DECREF(cpy_r_seed);
    cpy_r_r121 = CPyStatics[24]; /* ' is not a valid input for TokenBalances' */
    cpy_r_r122 = PyList_New(2);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 526, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_r123 = (CPyPtr)&((PyListObject *)cpy_r_r122)->ob_item;
    cpy_r_r124 = *(CPyPtr *)cpy_r_r123;
    *(PyObject * *)cpy_r_r124 = cpy_r_r120;
    CPy_INCREF(cpy_r_r121);
    cpy_r_r125 = cpy_r_r124 + 8;
    *(PyObject * *)cpy_r_r125 = cpy_r_r121;
    cpy_r_r126 = PyUnicode_Join(cpy_r_r114, cpy_r_r122);
    CPy_DECREF(cpy_r_r122);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 526, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r127 = CPyModule_builtins;
    cpy_r_r128 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r129 = CPyObject_GetAttr(cpy_r_r127, cpy_r_r128);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 526, CPyStatic_globals);
        goto CPyL104;
    }
    PyObject *cpy_r_r130[1] = {cpy_r_r126};
    cpy_r_r131 = (PyObject **)&cpy_r_r130;
    cpy_r_r132 = _PyObject_Vectorcall(cpy_r_r129, cpy_r_r131, 1, 0);
    CPy_DECREF(cpy_r_r129);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 526, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_DECREF(cpy_r_r126);
    CPy_Raise(cpy_r_r132);
    CPy_DECREF(cpy_r_r132);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 526, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL73: ;
    return 1;
CPyL74: ;
    cpy_r_r133 = 2;
    return cpy_r_r133;
CPyL75: ;
    CPy_INCREF(cpy_r_seed);
    goto CPyL2;
CPyL76: ;
    CPy_INCREF(cpy_r_block);
    goto CPyL4;
CPyL77: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_block);
    goto CPyL74;
CPyL78: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    goto CPyL74;
CPyL79: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    goto CPyL74;
CPyL80: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r13);
    goto CPyL74;
CPyL81: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r13);
    goto CPyL74;
CPyL82: ;
    CPy_DECREF(cpy_r_r17);
    goto CPyL12;
CPyL83: ;
    CPy_DecRef(cpy_r_seed);
    goto CPyL74;
CPyL84: ;
    CPy_DECREF(cpy_r_seed);
    goto CPyL15;
CPyL85: ;
    CPy_DecRef(cpy_r_r28);
    goto CPyL74;
CPyL86: ;
    CPy_DECREF(cpy_r_r28);
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r33.f2);
    CPy_DECREF(cpy_r_r33.f3);
    goto CPyL41;
CPyL87: ;
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_r37);
    goto CPyL74;
CPyL88: ;
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_r38);
    goto CPyL74;
CPyL89: ;
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_remote);
    CPy_DecRef(cpy_r_token_balances);
    goto CPyL74;
CPyL90: ;
    CPy_DECREF(cpy_r_r28);
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_remote);
    goto CPyL28;
CPyL91: ;
    CPy_DecRef(cpy_r_token_balances);
    goto CPyL74;
CPyL92: ;
    CPy_DecRef(cpy_r_r50);
    goto CPyL74;
CPyL93: ;
    CPy_DecRef(cpy_r_r55);
    goto CPyL74;
CPyL94: ;
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r32);
    CPy_DecRef(cpy_r_remote);
    goto CPyL74;
CPyL95: ;
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r32);
    goto CPyL74;
CPyL96: ;
    CPy_DECREF(cpy_r_r72);
    goto CPyL73;
CPyL97: ;
    CPy_DecRef(cpy_r_r72);
    goto CPyL74;
CPyL98: ;
    CPy_DecRef(cpy_r_remote);
    CPy_DecRef(cpy_r_token_balances);
    CPy_DecRef(cpy_r_r72);
    goto CPyL74;
CPyL99: ;
    CPy_DECREF(cpy_r_remote);
    CPy_DECREF(cpy_r_r72);
    goto CPyL53;
CPyL100: ;
    CPy_DecRef(cpy_r_r97);
    goto CPyL74;
CPyL101: ;
    CPy_DecRef(cpy_r_r102);
    goto CPyL74;
CPyL102: ;
    CPy_DecRef(cpy_r_remote);
    CPy_DecRef(cpy_r_r72);
    goto CPyL74;
CPyL103: ;
    CPy_DecRef(cpy_r_r120);
    goto CPyL74;
CPyL104: ;
    CPy_DecRef(cpy_r_r126);
    goto CPyL74;
}

PyObject *CPyPy_RemoteTokenBalances_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"seed", "block", 0};
    PyObject *obj_seed = NULL;
    PyObject *obj_block = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|O$O", "__init__", kwlist, &obj_seed, &obj_block)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_seed;
    if (obj_seed == NULL) {
        arg_seed = NULL;
        goto __LL29;
    }
    if (PyDict_Check(obj_seed))
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL29;
    if (PyList_Check(obj_seed))
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL29;
    if (obj_seed == Py_None)
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL29;
    CPy_TypeError("union[dict, list, None]", obj_seed); 
    goto fail;
__LL29: ;
    PyObject *arg_block;
    if (obj_block == NULL) {
        arg_block = NULL;
        goto __LL30;
    }
    if (PyLong_Check(obj_block))
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL30;
    if (obj_block == Py_None)
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL30;
    CPy_TypeError("int or None", obj_block); 
    goto fail;
__LL30: ;
    char retval = CPyDef_RemoteTokenBalances_____init__(arg_self, arg_seed, arg_block);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 506, CPyStatic_globals);
    return NULL;
}

char CPyDef_RemoteTokenBalances_____setitem__(PyObject *cpy_r_self, PyObject *cpy_r_protocol, PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    char cpy_r_r35;
    char cpy_r_r36;
    cpy_r_r0 = (PyObject *)CPyType_TokenBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_value)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[50]; /* 'value must be a `TokenBalances` object. You passed ' */
    cpy_r_r6 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r7 = CPyStatics[3]; /* '' */
    cpy_r_r8 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r9[3] = {cpy_r_r6, cpy_r_value, cpy_r_r7};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = PyObject_VectorcallMethod(cpy_r_r8, cpy_r_r10, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 546, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 546, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    CPy_INCREF(cpy_r_r5);
    *(PyObject * *)cpy_r_r14 = cpy_r_r5;
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 546, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 546, CPyStatic_globals);
        goto CPyL16;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 546, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 546, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = CPyModule_builtins;
    cpy_r_r24 = CPyStatics[22]; /* 'super' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 547, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r26 = (PyObject *)CPyType_RemoteTokenBalances;
    PyObject *cpy_r_r27[2] = {cpy_r_r26, cpy_r_self};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = _PyObject_Vectorcall(cpy_r_r25, cpy_r_r28, 2, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 547, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r30 = CPyStatics[28]; /* '__setitem__' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 547, CPyStatic_globals);
        goto CPyL14;
    }
    PyObject *cpy_r_r32[2] = {cpy_r_protocol, cpy_r_value};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = _PyObject_Vectorcall(cpy_r_r31, cpy_r_r33, 2, 0);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 547, CPyStatic_globals);
        goto CPyL14;
    }
    if (unlikely(cpy_r_r34 != Py_None)) {
        CPy_TypeError("None", cpy_r_r34); cpy_r_r35 = 2;
    } else
        cpy_r_r35 = 1;
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 547, CPyStatic_globals);
        goto CPyL14;
    }
    return cpy_r_r35;
CPyL14: ;
    cpy_r_r36 = 2;
    return cpy_r_r36;
CPyL15: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL14;
CPyL16: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL14;
}

PyObject *CPyPy_RemoteTokenBalances_____setitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"protocol", "value", 0};
    static CPyArg_Parser parser = {"OO:__setitem__", kwlist, 0};
    PyObject *obj_protocol;
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_protocol, &obj_value)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_protocol;
    if (likely(PyUnicode_Check(obj_protocol)))
        arg_protocol = obj_protocol;
    else {
        CPy_TypeError("str", obj_protocol); 
        goto fail;
    }
    PyObject *arg_value;
    if (likely(Py_TYPE(obj_value) == CPyType_TokenBalances))
        arg_value = obj_value;
    else {
        CPy_TypeError("eth_portfolio.typing.TokenBalances", obj_value); 
        goto fail;
    }
    char retval = CPyDef_RemoteTokenBalances_____setitem__(arg_self, arg_protocol, arg_value);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 528, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_RemoteTokenBalances___dataframe(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    int64_t cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    tuple_T4CIOO cpy_r_r5;
    CPyTagged cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    int32_t cpy_r_r14;
    char cpy_r_r15;
    int32_t cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    CPyPtr cpy_r_r20;
    int64_t cpy_r_r21;
    CPyTagged cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 557, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r1 = 0;
    cpy_r_r2 = PyDict_Size(cpy_r_self);
    cpy_r_r3 = cpy_r_r2 << 1;
    cpy_r_r4 = CPyDict_GetItemsIter(cpy_r_self);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 558, CPyStatic_globals);
        goto CPyL20;
    }
CPyL2: ;
    cpy_r_r5 = CPyDict_NextItem(cpy_r_r4, cpy_r_r1);
    cpy_r_r6 = cpy_r_r5.f1;
    cpy_r_r1 = cpy_r_r6;
    cpy_r_r7 = cpy_r_r5.f0;
    if (!cpy_r_r7) goto CPyL21;
    cpy_r_r8 = cpy_r_r5.f2;
    CPy_INCREF(cpy_r_r8);
    cpy_r_r9 = cpy_r_r5.f3;
    CPy_INCREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r5.f2);
    CPy_DECREF(cpy_r_r5.f3);
    if (likely(PyUnicode_Check(cpy_r_r8)))
        cpy_r_r10 = cpy_r_r8;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "dataframe", 558, CPyStatic_globals, "str", cpy_r_r8);
        goto CPyL22;
    }
    if (likely(Py_TYPE(cpy_r_r9) == CPyType_TokenBalances))
        cpy_r_r11 = cpy_r_r9;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "dataframe", 558, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r9);
        goto CPyL23;
    }
    cpy_r_r12 = CPyDef_TokenBalances___dataframe(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 559, CPyStatic_globals);
        goto CPyL24;
    }
CPyL6: ;
    cpy_r_r13 = CPyStatics[51]; /* 'protocol' */
    cpy_r_r14 = PyObject_SetItem(cpy_r_r12, cpy_r_r13, cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    cpy_r_r15 = cpy_r_r14 >= 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 560, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r16 = PyList_Append(cpy_r_r0, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r17 = cpy_r_r16 >= 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 561, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r18 = CPyDict_CheckSize(cpy_r_self, cpy_r_r3);
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 558, CPyStatic_globals);
        goto CPyL26;
    } else
        goto CPyL2;
CPyL9: ;
    cpy_r_r19 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 558, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r20 = (CPyPtr)&((PyVarObject *)cpy_r_r0)->ob_size;
    cpy_r_r21 = *(int64_t *)cpy_r_r20;
    cpy_r_r22 = cpy_r_r21 << 1;
    cpy_r_r23 = cpy_r_r22 != 0;
    if (!cpy_r_r23) goto CPyL27;
    cpy_r_r24 = CPyStatic_globals;
    cpy_r_r25 = CPyStatics[52]; /* 'concat' */
    cpy_r_r26 = CPyDict_GetItem(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 562, CPyStatic_globals);
        goto CPyL20;
    }
    PyObject *cpy_r_r27[1] = {cpy_r_r0};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = _PyObject_Vectorcall(cpy_r_r26, cpy_r_r28, 1, 0);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 562, CPyStatic_globals);
        goto CPyL20;
    }
    CPy_DECREF(cpy_r_r0);
    cpy_r_r30 = CPyStatics[34]; /* 'reset_index' */
    cpy_r_r31 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r32[2] = {cpy_r_r29, cpy_r_r31};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = CPyStatics[143]; /* ('drop',) */
    cpy_r_r35 = PyObject_VectorcallMethod(cpy_r_r30, cpy_r_r33, 9223372036854775809ULL, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 562, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_DECREF(cpy_r_r29);
    cpy_r_r36 = cpy_r_r35;
    goto CPyL18;
CPyL15: ;
    cpy_r_r37 = CPyStatic_globals;
    cpy_r_r38 = CPyStatics[32]; /* 'DataFrame' */
    cpy_r_r39 = CPyDict_GetItem(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 562, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r39, 0, 0, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 562, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r36 = cpy_r_r40;
CPyL18: ;
    return cpy_r_r36;
CPyL19: ;
    cpy_r_r41 = NULL;
    return cpy_r_r41;
CPyL20: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL19;
CPyL21: ;
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r5.f2);
    CPy_DECREF(cpy_r_r5.f3);
    goto CPyL9;
CPyL22: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r9);
    goto CPyL19;
CPyL23: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r10);
    goto CPyL19;
CPyL24: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r10);
    goto CPyL19;
CPyL25: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r12);
    goto CPyL19;
CPyL26: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    goto CPyL19;
CPyL27: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL15;
CPyL28: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL19;
}

PyObject *CPyPy_RemoteTokenBalances___dataframe(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":dataframe", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_RemoteTokenBalances___dataframe(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 550, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_RemoteTokenBalances___sum_usd(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    CPyTagged cpy_r_r2;
    int64_t cpy_r_r3;
    CPyTagged cpy_r_r4;
    PyObject *cpy_r_r5;
    tuple_T3CIO cpy_r_r6;
    CPyTagged cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    cpy_r_r0 = CPyStatics[140]; /* 0 */
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = 0;
    cpy_r_r3 = PyDict_Size(cpy_r_self);
    cpy_r_r4 = cpy_r_r3 << 1;
    cpy_r_r5 = CPyDict_GetValuesIter(cpy_r_self);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 577, CPyStatic_globals);
        goto CPyL12;
    }
CPyL1: ;
    cpy_r_r6 = CPyDict_NextValue(cpy_r_r5, cpy_r_r2);
    cpy_r_r7 = cpy_r_r6.f1;
    cpy_r_r2 = cpy_r_r7;
    cpy_r_r8 = cpy_r_r6.f0;
    if (!cpy_r_r8) goto CPyL13;
    cpy_r_r9 = cpy_r_r6.f2;
    CPy_INCREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r6.f2);
    if (likely(Py_TYPE(cpy_r_r9) == CPyType_TokenBalances))
        cpy_r_r10 = cpy_r_r9;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "sum_usd", 577, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r9);
        goto CPyL14;
    }
    cpy_r_r11 = CPyDef_TokenBalances___sum_usd(cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 577, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r12 = PyNumber_Add(cpy_r_r1, cpy_r_r11);
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", -1, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r1 = cpy_r_r12;
    cpy_r_r13 = CPyDict_CheckSize(cpy_r_self, cpy_r_r4);
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 577, CPyStatic_globals);
        goto CPyL14;
    } else
        goto CPyL1;
CPyL7: ;
    cpy_r_r14 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 577, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyStatics[20]; /* 'Decimal' */
    cpy_r_r17 = CPyDict_GetItem(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 577, CPyStatic_globals);
        goto CPyL12;
    }
    PyObject *cpy_r_r18[1] = {cpy_r_r1};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = _PyObject_Vectorcall(cpy_r_r17, cpy_r_r19, 1, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 577, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r1);
    return cpy_r_r20;
CPyL11: ;
    cpy_r_r21 = NULL;
    return cpy_r_r21;
CPyL12: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL11;
CPyL13: ;
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r6.f2);
    goto CPyL7;
CPyL14: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r5);
    goto CPyL11;
CPyL15: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL11;
}

PyObject *CPyPy_RemoteTokenBalances___sum_usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":sum_usd", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_RemoteTokenBalances___sum_usd(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 564, CPyStatic_globals);
    return NULL;
}

char CPyDef_RemoteTokenBalances_____bool__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    cpy_r_r0 = CPyDict_ValuesView(cpy_r_self);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 591, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r1 = CPyModule_builtins;
    cpy_r_r2 = CPyStatics[42]; /* 'any' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 591, CPyStatic_globals);
        goto CPyL6;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 591, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!PyBool_Check(cpy_r_r6))) {
        CPy_TypeError("bool", cpy_r_r6); cpy_r_r7 = 2;
    } else
        cpy_r_r7 = cpy_r_r6 == Py_True;
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 591, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r7;
CPyL5: ;
    cpy_r_r8 = 2;
    return cpy_r_r8;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_RemoteTokenBalances_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__bool__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    char retval = CPyDef_RemoteTokenBalances_____bool__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 579, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_RemoteTokenBalances_____repr__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[54]; /* 'RemoteTokenBalances' */
    cpy_r_r1 = PyDict_Copy(cpy_r_self);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 600, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r2 = PyObject_Str(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 600, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r3 = CPyStr_Build(2, cpy_r_r0, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 600, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy_RemoteTokenBalances_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__repr__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_RemoteTokenBalances_____repr__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 593, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_RemoteTokenBalances_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
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
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    CPyTagged cpy_r_r58;
    int64_t cpy_r_r59;
    CPyTagged cpy_r_r60;
    PyObject *cpy_r_r61;
    tuple_T4CIOO cpy_r_r62;
    CPyTagged cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_protocol;
    PyObject *cpy_r_token_balances;
    char cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    int32_t cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    char cpy_r_r75;
    CPyTagged cpy_r_r76;
    int64_t cpy_r_r77;
    CPyTagged cpy_r_r78;
    PyObject *cpy_r_r79;
    tuple_T4CIOO cpy_r_r80;
    CPyTagged cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    char cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    int32_t cpy_r_r90;
    char cpy_r_r91;
    char cpy_r_r92;
    char cpy_r_r93;
    PyObject *cpy_r_r94;
    cpy_r_r0 = (PyObject *)CPyType_RemoteTokenBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 623, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r11 = CPyStatics[55]; /* ' is not a RemoteTokenBalances object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 623, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 623, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 623, CPyStatic_globals);
        goto CPyL55;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 623, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 623, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = CPyStatics[48]; /* 'block' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_self, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 624, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r24))
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL31;
    if (cpy_r_r24 == Py_None)
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL31;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 624, CPyStatic_globals, "int or None", cpy_r_r24);
    goto CPyL53;
__LL31: ;
    cpy_r_r26 = CPyStatics[48]; /* 'block' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_other, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 624, CPyStatic_globals);
        goto CPyL56;
    }
    if (PyLong_Check(cpy_r_r27))
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL32;
    if (cpy_r_r27 == Py_None)
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL32;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 624, CPyStatic_globals, "int or None", cpy_r_r27);
    goto CPyL56;
__LL32: ;
    cpy_r_r29 = PyObject_RichCompare(cpy_r_r25, cpy_r_r28, 3);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 624, CPyStatic_globals);
        goto CPyL53;
    }
    if (unlikely(!PyBool_Check(cpy_r_r29))) {
        CPy_TypeError("bool", cpy_r_r29); cpy_r_r30 = 2;
    } else
        cpy_r_r30 = cpy_r_r29 == Py_True;
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 624, CPyStatic_globals);
        goto CPyL53;
    }
    if (!cpy_r_r30) goto CPyL26;
    cpy_r_r31 = CPyStatics[56]; /* ('These RemoteTokenBalances objects are not from the same '
                                   'block (') */
    cpy_r_r32 = CPyStatics[48]; /* 'block' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_self, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 626, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r33))
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL33;
    if (cpy_r_r33 == Py_None)
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL33;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 626, CPyStatic_globals, "int or None", cpy_r_r33);
    goto CPyL53;
__LL33: ;
    cpy_r_r35 = PyObject_Str(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 626, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r36 = CPyStatics[9]; /* ' and ' */
    cpy_r_r37 = CPyStatics[48]; /* 'block' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_other, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 626, CPyStatic_globals);
        goto CPyL57;
    }
    if (PyLong_Check(cpy_r_r38))
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL34;
    if (cpy_r_r38 == Py_None)
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL34;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 626, CPyStatic_globals, "int or None", cpy_r_r38);
    goto CPyL57;
__LL34: ;
    cpy_r_r40 = PyObject_Str(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 626, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r41 = CPyStatics[10]; /* ')' */
    cpy_r_r42 = CPyStr_Build(5, cpy_r_r31, cpy_r_r35, cpy_r_r36, cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 626, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r43 = CPyModule_builtins;
    cpy_r_r44 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 625, CPyStatic_globals);
        goto CPyL58;
    }
    PyObject *cpy_r_r46[1] = {cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 625, CPyStatic_globals);
        goto CPyL58;
    }
    CPy_DECREF(cpy_r_r42);
    CPy_Raise(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 625, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_r49 = CPyStatics[48]; /* 'block' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_self, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 629, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r50))
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL35;
    if (cpy_r_r50 == Py_None)
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL35;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 629, CPyStatic_globals, "int or None", cpy_r_r50);
    goto CPyL53;
__LL35: ;
    cpy_r_r52 = (PyObject *)CPyType_RemoteTokenBalances;
    PyObject *cpy_r_r53[1] = {cpy_r_r51};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = CPyStatics[144]; /* ('block',) */
    cpy_r_r56 = _PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 0, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 629, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_DECREF(cpy_r_r51);
    if (likely(PyDict_Check(cpy_r_r56)))
        cpy_r_r57 = cpy_r_r56;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 629, CPyStatic_globals, "dict", cpy_r_r56);
        goto CPyL53;
    }
    cpy_r_r58 = 0;
    cpy_r_r59 = PyDict_Size(cpy_r_self);
    cpy_r_r60 = cpy_r_r59 << 1;
    cpy_r_r61 = CPyDict_GetItemsIter(cpy_r_self);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 630, CPyStatic_globals);
        goto CPyL60;
    }
CPyL31: ;
    cpy_r_r62 = CPyDict_NextItem(cpy_r_r61, cpy_r_r58);
    cpy_r_r63 = cpy_r_r62.f1;
    cpy_r_r58 = cpy_r_r63;
    cpy_r_r64 = cpy_r_r62.f0;
    if (!cpy_r_r64) goto CPyL61;
    cpy_r_r65 = cpy_r_r62.f2;
    CPy_INCREF(cpy_r_r65);
    cpy_r_r66 = cpy_r_r62.f3;
    CPy_INCREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    if (likely(PyUnicode_Check(cpy_r_r65)))
        cpy_r_r67 = cpy_r_r65;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 630, CPyStatic_globals, "str", cpy_r_r65);
        goto CPyL62;
    }
    if (likely(Py_TYPE(cpy_r_r66) == CPyType_TokenBalances))
        cpy_r_r68 = cpy_r_r66;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 630, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r66);
        goto CPyL63;
    }
    cpy_r_protocol = cpy_r_r67;
    cpy_r_token_balances = cpy_r_r68;
    cpy_r_r69 = CPyDef_TokenBalances_____bool__(cpy_r_token_balances);
    if (unlikely(cpy_r_r69 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 630, CPyStatic_globals);
        goto CPyL64;
    }
    if (!cpy_r_r69) goto CPyL65;
    cpy_r_r70 = CPyDict_GetItem(cpy_r_r57, cpy_r_protocol);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 632, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r71 = PyNumber_InPlaceAdd(cpy_r_r70, cpy_r_token_balances);
    CPy_DECREF(cpy_r_r70);
    CPy_DECREF(cpy_r_token_balances);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 632, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r72 = CPyDict_SetItem(cpy_r_r57, cpy_r_protocol, cpy_r_r71);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_r71);
    cpy_r_r73 = cpy_r_r72 >= 0;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 632, CPyStatic_globals);
        goto CPyL67;
    }
CPyL39: ;
    cpy_r_r74 = CPyDict_CheckSize(cpy_r_self, cpy_r_r60);
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 630, CPyStatic_globals);
        goto CPyL67;
    } else
        goto CPyL31;
CPyL40: ;
    cpy_r_r75 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 630, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r76 = 0;
    cpy_r_r77 = PyDict_Size(cpy_r_other);
    cpy_r_r78 = cpy_r_r77 << 1;
    cpy_r_r79 = CPyDict_GetItemsIter(cpy_r_other);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 633, CPyStatic_globals);
        goto CPyL60;
    }
CPyL42: ;
    cpy_r_r80 = CPyDict_NextItem(cpy_r_r79, cpy_r_r76);
    cpy_r_r81 = cpy_r_r80.f1;
    cpy_r_r76 = cpy_r_r81;
    cpy_r_r82 = cpy_r_r80.f0;
    if (!cpy_r_r82) goto CPyL68;
    cpy_r_r83 = cpy_r_r80.f2;
    CPy_INCREF(cpy_r_r83);
    cpy_r_r84 = cpy_r_r80.f3;
    CPy_INCREF(cpy_r_r84);
    CPy_DECREF(cpy_r_r80.f2);
    CPy_DECREF(cpy_r_r80.f3);
    if (likely(PyUnicode_Check(cpy_r_r83)))
        cpy_r_r85 = cpy_r_r83;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 633, CPyStatic_globals, "str", cpy_r_r83);
        goto CPyL69;
    }
    if (likely(Py_TYPE(cpy_r_r84) == CPyType_TokenBalances))
        cpy_r_r86 = cpy_r_r84;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 633, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r84);
        goto CPyL70;
    }
    cpy_r_protocol = cpy_r_r85;
    cpy_r_token_balances = cpy_r_r86;
    cpy_r_r87 = CPyDef_TokenBalances_____bool__(cpy_r_token_balances);
    if (unlikely(cpy_r_r87 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 630, CPyStatic_globals);
        goto CPyL71;
    }
    if (!cpy_r_r87) goto CPyL72;
    cpy_r_r88 = CPyDict_GetItem(cpy_r_r57, cpy_r_protocol);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 635, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r89 = PyNumber_InPlaceAdd(cpy_r_r88, cpy_r_token_balances);
    CPy_DECREF(cpy_r_r88);
    CPy_DECREF(cpy_r_token_balances);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 635, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r90 = CPyDict_SetItem(cpy_r_r57, cpy_r_protocol, cpy_r_r89);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_r89);
    cpy_r_r91 = cpy_r_r90 >= 0;
    if (unlikely(!cpy_r_r91)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 635, CPyStatic_globals);
        goto CPyL74;
    }
CPyL50: ;
    cpy_r_r92 = CPyDict_CheckSize(cpy_r_other, cpy_r_r78);
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 633, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL42;
CPyL51: ;
    cpy_r_r93 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 633, CPyStatic_globals);
        goto CPyL60;
    }
    return cpy_r_r57;
CPyL53: ;
    cpy_r_r94 = NULL;
    return cpy_r_r94;
CPyL54: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL53;
CPyL55: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL53;
CPyL56: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL53;
CPyL57: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL53;
CPyL58: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL53;
CPyL59: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL53;
CPyL60: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL53;
CPyL61: ;
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    goto CPyL40;
CPyL62: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r66);
    goto CPyL53;
CPyL63: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r67);
    goto CPyL53;
CPyL64: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_token_balances);
    goto CPyL53;
CPyL65: ;
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_token_balances);
    goto CPyL39;
CPyL66: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_protocol);
    goto CPyL53;
CPyL67: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    goto CPyL53;
CPyL68: ;
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r80.f2);
    CPy_DECREF(cpy_r_r80.f3);
    goto CPyL51;
CPyL69: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r84);
    goto CPyL53;
CPyL70: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r85);
    goto CPyL53;
CPyL71: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_token_balances);
    CPy_DecRef(cpy_r_r79);
    goto CPyL53;
CPyL72: ;
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_token_balances);
    goto CPyL50;
CPyL73: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_r79);
    goto CPyL53;
CPyL74: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r79);
    goto CPyL53;
}

PyObject *CPyPy_RemoteTokenBalances_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyDict_Check(obj_other)))
        arg_other = obj_other;
    else {
        CPy_TypeError("dict", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_RemoteTokenBalances_____add__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 602, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_RemoteTokenBalances_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    CPy_INCREF(cpy_r_self);
    if (likely(PyDict_Check(cpy_r_self)))
        cpy_r_r0 = cpy_r_self;
    else {
        CPy_TypeError("dict", cpy_r_self); 
        cpy_r_r0 = NULL;
    }
    if (cpy_r_r0 == NULL) goto CPyL5;
    CPy_INCREF(cpy_r_other);
    if (likely(PyDict_Check(cpy_r_other)))
        cpy_r_r1 = cpy_r_other;
    else {
        CPy_TypeError("dict", cpy_r_other); 
        cpy_r_r1 = NULL;
    }
    if (cpy_r_r1 == NULL) goto CPyL6;
    cpy_r_r2 = CPyDef_RemoteTokenBalances_____add__(cpy_r_r0, cpy_r_r1);
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL5;
    if (likely(PyObject_TypeCheck(cpy_r_r2, CPyType__SummableNonNumericMixin)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", cpy_r_r2); 
        cpy_r_r3 = NULL;
    }
    if (cpy_r_r3 == NULL) goto CPyL5;
    return cpy_r_r3;
CPyL5: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
CPyL6: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_RemoteTokenBalances_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add_____SummableNonNumericMixin_glue", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_RemoteTokenBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.RemoteTokenBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyObject_TypeCheck(obj_other, CPyType__SummableNonNumericMixin)))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_RemoteTokenBalances_____add___3___SummableNonNumericMixin_glue(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add_____SummableNonNumericMixin_glue", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_RemoteTokenBalances_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
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
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    CPyTagged cpy_r_r58;
    int64_t cpy_r_r59;
    CPyTagged cpy_r_r60;
    PyObject *cpy_r_r61;
    tuple_T4CIOO cpy_r_r62;
    CPyTagged cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_protocol;
    PyObject *cpy_r_token_balances;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    int32_t cpy_r_r71;
    char cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    PyObject *cpy_r_r75;
    CPyTagged cpy_r_r76;
    int64_t cpy_r_r77;
    CPyTagged cpy_r_r78;
    PyObject *cpy_r_r79;
    tuple_T4CIOO cpy_r_r80;
    CPyTagged cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    char cpy_r_r87;
    int32_t cpy_r_r88;
    char cpy_r_r89;
    char cpy_r_r90;
    char cpy_r_r91;
    PyObject *cpy_r_r92;
    cpy_r_r0 = (PyObject *)CPyType_RemoteTokenBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 659, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r11 = CPyStatics[55]; /* ' is not a RemoteTokenBalances object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 659, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 659, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 659, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 659, CPyStatic_globals);
        goto CPyL52;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 659, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = CPyStatics[48]; /* 'block' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_self, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 660, CPyStatic_globals);
        goto CPyL50;
    }
    if (PyLong_Check(cpy_r_r24))
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL36;
    if (cpy_r_r24 == Py_None)
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL36;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 660, CPyStatic_globals, "int or None", cpy_r_r24);
    goto CPyL50;
__LL36: ;
    cpy_r_r26 = CPyStatics[48]; /* 'block' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_other, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 660, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r27))
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL37;
    if (cpy_r_r27 == Py_None)
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL37;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 660, CPyStatic_globals, "int or None", cpy_r_r27);
    goto CPyL53;
__LL37: ;
    cpy_r_r29 = PyObject_RichCompare(cpy_r_r25, cpy_r_r28, 3);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 660, CPyStatic_globals);
        goto CPyL50;
    }
    if (unlikely(!PyBool_Check(cpy_r_r29))) {
        CPy_TypeError("bool", cpy_r_r29); cpy_r_r30 = 2;
    } else
        cpy_r_r30 = cpy_r_r29 == Py_True;
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 660, CPyStatic_globals);
        goto CPyL50;
    }
    if (!cpy_r_r30) goto CPyL26;
    cpy_r_r31 = CPyStatics[56]; /* ('These RemoteTokenBalances objects are not from the same '
                                   'block (') */
    cpy_r_r32 = CPyStatics[48]; /* 'block' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_self, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 662, CPyStatic_globals);
        goto CPyL50;
    }
    if (PyLong_Check(cpy_r_r33))
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL38;
    if (cpy_r_r33 == Py_None)
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL38;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 662, CPyStatic_globals, "int or None", cpy_r_r33);
    goto CPyL50;
__LL38: ;
    cpy_r_r35 = PyObject_Str(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 662, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r36 = CPyStatics[9]; /* ' and ' */
    cpy_r_r37 = CPyStatics[48]; /* 'block' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_other, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 662, CPyStatic_globals);
        goto CPyL54;
    }
    if (PyLong_Check(cpy_r_r38))
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL39;
    if (cpy_r_r38 == Py_None)
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL39;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 662, CPyStatic_globals, "int or None", cpy_r_r38);
    goto CPyL54;
__LL39: ;
    cpy_r_r40 = PyObject_Str(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 662, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r41 = CPyStatics[10]; /* ')' */
    cpy_r_r42 = CPyStr_Build(5, cpy_r_r31, cpy_r_r35, cpy_r_r36, cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 662, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r43 = CPyModule_builtins;
    cpy_r_r44 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 661, CPyStatic_globals);
        goto CPyL55;
    }
    PyObject *cpy_r_r46[1] = {cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 661, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_DECREF(cpy_r_r42);
    CPy_Raise(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 661, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_r49 = CPyStatics[48]; /* 'block' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_self, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 665, CPyStatic_globals);
        goto CPyL50;
    }
    if (PyLong_Check(cpy_r_r50))
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL40;
    if (cpy_r_r50 == Py_None)
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL40;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 665, CPyStatic_globals, "int or None", cpy_r_r50);
    goto CPyL50;
__LL40: ;
    cpy_r_r52 = (PyObject *)CPyType_RemoteTokenBalances;
    PyObject *cpy_r_r53[2] = {cpy_r_self, cpy_r_r51};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = CPyStatics[144]; /* ('block',) */
    cpy_r_r56 = _PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 1, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 665, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_DECREF(cpy_r_r51);
    if (likely(PyDict_Check(cpy_r_r56)))
        cpy_r_r57 = cpy_r_r56;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 665, CPyStatic_globals, "dict", cpy_r_r56);
        goto CPyL50;
    }
    cpy_r_r58 = 0;
    cpy_r_r59 = PyDict_Size(cpy_r_other);
    cpy_r_r60 = cpy_r_r59 << 1;
    cpy_r_r61 = CPyDict_GetItemsIter(cpy_r_other);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 666, CPyStatic_globals);
        goto CPyL57;
    }
CPyL31: ;
    cpy_r_r62 = CPyDict_NextItem(cpy_r_r61, cpy_r_r58);
    cpy_r_r63 = cpy_r_r62.f1;
    cpy_r_r58 = cpy_r_r63;
    cpy_r_r64 = cpy_r_r62.f0;
    if (!cpy_r_r64) goto CPyL58;
    cpy_r_r65 = cpy_r_r62.f2;
    CPy_INCREF(cpy_r_r65);
    cpy_r_r66 = cpy_r_r62.f3;
    CPy_INCREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    if (likely(PyUnicode_Check(cpy_r_r65)))
        cpy_r_r67 = cpy_r_r65;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 666, CPyStatic_globals, "str", cpy_r_r65);
        goto CPyL59;
    }
    if (likely(Py_TYPE(cpy_r_r66) == CPyType_TokenBalances))
        cpy_r_r68 = cpy_r_r66;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 666, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r66);
        goto CPyL60;
    }
    cpy_r_protocol = cpy_r_r67;
    cpy_r_token_balances = cpy_r_r68;
    cpy_r_r69 = CPyDict_GetItem(cpy_r_r57, cpy_r_protocol);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 667, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r70 = PyNumber_InPlaceSubtract(cpy_r_r69, cpy_r_token_balances);
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_token_balances);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 667, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r71 = CPyDict_SetItem(cpy_r_r57, cpy_r_protocol, cpy_r_r70);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_r70);
    cpy_r_r72 = cpy_r_r71 >= 0;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 667, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r73 = CPyDict_CheckSize(cpy_r_other, cpy_r_r60);
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 666, CPyStatic_globals);
        goto CPyL63;
    } else
        goto CPyL31;
CPyL38: ;
    cpy_r_r74 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 666, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r75 = PyDict_Copy(cpy_r_r57);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 668, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r76 = 0;
    cpy_r_r77 = PyDict_Size(cpy_r_r75);
    cpy_r_r78 = cpy_r_r77 << 1;
    cpy_r_r79 = CPyDict_GetItemsIter(cpy_r_r75);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 668, CPyStatic_globals);
        goto CPyL64;
    }
CPyL41: ;
    cpy_r_r80 = CPyDict_NextItem(cpy_r_r79, cpy_r_r76);
    cpy_r_r81 = cpy_r_r80.f1;
    cpy_r_r76 = cpy_r_r81;
    cpy_r_r82 = cpy_r_r80.f0;
    if (!cpy_r_r82) goto CPyL65;
    cpy_r_r83 = cpy_r_r80.f2;
    CPy_INCREF(cpy_r_r83);
    cpy_r_r84 = cpy_r_r80.f3;
    CPy_INCREF(cpy_r_r84);
    CPy_DECREF(cpy_r_r80.f2);
    CPy_DECREF(cpy_r_r80.f3);
    if (likely(PyUnicode_Check(cpy_r_r83)))
        cpy_r_r85 = cpy_r_r83;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 668, CPyStatic_globals, "str", cpy_r_r83);
        goto CPyL66;
    }
    if (likely(Py_TYPE(cpy_r_r84) == CPyType_TokenBalances))
        cpy_r_r86 = cpy_r_r84;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 668, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r84);
        goto CPyL67;
    }
    cpy_r_protocol = cpy_r_r85;
    cpy_r_token_balances = cpy_r_r86;
    cpy_r_r87 = CPyDef_TokenBalances_____bool__(cpy_r_token_balances);
    CPy_DECREF(cpy_r_token_balances);
    if (unlikely(cpy_r_r87 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 666, CPyStatic_globals);
        goto CPyL68;
    }
    if (cpy_r_r87) goto CPyL69;
    cpy_r_r88 = PyObject_DelItem(cpy_r_r57, cpy_r_protocol);
    CPy_DECREF(cpy_r_protocol);
    cpy_r_r89 = cpy_r_r88 >= 0;
    if (unlikely(!cpy_r_r89)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 670, CPyStatic_globals);
        goto CPyL70;
    }
CPyL47: ;
    cpy_r_r90 = CPyDict_CheckSize(cpy_r_r75, cpy_r_r78);
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 668, CPyStatic_globals);
        goto CPyL70;
    } else
        goto CPyL41;
CPyL48: ;
    cpy_r_r91 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r91)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 668, CPyStatic_globals);
        goto CPyL57;
    }
    return cpy_r_r57;
CPyL50: ;
    cpy_r_r92 = NULL;
    return cpy_r_r92;
CPyL51: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL50;
CPyL52: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL50;
CPyL53: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL50;
CPyL54: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL50;
CPyL55: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL50;
CPyL56: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL50;
CPyL57: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL50;
CPyL58: ;
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    goto CPyL38;
CPyL59: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r66);
    goto CPyL50;
CPyL60: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r67);
    goto CPyL50;
CPyL61: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_token_balances);
    goto CPyL50;
CPyL62: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_protocol);
    goto CPyL50;
CPyL63: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    goto CPyL50;
CPyL64: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r75);
    goto CPyL50;
CPyL65: ;
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r80.f2);
    CPy_DECREF(cpy_r_r80.f3);
    goto CPyL48;
CPyL66: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r84);
    goto CPyL50;
CPyL67: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r85);
    goto CPyL50;
CPyL68: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r79);
    goto CPyL50;
CPyL69: ;
    CPy_DECREF(cpy_r_protocol);
    goto CPyL47;
CPyL70: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r79);
    goto CPyL50;
}

PyObject *CPyPy_RemoteTokenBalances_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__sub__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyDict_Check(obj_other)))
        arg_other = obj_other;
    else {
        CPy_TypeError("dict", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_RemoteTokenBalances_____sub__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 638, CPyStatic_globals);
    return NULL;
}

char CPyDef_WalletBalances_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    int32_t cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    tuple_T3OOO cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    int32_t cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    int32_t cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    int32_t cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    int32_t cpy_r_r49;
    char cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    int32_t cpy_r_r57;
    char cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject **cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    CPyPtr cpy_r_r69;
    CPyPtr cpy_r_r70;
    CPyPtr cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject **cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    char cpy_r_r84;
    PyObject *cpy_r_key;
    PyObject *cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_balances;
    PyObject *cpy_r_r87;
    char cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    CPyPtr cpy_r_r93;
    PyObject *cpy_r_r94;
    char cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    char cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    CPyPtr cpy_r_r111;
    PyObject *cpy_r_r112;
    char cpy_r_r113;
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
    PyObject **cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject **cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    int32_t cpy_r_r135;
    char cpy_r_r136;
    char cpy_r_r137;
    char cpy_r_r138;
    if (cpy_r_seed != NULL) goto CPyL79;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_seed = cpy_r_r0;
CPyL2: ;
    if (cpy_r_block != NULL) goto CPyL80;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_block = cpy_r_r1;
CPyL4: ;
    cpy_r_r2 = CPyModule_builtins;
    cpy_r_r3 = CPyStatics[22]; /* 'super' */
    cpy_r_r4 = CPyObject_GetAttr(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 703, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r5 = (PyObject *)CPyType_WalletBalances;
    PyObject *cpy_r_r6[2] = {cpy_r_r5, cpy_r_self};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r7, 2, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 703, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r9 = CPyStatics[23]; /* '__init__' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 703, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r11 = _PyObject_Vectorcall(cpy_r_r10, 0, 0, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 703, CPyStatic_globals);
        goto CPyL81;
    } else
        goto CPyL82;
CPyL8: ;
    cpy_r_r12 = CPyStatics[48]; /* 'block' */
    cpy_r_r13 = PyObject_SetAttr(cpy_r_self, cpy_r_r12, cpy_r_block);
    cpy_r_r14 = cpy_r_r13 >= 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 704, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r15 = CPyStatics[57]; /* 'assets' */
    cpy_r_r16 = CPyStatics[58]; /* 'debt' */
    cpy_r_r17 = CPyStatics[59]; /* 'external' */
    CPy_INCREF(cpy_r_r15);
    CPy_INCREF(cpy_r_r16);
    CPy_INCREF(cpy_r_r17);
    cpy_r_r18.f0 = cpy_r_r15;
    cpy_r_r18.f1 = cpy_r_r16;
    cpy_r_r18.f2 = cpy_r_r17;
    cpy_r_r19 = CPyStatics[60]; /* '_keys' */
    cpy_r_r20 = PyTuple_New(3);
    if (unlikely(cpy_r_r20 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp41 = cpy_r_r18.f0;
    PyTuple_SET_ITEM(cpy_r_r20, 0, __tmp41);
    PyObject *__tmp42 = cpy_r_r18.f1;
    PyTuple_SET_ITEM(cpy_r_r20, 1, __tmp42);
    PyObject *__tmp43 = cpy_r_r18.f2;
    PyTuple_SET_ITEM(cpy_r_r20, 2, __tmp43);
    cpy_r_r21 = PyObject_SetAttr(cpy_r_self, cpy_r_r19, cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r22 = cpy_r_r21 >= 0;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 705, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r23 = NULL;
    cpy_r_r24 = CPyDef_TokenBalances(cpy_r_r23, cpy_r_block);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 706, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r25 = CPyStatics[57]; /* 'assets' */
    cpy_r_r26 = CPyDict_SetItem(cpy_r_self, cpy_r_r25, cpy_r_r24);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r27 = cpy_r_r26 >= 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 706, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r28 = (PyObject *)CPyType_RemoteTokenBalances;
    PyObject *cpy_r_r29[1] = {cpy_r_block};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = CPyStatics[144]; /* ('block',) */
    cpy_r_r32 = _PyObject_Vectorcall(cpy_r_r28, cpy_r_r30, 0, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 707, CPyStatic_globals);
        goto CPyL81;
    }
    if (likely(PyDict_Check(cpy_r_r32)))
        cpy_r_r33 = cpy_r_r32;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 707, CPyStatic_globals, "dict", cpy_r_r32);
        goto CPyL81;
    }
    cpy_r_r34 = CPyStatics[58]; /* 'debt' */
    cpy_r_r35 = CPyDict_SetItem(cpy_r_self, cpy_r_r34, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r36 = cpy_r_r35 >= 0;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 707, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r37 = (PyObject *)CPyType_RemoteTokenBalances;
    PyObject *cpy_r_r38[1] = {cpy_r_block};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = CPyStatics[144]; /* ('block',) */
    cpy_r_r41 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r39, 0, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 708, CPyStatic_globals);
        goto CPyL81;
    }
    CPy_DECREF(cpy_r_block);
    if (likely(PyDict_Check(cpy_r_r41)))
        cpy_r_r42 = cpy_r_r41;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 708, CPyStatic_globals, "dict", cpy_r_r41);
        goto CPyL83;
    }
    cpy_r_r43 = CPyStatics[59]; /* 'external' */
    cpy_r_r44 = CPyDict_SetItem(cpy_r_self, cpy_r_r43, cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 708, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r46 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r47 = cpy_r_seed == cpy_r_r46;
    if (cpy_r_r47) {
        goto CPyL84;
    } else
        goto CPyL20;
CPyL19: ;
    return 1;
CPyL20: ;
    cpy_r_r48 = (PyObject *)&PyDict_Type;
    cpy_r_r49 = PyObject_IsInstance(cpy_r_seed, cpy_r_r48);
    cpy_r_r50 = cpy_r_r49 >= 0;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 712, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r51 = cpy_r_r49;
    if (!cpy_r_r51) goto CPyL25;
    if (likely(PyDict_Check(cpy_r_seed)))
        cpy_r_r52 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 713, CPyStatic_globals, "dict", cpy_r_seed);
        goto CPyL78;
    }
    cpy_r_r53 = CPyDict_ItemsView(cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 713, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_seed = cpy_r_r53;
CPyL25: ;
    cpy_r_r54 = CPyStatic_globals;
    cpy_r_r55 = CPyStatics[61]; /* 'Iterable' */
    cpy_r_r56 = CPyDict_GetItem(cpy_r_r54, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 714, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r57 = PyObject_IsInstance(cpy_r_seed, cpy_r_r56);
    CPy_DECREF(cpy_r_r56);
    cpy_r_r58 = cpy_r_r57 >= 0;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 714, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r59 = cpy_r_r57;
    if (cpy_r_r59) goto CPyL35;
    cpy_r_r60 = CPyStatics[3]; /* '' */
    cpy_r_r61 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r62 = CPyStatics[3]; /* '' */
    cpy_r_r63 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r64[3] = {cpy_r_r61, cpy_r_seed, cpy_r_r62};
    cpy_r_r65 = (PyObject **)&cpy_r_r64;
    cpy_r_r66 = PyObject_VectorcallMethod(cpy_r_r63, cpy_r_r65, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 715, CPyStatic_globals);
        goto CPyL83;
    }
    CPy_DECREF(cpy_r_seed);
    cpy_r_r67 = CPyStatics[62]; /* ' is not a valid input for WalletBalances' */
    cpy_r_r68 = PyList_New(2);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 715, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r69 = (CPyPtr)&((PyListObject *)cpy_r_r68)->ob_item;
    cpy_r_r70 = *(CPyPtr *)cpy_r_r69;
    *(PyObject * *)cpy_r_r70 = cpy_r_r66;
    CPy_INCREF(cpy_r_r67);
    cpy_r_r71 = cpy_r_r70 + 8;
    *(PyObject * *)cpy_r_r71 = cpy_r_r67;
    cpy_r_r72 = PyUnicode_Join(cpy_r_r60, cpy_r_r68);
    CPy_DECREF(cpy_r_r68);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 715, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r73 = CPyModule_builtins;
    cpy_r_r74 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r75 = CPyObject_GetAttr(cpy_r_r73, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 715, CPyStatic_globals);
        goto CPyL86;
    }
    PyObject *cpy_r_r76[1] = {cpy_r_r72};
    cpy_r_r77 = (PyObject **)&cpy_r_r76;
    cpy_r_r78 = _PyObject_Vectorcall(cpy_r_r75, cpy_r_r77, 1, 0);
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 715, CPyStatic_globals);
        goto CPyL86;
    }
    CPy_DECREF(cpy_r_r72);
    CPy_Raise(cpy_r_r78);
    CPy_DECREF(cpy_r_r78);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 715, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL35: ;
    cpy_r_r79 = PyObject_GetIter(cpy_r_seed);
    CPy_DECREF(cpy_r_seed);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 716, CPyStatic_globals);
        goto CPyL78;
    }
CPyL36: ;
    cpy_r_r80 = PyIter_Next(cpy_r_r79);
    if (cpy_r_r80 == NULL) goto CPyL87;
    if (PyUnicode_Check(cpy_r_r80))
        cpy_r_r81 = cpy_r_r80;
    else {
        cpy_r_r81 = NULL;
    }
    if (cpy_r_r81 != NULL) goto __LL44;
    if (unlikely(!(PyTuple_Check(cpy_r_r80) && PyTuple_GET_SIZE(cpy_r_r80) == 2))) {
        cpy_r_r81 = NULL;
        goto __LL45;
    }
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r80, 0))))
        cpy_r_r81 = PyTuple_GET_ITEM(cpy_r_r80, 0);
    else {
        cpy_r_r81 = NULL;
    }
    if (cpy_r_r81 == NULL) goto __LL45;
    if (likely(Py_TYPE(PyTuple_GET_ITEM(cpy_r_r80, 1)) == CPyType_TokenBalances))
        cpy_r_r81 = PyTuple_GET_ITEM(cpy_r_r80, 1);
    else {
        cpy_r_r81 = NULL;
    }
    if (cpy_r_r81 == NULL) goto __LL45;
    cpy_r_r81 = cpy_r_r80;
__LL45: ;
    if (cpy_r_r81 != NULL) goto __LL44;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 716, CPyStatic_globals, "union[str, tuple[str, eth_portfolio.typing.TokenBalances]]", cpy_r_r80);
    goto CPyL88;
__LL44: ;
    cpy_r_r82 = PyObject_GetIter(cpy_r_r81);
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 716, CPyStatic_globals);
        goto CPyL88;
    }
    cpy_r_r83 = PyIter_Next(cpy_r_r82);
    if (cpy_r_r83 == NULL) {
        goto CPyL89;
    } else
        goto CPyL42;
CPyL40: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r84 = 0;
    if (unlikely(!cpy_r_r84)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 716, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL42: ;
    cpy_r_key = cpy_r_r83;
    cpy_r_r85 = PyIter_Next(cpy_r_r82);
    if (cpy_r_r85 == NULL) {
        goto CPyL90;
    } else
        goto CPyL45;
CPyL43: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r86 = 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 716, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL45: ;
    cpy_r_balances = cpy_r_r85;
    cpy_r_r87 = PyIter_Next(cpy_r_r82);
    CPy_DECREF(cpy_r_r82);
    if (cpy_r_r87 == NULL) {
        goto CPyL48;
    } else
        goto CPyL91;
CPyL46: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r88 = 0;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 716, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL48: ;
    cpy_r_r89 = CPyStatics[48]; /* 'block' */
    cpy_r_r90 = CPyObject_GetAttr(cpy_r_self, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 717, CPyStatic_globals);
        goto CPyL92;
    }
    if (PyLong_Check(cpy_r_r90))
        cpy_r_r91 = cpy_r_r90;
    else {
        cpy_r_r91 = NULL;
    }
    if (cpy_r_r91 != NULL) goto __LL46;
    if (cpy_r_r90 == Py_None)
        cpy_r_r91 = cpy_r_r90;
    else {
        cpy_r_r91 = NULL;
    }
    if (cpy_r_r91 != NULL) goto __LL46;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 717, CPyStatic_globals, "int or None", cpy_r_r90);
    goto CPyL92;
__LL46: ;
    cpy_r_r92 = (PyObject *)CPyType_TokenBalances;
    cpy_r_r93 = (CPyPtr)&((PyObject *)cpy_r_balances)->ob_type;
    cpy_r_r94 = *(PyObject * *)cpy_r_r93;
    cpy_r_r95 = cpy_r_r94 == cpy_r_r92;
    if (!cpy_r_r95) goto CPyL53;
    CPy_INCREF(cpy_r_balances);
    if (likely(Py_TYPE(cpy_r_balances) == CPyType_TokenBalances))
        cpy_r_r96 = cpy_r_balances;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 717, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_balances);
        goto CPyL93;
    }
    cpy_r_r97 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_r96)->_block;
    CPy_INCREF(cpy_r_r97);
    CPy_DECREF(cpy_r_r96);
    cpy_r_r98 = cpy_r_r97;
    goto CPyL55;
CPyL53: ;
    CPy_INCREF(cpy_r_balances);
    cpy_r_r99 = cpy_r_balances;
    cpy_r_r100 = CPyStatics[48]; /* 'block' */
    cpy_r_r101 = CPyObject_GetAttr(cpy_r_r99, cpy_r_r100);
    CPy_DECREF(cpy_r_r99);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 717, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r98 = cpy_r_r101;
CPyL55: ;
    cpy_r_r102 = PyObject_RichCompare(cpy_r_r91, cpy_r_r98, 3);
    CPy_DECREF(cpy_r_r91);
    CPy_DECREF(cpy_r_r98);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 717, CPyStatic_globals);
        goto CPyL92;
    }
    if (unlikely(!PyBool_Check(cpy_r_r102))) {
        CPy_TypeError("bool", cpy_r_r102); cpy_r_r103 = 2;
    } else
        cpy_r_r103 = cpy_r_r102 == Py_True;
    CPy_DECREF(cpy_r_r102);
    if (unlikely(cpy_r_r103 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 717, CPyStatic_globals);
        goto CPyL92;
    }
    if (cpy_r_r103) {
        goto CPyL94;
    } else
        goto CPyL72;
CPyL58: ;
    cpy_r_r104 = CPyStatics[49]; /* 'These objects are not from the same block (' */
    cpy_r_r105 = CPyStatics[48]; /* 'block' */
    cpy_r_r106 = CPyObject_GetAttr(cpy_r_self, cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 719, CPyStatic_globals);
        goto CPyL95;
    }
    if (PyLong_Check(cpy_r_r106))
        cpy_r_r107 = cpy_r_r106;
    else {
        cpy_r_r107 = NULL;
    }
    if (cpy_r_r107 != NULL) goto __LL47;
    if (cpy_r_r106 == Py_None)
        cpy_r_r107 = cpy_r_r106;
    else {
        cpy_r_r107 = NULL;
    }
    if (cpy_r_r107 != NULL) goto __LL47;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 719, CPyStatic_globals, "int or None", cpy_r_r106);
    goto CPyL95;
__LL47: ;
    cpy_r_r108 = PyObject_Str(cpy_r_r107);
    CPy_DECREF(cpy_r_r107);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 719, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r109 = CPyStatics[9]; /* ' and ' */
    cpy_r_r110 = (PyObject *)CPyType_TokenBalances;
    cpy_r_r111 = (CPyPtr)&((PyObject *)cpy_r_balances)->ob_type;
    cpy_r_r112 = *(PyObject * *)cpy_r_r111;
    cpy_r_r113 = cpy_r_r112 == cpy_r_r110;
    if (!cpy_r_r113) goto CPyL64;
    if (likely(Py_TYPE(cpy_r_balances) == CPyType_TokenBalances))
        cpy_r_r114 = cpy_r_balances;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 719, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_balances);
        goto CPyL96;
    }
    cpy_r_r115 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_r114)->_block;
    CPy_INCREF(cpy_r_r115);
    CPy_DECREF(cpy_r_r114);
    cpy_r_r116 = cpy_r_r115;
    goto CPyL66;
CPyL64: ;
    cpy_r_r117 = cpy_r_balances;
    cpy_r_r118 = CPyStatics[48]; /* 'block' */
    cpy_r_r119 = CPyObject_GetAttr(cpy_r_r117, cpy_r_r118);
    CPy_DECREF(cpy_r_r117);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 719, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r116 = cpy_r_r119;
CPyL66: ;
    cpy_r_r120 = PyObject_Str(cpy_r_r116);
    CPy_DECREF(cpy_r_r116);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 719, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r121 = CPyStatics[10]; /* ')' */
    cpy_r_r122 = CPyStr_Build(5, cpy_r_r104, cpy_r_r108, cpy_r_r109, cpy_r_r120, cpy_r_r121);
    CPy_DECREF(cpy_r_r108);
    CPy_DECREF(cpy_r_r120);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 719, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r123 = CPyModule_builtins;
    cpy_r_r124 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r125 = CPyObject_GetAttr(cpy_r_r123, cpy_r_r124);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 718, CPyStatic_globals);
        goto CPyL97;
    }
    PyObject *cpy_r_r126[1] = {cpy_r_r122};
    cpy_r_r127 = (PyObject **)&cpy_r_r126;
    cpy_r_r128 = _PyObject_Vectorcall(cpy_r_r125, cpy_r_r127, 1, 0);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 718, CPyStatic_globals);
        goto CPyL97;
    }
    CPy_DECREF(cpy_r_r122);
    CPy_Raise(cpy_r_r128);
    CPy_DECREF(cpy_r_r128);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 718, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_Unreachable();
CPyL72: ;
    cpy_r_r129 = CPyStatics[63]; /* '__validateitem' */
    PyObject *cpy_r_r130[3] = {cpy_r_self, cpy_r_key, cpy_r_balances};
    cpy_r_r131 = (PyObject **)&cpy_r_r130;
    cpy_r_r132 = PyObject_VectorcallMethod(cpy_r_r129, cpy_r_r131, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 721, CPyStatic_globals);
        goto CPyL92;
    } else
        goto CPyL98;
CPyL73: ;
    cpy_r_r133 = CPyDict_GetItem(cpy_r_self, cpy_r_key);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 722, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r134 = PyNumber_InPlaceAdd(cpy_r_r133, cpy_r_balances);
    CPy_DECREF(cpy_r_r133);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 722, CPyStatic_globals);
        goto CPyL99;
    }
    cpy_r_r135 = CPyDict_SetItem(cpy_r_self, cpy_r_key, cpy_r_r134);
    CPy_DECREF(cpy_r_key);
    CPy_DECREF(cpy_r_r134);
    cpy_r_r136 = cpy_r_r135 >= 0;
    if (unlikely(!cpy_r_r136)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 722, CPyStatic_globals);
        goto CPyL88;
    } else
        goto CPyL36;
CPyL76: ;
    cpy_r_r137 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r137)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 716, CPyStatic_globals);
        goto CPyL78;
    }
    return 1;
CPyL78: ;
    cpy_r_r138 = 2;
    return cpy_r_r138;
CPyL79: ;
    CPy_INCREF(cpy_r_seed);
    goto CPyL2;
CPyL80: ;
    CPy_INCREF(cpy_r_block);
    goto CPyL4;
CPyL81: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_block);
    goto CPyL78;
CPyL82: ;
    CPy_DECREF(cpy_r_r11);
    goto CPyL8;
CPyL83: ;
    CPy_DecRef(cpy_r_seed);
    goto CPyL78;
CPyL84: ;
    CPy_DECREF(cpy_r_seed);
    goto CPyL19;
CPyL85: ;
    CPy_DecRef(cpy_r_r66);
    goto CPyL78;
CPyL86: ;
    CPy_DecRef(cpy_r_r72);
    goto CPyL78;
CPyL87: ;
    CPy_DECREF(cpy_r_r79);
    goto CPyL76;
CPyL88: ;
    CPy_DecRef(cpy_r_r79);
    goto CPyL78;
CPyL89: ;
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r82);
    goto CPyL40;
CPyL90: ;
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r82);
    CPy_DECREF(cpy_r_key);
    goto CPyL43;
CPyL91: ;
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_key);
    CPy_DECREF(cpy_r_balances);
    CPy_DECREF(cpy_r_r87);
    goto CPyL46;
CPyL92: ;
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_key);
    CPy_DecRef(cpy_r_balances);
    goto CPyL78;
CPyL93: ;
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_key);
    CPy_DecRef(cpy_r_balances);
    CPy_DecRef(cpy_r_r91);
    goto CPyL78;
CPyL94: ;
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_key);
    goto CPyL58;
CPyL95: ;
    CPy_DecRef(cpy_r_balances);
    goto CPyL78;
CPyL96: ;
    CPy_DecRef(cpy_r_r108);
    goto CPyL78;
CPyL97: ;
    CPy_DecRef(cpy_r_r122);
    goto CPyL78;
CPyL98: ;
    CPy_DECREF(cpy_r_r132);
    goto CPyL73;
CPyL99: ;
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_key);
    goto CPyL78;
}

PyObject *CPyPy_WalletBalances_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"seed", "block", 0};
    PyObject *obj_seed = NULL;
    PyObject *obj_block = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|O$O", "__init__", kwlist, &obj_seed, &obj_block)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_seed;
    if (obj_seed == NULL) {
        arg_seed = NULL;
        goto __LL48;
    }
    if (PyDict_Check(obj_seed))
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL48;
    arg_seed = obj_seed;
    if (arg_seed != NULL) goto __LL48;
    if (obj_seed == Py_None)
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL48;
    CPy_TypeError("union[dict, object, None]", obj_seed); 
    goto fail;
__LL48: ;
    PyObject *arg_block;
    if (obj_block == NULL) {
        arg_block = NULL;
        goto __LL49;
    }
    if (PyLong_Check(obj_block))
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL49;
    if (obj_block == Py_None)
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL49;
    CPy_TypeError("int or None", obj_block); 
    goto fail;
__LL49: ;
    char retval = CPyDef_WalletBalances_____init__(arg_self, arg_seed, arg_block);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 697, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances___assets(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[57]; /* 'assets' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "assets", 732, CPyStatic_globals);
        goto CPyL4;
    }
    if (Py_TYPE(cpy_r_r1) == CPyType_TokenBalances)
        cpy_r_r2 = cpy_r_r1;
    else {
        cpy_r_r2 = NULL;
    }
    if (cpy_r_r2 != NULL) goto __LL50;
    if (PyDict_Check(cpy_r_r1))
        cpy_r_r2 = cpy_r_r1;
    else {
        cpy_r_r2 = NULL;
    }
    if (cpy_r_r2 != NULL) goto __LL50;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "assets", 732, CPyStatic_globals, "union[eth_portfolio.typing.TokenBalances, dict]", cpy_r_r1);
    goto CPyL4;
__LL50: ;
    if (likely(Py_TYPE(cpy_r_r2) == CPyType_TokenBalances))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "assets", 732, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r2);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy_WalletBalances___assets(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":assets", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances___assets(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "assets", 725, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances___debt(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[58]; /* 'debt' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "debt", 742, CPyStatic_globals);
        goto CPyL4;
    }
    if (Py_TYPE(cpy_r_r1) == CPyType_TokenBalances)
        cpy_r_r2 = cpy_r_r1;
    else {
        cpy_r_r2 = NULL;
    }
    if (cpy_r_r2 != NULL) goto __LL51;
    if (PyDict_Check(cpy_r_r1))
        cpy_r_r2 = cpy_r_r1;
    else {
        cpy_r_r2 = NULL;
    }
    if (cpy_r_r2 != NULL) goto __LL51;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "debt", 742, CPyStatic_globals, "union[eth_portfolio.typing.TokenBalances, dict]", cpy_r_r1);
    goto CPyL4;
__LL51: ;
    if (likely(PyDict_Check(cpy_r_r2)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "debt", 742, CPyStatic_globals, "dict", cpy_r_r2);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy_WalletBalances___debt(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":debt", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances___debt(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "debt", 735, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances___external(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[59]; /* 'external' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "external", 752, CPyStatic_globals);
        goto CPyL4;
    }
    if (Py_TYPE(cpy_r_r1) == CPyType_TokenBalances)
        cpy_r_r2 = cpy_r_r1;
    else {
        cpy_r_r2 = NULL;
    }
    if (cpy_r_r2 != NULL) goto __LL52;
    if (PyDict_Check(cpy_r_r1))
        cpy_r_r2 = cpy_r_r1;
    else {
        cpy_r_r2 = NULL;
    }
    if (cpy_r_r2 != NULL) goto __LL52;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "external", 752, CPyStatic_globals, "union[eth_portfolio.typing.TokenBalances, dict]", cpy_r_r1);
    goto CPyL4;
__LL52: ;
    if (likely(PyDict_Check(cpy_r_r2)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "external", 752, CPyStatic_globals, "dict", cpy_r_r2);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy_WalletBalances___external(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":external", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances___external(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "external", 745, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances___dataframe(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    int64_t cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    tuple_T4CIOO cpy_r_r5;
    CPyTagged cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_df;
    PyObject *cpy_r_r22;
    int32_t cpy_r_r23;
    char cpy_r_r24;
    int32_t cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    CPyPtr cpy_r_r29;
    int64_t cpy_r_r30;
    CPyTagged cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject **cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject **cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 762, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r1 = 0;
    cpy_r_r2 = PyDict_Size(cpy_r_self);
    cpy_r_r3 = cpy_r_r2 << 1;
    cpy_r_r4 = CPyDict_GetItemsIter(cpy_r_self);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 763, CPyStatic_globals);
        goto CPyL25;
    }
CPyL2: ;
    cpy_r_r5 = CPyDict_NextItem(cpy_r_r4, cpy_r_r1);
    cpy_r_r6 = cpy_r_r5.f1;
    cpy_r_r1 = cpy_r_r6;
    cpy_r_r7 = cpy_r_r5.f0;
    if (!cpy_r_r7) goto CPyL26;
    cpy_r_r8 = cpy_r_r5.f2;
    CPy_INCREF(cpy_r_r8);
    cpy_r_r9 = cpy_r_r5.f3;
    CPy_INCREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r5.f2);
    CPy_DECREF(cpy_r_r5.f3);
    if (likely(PyUnicode_Check(cpy_r_r8)))
        cpy_r_r10 = cpy_r_r8;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "dataframe", 763, CPyStatic_globals, "str", cpy_r_r8);
        goto CPyL27;
    }
    if (Py_TYPE(cpy_r_r9) == CPyType_TokenBalances)
        cpy_r_r11 = cpy_r_r9;
    else {
        cpy_r_r11 = NULL;
    }
    if (cpy_r_r11 != NULL) goto __LL53;
    if (PyDict_Check(cpy_r_r9))
        cpy_r_r11 = cpy_r_r9;
    else {
        cpy_r_r11 = NULL;
    }
    if (cpy_r_r11 != NULL) goto __LL53;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "dataframe", 763, CPyStatic_globals, "union[eth_portfolio.typing.TokenBalances, dict]", cpy_r_r9);
    goto CPyL28;
__LL53: ;
    cpy_r_r12 = (PyObject *)CPyType_TokenBalances;
    cpy_r_r13 = (CPyPtr)&((PyObject *)cpy_r_r11)->ob_type;
    cpy_r_r14 = *(PyObject * *)cpy_r_r13;
    cpy_r_r15 = cpy_r_r14 == cpy_r_r12;
    if (!cpy_r_r15) goto CPyL9;
    if (likely(Py_TYPE(cpy_r_r11) == CPyType_TokenBalances))
        cpy_r_r16 = cpy_r_r11;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "dataframe", 764, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r11);
        goto CPyL29;
    }
    cpy_r_r17 = CPyDef_TokenBalances___dataframe(cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 764, CPyStatic_globals);
        goto CPyL29;
    }
CPyL8: ;
    cpy_r_r18 = cpy_r_r17;
    goto CPyL11;
CPyL9: ;
    cpy_r_r19 = cpy_r_r11;
    cpy_r_r20 = CPyStatics[64]; /* 'dataframe' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 764, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r18 = cpy_r_r21;
CPyL11: ;
    cpy_r_df = cpy_r_r18;
    cpy_r_r22 = CPyStatics[65]; /* 'category' */
    cpy_r_r23 = PyObject_SetItem(cpy_r_df, cpy_r_r22, cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    cpy_r_r24 = cpy_r_r23 >= 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 765, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r25 = PyList_Append(cpy_r_r0, cpy_r_df);
    CPy_DECREF(cpy_r_df);
    cpy_r_r26 = cpy_r_r25 >= 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 766, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r27 = CPyDict_CheckSize(cpy_r_self, cpy_r_r3);
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 763, CPyStatic_globals);
        goto CPyL31;
    } else
        goto CPyL2;
CPyL14: ;
    cpy_r_r28 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 763, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r29 = (CPyPtr)&((PyVarObject *)cpy_r_r0)->ob_size;
    cpy_r_r30 = *(int64_t *)cpy_r_r29;
    cpy_r_r31 = cpy_r_r30 << 1;
    cpy_r_r32 = cpy_r_r31 != 0;
    if (!cpy_r_r32) goto CPyL32;
    cpy_r_r33 = CPyStatic_globals;
    cpy_r_r34 = CPyStatics[52]; /* 'concat' */
    cpy_r_r35 = CPyDict_GetItem(cpy_r_r33, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 767, CPyStatic_globals);
        goto CPyL25;
    }
    PyObject *cpy_r_r36[1] = {cpy_r_r0};
    cpy_r_r37 = (PyObject **)&cpy_r_r36;
    cpy_r_r38 = _PyObject_Vectorcall(cpy_r_r35, cpy_r_r37, 1, 0);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 767, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_r0);
    cpy_r_r39 = CPyStatics[34]; /* 'reset_index' */
    cpy_r_r40 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r41[2] = {cpy_r_r38, cpy_r_r40};
    cpy_r_r42 = (PyObject **)&cpy_r_r41;
    cpy_r_r43 = CPyStatics[143]; /* ('drop',) */
    cpy_r_r44 = PyObject_VectorcallMethod(cpy_r_r39, cpy_r_r42, 9223372036854775809ULL, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 767, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_DECREF(cpy_r_r38);
    cpy_r_r45 = cpy_r_r44;
    goto CPyL23;
CPyL20: ;
    cpy_r_r46 = CPyStatic_globals;
    cpy_r_r47 = CPyStatics[32]; /* 'DataFrame' */
    cpy_r_r48 = CPyDict_GetItem(cpy_r_r46, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 767, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r49 = _PyObject_Vectorcall(cpy_r_r48, 0, 0, 0);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 767, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r45 = cpy_r_r49;
CPyL23: ;
    return cpy_r_r45;
CPyL24: ;
    cpy_r_r50 = NULL;
    return cpy_r_r50;
CPyL25: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL24;
CPyL26: ;
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r5.f2);
    CPy_DECREF(cpy_r_r5.f3);
    goto CPyL14;
CPyL27: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r9);
    goto CPyL24;
CPyL28: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r10);
    goto CPyL24;
CPyL29: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r10);
    goto CPyL24;
CPyL30: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_df);
    goto CPyL24;
CPyL31: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    goto CPyL24;
CPyL32: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL20;
CPyL33: ;
    CPy_DecRef(cpy_r_r38);
    goto CPyL24;
}

PyObject *CPyPy_WalletBalances___dataframe(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":dataframe", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances___dataframe(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 755, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances___sum_usd(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    cpy_r_r0 = CPyStatics[57]; /* 'assets' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals);
        goto CPyL12;
    }
    if (likely(Py_TYPE(cpy_r_r1) == CPyType_TokenBalances))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r1);
        goto CPyL12;
    }
    cpy_r_r3 = CPyDef_TokenBalances___sum_usd(cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r4 = CPyStatics[58]; /* 'debt' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_self, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals);
        goto CPyL13;
    }
    if (likely(PyDict_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals, "dict", cpy_r_r5);
        goto CPyL13;
    }
    cpy_r_r7 = CPyStatics[66]; /* 'sum_usd' */
    PyObject *cpy_r_r8[1] = {cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_DECREF(cpy_r_r6);
    cpy_r_r11 = PyNumber_Subtract(cpy_r_r3, cpy_r_r10);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r12 = CPyStatics[59]; /* 'external' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_self, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals);
        goto CPyL15;
    }
    if (likely(PyDict_Check(cpy_r_r13)))
        cpy_r_r14 = cpy_r_r13;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals, "dict", cpy_r_r13);
        goto CPyL15;
    }
    cpy_r_r15 = CPyStatics[66]; /* 'sum_usd' */
    PyObject *cpy_r_r16[1] = {cpy_r_r14};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = PyObject_VectorcallMethod(cpy_r_r15, cpy_r_r17, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_DECREF(cpy_r_r14);
    cpy_r_r19 = PyNumber_Add(cpy_r_r11, cpy_r_r18);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 782, CPyStatic_globals);
        goto CPyL12;
    }
    return cpy_r_r19;
CPyL12: ;
    cpy_r_r20 = NULL;
    return cpy_r_r20;
CPyL13: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL12;
CPyL14: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r6);
    goto CPyL12;
CPyL15: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL12;
CPyL16: ;
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r14);
    goto CPyL12;
}

PyObject *CPyPy_WalletBalances___sum_usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":sum_usd", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances___sum_usd(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 769, CPyStatic_globals);
    return NULL;
}

char CPyDef_WalletBalances_____bool__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    cpy_r_r0 = CPyDict_ValuesView(cpy_r_self);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 796, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r1 = CPyModule_builtins;
    cpy_r_r2 = CPyStatics[42]; /* 'any' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 796, CPyStatic_globals);
        goto CPyL6;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 796, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!PyBool_Check(cpy_r_r6))) {
        CPy_TypeError("bool", cpy_r_r6); cpy_r_r7 = 2;
    } else
        cpy_r_r7 = cpy_r_r6 == Py_True;
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 796, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r7;
CPyL5: ;
    cpy_r_r8 = 2;
    return cpy_r_r8;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_WalletBalances_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__bool__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    char retval = CPyDef_WalletBalances_____bool__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 784, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances_____repr__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[67]; /* 'WalletBalances ' */
    cpy_r_r1 = PyDict_Copy(cpy_r_self);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 805, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r2 = PyObject_Str(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 805, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r3 = CPyStr_Build(2, cpy_r_r0, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 805, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy_WalletBalances_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__repr__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances_____repr__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 798, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
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
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    CPyTagged cpy_r_r58;
    int64_t cpy_r_r59;
    CPyTagged cpy_r_r60;
    PyObject *cpy_r_r61;
    tuple_T4CIOO cpy_r_r62;
    CPyTagged cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_category;
    PyObject *cpy_r_balances;
    int32_t cpy_r_r69;
    char cpy_r_r70;
    char cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    int32_t cpy_r_r74;
    char cpy_r_r75;
    char cpy_r_r76;
    char cpy_r_r77;
    CPyTagged cpy_r_r78;
    int64_t cpy_r_r79;
    CPyTagged cpy_r_r80;
    PyObject *cpy_r_r81;
    tuple_T4CIOO cpy_r_r82;
    CPyTagged cpy_r_r83;
    char cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    int32_t cpy_r_r89;
    char cpy_r_r90;
    char cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    int32_t cpy_r_r94;
    char cpy_r_r95;
    char cpy_r_r96;
    char cpy_r_r97;
    PyObject *cpy_r_r98;
    cpy_r_r0 = (PyObject *)CPyType_WalletBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 828, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r11 = CPyStatics[68]; /* ' is not a WalletBalances object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 828, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 828, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 828, CPyStatic_globals);
        goto CPyL55;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 828, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 828, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = CPyStatics[48]; /* 'block' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_self, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 829, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r24))
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL54;
    if (cpy_r_r24 == Py_None)
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL54;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 829, CPyStatic_globals, "int or None", cpy_r_r24);
    goto CPyL53;
__LL54: ;
    cpy_r_r26 = CPyStatics[48]; /* 'block' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_other, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 829, CPyStatic_globals);
        goto CPyL56;
    }
    if (PyLong_Check(cpy_r_r27))
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL55;
    if (cpy_r_r27 == Py_None)
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL55;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 829, CPyStatic_globals, "int or None", cpy_r_r27);
    goto CPyL56;
__LL55: ;
    cpy_r_r29 = PyObject_RichCompare(cpy_r_r25, cpy_r_r28, 3);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 829, CPyStatic_globals);
        goto CPyL53;
    }
    if (unlikely(!PyBool_Check(cpy_r_r29))) {
        CPy_TypeError("bool", cpy_r_r29); cpy_r_r30 = 2;
    } else
        cpy_r_r30 = cpy_r_r29 == Py_True;
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 829, CPyStatic_globals);
        goto CPyL53;
    }
    if (!cpy_r_r30) goto CPyL26;
    cpy_r_r31 = CPyStatics[69]; /* ('These WalletBalances objects are not from the same '
                                   'block (') */
    cpy_r_r32 = CPyStatics[48]; /* 'block' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_self, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 831, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r33))
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL56;
    if (cpy_r_r33 == Py_None)
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL56;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 831, CPyStatic_globals, "int or None", cpy_r_r33);
    goto CPyL53;
__LL56: ;
    cpy_r_r35 = PyObject_Str(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 831, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r36 = CPyStatics[9]; /* ' and ' */
    cpy_r_r37 = CPyStatics[48]; /* 'block' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_other, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 831, CPyStatic_globals);
        goto CPyL57;
    }
    if (PyLong_Check(cpy_r_r38))
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL57;
    if (cpy_r_r38 == Py_None)
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL57;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 831, CPyStatic_globals, "int or None", cpy_r_r38);
    goto CPyL57;
__LL57: ;
    cpy_r_r40 = PyObject_Str(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 831, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r41 = CPyStatics[10]; /* ')' */
    cpy_r_r42 = CPyStr_Build(5, cpy_r_r31, cpy_r_r35, cpy_r_r36, cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 831, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r43 = CPyModule_builtins;
    cpy_r_r44 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 830, CPyStatic_globals);
        goto CPyL58;
    }
    PyObject *cpy_r_r46[1] = {cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 830, CPyStatic_globals);
        goto CPyL58;
    }
    CPy_DECREF(cpy_r_r42);
    CPy_Raise(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 830, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_r49 = CPyStatics[48]; /* 'block' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_self, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 834, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r50))
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL58;
    if (cpy_r_r50 == Py_None)
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL58;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 834, CPyStatic_globals, "int or None", cpy_r_r50);
    goto CPyL53;
__LL58: ;
    cpy_r_r52 = (PyObject *)CPyType_WalletBalances;
    PyObject *cpy_r_r53[1] = {cpy_r_r51};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = CPyStatics[144]; /* ('block',) */
    cpy_r_r56 = _PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 0, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 834, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_DECREF(cpy_r_r51);
    if (likely(PyDict_Check(cpy_r_r56)))
        cpy_r_r57 = cpy_r_r56;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 834, CPyStatic_globals, "dict", cpy_r_r56);
        goto CPyL53;
    }
    cpy_r_r58 = 0;
    cpy_r_r59 = PyDict_Size(cpy_r_self);
    cpy_r_r60 = cpy_r_r59 << 1;
    cpy_r_r61 = CPyDict_GetItemsIter(cpy_r_self);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 835, CPyStatic_globals);
        goto CPyL60;
    }
CPyL31: ;
    cpy_r_r62 = CPyDict_NextItem(cpy_r_r61, cpy_r_r58);
    cpy_r_r63 = cpy_r_r62.f1;
    cpy_r_r58 = cpy_r_r63;
    cpy_r_r64 = cpy_r_r62.f0;
    if (!cpy_r_r64) goto CPyL61;
    cpy_r_r65 = cpy_r_r62.f2;
    CPy_INCREF(cpy_r_r65);
    cpy_r_r66 = cpy_r_r62.f3;
    CPy_INCREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    if (likely(PyUnicode_Check(cpy_r_r65)))
        cpy_r_r67 = cpy_r_r65;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 835, CPyStatic_globals, "str", cpy_r_r65);
        goto CPyL62;
    }
    if (Py_TYPE(cpy_r_r66) == CPyType_TokenBalances)
        cpy_r_r68 = cpy_r_r66;
    else {
        cpy_r_r68 = NULL;
    }
    if (cpy_r_r68 != NULL) goto __LL59;
    if (PyDict_Check(cpy_r_r66))
        cpy_r_r68 = cpy_r_r66;
    else {
        cpy_r_r68 = NULL;
    }
    if (cpy_r_r68 != NULL) goto __LL59;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 835, CPyStatic_globals, "union[eth_portfolio.typing.TokenBalances, dict]", cpy_r_r66);
    goto CPyL63;
__LL59: ;
    cpy_r_category = cpy_r_r67;
    cpy_r_balances = cpy_r_r68;
    cpy_r_r69 = PyObject_IsTrue(cpy_r_balances);
    cpy_r_r70 = cpy_r_r69 >= 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 835, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r71 = cpy_r_r69;
    if (!cpy_r_r71) goto CPyL65;
    cpy_r_r72 = CPyDict_GetItem(cpy_r_r57, cpy_r_category);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 837, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r73 = PyNumber_InPlaceAdd(cpy_r_r72, cpy_r_balances);
    CPy_DECREF(cpy_r_r72);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 837, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r74 = CPyDict_SetItem(cpy_r_r57, cpy_r_category, cpy_r_r73);
    CPy_DECREF(cpy_r_category);
    CPy_DECREF(cpy_r_r73);
    cpy_r_r75 = cpy_r_r74 >= 0;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 837, CPyStatic_globals);
        goto CPyL67;
    }
CPyL39: ;
    cpy_r_r76 = CPyDict_CheckSize(cpy_r_self, cpy_r_r60);
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 835, CPyStatic_globals);
        goto CPyL67;
    } else
        goto CPyL31;
CPyL40: ;
    cpy_r_r77 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r77)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 835, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r78 = 0;
    cpy_r_r79 = PyDict_Size(cpy_r_other);
    cpy_r_r80 = cpy_r_r79 << 1;
    cpy_r_r81 = CPyDict_GetItemsIter(cpy_r_other);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 838, CPyStatic_globals);
        goto CPyL60;
    }
CPyL42: ;
    cpy_r_r82 = CPyDict_NextItem(cpy_r_r81, cpy_r_r78);
    cpy_r_r83 = cpy_r_r82.f1;
    cpy_r_r78 = cpy_r_r83;
    cpy_r_r84 = cpy_r_r82.f0;
    if (!cpy_r_r84) goto CPyL68;
    cpy_r_r85 = cpy_r_r82.f2;
    CPy_INCREF(cpy_r_r85);
    cpy_r_r86 = cpy_r_r82.f3;
    CPy_INCREF(cpy_r_r86);
    CPy_DECREF(cpy_r_r82.f2);
    CPy_DECREF(cpy_r_r82.f3);
    if (likely(PyUnicode_Check(cpy_r_r85)))
        cpy_r_r87 = cpy_r_r85;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 838, CPyStatic_globals, "str", cpy_r_r85);
        goto CPyL69;
    }
    if (Py_TYPE(cpy_r_r86) == CPyType_TokenBalances)
        cpy_r_r88 = cpy_r_r86;
    else {
        cpy_r_r88 = NULL;
    }
    if (cpy_r_r88 != NULL) goto __LL60;
    if (PyDict_Check(cpy_r_r86))
        cpy_r_r88 = cpy_r_r86;
    else {
        cpy_r_r88 = NULL;
    }
    if (cpy_r_r88 != NULL) goto __LL60;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 838, CPyStatic_globals, "union[eth_portfolio.typing.TokenBalances, dict]", cpy_r_r86);
    goto CPyL70;
__LL60: ;
    cpy_r_category = cpy_r_r87;
    cpy_r_balances = cpy_r_r88;
    cpy_r_r89 = PyObject_IsTrue(cpy_r_balances);
    cpy_r_r90 = cpy_r_r89 >= 0;
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 835, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r91 = cpy_r_r89;
    if (!cpy_r_r91) goto CPyL72;
    cpy_r_r92 = CPyDict_GetItem(cpy_r_r57, cpy_r_category);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 840, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r93 = PyNumber_InPlaceAdd(cpy_r_r92, cpy_r_balances);
    CPy_DECREF(cpy_r_r92);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 840, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r94 = CPyDict_SetItem(cpy_r_r57, cpy_r_category, cpy_r_r93);
    CPy_DECREF(cpy_r_category);
    CPy_DECREF(cpy_r_r93);
    cpy_r_r95 = cpy_r_r94 >= 0;
    if (unlikely(!cpy_r_r95)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 840, CPyStatic_globals);
        goto CPyL74;
    }
CPyL50: ;
    cpy_r_r96 = CPyDict_CheckSize(cpy_r_other, cpy_r_r80);
    if (unlikely(!cpy_r_r96)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 838, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL42;
CPyL51: ;
    cpy_r_r97 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r97)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 838, CPyStatic_globals);
        goto CPyL60;
    }
    return cpy_r_r57;
CPyL53: ;
    cpy_r_r98 = NULL;
    return cpy_r_r98;
CPyL54: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL53;
CPyL55: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL53;
CPyL56: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL53;
CPyL57: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL53;
CPyL58: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL53;
CPyL59: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL53;
CPyL60: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL53;
CPyL61: ;
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    goto CPyL40;
CPyL62: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r66);
    goto CPyL53;
CPyL63: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r67);
    goto CPyL53;
CPyL64: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_category);
    CPy_DecRef(cpy_r_balances);
    goto CPyL53;
CPyL65: ;
    CPy_DECREF(cpy_r_category);
    CPy_DECREF(cpy_r_balances);
    goto CPyL39;
CPyL66: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_category);
    goto CPyL53;
CPyL67: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    goto CPyL53;
CPyL68: ;
    CPy_DECREF(cpy_r_r81);
    CPy_DECREF(cpy_r_r82.f2);
    CPy_DECREF(cpy_r_r82.f3);
    goto CPyL51;
CPyL69: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r81);
    CPy_DecRef(cpy_r_r86);
    goto CPyL53;
CPyL70: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r81);
    CPy_DecRef(cpy_r_r87);
    goto CPyL53;
CPyL71: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_category);
    CPy_DecRef(cpy_r_balances);
    CPy_DecRef(cpy_r_r81);
    goto CPyL53;
CPyL72: ;
    CPy_DECREF(cpy_r_category);
    CPy_DECREF(cpy_r_balances);
    goto CPyL50;
CPyL73: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_category);
    CPy_DecRef(cpy_r_r81);
    goto CPyL53;
CPyL74: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r81);
    goto CPyL53;
}

PyObject *CPyPy_WalletBalances_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyDict_Check(obj_other)))
        arg_other = obj_other;
    else {
        CPy_TypeError("dict", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances_____add__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 807, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    CPy_INCREF(cpy_r_self);
    if (likely(PyDict_Check(cpy_r_self)))
        cpy_r_r0 = cpy_r_self;
    else {
        CPy_TypeError("dict", cpy_r_self); 
        cpy_r_r0 = NULL;
    }
    if (cpy_r_r0 == NULL) goto CPyL5;
    CPy_INCREF(cpy_r_other);
    if (likely(PyDict_Check(cpy_r_other)))
        cpy_r_r1 = cpy_r_other;
    else {
        CPy_TypeError("dict", cpy_r_other); 
        cpy_r_r1 = NULL;
    }
    if (cpy_r_r1 == NULL) goto CPyL6;
    cpy_r_r2 = CPyDef_WalletBalances_____add__(cpy_r_r0, cpy_r_r1);
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL5;
    if (likely(PyObject_TypeCheck(cpy_r_r2, CPyType__SummableNonNumericMixin)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", cpy_r_r2); 
        cpy_r_r3 = NULL;
    }
    if (cpy_r_r3 == NULL) goto CPyL5;
    return cpy_r_r3;
CPyL5: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
CPyL6: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_WalletBalances_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add_____SummableNonNumericMixin_glue", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WalletBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyObject_TypeCheck(obj_other, CPyType__SummableNonNumericMixin)))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances_____add___3___SummableNonNumericMixin_glue(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add_____SummableNonNumericMixin_glue", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
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
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    CPyTagged cpy_r_r58;
    int64_t cpy_r_r59;
    CPyTagged cpy_r_r60;
    PyObject *cpy_r_r61;
    tuple_T4CIOO cpy_r_r62;
    CPyTagged cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_category;
    PyObject *cpy_r_balances;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    int32_t cpy_r_r71;
    char cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    PyObject *cpy_r_r75;
    CPyTagged cpy_r_r76;
    int64_t cpy_r_r77;
    CPyTagged cpy_r_r78;
    PyObject *cpy_r_r79;
    tuple_T4CIOO cpy_r_r80;
    CPyTagged cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    int32_t cpy_r_r87;
    char cpy_r_r88;
    char cpy_r_r89;
    int32_t cpy_r_r90;
    char cpy_r_r91;
    char cpy_r_r92;
    char cpy_r_r93;
    PyObject *cpy_r_r94;
    cpy_r_r0 = (PyObject *)CPyType_WalletBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 864, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r11 = CPyStatics[68]; /* ' is not a WalletBalances object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 864, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 864, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 864, CPyStatic_globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 864, CPyStatic_globals);
        goto CPyL52;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 864, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = CPyStatics[48]; /* 'block' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_self, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 865, CPyStatic_globals);
        goto CPyL50;
    }
    if (PyLong_Check(cpy_r_r24))
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL61;
    if (cpy_r_r24 == Py_None)
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL61;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 865, CPyStatic_globals, "int or None", cpy_r_r24);
    goto CPyL50;
__LL61: ;
    cpy_r_r26 = CPyStatics[48]; /* 'block' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_other, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 865, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r27))
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL62;
    if (cpy_r_r27 == Py_None)
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL62;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 865, CPyStatic_globals, "int or None", cpy_r_r27);
    goto CPyL53;
__LL62: ;
    cpy_r_r29 = PyObject_RichCompare(cpy_r_r25, cpy_r_r28, 3);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 865, CPyStatic_globals);
        goto CPyL50;
    }
    if (unlikely(!PyBool_Check(cpy_r_r29))) {
        CPy_TypeError("bool", cpy_r_r29); cpy_r_r30 = 2;
    } else
        cpy_r_r30 = cpy_r_r29 == Py_True;
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 865, CPyStatic_globals);
        goto CPyL50;
    }
    if (!cpy_r_r30) goto CPyL26;
    cpy_r_r31 = CPyStatics[69]; /* ('These WalletBalances objects are not from the same '
                                   'block (') */
    cpy_r_r32 = CPyStatics[48]; /* 'block' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_self, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 867, CPyStatic_globals);
        goto CPyL50;
    }
    if (PyLong_Check(cpy_r_r33))
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL63;
    if (cpy_r_r33 == Py_None)
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL63;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 867, CPyStatic_globals, "int or None", cpy_r_r33);
    goto CPyL50;
__LL63: ;
    cpy_r_r35 = PyObject_Str(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 867, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r36 = CPyStatics[9]; /* ' and ' */
    cpy_r_r37 = CPyStatics[48]; /* 'block' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_other, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 867, CPyStatic_globals);
        goto CPyL54;
    }
    if (PyLong_Check(cpy_r_r38))
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL64;
    if (cpy_r_r38 == Py_None)
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL64;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 867, CPyStatic_globals, "int or None", cpy_r_r38);
    goto CPyL54;
__LL64: ;
    cpy_r_r40 = PyObject_Str(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 867, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r41 = CPyStatics[10]; /* ')' */
    cpy_r_r42 = CPyStr_Build(5, cpy_r_r31, cpy_r_r35, cpy_r_r36, cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 867, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r43 = CPyModule_builtins;
    cpy_r_r44 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 866, CPyStatic_globals);
        goto CPyL55;
    }
    PyObject *cpy_r_r46[1] = {cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 866, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_DECREF(cpy_r_r42);
    CPy_Raise(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 866, CPyStatic_globals);
        goto CPyL50;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_r49 = CPyStatics[48]; /* 'block' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_self, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 870, CPyStatic_globals);
        goto CPyL50;
    }
    if (PyLong_Check(cpy_r_r50))
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL65;
    if (cpy_r_r50 == Py_None)
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL65;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 870, CPyStatic_globals, "int or None", cpy_r_r50);
    goto CPyL50;
__LL65: ;
    cpy_r_r52 = (PyObject *)CPyType_WalletBalances;
    PyObject *cpy_r_r53[2] = {cpy_r_self, cpy_r_r51};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = CPyStatics[144]; /* ('block',) */
    cpy_r_r56 = _PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 1, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 870, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_DECREF(cpy_r_r51);
    if (likely(PyDict_Check(cpy_r_r56)))
        cpy_r_r57 = cpy_r_r56;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 870, CPyStatic_globals, "dict", cpy_r_r56);
        goto CPyL50;
    }
    cpy_r_r58 = 0;
    cpy_r_r59 = PyDict_Size(cpy_r_other);
    cpy_r_r60 = cpy_r_r59 << 1;
    cpy_r_r61 = CPyDict_GetItemsIter(cpy_r_other);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 871, CPyStatic_globals);
        goto CPyL57;
    }
CPyL31: ;
    cpy_r_r62 = CPyDict_NextItem(cpy_r_r61, cpy_r_r58);
    cpy_r_r63 = cpy_r_r62.f1;
    cpy_r_r58 = cpy_r_r63;
    cpy_r_r64 = cpy_r_r62.f0;
    if (!cpy_r_r64) goto CPyL58;
    cpy_r_r65 = cpy_r_r62.f2;
    CPy_INCREF(cpy_r_r65);
    cpy_r_r66 = cpy_r_r62.f3;
    CPy_INCREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    if (likely(PyUnicode_Check(cpy_r_r65)))
        cpy_r_r67 = cpy_r_r65;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 871, CPyStatic_globals, "str", cpy_r_r65);
        goto CPyL59;
    }
    if (Py_TYPE(cpy_r_r66) == CPyType_TokenBalances)
        cpy_r_r68 = cpy_r_r66;
    else {
        cpy_r_r68 = NULL;
    }
    if (cpy_r_r68 != NULL) goto __LL66;
    if (PyDict_Check(cpy_r_r66))
        cpy_r_r68 = cpy_r_r66;
    else {
        cpy_r_r68 = NULL;
    }
    if (cpy_r_r68 != NULL) goto __LL66;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 871, CPyStatic_globals, "union[eth_portfolio.typing.TokenBalances, dict]", cpy_r_r66);
    goto CPyL60;
__LL66: ;
    cpy_r_category = cpy_r_r67;
    cpy_r_balances = cpy_r_r68;
    cpy_r_r69 = CPyDict_GetItem(cpy_r_r57, cpy_r_category);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 872, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r70 = PyNumber_InPlaceSubtract(cpy_r_r69, cpy_r_balances);
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 872, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r71 = CPyDict_SetItem(cpy_r_r57, cpy_r_category, cpy_r_r70);
    CPy_DECREF(cpy_r_category);
    CPy_DECREF(cpy_r_r70);
    cpy_r_r72 = cpy_r_r71 >= 0;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 872, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r73 = CPyDict_CheckSize(cpy_r_other, cpy_r_r60);
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 871, CPyStatic_globals);
        goto CPyL63;
    } else
        goto CPyL31;
CPyL38: ;
    cpy_r_r74 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 871, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r75 = PyDict_Copy(cpy_r_r57);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 873, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r76 = 0;
    cpy_r_r77 = PyDict_Size(cpy_r_r75);
    cpy_r_r78 = cpy_r_r77 << 1;
    cpy_r_r79 = CPyDict_GetItemsIter(cpy_r_r75);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 873, CPyStatic_globals);
        goto CPyL64;
    }
CPyL41: ;
    cpy_r_r80 = CPyDict_NextItem(cpy_r_r79, cpy_r_r76);
    cpy_r_r81 = cpy_r_r80.f1;
    cpy_r_r76 = cpy_r_r81;
    cpy_r_r82 = cpy_r_r80.f0;
    if (!cpy_r_r82) goto CPyL65;
    cpy_r_r83 = cpy_r_r80.f2;
    CPy_INCREF(cpy_r_r83);
    cpy_r_r84 = cpy_r_r80.f3;
    CPy_INCREF(cpy_r_r84);
    CPy_DECREF(cpy_r_r80.f2);
    CPy_DECREF(cpy_r_r80.f3);
    if (likely(PyUnicode_Check(cpy_r_r83)))
        cpy_r_r85 = cpy_r_r83;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 873, CPyStatic_globals, "str", cpy_r_r83);
        goto CPyL66;
    }
    if (Py_TYPE(cpy_r_r84) == CPyType_TokenBalances)
        cpy_r_r86 = cpy_r_r84;
    else {
        cpy_r_r86 = NULL;
    }
    if (cpy_r_r86 != NULL) goto __LL67;
    if (PyDict_Check(cpy_r_r84))
        cpy_r_r86 = cpy_r_r84;
    else {
        cpy_r_r86 = NULL;
    }
    if (cpy_r_r86 != NULL) goto __LL67;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 873, CPyStatic_globals, "union[eth_portfolio.typing.TokenBalances, dict]", cpy_r_r84);
    goto CPyL67;
__LL67: ;
    cpy_r_category = cpy_r_r85;
    cpy_r_balances = cpy_r_r86;
    cpy_r_r87 = PyObject_IsTrue(cpy_r_balances);
    CPy_DECREF(cpy_r_balances);
    cpy_r_r88 = cpy_r_r87 >= 0;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 871, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r89 = cpy_r_r87;
    if (cpy_r_r89) goto CPyL69;
    cpy_r_r90 = PyObject_DelItem(cpy_r_r57, cpy_r_category);
    CPy_DECREF(cpy_r_category);
    cpy_r_r91 = cpy_r_r90 >= 0;
    if (unlikely(!cpy_r_r91)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 875, CPyStatic_globals);
        goto CPyL70;
    }
CPyL47: ;
    cpy_r_r92 = CPyDict_CheckSize(cpy_r_r75, cpy_r_r78);
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 873, CPyStatic_globals);
        goto CPyL70;
    } else
        goto CPyL41;
CPyL48: ;
    cpy_r_r93 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 873, CPyStatic_globals);
        goto CPyL57;
    }
    return cpy_r_r57;
CPyL50: ;
    cpy_r_r94 = NULL;
    return cpy_r_r94;
CPyL51: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL50;
CPyL52: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL50;
CPyL53: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL50;
CPyL54: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL50;
CPyL55: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL50;
CPyL56: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL50;
CPyL57: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL50;
CPyL58: ;
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    goto CPyL38;
CPyL59: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r66);
    goto CPyL50;
CPyL60: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r67);
    goto CPyL50;
CPyL61: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_category);
    CPy_DecRef(cpy_r_balances);
    goto CPyL50;
CPyL62: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_category);
    goto CPyL50;
CPyL63: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    goto CPyL50;
CPyL64: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r75);
    goto CPyL50;
CPyL65: ;
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r80.f2);
    CPy_DECREF(cpy_r_r80.f3);
    goto CPyL48;
CPyL66: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r84);
    goto CPyL50;
CPyL67: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r85);
    goto CPyL50;
CPyL68: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_category);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r79);
    goto CPyL50;
CPyL69: ;
    CPy_DECREF(cpy_r_category);
    goto CPyL47;
CPyL70: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r79);
    goto CPyL50;
}

PyObject *CPyPy_WalletBalances_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__sub__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyDict_Check(obj_other)))
        arg_other = obj_other;
    else {
        CPy_TypeError("dict", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances_____sub__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 843, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalances_____getitem__(PyObject *cpy_r_self, PyObject *cpy_r_key) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    cpy_r_r0 = CPyStatics[70]; /* '__validatekey' */
    PyObject *cpy_r_r1[2] = {cpy_r_self, cpy_r_key};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 897, CPyStatic_globals);
        goto CPyL7;
    } else
        goto CPyL8;
CPyL1: ;
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[22]; /* 'super' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 898, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r7 = (PyObject *)CPyType_WalletBalances;
    PyObject *cpy_r_r8[2] = {cpy_r_r7, cpy_r_self};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r9, 2, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 898, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r11 = CPyStatics[26]; /* '__getitem__' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 898, CPyStatic_globals);
        goto CPyL7;
    }
    PyObject *cpy_r_r13[1] = {cpy_r_key};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 898, CPyStatic_globals);
        goto CPyL7;
    }
    if (Py_TYPE(cpy_r_r15) == CPyType_TokenBalances)
        cpy_r_r16 = cpy_r_r15;
    else {
        cpy_r_r16 = NULL;
    }
    if (cpy_r_r16 != NULL) goto __LL68;
    if (PyDict_Check(cpy_r_r15))
        cpy_r_r16 = cpy_r_r15;
    else {
        cpy_r_r16 = NULL;
    }
    if (cpy_r_r16 != NULL) goto __LL68;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__getitem__", 898, CPyStatic_globals, "union[eth_portfolio.typing.TokenBalances, dict]", cpy_r_r15);
    goto CPyL7;
__LL68: ;
    return cpy_r_r16;
CPyL7: ;
    cpy_r_r17 = NULL;
    return cpy_r_r17;
CPyL8: ;
    CPy_DECREF(cpy_r_r3);
    goto CPyL1;
}

PyObject *CPyPy_WalletBalances_____getitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", 0};
    static CPyArg_Parser parser = {"O:__getitem__", kwlist, 0};
    PyObject *obj_key;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_key)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_key;
    if (likely(PyUnicode_Check(obj_key)))
        arg_key = obj_key;
    else {
        CPy_TypeError("str", obj_key); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalances_____getitem__(arg_self, arg_key);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__getitem__", 878, CPyStatic_globals);
    return NULL;
}

char CPyDef_WalletBalances_____setitem__(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    cpy_r_r0 = CPyStatics[63]; /* '__validateitem' */
    PyObject *cpy_r_r1[3] = {cpy_r_self, cpy_r_key, cpy_r_value};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 920, CPyStatic_globals);
        goto CPyL6;
    } else
        goto CPyL7;
CPyL1: ;
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[22]; /* 'super' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 921, CPyStatic_globals);
        goto CPyL6;
    }
    cpy_r_r7 = (PyObject *)CPyType_WalletBalances;
    PyObject *cpy_r_r8[2] = {cpy_r_r7, cpy_r_self};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r9, 2, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 921, CPyStatic_globals);
        goto CPyL6;
    }
    cpy_r_r11 = CPyStatics[28]; /* '__setitem__' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 921, CPyStatic_globals);
        goto CPyL6;
    }
    PyObject *cpy_r_r13[2] = {cpy_r_key, cpy_r_value};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 2, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 921, CPyStatic_globals);
        goto CPyL6;
    } else
        goto CPyL8;
CPyL5: ;
    return 1;
CPyL6: ;
    cpy_r_r16 = 2;
    return cpy_r_r16;
CPyL7: ;
    CPy_DECREF(cpy_r_r3);
    goto CPyL1;
CPyL8: ;
    CPy_DECREF(cpy_r_r15);
    goto CPyL5;
}

PyObject *CPyPy_WalletBalances_____setitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", "value", 0};
    static CPyArg_Parser parser = {"OO:__setitem__", kwlist, 0};
    PyObject *obj_key;
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_key, &obj_value)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_key;
    if (likely(PyUnicode_Check(obj_key)))
        arg_key = obj_key;
    else {
        CPy_TypeError("str", obj_key); 
        goto fail;
    }
    PyObject *arg_value;
    if (Py_TYPE(obj_value) == CPyType_TokenBalances)
        arg_value = obj_value;
    else {
        arg_value = NULL;
    }
    if (arg_value != NULL) goto __LL69;
    if (PyDict_Check(obj_value))
        arg_value = obj_value;
    else {
        arg_value = NULL;
    }
    if (arg_value != NULL) goto __LL69;
    CPy_TypeError("union[eth_portfolio.typing.TokenBalances, dict]", obj_value); 
    goto fail;
__LL69: ;
    char retval = CPyDef_WalletBalances_____setitem__(arg_self, arg_key, arg_value);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 900, CPyStatic_globals);
    return NULL;
}

char CPyDef_WalletBalances_____validatekey(PyObject *cpy_r_self, PyObject *cpy_r_key) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    tuple_T3OOO cpy_r_r2;
    PyObject *cpy_r_r3;
    int32_t cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    tuple_T3OOO cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    cpy_r_r0 = CPyStatics[60]; /* '_keys' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 935, CPyStatic_globals);
        goto CPyL13;
    }
    PyObject *__tmp70;
    if (unlikely(!(PyTuple_Check(cpy_r_r1) && PyTuple_GET_SIZE(cpy_r_r1) == 3))) {
        __tmp70 = NULL;
        goto __LL71;
    }
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r1, 0))))
        __tmp70 = PyTuple_GET_ITEM(cpy_r_r1, 0);
    else {
        __tmp70 = NULL;
    }
    if (__tmp70 == NULL) goto __LL71;
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r1, 1))))
        __tmp70 = PyTuple_GET_ITEM(cpy_r_r1, 1);
    else {
        __tmp70 = NULL;
    }
    if (__tmp70 == NULL) goto __LL71;
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r1, 2))))
        __tmp70 = PyTuple_GET_ITEM(cpy_r_r1, 2);
    else {
        __tmp70 = NULL;
    }
    if (__tmp70 == NULL) goto __LL71;
    __tmp70 = cpy_r_r1;
__LL71: ;
    if (unlikely(__tmp70 == NULL)) {
        CPy_TypeError("tuple[str, str, str]", cpy_r_r1); cpy_r_r2 = (tuple_T3OOO) { NULL, NULL, NULL };
    } else {
        PyObject *__tmp72 = PyTuple_GET_ITEM(cpy_r_r1, 0);
        CPy_INCREF(__tmp72);
        PyObject *__tmp73;
        if (likely(PyUnicode_Check(__tmp72)))
            __tmp73 = __tmp72;
        else {
            CPy_TypeError("str", __tmp72); 
            __tmp73 = NULL;
        }
        cpy_r_r2.f0 = __tmp73;
        PyObject *__tmp74 = PyTuple_GET_ITEM(cpy_r_r1, 1);
        CPy_INCREF(__tmp74);
        PyObject *__tmp75;
        if (likely(PyUnicode_Check(__tmp74)))
            __tmp75 = __tmp74;
        else {
            CPy_TypeError("str", __tmp74); 
            __tmp75 = NULL;
        }
        cpy_r_r2.f1 = __tmp75;
        PyObject *__tmp76 = PyTuple_GET_ITEM(cpy_r_r1, 2);
        CPy_INCREF(__tmp76);
        PyObject *__tmp77;
        if (likely(PyUnicode_Check(__tmp76)))
            __tmp77 = __tmp76;
        else {
            CPy_TypeError("str", __tmp76); 
            __tmp77 = NULL;
        }
        cpy_r_r2.f2 = __tmp77;
    }
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 935, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r3 = PyTuple_New(3);
    if (unlikely(cpy_r_r3 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp78 = cpy_r_r2.f0;
    PyTuple_SET_ITEM(cpy_r_r3, 0, __tmp78);
    PyObject *__tmp79 = cpy_r_r2.f1;
    PyTuple_SET_ITEM(cpy_r_r3, 1, __tmp79);
    PyObject *__tmp80 = cpy_r_r2.f2;
    PyTuple_SET_ITEM(cpy_r_r3, 2, __tmp80);
    cpy_r_r4 = PySequence_Contains(cpy_r_r3, cpy_r_key);
    CPy_DECREF(cpy_r_r3);
    cpy_r_r5 = cpy_r_r4 >= 0;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 935, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r6 = cpy_r_r4;
    cpy_r_r7 = cpy_r_r6 ^ 1;
    if (!cpy_r_r7) goto CPyL12;
    cpy_r_r8 = CPyStatics[71]; /* ' is not a valid key for WalletBalances. Valid keys are: ' */
    cpy_r_r9 = CPyStatics[60]; /* '_keys' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_self, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 937, CPyStatic_globals);
        goto CPyL13;
    }
    PyObject *__tmp81;
    if (unlikely(!(PyTuple_Check(cpy_r_r10) && PyTuple_GET_SIZE(cpy_r_r10) == 3))) {
        __tmp81 = NULL;
        goto __LL82;
    }
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r10, 0))))
        __tmp81 = PyTuple_GET_ITEM(cpy_r_r10, 0);
    else {
        __tmp81 = NULL;
    }
    if (__tmp81 == NULL) goto __LL82;
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r10, 1))))
        __tmp81 = PyTuple_GET_ITEM(cpy_r_r10, 1);
    else {
        __tmp81 = NULL;
    }
    if (__tmp81 == NULL) goto __LL82;
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r10, 2))))
        __tmp81 = PyTuple_GET_ITEM(cpy_r_r10, 2);
    else {
        __tmp81 = NULL;
    }
    if (__tmp81 == NULL) goto __LL82;
    __tmp81 = cpy_r_r10;
__LL82: ;
    if (unlikely(__tmp81 == NULL)) {
        CPy_TypeError("tuple[str, str, str]", cpy_r_r10); cpy_r_r11 = (tuple_T3OOO) { NULL, NULL, NULL };
    } else {
        PyObject *__tmp83 = PyTuple_GET_ITEM(cpy_r_r10, 0);
        CPy_INCREF(__tmp83);
        PyObject *__tmp84;
        if (likely(PyUnicode_Check(__tmp83)))
            __tmp84 = __tmp83;
        else {
            CPy_TypeError("str", __tmp83); 
            __tmp84 = NULL;
        }
        cpy_r_r11.f0 = __tmp84;
        PyObject *__tmp85 = PyTuple_GET_ITEM(cpy_r_r10, 1);
        CPy_INCREF(__tmp85);
        PyObject *__tmp86;
        if (likely(PyUnicode_Check(__tmp85)))
            __tmp86 = __tmp85;
        else {
            CPy_TypeError("str", __tmp85); 
            __tmp86 = NULL;
        }
        cpy_r_r11.f1 = __tmp86;
        PyObject *__tmp87 = PyTuple_GET_ITEM(cpy_r_r10, 2);
        CPy_INCREF(__tmp87);
        PyObject *__tmp88;
        if (likely(PyUnicode_Check(__tmp87)))
            __tmp88 = __tmp87;
        else {
            CPy_TypeError("str", __tmp87); 
            __tmp88 = NULL;
        }
        cpy_r_r11.f2 = __tmp88;
    }
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 937, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r12 = PyTuple_New(3);
    if (unlikely(cpy_r_r12 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp89 = cpy_r_r11.f0;
    PyTuple_SET_ITEM(cpy_r_r12, 0, __tmp89);
    PyObject *__tmp90 = cpy_r_r11.f1;
    PyTuple_SET_ITEM(cpy_r_r12, 1, __tmp90);
    PyObject *__tmp91 = cpy_r_r11.f2;
    PyTuple_SET_ITEM(cpy_r_r12, 2, __tmp91);
    cpy_r_r13 = PyObject_Str(cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 937, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r14 = CPyStr_Build(3, cpy_r_key, cpy_r_r8, cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 937, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r15 = CPyModule_builtins;
    cpy_r_r16 = CPyStatics[72]; /* 'KeyError' */
    cpy_r_r17 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 936, CPyStatic_globals);
        goto CPyL14;
    }
    PyObject *cpy_r_r18[1] = {cpy_r_r14};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = _PyObject_Vectorcall(cpy_r_r17, cpy_r_r19, 1, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 936, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_DECREF(cpy_r_r14);
    CPy_Raise(cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 936, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL12: ;
    return 1;
CPyL13: ;
    cpy_r_r21 = 2;
    return cpy_r_r21;
CPyL14: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL13;
}

PyObject *CPyPy_WalletBalances_____validatekey(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", 0};
    static CPyArg_Parser parser = {"O:__validatekey", kwlist, 0};
    PyObject *obj_key;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_key)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_key;
    if (likely(PyUnicode_Check(obj_key)))
        arg_key = obj_key;
    else {
        CPy_TypeError("str", obj_key); 
        goto fail;
    }
    char retval = CPyDef_WalletBalances_____validatekey(arg_self, arg_key);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__validatekey", 923, CPyStatic_globals);
    return NULL;
}

char CPyDef_WalletBalances_____validateitem(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_item) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    int32_t cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    CPyPtr cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject **cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    char cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    CPyPtr cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject **cpy_r_r60;
    PyObject *cpy_r_r61;
    char cpy_r_r62;
    cpy_r_r0 = CPyStatics[70]; /* '__validatekey' */
    PyObject *cpy_r_r1[2] = {cpy_r_self, cpy_r_key};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 952, CPyStatic_globals);
        goto CPyL34;
    } else
        goto CPyL35;
CPyL1: ;
    cpy_r_r4 = CPyStatics[57]; /* 'assets' */
    cpy_r_r5 = PyUnicode_Compare(cpy_r_key, cpy_r_r4);
    cpy_r_r6 = cpy_r_r5 == -1;
    if (!cpy_r_r6) goto CPyL4;
    cpy_r_r7 = PyErr_Occurred();
    cpy_r_r8 = cpy_r_r7 != NULL;
    if (!cpy_r_r8) goto CPyL4;
    cpy_r_r9 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 953, CPyStatic_globals);
        goto CPyL34;
    }
CPyL4: ;
    cpy_r_r10 = cpy_r_r5 == 0;
    if (!cpy_r_r10) goto CPyL12;
    cpy_r_r11 = (PyObject *)CPyType_TokenBalances;
    cpy_r_r12 = (CPyPtr)&((PyObject *)cpy_r_item)->ob_type;
    cpy_r_r13 = *(PyObject * *)cpy_r_r12;
    cpy_r_r14 = cpy_r_r13 == cpy_r_r11;
    if (cpy_r_r14) goto CPyL33;
    cpy_r_r15 = PyObject_Str(cpy_r_item);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 956, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r16 = CPyStatics[73]; /* ' is not a valid value for "' */
    cpy_r_r17 = CPyStatics[74]; /* '". Must be a TokenBalances object.' */
    cpy_r_r18 = CPyStr_Build(4, cpy_r_r15, cpy_r_r16, cpy_r_key, cpy_r_r17);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 956, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r19 = CPyModule_builtins;
    cpy_r_r20 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 955, CPyStatic_globals);
        goto CPyL36;
    }
    PyObject *cpy_r_r22[1] = {cpy_r_r18};
    cpy_r_r23 = (PyObject **)&cpy_r_r22;
    cpy_r_r24 = _PyObject_Vectorcall(cpy_r_r21, cpy_r_r23, 1, 0);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 955, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_DECREF(cpy_r_r18);
    CPy_Raise(cpy_r_r24);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 955, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r25 = CPyStatics[58]; /* 'debt' */
    cpy_r_r26 = PyUnicode_Compare(cpy_r_key, cpy_r_r25);
    cpy_r_r27 = cpy_r_r26 == -1;
    if (!cpy_r_r27) goto CPyL15;
    cpy_r_r28 = PyErr_Occurred();
    cpy_r_r29 = cpy_r_r28 != NULL;
    if (!cpy_r_r29) goto CPyL15;
    cpy_r_r30 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", -1, CPyStatic_globals);
        goto CPyL34;
    }
CPyL15: ;
    cpy_r_r31 = cpy_r_r26 == 0;
    if (!cpy_r_r31) goto CPyL17;
    if (cpy_r_r31) {
        goto CPyL21;
    } else
        goto CPyL28;
CPyL17: ;
    cpy_r_r32 = CPyStatics[59]; /* 'external' */
    cpy_r_r33 = PyUnicode_Compare(cpy_r_key, cpy_r_r32);
    cpy_r_r34 = cpy_r_r33 == -1;
    if (!cpy_r_r34) goto CPyL20;
    cpy_r_r35 = PyErr_Occurred();
    cpy_r_r36 = cpy_r_r35 != NULL;
    if (!cpy_r_r36) goto CPyL20;
    cpy_r_r37 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", -1, CPyStatic_globals);
        goto CPyL34;
    }
CPyL20: ;
    cpy_r_r38 = cpy_r_r33 == 0;
    if (!cpy_r_r38) goto CPyL28;
CPyL21: ;
    cpy_r_r39 = (PyObject *)CPyType_RemoteTokenBalances;
    cpy_r_r40 = (CPyPtr)&((PyObject *)cpy_r_item)->ob_type;
    cpy_r_r41 = *(PyObject * *)cpy_r_r40;
    cpy_r_r42 = cpy_r_r41 == cpy_r_r39;
    if (cpy_r_r42) goto CPyL33;
    cpy_r_r43 = PyObject_Str(cpy_r_item);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 961, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r44 = CPyStatics[73]; /* ' is not a valid value for "' */
    cpy_r_r45 = CPyStatics[75]; /* '". Must be a RemoteTokenBalances object.' */
    cpy_r_r46 = CPyStr_Build(4, cpy_r_r43, cpy_r_r44, cpy_r_key, cpy_r_r45);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 961, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r47 = CPyModule_builtins;
    cpy_r_r48 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 960, CPyStatic_globals);
        goto CPyL37;
    }
    PyObject *cpy_r_r50[1] = {cpy_r_r46};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = _PyObject_Vectorcall(cpy_r_r49, cpy_r_r51, 1, 0);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 960, CPyStatic_globals);
        goto CPyL37;
    }
    CPy_DECREF(cpy_r_r46);
    CPy_Raise(cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 960, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r53 = CPyStatics[76]; /* 'key ' */
    cpy_r_r54 = CPyStatics[77]; /* ' is not yet implemented.' */
    cpy_r_r55 = CPyStr_Build(3, cpy_r_r53, cpy_r_key, cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 964, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r56 = CPyModule_builtins;
    cpy_r_r57 = CPyStatics[21]; /* 'NotImplementedError' */
    cpy_r_r58 = CPyObject_GetAttr(cpy_r_r56, cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 964, CPyStatic_globals);
        goto CPyL38;
    }
    PyObject *cpy_r_r59[1] = {cpy_r_r55};
    cpy_r_r60 = (PyObject **)&cpy_r_r59;
    cpy_r_r61 = _PyObject_Vectorcall(cpy_r_r58, cpy_r_r60, 1, 0);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 964, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_DECREF(cpy_r_r55);
    CPy_Raise(cpy_r_r61);
    CPy_DECREF(cpy_r_r61);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 964, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_Unreachable();
CPyL33: ;
    return 1;
CPyL34: ;
    cpy_r_r62 = 2;
    return cpy_r_r62;
CPyL35: ;
    CPy_DECREF(cpy_r_r3);
    goto CPyL1;
CPyL36: ;
    CPy_DecRef(cpy_r_r18);
    goto CPyL34;
CPyL37: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL34;
CPyL38: ;
    CPy_DecRef(cpy_r_r55);
    goto CPyL34;
}

PyObject *CPyPy_WalletBalances_____validateitem(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", "item", 0};
    static CPyArg_Parser parser = {"OO:__validateitem", kwlist, 0};
    PyObject *obj_key;
    PyObject *obj_item;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_key, &obj_item)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_key;
    if (likely(PyUnicode_Check(obj_key)))
        arg_key = obj_key;
    else {
        CPy_TypeError("str", obj_key); 
        goto fail;
    }
    PyObject *arg_item = obj_item;
    char retval = CPyDef_WalletBalances_____validateitem(arg_self, arg_key, arg_item);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__validateitem", 940, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    cpy_r_r0 = ((eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("eth_portfolio\\typing.py", "<lambda>", "__mypyc_lambda__1___init___PortfolioBalances_obj", "__mypyc_env__", 987, CPyStatic_globals);
        goto CPyL5;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((eth_portfolio___typing_____init___3_PortfolioBalances_envObject *)cpy_r_r0)->_block;
    if (unlikely(cpy_r_r1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'block' of '__init___PortfolioBalances_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r1);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 987, CPyStatic_globals);
        goto CPyL5;
    }
CPyL2: ;
    cpy_r_r2 = (PyObject *)CPyType_WalletBalances;
    PyObject *cpy_r_r3[1] = {cpy_r_r1};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = CPyStatics[144]; /* ('block',) */
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r4, 0, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 987, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r1);
    if (likely(PyDict_Check(cpy_r_r6)))
        cpy_r_r7 = cpy_r_r6;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "<lambda>", 987, CPyStatic_globals, "dict", cpy_r_r6);
        goto CPyL5;
    }
    return cpy_r_r7;
CPyL5: ;
    cpy_r_r8 = NULL;
    return cpy_r_r8;
CPyL6: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL5;
}

PyObject *CPyPy___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__call__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, PyVectorcall_NARGS(nargs), kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *retval = CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 987, CPyStatic_globals);
    return NULL;
}

char CPyDef_PortfolioBalances_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    CPyTagged cpy_r_r26;
    int64_t cpy_r_r27;
    CPyTagged cpy_r_r28;
    PyObject *cpy_r_r29;
    tuple_T4CIOO cpy_r_r30;
    CPyTagged cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_wallet;
    PyObject *cpy_r_balances;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    char cpy_r_r41;
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
    PyObject **cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    char cpy_r_r61;
    char cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    int32_t cpy_r_r65;
    char cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    CPyTagged cpy_r_r69;
    CPyPtr cpy_r_r70;
    int64_t cpy_r_r71;
    CPyTagged cpy_r_r72;
    char cpy_r_r73;
    int64_t cpy_r_r74;
    CPyPtr cpy_r_r75;
    CPyPtr cpy_r_r76;
    int64_t cpy_r_r77;
    CPyPtr cpy_r_r78;
    PyObject *cpy_r_r79;
    tuple_T2OO cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    char cpy_r_r88;
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
    PyObject **cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    char cpy_r_r108;
    CPyTagged cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject **cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    CPyPtr cpy_r_r119;
    CPyPtr cpy_r_r120;
    CPyPtr cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject **cpy_r_r127;
    PyObject *cpy_r_r128;
    char cpy_r_r129;
    if (cpy_r_seed != NULL) goto CPyL75;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_seed = cpy_r_r0;
CPyL2: ;
    if (cpy_r_block != NULL) goto CPyL76;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_block = cpy_r_r1;
CPyL4: ;
    cpy_r_r2 = CPyDef___init___3_PortfolioBalances_env();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 986, CPyStatic_globals);
        goto CPyL77;
    }
    if (((eth_portfolio___typing_____init___3_PortfolioBalances_envObject *)cpy_r_r2)->_block != NULL) {
        CPy_DECREF(((eth_portfolio___typing_____init___3_PortfolioBalances_envObject *)cpy_r_r2)->_block);
    }
    ((eth_portfolio___typing_____init___3_PortfolioBalances_envObject *)cpy_r_r2)->_block = cpy_r_block;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 986, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[22]; /* 'super' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 987, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r7 = (PyObject *)CPyType_PortfolioBalances;
    PyObject *cpy_r_r8[2] = {cpy_r_r7, cpy_r_self};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r9, 2, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 987, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r11 = CPyStatics[23]; /* '__init__' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 987, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r13 = CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj();
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 987, CPyStatic_globals);
        goto CPyL79;
    }
    CPy_INCREF(cpy_r_r2);
    if (((eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *)cpy_r_r13)->___mypyc_env__ != NULL) {
        CPy_DECREF(((eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *)cpy_r_r13)->___mypyc_env__);
    }
    ((eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject *)cpy_r_r13)->___mypyc_env__ = cpy_r_r2;
    cpy_r_r14 = 1;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 987, CPyStatic_globals);
        goto CPyL80;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_r13};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 987, CPyStatic_globals);
        goto CPyL81;
    } else
        goto CPyL82;
CPyL12: ;
    CPy_DECREF(cpy_r_r13);
    cpy_r_r18 = ((eth_portfolio___typing_____init___3_PortfolioBalances_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r18 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'block' of '__init___PortfolioBalances_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r18);
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 988, CPyStatic_globals);
        goto CPyL83;
    }
CPyL13: ;
    ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block = cpy_r_r18;
    cpy_r_r19 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r20 = cpy_r_seed == cpy_r_r19;
    if (cpy_r_r20) {
        goto CPyL84;
    } else
        goto CPyL15;
CPyL14: ;
    return 1;
CPyL15: ;
    cpy_r_r21 = (PyObject *)&PyDict_Type;
    cpy_r_r22 = PyObject_IsInstance(cpy_r_seed, cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 991, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r24 = cpy_r_r22;
    if (!cpy_r_r24) goto CPyL41;
    if (likely(PyDict_Check(cpy_r_seed)))
        cpy_r_r25 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 992, CPyStatic_globals, "dict", cpy_r_seed);
        goto CPyL74;
    }
    cpy_r_r26 = 0;
    cpy_r_r27 = PyDict_Size(cpy_r_r25);
    cpy_r_r28 = cpy_r_r27 << 1;
    cpy_r_r29 = CPyDict_GetItemsIter(cpy_r_r25);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 992, CPyStatic_globals);
        goto CPyL85;
    }
CPyL19: ;
    cpy_r_r30 = CPyDict_NextItem(cpy_r_r29, cpy_r_r26);
    cpy_r_r31 = cpy_r_r30.f1;
    cpy_r_r26 = cpy_r_r31;
    cpy_r_r32 = cpy_r_r30.f0;
    if (!cpy_r_r32) goto CPyL86;
    cpy_r_r33 = cpy_r_r30.f2;
    CPy_INCREF(cpy_r_r33);
    cpy_r_r34 = cpy_r_r30.f3;
    CPy_INCREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r30.f2);
    CPy_DECREF(cpy_r_r30.f3);
    if (likely(PyDict_Check(cpy_r_r34)))
        cpy_r_r35 = cpy_r_r34;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 992, CPyStatic_globals, "dict", cpy_r_r34);
        goto CPyL87;
    }
    cpy_r_wallet = cpy_r_r33;
    cpy_r_balances = cpy_r_r35;
    cpy_r_r36 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r36);
    cpy_r_r37 = CPyStatics[48]; /* 'block' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_balances, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 993, CPyStatic_globals);
        goto CPyL88;
    }
    if (PyLong_Check(cpy_r_r38))
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL92;
    if (cpy_r_r38 == Py_None)
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL92;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 993, CPyStatic_globals, "int or None", cpy_r_r38);
    goto CPyL88;
__LL92: ;
    cpy_r_r40 = PyObject_RichCompare(cpy_r_r36, cpy_r_r39, 3);
    CPy_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 993, CPyStatic_globals);
        goto CPyL89;
    }
    if (unlikely(!PyBool_Check(cpy_r_r40))) {
        CPy_TypeError("bool", cpy_r_r40); cpy_r_r41 = 2;
    } else
        cpy_r_r41 = cpy_r_r40 == Py_True;
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r41 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 993, CPyStatic_globals);
        goto CPyL89;
    }
    if (cpy_r_r41) {
        goto CPyL90;
    } else
        goto CPyL35;
CPyL26: ;
    cpy_r_r42 = CPyStatics[49]; /* 'These objects are not from the same block (' */
    cpy_r_r43 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r43);
    cpy_r_r44 = PyObject_Str(cpy_r_r43);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 995, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r45 = CPyStatics[9]; /* ' and ' */
    cpy_r_r46 = CPyStatics[48]; /* 'block' */
    cpy_r_r47 = CPyObject_GetAttr(cpy_r_balances, cpy_r_r46);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 995, CPyStatic_globals);
        goto CPyL92;
    }
    if (PyLong_Check(cpy_r_r47))
        cpy_r_r48 = cpy_r_r47;
    else {
        cpy_r_r48 = NULL;
    }
    if (cpy_r_r48 != NULL) goto __LL93;
    if (cpy_r_r47 == Py_None)
        cpy_r_r48 = cpy_r_r47;
    else {
        cpy_r_r48 = NULL;
    }
    if (cpy_r_r48 != NULL) goto __LL93;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 995, CPyStatic_globals, "int or None", cpy_r_r47);
    goto CPyL92;
__LL93: ;
    cpy_r_r49 = PyObject_Str(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 995, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r50 = CPyStatics[10]; /* ')' */
    cpy_r_r51 = CPyStr_Build(5, cpy_r_r42, cpy_r_r44, cpy_r_r45, cpy_r_r49, cpy_r_r50);
    CPy_DECREF(cpy_r_r44);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 995, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r52 = CPyModule_builtins;
    cpy_r_r53 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r54 = CPyObject_GetAttr(cpy_r_r52, cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 994, CPyStatic_globals);
        goto CPyL93;
    }
    PyObject *cpy_r_r55[1] = {cpy_r_r51};
    cpy_r_r56 = (PyObject **)&cpy_r_r55;
    cpy_r_r57 = _PyObject_Vectorcall(cpy_r_r54, cpy_r_r56, 1, 0);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 994, CPyStatic_globals);
        goto CPyL93;
    }
    CPy_DECREF(cpy_r_r51);
    CPy_Raise(cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 994, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL35: ;
    cpy_r_r58 = PyObject_GetItem(cpy_r_self, cpy_r_wallet);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 997, CPyStatic_globals);
        goto CPyL89;
    }
    cpy_r_r59 = PyNumber_InPlaceAdd(cpy_r_r58, cpy_r_balances);
    CPy_DECREF(cpy_r_r58);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 997, CPyStatic_globals);
        goto CPyL94;
    }
    if (likely(PyDict_Check(cpy_r_r59)))
        cpy_r_r60 = cpy_r_r59;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 997, CPyStatic_globals, "dict", cpy_r_r59);
        goto CPyL94;
    }
    cpy_r_r61 = CPyDef_PortfolioBalances_____setitem__(cpy_r_self, cpy_r_wallet, cpy_r_r60);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r61 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 997, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r62 = CPyDict_CheckSize(cpy_r_r25, cpy_r_r28);
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 992, CPyStatic_globals);
        goto CPyL95;
    } else
        goto CPyL19;
CPyL40: ;
    cpy_r_r63 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 992, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL73;
CPyL41: ;
    cpy_r_r64 = (PyObject *)&PyList_Type;
    cpy_r_r65 = PyObject_IsInstance(cpy_r_seed, cpy_r_r64);
    cpy_r_r66 = cpy_r_r65 >= 0;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 998, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r67 = cpy_r_r65;
    if (!cpy_r_r67) goto CPyL66;
    if (likely(PyList_Check(cpy_r_seed)))
        cpy_r_r68 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 999, CPyStatic_globals, "list", cpy_r_seed);
        goto CPyL74;
    }
    cpy_r_r69 = 0;
CPyL45: ;
    cpy_r_r70 = (CPyPtr)&((PyVarObject *)cpy_r_r68)->ob_size;
    cpy_r_r71 = *(int64_t *)cpy_r_r70;
    cpy_r_r72 = cpy_r_r71 << 1;
    cpy_r_r73 = (Py_ssize_t)cpy_r_r69 < (Py_ssize_t)cpy_r_r72;
    if (!cpy_r_r73) goto CPyL96;
    cpy_r_r74 = (Py_ssize_t)cpy_r_r69 >> 1;
    cpy_r_r75 = (CPyPtr)&((PyListObject *)cpy_r_r68)->ob_item;
    cpy_r_r76 = *(CPyPtr *)cpy_r_r75;
    cpy_r_r77 = cpy_r_r74 * 8;
    cpy_r_r78 = cpy_r_r76 + cpy_r_r77;
    cpy_r_r79 = *(PyObject * *)cpy_r_r78;
    CPy_INCREF(cpy_r_r79);
    PyObject *__tmp94;
    if (unlikely(!(PyTuple_Check(cpy_r_r79) && PyTuple_GET_SIZE(cpy_r_r79) == 2))) {
        __tmp94 = NULL;
        goto __LL95;
    }
    __tmp94 = PyTuple_GET_ITEM(cpy_r_r79, 0);
    if (__tmp94 == NULL) goto __LL95;
    if (likely(PyDict_Check(PyTuple_GET_ITEM(cpy_r_r79, 1))))
        __tmp94 = PyTuple_GET_ITEM(cpy_r_r79, 1);
    else {
        __tmp94 = NULL;
    }
    if (__tmp94 == NULL) goto __LL95;
    __tmp94 = cpy_r_r79;
__LL95: ;
    if (unlikely(__tmp94 == NULL)) {
        CPy_TypeError("tuple[object, dict]", cpy_r_r79); cpy_r_r80 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp96 = PyTuple_GET_ITEM(cpy_r_r79, 0);
        CPy_INCREF(__tmp96);
        PyObject *__tmp97;
        __tmp97 = __tmp96;
        cpy_r_r80.f0 = __tmp97;
        PyObject *__tmp98 = PyTuple_GET_ITEM(cpy_r_r79, 1);
        CPy_INCREF(__tmp98);
        PyObject *__tmp99;
        if (likely(PyDict_Check(__tmp98)))
            __tmp99 = __tmp98;
        else {
            CPy_TypeError("dict", __tmp98); 
            __tmp99 = NULL;
        }
        cpy_r_r80.f1 = __tmp99;
    }
    CPy_DECREF(cpy_r_r79);
    if (unlikely(cpy_r_r80.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 999, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r81 = cpy_r_r80.f0;
    CPy_INCREF(cpy_r_r81);
    cpy_r_wallet = cpy_r_r81;
    cpy_r_r82 = cpy_r_r80.f1;
    CPy_INCREF(cpy_r_r82);
    CPy_DECREF(cpy_r_r80.f0);
    CPy_DECREF(cpy_r_r80.f1);
    cpy_r_balances = cpy_r_r82;
    cpy_r_r83 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r83);
    cpy_r_r84 = CPyStatics[48]; /* 'block' */
    cpy_r_r85 = CPyObject_GetAttr(cpy_r_balances, cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1000, CPyStatic_globals);
        goto CPyL98;
    }
    if (PyLong_Check(cpy_r_r85))
        cpy_r_r86 = cpy_r_r85;
    else {
        cpy_r_r86 = NULL;
    }
    if (cpy_r_r86 != NULL) goto __LL100;
    if (cpy_r_r85 == Py_None)
        cpy_r_r86 = cpy_r_r85;
    else {
        cpy_r_r86 = NULL;
    }
    if (cpy_r_r86 != NULL) goto __LL100;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1000, CPyStatic_globals, "int or None", cpy_r_r85);
    goto CPyL98;
__LL100: ;
    cpy_r_r87 = PyObject_RichCompare(cpy_r_r83, cpy_r_r86, 3);
    CPy_DECREF(cpy_r_r83);
    CPy_DECREF(cpy_r_r86);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1000, CPyStatic_globals);
        goto CPyL99;
    }
    if (unlikely(!PyBool_Check(cpy_r_r87))) {
        CPy_TypeError("bool", cpy_r_r87); cpy_r_r88 = 2;
    } else
        cpy_r_r88 = cpy_r_r87 == Py_True;
    CPy_DECREF(cpy_r_r87);
    if (unlikely(cpy_r_r88 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1000, CPyStatic_globals);
        goto CPyL99;
    }
    if (cpy_r_r88) {
        goto CPyL100;
    } else
        goto CPyL61;
CPyL52: ;
    cpy_r_r89 = CPyStatics[49]; /* 'These objects are not from the same block (' */
    cpy_r_r90 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r90);
    cpy_r_r91 = PyObject_Str(cpy_r_r90);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1002, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r92 = CPyStatics[9]; /* ' and ' */
    cpy_r_r93 = CPyStatics[48]; /* 'block' */
    cpy_r_r94 = CPyObject_GetAttr(cpy_r_balances, cpy_r_r93);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1002, CPyStatic_globals);
        goto CPyL101;
    }
    if (PyLong_Check(cpy_r_r94))
        cpy_r_r95 = cpy_r_r94;
    else {
        cpy_r_r95 = NULL;
    }
    if (cpy_r_r95 != NULL) goto __LL101;
    if (cpy_r_r94 == Py_None)
        cpy_r_r95 = cpy_r_r94;
    else {
        cpy_r_r95 = NULL;
    }
    if (cpy_r_r95 != NULL) goto __LL101;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1002, CPyStatic_globals, "int or None", cpy_r_r94);
    goto CPyL101;
__LL101: ;
    cpy_r_r96 = PyObject_Str(cpy_r_r95);
    CPy_DECREF(cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1002, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r97 = CPyStatics[10]; /* ')' */
    cpy_r_r98 = CPyStr_Build(5, cpy_r_r89, cpy_r_r91, cpy_r_r92, cpy_r_r96, cpy_r_r97);
    CPy_DECREF(cpy_r_r91);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1002, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r99 = CPyModule_builtins;
    cpy_r_r100 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r101 = CPyObject_GetAttr(cpy_r_r99, cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1001, CPyStatic_globals);
        goto CPyL102;
    }
    PyObject *cpy_r_r102[1] = {cpy_r_r98};
    cpy_r_r103 = (PyObject **)&cpy_r_r102;
    cpy_r_r104 = _PyObject_Vectorcall(cpy_r_r101, cpy_r_r103, 1, 0);
    CPy_DECREF(cpy_r_r101);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1001, CPyStatic_globals);
        goto CPyL102;
    }
    CPy_DECREF(cpy_r_r98);
    CPy_Raise(cpy_r_r104);
    CPy_DECREF(cpy_r_r104);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1001, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL61: ;
    cpy_r_r105 = PyObject_GetItem(cpy_r_self, cpy_r_wallet);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1004, CPyStatic_globals);
        goto CPyL99;
    }
    cpy_r_r106 = PyNumber_InPlaceAdd(cpy_r_r105, cpy_r_balances);
    CPy_DECREF(cpy_r_r105);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1004, CPyStatic_globals);
        goto CPyL103;
    }
    if (likely(PyDict_Check(cpy_r_r106)))
        cpy_r_r107 = cpy_r_r106;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1004, CPyStatic_globals, "dict", cpy_r_r106);
        goto CPyL103;
    }
    cpy_r_r108 = CPyDef_PortfolioBalances_____setitem__(cpy_r_self, cpy_r_wallet, cpy_r_r107);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r107);
    if (unlikely(cpy_r_r108 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1004, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r109 = cpy_r_r69 + 2;
    cpy_r_r69 = cpy_r_r109;
    goto CPyL45;
CPyL66: ;
    cpy_r_r110 = CPyStatics[3]; /* '' */
    cpy_r_r111 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r112 = CPyStatics[3]; /* '' */
    cpy_r_r113 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r114[3] = {cpy_r_r111, cpy_r_seed, cpy_r_r112};
    cpy_r_r115 = (PyObject **)&cpy_r_r114;
    cpy_r_r116 = PyObject_VectorcallMethod(cpy_r_r113, cpy_r_r115, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1006, CPyStatic_globals);
        goto CPyL83;
    }
    CPy_DECREF(cpy_r_seed);
    cpy_r_r117 = CPyStatics[78]; /* ' is not a valid input for PortfolioBalances' */
    cpy_r_r118 = PyList_New(2);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1006, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r119 = (CPyPtr)&((PyListObject *)cpy_r_r118)->ob_item;
    cpy_r_r120 = *(CPyPtr *)cpy_r_r119;
    *(PyObject * *)cpy_r_r120 = cpy_r_r116;
    CPy_INCREF(cpy_r_r117);
    cpy_r_r121 = cpy_r_r120 + 8;
    *(PyObject * *)cpy_r_r121 = cpy_r_r117;
    cpy_r_r122 = PyUnicode_Join(cpy_r_r110, cpy_r_r118);
    CPy_DECREF(cpy_r_r118);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1006, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r123 = CPyModule_builtins;
    cpy_r_r124 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r125 = CPyObject_GetAttr(cpy_r_r123, cpy_r_r124);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1006, CPyStatic_globals);
        goto CPyL105;
    }
    PyObject *cpy_r_r126[1] = {cpy_r_r122};
    cpy_r_r127 = (PyObject **)&cpy_r_r126;
    cpy_r_r128 = _PyObject_Vectorcall(cpy_r_r125, cpy_r_r127, 1, 0);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1006, CPyStatic_globals);
        goto CPyL105;
    }
    CPy_DECREF(cpy_r_r122);
    CPy_Raise(cpy_r_r128);
    CPy_DECREF(cpy_r_r128);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1006, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL73: ;
    return 1;
CPyL74: ;
    cpy_r_r129 = 2;
    return cpy_r_r129;
CPyL75: ;
    CPy_INCREF(cpy_r_seed);
    goto CPyL2;
CPyL76: ;
    CPy_INCREF(cpy_r_block);
    goto CPyL4;
CPyL77: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_block);
    goto CPyL74;
CPyL78: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    goto CPyL74;
CPyL79: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    goto CPyL74;
CPyL80: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r13);
    goto CPyL74;
CPyL81: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r13);
    goto CPyL74;
CPyL82: ;
    CPy_DECREF(cpy_r_r17);
    goto CPyL12;
CPyL83: ;
    CPy_DecRef(cpy_r_seed);
    goto CPyL74;
CPyL84: ;
    CPy_DECREF(cpy_r_seed);
    goto CPyL14;
CPyL85: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL74;
CPyL86: ;
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r30.f2);
    CPy_DECREF(cpy_r_r30.f3);
    goto CPyL40;
CPyL87: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r33);
    goto CPyL74;
CPyL88: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balances);
    CPy_DecRef(cpy_r_r36);
    goto CPyL74;
CPyL89: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balances);
    goto CPyL74;
CPyL90: ;
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_wallet);
    goto CPyL26;
CPyL91: ;
    CPy_DecRef(cpy_r_balances);
    goto CPyL74;
CPyL92: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL74;
CPyL93: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL74;
CPyL94: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_wallet);
    goto CPyL74;
CPyL95: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    goto CPyL74;
CPyL96: ;
    CPy_DECREF(cpy_r_r68);
    goto CPyL73;
CPyL97: ;
    CPy_DecRef(cpy_r_r68);
    goto CPyL74;
CPyL98: ;
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balances);
    CPy_DecRef(cpy_r_r68);
    CPy_DecRef(cpy_r_r83);
    goto CPyL74;
CPyL99: ;
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balances);
    CPy_DecRef(cpy_r_r68);
    goto CPyL74;
CPyL100: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r68);
    goto CPyL52;
CPyL101: ;
    CPy_DecRef(cpy_r_r91);
    goto CPyL74;
CPyL102: ;
    CPy_DecRef(cpy_r_r98);
    goto CPyL74;
CPyL103: ;
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_r68);
    goto CPyL74;
CPyL104: ;
    CPy_DecRef(cpy_r_r116);
    goto CPyL74;
CPyL105: ;
    CPy_DecRef(cpy_r_r122);
    goto CPyL74;
}

PyObject *CPyPy_PortfolioBalances_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"seed", "block", 0};
    PyObject *obj_seed = NULL;
    PyObject *obj_block = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|O$O", "__init__", kwlist, &obj_seed, &obj_block)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_seed;
    if (obj_seed == NULL) {
        arg_seed = NULL;
        goto __LL102;
    }
    if (PyDict_Check(obj_seed))
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL102;
    if (PyList_Check(obj_seed))
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL102;
    if (obj_seed == Py_None)
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL102;
    CPy_TypeError("union[dict, list, None]", obj_seed); 
    goto fail;
__LL102: ;
    PyObject *arg_block;
    if (obj_block == NULL) {
        arg_block = NULL;
        goto __LL103;
    }
    if (PyLong_Check(obj_block))
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL103;
    if (obj_block == Py_None)
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL103;
    CPy_TypeError("int or None", obj_block); 
    goto fail;
__LL103: ;
    char retval = CPyDef_PortfolioBalances_____init__(arg_self, arg_seed, arg_block);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 986, CPyStatic_globals);
    return NULL;
}

char CPyDef_PortfolioBalances_____setitem__(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    char cpy_r_r35;
    cpy_r_r0 = (PyObject *)CPyType_WalletBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_value)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[79]; /* 'value must be a `WalletBalances` object. You passed ' */
    cpy_r_r6 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r7 = CPyStatics[3]; /* '' */
    cpy_r_r8 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r9[3] = {cpy_r_r6, cpy_r_value, cpy_r_r7};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = PyObject_VectorcallMethod(cpy_r_r8, cpy_r_r10, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1011, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1011, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    CPy_INCREF(cpy_r_r5);
    *(PyObject * *)cpy_r_r14 = cpy_r_r5;
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1011, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1010, CPyStatic_globals);
        goto CPyL15;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1010, CPyStatic_globals);
        goto CPyL15;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1010, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = CPyModule_builtins;
    cpy_r_r24 = CPyStatics[22]; /* 'super' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1013, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r26 = (PyObject *)CPyType_PortfolioBalances;
    PyObject *cpy_r_r27[2] = {cpy_r_r26, cpy_r_self};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = _PyObject_Vectorcall(cpy_r_r25, cpy_r_r28, 2, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1013, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r30 = CPyStatics[28]; /* '__setitem__' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1013, CPyStatic_globals);
        goto CPyL13;
    }
    PyObject *cpy_r_r32[2] = {cpy_r_key, cpy_r_value};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = _PyObject_Vectorcall(cpy_r_r31, cpy_r_r33, 2, 0);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1013, CPyStatic_globals);
        goto CPyL13;
    } else
        goto CPyL16;
CPyL12: ;
    return 1;
CPyL13: ;
    cpy_r_r35 = 2;
    return cpy_r_r35;
CPyL14: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL13;
CPyL15: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL13;
CPyL16: ;
    CPy_DECREF(cpy_r_r34);
    goto CPyL12;
}

PyObject *CPyPy_PortfolioBalances_____setitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"key", "value", 0};
    static CPyArg_Parser parser = {"OO:__setitem__", kwlist, 0};
    PyObject *obj_key;
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_key, &obj_value)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_key = obj_key;
    PyObject *arg_value;
    if (likely(PyDict_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("dict", obj_value); 
        goto fail;
    }
    char retval = CPyDef_PortfolioBalances_____setitem__(arg_self, arg_key, arg_value);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__setitem__", 1008, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalances___dataframe(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    int32_t cpy_r_r17;
    char cpy_r_r18;
    int32_t cpy_r_r19;
    char cpy_r_r20;
    char cpy_r_r21;
    CPyPtr cpy_r_r22;
    int64_t cpy_r_r23;
    CPyTagged cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1023, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r1 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r2[1] = {cpy_r_self};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r3, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1024, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r5 = PyObject_GetIter(cpy_r_r4);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1024, CPyStatic_globals);
        goto CPyL28;
    }
CPyL3: ;
    cpy_r_r6 = PyIter_Next(cpy_r_r5);
    if (cpy_r_r6 == NULL) goto CPyL29;
    cpy_r_r7 = PyObject_GetIter(cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1024, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r8 = PyIter_Next(cpy_r_r7);
    if (cpy_r_r8 == NULL) {
        goto CPyL31;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r9 = 0;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1024, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r10 = PyIter_Next(cpy_r_r7);
    if (cpy_r_r10 == NULL) {
        goto CPyL32;
    } else
        goto CPyL11;
CPyL9: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r11 = 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1024, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r12 = PyIter_Next(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (cpy_r_r12 == NULL) {
        goto CPyL14;
    } else
        goto CPyL33;
CPyL12: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r13 = 0;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1024, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_Unreachable();
CPyL14: ;
    cpy_r_r14 = CPyStatics[64]; /* 'dataframe' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r14);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1025, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r16 = CPyStatics[80]; /* 'wallet' */
    cpy_r_r17 = PyObject_SetItem(cpy_r_r15, cpy_r_r16, cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r18 = cpy_r_r17 >= 0;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1026, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r19 = PyList_Append(cpy_r_r0, cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    cpy_r_r20 = cpy_r_r19 >= 0;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1027, CPyStatic_globals);
        goto CPyL30;
    } else
        goto CPyL3;
CPyL17: ;
    cpy_r_r21 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1024, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r22 = (CPyPtr)&((PyVarObject *)cpy_r_r0)->ob_size;
    cpy_r_r23 = *(int64_t *)cpy_r_r22;
    cpy_r_r24 = cpy_r_r23 << 1;
    cpy_r_r25 = cpy_r_r24 != 0;
    if (!cpy_r_r25) goto CPyL36;
    cpy_r_r26 = CPyStatic_globals;
    cpy_r_r27 = CPyStatics[52]; /* 'concat' */
    cpy_r_r28 = CPyDict_GetItem(cpy_r_r26, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1028, CPyStatic_globals);
        goto CPyL28;
    }
    PyObject *cpy_r_r29[1] = {cpy_r_r0};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = _PyObject_Vectorcall(cpy_r_r28, cpy_r_r30, 1, 0);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1028, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_DECREF(cpy_r_r0);
    cpy_r_r32 = CPyStatics[34]; /* 'reset_index' */
    cpy_r_r33 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r34[2] = {cpy_r_r31, cpy_r_r33};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = CPyStatics[143]; /* ('drop',) */
    cpy_r_r37 = PyObject_VectorcallMethod(cpy_r_r32, cpy_r_r35, 9223372036854775809ULL, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1028, CPyStatic_globals);
        goto CPyL37;
    }
    CPy_DECREF(cpy_r_r31);
    cpy_r_r38 = cpy_r_r37;
    goto CPyL26;
CPyL23: ;
    cpy_r_r39 = CPyStatic_globals;
    cpy_r_r40 = CPyStatics[32]; /* 'DataFrame' */
    cpy_r_r41 = CPyDict_GetItem(cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1028, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r42 = _PyObject_Vectorcall(cpy_r_r41, 0, 0, 0);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1028, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r38 = cpy_r_r42;
CPyL26: ;
    return cpy_r_r38;
CPyL27: ;
    cpy_r_r43 = NULL;
    return cpy_r_r43;
CPyL28: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL27;
CPyL29: ;
    CPy_DECREF(cpy_r_r5);
    goto CPyL17;
CPyL30: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    goto CPyL27;
CPyL31: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r7);
    goto CPyL6;
CPyL32: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r8);
    goto CPyL9;
CPyL33: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r12);
    goto CPyL12;
CPyL34: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r8);
    goto CPyL27;
CPyL35: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r15);
    goto CPyL27;
CPyL36: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL23;
CPyL37: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL27;
}

PyObject *CPyPy_PortfolioBalances___dataframe(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":dataframe", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalances___dataframe(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "dataframe", 1016, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalances___sum_usd(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    cpy_r_r0 = CPyStatics[140]; /* 0 */
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = cpy_r_r0;
    cpy_r_r2 = CPyStatics[40]; /* 'values' */
    PyObject *cpy_r_r3[1] = {cpy_r_self};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_VectorcallMethod(cpy_r_r2, cpy_r_r4, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 1043, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r6 = PyObject_GetIter(cpy_r_r5);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 1043, CPyStatic_globals);
        goto CPyL9;
    }
CPyL2: ;
    cpy_r_r7 = PyIter_Next(cpy_r_r6);
    if (cpy_r_r7 == NULL) goto CPyL10;
    cpy_r_r8 = CPyStatics[66]; /* 'sum_usd' */
    PyObject *cpy_r_r9[1] = {cpy_r_r7};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = PyObject_VectorcallMethod(cpy_r_r8, cpy_r_r10, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 1043, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r7);
    cpy_r_r12 = PyNumber_Add(cpy_r_r1, cpy_r_r11);
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", -1, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r1 = cpy_r_r12;
    goto CPyL2;
CPyL6: ;
    cpy_r_r13 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 1043, CPyStatic_globals);
        goto CPyL9;
    }
    return cpy_r_r1;
CPyL8: ;
    cpy_r_r14 = NULL;
    return cpy_r_r14;
CPyL9: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL8;
CPyL10: ;
    CPy_DECREF(cpy_r_r6);
    goto CPyL6;
CPyL11: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    goto CPyL8;
CPyL12: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL8;
}

PyObject *CPyPy_PortfolioBalances___sum_usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":sum_usd", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalances___sum_usd(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "sum_usd", 1030, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalances___inverted(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    int32_t cpy_r_r29;
    char cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    int32_t cpy_r_r36;
    char cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    cpy_r_r0 = (PyObject *)CPyType_PortfolioBalancesByCategory;
    cpy_r_r1 = _PyObject_Vectorcall(cpy_r_r0, 0, 0, 0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1059, CPyStatic_globals);
        goto CPyL38;
    }
    if (likely(PyDict_Check(cpy_r_r1)))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "inverted", 1059, CPyStatic_globals, "dict", cpy_r_r1);
        goto CPyL38;
    }
    cpy_r_r3 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r4[1] = {cpy_r_self};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r3, cpy_r_r5, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1060, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r7 = PyObject_GetIter(cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1060, CPyStatic_globals);
        goto CPyL39;
    }
CPyL4: ;
    cpy_r_r8 = PyIter_Next(cpy_r_r7);
    if (cpy_r_r8 == NULL) goto CPyL40;
    cpy_r_r9 = PyObject_GetIter(cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1060, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r10 = PyIter_Next(cpy_r_r9);
    if (cpy_r_r10 == NULL) {
        goto CPyL42;
    } else
        goto CPyL9;
CPyL7: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r11 = 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1060, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_Unreachable();
CPyL9: ;
    cpy_r_r12 = PyIter_Next(cpy_r_r9);
    if (cpy_r_r12 == NULL) {
        goto CPyL43;
    } else
        goto CPyL12;
CPyL10: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r13 = 0;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1060, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r14 = PyIter_Next(cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    if (cpy_r_r14 == NULL) {
        goto CPyL15;
    } else
        goto CPyL44;
CPyL13: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r15 = 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1060, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_Unreachable();
CPyL15: ;
    cpy_r_r16 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r17[1] = {cpy_r_r12};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_VectorcallMethod(cpy_r_r16, cpy_r_r18, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1061, CPyStatic_globals);
        goto CPyL45;
    }
    CPy_DECREF(cpy_r_r12);
    cpy_r_r20 = PyObject_GetIter(cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1061, CPyStatic_globals);
        goto CPyL46;
    }
CPyL17: ;
    cpy_r_r21 = PyIter_Next(cpy_r_r20);
    if (cpy_r_r21 == NULL) goto CPyL47;
    cpy_r_r22 = PyObject_GetIter(cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1061, CPyStatic_globals);
        goto CPyL48;
    }
    cpy_r_r23 = PyIter_Next(cpy_r_r22);
    if (cpy_r_r23 == NULL) {
        goto CPyL49;
    } else
        goto CPyL22;
CPyL20: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r24 = 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1061, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_Unreachable();
CPyL22: ;
    cpy_r_r25 = PyIter_Next(cpy_r_r22);
    if (cpy_r_r25 == NULL) {
        goto CPyL50;
    } else
        goto CPyL25;
CPyL23: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r26 = 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1061, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_Unreachable();
CPyL25: ;
    cpy_r_r27 = PyIter_Next(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (cpy_r_r27 == NULL) {
        goto CPyL28;
    } else
        goto CPyL51;
CPyL26: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r28 = 0;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1061, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r29 = PyObject_IsTrue(cpy_r_r25);
    cpy_r_r30 = cpy_r_r29 >= 0;
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1061, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r31 = cpy_r_r29;
    if (!cpy_r_r31) goto CPyL53;
    cpy_r_r32 = CPyDict_GetItem(cpy_r_r2, cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1063, CPyStatic_globals);
        goto CPyL54;
    }
    if (likely(Py_TYPE(cpy_r_r32) == CPyType_WalletBalancesRaw))
        cpy_r_r33 = cpy_r_r32;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "inverted", 1063, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_r32);
        goto CPyL54;
    }
    cpy_r_r34 = PyObject_GetItem(cpy_r_r33, cpy_r_r10);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1063, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r35 = PyNumber_InPlaceAdd(cpy_r_r34, cpy_r_r25);
    CPy_DECREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1063, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r36 = PyObject_SetItem(cpy_r_r33, cpy_r_r10, cpy_r_r35);
    CPy_DECREF(cpy_r_r33);
    CPy_DECREF(cpy_r_r35);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1063, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL17;
CPyL35: ;
    cpy_r_r38 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1061, CPyStatic_globals);
        goto CPyL41;
    } else
        goto CPyL4;
CPyL36: ;
    cpy_r_r39 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1060, CPyStatic_globals);
        goto CPyL39;
    }
    return cpy_r_r2;
CPyL38: ;
    cpy_r_r40 = NULL;
    return cpy_r_r40;
CPyL39: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL38;
CPyL40: ;
    CPy_DECREF(cpy_r_r7);
    goto CPyL36;
CPyL41: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    goto CPyL38;
CPyL42: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r9);
    goto CPyL7;
CPyL43: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r10);
    goto CPyL10;
CPyL44: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r14);
    goto CPyL13;
CPyL45: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r12);
    goto CPyL38;
CPyL46: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL38;
CPyL47: ;
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r20);
    goto CPyL35;
CPyL48: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r20);
    goto CPyL38;
CPyL49: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r22);
    goto CPyL20;
CPyL50: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r23);
    goto CPyL23;
CPyL51: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r27);
    goto CPyL26;
CPyL52: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r25);
    goto CPyL38;
CPyL53: ;
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r25);
    goto CPyL17;
CPyL54: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r25);
    goto CPyL38;
CPyL55: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r33);
    goto CPyL38;
CPyL56: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r33);
    goto CPyL38;
}

PyObject *CPyPy_PortfolioBalances___inverted(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":inverted", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalances___inverted(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "inverted", 1046, CPyStatic_globals);
    return NULL;
}

char CPyDef_PortfolioBalances_____bool__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    cpy_r_r0 = CPyStatics[40]; /* 'values' */
    PyObject *cpy_r_r1[1] = {cpy_r_self};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1078, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[42]; /* 'any' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1078, CPyStatic_globals);
        goto CPyL6;
    }
    PyObject *cpy_r_r7[1] = {cpy_r_r3};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 1, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1078, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r3);
    if (unlikely(!PyBool_Check(cpy_r_r9))) {
        CPy_TypeError("bool", cpy_r_r9); cpy_r_r10 = 2;
    } else
        cpy_r_r10 = cpy_r_r9 == Py_True;
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1078, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r10;
CPyL5: ;
    cpy_r_r11 = 2;
    return cpy_r_r11;
CPyL6: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL5;
}

PyObject *CPyPy_PortfolioBalances_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__bool__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    char retval = CPyDef_PortfolioBalances_____bool__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1066, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalances_____repr__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[81]; /* 'WalletBalances' */
    cpy_r_r1 = CPyDict_FromAny(cpy_r_self);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1087, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r2 = PyObject_Str(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1087, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r3 = CPyStr_Build(2, cpy_r_r0, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1087, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy_PortfolioBalances_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__repr__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalances_____repr__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1080, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalances_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
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
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_wallet;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_balance;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    int32_t cpy_r_r57;
    char cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject **cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject **cpy_r_r67;
    PyObject *cpy_r_r68;
    char cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    char cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    int32_t cpy_r_r83;
    char cpy_r_r84;
    char cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject **cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject **cpy_r_r93;
    PyObject *cpy_r_r94;
    char cpy_r_r95;
    PyObject *cpy_r_r96;
    cpy_r_r0 = (PyObject *)CPyType_PortfolioBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1110, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r11 = CPyStatics[82]; /* ' is not a PortfolioBalances object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1110, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1110, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1110, CPyStatic_globals);
        goto CPyL62;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1110, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1110, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PyObject_RichCompare(cpy_r_r23, cpy_r_r24, 3);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1111, CPyStatic_globals);
        goto CPyL60;
    }
    if (unlikely(!PyBool_Check(cpy_r_r25))) {
        CPy_TypeError("bool", cpy_r_r25); cpy_r_r26 = 2;
    } else
        cpy_r_r26 = cpy_r_r25 == Py_True;
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1111, CPyStatic_globals);
        goto CPyL60;
    }
    if (!cpy_r_r26) goto CPyL18;
    cpy_r_r27 = CPyStatics[83]; /* ('These PortfolioBalances objects are not from the same '
                                   'block (') */
    cpy_r_r28 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r28);
    cpy_r_r29 = PyObject_Str(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1113, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r30 = CPyStatics[9]; /* ' and ' */
    cpy_r_r31 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r31);
    cpy_r_r32 = PyObject_Str(cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1113, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r33 = CPyStatics[10]; /* ')' */
    cpy_r_r34 = CPyStr_Build(5, cpy_r_r27, cpy_r_r29, cpy_r_r30, cpy_r_r32, cpy_r_r33);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1113, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1112, CPyStatic_globals);
        goto CPyL64;
    }
    PyObject *cpy_r_r38[1] = {cpy_r_r34};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r39, 1, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1112, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_DECREF(cpy_r_r34);
    CPy_Raise(cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1112, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r41 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42 = NULL;
    cpy_r_r43 = CPyDef_PortfolioBalances(cpy_r_r42, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1116, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r44 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r45[1] = {cpy_r_self};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = PyObject_VectorcallMethod(cpy_r_r44, cpy_r_r46, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1117, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r48 = PyObject_GetIter(cpy_r_r47);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1117, CPyStatic_globals);
        goto CPyL65;
    }
CPyL21: ;
    cpy_r_r49 = PyIter_Next(cpy_r_r48);
    if (cpy_r_r49 == NULL) goto CPyL66;
    cpy_r_r50 = PyObject_GetIter(cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1117, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r51 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r51 == NULL) {
        goto CPyL68;
    } else
        goto CPyL26;
CPyL24: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r52 = 0;
    if (unlikely(!cpy_r_r52)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1117, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_wallet = cpy_r_r51;
    cpy_r_r53 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r53 == NULL) {
        goto CPyL69;
    } else
        goto CPyL29;
CPyL27: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r54 = 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1117, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL29: ;
    cpy_r_balance = cpy_r_r53;
    cpy_r_r55 = PyIter_Next(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (cpy_r_r55 == NULL) {
        goto CPyL32;
    } else
        goto CPyL70;
CPyL30: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r56 = 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1117, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL32: ;
    cpy_r_r57 = PyObject_IsTrue(cpy_r_balance);
    cpy_r_r58 = cpy_r_r57 >= 0;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1117, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r59 = cpy_r_r57;
    if (!cpy_r_r59) goto CPyL72;
    cpy_r_r60 = CPyStatics[47]; /* '_getitem_nochecksum' */
    PyObject *cpy_r_r61[2] = {cpy_r_r43, cpy_r_wallet};
    cpy_r_r62 = (PyObject **)&cpy_r_r61;
    cpy_r_r63 = PyObject_VectorcallMethod(cpy_r_r60, cpy_r_r62, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1119, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r64 = PyNumber_Add(cpy_r_r63, cpy_r_balance);
    CPy_DECREF(cpy_r_r63);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1119, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r65 = CPyStatics[46]; /* '_setitem_nochecksum' */
    PyObject *cpy_r_r66[3] = {cpy_r_r43, cpy_r_wallet, cpy_r_r64};
    cpy_r_r67 = (PyObject **)&cpy_r_r66;
    cpy_r_r68 = PyObject_VectorcallMethod(cpy_r_r65, cpy_r_r67, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1119, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL75;
CPyL37: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r64);
    goto CPyL21;
CPyL38: ;
    cpy_r_r69 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r69)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1117, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r70 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r71[1] = {cpy_r_other};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = PyObject_VectorcallMethod(cpy_r_r70, cpy_r_r72, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1120, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r74 = PyObject_GetIter(cpy_r_r73);
    CPy_DECREF(cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1120, CPyStatic_globals);
        goto CPyL65;
    }
CPyL41: ;
    cpy_r_r75 = PyIter_Next(cpy_r_r74);
    if (cpy_r_r75 == NULL) goto CPyL76;
    cpy_r_r76 = PyObject_GetIter(cpy_r_r75);
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1120, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r77 = PyIter_Next(cpy_r_r76);
    if (cpy_r_r77 == NULL) {
        goto CPyL78;
    } else
        goto CPyL46;
CPyL44: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r78 = 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1120, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL46: ;
    cpy_r_wallet = cpy_r_r77;
    cpy_r_r79 = PyIter_Next(cpy_r_r76);
    if (cpy_r_r79 == NULL) {
        goto CPyL79;
    } else
        goto CPyL49;
CPyL47: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r80 = 0;
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1120, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL49: ;
    cpy_r_balance = cpy_r_r79;
    cpy_r_r81 = PyIter_Next(cpy_r_r76);
    CPy_DECREF(cpy_r_r76);
    if (cpy_r_r81 == NULL) {
        goto CPyL52;
    } else
        goto CPyL80;
CPyL50: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r82 = 0;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1120, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL52: ;
    cpy_r_r83 = PyObject_IsTrue(cpy_r_balance);
    cpy_r_r84 = cpy_r_r83 >= 0;
    if (unlikely(!cpy_r_r84)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1117, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r85 = cpy_r_r83;
    if (!cpy_r_r85) goto CPyL82;
    cpy_r_r86 = CPyStatics[47]; /* '_getitem_nochecksum' */
    PyObject *cpy_r_r87[2] = {cpy_r_r43, cpy_r_wallet};
    cpy_r_r88 = (PyObject **)&cpy_r_r87;
    cpy_r_r89 = PyObject_VectorcallMethod(cpy_r_r86, cpy_r_r88, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1122, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r90 = PyNumber_Add(cpy_r_r89, cpy_r_balance);
    CPy_DECREF(cpy_r_r89);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1122, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r91 = CPyStatics[46]; /* '_setitem_nochecksum' */
    PyObject *cpy_r_r92[3] = {cpy_r_r43, cpy_r_wallet, cpy_r_r90};
    cpy_r_r93 = (PyObject **)&cpy_r_r92;
    cpy_r_r94 = PyObject_VectorcallMethod(cpy_r_r91, cpy_r_r93, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1122, CPyStatic_globals);
        goto CPyL84;
    } else
        goto CPyL85;
CPyL57: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r90);
    goto CPyL41;
CPyL58: ;
    cpy_r_r95 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r95)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1120, CPyStatic_globals);
        goto CPyL65;
    }
    return cpy_r_r43;
CPyL60: ;
    cpy_r_r96 = NULL;
    return cpy_r_r96;
CPyL61: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL60;
CPyL62: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL60;
CPyL63: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL60;
CPyL64: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL60;
CPyL65: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL60;
CPyL66: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL38;
CPyL67: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    goto CPyL60;
CPyL68: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    goto CPyL24;
CPyL69: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    CPy_DECREF(cpy_r_wallet);
    goto CPyL27;
CPyL70: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balance);
    CPy_DECREF(cpy_r_r55);
    goto CPyL30;
CPyL71: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balance);
    goto CPyL60;
CPyL72: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balance);
    goto CPyL21;
CPyL73: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_wallet);
    goto CPyL60;
CPyL74: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_r64);
    goto CPyL60;
CPyL75: ;
    CPy_DECREF(cpy_r_r68);
    goto CPyL37;
CPyL76: ;
    CPy_DECREF(cpy_r_r74);
    goto CPyL58;
CPyL77: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r74);
    goto CPyL60;
CPyL78: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r76);
    goto CPyL44;
CPyL79: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r76);
    goto CPyL47;
CPyL80: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balance);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r81);
    goto CPyL50;
CPyL81: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balance);
    CPy_DecRef(cpy_r_r74);
    goto CPyL60;
CPyL82: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balance);
    goto CPyL41;
CPyL83: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_r74);
    goto CPyL60;
CPyL84: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r90);
    goto CPyL60;
CPyL85: ;
    CPy_DECREF(cpy_r_r94);
    goto CPyL57;
}

PyObject *CPyPy_PortfolioBalances_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(Py_TYPE(obj_other) == CPyType_PortfolioBalances))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalances_____add__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1089, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalances_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPy_INCREF(cpy_r_other);
    if (likely(Py_TYPE(cpy_r_other) == CPyType_PortfolioBalances))
        cpy_r_r0 = cpy_r_other;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", cpy_r_other); 
        cpy_r_r0 = NULL;
    }
    if (cpy_r_r0 == NULL) goto CPyL3;
    cpy_r_r1 = CPyDef_PortfolioBalances_____add__(cpy_r_self, cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL3;
    return cpy_r_r1;
CPyL3: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_PortfolioBalances_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add_____SummableNonNumericMixin_glue", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyObject_TypeCheck(obj_other, CPyType__SummableNonNumericMixin)))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalances_____add___3___SummableNonNumericMixin_glue(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add_____SummableNonNumericMixin_glue", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalances_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
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
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_protocol;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_balances;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    char cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject **cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    char cpy_r_r70;
    PyObject *cpy_r_r71;
    char cpy_r_r72;
    PyObject *cpy_r_r73;
    char cpy_r_r74;
    int32_t cpy_r_r75;
    char cpy_r_r76;
    char cpy_r_r77;
    int32_t cpy_r_r78;
    char cpy_r_r79;
    char cpy_r_r80;
    PyObject *cpy_r_r81;
    cpy_r_r0 = (PyObject *)CPyType_PortfolioBalances;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1146, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r11 = CPyStatics[82]; /* ' is not a PortfolioBalances object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1146, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1146, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1146, CPyStatic_globals);
        goto CPyL58;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1146, CPyStatic_globals);
        goto CPyL58;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1146, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PyObject_RichCompare(cpy_r_r23, cpy_r_r24, 3);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1147, CPyStatic_globals);
        goto CPyL56;
    }
    if (unlikely(!PyBool_Check(cpy_r_r25))) {
        CPy_TypeError("bool", cpy_r_r25); cpy_r_r26 = 2;
    } else
        cpy_r_r26 = cpy_r_r25 == Py_True;
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1147, CPyStatic_globals);
        goto CPyL56;
    }
    if (!cpy_r_r26) goto CPyL18;
    cpy_r_r27 = CPyStatics[83]; /* ('These PortfolioBalances objects are not from the same '
                                   'block (') */
    cpy_r_r28 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r28);
    cpy_r_r29 = PyObject_Str(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1149, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r30 = CPyStatics[9]; /* ' and ' */
    cpy_r_r31 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r31);
    cpy_r_r32 = PyObject_Str(cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1149, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r33 = CPyStatics[10]; /* ')' */
    cpy_r_r34 = CPyStr_Build(5, cpy_r_r27, cpy_r_r29, cpy_r_r30, cpy_r_r32, cpy_r_r33);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1149, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1148, CPyStatic_globals);
        goto CPyL60;
    }
    PyObject *cpy_r_r38[1] = {cpy_r_r34};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r39, 1, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1148, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_DECREF(cpy_r_r34);
    CPy_Raise(cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1148, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r41 = ((eth_portfolio___typing___PortfolioBalancesObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r41);
    CPy_INCREF(cpy_r_self);
    if (PyDict_Check(cpy_r_self))
        cpy_r_r42 = cpy_r_self;
    else {
        cpy_r_r42 = NULL;
    }
    if (cpy_r_r42 != NULL) goto __LL104;
    if (PyList_Check(cpy_r_self))
        cpy_r_r42 = cpy_r_self;
    else {
        cpy_r_r42 = NULL;
    }
    if (cpy_r_r42 != NULL) goto __LL104;
    if (cpy_r_self == Py_None)
        cpy_r_r42 = cpy_r_self;
    else {
        cpy_r_r42 = NULL;
    }
    if (cpy_r_r42 != NULL) goto __LL104;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1152, CPyStatic_globals, "union[dict, list, None]", cpy_r_self);
    goto CPyL61;
__LL104: ;
    cpy_r_r43 = CPyDef_PortfolioBalances(cpy_r_r42, cpy_r_r41);
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1152, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r44 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r45[1] = {cpy_r_other};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = PyObject_VectorcallMethod(cpy_r_r44, cpy_r_r46, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1153, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r48 = PyObject_GetIter(cpy_r_r47);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1153, CPyStatic_globals);
        goto CPyL62;
    }
CPyL22: ;
    cpy_r_r49 = PyIter_Next(cpy_r_r48);
    if (cpy_r_r49 == NULL) goto CPyL63;
    cpy_r_r50 = PyObject_GetIter(cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1153, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r51 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r51 == NULL) {
        goto CPyL65;
    } else
        goto CPyL27;
CPyL25: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r52 = 0;
    if (unlikely(!cpy_r_r52)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1153, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL27: ;
    cpy_r_protocol = cpy_r_r51;
    cpy_r_r53 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r53 == NULL) {
        goto CPyL66;
    } else
        goto CPyL30;
CPyL28: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r54 = 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1153, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL30: ;
    cpy_r_balances = cpy_r_r53;
    cpy_r_r55 = PyIter_Next(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (cpy_r_r55 == NULL) {
        goto CPyL33;
    } else
        goto CPyL67;
CPyL31: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r56 = 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1153, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL33: ;
    cpy_r_r57 = PyObject_GetItem(cpy_r_r43, cpy_r_protocol);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1154, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r58 = PyNumber_InPlaceSubtract(cpy_r_r57, cpy_r_balances);
    CPy_DECREF(cpy_r_r57);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1154, CPyStatic_globals);
        goto CPyL69;
    }
    if (likely(PyDict_Check(cpy_r_r58)))
        cpy_r_r59 = cpy_r_r58;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1154, CPyStatic_globals, "dict", cpy_r_r58);
        goto CPyL69;
    }
    cpy_r_r60 = CPyDef_PortfolioBalances_____setitem__(cpy_r_r43, cpy_r_protocol, cpy_r_r59);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r60 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1154, CPyStatic_globals);
        goto CPyL64;
    } else
        goto CPyL22;
CPyL37: ;
    cpy_r_r61 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1153, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r62 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r63[1] = {cpy_r_r43};
    cpy_r_r64 = (PyObject **)&cpy_r_r63;
    cpy_r_r65 = PyObject_VectorcallMethod(cpy_r_r62, cpy_r_r64, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1155, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r66 = PyObject_GetIter(cpy_r_r65);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1155, CPyStatic_globals);
        goto CPyL62;
    }
CPyL40: ;
    cpy_r_r67 = PyIter_Next(cpy_r_r66);
    if (cpy_r_r67 == NULL) goto CPyL70;
    cpy_r_r68 = PyObject_GetIter(cpy_r_r67);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1155, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r69 = PyIter_Next(cpy_r_r68);
    if (cpy_r_r69 == NULL) {
        goto CPyL72;
    } else
        goto CPyL45;
CPyL43: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r70 = 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1155, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL45: ;
    cpy_r_protocol = cpy_r_r69;
    cpy_r_r71 = PyIter_Next(cpy_r_r68);
    if (cpy_r_r71 == NULL) {
        goto CPyL73;
    } else
        goto CPyL48;
CPyL46: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r72 = 0;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1155, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL48: ;
    cpy_r_balances = cpy_r_r71;
    cpy_r_r73 = PyIter_Next(cpy_r_r68);
    CPy_DECREF(cpy_r_r68);
    if (cpy_r_r73 == NULL) {
        goto CPyL51;
    } else
        goto CPyL74;
CPyL49: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r74 = 0;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1155, CPyStatic_globals);
        goto CPyL56;
    }
    CPy_Unreachable();
CPyL51: ;
    cpy_r_r75 = PyObject_IsTrue(cpy_r_balances);
    CPy_DECREF(cpy_r_balances);
    cpy_r_r76 = cpy_r_r75 >= 0;
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1153, CPyStatic_globals);
        goto CPyL75;
    }
    cpy_r_r77 = cpy_r_r75;
    if (cpy_r_r77) goto CPyL76;
    cpy_r_r78 = PyObject_DelItem(cpy_r_r43, cpy_r_protocol);
    CPy_DECREF(cpy_r_protocol);
    cpy_r_r79 = cpy_r_r78 >= 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1157, CPyStatic_globals);
        goto CPyL71;
    } else
        goto CPyL40;
CPyL54: ;
    cpy_r_r80 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1155, CPyStatic_globals);
        goto CPyL62;
    }
    return cpy_r_r43;
CPyL56: ;
    cpy_r_r81 = NULL;
    return cpy_r_r81;
CPyL57: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL56;
CPyL58: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL56;
CPyL59: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL56;
CPyL60: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL56;
CPyL61: ;
    CPy_DecRef(cpy_r_r41);
    goto CPyL56;
CPyL62: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL56;
CPyL63: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL37;
CPyL64: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    goto CPyL56;
CPyL65: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    goto CPyL25;
CPyL66: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    CPy_DECREF(cpy_r_protocol);
    goto CPyL28;
CPyL67: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_balances);
    CPy_DECREF(cpy_r_r55);
    goto CPyL31;
CPyL68: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_balances);
    goto CPyL56;
CPyL69: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_protocol);
    goto CPyL56;
CPyL70: ;
    CPy_DECREF(cpy_r_r66);
    goto CPyL54;
CPyL71: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r66);
    goto CPyL56;
CPyL72: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r68);
    goto CPyL43;
CPyL73: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r68);
    goto CPyL46;
CPyL74: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_balances);
    CPy_DECREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r73);
    goto CPyL49;
CPyL75: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_r66);
    goto CPyL56;
CPyL76: ;
    CPy_DECREF(cpy_r_protocol);
    goto CPyL40;
}

PyObject *CPyPy_PortfolioBalances_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__sub__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalances))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(Py_TYPE(obj_other) == CPyType_PortfolioBalances))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalances", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalances_____sub__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1125, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = ((eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("eth_portfolio\\typing.py", "<lambda>", "__mypyc_lambda__2___init___WalletBalancesRaw_obj", "__mypyc_env__", 1187, CPyStatic_globals);
        goto CPyL4;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *)cpy_r_r0)->_block;
    if (unlikely(cpy_r_r1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'block' of '__init___WalletBalancesRaw_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r1);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 1187, CPyStatic_globals);
        goto CPyL4;
    }
CPyL2: ;
    cpy_r_r2 = NULL;
    cpy_r_r3 = CPyDef_TokenBalances(cpy_r_r2, cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 1187, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__call__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, PyVectorcall_NARGS(nargs), kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *retval = CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 1187, CPyStatic_globals);
    return NULL;
}

char CPyDef_WalletBalancesRaw_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    CPyTagged cpy_r_r26;
    int64_t cpy_r_r27;
    CPyTagged cpy_r_r28;
    PyObject *cpy_r_r29;
    tuple_T4CIOO cpy_r_r30;
    CPyTagged cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_wallet;
    PyObject *cpy_r_balances;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
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
    char cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    int32_t cpy_r_r61;
    char cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    CPyTagged cpy_r_r65;
    CPyPtr cpy_r_r66;
    int64_t cpy_r_r67;
    CPyTagged cpy_r_r68;
    char cpy_r_r69;
    int64_t cpy_r_r70;
    CPyPtr cpy_r_r71;
    CPyPtr cpy_r_r72;
    int64_t cpy_r_r73;
    CPyPtr cpy_r_r74;
    PyObject *cpy_r_r75;
    tuple_T2OO cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
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
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject **cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    int32_t cpy_r_r99;
    char cpy_r_r100;
    CPyTagged cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject **cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    CPyPtr cpy_r_r111;
    CPyPtr cpy_r_r112;
    CPyPtr cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject **cpy_r_r119;
    PyObject *cpy_r_r120;
    char cpy_r_r121;
    if (cpy_r_seed != NULL) goto CPyL65;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_seed = cpy_r_r0;
CPyL2: ;
    if (cpy_r_block != NULL) goto CPyL66;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_block = cpy_r_r1;
CPyL4: ;
    cpy_r_r2 = CPyDef___init___3_WalletBalancesRaw_env();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1186, CPyStatic_globals);
        goto CPyL67;
    }
    if (((eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *)cpy_r_r2)->_block != NULL) {
        CPy_DECREF(((eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *)cpy_r_r2)->_block);
    }
    ((eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *)cpy_r_r2)->_block = cpy_r_block;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1186, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[22]; /* 'super' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1187, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r7 = (PyObject *)CPyType_WalletBalancesRaw;
    PyObject *cpy_r_r8[2] = {cpy_r_r7, cpy_r_self};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r9, 2, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1187, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r11 = CPyStatics[23]; /* '__init__' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1187, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r13 = CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj();
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1187, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_INCREF(cpy_r_r2);
    if (((eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *)cpy_r_r13)->___mypyc_env__ != NULL) {
        CPy_DECREF(((eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *)cpy_r_r13)->___mypyc_env__);
    }
    ((eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject *)cpy_r_r13)->___mypyc_env__ = cpy_r_r2;
    cpy_r_r14 = 1;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1187, CPyStatic_globals);
        goto CPyL70;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_r13};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1187, CPyStatic_globals);
        goto CPyL71;
    } else
        goto CPyL72;
CPyL12: ;
    CPy_DECREF(cpy_r_r13);
    cpy_r_r18 = ((eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r18 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'block' of '__init___WalletBalancesRaw_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r18);
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1188, CPyStatic_globals);
        goto CPyL73;
    }
CPyL13: ;
    ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block = cpy_r_r18;
    cpy_r_r19 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r20 = cpy_r_seed == cpy_r_r19;
    if (cpy_r_r20) {
        goto CPyL74;
    } else
        goto CPyL15;
CPyL14: ;
    return 1;
CPyL15: ;
    cpy_r_r21 = (PyObject *)&PyDict_Type;
    cpy_r_r22 = PyObject_IsInstance(cpy_r_seed, cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1191, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r24 = cpy_r_r22;
    if (!cpy_r_r24) goto CPyL36;
    if (likely(PyDict_Check(cpy_r_seed)))
        cpy_r_r25 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1192, CPyStatic_globals, "dict", cpy_r_seed);
        goto CPyL64;
    }
    cpy_r_r26 = 0;
    cpy_r_r27 = PyDict_Size(cpy_r_r25);
    cpy_r_r28 = cpy_r_r27 << 1;
    cpy_r_r29 = CPyDict_GetItemsIter(cpy_r_r25);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1192, CPyStatic_globals);
        goto CPyL75;
    }
CPyL19: ;
    cpy_r_r30 = CPyDict_NextItem(cpy_r_r29, cpy_r_r26);
    cpy_r_r31 = cpy_r_r30.f1;
    cpy_r_r26 = cpy_r_r31;
    cpy_r_r32 = cpy_r_r30.f0;
    if (!cpy_r_r32) goto CPyL76;
    cpy_r_r33 = cpy_r_r30.f2;
    CPy_INCREF(cpy_r_r33);
    cpy_r_r34 = cpy_r_r30.f3;
    CPy_INCREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r30.f2);
    CPy_DECREF(cpy_r_r30.f3);
    if (likely(Py_TYPE(cpy_r_r34) == CPyType_TokenBalances))
        cpy_r_r35 = cpy_r_r34;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1192, CPyStatic_globals, "eth_portfolio.typing.TokenBalances", cpy_r_r34);
        goto CPyL77;
    }
    cpy_r_wallet = cpy_r_r33;
    cpy_r_balances = cpy_r_r35;
    cpy_r_r36 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r36);
    cpy_r_r37 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_balances)->_block;
    CPy_INCREF(cpy_r_r37);
    cpy_r_r38 = PyObject_RichCompare(cpy_r_r36, cpy_r_r37, 3);
    CPy_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1193, CPyStatic_globals);
        goto CPyL78;
    }
    if (unlikely(!PyBool_Check(cpy_r_r38))) {
        CPy_TypeError("bool", cpy_r_r38); cpy_r_r39 = 2;
    } else
        cpy_r_r39 = cpy_r_r38 == Py_True;
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r39 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1193, CPyStatic_globals);
        goto CPyL78;
    }
    if (cpy_r_r39) {
        goto CPyL79;
    } else
        goto CPyL31;
CPyL24: ;
    cpy_r_r40 = CPyStatics[49]; /* 'These objects are not from the same block (' */
    cpy_r_r41 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42 = PyObject_Str(cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1195, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r43 = CPyStatics[9]; /* ' and ' */
    cpy_r_r44 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_balances)->_block;
    CPy_INCREF(cpy_r_r44);
    CPy_DECREF(cpy_r_balances);
    cpy_r_r45 = PyObject_Str(cpy_r_r44);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1195, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r46 = CPyStatics[10]; /* ')' */
    cpy_r_r47 = CPyStr_Build(5, cpy_r_r40, cpy_r_r42, cpy_r_r43, cpy_r_r45, cpy_r_r46);
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1195, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r48 = CPyModule_builtins;
    cpy_r_r49 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1194, CPyStatic_globals);
        goto CPyL82;
    }
    PyObject *cpy_r_r51[1] = {cpy_r_r47};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = _PyObject_Vectorcall(cpy_r_r50, cpy_r_r52, 1, 0);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1194, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_DECREF(cpy_r_r47);
    CPy_Raise(cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1194, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL31: ;
    cpy_r_r54 = PyObject_GetItem(cpy_r_self, cpy_r_wallet);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1197, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r55 = PyNumber_InPlaceAdd(cpy_r_r54, cpy_r_balances);
    CPy_DECREF(cpy_r_r54);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1197, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r56 = PyObject_SetItem(cpy_r_self, cpy_r_wallet, cpy_r_r55);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r55);
    cpy_r_r57 = cpy_r_r56 >= 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1197, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r58 = CPyDict_CheckSize(cpy_r_r25, cpy_r_r28);
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1192, CPyStatic_globals);
        goto CPyL84;
    } else
        goto CPyL19;
CPyL35: ;
    cpy_r_r59 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1192, CPyStatic_globals);
        goto CPyL64;
    } else
        goto CPyL63;
CPyL36: ;
    cpy_r_r60 = (PyObject *)&PyList_Type;
    cpy_r_r61 = PyObject_IsInstance(cpy_r_seed, cpy_r_r60);
    cpy_r_r62 = cpy_r_r61 >= 0;
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1198, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r63 = cpy_r_r61;
    if (!cpy_r_r63) goto CPyL56;
    if (likely(PyList_Check(cpy_r_seed)))
        cpy_r_r64 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1199, CPyStatic_globals, "list", cpy_r_seed);
        goto CPyL64;
    }
    cpy_r_r65 = 0;
CPyL40: ;
    cpy_r_r66 = (CPyPtr)&((PyVarObject *)cpy_r_r64)->ob_size;
    cpy_r_r67 = *(int64_t *)cpy_r_r66;
    cpy_r_r68 = cpy_r_r67 << 1;
    cpy_r_r69 = (Py_ssize_t)cpy_r_r65 < (Py_ssize_t)cpy_r_r68;
    if (!cpy_r_r69) goto CPyL85;
    cpy_r_r70 = (Py_ssize_t)cpy_r_r65 >> 1;
    cpy_r_r71 = (CPyPtr)&((PyListObject *)cpy_r_r64)->ob_item;
    cpy_r_r72 = *(CPyPtr *)cpy_r_r71;
    cpy_r_r73 = cpy_r_r70 * 8;
    cpy_r_r74 = cpy_r_r72 + cpy_r_r73;
    cpy_r_r75 = *(PyObject * *)cpy_r_r74;
    CPy_INCREF(cpy_r_r75);
    PyObject *__tmp105;
    if (unlikely(!(PyTuple_Check(cpy_r_r75) && PyTuple_GET_SIZE(cpy_r_r75) == 2))) {
        __tmp105 = NULL;
        goto __LL106;
    }
    __tmp105 = PyTuple_GET_ITEM(cpy_r_r75, 0);
    if (__tmp105 == NULL) goto __LL106;
    if (likely(Py_TYPE(PyTuple_GET_ITEM(cpy_r_r75, 1)) == CPyType_TokenBalances))
        __tmp105 = PyTuple_GET_ITEM(cpy_r_r75, 1);
    else {
        __tmp105 = NULL;
    }
    if (__tmp105 == NULL) goto __LL106;
    __tmp105 = cpy_r_r75;
__LL106: ;
    if (unlikely(__tmp105 == NULL)) {
        CPy_TypeError("tuple[object, eth_portfolio.typing.TokenBalances]", cpy_r_r75); cpy_r_r76 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp107 = PyTuple_GET_ITEM(cpy_r_r75, 0);
        CPy_INCREF(__tmp107);
        PyObject *__tmp108;
        __tmp108 = __tmp107;
        cpy_r_r76.f0 = __tmp108;
        PyObject *__tmp109 = PyTuple_GET_ITEM(cpy_r_r75, 1);
        CPy_INCREF(__tmp109);
        PyObject *__tmp110;
        if (likely(Py_TYPE(__tmp109) == CPyType_TokenBalances))
            __tmp110 = __tmp109;
        else {
            CPy_TypeError("eth_portfolio.typing.TokenBalances", __tmp109); 
            __tmp110 = NULL;
        }
        cpy_r_r76.f1 = __tmp110;
    }
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r76.f0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1199, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r77 = cpy_r_r76.f0;
    CPy_INCREF(cpy_r_r77);
    cpy_r_wallet = cpy_r_r77;
    cpy_r_r78 = cpy_r_r76.f1;
    CPy_INCREF(cpy_r_r78);
    CPy_DECREF(cpy_r_r76.f0);
    CPy_DECREF(cpy_r_r76.f1);
    cpy_r_balances = cpy_r_r78;
    cpy_r_r79 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r79);
    cpy_r_r80 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_balances)->_block;
    CPy_INCREF(cpy_r_r80);
    cpy_r_r81 = PyObject_RichCompare(cpy_r_r79, cpy_r_r80, 3);
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1200, CPyStatic_globals);
        goto CPyL87;
    }
    if (unlikely(!PyBool_Check(cpy_r_r81))) {
        CPy_TypeError("bool", cpy_r_r81); cpy_r_r82 = 2;
    } else
        cpy_r_r82 = cpy_r_r81 == Py_True;
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r82 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1200, CPyStatic_globals);
        goto CPyL87;
    }
    if (cpy_r_r82) {
        goto CPyL88;
    } else
        goto CPyL52;
CPyL45: ;
    cpy_r_r83 = CPyStatics[49]; /* 'These objects are not from the same block (' */
    cpy_r_r84 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r84);
    cpy_r_r85 = PyObject_Str(cpy_r_r84);
    CPy_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1202, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r86 = CPyStatics[9]; /* ' and ' */
    cpy_r_r87 = ((eth_portfolio___typing___TokenBalancesObject *)cpy_r_balances)->_block;
    CPy_INCREF(cpy_r_r87);
    CPy_DECREF(cpy_r_balances);
    cpy_r_r88 = PyObject_Str(cpy_r_r87);
    CPy_DECREF(cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1202, CPyStatic_globals);
        goto CPyL89;
    }
    cpy_r_r89 = CPyStatics[10]; /* ')' */
    cpy_r_r90 = CPyStr_Build(5, cpy_r_r83, cpy_r_r85, cpy_r_r86, cpy_r_r88, cpy_r_r89);
    CPy_DECREF(cpy_r_r85);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1202, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r91 = CPyModule_builtins;
    cpy_r_r92 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r93 = CPyObject_GetAttr(cpy_r_r91, cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1201, CPyStatic_globals);
        goto CPyL90;
    }
    PyObject *cpy_r_r94[1] = {cpy_r_r90};
    cpy_r_r95 = (PyObject **)&cpy_r_r94;
    cpy_r_r96 = _PyObject_Vectorcall(cpy_r_r93, cpy_r_r95, 1, 0);
    CPy_DECREF(cpy_r_r93);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1201, CPyStatic_globals);
        goto CPyL90;
    }
    CPy_DECREF(cpy_r_r90);
    CPy_Raise(cpy_r_r96);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1201, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL52: ;
    cpy_r_r97 = PyObject_GetItem(cpy_r_self, cpy_r_wallet);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1204, CPyStatic_globals);
        goto CPyL87;
    }
    cpy_r_r98 = PyNumber_InPlaceAdd(cpy_r_r97, cpy_r_balances);
    CPy_DECREF(cpy_r_r97);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1204, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r99 = PyObject_SetItem(cpy_r_self, cpy_r_wallet, cpy_r_r98);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r98);
    cpy_r_r100 = cpy_r_r99 >= 0;
    if (unlikely(!cpy_r_r100)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1204, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r101 = cpy_r_r65 + 2;
    cpy_r_r65 = cpy_r_r101;
    goto CPyL40;
CPyL56: ;
    cpy_r_r102 = CPyStatics[3]; /* '' */
    cpy_r_r103 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r104 = CPyStatics[3]; /* '' */
    cpy_r_r105 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r106[3] = {cpy_r_r103, cpy_r_seed, cpy_r_r104};
    cpy_r_r107 = (PyObject **)&cpy_r_r106;
    cpy_r_r108 = PyObject_VectorcallMethod(cpy_r_r105, cpy_r_r107, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1206, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_DECREF(cpy_r_seed);
    cpy_r_r109 = CPyStatics[84]; /* ' is not a valid input for WalletBalancesRaw' */
    cpy_r_r110 = PyList_New(2);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1206, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r111 = (CPyPtr)&((PyListObject *)cpy_r_r110)->ob_item;
    cpy_r_r112 = *(CPyPtr *)cpy_r_r111;
    *(PyObject * *)cpy_r_r112 = cpy_r_r108;
    CPy_INCREF(cpy_r_r109);
    cpy_r_r113 = cpy_r_r112 + 8;
    *(PyObject * *)cpy_r_r113 = cpy_r_r109;
    cpy_r_r114 = PyUnicode_Join(cpy_r_r102, cpy_r_r110);
    CPy_DECREF(cpy_r_r110);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1206, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r115 = CPyModule_builtins;
    cpy_r_r116 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r117 = CPyObject_GetAttr(cpy_r_r115, cpy_r_r116);
    if (unlikely(cpy_r_r117 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1206, CPyStatic_globals);
        goto CPyL93;
    }
    PyObject *cpy_r_r118[1] = {cpy_r_r114};
    cpy_r_r119 = (PyObject **)&cpy_r_r118;
    cpy_r_r120 = _PyObject_Vectorcall(cpy_r_r117, cpy_r_r119, 1, 0);
    CPy_DECREF(cpy_r_r117);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1206, CPyStatic_globals);
        goto CPyL93;
    }
    CPy_DECREF(cpy_r_r114);
    CPy_Raise(cpy_r_r120);
    CPy_DECREF(cpy_r_r120);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1206, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL63: ;
    return 1;
CPyL64: ;
    cpy_r_r121 = 2;
    return cpy_r_r121;
CPyL65: ;
    CPy_INCREF(cpy_r_seed);
    goto CPyL2;
CPyL66: ;
    CPy_INCREF(cpy_r_block);
    goto CPyL4;
CPyL67: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_block);
    goto CPyL64;
CPyL68: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    goto CPyL64;
CPyL69: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    goto CPyL64;
CPyL70: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r13);
    goto CPyL64;
CPyL71: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r13);
    goto CPyL64;
CPyL72: ;
    CPy_DECREF(cpy_r_r17);
    goto CPyL12;
CPyL73: ;
    CPy_DecRef(cpy_r_seed);
    goto CPyL64;
CPyL74: ;
    CPy_DECREF(cpy_r_seed);
    goto CPyL14;
CPyL75: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL64;
CPyL76: ;
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r30.f2);
    CPy_DECREF(cpy_r_r30.f3);
    goto CPyL35;
CPyL77: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r33);
    goto CPyL64;
CPyL78: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balances);
    goto CPyL64;
CPyL79: ;
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_wallet);
    goto CPyL24;
CPyL80: ;
    CPy_DecRef(cpy_r_balances);
    goto CPyL64;
CPyL81: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL64;
CPyL82: ;
    CPy_DecRef(cpy_r_r47);
    goto CPyL64;
CPyL83: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_wallet);
    goto CPyL64;
CPyL84: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    goto CPyL64;
CPyL85: ;
    CPy_DECREF(cpy_r_r64);
    goto CPyL63;
CPyL86: ;
    CPy_DecRef(cpy_r_r64);
    goto CPyL64;
CPyL87: ;
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balances);
    CPy_DecRef(cpy_r_r64);
    goto CPyL64;
CPyL88: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r64);
    goto CPyL45;
CPyL89: ;
    CPy_DecRef(cpy_r_r85);
    goto CPyL64;
CPyL90: ;
    CPy_DecRef(cpy_r_r90);
    goto CPyL64;
CPyL91: ;
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_r64);
    goto CPyL64;
CPyL92: ;
    CPy_DecRef(cpy_r_r108);
    goto CPyL64;
CPyL93: ;
    CPy_DecRef(cpy_r_r114);
    goto CPyL64;
}

PyObject *CPyPy_WalletBalancesRaw_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"seed", "block", 0};
    PyObject *obj_seed = NULL;
    PyObject *obj_block = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|O$O", "__init__", kwlist, &obj_seed, &obj_block)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WalletBalancesRaw))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalancesRaw", obj_self); 
        goto fail;
    }
    PyObject *arg_seed;
    if (obj_seed == NULL) {
        arg_seed = NULL;
        goto __LL111;
    }
    if (PyDict_Check(obj_seed))
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL111;
    if (PyList_Check(obj_seed))
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL111;
    if (obj_seed == Py_None)
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL111;
    CPy_TypeError("union[dict, list, None]", obj_seed); 
    goto fail;
__LL111: ;
    PyObject *arg_block;
    if (obj_block == NULL) {
        arg_block = NULL;
        goto __LL112;
    }
    if (PyLong_Check(obj_block))
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL112;
    if (obj_block == Py_None)
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL112;
    CPy_TypeError("int or None", obj_block); 
    goto fail;
__LL112: ;
    char retval = CPyDef_WalletBalancesRaw_____init__(arg_self, arg_seed, arg_block);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1186, CPyStatic_globals);
    return NULL;
}

char CPyDef_WalletBalancesRaw_____bool__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    cpy_r_r0 = CPyStatics[40]; /* 'values' */
    PyObject *cpy_r_r1[1] = {cpy_r_self};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1220, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[42]; /* 'any' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1220, CPyStatic_globals);
        goto CPyL6;
    }
    PyObject *cpy_r_r7[1] = {cpy_r_r3};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 1, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1220, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r3);
    if (unlikely(!PyBool_Check(cpy_r_r9))) {
        CPy_TypeError("bool", cpy_r_r9); cpy_r_r10 = 2;
    } else
        cpy_r_r10 = cpy_r_r9 == Py_True;
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1220, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r10;
CPyL5: ;
    cpy_r_r11 = 2;
    return cpy_r_r11;
CPyL6: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL5;
}

PyObject *CPyPy_WalletBalancesRaw_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__bool__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WalletBalancesRaw))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalancesRaw", obj_self); 
        goto fail;
    }
    char retval = CPyDef_WalletBalancesRaw_____bool__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1208, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalancesRaw_____repr__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[81]; /* 'WalletBalances' */
    cpy_r_r1 = CPyDict_FromAny(cpy_r_self);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1229, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r2 = PyObject_Str(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1229, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r3 = CPyStr_Build(2, cpy_r_r0, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1229, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy_WalletBalancesRaw_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__repr__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WalletBalancesRaw))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalancesRaw", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalancesRaw_____repr__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1222, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalancesRaw_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
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
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_wallet;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_balance;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    int32_t cpy_r_r57;
    char cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject **cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject **cpy_r_r67;
    PyObject *cpy_r_r68;
    char cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    char cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    int32_t cpy_r_r83;
    char cpy_r_r84;
    char cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject **cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject **cpy_r_r93;
    PyObject *cpy_r_r94;
    char cpy_r_r95;
    PyObject *cpy_r_r96;
    cpy_r_r0 = (PyObject *)CPyType_WalletBalancesRaw;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1252, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r11 = CPyStatics[85]; /* ' is not a WalletBalancesRaw object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1252, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1252, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1252, CPyStatic_globals);
        goto CPyL62;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1252, CPyStatic_globals);
        goto CPyL62;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1252, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PyObject_RichCompare(cpy_r_r23, cpy_r_r24, 3);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1253, CPyStatic_globals);
        goto CPyL60;
    }
    if (unlikely(!PyBool_Check(cpy_r_r25))) {
        CPy_TypeError("bool", cpy_r_r25); cpy_r_r26 = 2;
    } else
        cpy_r_r26 = cpy_r_r25 == Py_True;
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1253, CPyStatic_globals);
        goto CPyL60;
    }
    if (!cpy_r_r26) goto CPyL18;
    cpy_r_r27 = CPyStatics[86]; /* ('These WalletBalancesRaw objects are not from the same '
                                   'block (') */
    cpy_r_r28 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r28);
    cpy_r_r29 = PyObject_Str(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1255, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r30 = CPyStatics[9]; /* ' and ' */
    cpy_r_r31 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r31);
    cpy_r_r32 = PyObject_Str(cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1255, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r33 = CPyStatics[10]; /* ')' */
    cpy_r_r34 = CPyStr_Build(5, cpy_r_r27, cpy_r_r29, cpy_r_r30, cpy_r_r32, cpy_r_r33);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1255, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1254, CPyStatic_globals);
        goto CPyL64;
    }
    PyObject *cpy_r_r38[1] = {cpy_r_r34};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r39, 1, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1254, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_DECREF(cpy_r_r34);
    CPy_Raise(cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1254, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r41 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42 = NULL;
    cpy_r_r43 = CPyDef_WalletBalancesRaw(cpy_r_r42, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1258, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r44 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r45[1] = {cpy_r_self};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = PyObject_VectorcallMethod(cpy_r_r44, cpy_r_r46, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1259, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r48 = PyObject_GetIter(cpy_r_r47);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1259, CPyStatic_globals);
        goto CPyL65;
    }
CPyL21: ;
    cpy_r_r49 = PyIter_Next(cpy_r_r48);
    if (cpy_r_r49 == NULL) goto CPyL66;
    cpy_r_r50 = PyObject_GetIter(cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1259, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r51 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r51 == NULL) {
        goto CPyL68;
    } else
        goto CPyL26;
CPyL24: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r52 = 0;
    if (unlikely(!cpy_r_r52)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1259, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_wallet = cpy_r_r51;
    cpy_r_r53 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r53 == NULL) {
        goto CPyL69;
    } else
        goto CPyL29;
CPyL27: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r54 = 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1259, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL29: ;
    cpy_r_balance = cpy_r_r53;
    cpy_r_r55 = PyIter_Next(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (cpy_r_r55 == NULL) {
        goto CPyL32;
    } else
        goto CPyL70;
CPyL30: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r56 = 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1259, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL32: ;
    cpy_r_r57 = PyObject_IsTrue(cpy_r_balance);
    cpy_r_r58 = cpy_r_r57 >= 0;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1259, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r59 = cpy_r_r57;
    if (!cpy_r_r59) goto CPyL72;
    cpy_r_r60 = CPyStatics[47]; /* '_getitem_nochecksum' */
    PyObject *cpy_r_r61[2] = {cpy_r_r43, cpy_r_wallet};
    cpy_r_r62 = (PyObject **)&cpy_r_r61;
    cpy_r_r63 = PyObject_VectorcallMethod(cpy_r_r60, cpy_r_r62, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1261, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r64 = PyNumber_Add(cpy_r_r63, cpy_r_balance);
    CPy_DECREF(cpy_r_r63);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1261, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r65 = CPyStatics[46]; /* '_setitem_nochecksum' */
    PyObject *cpy_r_r66[3] = {cpy_r_r43, cpy_r_wallet, cpy_r_r64};
    cpy_r_r67 = (PyObject **)&cpy_r_r66;
    cpy_r_r68 = PyObject_VectorcallMethod(cpy_r_r65, cpy_r_r67, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1261, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL75;
CPyL37: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r64);
    goto CPyL21;
CPyL38: ;
    cpy_r_r69 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r69)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1259, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r70 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r71[1] = {cpy_r_other};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = PyObject_VectorcallMethod(cpy_r_r70, cpy_r_r72, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1262, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r74 = PyObject_GetIter(cpy_r_r73);
    CPy_DECREF(cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1262, CPyStatic_globals);
        goto CPyL65;
    }
CPyL41: ;
    cpy_r_r75 = PyIter_Next(cpy_r_r74);
    if (cpy_r_r75 == NULL) goto CPyL76;
    cpy_r_r76 = PyObject_GetIter(cpy_r_r75);
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1262, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r77 = PyIter_Next(cpy_r_r76);
    if (cpy_r_r77 == NULL) {
        goto CPyL78;
    } else
        goto CPyL46;
CPyL44: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r78 = 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1262, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL46: ;
    cpy_r_wallet = cpy_r_r77;
    cpy_r_r79 = PyIter_Next(cpy_r_r76);
    if (cpy_r_r79 == NULL) {
        goto CPyL79;
    } else
        goto CPyL49;
CPyL47: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r80 = 0;
    if (unlikely(!cpy_r_r80)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1262, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL49: ;
    cpy_r_balance = cpy_r_r79;
    cpy_r_r81 = PyIter_Next(cpy_r_r76);
    CPy_DECREF(cpy_r_r76);
    if (cpy_r_r81 == NULL) {
        goto CPyL52;
    } else
        goto CPyL80;
CPyL50: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r82 = 0;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1262, CPyStatic_globals);
        goto CPyL60;
    }
    CPy_Unreachable();
CPyL52: ;
    cpy_r_r83 = PyObject_IsTrue(cpy_r_balance);
    cpy_r_r84 = cpy_r_r83 >= 0;
    if (unlikely(!cpy_r_r84)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1259, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r85 = cpy_r_r83;
    if (!cpy_r_r85) goto CPyL82;
    cpy_r_r86 = CPyStatics[47]; /* '_getitem_nochecksum' */
    PyObject *cpy_r_r87[2] = {cpy_r_r43, cpy_r_wallet};
    cpy_r_r88 = (PyObject **)&cpy_r_r87;
    cpy_r_r89 = PyObject_VectorcallMethod(cpy_r_r86, cpy_r_r88, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1264, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r90 = PyNumber_Add(cpy_r_r89, cpy_r_balance);
    CPy_DECREF(cpy_r_r89);
    CPy_DECREF(cpy_r_balance);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1264, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r91 = CPyStatics[46]; /* '_setitem_nochecksum' */
    PyObject *cpy_r_r92[3] = {cpy_r_r43, cpy_r_wallet, cpy_r_r90};
    cpy_r_r93 = (PyObject **)&cpy_r_r92;
    cpy_r_r94 = PyObject_VectorcallMethod(cpy_r_r91, cpy_r_r93, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1264, CPyStatic_globals);
        goto CPyL84;
    } else
        goto CPyL85;
CPyL57: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r90);
    goto CPyL41;
CPyL58: ;
    cpy_r_r95 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r95)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1262, CPyStatic_globals);
        goto CPyL65;
    }
    return cpy_r_r43;
CPyL60: ;
    cpy_r_r96 = NULL;
    return cpy_r_r96;
CPyL61: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL60;
CPyL62: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL60;
CPyL63: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL60;
CPyL64: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL60;
CPyL65: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL60;
CPyL66: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL38;
CPyL67: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    goto CPyL60;
CPyL68: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    goto CPyL24;
CPyL69: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    CPy_DECREF(cpy_r_wallet);
    goto CPyL27;
CPyL70: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balance);
    CPy_DECREF(cpy_r_r55);
    goto CPyL30;
CPyL71: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balance);
    goto CPyL60;
CPyL72: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balance);
    goto CPyL21;
CPyL73: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_wallet);
    goto CPyL60;
CPyL74: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_r64);
    goto CPyL60;
CPyL75: ;
    CPy_DECREF(cpy_r_r68);
    goto CPyL37;
CPyL76: ;
    CPy_DECREF(cpy_r_r74);
    goto CPyL58;
CPyL77: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r74);
    goto CPyL60;
CPyL78: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r76);
    goto CPyL44;
CPyL79: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r76);
    goto CPyL47;
CPyL80: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balance);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r81);
    goto CPyL50;
CPyL81: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balance);
    CPy_DecRef(cpy_r_r74);
    goto CPyL60;
CPyL82: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balance);
    goto CPyL41;
CPyL83: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_r74);
    goto CPyL60;
CPyL84: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r90);
    goto CPyL60;
CPyL85: ;
    CPy_DECREF(cpy_r_r94);
    goto CPyL57;
}

PyObject *CPyPy_WalletBalancesRaw_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WalletBalancesRaw))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalancesRaw", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(Py_TYPE(obj_other) == CPyType_WalletBalancesRaw))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalancesRaw", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalancesRaw_____add__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1231, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalancesRaw_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPy_INCREF(cpy_r_other);
    if (likely(Py_TYPE(cpy_r_other) == CPyType_WalletBalancesRaw))
        cpy_r_r0 = cpy_r_other;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalancesRaw", cpy_r_other); 
        cpy_r_r0 = NULL;
    }
    if (cpy_r_r0 == NULL) goto CPyL3;
    cpy_r_r1 = CPyDef_WalletBalancesRaw_____add__(cpy_r_self, cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL3;
    return cpy_r_r1;
CPyL3: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_WalletBalancesRaw_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add_____SummableNonNumericMixin_glue", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WalletBalancesRaw))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalancesRaw", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyObject_TypeCheck(obj_other, CPyType__SummableNonNumericMixin)))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalancesRaw_____add___3___SummableNonNumericMixin_glue(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add_____SummableNonNumericMixin_glue", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_WalletBalancesRaw_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
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
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_wallet;
    PyObject *cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_balances;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    int32_t cpy_r_r57;
    char cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    int32_t cpy_r_r62;
    char cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject **cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    char cpy_r_r73;
    PyObject *cpy_r_r74;
    char cpy_r_r75;
    PyObject *cpy_r_r76;
    char cpy_r_r77;
    int32_t cpy_r_r78;
    char cpy_r_r79;
    char cpy_r_r80;
    int32_t cpy_r_r81;
    char cpy_r_r82;
    char cpy_r_r83;
    PyObject *cpy_r_r84;
    cpy_r_r0 = (PyObject *)CPyType_WalletBalancesRaw;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1288, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r11 = CPyStatics[85]; /* ' is not a WalletBalancesRaw object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1288, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1288, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1288, CPyStatic_globals);
        goto CPyL59;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1288, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1288, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PyObject_RichCompare(cpy_r_r23, cpy_r_r24, 3);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1289, CPyStatic_globals);
        goto CPyL57;
    }
    if (unlikely(!PyBool_Check(cpy_r_r25))) {
        CPy_TypeError("bool", cpy_r_r25); cpy_r_r26 = 2;
    } else
        cpy_r_r26 = cpy_r_r25 == Py_True;
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1289, CPyStatic_globals);
        goto CPyL57;
    }
    if (!cpy_r_r26) goto CPyL18;
    cpy_r_r27 = CPyStatics[86]; /* ('These WalletBalancesRaw objects are not from the same '
                                   'block (') */
    cpy_r_r28 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_self)->_block;
    CPy_INCREF(cpy_r_r28);
    cpy_r_r29 = PyObject_Str(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1291, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r30 = CPyStatics[9]; /* ' and ' */
    cpy_r_r31 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r31);
    cpy_r_r32 = PyObject_Str(cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1291, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r33 = CPyStatics[10]; /* ')' */
    cpy_r_r34 = CPyStr_Build(5, cpy_r_r27, cpy_r_r29, cpy_r_r30, cpy_r_r32, cpy_r_r33);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1291, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r35 = CPyModule_builtins;
    cpy_r_r36 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1290, CPyStatic_globals);
        goto CPyL61;
    }
    PyObject *cpy_r_r38[1] = {cpy_r_r34};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = _PyObject_Vectorcall(cpy_r_r37, cpy_r_r39, 1, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1290, CPyStatic_globals);
        goto CPyL61;
    }
    CPy_DECREF(cpy_r_r34);
    CPy_Raise(cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1290, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r41 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_other)->_block;
    CPy_INCREF(cpy_r_r41);
    CPy_INCREF(cpy_r_self);
    if (PyDict_Check(cpy_r_self))
        cpy_r_r42 = cpy_r_self;
    else {
        cpy_r_r42 = NULL;
    }
    if (cpy_r_r42 != NULL) goto __LL113;
    if (PyList_Check(cpy_r_self))
        cpy_r_r42 = cpy_r_self;
    else {
        cpy_r_r42 = NULL;
    }
    if (cpy_r_r42 != NULL) goto __LL113;
    if (cpy_r_self == Py_None)
        cpy_r_r42 = cpy_r_self;
    else {
        cpy_r_r42 = NULL;
    }
    if (cpy_r_r42 != NULL) goto __LL113;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1294, CPyStatic_globals, "union[dict, list, None]", cpy_r_self);
    goto CPyL62;
__LL113: ;
    cpy_r_r43 = CPyDef_WalletBalancesRaw(cpy_r_r42, cpy_r_r41);
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1294, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r44 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r45[1] = {cpy_r_other};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = PyObject_VectorcallMethod(cpy_r_r44, cpy_r_r46, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1295, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r48 = PyObject_GetIter(cpy_r_r47);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1295, CPyStatic_globals);
        goto CPyL63;
    }
CPyL22: ;
    cpy_r_r49 = PyIter_Next(cpy_r_r48);
    if (cpy_r_r49 == NULL) goto CPyL64;
    cpy_r_r50 = PyObject_GetIter(cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1295, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r51 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r51 == NULL) {
        goto CPyL66;
    } else
        goto CPyL27;
CPyL25: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r52 = 0;
    if (unlikely(!cpy_r_r52)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1295, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL27: ;
    cpy_r_wallet = cpy_r_r51;
    cpy_r_r53 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r53 == NULL) {
        goto CPyL67;
    } else
        goto CPyL30;
CPyL28: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r54 = 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1295, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL30: ;
    cpy_r_balances = cpy_r_r53;
    cpy_r_r55 = PyIter_Next(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (cpy_r_r55 == NULL) {
        goto CPyL33;
    } else
        goto CPyL68;
CPyL31: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r56 = 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1295, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL33: ;
    cpy_r_r57 = PyObject_IsTrue(cpy_r_balances);
    cpy_r_r58 = cpy_r_r57 >= 0;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1295, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r59 = cpy_r_r57;
    if (!cpy_r_r59) goto CPyL70;
    cpy_r_r60 = PyObject_GetItem(cpy_r_r43, cpy_r_wallet);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1297, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r61 = PyNumber_InPlaceSubtract(cpy_r_r60, cpy_r_balances);
    CPy_DECREF(cpy_r_r60);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1297, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r62 = PyObject_SetItem(cpy_r_r43, cpy_r_wallet, cpy_r_r61);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r61);
    cpy_r_r63 = cpy_r_r62 >= 0;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1297, CPyStatic_globals);
        goto CPyL65;
    } else
        goto CPyL22;
CPyL38: ;
    cpy_r_r64 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1295, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r65 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r66[1] = {cpy_r_r43};
    cpy_r_r67 = (PyObject **)&cpy_r_r66;
    cpy_r_r68 = PyObject_VectorcallMethod(cpy_r_r65, cpy_r_r67, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1298, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r69 = PyObject_GetIter(cpy_r_r68);
    CPy_DECREF(cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1298, CPyStatic_globals);
        goto CPyL63;
    }
CPyL41: ;
    cpy_r_r70 = PyIter_Next(cpy_r_r69);
    if (cpy_r_r70 == NULL) goto CPyL72;
    cpy_r_r71 = PyObject_GetIter(cpy_r_r70);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1298, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r72 = PyIter_Next(cpy_r_r71);
    if (cpy_r_r72 == NULL) {
        goto CPyL74;
    } else
        goto CPyL46;
CPyL44: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r73 = 0;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1298, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL46: ;
    cpy_r_wallet = cpy_r_r72;
    cpy_r_r74 = PyIter_Next(cpy_r_r71);
    if (cpy_r_r74 == NULL) {
        goto CPyL75;
    } else
        goto CPyL49;
CPyL47: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r75 = 0;
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1298, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL49: ;
    cpy_r_balances = cpy_r_r74;
    cpy_r_r76 = PyIter_Next(cpy_r_r71);
    CPy_DECREF(cpy_r_r71);
    if (cpy_r_r76 == NULL) {
        goto CPyL52;
    } else
        goto CPyL76;
CPyL50: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r77 = 0;
    if (unlikely(!cpy_r_r77)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1298, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_Unreachable();
CPyL52: ;
    cpy_r_r78 = PyObject_IsTrue(cpy_r_balances);
    CPy_DECREF(cpy_r_balances);
    cpy_r_r79 = cpy_r_r78 >= 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1295, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r80 = cpy_r_r78;
    if (cpy_r_r80) goto CPyL78;
    cpy_r_r81 = PyObject_DelItem(cpy_r_r43, cpy_r_wallet);
    CPy_DECREF(cpy_r_wallet);
    cpy_r_r82 = cpy_r_r81 >= 0;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1300, CPyStatic_globals);
        goto CPyL73;
    } else
        goto CPyL41;
CPyL55: ;
    cpy_r_r83 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1298, CPyStatic_globals);
        goto CPyL63;
    }
    return cpy_r_r43;
CPyL57: ;
    cpy_r_r84 = NULL;
    return cpy_r_r84;
CPyL58: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL57;
CPyL59: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL57;
CPyL60: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL57;
CPyL61: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL57;
CPyL62: ;
    CPy_DecRef(cpy_r_r41);
    goto CPyL57;
CPyL63: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL57;
CPyL64: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL38;
CPyL65: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    goto CPyL57;
CPyL66: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    goto CPyL25;
CPyL67: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    CPy_DECREF(cpy_r_wallet);
    goto CPyL28;
CPyL68: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balances);
    CPy_DECREF(cpy_r_r55);
    goto CPyL31;
CPyL69: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_balances);
    goto CPyL57;
CPyL70: ;
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balances);
    goto CPyL22;
CPyL71: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_wallet);
    goto CPyL57;
CPyL72: ;
    CPy_DECREF(cpy_r_r69);
    goto CPyL55;
CPyL73: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r69);
    goto CPyL57;
CPyL74: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r71);
    goto CPyL44;
CPyL75: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r71);
    goto CPyL47;
CPyL76: ;
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_wallet);
    CPy_DECREF(cpy_r_balances);
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r76);
    goto CPyL50;
CPyL77: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_wallet);
    CPy_DecRef(cpy_r_r69);
    goto CPyL57;
CPyL78: ;
    CPy_DECREF(cpy_r_wallet);
    goto CPyL41;
}

PyObject *CPyPy_WalletBalancesRaw_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__sub__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_WalletBalancesRaw))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalancesRaw", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(Py_TYPE(obj_other) == CPyType_WalletBalancesRaw))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing.WalletBalancesRaw", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_WalletBalancesRaw_____sub__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1267, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
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

PyObject *CPyPy___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
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
    PyObject *retval = CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__(PyObject *cpy_r___mypyc_self__) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = ((eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("eth_portfolio\\typing.py", "<lambda>", "__mypyc_lambda__3___init___PortfolioBalancesByCategory_obj", "__mypyc_env__", 1331, CPyStatic_globals);
        goto CPyL4;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *)cpy_r_r0)->_block;
    if (unlikely(cpy_r_r1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'block' of '__init___PortfolioBalancesByCategory_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r1);
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 1331, CPyStatic_globals);
        goto CPyL4;
    }
CPyL2: ;
    cpy_r_r2 = NULL;
    cpy_r_r3 = CPyDef_WalletBalancesRaw(cpy_r_r2, cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 1331, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__call__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, PyVectorcall_NARGS(nargs), kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *retval = CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__(arg___mypyc_self__);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "<lambda>", 1331, CPyStatic_globals);
    return NULL;
}

char CPyDef_PortfolioBalancesByCategory_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    int32_t cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    int32_t cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    CPyPtr cpy_r_r45;
    CPyPtr cpy_r_r46;
    CPyPtr cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject **cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_label;
    PyObject *cpy_r_r61;
    char cpy_r_r62;
    PyObject *cpy_r_balances;
    PyObject *cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    CPyPtr cpy_r_r69;
    PyObject *cpy_r_r70;
    char cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    char cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    CPyPtr cpy_r_r87;
    PyObject *cpy_r_r88;
    char cpy_r_r89;
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
    PyObject **cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    int32_t cpy_r_r107;
    char cpy_r_r108;
    char cpy_r_r109;
    char cpy_r_r110;
    if (cpy_r_seed != NULL) goto CPyL74;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_seed = cpy_r_r0;
CPyL2: ;
    if (cpy_r_block != NULL) goto CPyL75;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_block = cpy_r_r1;
CPyL4: ;
    cpy_r_r2 = CPyDef___init___3_PortfolioBalancesByCategory_env();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1330, CPyStatic_globals);
        goto CPyL76;
    }
    if (((eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *)cpy_r_r2)->_block != NULL) {
        CPy_DECREF(((eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *)cpy_r_r2)->_block);
    }
    ((eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *)cpy_r_r2)->_block = cpy_r_block;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1330, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[22]; /* 'super' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1331, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r7 = (PyObject *)CPyType_PortfolioBalancesByCategory;
    PyObject *cpy_r_r8[2] = {cpy_r_r7, cpy_r_self};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r9, 2, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1331, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r11 = CPyStatics[23]; /* '__init__' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1331, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r13 = CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj();
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1331, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_INCREF(cpy_r_r2);
    if (((eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *)cpy_r_r13)->___mypyc_env__ != NULL) {
        CPy_DECREF(((eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *)cpy_r_r13)->___mypyc_env__);
    }
    ((eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject *)cpy_r_r13)->___mypyc_env__ = cpy_r_r2;
    cpy_r_r14 = 1;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1331, CPyStatic_globals);
        goto CPyL79;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_r13};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1331, CPyStatic_globals);
        goto CPyL80;
    } else
        goto CPyL81;
CPyL12: ;
    CPy_DECREF(cpy_r_r13);
    cpy_r_r18 = ((eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject *)cpy_r_r2)->_block;
    if (unlikely(cpy_r_r18 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'block' of '__init___PortfolioBalancesByCategory_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r18);
    }
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1332, CPyStatic_globals);
        goto CPyL82;
    }
CPyL13: ;
    cpy_r_r19 = CPyStatics[48]; /* 'block' */
    cpy_r_r20 = PyObject_SetAttr(cpy_r_self, cpy_r_r19, cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r21 = cpy_r_r20 >= 0;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1332, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r22 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r23 = cpy_r_seed == cpy_r_r22;
    if (cpy_r_r23) {
        goto CPyL83;
    } else
        goto CPyL16;
CPyL15: ;
    return 1;
CPyL16: ;
    cpy_r_r24 = (PyObject *)&PyDict_Type;
    cpy_r_r25 = PyObject_IsInstance(cpy_r_seed, cpy_r_r24);
    cpy_r_r26 = cpy_r_r25 >= 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1335, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r27 = cpy_r_r25;
    if (!cpy_r_r27) goto CPyL21;
    if (likely(PyDict_Check(cpy_r_seed)))
        cpy_r_r28 = cpy_r_seed;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1336, CPyStatic_globals, "dict", cpy_r_seed);
        goto CPyL73;
    }
    cpy_r_r29 = CPyDict_ItemsView(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1336, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_seed = cpy_r_r29;
CPyL21: ;
    cpy_r_r30 = CPyStatic_globals;
    cpy_r_r31 = CPyStatics[61]; /* 'Iterable' */
    cpy_r_r32 = CPyDict_GetItem(cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1337, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r33 = PyObject_IsInstance(cpy_r_seed, cpy_r_r32);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1337, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r35 = cpy_r_r33;
    if (cpy_r_r35) goto CPyL31;
    cpy_r_r36 = CPyStatics[3]; /* '' */
    cpy_r_r37 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r38 = CPyStatics[3]; /* '' */
    cpy_r_r39 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r40[3] = {cpy_r_r37, cpy_r_seed, cpy_r_r38};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = PyObject_VectorcallMethod(cpy_r_r39, cpy_r_r41, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1338, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_DECREF(cpy_r_seed);
    cpy_r_r43 = CPyStatics[87]; /* ' is not a valid input for PortfolioBalancesByCategory' */
    cpy_r_r44 = PyList_New(2);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1338, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r45 = (CPyPtr)&((PyListObject *)cpy_r_r44)->ob_item;
    cpy_r_r46 = *(CPyPtr *)cpy_r_r45;
    *(PyObject * *)cpy_r_r46 = cpy_r_r42;
    CPy_INCREF(cpy_r_r43);
    cpy_r_r47 = cpy_r_r46 + 8;
    *(PyObject * *)cpy_r_r47 = cpy_r_r43;
    cpy_r_r48 = PyUnicode_Join(cpy_r_r36, cpy_r_r44);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1338, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r49 = CPyModule_builtins;
    cpy_r_r50 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r51 = CPyObject_GetAttr(cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1338, CPyStatic_globals);
        goto CPyL85;
    }
    PyObject *cpy_r_r52[1] = {cpy_r_r48};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = _PyObject_Vectorcall(cpy_r_r51, cpy_r_r53, 1, 0);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1338, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_DECREF(cpy_r_r48);
    CPy_Raise(cpy_r_r54);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1338, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_Unreachable();
CPyL31: ;
    cpy_r_r55 = PyObject_GetIter(cpy_r_seed);
    CPy_DECREF(cpy_r_seed);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1339, CPyStatic_globals);
        goto CPyL73;
    }
CPyL32: ;
    cpy_r_r56 = PyIter_Next(cpy_r_r55);
    if (cpy_r_r56 == NULL) goto CPyL86;
    if (PyUnicode_Check(cpy_r_r56))
        cpy_r_r57 = cpy_r_r56;
    else {
        cpy_r_r57 = NULL;
    }
    if (cpy_r_r57 != NULL) goto __LL114;
    if (unlikely(!(PyTuple_Check(cpy_r_r56) && PyTuple_GET_SIZE(cpy_r_r56) == 2))) {
        cpy_r_r57 = NULL;
        goto __LL115;
    }
    if (likely(PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r56, 0))))
        cpy_r_r57 = PyTuple_GET_ITEM(cpy_r_r56, 0);
    else {
        cpy_r_r57 = NULL;
    }
    if (cpy_r_r57 == NULL) goto __LL115;
    if (likely(Py_TYPE(PyTuple_GET_ITEM(cpy_r_r56, 1)) == CPyType_WalletBalancesRaw))
        cpy_r_r57 = PyTuple_GET_ITEM(cpy_r_r56, 1);
    else {
        cpy_r_r57 = NULL;
    }
    if (cpy_r_r57 == NULL) goto __LL115;
    cpy_r_r57 = cpy_r_r56;
__LL115: ;
    if (cpy_r_r57 != NULL) goto __LL114;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1339, CPyStatic_globals, "union[str, tuple[str, eth_portfolio.typing.WalletBalancesRaw]]", cpy_r_r56);
    goto CPyL87;
__LL114: ;
    cpy_r_r58 = PyObject_GetIter(cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1339, CPyStatic_globals);
        goto CPyL87;
    }
    cpy_r_r59 = PyIter_Next(cpy_r_r58);
    if (cpy_r_r59 == NULL) {
        goto CPyL88;
    } else
        goto CPyL38;
CPyL36: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r60 = 0;
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1339, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_Unreachable();
CPyL38: ;
    cpy_r_label = cpy_r_r59;
    cpy_r_r61 = PyIter_Next(cpy_r_r58);
    if (cpy_r_r61 == NULL) {
        goto CPyL89;
    } else
        goto CPyL41;
CPyL39: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r62 = 0;
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1339, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_Unreachable();
CPyL41: ;
    cpy_r_balances = cpy_r_r61;
    cpy_r_r63 = PyIter_Next(cpy_r_r58);
    CPy_DECREF(cpy_r_r58);
    if (cpy_r_r63 == NULL) {
        goto CPyL44;
    } else
        goto CPyL90;
CPyL42: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r64 = 0;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1339, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_Unreachable();
CPyL44: ;
    cpy_r_r65 = CPyStatics[48]; /* 'block' */
    cpy_r_r66 = CPyObject_GetAttr(cpy_r_self, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1340, CPyStatic_globals);
        goto CPyL91;
    }
    if (PyLong_Check(cpy_r_r66))
        cpy_r_r67 = cpy_r_r66;
    else {
        cpy_r_r67 = NULL;
    }
    if (cpy_r_r67 != NULL) goto __LL116;
    if (cpy_r_r66 == Py_None)
        cpy_r_r67 = cpy_r_r66;
    else {
        cpy_r_r67 = NULL;
    }
    if (cpy_r_r67 != NULL) goto __LL116;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1340, CPyStatic_globals, "int or None", cpy_r_r66);
    goto CPyL91;
__LL116: ;
    cpy_r_r68 = (PyObject *)CPyType_WalletBalancesRaw;
    cpy_r_r69 = (CPyPtr)&((PyObject *)cpy_r_balances)->ob_type;
    cpy_r_r70 = *(PyObject * *)cpy_r_r69;
    cpy_r_r71 = cpy_r_r70 == cpy_r_r68;
    if (!cpy_r_r71) goto CPyL49;
    CPy_INCREF(cpy_r_balances);
    if (likely(Py_TYPE(cpy_r_balances) == CPyType_WalletBalancesRaw))
        cpy_r_r72 = cpy_r_balances;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1340, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_balances);
        goto CPyL92;
    }
    cpy_r_r73 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_r72)->_block;
    CPy_INCREF(cpy_r_r73);
    CPy_DECREF(cpy_r_r72);
    cpy_r_r74 = cpy_r_r73;
    goto CPyL51;
CPyL49: ;
    CPy_INCREF(cpy_r_balances);
    cpy_r_r75 = cpy_r_balances;
    cpy_r_r76 = CPyStatics[48]; /* 'block' */
    cpy_r_r77 = CPyObject_GetAttr(cpy_r_r75, cpy_r_r76);
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1340, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r74 = cpy_r_r77;
CPyL51: ;
    cpy_r_r78 = PyObject_RichCompare(cpy_r_r67, cpy_r_r74, 3);
    CPy_DECREF(cpy_r_r67);
    CPy_DECREF(cpy_r_r74);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1340, CPyStatic_globals);
        goto CPyL91;
    }
    if (unlikely(!PyBool_Check(cpy_r_r78))) {
        CPy_TypeError("bool", cpy_r_r78); cpy_r_r79 = 2;
    } else
        cpy_r_r79 = cpy_r_r78 == Py_True;
    CPy_DECREF(cpy_r_r78);
    if (unlikely(cpy_r_r79 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1340, CPyStatic_globals);
        goto CPyL91;
    }
    if (cpy_r_r79) {
        goto CPyL93;
    } else
        goto CPyL68;
CPyL54: ;
    cpy_r_r80 = CPyStatics[49]; /* 'These objects are not from the same block (' */
    cpy_r_r81 = CPyStatics[48]; /* 'block' */
    cpy_r_r82 = CPyObject_GetAttr(cpy_r_self, cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1342, CPyStatic_globals);
        goto CPyL94;
    }
    if (PyLong_Check(cpy_r_r82))
        cpy_r_r83 = cpy_r_r82;
    else {
        cpy_r_r83 = NULL;
    }
    if (cpy_r_r83 != NULL) goto __LL117;
    if (cpy_r_r82 == Py_None)
        cpy_r_r83 = cpy_r_r82;
    else {
        cpy_r_r83 = NULL;
    }
    if (cpy_r_r83 != NULL) goto __LL117;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1342, CPyStatic_globals, "int or None", cpy_r_r82);
    goto CPyL94;
__LL117: ;
    cpy_r_r84 = PyObject_Str(cpy_r_r83);
    CPy_DECREF(cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1342, CPyStatic_globals);
        goto CPyL94;
    }
    cpy_r_r85 = CPyStatics[9]; /* ' and ' */
    cpy_r_r86 = (PyObject *)CPyType_WalletBalancesRaw;
    cpy_r_r87 = (CPyPtr)&((PyObject *)cpy_r_balances)->ob_type;
    cpy_r_r88 = *(PyObject * *)cpy_r_r87;
    cpy_r_r89 = cpy_r_r88 == cpy_r_r86;
    if (!cpy_r_r89) goto CPyL60;
    if (likely(Py_TYPE(cpy_r_balances) == CPyType_WalletBalancesRaw))
        cpy_r_r90 = cpy_r_balances;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__init__", 1342, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_balances);
        goto CPyL95;
    }
    cpy_r_r91 = ((eth_portfolio___typing___WalletBalancesRawObject *)cpy_r_r90)->_block;
    CPy_INCREF(cpy_r_r91);
    CPy_DECREF(cpy_r_r90);
    cpy_r_r92 = cpy_r_r91;
    goto CPyL62;
CPyL60: ;
    cpy_r_r93 = cpy_r_balances;
    cpy_r_r94 = CPyStatics[48]; /* 'block' */
    cpy_r_r95 = CPyObject_GetAttr(cpy_r_r93, cpy_r_r94);
    CPy_DECREF(cpy_r_r93);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1342, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r92 = cpy_r_r95;
CPyL62: ;
    cpy_r_r96 = PyObject_Str(cpy_r_r92);
    CPy_DECREF(cpy_r_r92);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1342, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r97 = CPyStatics[10]; /* ')' */
    cpy_r_r98 = CPyStr_Build(5, cpy_r_r80, cpy_r_r84, cpy_r_r85, cpy_r_r96, cpy_r_r97);
    CPy_DECREF(cpy_r_r84);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1342, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r99 = CPyModule_builtins;
    cpy_r_r100 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r101 = CPyObject_GetAttr(cpy_r_r99, cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1341, CPyStatic_globals);
        goto CPyL96;
    }
    PyObject *cpy_r_r102[1] = {cpy_r_r98};
    cpy_r_r103 = (PyObject **)&cpy_r_r102;
    cpy_r_r104 = _PyObject_Vectorcall(cpy_r_r101, cpy_r_r103, 1, 0);
    CPy_DECREF(cpy_r_r101);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1341, CPyStatic_globals);
        goto CPyL96;
    }
    CPy_DECREF(cpy_r_r98);
    CPy_Raise(cpy_r_r104);
    CPy_DECREF(cpy_r_r104);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1341, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_Unreachable();
CPyL68: ;
    cpy_r_r105 = CPyDict_GetItem(cpy_r_self, cpy_r_label);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1344, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r106 = PyNumber_InPlaceAdd(cpy_r_r105, cpy_r_balances);
    CPy_DECREF(cpy_r_r105);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1344, CPyStatic_globals);
        goto CPyL97;
    }
    cpy_r_r107 = CPyDict_SetItem(cpy_r_self, cpy_r_label, cpy_r_r106);
    CPy_DECREF(cpy_r_label);
    CPy_DECREF(cpy_r_r106);
    cpy_r_r108 = cpy_r_r107 >= 0;
    if (unlikely(!cpy_r_r108)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1344, CPyStatic_globals);
        goto CPyL87;
    } else
        goto CPyL32;
CPyL71: ;
    cpy_r_r109 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r109)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1339, CPyStatic_globals);
        goto CPyL73;
    }
    return 1;
CPyL73: ;
    cpy_r_r110 = 2;
    return cpy_r_r110;
CPyL74: ;
    CPy_INCREF(cpy_r_seed);
    goto CPyL2;
CPyL75: ;
    CPy_INCREF(cpy_r_block);
    goto CPyL4;
CPyL76: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_block);
    goto CPyL73;
CPyL77: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    goto CPyL73;
CPyL78: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    goto CPyL73;
CPyL79: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r13);
    goto CPyL73;
CPyL80: ;
    CPy_DecRef(cpy_r_seed);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r13);
    goto CPyL73;
CPyL81: ;
    CPy_DECREF(cpy_r_r17);
    goto CPyL12;
CPyL82: ;
    CPy_DecRef(cpy_r_seed);
    goto CPyL73;
CPyL83: ;
    CPy_DECREF(cpy_r_seed);
    goto CPyL15;
CPyL84: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL73;
CPyL85: ;
    CPy_DecRef(cpy_r_r48);
    goto CPyL73;
CPyL86: ;
    CPy_DECREF(cpy_r_r55);
    goto CPyL71;
CPyL87: ;
    CPy_DecRef(cpy_r_r55);
    goto CPyL73;
CPyL88: ;
    CPy_DECREF(cpy_r_r55);
    CPy_DECREF(cpy_r_r58);
    goto CPyL36;
CPyL89: ;
    CPy_DECREF(cpy_r_r55);
    CPy_DECREF(cpy_r_r58);
    CPy_DECREF(cpy_r_label);
    goto CPyL39;
CPyL90: ;
    CPy_DECREF(cpy_r_r55);
    CPy_DECREF(cpy_r_label);
    CPy_DECREF(cpy_r_balances);
    CPy_DECREF(cpy_r_r63);
    goto CPyL42;
CPyL91: ;
    CPy_DecRef(cpy_r_r55);
    CPy_DecRef(cpy_r_label);
    CPy_DecRef(cpy_r_balances);
    goto CPyL73;
CPyL92: ;
    CPy_DecRef(cpy_r_r55);
    CPy_DecRef(cpy_r_label);
    CPy_DecRef(cpy_r_balances);
    CPy_DecRef(cpy_r_r67);
    goto CPyL73;
CPyL93: ;
    CPy_DECREF(cpy_r_r55);
    CPy_DECREF(cpy_r_label);
    goto CPyL54;
CPyL94: ;
    CPy_DecRef(cpy_r_balances);
    goto CPyL73;
CPyL95: ;
    CPy_DecRef(cpy_r_r84);
    goto CPyL73;
CPyL96: ;
    CPy_DecRef(cpy_r_r98);
    goto CPyL73;
CPyL97: ;
    CPy_DecRef(cpy_r_r55);
    CPy_DecRef(cpy_r_label);
    goto CPyL73;
}

PyObject *CPyPy_PortfolioBalancesByCategory_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"seed", "block", 0};
    PyObject *obj_seed = NULL;
    PyObject *obj_block = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|O$O", "__init__", kwlist, &obj_seed, &obj_block)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_seed;
    if (obj_seed == NULL) {
        arg_seed = NULL;
        goto __LL118;
    }
    if (PyDict_Check(obj_seed))
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL118;
    arg_seed = obj_seed;
    if (arg_seed != NULL) goto __LL118;
    if (obj_seed == Py_None)
        arg_seed = obj_seed;
    else {
        arg_seed = NULL;
    }
    if (arg_seed != NULL) goto __LL118;
    CPy_TypeError("union[dict, object, None]", obj_seed); 
    goto fail;
__LL118: ;
    PyObject *arg_block;
    if (obj_block == NULL) {
        arg_block = NULL;
        goto __LL119;
    }
    if (PyLong_Check(obj_block))
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL119;
    if (obj_block == Py_None)
        arg_block = obj_block;
    else {
        arg_block = NULL;
    }
    if (arg_block != NULL) goto __LL119;
    CPy_TypeError("int or None", obj_block); 
    goto fail;
__LL119: ;
    char retval = CPyDef_PortfolioBalancesByCategory_____init__(arg_self, arg_seed, arg_block);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__init__", 1330, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalancesByCategory___assets(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = CPyStatics[57]; /* 'assets' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "assets", 1354, CPyStatic_globals);
        goto CPyL3;
    }
    if (likely(Py_TYPE(cpy_r_r1) == CPyType_WalletBalancesRaw))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "assets", 1354, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_r1);
        goto CPyL3;
    }
    return cpy_r_r2;
CPyL3: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy_PortfolioBalancesByCategory___assets(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":assets", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalancesByCategory___assets(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "assets", 1347, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalancesByCategory___debt(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = CPyStatics[58]; /* 'debt' */
    cpy_r_r1 = CPyDict_GetItem(cpy_r_self, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "debt", 1364, CPyStatic_globals);
        goto CPyL3;
    }
    if (likely(Py_TYPE(cpy_r_r1) == CPyType_WalletBalancesRaw))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "debt", 1364, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_r1);
        goto CPyL3;
    }
    return cpy_r_r2;
CPyL3: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy_PortfolioBalancesByCategory___debt(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":debt", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalancesByCategory___debt(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "debt", 1357, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalancesByCategory___invert(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyTagged cpy_r_r3;
    int64_t cpy_r_r4;
    CPyTagged cpy_r_r5;
    PyObject *cpy_r_r6;
    tuple_T4CIOO cpy_r_r7;
    CPyTagged cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    int32_t cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    char cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    cpy_r_r0 = NULL;
    cpy_r_r1 = NULL;
    cpy_r_r2 = CPyDef_PortfolioBalances(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1379, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r3 = 0;
    cpy_r_r4 = PyDict_Size(cpy_r_self);
    cpy_r_r5 = cpy_r_r4 << 1;
    cpy_r_r6 = CPyDict_GetItemsIter(cpy_r_self);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1380, CPyStatic_globals);
        goto CPyL29;
    }
CPyL2: ;
    cpy_r_r7 = CPyDict_NextItem(cpy_r_r6, cpy_r_r3);
    cpy_r_r8 = cpy_r_r7.f1;
    cpy_r_r3 = cpy_r_r8;
    cpy_r_r9 = cpy_r_r7.f0;
    if (!cpy_r_r9) goto CPyL30;
    cpy_r_r10 = cpy_r_r7.f2;
    CPy_INCREF(cpy_r_r10);
    cpy_r_r11 = cpy_r_r7.f3;
    CPy_INCREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r7.f2);
    CPy_DECREF(cpy_r_r7.f3);
    if (likely(PyUnicode_Check(cpy_r_r10)))
        cpy_r_r12 = cpy_r_r10;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "invert", 1380, CPyStatic_globals, "str", cpy_r_r10);
        goto CPyL31;
    }
    if (likely(Py_TYPE(cpy_r_r11) == CPyType_WalletBalancesRaw))
        cpy_r_r13 = cpy_r_r11;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "invert", 1380, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_r11);
        goto CPyL32;
    }
    cpy_r_r14 = CPyStatics[29]; /* 'items' */
    PyObject *cpy_r_r15[1] = {cpy_r_r13};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = PyObject_VectorcallMethod(cpy_r_r14, cpy_r_r16, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1381, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_DECREF(cpy_r_r13);
    cpy_r_r18 = PyObject_GetIter(cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1381, CPyStatic_globals);
        goto CPyL34;
    }
CPyL7: ;
    cpy_r_r19 = PyIter_Next(cpy_r_r18);
    if (cpy_r_r19 == NULL) goto CPyL35;
    cpy_r_r20 = PyObject_GetIter(cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1381, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r21 = PyIter_Next(cpy_r_r20);
    if (cpy_r_r21 == NULL) {
        goto CPyL37;
    } else
        goto CPyL12;
CPyL10: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r22 = 0;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1381, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_Unreachable();
CPyL12: ;
    cpy_r_r23 = PyIter_Next(cpy_r_r20);
    if (cpy_r_r23 == NULL) {
        goto CPyL38;
    } else
        goto CPyL15;
CPyL13: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r24 = 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1381, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_Unreachable();
CPyL15: ;
    cpy_r_r25 = PyIter_Next(cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    if (cpy_r_r25 == NULL) {
        goto CPyL18;
    } else
        goto CPyL39;
CPyL16: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r26 = 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1381, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r27 = PyObject_IsTrue(cpy_r_r23);
    cpy_r_r28 = cpy_r_r27 >= 0;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1381, CPyStatic_globals);
        goto CPyL40;
    }
    cpy_r_r29 = cpy_r_r27;
    if (!cpy_r_r29) goto CPyL41;
    cpy_r_r30 = PyObject_GetItem(cpy_r_r2, cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1383, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r31 = PyObject_GetItem(cpy_r_r30, cpy_r_r12);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1383, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r32 = PyNumber_InPlaceAdd(cpy_r_r31, cpy_r_r23);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1383, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r33 = PyObject_SetItem(cpy_r_r30, cpy_r_r12, cpy_r_r32);
    CPy_DECREF(cpy_r_r30);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1383, CPyStatic_globals);
        goto CPyL36;
    } else
        goto CPyL7;
CPyL24: ;
    cpy_r_r35 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1381, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r36 = CPyDict_CheckSize(cpy_r_self, cpy_r_r5);
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1380, CPyStatic_globals);
        goto CPyL45;
    } else
        goto CPyL2;
CPyL26: ;
    cpy_r_r37 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1380, CPyStatic_globals);
        goto CPyL29;
    }
    return cpy_r_r2;
CPyL28: ;
    cpy_r_r38 = NULL;
    return cpy_r_r38;
CPyL29: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL28;
CPyL30: ;
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r7.f2);
    CPy_DECREF(cpy_r_r7.f3);
    goto CPyL26;
CPyL31: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r11);
    goto CPyL28;
CPyL32: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r12);
    goto CPyL28;
CPyL33: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r13);
    goto CPyL28;
CPyL34: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r12);
    goto CPyL28;
CPyL35: ;
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r18);
    goto CPyL24;
CPyL36: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r18);
    goto CPyL28;
CPyL37: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r18);
    CPy_DECREF(cpy_r_r20);
    goto CPyL10;
CPyL38: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r18);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r21);
    goto CPyL13;
CPyL39: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r18);
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r25);
    goto CPyL16;
CPyL40: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r23);
    goto CPyL28;
CPyL41: ;
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r23);
    goto CPyL7;
CPyL42: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r23);
    goto CPyL28;
CPyL43: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r30);
    goto CPyL28;
CPyL44: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r30);
    goto CPyL28;
CPyL45: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    goto CPyL28;
}

PyObject *CPyPy_PortfolioBalancesByCategory___invert(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":invert", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalancesByCategory___invert(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "invert", 1366, CPyStatic_globals);
    return NULL;
}

char CPyDef_PortfolioBalancesByCategory_____bool__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    cpy_r_r0 = CPyDict_ValuesView(cpy_r_self);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1398, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r1 = CPyModule_builtins;
    cpy_r_r2 = CPyStatics[42]; /* 'any' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1398, CPyStatic_globals);
        goto CPyL6;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1398, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r0);
    if (unlikely(!PyBool_Check(cpy_r_r6))) {
        CPy_TypeError("bool", cpy_r_r6); cpy_r_r7 = 2;
    } else
        cpy_r_r7 = cpy_r_r6 == Py_True;
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1398, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r7;
CPyL5: ;
    cpy_r_r8 = 2;
    return cpy_r_r8;
CPyL6: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_PortfolioBalancesByCategory_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__bool__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    char retval = CPyDef_PortfolioBalancesByCategory_____bool__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__bool__", 1386, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalancesByCategory_____repr__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyStatics[88]; /* 'PortfolioBalancesByCategory' */
    cpy_r_r1 = PyDict_Copy(cpy_r_self);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1407, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r2 = PyObject_Str(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1407, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r3 = CPyStr_Build(2, cpy_r_r0, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1407, CPyStatic_globals);
        goto CPyL4;
    }
    return cpy_r_r3;
CPyL4: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
}

PyObject *CPyPy_PortfolioBalancesByCategory_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__repr__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalancesByCategory_____repr__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__repr__", 1400, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalancesByCategory_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
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
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    CPyTagged cpy_r_r58;
    int64_t cpy_r_r59;
    CPyTagged cpy_r_r60;
    PyObject *cpy_r_r61;
    tuple_T4CIOO cpy_r_r62;
    CPyTagged cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_protocol;
    PyObject *cpy_r_balances;
    char cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    int32_t cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    char cpy_r_r75;
    CPyTagged cpy_r_r76;
    int64_t cpy_r_r77;
    CPyTagged cpy_r_r78;
    PyObject *cpy_r_r79;
    tuple_T4CIOO cpy_r_r80;
    CPyTagged cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    char cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    int32_t cpy_r_r90;
    char cpy_r_r91;
    char cpy_r_r92;
    char cpy_r_r93;
    PyObject *cpy_r_r94;
    cpy_r_r0 = (PyObject *)CPyType_PortfolioBalancesByCategory;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1430, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r11 = CPyStatics[89]; /* ' is not a PortfolioBalancesByCategory object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1430, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1430, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1430, CPyStatic_globals);
        goto CPyL55;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1430, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1430, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = CPyStatics[48]; /* 'block' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_self, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1431, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r24))
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL120;
    if (cpy_r_r24 == Py_None)
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL120;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1431, CPyStatic_globals, "int or None", cpy_r_r24);
    goto CPyL53;
__LL120: ;
    cpy_r_r26 = CPyStatics[48]; /* 'block' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_other, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1431, CPyStatic_globals);
        goto CPyL56;
    }
    if (PyLong_Check(cpy_r_r27))
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL121;
    if (cpy_r_r27 == Py_None)
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL121;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1431, CPyStatic_globals, "int or None", cpy_r_r27);
    goto CPyL56;
__LL121: ;
    cpy_r_r29 = PyObject_RichCompare(cpy_r_r25, cpy_r_r28, 3);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1431, CPyStatic_globals);
        goto CPyL53;
    }
    if (unlikely(!PyBool_Check(cpy_r_r29))) {
        CPy_TypeError("bool", cpy_r_r29); cpy_r_r30 = 2;
    } else
        cpy_r_r30 = cpy_r_r29 == Py_True;
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1431, CPyStatic_globals);
        goto CPyL53;
    }
    if (!cpy_r_r30) goto CPyL26;
    cpy_r_r31 = CPyStatics[90]; /* ('These PortfolioBalancesByCategory objects are not from '
                                   'the same block (') */
    cpy_r_r32 = CPyStatics[48]; /* 'block' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_self, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1433, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r33))
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL122;
    if (cpy_r_r33 == Py_None)
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL122;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1433, CPyStatic_globals, "int or None", cpy_r_r33);
    goto CPyL53;
__LL122: ;
    cpy_r_r35 = PyObject_Str(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1433, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r36 = CPyStatics[9]; /* ' and ' */
    cpy_r_r37 = CPyStatics[48]; /* 'block' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_other, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1433, CPyStatic_globals);
        goto CPyL57;
    }
    if (PyLong_Check(cpy_r_r38))
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL123;
    if (cpy_r_r38 == Py_None)
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL123;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1433, CPyStatic_globals, "int or None", cpy_r_r38);
    goto CPyL57;
__LL123: ;
    cpy_r_r40 = PyObject_Str(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1433, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r41 = CPyStatics[10]; /* ')' */
    cpy_r_r42 = CPyStr_Build(5, cpy_r_r31, cpy_r_r35, cpy_r_r36, cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1433, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r43 = CPyModule_builtins;
    cpy_r_r44 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1432, CPyStatic_globals);
        goto CPyL58;
    }
    PyObject *cpy_r_r46[1] = {cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1432, CPyStatic_globals);
        goto CPyL58;
    }
    CPy_DECREF(cpy_r_r42);
    CPy_Raise(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1432, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_r49 = CPyStatics[48]; /* 'block' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_self, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1436, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r50))
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL124;
    if (cpy_r_r50 == Py_None)
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL124;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1436, CPyStatic_globals, "int or None", cpy_r_r50);
    goto CPyL53;
__LL124: ;
    cpy_r_r52 = (PyObject *)CPyType_PortfolioBalancesByCategory;
    PyObject *cpy_r_r53[1] = {cpy_r_r51};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = CPyStatics[144]; /* ('block',) */
    cpy_r_r56 = _PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 0, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1436, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_DECREF(cpy_r_r51);
    if (likely(PyDict_Check(cpy_r_r56)))
        cpy_r_r57 = cpy_r_r56;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1436, CPyStatic_globals, "dict", cpy_r_r56);
        goto CPyL53;
    }
    cpy_r_r58 = 0;
    cpy_r_r59 = PyDict_Size(cpy_r_self);
    cpy_r_r60 = cpy_r_r59 << 1;
    cpy_r_r61 = CPyDict_GetItemsIter(cpy_r_self);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1437, CPyStatic_globals);
        goto CPyL60;
    }
CPyL31: ;
    cpy_r_r62 = CPyDict_NextItem(cpy_r_r61, cpy_r_r58);
    cpy_r_r63 = cpy_r_r62.f1;
    cpy_r_r58 = cpy_r_r63;
    cpy_r_r64 = cpy_r_r62.f0;
    if (!cpy_r_r64) goto CPyL61;
    cpy_r_r65 = cpy_r_r62.f2;
    CPy_INCREF(cpy_r_r65);
    cpy_r_r66 = cpy_r_r62.f3;
    CPy_INCREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    if (likely(PyUnicode_Check(cpy_r_r65)))
        cpy_r_r67 = cpy_r_r65;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1437, CPyStatic_globals, "str", cpy_r_r65);
        goto CPyL62;
    }
    if (likely(Py_TYPE(cpy_r_r66) == CPyType_WalletBalancesRaw))
        cpy_r_r68 = cpy_r_r66;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1437, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_r66);
        goto CPyL63;
    }
    cpy_r_protocol = cpy_r_r67;
    cpy_r_balances = cpy_r_r68;
    cpy_r_r69 = CPyDef_WalletBalancesRaw_____bool__(cpy_r_balances);
    if (unlikely(cpy_r_r69 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1437, CPyStatic_globals);
        goto CPyL64;
    }
    if (!cpy_r_r69) goto CPyL65;
    cpy_r_r70 = CPyDict_GetItem(cpy_r_r57, cpy_r_protocol);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1439, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r71 = PyNumber_InPlaceAdd(cpy_r_r70, cpy_r_balances);
    CPy_DECREF(cpy_r_r70);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1439, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r72 = CPyDict_SetItem(cpy_r_r57, cpy_r_protocol, cpy_r_r71);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_r71);
    cpy_r_r73 = cpy_r_r72 >= 0;
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1439, CPyStatic_globals);
        goto CPyL67;
    }
CPyL39: ;
    cpy_r_r74 = CPyDict_CheckSize(cpy_r_self, cpy_r_r60);
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1437, CPyStatic_globals);
        goto CPyL67;
    } else
        goto CPyL31;
CPyL40: ;
    cpy_r_r75 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1437, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r76 = 0;
    cpy_r_r77 = PyDict_Size(cpy_r_other);
    cpy_r_r78 = cpy_r_r77 << 1;
    cpy_r_r79 = CPyDict_GetItemsIter(cpy_r_other);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1440, CPyStatic_globals);
        goto CPyL60;
    }
CPyL42: ;
    cpy_r_r80 = CPyDict_NextItem(cpy_r_r79, cpy_r_r76);
    cpy_r_r81 = cpy_r_r80.f1;
    cpy_r_r76 = cpy_r_r81;
    cpy_r_r82 = cpy_r_r80.f0;
    if (!cpy_r_r82) goto CPyL68;
    cpy_r_r83 = cpy_r_r80.f2;
    CPy_INCREF(cpy_r_r83);
    cpy_r_r84 = cpy_r_r80.f3;
    CPy_INCREF(cpy_r_r84);
    CPy_DECREF(cpy_r_r80.f2);
    CPy_DECREF(cpy_r_r80.f3);
    if (likely(PyUnicode_Check(cpy_r_r83)))
        cpy_r_r85 = cpy_r_r83;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1440, CPyStatic_globals, "str", cpy_r_r83);
        goto CPyL69;
    }
    if (likely(Py_TYPE(cpy_r_r84) == CPyType_WalletBalancesRaw))
        cpy_r_r86 = cpy_r_r84;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__add__", 1440, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_r84);
        goto CPyL70;
    }
    cpy_r_protocol = cpy_r_r85;
    cpy_r_balances = cpy_r_r86;
    cpy_r_r87 = CPyDef_WalletBalancesRaw_____bool__(cpy_r_balances);
    if (unlikely(cpy_r_r87 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1437, CPyStatic_globals);
        goto CPyL71;
    }
    if (!cpy_r_r87) goto CPyL72;
    cpy_r_r88 = CPyDict_GetItem(cpy_r_r57, cpy_r_protocol);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1442, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r89 = PyNumber_InPlaceAdd(cpy_r_r88, cpy_r_balances);
    CPy_DECREF(cpy_r_r88);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1442, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r90 = CPyDict_SetItem(cpy_r_r57, cpy_r_protocol, cpy_r_r89);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_r89);
    cpy_r_r91 = cpy_r_r90 >= 0;
    if (unlikely(!cpy_r_r91)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1442, CPyStatic_globals);
        goto CPyL74;
    }
CPyL50: ;
    cpy_r_r92 = CPyDict_CheckSize(cpy_r_other, cpy_r_r78);
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1440, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL42;
CPyL51: ;
    cpy_r_r93 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1440, CPyStatic_globals);
        goto CPyL60;
    }
    return cpy_r_r57;
CPyL53: ;
    cpy_r_r94 = NULL;
    return cpy_r_r94;
CPyL54: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL53;
CPyL55: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL53;
CPyL56: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL53;
CPyL57: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL53;
CPyL58: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL53;
CPyL59: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL53;
CPyL60: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL53;
CPyL61: ;
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    goto CPyL40;
CPyL62: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r66);
    goto CPyL53;
CPyL63: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r67);
    goto CPyL53;
CPyL64: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_balances);
    goto CPyL53;
CPyL65: ;
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_balances);
    goto CPyL39;
CPyL66: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_protocol);
    goto CPyL53;
CPyL67: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    goto CPyL53;
CPyL68: ;
    CPy_DECREF(cpy_r_r79);
    CPy_DECREF(cpy_r_r80.f2);
    CPy_DECREF(cpy_r_r80.f3);
    goto CPyL51;
CPyL69: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r84);
    goto CPyL53;
CPyL70: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r79);
    CPy_DecRef(cpy_r_r85);
    goto CPyL53;
CPyL71: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_balances);
    CPy_DecRef(cpy_r_r79);
    goto CPyL53;
CPyL72: ;
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_balances);
    goto CPyL50;
CPyL73: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_r79);
    goto CPyL53;
CPyL74: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r79);
    goto CPyL53;
}

PyObject *CPyPy_PortfolioBalancesByCategory_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyDict_Check(obj_other)))
        arg_other = obj_other;
    else {
        CPy_TypeError("dict", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalancesByCategory_____add__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add__", 1409, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalancesByCategory_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    CPy_INCREF(cpy_r_self);
    if (likely(PyDict_Check(cpy_r_self)))
        cpy_r_r0 = cpy_r_self;
    else {
        CPy_TypeError("dict", cpy_r_self); 
        cpy_r_r0 = NULL;
    }
    if (cpy_r_r0 == NULL) goto CPyL5;
    CPy_INCREF(cpy_r_other);
    if (likely(PyDict_Check(cpy_r_other)))
        cpy_r_r1 = cpy_r_other;
    else {
        CPy_TypeError("dict", cpy_r_other); 
        cpy_r_r1 = NULL;
    }
    if (cpy_r_r1 == NULL) goto CPyL6;
    cpy_r_r2 = CPyDef_PortfolioBalancesByCategory_____add__(cpy_r_r0, cpy_r_r1);
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL5;
    if (likely(PyObject_TypeCheck(cpy_r_r2, CPyType__SummableNonNumericMixin)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", cpy_r_r2); 
        cpy_r_r3 = NULL;
    }
    if (cpy_r_r3 == NULL) goto CPyL5;
    return cpy_r_r3;
CPyL5: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
CPyL6: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_PortfolioBalancesByCategory_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__add_____SummableNonNumericMixin_glue", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_PortfolioBalancesByCategory))
        arg_self = obj_self;
    else {
        CPy_TypeError("eth_portfolio.typing.PortfolioBalancesByCategory", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyObject_TypeCheck(obj_other, CPyType__SummableNonNumericMixin)))
        arg_other = obj_other;
    else {
        CPy_TypeError("eth_portfolio.typing._SummableNonNumericMixin", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalancesByCategory_____add___3___SummableNonNumericMixin_glue(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__add_____SummableNonNumericMixin_glue", -1, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_PortfolioBalancesByCategory_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other) {
    PyObject *cpy_r_r0;
    CPyPtr cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
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
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    CPyTagged cpy_r_r58;
    int64_t cpy_r_r59;
    CPyTagged cpy_r_r60;
    PyObject *cpy_r_r61;
    tuple_T4CIOO cpy_r_r62;
    CPyTagged cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_protocol;
    PyObject *cpy_r_balances;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    int32_t cpy_r_r71;
    char cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    CPyTagged cpy_r_r75;
    int64_t cpy_r_r76;
    CPyTagged cpy_r_r77;
    PyObject *cpy_r_r78;
    tuple_T4CIOO cpy_r_r79;
    CPyTagged cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    char cpy_r_r86;
    int32_t cpy_r_r87;
    char cpy_r_r88;
    char cpy_r_r89;
    char cpy_r_r90;
    PyObject *cpy_r_r91;
    cpy_r_r0 = (PyObject *)CPyType_PortfolioBalancesByCategory;
    cpy_r_r1 = (CPyPtr)&((PyObject *)cpy_r_other)->ob_type;
    cpy_r_r2 = *(PyObject * *)cpy_r_r1;
    cpy_r_r3 = cpy_r_r2 == cpy_r_r0;
    if (cpy_r_r3) goto CPyL8;
    cpy_r_r4 = CPyStatics[3]; /* '' */
    cpy_r_r5 = CPyStatics[4]; /* '{:{}}' */
    cpy_r_r6 = CPyStatics[3]; /* '' */
    cpy_r_r7 = CPyStatics[5]; /* 'format' */
    PyObject *cpy_r_r8[3] = {cpy_r_r5, cpy_r_other, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r9, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1466, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r11 = CPyStatics[89]; /* ' is not a PortfolioBalancesByCategory object' */
    cpy_r_r12 = PyList_New(2);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1466, CPyStatic_globals);
        goto CPyL50;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r11;
    cpy_r_r16 = PyUnicode_Join(cpy_r_r4, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1466, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[7]; /* 'TypeError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1466, CPyStatic_globals);
        goto CPyL51;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1466, CPyStatic_globals);
        goto CPyL51;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1466, CPyStatic_globals);
        goto CPyL49;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r23 = CPyStatics[48]; /* 'block' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_self, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1467, CPyStatic_globals);
        goto CPyL49;
    }
    if (PyLong_Check(cpy_r_r24))
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL125;
    if (cpy_r_r24 == Py_None)
        cpy_r_r25 = cpy_r_r24;
    else {
        cpy_r_r25 = NULL;
    }
    if (cpy_r_r25 != NULL) goto __LL125;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1467, CPyStatic_globals, "int or None", cpy_r_r24);
    goto CPyL49;
__LL125: ;
    cpy_r_r26 = CPyStatics[48]; /* 'block' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_other, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1467, CPyStatic_globals);
        goto CPyL52;
    }
    if (PyLong_Check(cpy_r_r27))
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL126;
    if (cpy_r_r27 == Py_None)
        cpy_r_r28 = cpy_r_r27;
    else {
        cpy_r_r28 = NULL;
    }
    if (cpy_r_r28 != NULL) goto __LL126;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1467, CPyStatic_globals, "int or None", cpy_r_r27);
    goto CPyL52;
__LL126: ;
    cpy_r_r29 = PyObject_RichCompare(cpy_r_r25, cpy_r_r28, 3);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1467, CPyStatic_globals);
        goto CPyL49;
    }
    if (unlikely(!PyBool_Check(cpy_r_r29))) {
        CPy_TypeError("bool", cpy_r_r29); cpy_r_r30 = 2;
    } else
        cpy_r_r30 = cpy_r_r29 == Py_True;
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1467, CPyStatic_globals);
        goto CPyL49;
    }
    if (!cpy_r_r30) goto CPyL26;
    cpy_r_r31 = CPyStatics[90]; /* ('These PortfolioBalancesByCategory objects are not from '
                                   'the same block (') */
    cpy_r_r32 = CPyStatics[48]; /* 'block' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_self, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1469, CPyStatic_globals);
        goto CPyL49;
    }
    if (PyLong_Check(cpy_r_r33))
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL127;
    if (cpy_r_r33 == Py_None)
        cpy_r_r34 = cpy_r_r33;
    else {
        cpy_r_r34 = NULL;
    }
    if (cpy_r_r34 != NULL) goto __LL127;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1469, CPyStatic_globals, "int or None", cpy_r_r33);
    goto CPyL49;
__LL127: ;
    cpy_r_r35 = PyObject_Str(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1469, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r36 = CPyStatics[9]; /* ' and ' */
    cpy_r_r37 = CPyStatics[48]; /* 'block' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_other, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1469, CPyStatic_globals);
        goto CPyL53;
    }
    if (PyLong_Check(cpy_r_r38))
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL128;
    if (cpy_r_r38 == Py_None)
        cpy_r_r39 = cpy_r_r38;
    else {
        cpy_r_r39 = NULL;
    }
    if (cpy_r_r39 != NULL) goto __LL128;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1469, CPyStatic_globals, "int or None", cpy_r_r38);
    goto CPyL53;
__LL128: ;
    cpy_r_r40 = PyObject_Str(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1469, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r41 = CPyStatics[10]; /* ')' */
    cpy_r_r42 = CPyStr_Build(5, cpy_r_r31, cpy_r_r35, cpy_r_r36, cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1469, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r43 = CPyModule_builtins;
    cpy_r_r44 = CPyStatics[11]; /* 'ValueError' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1468, CPyStatic_globals);
        goto CPyL54;
    }
    PyObject *cpy_r_r46[1] = {cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1468, CPyStatic_globals);
        goto CPyL54;
    }
    CPy_DECREF(cpy_r_r42);
    CPy_Raise(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(!0)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1468, CPyStatic_globals);
        goto CPyL49;
    }
    CPy_Unreachable();
CPyL26: ;
    cpy_r_r49 = CPyStatics[48]; /* 'block' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_self, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1473, CPyStatic_globals);
        goto CPyL49;
    }
    if (PyLong_Check(cpy_r_r50))
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL129;
    if (cpy_r_r50 == Py_None)
        cpy_r_r51 = cpy_r_r50;
    else {
        cpy_r_r51 = NULL;
    }
    if (cpy_r_r51 != NULL) goto __LL129;
    CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1473, CPyStatic_globals, "int or None", cpy_r_r50);
    goto CPyL49;
__LL129: ;
    cpy_r_r52 = (PyObject *)CPyType_PortfolioBalancesByCategory;
    PyObject *cpy_r_r53[2] = {cpy_r_self, cpy_r_r51};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = CPyStatics[144]; /* ('block',) */
    cpy_r_r56 = _PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 1, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1472, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_DECREF(cpy_r_r51);
    if (likely(PyDict_Check(cpy_r_r56)))
        cpy_r_r57 = cpy_r_r56;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1472, CPyStatic_globals, "dict", cpy_r_r56);
        goto CPyL49;
    }
    cpy_r_r58 = 0;
    cpy_r_r59 = PyDict_Size(cpy_r_other);
    cpy_r_r60 = cpy_r_r59 << 1;
    cpy_r_r61 = CPyDict_GetItemsIter(cpy_r_other);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1475, CPyStatic_globals);
        goto CPyL56;
    }
CPyL31: ;
    cpy_r_r62 = CPyDict_NextItem(cpy_r_r61, cpy_r_r58);
    cpy_r_r63 = cpy_r_r62.f1;
    cpy_r_r58 = cpy_r_r63;
    cpy_r_r64 = cpy_r_r62.f0;
    if (!cpy_r_r64) goto CPyL57;
    cpy_r_r65 = cpy_r_r62.f2;
    CPy_INCREF(cpy_r_r65);
    cpy_r_r66 = cpy_r_r62.f3;
    CPy_INCREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    if (likely(PyUnicode_Check(cpy_r_r65)))
        cpy_r_r67 = cpy_r_r65;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1475, CPyStatic_globals, "str", cpy_r_r65);
        goto CPyL58;
    }
    if (likely(Py_TYPE(cpy_r_r66) == CPyType_WalletBalancesRaw))
        cpy_r_r68 = cpy_r_r66;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1475, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_r66);
        goto CPyL59;
    }
    cpy_r_protocol = cpy_r_r67;
    cpy_r_balances = cpy_r_r68;
    cpy_r_r69 = CPyDict_GetItem(cpy_r_r57, cpy_r_protocol);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1476, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r70 = PyNumber_InPlaceSubtract(cpy_r_r69, cpy_r_balances);
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1476, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r71 = CPyDict_SetItem(cpy_r_r57, cpy_r_protocol, cpy_r_r70);
    CPy_DECREF(cpy_r_protocol);
    CPy_DECREF(cpy_r_r70);
    cpy_r_r72 = cpy_r_r71 >= 0;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1476, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r73 = CPyDict_CheckSize(cpy_r_other, cpy_r_r60);
    if (unlikely(!cpy_r_r73)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1475, CPyStatic_globals);
        goto CPyL62;
    } else
        goto CPyL31;
CPyL38: ;
    cpy_r_r74 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1475, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r75 = 0;
    cpy_r_r76 = PyDict_Size(cpy_r_r57);
    cpy_r_r77 = cpy_r_r76 << 1;
    cpy_r_r78 = CPyDict_GetItemsIter(cpy_r_r57);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1477, CPyStatic_globals);
        goto CPyL56;
    }
CPyL40: ;
    cpy_r_r79 = CPyDict_NextItem(cpy_r_r78, cpy_r_r75);
    cpy_r_r80 = cpy_r_r79.f1;
    cpy_r_r75 = cpy_r_r80;
    cpy_r_r81 = cpy_r_r79.f0;
    if (!cpy_r_r81) goto CPyL63;
    cpy_r_r82 = cpy_r_r79.f2;
    CPy_INCREF(cpy_r_r82);
    cpy_r_r83 = cpy_r_r79.f3;
    CPy_INCREF(cpy_r_r83);
    CPy_DECREF(cpy_r_r79.f2);
    CPy_DECREF(cpy_r_r79.f3);
    if (likely(PyUnicode_Check(cpy_r_r82)))
        cpy_r_r84 = cpy_r_r82;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1477, CPyStatic_globals, "str", cpy_r_r82);
        goto CPyL64;
    }
    if (likely(Py_TYPE(cpy_r_r83) == CPyType_WalletBalancesRaw))
        cpy_r_r85 = cpy_r_r83;
    else {
        CPy_TypeErrorTraceback("eth_portfolio\\typing.py", "__sub__", 1477, CPyStatic_globals, "eth_portfolio.typing.WalletBalancesRaw", cpy_r_r83);
        goto CPyL65;
    }
    cpy_r_protocol = cpy_r_r84;
    cpy_r_balances = cpy_r_r85;
    cpy_r_r86 = CPyDef_WalletBalancesRaw_____bool__(cpy_r_balances);
    CPy_DECREF(cpy_r_balances);
    if (unlikely(cpy_r_r86 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1475, CPyStatic_globals);
        goto CPyL66;
    }
    if (cpy_r_r86) goto CPyL67;
    cpy_r_r87 = PyObject_DelItem(cpy_r_r57, cpy_r_protocol);
    CPy_DECREF(cpy_r_protocol);
    cpy_r_r88 = cpy_r_r87 >= 0;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1479, CPyStatic_globals);
        goto CPyL68;
    }
CPyL46: ;
    cpy_r_r89 = CPyDict_CheckSize(cpy_r_r57, cpy_r_r77);
    if (unlikely(!cpy_r_r89)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1477, CPyStatic_globals);
        goto CPyL68;
    } else
        goto CPyL40;
CPyL47: ;
    cpy_r_r90 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1477, CPyStatic_globals);
        goto CPyL56;
    }
    return cpy_r_r57;
CPyL49: ;
    cpy_r_r91 = NULL;
    return cpy_r_r91;
CPyL50: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL49;
CPyL51: ;
    CPy_DecRef(cpy_r_r16);
    goto CPyL49;
CPyL52: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL49;
CPyL53: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL49;
CPyL54: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL49;
CPyL55: ;
    CPy_DecRef(cpy_r_r51);
    goto CPyL49;
CPyL56: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL49;
CPyL57: ;
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r62.f2);
    CPy_DECREF(cpy_r_r62.f3);
    goto CPyL38;
CPyL58: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r66);
    goto CPyL49;
CPyL59: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r67);
    goto CPyL49;
CPyL60: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_balances);
    goto CPyL49;
CPyL61: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_protocol);
    goto CPyL49;
CPyL62: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r61);
    goto CPyL49;
CPyL63: ;
    CPy_DECREF(cpy_r_r78);
    CPy_DECREF(cpy_r_r79.f2);
    CPy_DECREF(cpy_r_r79.f3);
    goto CPyL47;
CPyL64: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r78);
    CPy_DecRef(cpy_r_r83);
    goto CPyL49;
CPyL65: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r78);
    CPy_DecRef(cpy_r_r84);
    goto CPyL49;
CPyL66: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_protocol);
    CPy_DecRef(cpy_r_r78);
    goto CPyL49;
CPyL67: ;
    CPy_DECREF(cpy_r_protocol);
    goto CPyL46;
CPyL68: ;
    CPy_DecRef(cpy_r_r57);
    CPy_DecRef(cpy_r_r78);
    goto CPyL49;
}

PyObject *CPyPy_PortfolioBalancesByCategory_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"other", 0};
    static CPyArg_Parser parser = {"O:__sub__", kwlist, 0};
    PyObject *obj_other;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_other)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(PyDict_Check(obj_self)))
        arg_self = obj_self;
    else {
        CPy_TypeError("dict", obj_self); 
        goto fail;
    }
    PyObject *arg_other;
    if (likely(PyDict_Check(obj_other)))
        arg_other = obj_other;
    else {
        CPy_TypeError("dict", obj_other); 
        goto fail;
    }
    PyObject *retval = CPyDef_PortfolioBalancesByCategory_____sub__(arg_self, arg_other);
    return retval;
fail: ;
    CPy_AddTraceback("eth_portfolio\\typing.py", "__sub__", 1445, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
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
    PyObject **cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    int32_t cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject **cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    int32_t cpy_r_r57;
    char cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject **cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    int32_t cpy_r_r68;
    char cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    tuple_T2OO cpy_r_r79;
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
    PyObject *cpy_r_r92;
    char cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    int32_t cpy_r_r100;
    char cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    int32_t cpy_r_r104;
    char cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    int32_t cpy_r_r109;
    char cpy_r_r110;
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
    tuple_T2OO cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    int32_t cpy_r_r129;
    char cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject **cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    int32_t cpy_r_r144;
    char cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    char cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    int32_t cpy_r_r153;
    char cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    int32_t cpy_r_r157;
    char cpy_r_r158;
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
    tuple_T2OO cpy_r_r169;
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
    tuple_T2OO cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    tuple_T2OO cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    int32_t cpy_r_r191;
    char cpy_r_r192;
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
    char cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    int32_t cpy_r_r207;
    char cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    int32_t cpy_r_r211;
    char cpy_r_r212;
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
    tuple_T2OO cpy_r_r223;
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
    tuple_T2OO cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    tuple_T2OO cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    int32_t cpy_r_r245;
    char cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    tuple_T2OO cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    int32_t cpy_r_r265;
    char cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    int32_t cpy_r_r269;
    char cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_r272;
    PyObject *cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    tuple_T3OOO cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject *cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    int32_t cpy_r_r282;
    char cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    PyObject *cpy_r_r292;
    PyObject *cpy_r_r293;
    tuple_T2OO cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject *cpy_r_r303;
    PyObject *cpy_r_r304;
    PyObject *cpy_r_r305;
    PyObject *cpy_r_r306;
    tuple_T2OO cpy_r_r307;
    PyObject *cpy_r_r308;
    PyObject *cpy_r_r309;
    PyObject *cpy_r_r310;
    tuple_T2OO cpy_r_r311;
    PyObject *cpy_r_r312;
    PyObject *cpy_r_r313;
    PyObject *cpy_r_r314;
    PyObject *cpy_r_r315;
    int32_t cpy_r_r316;
    char cpy_r_r317;
    PyObject *cpy_r_r318;
    PyObject *cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    PyObject *cpy_r_r322;
    PyObject *cpy_r_r323;
    PyObject *cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    tuple_T2OO cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    tuple_T2OO cpy_r_r332;
    PyObject *cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    PyObject *cpy_r_r339;
    PyObject *cpy_r_r340;
    PyObject *cpy_r_r341;
    PyObject *cpy_r_r342;
    int32_t cpy_r_r343;
    char cpy_r_r344;
    PyObject *cpy_r_r345;
    PyObject *cpy_r_r346;
    int32_t cpy_r_r347;
    char cpy_r_r348;
    PyObject *cpy_r_r349;
    PyObject *cpy_r_r350;
    PyObject *cpy_r_r351;
    PyObject *cpy_r_r352;
    PyObject *cpy_r_r353;
    PyObject *cpy_r_r354;
    PyObject *cpy_r_r355;
    PyObject *cpy_r_r356;
    PyObject *cpy_r_r357;
    PyObject *cpy_r_r358;
    tuple_T2OO cpy_r_r359;
    PyObject *cpy_r_r360;
    PyObject *cpy_r_r361;
    PyObject *cpy_r_r362;
    PyObject *cpy_r_r363;
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    PyObject *cpy_r_r366;
    PyObject *cpy_r_r367;
    PyObject *cpy_r_r368;
    PyObject *cpy_r_r369;
    PyObject *cpy_r_r370;
    PyObject *cpy_r_r371;
    tuple_T2OO cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    PyObject *cpy_r_r375;
    tuple_T2OO cpy_r_r376;
    PyObject *cpy_r_r377;
    PyObject *cpy_r_r378;
    PyObject *cpy_r_r379;
    PyObject *cpy_r_r380;
    int32_t cpy_r_r381;
    char cpy_r_r382;
    PyObject *cpy_r_r383;
    PyObject *cpy_r_r384;
    PyObject *cpy_r_r385;
    PyObject *cpy_r_r386;
    PyObject *cpy_r_r387;
    PyObject *cpy_r_r388;
    PyObject *cpy_r_r389;
    PyObject *cpy_r_r390;
    PyObject *cpy_r_r391;
    PyObject *cpy_r_r392;
    char cpy_r_r393;
    PyObject *cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    int32_t cpy_r_r397;
    char cpy_r_r398;
    PyObject *cpy_r_r399;
    PyObject *cpy_r_r400;
    int32_t cpy_r_r401;
    char cpy_r_r402;
    PyObject *cpy_r_r403;
    PyObject *cpy_r_r404;
    PyObject *cpy_r_r405;
    PyObject *cpy_r_r406;
    PyObject *cpy_r_r407;
    PyObject *cpy_r_r408;
    PyObject *cpy_r_r409;
    PyObject *cpy_r_r410;
    PyObject *cpy_r_r411;
    PyObject *cpy_r_r412;
    tuple_T2OO cpy_r_r413;
    PyObject *cpy_r_r414;
    PyObject *cpy_r_r415;
    PyObject *cpy_r_r416;
    PyObject *cpy_r_r417;
    PyObject *cpy_r_r418;
    PyObject *cpy_r_r419;
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject *cpy_r_r422;
    PyObject *cpy_r_r423;
    PyObject *cpy_r_r424;
    PyObject *cpy_r_r425;
    tuple_T2OO cpy_r_r426;
    PyObject *cpy_r_r427;
    PyObject *cpy_r_r428;
    PyObject *cpy_r_r429;
    tuple_T2OO cpy_r_r430;
    PyObject *cpy_r_r431;
    PyObject *cpy_r_r432;
    PyObject *cpy_r_r433;
    PyObject *cpy_r_r434;
    int32_t cpy_r_r435;
    char cpy_r_r436;
    PyObject *cpy_r_r437;
    PyObject *cpy_r_r438;
    PyObject *cpy_r_r439;
    PyObject *cpy_r_r440;
    PyObject *cpy_r_r441;
    PyObject *cpy_r_r442;
    PyObject *cpy_r_r443;
    PyObject *cpy_r_r444;
    PyObject *cpy_r_r445;
    PyObject *cpy_r_r446;
    char cpy_r_r447;
    PyObject *cpy_r_r448;
    PyObject *cpy_r_r449;
    PyObject *cpy_r_r450;
    int32_t cpy_r_r451;
    char cpy_r_r452;
    PyObject *cpy_r_r453;
    PyObject *cpy_r_r454;
    int32_t cpy_r_r455;
    char cpy_r_r456;
    PyObject *cpy_r_r457;
    PyObject *cpy_r_r458;
    PyObject *cpy_r_r459;
    PyObject *cpy_r_r460;
    PyObject *cpy_r_r461;
    PyObject *cpy_r_r462;
    PyObject *cpy_r_r463;
    PyObject *cpy_r_r464;
    PyObject *cpy_r_r465;
    PyObject *cpy_r_r466;
    tuple_T2OO cpy_r_r467;
    PyObject *cpy_r_r468;
    PyObject *cpy_r_r469;
    PyObject *cpy_r_r470;
    PyObject *cpy_r_r471;
    PyObject *cpy_r_r472;
    PyObject *cpy_r_r473;
    PyObject *cpy_r_r474;
    PyObject *cpy_r_r475;
    PyObject *cpy_r_r476;
    PyObject *cpy_r_r477;
    PyObject *cpy_r_r478;
    PyObject *cpy_r_r479;
    tuple_T2OO cpy_r_r480;
    PyObject *cpy_r_r481;
    PyObject *cpy_r_r482;
    PyObject *cpy_r_r483;
    tuple_T2OO cpy_r_r484;
    PyObject *cpy_r_r485;
    PyObject *cpy_r_r486;
    PyObject *cpy_r_r487;
    PyObject *cpy_r_r488;
    int32_t cpy_r_r489;
    char cpy_r_r490;
    PyObject *cpy_r_r491;
    PyObject *cpy_r_r492;
    PyObject *cpy_r_r493;
    PyObject *cpy_r_r494;
    PyObject *cpy_r_r495;
    PyObject *cpy_r_r496;
    PyObject *cpy_r_r497;
    tuple_T2OO cpy_r_r498;
    PyObject *cpy_r_r499;
    PyObject *cpy_r_r500;
    PyObject *cpy_r_r501;
    PyObject *cpy_r_r502;
    PyObject *cpy_r_r503;
    PyObject *cpy_r_r504;
    PyObject *cpy_r_r505;
    PyObject *cpy_r_r506;
    PyObject *cpy_r_r507;
    PyObject *cpy_r_r508;
    int32_t cpy_r_r509;
    char cpy_r_r510;
    PyObject *cpy_r_r511;
    PyObject *cpy_r_r512;
    int32_t cpy_r_r513;
    char cpy_r_r514;
    char cpy_r_r515;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[91]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", -1, CPyStatic_globals);
        goto CPyL169;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[145]; /* ('cached_property',) */
    cpy_r_r6 = CPyStatics[93]; /* 'functools' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 27, CPyStatic_globals);
        goto CPyL169;
    }
    CPyModule_functools = cpy_r_r8;
    CPy_INCREF(CPyModule_functools);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[146]; /* ('Any', 'Callable', 'DefaultDict', 'Dict', 'Iterable',
                                   'List', 'Literal', 'Optional', 'Tuple', 'TypeVar',
                                   'Union', 'final') */
    cpy_r_r10 = CPyStatics[105]; /* 'typing' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 28, CPyStatic_globals);
        goto CPyL169;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[147]; /* ('DefaultChecksumDict',) */
    cpy_r_r14 = CPyStatics[107]; /* 'checksum_dict' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 43, CPyStatic_globals);
        goto CPyL169;
    }
    CPyModule_checksum_dict = cpy_r_r16;
    CPy_INCREF(CPyModule_checksum_dict);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[148]; /* ('DictStruct',) */
    cpy_r_r18 = CPyStatics[109]; /* 'dictstruct' */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 44, CPyStatic_globals);
        goto CPyL169;
    }
    CPyModule_dictstruct = cpy_r_r20;
    CPy_INCREF(CPyModule_dictstruct);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[149]; /* ('BlockNumber', 'ChecksumAddress') */
    cpy_r_r22 = CPyStatics[112]; /* 'eth_typing' */
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 45, CPyStatic_globals);
        goto CPyL169;
    }
    CPyModule_eth_typing = cpy_r_r24;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r25 = CPyStatics[150]; /* ('DataFrame', 'concat') */
    cpy_r_r26 = CPyStatics[113]; /* 'pandas' */
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyImport_ImportFromMany(cpy_r_r26, cpy_r_r25, cpy_r_r25, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 46, CPyStatic_globals);
        goto CPyL169;
    }
    CPyModule_pandas = cpy_r_r28;
    CPy_INCREF(CPyModule_pandas);
    CPy_DECREF(cpy_r_r28);
    cpy_r_r29 = CPyStatics[151]; /* ('ParamSpec', 'Self') */
    cpy_r_r30 = CPyStatics[116]; /* 'typing_extensions' */
    cpy_r_r31 = CPyStatic_globals;
    cpy_r_r32 = CPyImport_ImportFromMany(cpy_r_r30, cpy_r_r29, cpy_r_r29, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 47, CPyStatic_globals);
        goto CPyL169;
    }
    CPyModule_typing_extensions = cpy_r_r32;
    CPy_INCREF(CPyModule_typing_extensions);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r33 = CPyStatics[152]; /* ('Decimal',) */
    cpy_r_r34 = CPyStatics[117]; /* 'eth_portfolio._decimal' */
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyImport_ImportFromMany(cpy_r_r34, cpy_r_r33, cpy_r_r33, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 49, CPyStatic_globals);
        goto CPyL169;
    }
    CPyModule_eth_portfolio____decimal = cpy_r_r36;
    CPy_INCREF(CPyModule_eth_portfolio____decimal);
    CPy_DECREF(cpy_r_r36);
    cpy_r_r37 = CPyStatics[118]; /* '_T' */
    cpy_r_r38 = CPyStatic_globals;
    cpy_r_r39 = CPyStatics[102]; /* 'TypeVar' */
    cpy_r_r40 = CPyDict_GetItem(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 52, CPyStatic_globals);
        goto CPyL169;
    }
    PyObject *cpy_r_r41[1] = {cpy_r_r37};
    cpy_r_r42 = (PyObject **)&cpy_r_r41;
    cpy_r_r43 = _PyObject_Vectorcall(cpy_r_r40, cpy_r_r42, 1, 0);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 52, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r44 = CPyStatic_globals;
    cpy_r_r45 = CPyStatics[118]; /* '_T' */
    cpy_r_r46 = CPyDict_SetItem(cpy_r_r44, cpy_r_r45, cpy_r_r43);
    CPy_DECREF(cpy_r_r43);
    cpy_r_r47 = cpy_r_r46 >= 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 52, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r48 = CPyStatics[119]; /* '_I' */
    cpy_r_r49 = CPyStatic_globals;
    cpy_r_r50 = CPyStatics[102]; /* 'TypeVar' */
    cpy_r_r51 = CPyDict_GetItem(cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 53, CPyStatic_globals);
        goto CPyL169;
    }
    PyObject *cpy_r_r52[1] = {cpy_r_r48};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = _PyObject_Vectorcall(cpy_r_r51, cpy_r_r53, 1, 0);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 53, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r55 = CPyStatic_globals;
    cpy_r_r56 = CPyStatics[119]; /* '_I' */
    cpy_r_r57 = CPyDict_SetItem(cpy_r_r55, cpy_r_r56, cpy_r_r54);
    CPy_DECREF(cpy_r_r54);
    cpy_r_r58 = cpy_r_r57 >= 0;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 53, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r59 = CPyStatics[120]; /* '_P' */
    cpy_r_r60 = CPyStatic_globals;
    cpy_r_r61 = CPyStatics[114]; /* 'ParamSpec' */
    cpy_r_r62 = CPyDict_GetItem(cpy_r_r60, cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 54, CPyStatic_globals);
        goto CPyL169;
    }
    PyObject *cpy_r_r63[1] = {cpy_r_r59};
    cpy_r_r64 = (PyObject **)&cpy_r_r63;
    cpy_r_r65 = _PyObject_Vectorcall(cpy_r_r62, cpy_r_r64, 1, 0);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 54, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r66 = CPyStatic_globals;
    cpy_r_r67 = CPyStatics[120]; /* '_P' */
    cpy_r_r68 = CPyDict_SetItem(cpy_r_r66, cpy_r_r67, cpy_r_r65);
    CPy_DECREF(cpy_r_r65);
    cpy_r_r69 = cpy_r_r68 >= 0;
    if (unlikely(!cpy_r_r69)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 54, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r70 = CPyStatic_globals;
    cpy_r_r71 = CPyStatics[95]; /* 'Callable' */
    cpy_r_r72 = CPyDict_GetItem(cpy_r_r70, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 56, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r73 = CPyStatic_globals;
    cpy_r_r74 = CPyStatics[120]; /* '_P' */
    cpy_r_r75 = CPyDict_GetItem(cpy_r_r73, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 56, CPyStatic_globals);
        goto CPyL170;
    }
    cpy_r_r76 = CPyStatic_globals;
    cpy_r_r77 = CPyStatics[118]; /* '_T' */
    cpy_r_r78 = CPyDict_GetItem(cpy_r_r76, cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 56, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r79.f0 = cpy_r_r75;
    cpy_r_r79.f1 = cpy_r_r78;
    cpy_r_r80 = PyTuple_New(2);
    if (unlikely(cpy_r_r80 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp130 = cpy_r_r79.f0;
    PyTuple_SET_ITEM(cpy_r_r80, 0, __tmp130);
    PyObject *__tmp131 = cpy_r_r79.f1;
    PyTuple_SET_ITEM(cpy_r_r80, 1, __tmp131);
    cpy_r_r81 = PyObject_GetItem(cpy_r_r72, cpy_r_r80);
    CPy_DECREF(cpy_r_r72);
    CPy_DECREF(cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 56, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r82 = CPyStatic_globals;
    cpy_r_r83 = CPyStatics[121]; /* 'Fn' */
    cpy_r_r84 = CPyDict_SetItem(cpy_r_r82, cpy_r_r83, cpy_r_r81);
    CPy_DECREF(cpy_r_r81);
    cpy_r_r85 = cpy_r_r84 >= 0;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 56, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r86 = CPyStatic_globals;
    cpy_r_r87 = CPyStatics[108]; /* 'DictStruct' */
    cpy_r_r88 = CPyDict_GetItem(cpy_r_r86, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 62, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r89 = PyTuple_Pack(1, cpy_r_r88);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 61, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r90 = CPyStatics[122]; /* 'eth_portfolio.typing' */
    cpy_r_r91 = (PyObject *)CPyType_Balance_template;
    cpy_r_r92 = CPyType_FromTemplate(cpy_r_r91, cpy_r_r89, cpy_r_r90);
    CPy_DECREF(cpy_r_r89);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 61, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r93 = CPyDef_Balance_trait_vtable_setup();
    if (unlikely(cpy_r_r93 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", -1, CPyStatic_globals);
        goto CPyL172;
    }
    cpy_r_r94 = CPyStatics[123]; /* '__mypyc_attrs__' */
    cpy_r_r95 = CPyStatics[30]; /* 'balance' */
    cpy_r_r96 = CPyStatics[31]; /* 'usd_value' */
    cpy_r_r97 = CPyStatics[37]; /* 'token' */
    cpy_r_r98 = CPyStatics[48]; /* 'block' */
    cpy_r_r99 = PyTuple_Pack(4, cpy_r_r95, cpy_r_r96, cpy_r_r97, cpy_r_r98);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 61, CPyStatic_globals);
        goto CPyL172;
    }
    cpy_r_r100 = PyObject_SetAttr(cpy_r_r92, cpy_r_r94, cpy_r_r99);
    CPy_DECREF(cpy_r_r99);
    cpy_r_r101 = cpy_r_r100 >= 0;
    if (unlikely(!cpy_r_r101)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 61, CPyStatic_globals);
        goto CPyL172;
    }
    CPyType_Balance = (PyTypeObject *)cpy_r_r92;
    CPy_INCREF(CPyType_Balance);
    cpy_r_r102 = CPyStatic_globals;
    cpy_r_r103 = CPyStatics[124]; /* 'Balance' */
    cpy_r_r104 = CPyDict_SetItem(cpy_r_r102, cpy_r_r103, cpy_r_r92);
    CPy_DECREF(cpy_r_r92);
    cpy_r_r105 = cpy_r_r104 >= 0;
    if (unlikely(!cpy_r_r105)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 61, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r106 = (PyObject *)&PyUnicode_Type;
    cpy_r_r107 = CPyStatic_globals;
    cpy_r_r108 = CPyStatics[125]; /* 'ProtocolLabel' */
    cpy_r_r109 = CPyDict_SetItem(cpy_r_r107, cpy_r_r108, cpy_r_r106);
    cpy_r_r110 = cpy_r_r109 >= 0;
    if (unlikely(!cpy_r_r110)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 228, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r111 = CPyStatic_globals;
    cpy_r_r112 = CPyStatics[103]; /* 'Union' */
    cpy_r_r113 = CPyDict_GetItem(cpy_r_r111, cpy_r_r112);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 230, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r114 = CPyStatic_globals;
    cpy_r_r115 = CPyStatics[111]; /* 'ChecksumAddress' */
    cpy_r_r116 = CPyDict_GetItem(cpy_r_r114, cpy_r_r115);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 230, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r117 = CPyStatic_globals;
    cpy_r_r118 = CPyStatics[61]; /* 'Iterable' */
    cpy_r_r119 = CPyDict_GetItem(cpy_r_r117, cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 230, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r120 = CPyStatic_globals;
    cpy_r_r121 = CPyStatics[111]; /* 'ChecksumAddress' */
    cpy_r_r122 = CPyDict_GetItem(cpy_r_r120, cpy_r_r121);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 230, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r123 = PyObject_GetItem(cpy_r_r119, cpy_r_r122);
    CPy_DECREF(cpy_r_r119);
    CPy_DECREF(cpy_r_r122);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 230, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r124.f0 = cpy_r_r116;
    cpy_r_r124.f1 = cpy_r_r123;
    cpy_r_r125 = PyTuple_New(2);
    if (unlikely(cpy_r_r125 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp132 = cpy_r_r124.f0;
    PyTuple_SET_ITEM(cpy_r_r125, 0, __tmp132);
    PyObject *__tmp133 = cpy_r_r124.f1;
    PyTuple_SET_ITEM(cpy_r_r125, 1, __tmp133);
    cpy_r_r126 = PyObject_GetItem(cpy_r_r113, cpy_r_r125);
    CPy_DECREF(cpy_r_r113);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 230, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r127 = CPyStatic_globals;
    cpy_r_r128 = CPyStatics[126]; /* 'Addresses' */
    cpy_r_r129 = CPyDict_SetItem(cpy_r_r127, cpy_r_r128, cpy_r_r126);
    CPy_DECREF(cpy_r_r126);
    cpy_r_r130 = cpy_r_r129 >= 0;
    if (unlikely(!cpy_r_r130)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 230, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r131 = CPyStatics[127]; /* 'TokenAddress' */
    cpy_r_r132 = CPyStatic_globals;
    cpy_r_r133 = CPyStatics[111]; /* 'ChecksumAddress' */
    cpy_r_r134 = CPyDict_GetItem(cpy_r_r132, cpy_r_r133);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 231, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r135 = CPyStatic_globals;
    cpy_r_r136 = CPyStatics[102]; /* 'TypeVar' */
    cpy_r_r137 = CPyDict_GetItem(cpy_r_r135, cpy_r_r136);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 231, CPyStatic_globals);
        goto CPyL176;
    }
    PyObject *cpy_r_r138[2] = {cpy_r_r131, cpy_r_r134};
    cpy_r_r139 = (PyObject **)&cpy_r_r138;
    cpy_r_r140 = CPyStatics[153]; /* ('bound',) */
    cpy_r_r141 = _PyObject_Vectorcall(cpy_r_r137, cpy_r_r139, 1, cpy_r_r140);
    CPy_DECREF(cpy_r_r137);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 231, CPyStatic_globals);
        goto CPyL176;
    }
    CPy_DECREF(cpy_r_r134);
    cpy_r_r142 = CPyStatic_globals;
    cpy_r_r143 = CPyStatics[127]; /* 'TokenAddress' */
    cpy_r_r144 = CPyDict_SetItem(cpy_r_r142, cpy_r_r143, cpy_r_r141);
    CPy_DECREF(cpy_r_r141);
    cpy_r_r145 = cpy_r_r144 >= 0;
    if (unlikely(!cpy_r_r145)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 231, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r146 = NULL;
    cpy_r_r147 = CPyStatics[122]; /* 'eth_portfolio.typing' */
    cpy_r_r148 = (PyObject *)CPyType__SummableNonNumericMixin_template;
    cpy_r_r149 = CPyType_FromTemplate(cpy_r_r148, cpy_r_r146, cpy_r_r147);
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 234, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r150 = CPyDef__SummableNonNumericMixin_trait_vtable_setup();
    if (unlikely(cpy_r_r150 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", -1, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r151 = CPyStatics[123]; /* '__mypyc_attrs__' */
    cpy_r_r152 = PyTuple_Pack(0);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 234, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r153 = PyObject_SetAttr(cpy_r_r149, cpy_r_r151, cpy_r_r152);
    CPy_DECREF(cpy_r_r152);
    cpy_r_r154 = cpy_r_r153 >= 0;
    if (unlikely(!cpy_r_r154)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 234, CPyStatic_globals);
        goto CPyL177;
    }
    CPyType__SummableNonNumericMixin = (PyTypeObject *)cpy_r_r149;
    CPy_INCREF(CPyType__SummableNonNumericMixin);
    cpy_r_r155 = CPyStatic_globals;
    cpy_r_r156 = CPyStatics[129]; /* '_SummableNonNumericMixin' */
    cpy_r_r157 = CPyDict_SetItem(cpy_r_r155, cpy_r_r156, cpy_r_r149);
    CPy_DECREF(cpy_r_r149);
    cpy_r_r158 = cpy_r_r157 >= 0;
    if (unlikely(!cpy_r_r158)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 234, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r159 = CPyStatic_globals;
    cpy_r_r160 = CPyStatics[103]; /* 'Union' */
    cpy_r_r161 = CPyDict_GetItem(cpy_r_r159, cpy_r_r160);
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r162 = CPyStatic_globals;
    cpy_r_r163 = CPyStatics[97]; /* 'Dict' */
    cpy_r_r164 = CPyDict_GetItem(cpy_r_r162, cpy_r_r163);
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL178;
    }
    cpy_r_r165 = CPyStatic_globals;
    cpy_r_r166 = CPyStatics[111]; /* 'ChecksumAddress' */
    cpy_r_r167 = CPyDict_GetItem(cpy_r_r165, cpy_r_r166);
    if (unlikely(cpy_r_r167 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL179;
    }
    cpy_r_r168 = (PyObject *)CPyType_Balance;
    CPy_INCREF(cpy_r_r168);
    cpy_r_r169.f0 = cpy_r_r167;
    cpy_r_r169.f1 = cpy_r_r168;
    cpy_r_r170 = PyTuple_New(2);
    if (unlikely(cpy_r_r170 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp134 = cpy_r_r169.f0;
    PyTuple_SET_ITEM(cpy_r_r170, 0, __tmp134);
    PyObject *__tmp135 = cpy_r_r169.f1;
    PyTuple_SET_ITEM(cpy_r_r170, 1, __tmp135);
    cpy_r_r171 = PyObject_GetItem(cpy_r_r164, cpy_r_r170);
    CPy_DECREF(cpy_r_r164);
    CPy_DECREF(cpy_r_r170);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL178;
    }
    cpy_r_r172 = CPyStatic_globals;
    cpy_r_r173 = CPyStatics[61]; /* 'Iterable' */
    cpy_r_r174 = CPyDict_GetItem(cpy_r_r172, cpy_r_r173);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL180;
    }
    cpy_r_r175 = CPyStatic_globals;
    cpy_r_r176 = CPyStatics[101]; /* 'Tuple' */
    cpy_r_r177 = CPyDict_GetItem(cpy_r_r175, cpy_r_r176);
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL181;
    }
    cpy_r_r178 = CPyStatic_globals;
    cpy_r_r179 = CPyStatics[111]; /* 'ChecksumAddress' */
    cpy_r_r180 = CPyDict_GetItem(cpy_r_r178, cpy_r_r179);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL182;
    }
    cpy_r_r181 = (PyObject *)CPyType_Balance;
    CPy_INCREF(cpy_r_r181);
    cpy_r_r182.f0 = cpy_r_r180;
    cpy_r_r182.f1 = cpy_r_r181;
    cpy_r_r183 = PyTuple_New(2);
    if (unlikely(cpy_r_r183 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp136 = cpy_r_r182.f0;
    PyTuple_SET_ITEM(cpy_r_r183, 0, __tmp136);
    PyObject *__tmp137 = cpy_r_r182.f1;
    PyTuple_SET_ITEM(cpy_r_r183, 1, __tmp137);
    cpy_r_r184 = PyObject_GetItem(cpy_r_r177, cpy_r_r183);
    CPy_DECREF(cpy_r_r177);
    CPy_DECREF(cpy_r_r183);
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL181;
    }
    cpy_r_r185 = PyObject_GetItem(cpy_r_r174, cpy_r_r184);
    CPy_DECREF(cpy_r_r174);
    CPy_DECREF(cpy_r_r184);
    if (unlikely(cpy_r_r185 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL180;
    }
    cpy_r_r186.f0 = cpy_r_r171;
    cpy_r_r186.f1 = cpy_r_r185;
    cpy_r_r187 = PyTuple_New(2);
    if (unlikely(cpy_r_r187 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp138 = cpy_r_r186.f0;
    PyTuple_SET_ITEM(cpy_r_r187, 0, __tmp138);
    PyObject *__tmp139 = cpy_r_r186.f1;
    PyTuple_SET_ITEM(cpy_r_r187, 1, __tmp139);
    cpy_r_r188 = PyObject_GetItem(cpy_r_r161, cpy_r_r187);
    CPy_DECREF(cpy_r_r161);
    CPy_DECREF(cpy_r_r187);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r189 = CPyStatic_globals;
    cpy_r_r190 = CPyStatics[130]; /* '_TBSeed' */
    cpy_r_r191 = CPyDict_SetItem(cpy_r_r189, cpy_r_r190, cpy_r_r188);
    CPy_DECREF(cpy_r_r188);
    cpy_r_r192 = cpy_r_r191 >= 0;
    if (unlikely(!cpy_r_r192)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 283, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r193 = CPyStatic_globals;
    cpy_r_r194 = CPyStatics[106]; /* 'DefaultChecksumDict' */
    cpy_r_r195 = CPyDict_GetItem(cpy_r_r193, cpy_r_r194);
    if (unlikely(cpy_r_r195 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 286, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r196 = (PyObject *)CPyType_Balance;
    cpy_r_r197 = PyObject_GetItem(cpy_r_r195, cpy_r_r196);
    CPy_DECREF(cpy_r_r195);
    if (unlikely(cpy_r_r197 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 286, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r198 = (PyObject *)CPyType__SummableNonNumericMixin;
    cpy_r_r199 = PyTuple_Pack(2, cpy_r_r197, cpy_r_r198);
    CPy_DECREF(cpy_r_r197);
    if (unlikely(cpy_r_r199 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 286, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r200 = CPyStatics[122]; /* 'eth_portfolio.typing' */
    cpy_r_r201 = (PyObject *)CPyType_TokenBalances_template;
    cpy_r_r202 = CPyType_FromTemplate(cpy_r_r201, cpy_r_r199, cpy_r_r200);
    CPy_DECREF(cpy_r_r199);
    if (unlikely(cpy_r_r202 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 286, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r203 = CPyDef_TokenBalances_trait_vtable_setup();
    if (unlikely(cpy_r_r203 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", -1, CPyStatic_globals);
        goto CPyL183;
    }
    cpy_r_r204 = CPyStatics[123]; /* '__mypyc_attrs__' */
    cpy_r_r205 = CPyStatics[48]; /* 'block' */
    cpy_r_r206 = PyTuple_Pack(1, cpy_r_r205);
    if (unlikely(cpy_r_r206 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 286, CPyStatic_globals);
        goto CPyL183;
    }
    cpy_r_r207 = PyObject_SetAttr(cpy_r_r202, cpy_r_r204, cpy_r_r206);
    CPy_DECREF(cpy_r_r206);
    cpy_r_r208 = cpy_r_r207 >= 0;
    if (unlikely(!cpy_r_r208)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 286, CPyStatic_globals);
        goto CPyL183;
    }
    CPyType_TokenBalances = (PyTypeObject *)cpy_r_r202;
    CPy_INCREF(CPyType_TokenBalances);
    cpy_r_r209 = CPyStatic_globals;
    cpy_r_r210 = CPyStatics[43]; /* 'TokenBalances' */
    cpy_r_r211 = CPyDict_SetItem(cpy_r_r209, cpy_r_r210, cpy_r_r202);
    CPy_DECREF(cpy_r_r202);
    cpy_r_r212 = cpy_r_r211 >= 0;
    if (unlikely(!cpy_r_r212)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 286, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r213 = CPyStatic_globals;
    cpy_r_r214 = CPyStatics[103]; /* 'Union' */
    cpy_r_r215 = CPyDict_GetItem(cpy_r_r213, cpy_r_r214);
    if (unlikely(cpy_r_r215 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r216 = CPyStatic_globals;
    cpy_r_r217 = CPyStatics[97]; /* 'Dict' */
    cpy_r_r218 = CPyDict_GetItem(cpy_r_r216, cpy_r_r217);
    if (unlikely(cpy_r_r218 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL184;
    }
    cpy_r_r219 = CPyStatic_globals;
    cpy_r_r220 = CPyStatics[125]; /* 'ProtocolLabel' */
    cpy_r_r221 = CPyDict_GetItem(cpy_r_r219, cpy_r_r220);
    if (unlikely(cpy_r_r221 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL185;
    }
    cpy_r_r222 = (PyObject *)CPyType_TokenBalances;
    CPy_INCREF(cpy_r_r222);
    cpy_r_r223.f0 = cpy_r_r221;
    cpy_r_r223.f1 = cpy_r_r222;
    cpy_r_r224 = PyTuple_New(2);
    if (unlikely(cpy_r_r224 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp140 = cpy_r_r223.f0;
    PyTuple_SET_ITEM(cpy_r_r224, 0, __tmp140);
    PyObject *__tmp141 = cpy_r_r223.f1;
    PyTuple_SET_ITEM(cpy_r_r224, 1, __tmp141);
    cpy_r_r225 = PyObject_GetItem(cpy_r_r218, cpy_r_r224);
    CPy_DECREF(cpy_r_r218);
    CPy_DECREF(cpy_r_r224);
    if (unlikely(cpy_r_r225 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL184;
    }
    cpy_r_r226 = CPyStatic_globals;
    cpy_r_r227 = CPyStatics[98]; /* 'List' */
    cpy_r_r228 = CPyDict_GetItem(cpy_r_r226, cpy_r_r227);
    if (unlikely(cpy_r_r228 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r229 = CPyStatic_globals;
    cpy_r_r230 = CPyStatics[101]; /* 'Tuple' */
    cpy_r_r231 = CPyDict_GetItem(cpy_r_r229, cpy_r_r230);
    if (unlikely(cpy_r_r231 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r232 = CPyStatic_globals;
    cpy_r_r233 = CPyStatics[125]; /* 'ProtocolLabel' */
    cpy_r_r234 = CPyDict_GetItem(cpy_r_r232, cpy_r_r233);
    if (unlikely(cpy_r_r234 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r235 = (PyObject *)CPyType_TokenBalances;
    CPy_INCREF(cpy_r_r235);
    cpy_r_r236.f0 = cpy_r_r234;
    cpy_r_r236.f1 = cpy_r_r235;
    cpy_r_r237 = PyTuple_New(2);
    if (unlikely(cpy_r_r237 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp142 = cpy_r_r236.f0;
    PyTuple_SET_ITEM(cpy_r_r237, 0, __tmp142);
    PyObject *__tmp143 = cpy_r_r236.f1;
    PyTuple_SET_ITEM(cpy_r_r237, 1, __tmp143);
    cpy_r_r238 = PyObject_GetItem(cpy_r_r231, cpy_r_r237);
    CPy_DECREF(cpy_r_r231);
    CPy_DECREF(cpy_r_r237);
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r239 = PyObject_GetItem(cpy_r_r228, cpy_r_r238);
    CPy_DECREF(cpy_r_r228);
    CPy_DECREF(cpy_r_r238);
    if (unlikely(cpy_r_r239 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r240.f0 = cpy_r_r225;
    cpy_r_r240.f1 = cpy_r_r239;
    cpy_r_r241 = PyTuple_New(2);
    if (unlikely(cpy_r_r241 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp144 = cpy_r_r240.f0;
    PyTuple_SET_ITEM(cpy_r_r241, 0, __tmp144);
    PyObject *__tmp145 = cpy_r_r240.f1;
    PyTuple_SET_ITEM(cpy_r_r241, 1, __tmp145);
    cpy_r_r242 = PyObject_GetItem(cpy_r_r215, cpy_r_r241);
    CPy_DECREF(cpy_r_r215);
    CPy_DECREF(cpy_r_r241);
    if (unlikely(cpy_r_r242 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r243 = CPyStatic_globals;
    cpy_r_r244 = CPyStatics[131]; /* '_RTBSeed' */
    cpy_r_r245 = CPyDict_SetItem(cpy_r_r243, cpy_r_r244, cpy_r_r242);
    CPy_DECREF(cpy_r_r242);
    cpy_r_r246 = cpy_r_r245 >= 0;
    if (unlikely(!cpy_r_r246)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 486, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r247 = CPyStatic_globals;
    cpy_r_r248 = CPyStatics[96]; /* 'DefaultDict' */
    cpy_r_r249 = CPyDict_GetItem(cpy_r_r247, cpy_r_r248);
    if (unlikely(cpy_r_r249 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 489, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r250 = CPyStatic_globals;
    cpy_r_r251 = CPyStatics[125]; /* 'ProtocolLabel' */
    cpy_r_r252 = CPyDict_GetItem(cpy_r_r250, cpy_r_r251);
    if (unlikely(cpy_r_r252 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 489, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r253 = (PyObject *)CPyType_TokenBalances;
    CPy_INCREF(cpy_r_r253);
    cpy_r_r254.f0 = cpy_r_r252;
    cpy_r_r254.f1 = cpy_r_r253;
    cpy_r_r255 = PyTuple_New(2);
    if (unlikely(cpy_r_r255 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp146 = cpy_r_r254.f0;
    PyTuple_SET_ITEM(cpy_r_r255, 0, __tmp146);
    PyObject *__tmp147 = cpy_r_r254.f1;
    PyTuple_SET_ITEM(cpy_r_r255, 1, __tmp147);
    cpy_r_r256 = PyObject_GetItem(cpy_r_r249, cpy_r_r255);
    CPy_DECREF(cpy_r_r249);
    CPy_DECREF(cpy_r_r255);
    if (unlikely(cpy_r_r256 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 489, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r257 = (PyObject *)CPyType__SummableNonNumericMixin;
    cpy_r_r258 = PyTuple_Pack(2, cpy_r_r256, cpy_r_r257);
    CPy_DECREF(cpy_r_r256);
    if (unlikely(cpy_r_r258 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 489, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r259 = CPyStatics[122]; /* 'eth_portfolio.typing' */
    cpy_r_r260 = (PyObject *)CPyType_RemoteTokenBalances_template;
    cpy_r_r261 = CPyType_FromTemplate(cpy_r_r260, cpy_r_r258, cpy_r_r259);
    CPy_DECREF(cpy_r_r258);
    if (unlikely(cpy_r_r261 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 489, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r262 = CPyStatics[123]; /* '__mypyc_attrs__' */
    cpy_r_r263 = CPyStatics[132]; /* '__dict__' */
    cpy_r_r264 = PyTuple_Pack(1, cpy_r_r263);
    if (unlikely(cpy_r_r264 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 489, CPyStatic_globals);
        goto CPyL190;
    }
    cpy_r_r265 = PyObject_SetAttr(cpy_r_r261, cpy_r_r262, cpy_r_r264);
    CPy_DECREF(cpy_r_r264);
    cpy_r_r266 = cpy_r_r265 >= 0;
    if (unlikely(!cpy_r_r266)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 489, CPyStatic_globals);
        goto CPyL190;
    }
    CPyType_RemoteTokenBalances = (PyTypeObject *)cpy_r_r261;
    CPy_INCREF(CPyType_RemoteTokenBalances);
    cpy_r_r267 = CPyStatic_globals;
    cpy_r_r268 = CPyStatics[54]; /* 'RemoteTokenBalances' */
    cpy_r_r269 = CPyDict_SetItem(cpy_r_r267, cpy_r_r268, cpy_r_r261);
    CPy_DECREF(cpy_r_r261);
    cpy_r_r270 = cpy_r_r269 >= 0;
    if (unlikely(!cpy_r_r270)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 489, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r271 = CPyStatic_globals;
    cpy_r_r272 = CPyStatics[99]; /* 'Literal' */
    cpy_r_r273 = CPyDict_GetItem(cpy_r_r271, cpy_r_r272);
    if (unlikely(cpy_r_r273 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 674, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r274 = CPyStatics[57]; /* 'assets' */
    cpy_r_r275 = CPyStatics[58]; /* 'debt' */
    cpy_r_r276 = CPyStatics[59]; /* 'external' */
    CPy_INCREF(cpy_r_r274);
    CPy_INCREF(cpy_r_r275);
    CPy_INCREF(cpy_r_r276);
    cpy_r_r277.f0 = cpy_r_r274;
    cpy_r_r277.f1 = cpy_r_r275;
    cpy_r_r277.f2 = cpy_r_r276;
    cpy_r_r278 = PyTuple_New(3);
    if (unlikely(cpy_r_r278 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp148 = cpy_r_r277.f0;
    PyTuple_SET_ITEM(cpy_r_r278, 0, __tmp148);
    PyObject *__tmp149 = cpy_r_r277.f1;
    PyTuple_SET_ITEM(cpy_r_r278, 1, __tmp149);
    PyObject *__tmp150 = cpy_r_r277.f2;
    PyTuple_SET_ITEM(cpy_r_r278, 2, __tmp150);
    cpy_r_r279 = PyObject_GetItem(cpy_r_r273, cpy_r_r278);
    CPy_DECREF(cpy_r_r273);
    CPy_DECREF(cpy_r_r278);
    if (unlikely(cpy_r_r279 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 674, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r280 = CPyStatic_globals;
    cpy_r_r281 = CPyStatics[133]; /* 'CategoryLabel' */
    cpy_r_r282 = CPyDict_SetItem(cpy_r_r280, cpy_r_r281, cpy_r_r279);
    CPy_DECREF(cpy_r_r279);
    cpy_r_r283 = cpy_r_r282 >= 0;
    if (unlikely(!cpy_r_r283)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 674, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r284 = CPyStatic_globals;
    cpy_r_r285 = CPyStatics[103]; /* 'Union' */
    cpy_r_r286 = CPyDict_GetItem(cpy_r_r284, cpy_r_r285);
    if (unlikely(cpy_r_r286 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r287 = CPyStatic_globals;
    cpy_r_r288 = CPyStatics[97]; /* 'Dict' */
    cpy_r_r289 = CPyDict_GetItem(cpy_r_r287, cpy_r_r288);
    if (unlikely(cpy_r_r289 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r290 = CPyStatic_globals;
    cpy_r_r291 = CPyStatics[133]; /* 'CategoryLabel' */
    cpy_r_r292 = CPyDict_GetItem(cpy_r_r290, cpy_r_r291);
    if (unlikely(cpy_r_r292 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL192;
    }
    cpy_r_r293 = (PyObject *)CPyType_TokenBalances;
    CPy_INCREF(cpy_r_r293);
    cpy_r_r294.f0 = cpy_r_r292;
    cpy_r_r294.f1 = cpy_r_r293;
    cpy_r_r295 = PyTuple_New(2);
    if (unlikely(cpy_r_r295 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp151 = cpy_r_r294.f0;
    PyTuple_SET_ITEM(cpy_r_r295, 0, __tmp151);
    PyObject *__tmp152 = cpy_r_r294.f1;
    PyTuple_SET_ITEM(cpy_r_r295, 1, __tmp152);
    cpy_r_r296 = PyObject_GetItem(cpy_r_r289, cpy_r_r295);
    CPy_DECREF(cpy_r_r289);
    CPy_DECREF(cpy_r_r295);
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r297 = CPyStatic_globals;
    cpy_r_r298 = CPyStatics[61]; /* 'Iterable' */
    cpy_r_r299 = CPyDict_GetItem(cpy_r_r297, cpy_r_r298);
    if (unlikely(cpy_r_r299 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL193;
    }
    cpy_r_r300 = CPyStatic_globals;
    cpy_r_r301 = CPyStatics[101]; /* 'Tuple' */
    cpy_r_r302 = CPyDict_GetItem(cpy_r_r300, cpy_r_r301);
    if (unlikely(cpy_r_r302 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r303 = CPyStatic_globals;
    cpy_r_r304 = CPyStatics[133]; /* 'CategoryLabel' */
    cpy_r_r305 = CPyDict_GetItem(cpy_r_r303, cpy_r_r304);
    if (unlikely(cpy_r_r305 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL195;
    }
    cpy_r_r306 = (PyObject *)CPyType_TokenBalances;
    CPy_INCREF(cpy_r_r306);
    cpy_r_r307.f0 = cpy_r_r305;
    cpy_r_r307.f1 = cpy_r_r306;
    cpy_r_r308 = PyTuple_New(2);
    if (unlikely(cpy_r_r308 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp153 = cpy_r_r307.f0;
    PyTuple_SET_ITEM(cpy_r_r308, 0, __tmp153);
    PyObject *__tmp154 = cpy_r_r307.f1;
    PyTuple_SET_ITEM(cpy_r_r308, 1, __tmp154);
    cpy_r_r309 = PyObject_GetItem(cpy_r_r302, cpy_r_r308);
    CPy_DECREF(cpy_r_r302);
    CPy_DECREF(cpy_r_r308);
    if (unlikely(cpy_r_r309 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r310 = PyObject_GetItem(cpy_r_r299, cpy_r_r309);
    CPy_DECREF(cpy_r_r299);
    CPy_DECREF(cpy_r_r309);
    if (unlikely(cpy_r_r310 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL193;
    }
    cpy_r_r311.f0 = cpy_r_r296;
    cpy_r_r311.f1 = cpy_r_r310;
    cpy_r_r312 = PyTuple_New(2);
    if (unlikely(cpy_r_r312 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp155 = cpy_r_r311.f0;
    PyTuple_SET_ITEM(cpy_r_r312, 0, __tmp155);
    PyObject *__tmp156 = cpy_r_r311.f1;
    PyTuple_SET_ITEM(cpy_r_r312, 1, __tmp156);
    cpy_r_r313 = PyObject_GetItem(cpy_r_r286, cpy_r_r312);
    CPy_DECREF(cpy_r_r286);
    CPy_DECREF(cpy_r_r312);
    if (unlikely(cpy_r_r313 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r314 = CPyStatic_globals;
    cpy_r_r315 = CPyStatics[134]; /* '_WBSeed' */
    cpy_r_r316 = CPyDict_SetItem(cpy_r_r314, cpy_r_r315, cpy_r_r313);
    CPy_DECREF(cpy_r_r313);
    cpy_r_r317 = cpy_r_r316 >= 0;
    if (unlikely(!cpy_r_r317)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 676, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r318 = CPyStatic_globals;
    cpy_r_r319 = CPyStatics[97]; /* 'Dict' */
    cpy_r_r320 = CPyDict_GetItem(cpy_r_r318, cpy_r_r319);
    if (unlikely(cpy_r_r320 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 680, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r321 = CPyStatic_globals;
    cpy_r_r322 = CPyStatics[133]; /* 'CategoryLabel' */
    cpy_r_r323 = CPyDict_GetItem(cpy_r_r321, cpy_r_r322);
    if (unlikely(cpy_r_r323 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 680, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r324 = CPyStatic_globals;
    cpy_r_r325 = CPyStatics[103]; /* 'Union' */
    cpy_r_r326 = CPyDict_GetItem(cpy_r_r324, cpy_r_r325);
    if (unlikely(cpy_r_r326 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 680, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r327 = (PyObject *)CPyType_TokenBalances;
    cpy_r_r328 = (PyObject *)CPyType_RemoteTokenBalances;
    CPy_INCREF(cpy_r_r327);
    CPy_INCREF(cpy_r_r328);
    cpy_r_r329.f0 = cpy_r_r327;
    cpy_r_r329.f1 = cpy_r_r328;
    cpy_r_r330 = PyTuple_New(2);
    if (unlikely(cpy_r_r330 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp157 = cpy_r_r329.f0;
    PyTuple_SET_ITEM(cpy_r_r330, 0, __tmp157);
    PyObject *__tmp158 = cpy_r_r329.f1;
    PyTuple_SET_ITEM(cpy_r_r330, 1, __tmp158);
    cpy_r_r331 = PyObject_GetItem(cpy_r_r326, cpy_r_r330);
    CPy_DECREF(cpy_r_r326);
    CPy_DECREF(cpy_r_r330);
    if (unlikely(cpy_r_r331 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 680, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r332.f0 = cpy_r_r323;
    cpy_r_r332.f1 = cpy_r_r331;
    cpy_r_r333 = PyTuple_New(2);
    if (unlikely(cpy_r_r333 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp159 = cpy_r_r332.f0;
    PyTuple_SET_ITEM(cpy_r_r333, 0, __tmp159);
    PyObject *__tmp160 = cpy_r_r332.f1;
    PyTuple_SET_ITEM(cpy_r_r333, 1, __tmp160);
    cpy_r_r334 = PyObject_GetItem(cpy_r_r320, cpy_r_r333);
    CPy_DECREF(cpy_r_r320);
    CPy_DECREF(cpy_r_r333);
    if (unlikely(cpy_r_r334 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 680, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r335 = (PyObject *)CPyType__SummableNonNumericMixin;
    cpy_r_r336 = PyTuple_Pack(2, cpy_r_r334, cpy_r_r335);
    CPy_DECREF(cpy_r_r334);
    if (unlikely(cpy_r_r336 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 679, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r337 = CPyStatics[122]; /* 'eth_portfolio.typing' */
    cpy_r_r338 = (PyObject *)CPyType_WalletBalances_template;
    cpy_r_r339 = CPyType_FromTemplate(cpy_r_r338, cpy_r_r336, cpy_r_r337);
    CPy_DECREF(cpy_r_r336);
    if (unlikely(cpy_r_r339 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 679, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r340 = CPyStatics[123]; /* '__mypyc_attrs__' */
    cpy_r_r341 = CPyStatics[132]; /* '__dict__' */
    cpy_r_r342 = PyTuple_Pack(1, cpy_r_r341);
    if (unlikely(cpy_r_r342 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 679, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r343 = PyObject_SetAttr(cpy_r_r339, cpy_r_r340, cpy_r_r342);
    CPy_DECREF(cpy_r_r342);
    cpy_r_r344 = cpy_r_r343 >= 0;
    if (unlikely(!cpy_r_r344)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 679, CPyStatic_globals);
        goto CPyL198;
    }
    CPyType_WalletBalances = (PyTypeObject *)cpy_r_r339;
    CPy_INCREF(CPyType_WalletBalances);
    cpy_r_r345 = CPyStatic_globals;
    cpy_r_r346 = CPyStatics[81]; /* 'WalletBalances' */
    cpy_r_r347 = CPyDict_SetItem(cpy_r_r345, cpy_r_r346, cpy_r_r339);
    CPy_DECREF(cpy_r_r339);
    cpy_r_r348 = cpy_r_r347 >= 0;
    if (unlikely(!cpy_r_r348)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 679, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r349 = CPyStatic_globals;
    cpy_r_r350 = CPyStatics[103]; /* 'Union' */
    cpy_r_r351 = CPyDict_GetItem(cpy_r_r349, cpy_r_r350);
    if (unlikely(cpy_r_r351 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r352 = CPyStatic_globals;
    cpy_r_r353 = CPyStatics[97]; /* 'Dict' */
    cpy_r_r354 = CPyDict_GetItem(cpy_r_r352, cpy_r_r353);
    if (unlikely(cpy_r_r354 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL199;
    }
    cpy_r_r355 = CPyStatic_globals;
    cpy_r_r356 = CPyStatics[111]; /* 'ChecksumAddress' */
    cpy_r_r357 = CPyDict_GetItem(cpy_r_r355, cpy_r_r356);
    if (unlikely(cpy_r_r357 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r358 = (PyObject *)CPyType_WalletBalances;
    CPy_INCREF(cpy_r_r358);
    cpy_r_r359.f0 = cpy_r_r357;
    cpy_r_r359.f1 = cpy_r_r358;
    cpy_r_r360 = PyTuple_New(2);
    if (unlikely(cpy_r_r360 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp161 = cpy_r_r359.f0;
    PyTuple_SET_ITEM(cpy_r_r360, 0, __tmp161);
    PyObject *__tmp162 = cpy_r_r359.f1;
    PyTuple_SET_ITEM(cpy_r_r360, 1, __tmp162);
    cpy_r_r361 = PyObject_GetItem(cpy_r_r354, cpy_r_r360);
    CPy_DECREF(cpy_r_r354);
    CPy_DECREF(cpy_r_r360);
    if (unlikely(cpy_r_r361 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL199;
    }
    cpy_r_r362 = CPyStatic_globals;
    cpy_r_r363 = CPyStatics[98]; /* 'List' */
    cpy_r_r364 = CPyDict_GetItem(cpy_r_r362, cpy_r_r363);
    if (unlikely(cpy_r_r364 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r365 = CPyStatic_globals;
    cpy_r_r366 = CPyStatics[101]; /* 'Tuple' */
    cpy_r_r367 = CPyDict_GetItem(cpy_r_r365, cpy_r_r366);
    if (unlikely(cpy_r_r367 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL202;
    }
    cpy_r_r368 = CPyStatic_globals;
    cpy_r_r369 = CPyStatics[111]; /* 'ChecksumAddress' */
    cpy_r_r370 = CPyDict_GetItem(cpy_r_r368, cpy_r_r369);
    if (unlikely(cpy_r_r370 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL203;
    }
    cpy_r_r371 = (PyObject *)CPyType_WalletBalances;
    CPy_INCREF(cpy_r_r371);
    cpy_r_r372.f0 = cpy_r_r370;
    cpy_r_r372.f1 = cpy_r_r371;
    cpy_r_r373 = PyTuple_New(2);
    if (unlikely(cpy_r_r373 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp163 = cpy_r_r372.f0;
    PyTuple_SET_ITEM(cpy_r_r373, 0, __tmp163);
    PyObject *__tmp164 = cpy_r_r372.f1;
    PyTuple_SET_ITEM(cpy_r_r373, 1, __tmp164);
    cpy_r_r374 = PyObject_GetItem(cpy_r_r367, cpy_r_r373);
    CPy_DECREF(cpy_r_r367);
    CPy_DECREF(cpy_r_r373);
    if (unlikely(cpy_r_r374 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL202;
    }
    cpy_r_r375 = PyObject_GetItem(cpy_r_r364, cpy_r_r374);
    CPy_DECREF(cpy_r_r364);
    CPy_DECREF(cpy_r_r374);
    if (unlikely(cpy_r_r375 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r376.f0 = cpy_r_r361;
    cpy_r_r376.f1 = cpy_r_r375;
    cpy_r_r377 = PyTuple_New(2);
    if (unlikely(cpy_r_r377 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp165 = cpy_r_r376.f0;
    PyTuple_SET_ITEM(cpy_r_r377, 0, __tmp165);
    PyObject *__tmp166 = cpy_r_r376.f1;
    PyTuple_SET_ITEM(cpy_r_r377, 1, __tmp166);
    cpy_r_r378 = PyObject_GetItem(cpy_r_r351, cpy_r_r377);
    CPy_DECREF(cpy_r_r351);
    CPy_DECREF(cpy_r_r377);
    if (unlikely(cpy_r_r378 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r379 = CPyStatic_globals;
    cpy_r_r380 = CPyStatics[135]; /* '_PBSeed' */
    cpy_r_r381 = CPyDict_SetItem(cpy_r_r379, cpy_r_r380, cpy_r_r378);
    CPy_DECREF(cpy_r_r378);
    cpy_r_r382 = cpy_r_r381 >= 0;
    if (unlikely(!cpy_r_r382)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 967, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r383 = CPyStatic_globals;
    cpy_r_r384 = CPyStatics[106]; /* 'DefaultChecksumDict' */
    cpy_r_r385 = CPyDict_GetItem(cpy_r_r383, cpy_r_r384);
    if (unlikely(cpy_r_r385 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 970, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r386 = (PyObject *)CPyType_WalletBalances;
    cpy_r_r387 = PyObject_GetItem(cpy_r_r385, cpy_r_r386);
    CPy_DECREF(cpy_r_r385);
    if (unlikely(cpy_r_r387 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 970, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r388 = (PyObject *)CPyType__SummableNonNumericMixin;
    cpy_r_r389 = PyTuple_Pack(2, cpy_r_r387, cpy_r_r388);
    CPy_DECREF(cpy_r_r387);
    if (unlikely(cpy_r_r389 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 970, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r390 = CPyStatics[122]; /* 'eth_portfolio.typing' */
    cpy_r_r391 = (PyObject *)CPyType_PortfolioBalances_template;
    cpy_r_r392 = CPyType_FromTemplate(cpy_r_r391, cpy_r_r389, cpy_r_r390);
    CPy_DECREF(cpy_r_r389);
    if (unlikely(cpy_r_r392 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 970, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r393 = CPyDef_PortfolioBalances_trait_vtable_setup();
    if (unlikely(cpy_r_r393 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", -1, CPyStatic_globals);
        goto CPyL204;
    }
    cpy_r_r394 = CPyStatics[123]; /* '__mypyc_attrs__' */
    cpy_r_r395 = CPyStatics[48]; /* 'block' */
    cpy_r_r396 = PyTuple_Pack(1, cpy_r_r395);
    if (unlikely(cpy_r_r396 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 970, CPyStatic_globals);
        goto CPyL204;
    }
    cpy_r_r397 = PyObject_SetAttr(cpy_r_r392, cpy_r_r394, cpy_r_r396);
    CPy_DECREF(cpy_r_r396);
    cpy_r_r398 = cpy_r_r397 >= 0;
    if (unlikely(!cpy_r_r398)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 970, CPyStatic_globals);
        goto CPyL204;
    }
    CPyType_PortfolioBalances = (PyTypeObject *)cpy_r_r392;
    CPy_INCREF(CPyType_PortfolioBalances);
    cpy_r_r399 = CPyStatic_globals;
    cpy_r_r400 = CPyStatics[136]; /* 'PortfolioBalances' */
    cpy_r_r401 = CPyDict_SetItem(cpy_r_r399, cpy_r_r400, cpy_r_r392);
    CPy_DECREF(cpy_r_r392);
    cpy_r_r402 = cpy_r_r401 >= 0;
    if (unlikely(!cpy_r_r402)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 970, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r403 = CPyStatic_globals;
    cpy_r_r404 = CPyStatics[103]; /* 'Union' */
    cpy_r_r405 = CPyDict_GetItem(cpy_r_r403, cpy_r_r404);
    if (unlikely(cpy_r_r405 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r406 = CPyStatic_globals;
    cpy_r_r407 = CPyStatics[97]; /* 'Dict' */
    cpy_r_r408 = CPyDict_GetItem(cpy_r_r406, cpy_r_r407);
    if (unlikely(cpy_r_r408 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r409 = CPyStatic_globals;
    cpy_r_r410 = CPyStatics[111]; /* 'ChecksumAddress' */
    cpy_r_r411 = CPyDict_GetItem(cpy_r_r409, cpy_r_r410);
    if (unlikely(cpy_r_r411 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL206;
    }
    cpy_r_r412 = (PyObject *)CPyType_TokenBalances;
    CPy_INCREF(cpy_r_r412);
    cpy_r_r413.f0 = cpy_r_r411;
    cpy_r_r413.f1 = cpy_r_r412;
    cpy_r_r414 = PyTuple_New(2);
    if (unlikely(cpy_r_r414 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp167 = cpy_r_r413.f0;
    PyTuple_SET_ITEM(cpy_r_r414, 0, __tmp167);
    PyObject *__tmp168 = cpy_r_r413.f1;
    PyTuple_SET_ITEM(cpy_r_r414, 1, __tmp168);
    cpy_r_r415 = PyObject_GetItem(cpy_r_r408, cpy_r_r414);
    CPy_DECREF(cpy_r_r408);
    CPy_DECREF(cpy_r_r414);
    if (unlikely(cpy_r_r415 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r416 = CPyStatic_globals;
    cpy_r_r417 = CPyStatics[98]; /* 'List' */
    cpy_r_r418 = CPyDict_GetItem(cpy_r_r416, cpy_r_r417);
    if (unlikely(cpy_r_r418 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL207;
    }
    cpy_r_r419 = CPyStatic_globals;
    cpy_r_r420 = CPyStatics[101]; /* 'Tuple' */
    cpy_r_r421 = CPyDict_GetItem(cpy_r_r419, cpy_r_r420);
    if (unlikely(cpy_r_r421 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL208;
    }
    cpy_r_r422 = CPyStatic_globals;
    cpy_r_r423 = CPyStatics[111]; /* 'ChecksumAddress' */
    cpy_r_r424 = CPyDict_GetItem(cpy_r_r422, cpy_r_r423);
    if (unlikely(cpy_r_r424 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL209;
    }
    cpy_r_r425 = (PyObject *)CPyType_TokenBalances;
    CPy_INCREF(cpy_r_r425);
    cpy_r_r426.f0 = cpy_r_r424;
    cpy_r_r426.f1 = cpy_r_r425;
    cpy_r_r427 = PyTuple_New(2);
    if (unlikely(cpy_r_r427 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp169 = cpy_r_r426.f0;
    PyTuple_SET_ITEM(cpy_r_r427, 0, __tmp169);
    PyObject *__tmp170 = cpy_r_r426.f1;
    PyTuple_SET_ITEM(cpy_r_r427, 1, __tmp170);
    cpy_r_r428 = PyObject_GetItem(cpy_r_r421, cpy_r_r427);
    CPy_DECREF(cpy_r_r421);
    CPy_DECREF(cpy_r_r427);
    if (unlikely(cpy_r_r428 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL208;
    }
    cpy_r_r429 = PyObject_GetItem(cpy_r_r418, cpy_r_r428);
    CPy_DECREF(cpy_r_r418);
    CPy_DECREF(cpy_r_r428);
    if (unlikely(cpy_r_r429 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL207;
    }
    cpy_r_r430.f0 = cpy_r_r415;
    cpy_r_r430.f1 = cpy_r_r429;
    cpy_r_r431 = PyTuple_New(2);
    if (unlikely(cpy_r_r431 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp171 = cpy_r_r430.f0;
    PyTuple_SET_ITEM(cpy_r_r431, 0, __tmp171);
    PyObject *__tmp172 = cpy_r_r430.f1;
    PyTuple_SET_ITEM(cpy_r_r431, 1, __tmp172);
    cpy_r_r432 = PyObject_GetItem(cpy_r_r405, cpy_r_r431);
    CPy_DECREF(cpy_r_r405);
    CPy_DECREF(cpy_r_r431);
    if (unlikely(cpy_r_r432 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r433 = CPyStatic_globals;
    cpy_r_r434 = CPyStatics[137]; /* '_WTBInput' */
    cpy_r_r435 = CPyDict_SetItem(cpy_r_r433, cpy_r_r434, cpy_r_r432);
    CPy_DECREF(cpy_r_r432);
    cpy_r_r436 = cpy_r_r435 >= 0;
    if (unlikely(!cpy_r_r436)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1163, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r437 = CPyStatic_globals;
    cpy_r_r438 = CPyStatics[106]; /* 'DefaultChecksumDict' */
    cpy_r_r439 = CPyDict_GetItem(cpy_r_r437, cpy_r_r438);
    if (unlikely(cpy_r_r439 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1166, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r440 = (PyObject *)CPyType_TokenBalances;
    cpy_r_r441 = PyObject_GetItem(cpy_r_r439, cpy_r_r440);
    CPy_DECREF(cpy_r_r439);
    if (unlikely(cpy_r_r441 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1166, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r442 = (PyObject *)CPyType__SummableNonNumericMixin;
    cpy_r_r443 = PyTuple_Pack(2, cpy_r_r441, cpy_r_r442);
    CPy_DECREF(cpy_r_r441);
    if (unlikely(cpy_r_r443 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1166, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r444 = CPyStatics[122]; /* 'eth_portfolio.typing' */
    cpy_r_r445 = (PyObject *)CPyType_WalletBalancesRaw_template;
    cpy_r_r446 = CPyType_FromTemplate(cpy_r_r445, cpy_r_r443, cpy_r_r444);
    CPy_DECREF(cpy_r_r443);
    if (unlikely(cpy_r_r446 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1166, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r447 = CPyDef_WalletBalancesRaw_trait_vtable_setup();
    if (unlikely(cpy_r_r447 == 2)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", -1, CPyStatic_globals);
        goto CPyL210;
    }
    cpy_r_r448 = CPyStatics[123]; /* '__mypyc_attrs__' */
    cpy_r_r449 = CPyStatics[48]; /* 'block' */
    cpy_r_r450 = PyTuple_Pack(1, cpy_r_r449);
    if (unlikely(cpy_r_r450 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1166, CPyStatic_globals);
        goto CPyL210;
    }
    cpy_r_r451 = PyObject_SetAttr(cpy_r_r446, cpy_r_r448, cpy_r_r450);
    CPy_DECREF(cpy_r_r450);
    cpy_r_r452 = cpy_r_r451 >= 0;
    if (unlikely(!cpy_r_r452)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1166, CPyStatic_globals);
        goto CPyL210;
    }
    CPyType_WalletBalancesRaw = (PyTypeObject *)cpy_r_r446;
    CPy_INCREF(CPyType_WalletBalancesRaw);
    cpy_r_r453 = CPyStatic_globals;
    cpy_r_r454 = CPyStatics[138]; /* 'WalletBalancesRaw' */
    cpy_r_r455 = CPyDict_SetItem(cpy_r_r453, cpy_r_r454, cpy_r_r446);
    CPy_DECREF(cpy_r_r446);
    cpy_r_r456 = cpy_r_r455 >= 0;
    if (unlikely(!cpy_r_r456)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1166, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r457 = CPyStatic_globals;
    cpy_r_r458 = CPyStatics[103]; /* 'Union' */
    cpy_r_r459 = CPyDict_GetItem(cpy_r_r457, cpy_r_r458);
    if (unlikely(cpy_r_r459 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1306, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r460 = CPyStatic_globals;
    cpy_r_r461 = CPyStatics[97]; /* 'Dict' */
    cpy_r_r462 = CPyDict_GetItem(cpy_r_r460, cpy_r_r461);
    if (unlikely(cpy_r_r462 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1307, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r463 = CPyStatic_globals;
    cpy_r_r464 = CPyStatics[133]; /* 'CategoryLabel' */
    cpy_r_r465 = CPyDict_GetItem(cpy_r_r463, cpy_r_r464);
    if (unlikely(cpy_r_r465 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1307, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_r466 = (PyObject *)CPyType_WalletBalancesRaw;
    CPy_INCREF(cpy_r_r466);
    cpy_r_r467.f0 = cpy_r_r465;
    cpy_r_r467.f1 = cpy_r_r466;
    cpy_r_r468 = PyTuple_New(2);
    if (unlikely(cpy_r_r468 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp173 = cpy_r_r467.f0;
    PyTuple_SET_ITEM(cpy_r_r468, 0, __tmp173);
    PyObject *__tmp174 = cpy_r_r467.f1;
    PyTuple_SET_ITEM(cpy_r_r468, 1, __tmp174);
    cpy_r_r469 = PyObject_GetItem(cpy_r_r462, cpy_r_r468);
    CPy_DECREF(cpy_r_r462);
    CPy_DECREF(cpy_r_r468);
    if (unlikely(cpy_r_r469 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1307, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r470 = CPyStatic_globals;
    cpy_r_r471 = CPyStatics[61]; /* 'Iterable' */
    cpy_r_r472 = CPyDict_GetItem(cpy_r_r470, cpy_r_r471);
    if (unlikely(cpy_r_r472 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1307, CPyStatic_globals);
        goto CPyL213;
    }
    cpy_r_r473 = CPyStatic_globals;
    cpy_r_r474 = CPyStatics[101]; /* 'Tuple' */
    cpy_r_r475 = CPyDict_GetItem(cpy_r_r473, cpy_r_r474);
    if (unlikely(cpy_r_r475 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1307, CPyStatic_globals);
        goto CPyL214;
    }
    cpy_r_r476 = CPyStatic_globals;
    cpy_r_r477 = CPyStatics[133]; /* 'CategoryLabel' */
    cpy_r_r478 = CPyDict_GetItem(cpy_r_r476, cpy_r_r477);
    if (unlikely(cpy_r_r478 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1307, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r479 = (PyObject *)CPyType_WalletBalancesRaw;
    CPy_INCREF(cpy_r_r479);
    cpy_r_r480.f0 = cpy_r_r478;
    cpy_r_r480.f1 = cpy_r_r479;
    cpy_r_r481 = PyTuple_New(2);
    if (unlikely(cpy_r_r481 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp175 = cpy_r_r480.f0;
    PyTuple_SET_ITEM(cpy_r_r481, 0, __tmp175);
    PyObject *__tmp176 = cpy_r_r480.f1;
    PyTuple_SET_ITEM(cpy_r_r481, 1, __tmp176);
    cpy_r_r482 = PyObject_GetItem(cpy_r_r475, cpy_r_r481);
    CPy_DECREF(cpy_r_r475);
    CPy_DECREF(cpy_r_r481);
    if (unlikely(cpy_r_r482 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1307, CPyStatic_globals);
        goto CPyL214;
    }
    cpy_r_r483 = PyObject_GetItem(cpy_r_r472, cpy_r_r482);
    CPy_DECREF(cpy_r_r472);
    CPy_DECREF(cpy_r_r482);
    if (unlikely(cpy_r_r483 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1307, CPyStatic_globals);
        goto CPyL213;
    }
    cpy_r_r484.f0 = cpy_r_r469;
    cpy_r_r484.f1 = cpy_r_r483;
    cpy_r_r485 = PyTuple_New(2);
    if (unlikely(cpy_r_r485 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp177 = cpy_r_r484.f0;
    PyTuple_SET_ITEM(cpy_r_r485, 0, __tmp177);
    PyObject *__tmp178 = cpy_r_r484.f1;
    PyTuple_SET_ITEM(cpy_r_r485, 1, __tmp178);
    cpy_r_r486 = PyObject_GetItem(cpy_r_r459, cpy_r_r485);
    CPy_DECREF(cpy_r_r459);
    CPy_DECREF(cpy_r_r485);
    if (unlikely(cpy_r_r486 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1306, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r487 = CPyStatic_globals;
    cpy_r_r488 = CPyStatics[139]; /* '_CBInput' */
    cpy_r_r489 = CPyDict_SetItem(cpy_r_r487, cpy_r_r488, cpy_r_r486);
    CPy_DECREF(cpy_r_r486);
    cpy_r_r490 = cpy_r_r489 >= 0;
    if (unlikely(!cpy_r_r490)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1306, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r491 = CPyStatic_globals;
    cpy_r_r492 = CPyStatics[96]; /* 'DefaultDict' */
    cpy_r_r493 = CPyDict_GetItem(cpy_r_r491, cpy_r_r492);
    if (unlikely(cpy_r_r493 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1312, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r494 = CPyStatic_globals;
    cpy_r_r495 = CPyStatics[133]; /* 'CategoryLabel' */
    cpy_r_r496 = CPyDict_GetItem(cpy_r_r494, cpy_r_r495);
    if (unlikely(cpy_r_r496 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1312, CPyStatic_globals);
        goto CPyL216;
    }
    cpy_r_r497 = (PyObject *)CPyType_WalletBalancesRaw;
    CPy_INCREF(cpy_r_r497);
    cpy_r_r498.f0 = cpy_r_r496;
    cpy_r_r498.f1 = cpy_r_r497;
    cpy_r_r499 = PyTuple_New(2);
    if (unlikely(cpy_r_r499 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp179 = cpy_r_r498.f0;
    PyTuple_SET_ITEM(cpy_r_r499, 0, __tmp179);
    PyObject *__tmp180 = cpy_r_r498.f1;
    PyTuple_SET_ITEM(cpy_r_r499, 1, __tmp180);
    cpy_r_r500 = PyObject_GetItem(cpy_r_r493, cpy_r_r499);
    CPy_DECREF(cpy_r_r493);
    CPy_DECREF(cpy_r_r499);
    if (unlikely(cpy_r_r500 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1312, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r501 = (PyObject *)CPyType__SummableNonNumericMixin;
    cpy_r_r502 = PyTuple_Pack(2, cpy_r_r500, cpy_r_r501);
    CPy_DECREF(cpy_r_r500);
    if (unlikely(cpy_r_r502 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1311, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r503 = CPyStatics[122]; /* 'eth_portfolio.typing' */
    cpy_r_r504 = (PyObject *)CPyType_PortfolioBalancesByCategory_template;
    cpy_r_r505 = CPyType_FromTemplate(cpy_r_r504, cpy_r_r502, cpy_r_r503);
    CPy_DECREF(cpy_r_r502);
    if (unlikely(cpy_r_r505 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1311, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r506 = CPyStatics[123]; /* '__mypyc_attrs__' */
    cpy_r_r507 = CPyStatics[132]; /* '__dict__' */
    cpy_r_r508 = PyTuple_Pack(1, cpy_r_r507);
    if (unlikely(cpy_r_r508 == NULL)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1311, CPyStatic_globals);
        goto CPyL217;
    }
    cpy_r_r509 = PyObject_SetAttr(cpy_r_r505, cpy_r_r506, cpy_r_r508);
    CPy_DECREF(cpy_r_r508);
    cpy_r_r510 = cpy_r_r509 >= 0;
    if (unlikely(!cpy_r_r510)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1311, CPyStatic_globals);
        goto CPyL217;
    }
    CPyType_PortfolioBalancesByCategory = (PyTypeObject *)cpy_r_r505;
    CPy_INCREF(CPyType_PortfolioBalancesByCategory);
    cpy_r_r511 = CPyStatic_globals;
    cpy_r_r512 = CPyStatics[88]; /* 'PortfolioBalancesByCategory' */
    cpy_r_r513 = CPyDict_SetItem(cpy_r_r511, cpy_r_r512, cpy_r_r505);
    CPy_DECREF(cpy_r_r505);
    cpy_r_r514 = cpy_r_r513 >= 0;
    if (unlikely(!cpy_r_r514)) {
        CPy_AddTraceback("eth_portfolio\\typing.py", "<module>", 1311, CPyStatic_globals);
        goto CPyL169;
    }
    return 1;
CPyL169: ;
    cpy_r_r515 = 2;
    return cpy_r_r515;
CPyL170: ;
    CPy_DecRef(cpy_r_r72);
    goto CPyL169;
CPyL171: ;
    CPy_DecRef(cpy_r_r72);
    CPy_DecRef(cpy_r_r75);
    goto CPyL169;
CPyL172: ;
    CPy_DecRef(cpy_r_r92);
    goto CPyL169;
CPyL173: ;
    CPy_DecRef(cpy_r_r113);
    goto CPyL169;
CPyL174: ;
    CPy_DecRef(cpy_r_r113);
    CPy_DecRef(cpy_r_r116);
    goto CPyL169;
CPyL175: ;
    CPy_DecRef(cpy_r_r113);
    CPy_DecRef(cpy_r_r116);
    CPy_DecRef(cpy_r_r119);
    goto CPyL169;
CPyL176: ;
    CPy_DecRef(cpy_r_r134);
    goto CPyL169;
CPyL177: ;
    CPy_DecRef(cpy_r_r149);
    goto CPyL169;
CPyL178: ;
    CPy_DecRef(cpy_r_r161);
    goto CPyL169;
CPyL179: ;
    CPy_DecRef(cpy_r_r161);
    CPy_DecRef(cpy_r_r164);
    goto CPyL169;
CPyL180: ;
    CPy_DecRef(cpy_r_r161);
    CPy_DecRef(cpy_r_r171);
    goto CPyL169;
CPyL181: ;
    CPy_DecRef(cpy_r_r161);
    CPy_DecRef(cpy_r_r171);
    CPy_DecRef(cpy_r_r174);
    goto CPyL169;
CPyL182: ;
    CPy_DecRef(cpy_r_r161);
    CPy_DecRef(cpy_r_r171);
    CPy_DecRef(cpy_r_r174);
    CPy_DecRef(cpy_r_r177);
    goto CPyL169;
CPyL183: ;
    CPy_DecRef(cpy_r_r202);
    goto CPyL169;
CPyL184: ;
    CPy_DecRef(cpy_r_r215);
    goto CPyL169;
CPyL185: ;
    CPy_DecRef(cpy_r_r215);
    CPy_DecRef(cpy_r_r218);
    goto CPyL169;
CPyL186: ;
    CPy_DecRef(cpy_r_r215);
    CPy_DecRef(cpy_r_r225);
    goto CPyL169;
CPyL187: ;
    CPy_DecRef(cpy_r_r215);
    CPy_DecRef(cpy_r_r225);
    CPy_DecRef(cpy_r_r228);
    goto CPyL169;
CPyL188: ;
    CPy_DecRef(cpy_r_r215);
    CPy_DecRef(cpy_r_r225);
    CPy_DecRef(cpy_r_r228);
    CPy_DecRef(cpy_r_r231);
    goto CPyL169;
CPyL189: ;
    CPy_DecRef(cpy_r_r249);
    goto CPyL169;
CPyL190: ;
    CPy_DecRef(cpy_r_r261);
    goto CPyL169;
CPyL191: ;
    CPy_DecRef(cpy_r_r286);
    goto CPyL169;
CPyL192: ;
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r289);
    goto CPyL169;
CPyL193: ;
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r296);
    goto CPyL169;
CPyL194: ;
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r296);
    CPy_DecRef(cpy_r_r299);
    goto CPyL169;
CPyL195: ;
    CPy_DecRef(cpy_r_r286);
    CPy_DecRef(cpy_r_r296);
    CPy_DecRef(cpy_r_r299);
    CPy_DecRef(cpy_r_r302);
    goto CPyL169;
CPyL196: ;
    CPy_DecRef(cpy_r_r320);
    goto CPyL169;
CPyL197: ;
    CPy_DecRef(cpy_r_r320);
    CPy_DecRef(cpy_r_r323);
    goto CPyL169;
CPyL198: ;
    CPy_DecRef(cpy_r_r339);
    goto CPyL169;
CPyL199: ;
    CPy_DecRef(cpy_r_r351);
    goto CPyL169;
CPyL200: ;
    CPy_DecRef(cpy_r_r351);
    CPy_DecRef(cpy_r_r354);
    goto CPyL169;
CPyL201: ;
    CPy_DecRef(cpy_r_r351);
    CPy_DecRef(cpy_r_r361);
    goto CPyL169;
CPyL202: ;
    CPy_DecRef(cpy_r_r351);
    CPy_DecRef(cpy_r_r361);
    CPy_DecRef(cpy_r_r364);
    goto CPyL169;
CPyL203: ;
    CPy_DecRef(cpy_r_r351);
    CPy_DecRef(cpy_r_r361);
    CPy_DecRef(cpy_r_r364);
    CPy_DecRef(cpy_r_r367);
    goto CPyL169;
CPyL204: ;
    CPy_DecRef(cpy_r_r392);
    goto CPyL169;
CPyL205: ;
    CPy_DecRef(cpy_r_r405);
    goto CPyL169;
CPyL206: ;
    CPy_DecRef(cpy_r_r405);
    CPy_DecRef(cpy_r_r408);
    goto CPyL169;
CPyL207: ;
    CPy_DecRef(cpy_r_r405);
    CPy_DecRef(cpy_r_r415);
    goto CPyL169;
CPyL208: ;
    CPy_DecRef(cpy_r_r405);
    CPy_DecRef(cpy_r_r415);
    CPy_DecRef(cpy_r_r418);
    goto CPyL169;
CPyL209: ;
    CPy_DecRef(cpy_r_r405);
    CPy_DecRef(cpy_r_r415);
    CPy_DecRef(cpy_r_r418);
    CPy_DecRef(cpy_r_r421);
    goto CPyL169;
CPyL210: ;
    CPy_DecRef(cpy_r_r446);
    goto CPyL169;
CPyL211: ;
    CPy_DecRef(cpy_r_r459);
    goto CPyL169;
CPyL212: ;
    CPy_DecRef(cpy_r_r459);
    CPy_DecRef(cpy_r_r462);
    goto CPyL169;
CPyL213: ;
    CPy_DecRef(cpy_r_r459);
    CPy_DecRef(cpy_r_r469);
    goto CPyL169;
CPyL214: ;
    CPy_DecRef(cpy_r_r459);
    CPy_DecRef(cpy_r_r469);
    CPy_DecRef(cpy_r_r472);
    goto CPyL169;
CPyL215: ;
    CPy_DecRef(cpy_r_r459);
    CPy_DecRef(cpy_r_r469);
    CPy_DecRef(cpy_r_r472);
    CPy_DecRef(cpy_r_r475);
    goto CPyL169;
CPyL216: ;
    CPy_DecRef(cpy_r_r493);
    goto CPyL169;
CPyL217: ;
    CPy_DecRef(cpy_r_r505);
    goto CPyL169;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_eth_portfolio___typing = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_functools = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_checksum_dict = Py_None;
    CPyModule_dictstruct = Py_None;
    CPyModule_eth_typing = Py_None;
    CPyModule_pandas = Py_None;
    CPyModule_typing_extensions = Py_None;
    CPyModule_eth_portfolio____decimal = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[154];
const char * const CPyLit_Str[] = {
    "\005\000\005{:{}}\006format\032 is not a `Balance` object\tTypeError",
    "\002>These Balance objects represent balances of different tokens (\005 and ",
    "\002\001)\nValueError",
    "\001@These Balance objects represent balances from different blocks (",
    "\005\tException\vCannot add \002: \004args\033 is not a `Balance` object.",
    "\006\020Cannot subtract \t__class__\aDecimal\023NotImplementedError\005super\b__init__",
    "\003\' is not a valid input for TokenBalances\f__contains__\v__getitem__",
    "\003-value must be a `Balance` object. You passed \v__setitem__\005items",
    "\t\abalance\tusd_value\tDataFrame\001T\vreset_index\ainplace\005index\005token\006rename",
    "\006\acolumns\006values\003usd\003any\rTokenBalances\036 is not a TokenBalances object",
    "\0019These TokenBalances objects are not from the same block (",
    "\003\023_setitem_nochecksum\023_getitem_nochecksum\005block",
    "\001+These objects are not from the same block (",
    "\0033value must be a `TokenBalances` object. You passed \bprotocol\006concat",
    "\003\004drop\023RemoteTokenBalances$ is not a RemoteTokenBalances object",
    "\001\?These RemoteTokenBalances objects are not from the same block (",
    "\005\006assets\004debt\bexternal\005_keys\bIterable",
    "\003( is not a valid input for WalletBalances\016__validateitem\tdataframe",
    "\004\bcategory\asum_usd\017WalletBalances \037 is not a WalletBalances object",
    "\001:These WalletBalances objects are not from the same block (",
    "\001\r__validatekey",
    "\0028 is not a valid key for WalletBalances. Valid keys are: \bKeyError",
    "\002\033 is not a valid value for \"\"\". Must be a TokenBalances object.",
    "\002(\". Must be a RemoteTokenBalances object.\004key ",
    "\002\030 is not yet implemented.+ is not a valid input for PortfolioBalances",
    "\0024value must be a `WalletBalances` object. You passed \006wallet",
    "\002\016WalletBalances\" is not a PortfolioBalances object",
    "\001=These PortfolioBalances objects are not from the same block (",
    "\001+ is not a valid input for WalletBalancesRaw",
    "\001\" is not a WalletBalancesRaw object",
    "\001=These WalletBalancesRaw objects are not from the same block (",
    "\0015 is not a valid input for PortfolioBalancesByCategory",
    "\001\033PortfolioBalancesByCategory",
    "\001, is not a PortfolioBalancesByCategory object",
    "\001GThese PortfolioBalancesByCategory objects are not from the same block (",
    "\b\bbuiltins\017cached_property\tfunctools\003Any\bCallable\vDefaultDict\004Dict\004List",
    "\b\aLiteral\bOptional\005Tuple\aTypeVar\005Union\005final\006typing\023DefaultChecksumDict",
    "\005\rchecksum_dict\nDictStruct\ndictstruct\vBlockNumber\017ChecksumAddress",
    "\005\neth_typing\006pandas\tParamSpec\004Self\021typing_extensions",
    "\006\026eth_portfolio._decimal\002_T\002_I\002_P\002Fn\024eth_portfolio.typing",
    "\006\017__mypyc_attrs__\aBalance\rProtocolLabel\tAddresses\fTokenAddress\005bound",
    "\005\030_SummableNonNumericMixin\a_TBSeed\b_RTBSeed\b__dict__\rCategoryLabel",
    "\005\a_WBSeed\a_PBSeed\021PortfolioBalances\t_WTBInput\021WalletBalancesRaw",
    "\001\b_CBInput",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0010",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    13, 1, 35, 2, 39, 35, 1, 53, 1, 48, 1, 92, 12, 94, 95, 96, 97, 61,
    98, 99, 100, 101, 102, 103, 104, 1, 106, 1, 108, 2, 110, 111, 2, 32,
    52, 2, 114, 115, 1, 20, 1, 128
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_eth_portfolio___typing_internal = NULL;
CPyModule *CPyModule_eth_portfolio___typing;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_functools;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_checksum_dict;
CPyModule *CPyModule_dictstruct;
CPyModule *CPyModule_eth_typing;
CPyModule *CPyModule_pandas;
CPyModule *CPyModule_typing_extensions;
CPyModule *CPyModule_eth_portfolio____decimal;
PyTypeObject *CPyType_Balance;
PyObject *CPyDef_Balance(void);
PyTypeObject *CPyType__SummableNonNumericMixin;
PyObject *CPyDef__SummableNonNumericMixin(void);
PyTypeObject *CPyType_TokenBalances;
PyObject *CPyDef_TokenBalances(PyObject *cpy_r_seed, PyObject *cpy_r_block);
PyTypeObject *CPyType_RemoteTokenBalances;
PyTypeObject *CPyType_WalletBalances;
PyTypeObject *CPyType_PortfolioBalances;
PyObject *CPyDef_PortfolioBalances(PyObject *cpy_r_seed, PyObject *cpy_r_block);
PyTypeObject *CPyType_WalletBalancesRaw;
PyObject *CPyDef_WalletBalancesRaw(PyObject *cpy_r_seed, PyObject *cpy_r_block);
PyTypeObject *CPyType_PortfolioBalancesByCategory;
PyTypeObject *CPyType___init___3_RemoteTokenBalances_env;
PyObject *CPyDef___init___3_RemoteTokenBalances_env(void);
PyTypeObject *CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj;
PyObject *CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj(void);
PyTypeObject *CPyType___init___3_PortfolioBalances_env;
PyObject *CPyDef___init___3_PortfolioBalances_env(void);
PyTypeObject *CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj;
PyObject *CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj(void);
PyTypeObject *CPyType___init___3_WalletBalancesRaw_env;
PyObject *CPyDef___init___3_WalletBalancesRaw_env(void);
PyTypeObject *CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj;
PyObject *CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj(void);
PyTypeObject *CPyType___init___3_PortfolioBalancesByCategory_env;
PyObject *CPyDef___init___3_PortfolioBalancesByCategory_env(void);
PyTypeObject *CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj;
PyObject *CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj(void);
PyObject *CPyDef_Balance___usd(PyObject *cpy_r_self);
PyObject *CPyPy_Balance___usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Balance_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_Balance_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Balance_____radd__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_Balance_____radd__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Balance_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_Balance_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Balance_____bool__(PyObject *cpy_r_self);
PyObject *CPyPy_Balance_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Balance_____mypyc_defaults_setup(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy_Balance_____mypyc_defaults_setup(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__SummableNonNumericMixin_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy__SummableNonNumericMixin_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__SummableNonNumericMixin_____radd__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy__SummableNonNumericMixin_____radd__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_TokenBalances_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
PyObject *CPyPy_TokenBalances_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_TokenBalances_____getitem__(PyObject *cpy_r_self, PyObject *cpy_r_key);
PyObject *CPyPy_TokenBalances_____getitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_TokenBalances_____setitem__(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_value);
PyObject *CPyPy_TokenBalances_____setitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_TokenBalances___dataframe(PyObject *cpy_r_self);
PyObject *CPyPy_TokenBalances___dataframe(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_TokenBalances___sum_usd(PyObject *cpy_r_self);
PyObject *CPyPy_TokenBalances___sum_usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_TokenBalances_____bool__(PyObject *cpy_r_self);
PyObject *CPyPy_TokenBalances_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_TokenBalances_____repr__(PyObject *cpy_r_self);
PyObject *CPyPy_TokenBalances_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_TokenBalances_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_TokenBalances_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_TokenBalances_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_TokenBalances_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_TokenBalances_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_TokenBalances_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_RemoteTokenBalances_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
PyObject *CPyPy_RemoteTokenBalances_____init__(PyObject *self, PyObject *args, PyObject *kw);
char CPyDef_RemoteTokenBalances_____setitem__(PyObject *cpy_r_self, PyObject *cpy_r_protocol, PyObject *cpy_r_value);
PyObject *CPyPy_RemoteTokenBalances_____setitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_RemoteTokenBalances___dataframe(PyObject *cpy_r_self);
PyObject *CPyPy_RemoteTokenBalances___dataframe(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_RemoteTokenBalances___sum_usd(PyObject *cpy_r_self);
PyObject *CPyPy_RemoteTokenBalances___sum_usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_RemoteTokenBalances_____bool__(PyObject *cpy_r_self);
PyObject *CPyPy_RemoteTokenBalances_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_RemoteTokenBalances_____repr__(PyObject *cpy_r_self);
PyObject *CPyPy_RemoteTokenBalances_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_RemoteTokenBalances_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_RemoteTokenBalances_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_RemoteTokenBalances_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_RemoteTokenBalances_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_RemoteTokenBalances_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_RemoteTokenBalances_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WalletBalances_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
PyObject *CPyPy_WalletBalances_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_WalletBalances___assets(PyObject *cpy_r_self);
PyObject *CPyPy_WalletBalances___assets(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalances___debt(PyObject *cpy_r_self);
PyObject *CPyPy_WalletBalances___debt(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalances___external(PyObject *cpy_r_self);
PyObject *CPyPy_WalletBalances___external(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalances___dataframe(PyObject *cpy_r_self);
PyObject *CPyPy_WalletBalances___dataframe(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalances___sum_usd(PyObject *cpy_r_self);
PyObject *CPyPy_WalletBalances___sum_usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WalletBalances_____bool__(PyObject *cpy_r_self);
PyObject *CPyPy_WalletBalances_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalances_____repr__(PyObject *cpy_r_self);
PyObject *CPyPy_WalletBalances_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalances_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_WalletBalances_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalances_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_WalletBalances_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalances_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_WalletBalances_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalances_____getitem__(PyObject *cpy_r_self, PyObject *cpy_r_key);
PyObject *CPyPy_WalletBalances_____getitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WalletBalances_____setitem__(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_value);
PyObject *CPyPy_WalletBalances_____setitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WalletBalances_____validatekey(PyObject *cpy_r_self, PyObject *cpy_r_key);
PyObject *CPyPy_WalletBalances_____validatekey(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WalletBalances_____validateitem(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_item);
PyObject *CPyPy_WalletBalances_____validateitem(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_PortfolioBalances_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
PyObject *CPyPy_PortfolioBalances_____init__(PyObject *self, PyObject *args, PyObject *kw);
char CPyDef_PortfolioBalances_____setitem__(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_value);
PyObject *CPyPy_PortfolioBalances_____setitem__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalances___dataframe(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalances___dataframe(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalances___sum_usd(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalances___sum_usd(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalances___inverted(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalances___inverted(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_PortfolioBalances_____bool__(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalances_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalances_____repr__(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalances_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalances_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_PortfolioBalances_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalances_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_PortfolioBalances_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalances_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_PortfolioBalances_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_WalletBalancesRaw_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
PyObject *CPyPy_WalletBalancesRaw_____init__(PyObject *self, PyObject *args, PyObject *kw);
char CPyDef_WalletBalancesRaw_____bool__(PyObject *cpy_r_self);
PyObject *CPyPy_WalletBalancesRaw_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalancesRaw_____repr__(PyObject *cpy_r_self);
PyObject *CPyPy_WalletBalancesRaw_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalancesRaw_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_WalletBalancesRaw_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalancesRaw_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_WalletBalancesRaw_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_WalletBalancesRaw_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_WalletBalancesRaw_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__(PyObject *cpy_r___mypyc_self__);
PyObject *CPyPy___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_PortfolioBalancesByCategory_____init__(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
PyObject *CPyPy_PortfolioBalancesByCategory_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_PortfolioBalancesByCategory___assets(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalancesByCategory___assets(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalancesByCategory___debt(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalancesByCategory___debt(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalancesByCategory___invert(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalancesByCategory___invert(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_PortfolioBalancesByCategory_____bool__(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalancesByCategory_____bool__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalancesByCategory_____repr__(PyObject *cpy_r_self);
PyObject *CPyPy_PortfolioBalancesByCategory_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalancesByCategory_____add__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_PortfolioBalancesByCategory_____add__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalancesByCategory_____add___3___SummableNonNumericMixin_glue(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_PortfolioBalancesByCategory_____add___3___SummableNonNumericMixin_glue(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_PortfolioBalancesByCategory_____sub__(PyObject *cpy_r_self, PyObject *cpy_r_other);
PyObject *CPyPy_PortfolioBalancesByCategory_____sub__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static struct export_table_eth_portfolio___typing exports = {
    &CPyType_Balance,
    &CPyDef_Balance,
    &CPyType__SummableNonNumericMixin,
    &CPyDef__SummableNonNumericMixin,
    &CPyType_TokenBalances,
    &CPyDef_TokenBalances,
    &CPyType_RemoteTokenBalances,
    &CPyType_WalletBalances,
    &CPyType_PortfolioBalances,
    &CPyDef_PortfolioBalances,
    &CPyType_WalletBalancesRaw,
    &CPyDef_WalletBalancesRaw,
    &CPyType_PortfolioBalancesByCategory,
    &CPyType___init___3_RemoteTokenBalances_env,
    &CPyDef___init___3_RemoteTokenBalances_env,
    &CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj,
    &CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj,
    &CPyType___init___3_PortfolioBalances_env,
    &CPyDef___init___3_PortfolioBalances_env,
    &CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj,
    &CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj,
    &CPyType___init___3_WalletBalancesRaw_env,
    &CPyDef___init___3_WalletBalancesRaw_env,
    &CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj,
    &CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj,
    &CPyType___init___3_PortfolioBalancesByCategory_env,
    &CPyDef___init___3_PortfolioBalancesByCategory_env,
    &CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj,
    &CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj,
    &CPyDef_Balance___usd,
    &CPyDef_Balance_____add__,
    &CPyDef_Balance_____radd__,
    &CPyDef_Balance_____sub__,
    &CPyDef_Balance_____bool__,
    &CPyDef_Balance_____mypyc_defaults_setup,
    &CPyDef__SummableNonNumericMixin_____add__,
    &CPyDef__SummableNonNumericMixin_____radd__,
    &CPyDef_TokenBalances_____init__,
    &CPyDef_TokenBalances_____getitem__,
    &CPyDef_TokenBalances_____setitem__,
    &CPyDef_TokenBalances___dataframe,
    &CPyDef_TokenBalances___sum_usd,
    &CPyDef_TokenBalances_____bool__,
    &CPyDef_TokenBalances_____repr__,
    &CPyDef_TokenBalances_____add__,
    &CPyDef_TokenBalances_____add___3___SummableNonNumericMixin_glue,
    &CPyDef_TokenBalances_____sub__,
    &CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__,
    &CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__,
    &CPyDef_RemoteTokenBalances_____init__,
    &CPyDef_RemoteTokenBalances_____setitem__,
    &CPyDef_RemoteTokenBalances___dataframe,
    &CPyDef_RemoteTokenBalances___sum_usd,
    &CPyDef_RemoteTokenBalances_____bool__,
    &CPyDef_RemoteTokenBalances_____repr__,
    &CPyDef_RemoteTokenBalances_____add__,
    &CPyDef_RemoteTokenBalances_____add___3___SummableNonNumericMixin_glue,
    &CPyDef_RemoteTokenBalances_____sub__,
    &CPyDef_WalletBalances_____init__,
    &CPyDef_WalletBalances___assets,
    &CPyDef_WalletBalances___debt,
    &CPyDef_WalletBalances___external,
    &CPyDef_WalletBalances___dataframe,
    &CPyDef_WalletBalances___sum_usd,
    &CPyDef_WalletBalances_____bool__,
    &CPyDef_WalletBalances_____repr__,
    &CPyDef_WalletBalances_____add__,
    &CPyDef_WalletBalances_____add___3___SummableNonNumericMixin_glue,
    &CPyDef_WalletBalances_____sub__,
    &CPyDef_WalletBalances_____getitem__,
    &CPyDef_WalletBalances_____setitem__,
    &CPyDef_WalletBalances_____validatekey,
    &CPyDef_WalletBalances_____validateitem,
    &CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__,
    &CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__,
    &CPyDef_PortfolioBalances_____init__,
    &CPyDef_PortfolioBalances_____setitem__,
    &CPyDef_PortfolioBalances___dataframe,
    &CPyDef_PortfolioBalances___sum_usd,
    &CPyDef_PortfolioBalances___inverted,
    &CPyDef_PortfolioBalances_____bool__,
    &CPyDef_PortfolioBalances_____repr__,
    &CPyDef_PortfolioBalances_____add__,
    &CPyDef_PortfolioBalances_____add___3___SummableNonNumericMixin_glue,
    &CPyDef_PortfolioBalances_____sub__,
    &CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__,
    &CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__,
    &CPyDef_WalletBalancesRaw_____init__,
    &CPyDef_WalletBalancesRaw_____bool__,
    &CPyDef_WalletBalancesRaw_____repr__,
    &CPyDef_WalletBalancesRaw_____add__,
    &CPyDef_WalletBalancesRaw_____add___3___SummableNonNumericMixin_glue,
    &CPyDef_WalletBalancesRaw_____sub__,
    &CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__,
    &CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__,
    &CPyDef_PortfolioBalancesByCategory_____init__,
    &CPyDef_PortfolioBalancesByCategory___assets,
    &CPyDef_PortfolioBalancesByCategory___debt,
    &CPyDef_PortfolioBalancesByCategory___invert,
    &CPyDef_PortfolioBalancesByCategory_____bool__,
    &CPyDef_PortfolioBalancesByCategory_____repr__,
    &CPyDef_PortfolioBalancesByCategory_____add__,
    &CPyDef_PortfolioBalancesByCategory_____add___3___SummableNonNumericMixin_glue,
    &CPyDef_PortfolioBalancesByCategory_____sub__,
    &CPyDef___top_level__,
};

PyMODINIT_FUNC PyInit_typing__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "eth_portfolio.typing__mypyc", NULL, -1, NULL, NULL };
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
    
    capsule = PyCapsule_New(&exports, "eth_portfolio.typing__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_eth_portfolio___typing(void);
    capsule = PyCapsule_New((void *)CPyInit_eth_portfolio___typing, "eth_portfolio.typing__mypyc.init_eth_portfolio___typing", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_eth_portfolio___typing", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
