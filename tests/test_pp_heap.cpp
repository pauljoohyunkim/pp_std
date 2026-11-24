#include <gtest/gtest.h>
#include "pp_heap.h"

TEST(PP_Heap, AllocateZero) {
    PP_AllocBytes p = pp_alloc_bytes_allocate(0);
    // malloc(0) may return nullptr or unique ptr; just ensure free doesn't crash
    pp_alloc_bytes_free(p);
}

TEST(PP_Heap, AllocateAndFree) {
    PP_AllocBytes p = pp_alloc_bytes_allocate(16);
    EXPECT_NE(p, nullptr);
    pp_alloc_bytes_free(p);
}

TEST(PP_Heap, ClearAllocate) {
    PP_AllocBytes p = pp_alloc_bytes_clear_allocate(8);
    EXPECT_NE(p, nullptr);
    for (int i = 0; i < 8; ++i) {
        EXPECT_EQ(p[i], 0);
    }
    pp_alloc_bytes_free(p);
}

TEST(PP_Heap, Reallocate) {
    PP_AllocBytes p = pp_alloc_bytes_allocate(4);
    EXPECT_NE(p, nullptr);
    p[0] = 0xAA;
    int32_t rc = pp_alloc_bytes_reallocate(&p, 8);
    EXPECT_EQ(rc, 0);
    EXPECT_NE(p, nullptr);
    EXPECT_EQ(p[0], 0xAA);
    pp_alloc_bytes_free(p);
}

TEST(PP_Heap, FreeNull) {
    pp_alloc_bytes_free(nullptr);
}
