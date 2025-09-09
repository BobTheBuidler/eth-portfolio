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

#ifndef MYPYC_DECLARED_tuple_T4OOIO
#define MYPYC_DECLARED_tuple_T4OOIO
typedef struct tuple_T4OOIO {
    PyObject *f0;
    PyObject *f1;
    CPyTagged f2;
    PyObject *f3;
} tuple_T4OOIO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3IOO
#define MYPYC_DECLARED_tuple_T3IOO
typedef struct tuple_T3IOO {
    CPyTagged f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3IOO;
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
    PyObject *_address;
    PyObject *_block;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    PyObject *_nonce;
    tuple_T3OOO ___mypyc_temp__2;
    PyObject *_e;
} eth_portfolio____loaders____nonce___get_nonce_at_block_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_address;
    CPyTagged _nonce;
    int32_t ___mypyc_next_label__;
    PyObject *_highest_known_nonce_lt_query;
    PyObject *_lowest_known_nonce_gt_query;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_temp__4;
    char ___mypyc_temp__5;
    PyObject *___mypyc_temp__6;
    tuple_T3OOO ___mypyc_temp__7;
    PyObject *___mypyc_temp__8;
    CPyTagged ___mypyc_temp__9;
    CPyTagged ___mypyc_temp__10;
    PyObject *___mypyc_temp__11;
    CPyTagged _n;
    PyObject *_lo;
    PyObject *_hi;
    PyObject *___mypyc_temp__12;
    tuple_T3OOO ___mypyc_temp__13;
    CPyTagged _range_size;
    PyObject *___mypyc_temp__14;
    tuple_T3OOO ___mypyc_temp__15;
    tuple_T3OOO ___mypyc_temp__16;
    PyObject *___mypyc_temp__17;
    tuple_T3OOO ___mypyc_temp__18;
    PyObject *___mypyc_temp__19;
    tuple_T3OOO ___mypyc_temp__20;
    char _debug_logs_enabled;
    PyObject *___mypyc_temp__21;
    tuple_T3OOO ___mypyc_temp__22;
    CPyTagged __nonce;
    PyObject *_old_lo;
    PyObject *___mypyc_temp__23;
    tuple_T3OOO ___mypyc_temp__24;
    CPyTagged _prev_block_nonce;
} eth_portfolio____loaders____nonce___get_block_for_nonce_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_address;
    CPyTagged _nonce;
    PyObject *_lo;
    PyObject *_hi;
    CPyTagged _range_size;
    int32_t ___mypyc_next_label__;
    CPyTagged _num_chunks;
    CPyTagged _chunk_size;
    PyObject *___mypyc_temp__25;
    CPyTagged ___mypyc_temp__26;
    CPyTagged ___mypyc_temp__27;
    CPyTagged _i;
    PyObject *_points;
    PyObject *___mypyc_temp__28;
    CPyTagged ___mypyc_temp__29;
    PyObject *_point;
    PyObject *___mypyc_temp__30;
    tuple_T3OOO ___mypyc_temp__31;
    PyObject *_nonces;
    PyObject *___mypyc_temp__32;
    CPyTagged ___mypyc_temp__33;
    PyObject *___mypyc_temp__34;
    CPyTagged ___mypyc_temp__35;
    PyObject *_block;
    CPyTagged _n;
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
    double _ts;
    PyObject *___mypyc_temp__42;
    tuple_T3OOO ___mypyc_temp__43;
    PyObject *_block;
    tuple_T3OOO ___mypyc_temp__44;
    PyObject *___mypyc_temp__45;
    tuple_T3OOO ___mypyc_temp__46;
    PyObject *___mypyc_temp__47;
    tuple_T3OOO ___mypyc_temp__48;
} eth_portfolio____loaders____nonce___get_block_number_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_token;
    PyObject *_address;
    PyObject *_block;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    PyObject *_balance;
    tuple_T3OOO ___mypyc_temp__2;
    PyObject *_token_address;
    PyObject *___mypyc_temp__3;
    tuple_T3OOO ___mypyc_temp__4;
    PyObject *_price;
} eth_portfolio____loaders___balances___load_token_balance_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_txhash;
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
    PyObject *_args;
    PyObject *_kwargs;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
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
} eth_portfolio_scripts___docker___docker_compose___compose_wrap_ensure_containers_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_args;
    int32_t ___mypyc_next_label__;
    PyObject *_interval;
    PyObject *_portfolio;
    PyObject *_export_start_block;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    PyObject *_start_ts;
    PyObject *_start;
    PyObject *___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_temp__4;
    tuple_T3OOO ___mypyc_temp__5;
    tuple_T3OOO ___mypyc_temp__6;
    PyObject *_ts;
    PyObject *___mypyc_temp__7;
    tuple_T3OOO ___mypyc_temp__8;
    PyObject *___mypyc_temp__9;
    tuple_T3OOO ___mypyc_temp__10;
    PyObject *___mypyc_temp__11;
    tuple_T3OOO ___mypyc_temp__12;
} eth_portfolio_scripts___balances___export_balances_genObject;


