#include <vector>

class Solution1 {
public:
  int maximalSquare(const std::vector<std::vector<char>>& matrix) {
    const auto m = matrix.size();
    const auto n = matrix[0].size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    int ans = 0;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = matrix[i - 1][j - 1] == '1' ? (std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1) : 0;
        ans = std::max(dp[i][j], ans);
      }
    }

    return ans * ans;
  }
};