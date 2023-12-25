#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"

TEST(minimum_path_sum_exp_testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.minPathSum(Utils::v2<int>("[[1,2],[1,1]]")), 3);
  EXPECT_EQ(solution.minPathSum(Utils::v2<int>("[[1,3,1],[1,5,1],[4,2,1]]")), 7);
  EXPECT_EQ(solution.minPathSum(Utils::v2<int>("[[1,2,3],[4,5,6]]")), 12);
}