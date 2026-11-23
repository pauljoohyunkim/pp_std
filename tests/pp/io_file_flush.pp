func main :: () -> int32 {
    {
        let f :: PP_File = pp_file_open("/tmp/pp_std_flush_test.txt", PP_File_OpenMode::PP_FOPEN_WRITE_ONLY);
        let data :: const [uint8:6u] = @"flush";
        let written :: uint64 = pp_file_write(f, @data as ptr[const uint8], 5ul);
        if (written == 5ul) {
            pp_file_flush(f);
            pp_print_string("PASS_FLUSH\n");
        } else {
            pp_print_string("FAIL_WRITE\n");
        }
    }
    return 0;
}
