#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"

TEST(triangle_exp_testing, BasicAssertions) {
  Solution solution;

//  EXPECT_EQ(solution.minimumTotal(Utils::v2<int>("[2],[3,4],[6,5,7],[4,1,8,3]]")), 11);
//  EXPECT_EQ(solution.minimumTotal(Utils::v2<int>("[[-10]]")), -10);
  EXPECT_EQ(solution.minimumTotal(Utils::v2<int>("[[-1],[-2,-3]]")), -4);
}