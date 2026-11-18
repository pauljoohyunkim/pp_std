#ifndef PP_IO_H
#define PP_IO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pp_std_types.h"

void pp_std_print_string(pp_string_t str);
void pp_std_print_string_ref(const pp_string_t* str);
void pp_std_print_c_str(const uint8_t* str);
void pp_std_print_char(uint8_t c);
void pp_std_print_int64(int64_t val);
void pp_std_print_uint64(uint64_t val);
void pp_std_print_float(float val);
int32_t pp_std_input_char(void);

int32_t pp_std_fd_open(const pp_string_t* str, int32_t flags, int32_t mode);
void pp_std_fd_close(int32_t fd);
int32_t pp_std_fd_read(int32_t* fd, uint8_t* buf, uint32_t N);
int32_t pp_std_fd_write(int32_t* fd, const uint8_t* buf, uint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* PP_IO_H */
