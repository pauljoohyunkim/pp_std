func main :: () -> int32 {
    {
        let f :: PP_File = pp_file_open("/tmp/pp_std_test_write.txt", PP_File_OpenMode::PP_FOPEN_READ_ONLY);
        let buf :: [uint8:16u] = [uint8:16u; 0uss];
        let read_bytes :: uint64 = pp_file_read(f, @buf as ptr[uint8], 4ul);
        if (read_bytes == 4ul) {
            pp_print_c_str(@buf as ptr[const uint8]);
            pp_print_string("\n");
        } else {
            pp_print_string("FAIL_READ\n");
        }
    }
    return 0;
}
