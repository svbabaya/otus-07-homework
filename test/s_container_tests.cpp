#include "s_container.hpp"
#include <gtest/gtest.h>

TEST(s_container, exists) {
    ASSERT_NE(&s_cont, nullptr);
}

TEST(s_container, is_empty) {
    s_cont.clear();
    const int expected_size = 0;
    const int actual_size = s_cont.size();
    ASSERT_EQ(actual_size, expected_size);
}

TEST(s_container, push_back) {
    s_cont = {1, 2, 3};
    const int expected = 30;
    const int back = 30;
    s_cont.push_back(back);
    int actual = s_cont.back();
    ASSERT_EQ(actual, expected);
}

TEST(s_container, push_first) {
    s_cont = {1, 2, 3};
    const int expected = 10;
    const int first = 10;
    s_cont.insert(s_cont.begin(), first); 
    int actual = s_cont.front();
    ASSERT_EQ(actual, expected);
}

TEST(s_container, insert) {
    s_cont = {1, 2, 3};
    const int expected = 20;
    const int second = 20;
    s_cont.insert(++s_cont.begin(), second); 
    int actual = s_cont.at(1);
    ASSERT_EQ(actual, expected);
}

TEST(s_container, del_end) {
    s_cont = {1, 2, 3, 4, 5, 6, 7};
    const std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    s_cont.pop_back();
    ASSERT_EQ(s_cont, expected);
}

TEST(s_container, del_first) {
    s_cont = {1, 2, 3, 4, 5, 6, 7};
    const std::vector<int> expected = {2, 3, 4, 5, 6, 7};
    s_cont.erase(s_cont.begin());
    ASSERT_EQ(s_cont, expected);
}

TEST(s_container, del_middle) {
    s_cont = {1, 2, 3, 4, 5, 6, 7};
    const std::vector<int> expected = {1, 7};
    s_cont.erase(++s_cont.begin(), --s_cont.end());
    ASSERT_EQ(s_cont, expected);
}

TEST(s_container, get_element) {
    s_cont = {1, 2, 3, 440044, 5, 6, 7};
    const int expected = 440044;
    int actual = s_cont.at(3);
    ASSERT_EQ(actual, expected);
}

TEST(s_container, size) {
    s_cont = {1, 2, 3, 4, 5, 6, 7};
    const int expected = 7;
    int actual = s_cont.size();
    ASSERT_EQ(actual, expected);
}

TEST(s_container, invalid_index) {
    s_cont = {1, 2, 3, 4, 5, 6, 7};
    EXPECT_ANY_THROW(s_cont.at(s_cont.size() + 1));
}

TEST(s_container, copy) {
    s_cont = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> target;
    target = s_cont;
    ASSERT_EQ(target, s_cont);
}
