#include <gtest/gtest.h>

#include "solution.hpp"

TEST(tribonacci_number_testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.tribonacci(0), 0);
  EXPECT_EQ(solution.tribonacci(1), 1);
  EXPECT_EQ(solution.tribonacci(2), 1);
  EXPECT_EQ(solution.tribonacci(3), 2);
  EXPECT_EQ(solution.tribonacci(4), 4);
  EXPECT_EQ(solution.tribonacci(10), 149);
  EXPECT_EQ(solution.tribonacci(20), 66012);
  EXPECT_EQ(solution.tribonacci(30), 29249425);
  EXPECT_EQ(solution.tribonacci(37), 2082876103);
}