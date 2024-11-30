#include <gtest/gtest.h>

#include "s_container.hpp"

TEST(s_container, is_empty) {

    const int expected_size = 0;
    const int actual_size = s_cont.size();
    ASSERT_EQ(actual_size, expected_size);

}
