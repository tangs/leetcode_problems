#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"

TEST(unique_paths_ii_exp_testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.uniquePathsWithObstacles(Utils::v2<int>("[[0,0,0],[0,1,0],[0,0,0]]")), 2);
  EXPECT_EQ(solution.uniquePathsWithObstacles(Utils::v2<int>("[[0,1],[0,0]]")), 1);
  EXPECT_EQ(solution.uniquePathsWithObstacles(Utils::v2<int>("[[1]]")), 0);
}