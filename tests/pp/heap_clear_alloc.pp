func main :: () -> int32 {
    {
        let p :: PP_AllocBytes = pp_alloc_bytes_clear_allocate(8ul);
        if ((p as ptr[uint8]) == nullptr[uint8]) {
            pp_print_string("FAIL_CLEAR\n");
        } else {
            pp_print_string("PASS_CLEAR\n");
        }
    }
    return 0;
}
