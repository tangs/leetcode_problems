#include <vector>

class Solution {
public:
  int maximalSquare(const std::vector<std::vector<char>>& matrix) {
    const auto m = matrix.size();
    const auto n = matrix[0].size();

    std::vector<int> dp(n + 1);
    int ans = 0;

    for (int i = 0; i < m; ++i) {
      int prev = dp[0];
      for (int j = 1; j <= n; ++j) {
        int cur = dp[j];
        if (matrix[i][j - 1] == '1') {
          dp[j] = std::min({prev, dp[j - 1], dp[j]}) + 1;
          ans = std::max(dp[j], ans);
        } else {
          dp[j] = 0;
        }
        prev = cur;
      }
    }

    return ans * ans;
  }
};