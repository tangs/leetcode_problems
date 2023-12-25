#include <gtest/gtest.h>

#include "solution.hpp"

TEST(fibonacci_number_testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.fib(0), 0);
  EXPECT_EQ(solution.fib(1), 1);
  EXPECT_EQ(solution.fib(2), 1);
  EXPECT_EQ(solution.fib(3), 2);
  EXPECT_EQ(solution.fib(4), 3);
  EXPECT_EQ(solution.fib(10), 55);
  EXPECT_EQ(solution.fib(20), 6765);
  EXPECT_EQ(solution.fib(30), 832040);
}
