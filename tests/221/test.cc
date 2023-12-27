#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"
#include "solution1.hpp"

TEST(maximal_square_exp_testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]])xx")), 4);
  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["0"]])xx")), 0);
  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["1"]])xx")), 1);
}

TEST(maximal_square_exp1_testing, BasicAssertions) {
  Solution1 solution;

  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]])xx")), 4);
//  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["0"]])xx")), 0);
//  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["0"]])xx")), 0);
//  EXPECT_EQ(solution.maximalSquare(Utils::v2<char>(R"xx([["1"]])xx")), 1);
}