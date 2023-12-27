#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"

TEST(testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]])xx")), 4);
  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["0"]])xx")), 0);
  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["1"]])xx")), 1);
}