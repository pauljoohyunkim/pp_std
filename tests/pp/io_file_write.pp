func main :: () -> int32 {
    let data :: const [uint8:5u] = @"test";
    {
        let f :: PP_File = pp_file_open("/tmp/pp_std_test_write.txt", PP_File_OpenMode::PP_FOPEN_WRITE_ONLY);
        let written :: uint64 = pp_file_write(f, @data as ptr[const uint8], 4ul);
        if (written == 4ul) {
            pp_print_string("PASS\n");
        } else {
            pp_print_string("FAIL\n");
        }
    }
    return 0;
}
