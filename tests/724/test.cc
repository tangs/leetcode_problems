#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"

TEST(testing_pivotIndex, BasicAssertions) {
    Solution solution;
    EXPECT_EQ(solution.pivotIndex(std::vector{1, 7, 3, 6, 5, 6}), 3);
    EXPECT_EQ(solution.pivotIndex(std::vector{1, 2, 3}), -1);
    EXPECT_EQ(solution.pivotIndex(std::vector{2, 1, -1}), 0);
    EXPECT_EQ(solution.pivotIndex(std::vector{2, 1, -3}), -1);
    EXPECT_EQ(solution.pivotIndex(std::vector{-2, 2, -3}), 2);
    EXPECT_EQ(solution.pivotIndex(std::vector{1, 2, 3, 4, 2, 10}), 4);
    auto vec = std::vector{1, 2, 3, 4, 2, 10};
    EXPECT_EQ(solution.pivotIndex(vec), 4);
}
