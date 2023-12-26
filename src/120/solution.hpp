#include <vector>

class Solution {
public:
  int minimumTotal(const std::vector<std::vector<int>>& triangle) {
    int n = triangle.size();
    std::vector<int> dp(n);

    dp[0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
      dp[i] = dp[i - 1] + triangle[i][i];
      for (int j = i - 1; j > 0; --j) {
        dp[j] = std::min(dp[j], dp[j - 1]) + triangle[i][j];
      }
      dp[0] += triangle[i][0];
    }

    return *std::min_element(dp.cbegin(), dp.cend());
  }
};