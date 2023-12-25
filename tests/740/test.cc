#include <gtest/gtest.h>

#include "solution.hpp"

TEST(testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.deleteAndEarn({134,5,6,34,33,32,53,33,32,33,35,64,742,46,4646,4445,777,8756}), 19803);
}