struct export_table_295eace8438df6ec133b {
    PyObject **CPyStatic__nonce___logger;
    PyObject **CPyStatic__nonce___logger_is_enabled;
    PyObject **CPyStatic__nonce_____log;
    CPyTagged *CPyStatic__nonce___DEBUG;
    PyObject **CPyStatic__nonce___nonces;
    PyObject **CPyStatic__nonce___locks;
    PyObject **CPyStatic__nonce___get_transaction_count;
    PyObject **CPyStatic__nonce___igather;
    PyObject **CPyStatic__nonce___now;
    PyObject **CPyStatic__nonce___BlockCache___lock;
    PyTypeObject **CPyType__nonce___BlockCache;
    PyObject *(*CPyDef__nonce___BlockCache)(void);
    PyTypeObject **CPyType__nonce_____mypyc_lambda__0_obj;
    PyObject *(*CPyDef__nonce_____mypyc_lambda__0_obj)(void);
    PyTypeObject **CPyType__nonce___get_nonce_at_block_gen;
    PyObject *(*CPyDef__nonce___get_nonce_at_block_gen)(void);
    PyTypeObject **CPyType__nonce___get_block_for_nonce_gen;
    PyObject *(*CPyDef__nonce___get_block_for_nonce_gen)(void);
    PyTypeObject **CPyType__nonce____get_area_gen;
    PyObject *(*CPyDef__nonce____get_area_gen)(void);
    PyTypeObject **CPyType__nonce___get_block_number_gen;
    PyObject *(*CPyDef__nonce___get_block_number_gen)(void);
    PyObject *(*CPyDef__nonce_____mypyc_lambda__0_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef__nonce_____mypyc_lambda__0_obj_____call__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_nonce_at_block_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__nonce___get_nonce_at_block_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_nonce_at_block_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__nonce___get_nonce_at_block_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_nonce_at_block_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__nonce___get_nonce_at_block_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_nonce_at_block_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_nonce_at_block)(PyObject *cpy_r_address, PyObject *cpy_r_block);
    PyObject *(*CPyDef__nonce___get_block_for_nonce_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__nonce___get_block_for_nonce_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_block_for_nonce_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__nonce___get_block_for_nonce_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_block_for_nonce_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__nonce___get_block_for_nonce_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_block_for_nonce_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_block_for_nonce)(PyObject *cpy_r_address, CPyTagged cpy_r_nonce);
    PyObject *(*CPyDef__nonce____get_area_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__nonce____get_area_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce____get_area_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__nonce____get_area_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce____get_area_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__nonce____get_area_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce____get_area_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce____get_area)(PyObject *cpy_r_address, CPyTagged cpy_r_nonce, PyObject *cpy_r_lo, PyObject *cpy_r_hi, CPyTagged cpy_r_range_size);
    char (*CPyDef__nonce____update_nonces)(PyObject *cpy_r_address, CPyTagged cpy_r_nonce, PyObject *cpy_r_block);
    CPyTagged (*CPyDef__nonce____get_num_chunks)(CPyTagged cpy_r_range_size);
    char (*CPyDef__nonce___BlockCache_____mypyc_defaults_setup)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_block_number_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__nonce___get_block_number_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_block_number_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__nonce___get_block_number_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_block_number_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__nonce___get_block_number_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_block_number_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__nonce___get_block_number)(void);
    char (*CPyDef__nonce_____top_level__)(void);
    PyObject **CPyStatic__loaders___balances____ZERO;
    PyObject **CPyStatic__loaders___balances___logger;
    PyObject **CPyStatic__loaders___balances____builtin_round;
    PyTypeObject **CPyType__loaders___balances___load_token_balance_gen;
    PyObject *(*CPyDef__loaders___balances___load_token_balance_gen)(void);
    PyObject *(*CPyDef__loaders___balances___load_token_balance_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__loaders___balances___load_token_balance_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__loaders___balances___load_token_balance_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__loaders___balances___load_token_balance_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__loaders___balances___load_token_balance_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__loaders___balances___load_token_balance_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__loaders___balances___load_token_balance_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__loaders___balances___load_token_balance)(PyObject *cpy_r_token, PyObject *cpy_r_address, PyObject *cpy_r_block);
    PyObject *(*CPyDef__loaders___balances____calc_value)(PyObject *cpy_r_balance, PyObject *cpy_r_price);
    PyObject *(*CPyDef__loaders___balances___round)(PyObject *cpy_r_value, CPyTagged cpy_r_digits);
    char (*CPyDef__loaders___balances_____top_level__)(void);
    PyObject **CPyStatic_utils___Raw;
    PyObject **CPyStatic_utils___get_transaction_receipt;
    PyObject **CPyStatic_utils_____get_transaction_receipt;
    PyTypeObject **CPyType_utils____get_transaction_receipt_gen;
    PyObject *(*CPyDef_utils____get_transaction_receipt_gen)(void);
    PyObject *(*CPyDef_utils____get_transaction_receipt_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_utils____get_transaction_receipt_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_utils____get_transaction_receipt_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_utils____get_transaction_receipt_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_utils____get_transaction_receipt_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_utils____get_transaction_receipt_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_utils____get_transaction_receipt_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_utils____get_transaction_receipt)(PyObject *cpy_r_txhash);
    char (*CPyDef_utils_____top_level__)(void);
    PyObject *(*CPyDef__argspec___get_args_type)(PyObject *cpy_r_sample);
    PyObject *(*CPyDef__argspec___get_kwargs_type)(PyObject *cpy_r_sample);
    PyObject *(*CPyDef__argspec___get_return_type)(PyObject *cpy_r_sample);
    tuple_T3OOO (*CPyDef__argspec___get_types)(PyObject *cpy_r_sample);
    char (*CPyDef__argspec_____top_level__)(void);
    CPyTagged *CPyStatic__config___REORG_BUFFER;
    char (*CPyDef__config_____top_level__)(void);
    PyObject **CPyStatic__shitcoins___shitcoins;
    char (*CPyDef__shitcoins_____top_level__)(void);
    PyObject **CPyStatic__stableish___stableish;
    char (*CPyDef__stableish_____top_level__)(void);
    CPyTagged *CPyStatic_constants___NUM_WALLETS;
    PyObject **CPyStatic_constants___ADDRESSES;
    PyObject **CPyStatic_constants___TRANSFER_SIGS;
    PyObject **CPyStatic_constants___ETH_LIKE;
    PyObject **CPyStatic_constants___BTC_LIKE;
    PyObject **CPyStatic_constants___INTL_STABLECOINS;
    char (*CPyDef_constants_____top_level__)(void);
    char (*CPyDef_docker_____top_level__)(void);
    char (*CPyDef_check___check_docker)(void);
    char (*CPyDef_check___check_docker_compose)(void);
    char (*CPyDef_check___check_system)(void);
    char (*CPyDef_check_____top_level__)(void);
    PyObject **CPyStatic_docker_compose___logger;
    PyObject **CPyStatic_docker_compose___compose_file;
    PyTypeObject **CPyType_docker_compose___ensure_containers_env;
    PyObject *(*CPyDef_docker_compose___ensure_containers_env)(void);
    PyTypeObject **CPyType_docker_compose___compose_wrap_ensure_containers_env;
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_env)(void);
    PyTypeObject **CPyType_docker_compose___compose_wrap_ensure_containers_obj;
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_obj)(void);
    PyTypeObject **CPyType_docker_compose___compose_wrap_ensure_containers_gen;
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_gen)(void);
    char (*CPyDef_docker_compose___up)(PyObject *cpy_r_services);
    char (*CPyDef_docker_compose___down)(void);
    char (*CPyDef_docker_compose___build)(PyObject *cpy_r_services);
    char (*CPyDef_docker_compose___stop)(PyObject *cpy_r_container_name);
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_docker_compose___compose_wrap_ensure_containers_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    PyObject *(*CPyDef_docker_compose___ensure_containers)(PyObject *cpy_r_fn);
    char (*CPyDef_docker_compose____exec_command)(PyObject *cpy_r_command, PyObject *cpy_r_compose_options);
    char (*CPyDef_docker_compose_____top_level__)(void);
    PyObject **CPyStatic_eth_portfolio_scripts___balances____UTC;
    PyObject **CPyStatic_eth_portfolio_scripts___balances___create_task;
    PyObject **CPyStatic_eth_portfolio_scripts___balances___yield_to_loop;
    PyTypeObject **CPyType_eth_portfolio_scripts___balances___export_balances_gen;
    PyObject *(*CPyDef_eth_portfolio_scripts___balances___export_balances_gen)(void);
    PyObject *(*CPyDef_eth_portfolio_scripts___balances___export_balances_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_eth_portfolio_scripts___balances___export_balances_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_eth_portfolio_scripts___balances___export_balances_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_eth_portfolio_scripts___balances___export_balances_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_eth_portfolio_scripts___balances___export_balances_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_eth_portfolio_scripts___balances___export_balances_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_eth_portfolio_scripts___balances___export_balances_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_eth_portfolio_scripts___balances___export_balances)(PyObject *cpy_r_args);
    char (*CPyDef_eth_portfolio_scripts___balances_____top_level__)(void);
};
#endif
