func main :: () -> int32 {
    {
        let f :: PP_File = pp_file_open("/tmp/pp_std_file_seek_test.txt", PP_File_OpenMode::PP_FOPEN_WRITE_ONLY);
        let data :: const [uint8:7u] = @"seek!!";
        let _ :: uint64 = pp_file_write(f, @data as ptr[const uint8], 5ul);
    }
    {
        let f :: PP_File = pp_file_open("/tmp/pp_std_file_seek_test.txt", PP_File_OpenMode::PP_FOPEN_READ_ONLY);
        let _ :: int64 = pp_file_seek(f, 2l, PP_Whence::Set);
        let buf :: [uint8:4u] = [uint8:4u; 0uss];
        let read_bytes :: uint64 = pp_file_read(f, @buf as ptr[uint8], 3ul);
        if (read_bytes == 3ul) {
            pp_print_string("PASS_SEEK\n");
        } else {
            pp_print_string("FAIL_SEEK\n");
        }
    }
    return 0;
}
