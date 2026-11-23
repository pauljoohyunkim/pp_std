func main :: () -> int32 {
    {
        let flags :: PP_FD_OpenFlags = PP_FD_OpenFlags::ReadWrite | PP_FD_OpenFlags::Create | PP_FD_OpenFlags::Truncate;
        let fd :: PP_FD = pp_fd_open("/tmp/pp_std_fd_read_test.txt", flags, 420);
        if ((fd as int32) < 0) {
            pp_print_string("FAIL_OPEN\n");
        } else {
            let data :: const [uint8:5u] = @"data";
            let written :: int64 = pp_fd_write(fd, @data as ptr[const uint8], 4ul);
            if (written != 4l) {
                pp_print_string("FAIL_WRITE\n");
            } else {
                let seek :: int64 = pp_fd_seek(fd, 0l, PP_Whence::Set);
                if (seek < 0l) {
                    pp_print_string("FAIL_SEEK\n");
                } else {
                    let buf :: [uint8:8u] = [uint8:8u; 0uss];
                    let read_bytes :: int64 = pp_fd_read(fd, @buf as ptr[uint8], 4ul);
                    if (read_bytes == 4l) {
                        pp_print_string("PASS_READ\n");
                    } else {
                        pp_print_string("FAIL_READ\n");
                    }
                }
            }
        }
    }
    return 0;
}
