#include "pp_runtime.h"

#include <stdlib.h>
#include <string.h>

void pp_abort(void) { abort(); }

pp_list_t pp_get_argv(int32_t argc, uint8_t** argv) {
    pp_string_t* str_arr = NULL;
    uint8_t* buffer = NULL;
    pp_list_t arg_list = {0};

    if (argc <= 0 || argv == NULL) { return arg_list; }

    str_arr = (pp_string_t*)calloc((size_t)argc, sizeof(pp_string_t));
    if (!str_arr) goto error_cleanup;

    for (int32_t i = 0; i < argc; i++) {
        size_t arg_i_len = argv[i] ? strlen((const char*)argv[i]) : 0;

        /* Keep the NUL terminator so the copy is still usable as a C string.
         * drop only calls free(), so the extra byte costs nothing. */
        buffer = (uint8_t*)malloc(arg_i_len + 1);
        if (!buffer) goto error_cleanup;
        if (arg_i_len > 0) { memcpy(buffer, argv[i], arg_i_len); }
        buffer[arg_i_len] = '\0';

        /* Ownership moves into the list element: nullify the source so the
         * error path cannot free the same buffer twice. */
        str_arr[i].ptr = buffer;
        str_arr[i].len = (size_t)arg_i_len;
        buffer = NULL;
    }

    arg_list.data = str_arr;
    arg_list.len = (size_t)argc;
    arg_list.cap = (size_t)argc;
    arg_list.elem_size = sizeof(pp_string_t);
    str_arr = NULL; /* Ownership moved into arg_list. */
    return arg_list;

error_cleanup:
    free(buffer);
    if (str_arr) {
        /* calloc zeroed the tail, so free() sees NULL for elements not built yet. */
        for (int32_t i = 0; i < argc; i++) { free((void*)str_arr[i].ptr); }
    }
    free(str_arr);
    pp_abort();
    return arg_list; /* Unreachable: pp_abort() does not return. */
}

int32_t pp_system(const pp_string_t* command) {
    if (!command || !command->ptr) return system(NULL);

    char* buffer = (char*)malloc(command->len + 1);
    if (!buffer) return -1;
    buffer[command->len] = '\0';
    memcpy(buffer, command->ptr, command->len);

    int ret = system(buffer);

    free(buffer);

    return ret;
}