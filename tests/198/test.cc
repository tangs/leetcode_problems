#include <gtest/gtest.h>

#include "utils/utils.h"
#include "solution.hpp"

TEST(testing, BasicAssertions) {
  Solution solution;

  EXPECT_EQ(solution.rob({1,2,3,1}), 4);
  EXPECT_EQ(solution.rob({2,7,9,3,1}), 12);
  EXPECT_EQ(solution.rob({43}), 43);
  EXPECT_EQ(solution.rob({10,3,53,234,64,75,34,79,123,156,34}), 554);
}