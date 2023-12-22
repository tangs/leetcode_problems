#include <gtest/gtest.h>

#include "solution.hpp"

TEST(min_path_sum_rand_testing, BasicAssertions) {
  Solution solution;
  EXPECT_EQ(solution.climbStairs(0), 0);
  EXPECT_EQ(solution.climbStairs(1), 1);
  EXPECT_EQ(solution.climbStairs(2), 2);
  EXPECT_EQ(solution.climbStairs(20), 10946);
  EXPECT_EQ(solution.climbStairs(45), 1836311903);
}