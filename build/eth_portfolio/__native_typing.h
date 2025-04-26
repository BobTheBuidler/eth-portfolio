#ifndef MYPYC_NATIVE_eth_portfolio___typing_H
#define MYPYC_NATIVE_eth_portfolio___typing_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T4CIOO
#define MYPYC_DECLARED_tuple_T4CIOO
typedef struct tuple_T4CIOO {
    char f0;
    CPyTagged f1;
    PyObject *f2;
    PyObject *f3;
} tuple_T4CIOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3CIO
#define MYPYC_DECLARED_tuple_T3CIO
typedef struct tuple_T3CIO {
    char f0;
    CPyTagged f1;
    PyObject *f2;
} tuple_T3CIO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_balance;
    PyObject *_usd_value;
    PyObject *_token;
    PyObject *_block;
} eth_portfolio___typing___BalanceObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} eth_portfolio___typing____SummableNonNumericMixinObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_block;
} eth_portfolio___typing___TokenBalancesObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} eth_portfolio___typing___RemoteTokenBalancesObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} eth_portfolio___typing___WalletBalancesObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_block;
} eth_portfolio___typing___PortfolioBalancesObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_block;
} eth_portfolio___typing___WalletBalancesRawObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} eth_portfolio___typing___PortfolioBalancesByCategoryObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_block;
    PyObject *_self;
    PyObject *_seed;
} eth_portfolio___typing_____init___3_RemoteTokenBalances_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} eth_portfolio___typing_____mypyc_lambda__0___3_init___3_RemoteTokenBalances_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_block;
    PyObject *_self;
    PyObject *_seed;
} eth_portfolio___typing_____init___3_PortfolioBalances_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} eth_portfolio___typing_____mypyc_lambda__1___3_init___3_PortfolioBalances_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_block;
    PyObject *_self;
    PyObject *_seed;
} eth_portfolio___typing_____init___3_WalletBalancesRaw_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} eth_portfolio___typing_____mypyc_lambda__2___3_init___3_WalletBalancesRaw_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_block;
    PyObject *_self;
    PyObject *_seed;
} eth_portfolio___typing_____init___3_PortfolioBalancesByCategory_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} eth_portfolio___typing_____mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_objObject;


