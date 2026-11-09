#include "pp_std_types.h"
#include "pp_print.h"
#include <stdio.h>
#include <inttypes.h>

void pp_std_print_string(pp_string_t str) {
    pp_std_print_string_ref(&str);
}

void pp_std_print_string_ref(const pp_string_t* str) {
    if (!str) return;
    if (str->len == 0) return;
    if (!str->ptr) return;
    
    fwrite(str->ptr, sizeof(char), str->len, stdout);
    fflush(stdout);
}

void pp_std_print_char(uint8_t c) {
    fwrite(&c, sizeof(char), 1, stdout);
    fflush(stdout);
}

void pp_std_print_int64(int64_t val) {
    printf("%" PRId64, val);
}

void pp_std_print_uint64(uint64_t val) {
    printf("%" PRIu64, val);
}
