#ifndef PP_MISC_H
#define PP_MISC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "pp_std_types.h"

void pp_seed_unsafe_rand();
int32_t pp_unsafe_rand();

#ifdef __cplusplus
}
#endif

#endif /* PP_MISC_H */
