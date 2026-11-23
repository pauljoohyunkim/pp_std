func main :: () -> int32 {
    {
        let flags :: PP_FD_OpenFlags = PP_FD_OpenFlags::Write | PP_FD_OpenFlags::Create | PP_FD_OpenFlags::Truncate;
        let fd :: PP_FD = pp_fd_open("/tmp/pp_std_fd_test.txt", flags, 420);
        if ((fd as int32) < 0) {
            pp_print_string("FAIL_OPEN\n");
        } else {
            let data :: const [uint8:4u] = @"fd\n";
            let written :: int64 = pp_fd_write(fd, @data as ptr[const uint8], 3ul);
            if (written == 3l) {
                pp_print_string("PASS\n");
            } else {
                pp_print_string("FAIL_WRITE\n");
            }
        }
    }
    return 0;
}
