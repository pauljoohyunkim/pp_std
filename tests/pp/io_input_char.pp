func main :: () -> int32 {
    // Smoke test for pp_input_char; in CI stdin is empty so it returns -1 quickly
    let c :: int32 = pp_input_char();
    if (c == -1) {
        pp_print_string("EOF\n");
    } else {
        pp_print_string("OK\n");
    }
    return 0;
}
