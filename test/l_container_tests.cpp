#include <gtest/gtest.h>

#include "l_container.hpp"

TEST(l_container, is_empty) {

    const int expected_size = 0;
    const int actual_size = l_cont.size();
    ASSERT_EQ(actual_size, expected_size);

}
