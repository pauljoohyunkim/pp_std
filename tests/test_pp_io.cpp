#include <gtest/gtest.h>
#include "pp_io.h"
#include "pp_std_types.h"

TEST(PP_IO, PrintStringNull) {
    // Should not crash on null pointer
    pp_print_string(nullptr);
}

TEST(PP_IO, PrintStringEmpty) {
    pp_string_t s{nullptr, 0};
    pp_print_string(&s);
}

TEST(PP_IO, FD_OpenNull) {
    PP_FD fd = pp_fd_open(nullptr, 0, 0);
    EXPECT_EQ(fd, -1);
}

TEST(PP_IO, FD_OpenEmpty) {
    pp_string_t s{nullptr, 0};
    PP_FD fd = pp_fd_open(&s, 0, 0);
    EXPECT_EQ(fd, -1);
}

TEST(PP_IO, FD_ReadNull) {
    int64_t ret = pp_fd_read(nullptr, nullptr, 10);
    EXPECT_EQ(ret, -1);
}

TEST(PP_IO, FD_WriteNull) {
    int64_t ret = pp_fd_write(nullptr, nullptr, 10);
    EXPECT_EQ(ret, -1);
}

TEST(PP_IO, FD_SeekNull) {
    int64_t ret = pp_fd_seek(nullptr, 0, PP_SEEK_SET);
    EXPECT_EQ(ret, -1);
}

TEST(PP_IO, FileOpenNull) {
    PP_File fp = pp_file_open(nullptr, PP_FOPEN_READ_ONLY);
    EXPECT_EQ(fp, nullptr);
}

TEST(PP_IO, FileOpenEmpty) {
    pp_string_t s{nullptr, 0};
    PP_File fp = pp_file_open(&s, PP_FOPEN_READ_ONLY);
    EXPECT_EQ(fp, nullptr);
}

TEST(PP_IO, FileReadNull) {
    uint64_t r = pp_file_read(nullptr, nullptr, 10);
    EXPECT_EQ(r, 0u);
}

TEST(PP_IO, FileWriteNull) {
    uint64_t w = pp_file_write(nullptr, nullptr, 10);
    EXPECT_EQ(w, 0u);
}

TEST(PP_IO, FileSeekNull) {
    int32_t s = pp_file_seek(nullptr, 0, PP_SEEK_SET);
    EXPECT_EQ(s, -1);
}

TEST(PP_IO, FileTellNull) {
    int64_t t = pp_file_tell(nullptr);
    EXPECT_EQ(t, -1);
}

TEST(PP_IO, PrintCStrNull) {
    pp_print_c_str(nullptr);
}

TEST(PP_IO, PrintChar) {
    pp_print_char(0);
}

TEST(PP_IO, PrintInt64) {
    pp_print_int64(0);
}

TEST(PP_IO, PrintUint64) {
    pp_print_uint64(0);
}

TEST(PP_IO, PrintFloat) {
    pp_print_float(0.0f);
}

TEST(PP_IO, FDCloseInvalid) {
    pp_fd_close(-1);
}

TEST(PP_IO, FileCloseNull) {
    pp_file_close(nullptr);
}

TEST(PP_IO, FileFlushNull) {
    pp_file_flush(nullptr);
}
