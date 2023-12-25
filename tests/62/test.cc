#include <gtest/gtest.h>

#include "solution.hpp"

TEST(unique_paths_exp_testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.uniquePaths(1, 7), 1);
  EXPECT_EQ(solution.uniquePaths(2, 2), 2);
  EXPECT_EQ(solution.uniquePaths(3, 7), 28);
  EXPECT_EQ(solution.uniquePaths(4, 7), 84);
  EXPECT_EQ(solution.uniquePaths(10, 10), 48620);
  EXPECT_EQ(solution.uniquePaths(20, 10), 6906900);
}