#include "pp_std_types.h"
#include "pp_print.h"
#include <stdio.h>

void pp_std_print_string(const pp_string_t* str) {
    if (!str) return;
    if (str->len == 0) return;
    if (!str->ptr) return;
    
    fwrite(str->ptr, sizeof(char), str->len, stdout);
    fflush(stdout);
}
