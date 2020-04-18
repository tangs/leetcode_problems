#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;
        
        vector<vector<bool>> color(m, vector<bool>(n, false));

        int ret = 0;
        queue<pair<int, int>> q;
        std::function<void()> bfs;
        bfs = [&] () {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            if (r > 0 && grid[r - 1][c] == '1' && !color[r - 1][c]) {
                color[r - 1][c] = true;
                q.push(make_pair(r - 1, c));
            }
            if (c > 0 && grid[r][c - 1] == '1' && !color[r][c - 1]) {
                color[r][c - 1] = true;
                q.push(make_pair(r, c - 1));
            }
            if (r < m - 1 && grid[r + 1][c] == '1' && !color[r + 1][c]) {
                color[r + 1][c] = true;
                q.push(make_pair(r + 1, c));
            }
            if (c < n - 1 && grid[r][c + 1] == '1' && !color[r][c + 1]) {
                color[r][c + 1] = true;
                q.push(make_pair(r, c + 1));
            }
            if (q.size()) bfs();
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || color[i][j]) continue;
                ++ret;
                q.push(make_pair(i, j));
                color[i][j] = true;
                bfs();
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','0','1','0','0'},
        {'0','0','0','0','1'}
    };
    Solution solution;
    int ret = solution.numIslands(grid);
    return 0;
}