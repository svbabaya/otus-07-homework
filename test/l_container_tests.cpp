#include "l_container.hpp"
#include <gtest/gtest.h>

TEST(l_container, exists) {
    ASSERT_NE(&l_cont, nullptr);
}

TEST(l_container, is_empty) {
    l_cont.clear();
    const int expected_size = 0;
    const int actual_size = l_cont.size();
    ASSERT_EQ(actual_size, expected_size);
}

TEST(l_container, push_back) {
    l_cont = {1, 2, 3};
    const int expected = 30;
    const int back = 30;
    l_cont.push_back(back);
    int actual = l_cont.back();
    ASSERT_EQ(actual, expected);
}

TEST(l_container, push_first) {
    l_cont = {1, 2, 3};
    const int expected = 10;
    const int first = 10;
    l_cont.push_front(first); 
    int actual = l_cont.front();
    ASSERT_EQ(actual, expected);
}

TEST(l_container, insert) {
    l_cont = {1, 2, 3};
    const int expected = 20;
    const int second = 20;
    l_cont.insert(++l_cont.begin(), second); 
    int actual = *(++l_cont.begin());
    ASSERT_EQ(actual, expected);
}

TEST(l_container, del_end) {
    l_cont = {1, 2, 3, 4, 5, 6, 7};
    const std::list<int> expected = {1, 2, 3, 4, 5, 6};
    l_cont.pop_back();
    ASSERT_EQ(l_cont, expected);
}

TEST(l_container, del_first) {
    l_cont = {1, 2, 3, 4, 5, 6, 7};
    const std::list<int> expected = {2, 3, 4, 5, 6, 7};
    l_cont.pop_front();
    ASSERT_EQ(l_cont, expected);
}

TEST(l_container, del_middle) {
    l_cont = {1, 2, 3, 4, 5, 6, 7};
    const std::list<int> expected = {1, 7};
    l_cont.erase(++l_cont.begin(), --l_cont.end());
    ASSERT_EQ(l_cont, expected);
}

TEST(l_container, get_element) {
    l_cont = {1, 2, 3, 440044, 5, 6, 7};
    const int index = 3;
    const int expected = 440044;
    std::list<int>::iterator it = l_cont.begin();
    std::advance(it, index);
    const int actual = *it;
    ASSERT_EQ(actual, expected);
}

TEST(l_container, size) {
    l_cont = {1, 2, 3, 4, 5, 6, 7};
    const int expected = 7;
    int actual = l_cont.size();
    ASSERT_EQ(actual, expected);
}

TEST(l_container, out_of_range) {
    l_cont = {1, 2, 3, 4, 5, 6, 7};
    const int out_index = 10;
    const int max_index = l_cont.size() - 1;
    ASSERT_GT(out_index, max_index);
}

TEST(l_container, copy) {
    l_cont = {1, 2, 3, 4, 5, 6, 7};
    std::list<int> target;
    target = l_cont;
    ASSERT_EQ(target, l_cont);
}
