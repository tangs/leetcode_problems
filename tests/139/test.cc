#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"

TEST(testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.wordBreak("leetcode",
                               Utils::v1<std::string>(R"(["leet","code"])")), true);
  EXPECT_EQ(solution.wordBreak("applepenapple",
                               Utils::v1<std::string>(R"(["apple","pen"])")), true);
  EXPECT_EQ(solution.wordBreak("catsandog",
                               Utils::v1<std::string>(R"(["cats","dog","sand","and","cat"])")), false);
}