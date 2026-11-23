#ifndef PP_IO_H
#define PP_IO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "pp_std_types.h"

/* Takes the string header by const reference: PP passes `const string&` as a pointer. */
void pp_print_string(const pp_string_t* str);
void pp_print_c_str(const uint8_t* str);
void pp_print_char(uint8_t c);
void pp_print_int64(int64_t val);
void pp_print_uint64(uint64_t val);
void pp_print_float(float val);
int32_t pp_input_char(void);

typedef int32_t PP_FD;

/* Access/creation flags. The bit values must match the members of the PP_FD_OpenFlags flag
 * declared in lib/pp_std/extern/pp_io.ppi. Read-only is 0 (PP_FD_OpenFlags::none). */
typedef uint32_t PP_FD_OpenFlags;
#define PP_O_WRITE 1u
#define PP_O_RDWR 2u
#define PP_O_CREAT 64u
#define PP_O_EXCL 128u
#define PP_O_TRUNC 512u
#define PP_O_APPEND 1024u

/* Origin selector for pp_fd_seek; values must match the PP_Whence enum in extern/pp_io.ppi. */
typedef int32_t PP_Whence;
#define PP_SEEK_SET 0
#define PP_SEEK_CUR 1
#define PP_SEEK_END 2

PP_FD pp_fd_open(const pp_string_t* str, PP_FD_OpenFlags flags, int32_t mode);
void pp_fd_close(PP_FD fd);
int64_t pp_fd_read(PP_FD* fd, uint8_t* buf, uint64_t N);
int64_t pp_fd_write(PP_FD* fd, const uint8_t* buf, uint64_t count);
int64_t pp_fd_seek(PP_FD* fd, int64_t offset, PP_Whence whence);

typedef FILE* PP_File;
typedef uint32_t PP_File_OpenMode;
#define PP_FOPEN_READ_ONLY 0u
#define PP_FOPEN_WRITE_ONLY 1u
#define PP_FOPEN_APPEND 2u
#define PP_FOPEN_READ_WRITE 3u
#define PP_FOPEN_READ_WRITE_TRUNCATE 4u
#define PP_FOPEN_READ_APPEND 5u
PP_File pp_file_open(const pp_string_t* str, PP_File_OpenMode mode);
void pp_file_close(PP_File fp);
uint64_t pp_file_read(PP_File fp, uint8_t* buffer, uint64_t n);
uint64_t pp_file_write(PP_File fp, const uint8_t* buffer, uint64_t n);
void pp_file_flush(PP_File fp);
int32_t pp_file_seek(PP_File fp, int64_t offset, PP_Whence whence);
int64_t pp_file_tell(PP_File fp);

#ifdef __cplusplus
}
#endif

#endif /* PP_IO_H */
