#include <math.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;

        bool colors[m][n];
        memset(colors, 0, sizeof(colors));
        int cnt = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || colors[i][j]) continue;
                ++cnt;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (q.size()) {
                    auto val = q.front();
                    q.pop();
                    int i = val.first;
                    int j = val.second;
                    if (colors[i][j]) continue;
                    if (i > 0 && grid[i - 1][j] == '1') q.emplace(i - 1, j);
                    if (i < m - 1 && grid[i + 1][j] == '1') q.emplace(i + 1, j);
                    if (j > 0 && grid[i][j - 1] == '1') q.emplace(i, j - 1);
                    if (j < n - 1 && grid[i][j + 1] == '1') q.emplace(i, j + 1);
                    colors[i][j] = 1;
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<char>> grid = {
        // {'1','1','0','0','0'},
        // {'1','1','0','0','0'},
        // {'0','0','1','0','0'},
        // {'0','0','0','1','1'}
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}

    };
    Solution solution;
    solution.numIslands(grid);
}