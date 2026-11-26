#include <stdlib.h>
#include "pp_heap.h"

PP_AllocBytes pp_alloc_bytes_allocate(size_t n) {
    return (PP_AllocBytes)malloc(n);
}

PP_AllocBytes pp_alloc_bytes_clear_allocate(size_t n) {
    return (PP_AllocBytes)calloc(n, sizeof(uint8_t));
}

int32_t pp_alloc_bytes_reallocate(PP_AllocBytes* pab, size_t n) {
    PP_AllocBytes new_ab = (PP_AllocBytes)realloc(*pab, n);
    if (!new_ab) {
        return -1;
    }

    *pab = new_ab;
    return 0;
}

void pp_alloc_bytes_free(PP_AllocBytes ab) {
    free(ab);
}