struct export_table_eth_portfolio___typing {
    PyTypeObject **CPyType_Balance;
    PyObject *(*CPyDef_Balance)(void);
    PyTypeObject **CPyType__SummableNonNumericMixin;
    PyObject *(*CPyDef__SummableNonNumericMixin)(void);
    PyTypeObject **CPyType_TokenBalances;
    PyObject *(*CPyDef_TokenBalances)(PyObject *cpy_r_seed, PyObject *cpy_r_block);
    PyTypeObject **CPyType_RemoteTokenBalances;
    PyTypeObject **CPyType_WalletBalances;
    PyTypeObject **CPyType_PortfolioBalances;
    PyObject *(*CPyDef_PortfolioBalances)(PyObject *cpy_r_seed, PyObject *cpy_r_block);
    PyTypeObject **CPyType_WalletBalancesRaw;
    PyObject *(*CPyDef_WalletBalancesRaw)(PyObject *cpy_r_seed, PyObject *cpy_r_block);
    PyTypeObject **CPyType_PortfolioBalancesByCategory;
    PyTypeObject **CPyType___init___3_RemoteTokenBalances_env;
    PyObject *(*CPyDef___init___3_RemoteTokenBalances_env)(void);
    PyTypeObject **CPyType___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj;
    PyObject *(*CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj)(void);
    PyTypeObject **CPyType___init___3_PortfolioBalances_env;
    PyObject *(*CPyDef___init___3_PortfolioBalances_env)(void);
    PyTypeObject **CPyType___mypyc_lambda__1___3_init___3_PortfolioBalances_obj;
    PyObject *(*CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj)(void);
    PyTypeObject **CPyType___init___3_WalletBalancesRaw_env;
    PyObject *(*CPyDef___init___3_WalletBalancesRaw_env)(void);
    PyTypeObject **CPyType___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj;
    PyObject *(*CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj)(void);
    PyTypeObject **CPyType___init___3_PortfolioBalancesByCategory_env;
    PyObject *(*CPyDef___init___3_PortfolioBalancesByCategory_env)(void);
    PyTypeObject **CPyType___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj;
    PyObject *(*CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj)(void);
    PyObject *(*CPyDef_Balance___usd)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_Balance_____add__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_Balance_____radd__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_Balance_____sub__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    char (*CPyDef_Balance_____bool__)(PyObject *cpy_r_self);
    char (*CPyDef_Balance_____mypyc_defaults_setup)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__SummableNonNumericMixin_____add__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef__SummableNonNumericMixin_____radd__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    char (*CPyDef_TokenBalances_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
    PyObject *(*CPyDef_TokenBalances_____getitem__)(PyObject *cpy_r_self, PyObject *cpy_r_key);
    char (*CPyDef_TokenBalances_____setitem__)(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_value);
    PyObject *(*CPyDef_TokenBalances___dataframe)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_TokenBalances___sum_usd)(PyObject *cpy_r_self);
    char (*CPyDef_TokenBalances_____bool__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_TokenBalances_____repr__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_TokenBalances_____add__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_TokenBalances_____add___3___SummableNonNumericMixin_glue)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_TokenBalances_____sub__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__0___3_init___3_RemoteTokenBalances_obj_____call__)(PyObject *cpy_r___mypyc_self__);
    char (*CPyDef_RemoteTokenBalances_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
    char (*CPyDef_RemoteTokenBalances_____setitem__)(PyObject *cpy_r_self, PyObject *cpy_r_protocol, PyObject *cpy_r_value);
    PyObject *(*CPyDef_RemoteTokenBalances___dataframe)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_RemoteTokenBalances___sum_usd)(PyObject *cpy_r_self);
    char (*CPyDef_RemoteTokenBalances_____bool__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_RemoteTokenBalances_____repr__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_RemoteTokenBalances_____add__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_RemoteTokenBalances_____add___3___SummableNonNumericMixin_glue)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_RemoteTokenBalances_____sub__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    char (*CPyDef_WalletBalances_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
    PyObject *(*CPyDef_WalletBalances___assets)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_WalletBalances___debt)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_WalletBalances___external)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_WalletBalances___dataframe)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_WalletBalances___sum_usd)(PyObject *cpy_r_self);
    char (*CPyDef_WalletBalances_____bool__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_WalletBalances_____repr__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_WalletBalances_____add__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_WalletBalances_____add___3___SummableNonNumericMixin_glue)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_WalletBalances_____sub__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_WalletBalances_____getitem__)(PyObject *cpy_r_self, PyObject *cpy_r_key);
    char (*CPyDef_WalletBalances_____setitem__)(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_value);
    char (*CPyDef_WalletBalances_____validatekey)(PyObject *cpy_r_self, PyObject *cpy_r_key);
    char (*CPyDef_WalletBalances_____validateitem)(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_item);
    PyObject *(*CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__1___3_init___3_PortfolioBalances_obj_____call__)(PyObject *cpy_r___mypyc_self__);
    char (*CPyDef_PortfolioBalances_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
    char (*CPyDef_PortfolioBalances_____setitem__)(PyObject *cpy_r_self, PyObject *cpy_r_key, PyObject *cpy_r_value);
    PyObject *(*CPyDef_PortfolioBalances___dataframe)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_PortfolioBalances___sum_usd)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_PortfolioBalances___inverted)(PyObject *cpy_r_self);
    char (*CPyDef_PortfolioBalances_____bool__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_PortfolioBalances_____repr__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_PortfolioBalances_____add__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_PortfolioBalances_____add___3___SummableNonNumericMixin_glue)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_PortfolioBalances_____sub__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__2___3_init___3_WalletBalancesRaw_obj_____call__)(PyObject *cpy_r___mypyc_self__);
    char (*CPyDef_WalletBalancesRaw_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
    char (*CPyDef_WalletBalancesRaw_____bool__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_WalletBalancesRaw_____repr__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_WalletBalancesRaw_____add__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_WalletBalancesRaw_____add___3___SummableNonNumericMixin_glue)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_WalletBalancesRaw_____sub__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__3___3_init___3_PortfolioBalancesByCategory_obj_____call__)(PyObject *cpy_r___mypyc_self__);
    char (*CPyDef_PortfolioBalancesByCategory_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_seed, PyObject *cpy_r_block);
    PyObject *(*CPyDef_PortfolioBalancesByCategory___assets)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_PortfolioBalancesByCategory___debt)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_PortfolioBalancesByCategory___invert)(PyObject *cpy_r_self);
    char (*CPyDef_PortfolioBalancesByCategory_____bool__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_PortfolioBalancesByCategory_____repr__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_PortfolioBalancesByCategory_____add__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_PortfolioBalancesByCategory_____add___3___SummableNonNumericMixin_glue)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    PyObject *(*CPyDef_PortfolioBalancesByCategory_____sub__)(PyObject *cpy_r_self, PyObject *cpy_r_other);
    char (*CPyDef___top_level__)(void);
};
#endif
