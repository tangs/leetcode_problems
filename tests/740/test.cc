#include <gtest/gtest.h>

#include "solution.hpp"

TEST(delete_and_earn_exp_testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.deleteAndEarn({3,4,2}), 6);
  EXPECT_EQ(solution.deleteAndEarn({2,2,3,3,3,4}), 9);
  EXPECT_EQ(solution.deleteAndEarn({134,5,6,34,33,32,53,33,32,33,35,64,742,46,4646,4445,777,8756}), 19803);
  EXPECT_EQ(solution.deleteAndEarn({134,5,6,34,33,9999,53,10000,32,33,35,9999,10000,46,4646,4445,777,8756}), 38964);
}