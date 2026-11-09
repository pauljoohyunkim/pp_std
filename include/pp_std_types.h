#ifndef PP_STD_TYPES_H
#define PP_STD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*
 * Layouts must match the LLVM struct types emitted by the PP compiler.
 * Keep these in sync with pp_backend_lower_type in src/pp_code_generator.c.
 */

/* pp.string = { ptr, len }  (field 0: i8* or void*, field 1: i64) */
typedef struct pp_string {
    const uint8_t* ptr;
    uint64_t len;
} pp_string_t;

/* pp.list = { data_ptr, len, cap } (field 0: ptr, fields 1/2: i64) */
typedef struct pp_list {
    void* data;
    uint64_t len;
    uint64_t cap;
} pp_list_t;

#ifdef __cplusplus
}
#endif

#endif /* PP_STD_TYPES_H */
