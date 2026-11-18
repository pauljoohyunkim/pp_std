#include "pp_io.h"

#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pp_std_types.h"

void pp_std_print_string(pp_string_t str) { pp_std_print_string_ref(&str); }

void pp_std_print_string_ref(const pp_string_t* str) {
    if (!str) return;
    if (str->len == 0) return;
    if (!str->ptr) return;

    fwrite(str->ptr, sizeof(char), str->len, stdout);
    fflush(stdout);
}

void pp_std_print_c_str(const uint8_t* str) {
    if (!str) return;

    fwrite(str, sizeof(char), strlen((const char*)str), stdout);
    fflush(stdout);
}

void pp_std_print_char(uint8_t c) {
    fwrite(&c, sizeof(char), 1, stdout);
    fflush(stdout);
}

void pp_std_print_int64(int64_t val) { printf("%" PRId64, val); }

void pp_std_print_uint64(uint64_t val) { printf("%" PRIu64, val); }

void pp_std_print_float(float val) { printf("%f", val); }

int32_t pp_std_input_char(void) {
    int c = getchar();
    if (c == EOF) { return -1; }
    return c;
}

int32_t pp_std_fd_open(const pp_string_t* str, int32_t flags, int32_t mode) {
    char* buf = NULL;
    if (!str) return -1;
    if (str->len == 0) return -1;
    if (!str->ptr) return -1;

    int ret = 0;

    buf = malloc(str->len + 1);
    if (!buf) return -1;

    memcpy(buf, str->ptr, str->len);
    buf[str->len] = '\0';

    ret = open(buf, flags, mode);
    free(buf);

    return ret;
}

void pp_std_fd_close(int32_t fd) { close(fd); }

int32_t pp_std_fd_read(int32_t* fd, uint8_t* buf, uint32_t N) {
    if (!fd || *fd < 0) return -1;
    if (!buf) return -1;
    if (N == 0) return 0;

    ssize_t ret = read(*fd, buf, N);

    return ret;
}

int32_t pp_std_fd_write(int32_t* fd, const uint8_t* buf, uint32_t count) {
    if (!fd || *fd < 0 || !buf) return -1;
    if (count == 0) return 0;

    ssize_t ret = write(*fd, buf, count);

    return ret;
}
