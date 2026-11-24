func main :: (argc :: int32, argv :: ptr[ptr[uint8]]) -> int32 {
    // Smoke test for pp_get_argv; we just call it to ensure linkage
    let args :: [string] = pp_get_argv(argc, argv);
    pp_print_string("PASS_ARGV\n");
    return 0;
}
