func main :: () -> int32 {
    {
        let p :: PP_AllocBytes = pp_alloc_bytes_allocate(4ul);
        if ((p as ptr[uint8]) == nullptr[uint8]) {
            pp_print_string("FAIL_ALLOC\n");
        } else {
            // realloc through a mutable handle borrow: the C side updates the slot in place
            let rc :: int32 = pp_alloc_bytes_reallocate(p, 8ul);
            if (rc == 0) {
                pp_print_string("PASS_REALLOC\n");
            } else {
                pp_print_string("FAIL_REALLOC\n");
            }
        }
    }
    return 0;
}
