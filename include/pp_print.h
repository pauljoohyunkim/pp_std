#ifndef PP_PRINT_H
#define PP_PRINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pp_std_types.h"

void pp_std_print_string(pp_string_t str);
void pp_std_print_string_ref(const pp_string_t* str);
void pp_std_print_char(uint8_t c);
void pp_std_print_int64(int64_t val);
void pp_std_print_uint64(uint64_t val);
void pp_std_print_float(float val);

#ifdef __cplusplus
}
#endif

#endif /* PP_PRINT_H */
