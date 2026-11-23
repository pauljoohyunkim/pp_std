func main :: () -> int32 {
    {
        let flags :: PP_FD_OpenFlags = PP_FD_OpenFlags::ReadWrite | PP_FD_OpenFlags::Create | PP_FD_OpenFlags::Truncate;
        let fd :: PP_FD = pp_fd_open("/tmp/pp_std_fd_seek_test.txt", flags, 420);
        if ((fd as int32) < 0) {
            pp_print_string("FAIL_OPEN\n");
        } else {
            let data :: const [uint8:6u] = @"12345";
            let _ :: int64 = pp_fd_write(fd, @data as ptr[const uint8], 5ul);
            let pos :: int64 = pp_fd_seek(fd, 2l, PP_Whence::Set);
            if (pos == 2l) {
                pp_print_string("PASS_SEEK\n");
            } else {
                pp_print_string("FAIL_SEEK\n");
            }
        }
    }
    return 0;
}
