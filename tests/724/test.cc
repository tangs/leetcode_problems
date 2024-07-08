#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"

TEST(testing, BasicAssertions) {
    Solution solution;
    EXPECT_EQ(solution.pivotIndex(std::vector{1, 7, 3, 6, 5, 6}), 3);
    EXPECT_EQ(solution.pivotIndex({1, 2, 3}), -1);
    EXPECT_EQ(solution.pivotIndex({2, 1, -1}), 0);
    EXPECT_EQ(solution.pivotIndex({2, 1, -3}), -1);
    EXPECT_EQ(solution.pivotIndex({-2, 2, -3}), 2);
}