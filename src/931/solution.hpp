#include <vector>

class Solution {
public:
  int minFallingPathSum(const std::vector<std::vector<int>>& matrix) {
    const auto n = matrix.size();
    std::vector<int> dp = matrix[0];

    for (int i = 1; i < n; ++i) {
      auto prevDp = dp;
      dp[0] = std::min(prevDp[0], prevDp[1]) + matrix[i][0];
      for (int j = 1; j < n - 1; ++j) {
        dp[j] = *std::min_element(prevDp.cbegin() + j - 1, prevDp.cbegin() + j + 2) + matrix[i][j];
      }
      dp[n - 1] = std::min(prevDp[n - 2], prevDp[n - 1]) + matrix[i][n - 1];
    }

    return *std::min_element(dp.cbegin(), dp.cend());
  }
};