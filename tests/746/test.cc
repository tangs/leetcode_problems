#include <gtest/gtest.h>

#include "solution.hpp"

TEST(min_cost_climbing_stairs_testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.minCostClimbingStairs(std::vector<int>{10,15,20}), 15);
  EXPECT_EQ(solution.minCostClimbingStairs(std::vector<int>{1,100,1,1,1,100,1,1,100,1}), 6);
  EXPECT_EQ(solution.minCostClimbingStairs(std::vector<int>{1,2,3,4,5,6}), 9);
  EXPECT_EQ(solution.minCostClimbingStairs(std::vector<int>{152,35,366,464,363,363,326,472,47,47,326,36,434,632,743,436,723,47,377,336}), 2671);
}