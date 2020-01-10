#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;

        // int dp[m + 1][n + 1];
        // memset(dp, 0, sizeof(dp));
        for (int i = 1; i < m; ++i)
            grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < n; ++i)
            grid[0][i] += grid[0][i - 1];

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int left = grid[i][j - 1];
                int top = grid[i - 1][j];
                grid[i][j] += min(left, top);
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution solution;
    solution.minPathSum(grid);
}
