#ifndef PP_STD_TYPES_H
#define PP_STD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

/*
 * Layouts must match the LLVM struct types emitted by the PP compiler.
 * Keep these in sync with pp_backend_lower_type in src/pp_code_generator.c.
 *
 * Length-like fields are `size_t` (pointer width), matching PP's `usize`: they are i32 on a
 * 32-bit target and i64 (or whatever the pointer width is) on a 64-bit target.
 */

/* pp.string = { ptr, len }  (field 0: i8*, field 1: usize/size_t) */
typedef struct pp_string {
    const uint8_t* ptr;
    size_t len;
} pp_string_t;

/* pp.list = { data, len, cap, elem_size } (field 0: ptr, fields 1/2/3: usize/size_t) */
typedef struct pp_list {
    void* data;
    size_t len;
    size_t cap;
    size_t elem_size;
} pp_list_t;

#ifdef __cplusplus
}
#endif

#endif /* PP_STD_TYPES_H */
