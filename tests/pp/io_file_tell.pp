func main :: () -> int32 {
    {
        let f :: PP_File = pp_file_open("/tmp/pp_std_file_tell_test.txt", PP_File_OpenMode::PP_FOPEN_WRITE_ONLY);
        let data :: const [uint8:5u] = @"abcd";
        let _ :: uint64 = pp_file_write(f, @data as ptr[const uint8], 4ul);
        let pos :: int64 = pp_file_tell(f);
        if (pos == 4l) {
            pp_print_string("PASS_TELL\n");
        } else {
            pp_print_string("FAIL_TELL\n");
        }
    }
    return 0;
}
