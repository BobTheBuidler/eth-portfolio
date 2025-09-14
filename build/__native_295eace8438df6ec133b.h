#ifndef MYPYC_NATIVE_295eace8438df6ec133b_H
#define MYPYC_NATIVE_295eace8438df6ec133b_H
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

#ifndef MYPYC_DECLARED_tuple_T2II
#define MYPYC_DECLARED_tuple_T2II
typedef struct tuple_T2II {
    CPyTagged f0;
    CPyTagged f1;
} tuple_T2II;
#endif

#ifndef MYPYC_DECLARED_tuple_T4OIII
#define MYPYC_DECLARED_tuple_T4OIII
typedef struct tuple_T4OIII {
    PyObject *f0;
    CPyTagged f1;
    CPyTagged f2;
    CPyTagged f3;
} tuple_T4OIII;
#endif

#ifndef MYPYC_DECLARED_tuple_T3IOI
#define MYPYC_DECLARED_tuple_T3IOI
typedef struct tuple_T3IOI {
    CPyTagged f0;
    PyObject *f1;
    CPyTagged f2;
} tuple_T3IOI;
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

#ifndef MYPYC_DECLARED_tuple_T0
#define MYPYC_DECLARED_tuple_T0
typedef struct tuple_T0 {
    int empty_struct_error_flag;
} tuple_T0;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_lock;
    double _ttl;
} eth_portfolio____loaders____nonce___BlockCacheObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} eth_portfolio____loaders____nonce_____mypyc_lambda__0_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__address;
    CPyTagged ___mypyc_generator_attribute__block;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    PyObject *___mypyc_generator_attribute__nonce;
    tuple_T3OOO ___mypyc_temp__2;
    PyObject *___mypyc_generator_attribute__e;
} eth_portfolio____loaders____nonce___get_nonce_at_block_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__address;
    CPyTagged ___mypyc_generator_attribute__nonce;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__highest_known_nonce_lt_query;
    PyObject *___mypyc_generator_attribute__lowest_known_nonce_gt_query;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_temp__4;
    char ___mypyc_temp__5;
    PyObject *___mypyc_temp__6;
    tuple_T3OOO ___mypyc_temp__7;
    PyObject *___mypyc_temp__8;
    CPyTagged ___mypyc_temp__9;
    int64_t ___mypyc_temp__10;
    PyObject *___mypyc_temp__11;
    CPyTagged ___mypyc_generator_attribute__n;
    CPyTagged ___mypyc_generator_attribute__lo;
    CPyTagged ___mypyc_generator_attribute__hi;
    PyObject *___mypyc_temp__12;
    tuple_T3OOO ___mypyc_temp__13;
    CPyTagged ___mypyc_generator_attribute__range_size;
    PyObject *___mypyc_temp__14;
    tuple_T3OOO ___mypyc_temp__15;
    tuple_T3OOO ___mypyc_temp__16;
    PyObject *___mypyc_temp__17;
    tuple_T3OOO ___mypyc_temp__18;
    PyObject *___mypyc_temp__19;
    tuple_T3OOO ___mypyc_temp__20;
    char ___mypyc_generator_attribute__debug_logs_enabled;
    PyObject *___mypyc_temp__21;
    tuple_T3OOO ___mypyc_temp__22;
    CPyTagged ___mypyc_generator_attribute___nonce;
    CPyTagged ___mypyc_generator_attribute__old_lo;
    PyObject *___mypyc_temp__23;
    tuple_T3OOO ___mypyc_temp__24;
    CPyTagged ___mypyc_generator_attribute__prev_block_nonce;
} eth_portfolio____loaders____nonce___get_block_for_nonce_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__address;
    CPyTagged ___mypyc_generator_attribute__nonce;
    CPyTagged ___mypyc_generator_attribute__lo;
    CPyTagged ___mypyc_generator_attribute__hi;
    CPyTagged ___mypyc_generator_attribute__range_size;
    int32_t ___mypyc_next_label__;
    CPyTagged ___mypyc_generator_attribute__num_chunks;
    CPyTagged ___mypyc_generator_attribute__chunk_size;
    PyObject *___mypyc_temp__25;
    CPyTagged ___mypyc_temp__26;
    CPyTagged ___mypyc_temp__27;
    CPyTagged ___mypyc_generator_attribute__i;
    PyObject *___mypyc_generator_attribute__points;
    PyObject *___mypyc_temp__28;
    int64_t ___mypyc_temp__29;
    CPyTagged ___mypyc_generator_attribute__point;
    PyObject *___mypyc_temp__30;
    tuple_T3OOO ___mypyc_temp__31;
    PyObject *___mypyc_generator_attribute__nonces;
    PyObject *___mypyc_temp__32;
    int64_t ___mypyc_temp__33;
    PyObject *___mypyc_temp__34;
    int64_t ___mypyc_temp__35;
    CPyTagged ___mypyc_generator_attribute__block;
    CPyTagged ___mypyc_generator_attribute__n;
} eth_portfolio____loaders____nonce____get_area_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    uint32_t bitmap;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__36;
    PyObject *___mypyc_temp__37;
    char ___mypyc_temp__38;
    PyObject *___mypyc_temp__39;
    tuple_T3OOO ___mypyc_temp__40;
    PyObject *___mypyc_temp__41;
    double ___mypyc_generator_attribute__ts;
    PyObject *___mypyc_temp__42;
    tuple_T3OOO ___mypyc_temp__43;
    CPyTagged ___mypyc_generator_attribute__block;
    tuple_T3OOO ___mypyc_temp__44;
    PyObject *___mypyc_temp__45;
    tuple_T3OOO ___mypyc_temp__46;
    PyObject *___mypyc_temp__47;
    tuple_T3OOO ___mypyc_temp__48;
} eth_portfolio____loaders____nonce___get_block_number_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__token;
    PyObject *___mypyc_generator_attribute__address;
    CPyTagged ___mypyc_generator_attribute__block;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    PyObject *___mypyc_generator_attribute__balance;
    tuple_T3OOO ___mypyc_temp__2;
    PyObject *___mypyc_generator_attribute__token_address;
    PyObject *___mypyc_temp__3;
    tuple_T3OOO ___mypyc_temp__4;
    PyObject *___mypyc_generator_attribute__price;
} eth_portfolio____loaders___balances___load_token_balance_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__txhash;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
} eth_portfolio____loaders___utils____get_transaction_receipt_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_fn;
    PyObject *_compose_wrap;
} eth_portfolio_scripts___docker___docker_compose___ensure_containers_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *___mypyc_env__;
    PyObject *___mypyc_generator_attribute__args;
    PyObject *___mypyc_generator_attribute__kwargs;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    PyObject **_stop_iter_ptr;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    PyObject *___mypyc_temp__2;
} eth_portfolio_scripts___docker___docker_compose___compose_wrap_ensure_containers_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} eth_portfolio_scripts___docker___docker_compose___compose_wrap_ensure_containers_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} eth_portfolio_scripts___docker___docker_compose___compose_wrap_gen___3_50Object;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__args;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__interval;
    PyObject *___mypyc_generator_attribute__portfolio;
    PyObject *___mypyc_generator_attribute__export_start_block;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    PyObject *___mypyc_generator_attribute__start_ts;
    PyObject *___mypyc_generator_attribute__start;
    PyObject *___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_temp__4;
    tuple_T3OOO ___mypyc_temp__5;
    tuple_T3OOO ___mypyc_temp__6;
    PyObject *___mypyc_generator_attribute__ts;
    PyObject *___mypyc_temp__7;
    tuple_T3OOO ___mypyc_temp__8;
    PyObject *___mypyc_temp__9;
    tuple_T3OOO ___mypyc_temp__10;
    PyObject *___mypyc_temp__11;
    tuple_T3OOO ___mypyc_temp__12;
} eth_portfolio_scripts___balances___export_balances_genObject;

#endif
