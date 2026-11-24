func main :: () -> int32 {
    {
        let p :: PP_AllocBytes = pp_alloc_bytes_allocate(16ul);
        if ((p as ptr[uint8]) == nullptr[uint8]) {
            pp_print_string("FAIL_ALLOC\n");
        } else {
            pp_print_string("PASS_ALLOC\n");
        }
    }
    return 0;
}
