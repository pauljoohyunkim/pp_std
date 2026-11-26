#ifndef PP_HEAP_H
#define PP_HEAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pp_std_types.h"

#include <stdint.h>

typedef uint8_t* PP_AllocBytes;
PP_AllocBytes pp_alloc_bytes_allocate(size_t n);
PP_AllocBytes pp_alloc_bytes_clear_allocate(size_t n);
int32_t pp_alloc_bytes_reallocate(PP_AllocBytes* pab, size_t n);
void pp_alloc_bytes_free(PP_AllocBytes ab);

#ifdef __cplusplus
}
#endif

#endif /* PP_HEAP_H */
