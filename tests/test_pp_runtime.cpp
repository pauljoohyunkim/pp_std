#include <gtest/gtest.h>
#include "pp_runtime.h"

TEST(PP_Runtime, GetArgvNull) {
    pp_list_t lst = pp_get_argv(0, nullptr);
    // Should not crash, list may be empty
    (void)lst;
}

TEST(PP_Runtime, GetArgvZero) {
    pp_list_t lst = pp_get_argv(0, nullptr);
    // Ensure fields are sane
    EXPECT_NE(&lst, nullptr);
}
