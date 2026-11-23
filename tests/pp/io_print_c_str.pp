func main :: () -> int32 {
    let s :: const [uint8:6u] = @"Hello";
    pp_print_c_str(@s as ptr[const uint8]);
    pp_print_string("\n");
    return 0;
}
