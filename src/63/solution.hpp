#include <vector>

class Solution {
public:
  int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    std::vector<int> dp(n);
    dp[0] = obstacleGrid[0][0] ^ 1;

    for (int i = 1; i < n; ++i) dp[i] = obstacleGrid[0][i] == 1 ? 0 : dp[i - 1];
    for (int i = 1; i < m; ++i) {
      dp[0] = obstacleGrid[i][0] == 1 ? 0 : dp[0];
      for (int j = 1; j < n; ++j) {
        dp[j] = obstacleGrid[i][j] == 1 ? 0 : dp[j - 1] + dp[j];
      }
    }

    return dp[n - 1];
  }
};