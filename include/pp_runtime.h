#ifndef PP_RUNTIME_H
#define PP_RUNTIME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "pp_std_types.h"

void pp_abort(void);
pp_list_t pp_get_argv(int32_t argc, uint8_t** argv);

#ifdef __cplusplus
}
#endif

#endif /* PP_RUNTIME_H */
