#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"

TEST(minimum_falling_path_sum_testing, BasicAssertions) {
  Solution solution;

//  EXPECT_EQ(solution.minFallingPathSum(Utils::v2<int>("[[2,1,3],[6,5,4],[7,8,9]]")), 13);
  EXPECT_EQ(solution.minFallingPathSum(Utils::v2<int>("[[-19,57],[-40,-5]]")), -59);
}