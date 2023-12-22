#include <math.h>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;

        queue<pair<int, int>> s;
        for (int i = 0; i < m; ++i) {
            auto& row = grid[i];
            for (int j = 0; j < n; ++j) if (row[j] == 2) s.emplace(i, j);
        }

        int ret = 0;
        int times[m][n];
        memset(times, 0, sizeof(times));
        while (s.size()) {
            auto it = s.front();
            s.pop();
            int r = it.first, c = it.second;
            static const int r_dt[] = {1, -1, 0, 0};
            static const int c_dt[] = {0, 0, 1, -1};
            for (int i = 0; i < 4; ++i) {
                int r1 = r + r_dt[i];
                int c1 = c + c_dt[i];

                if (r1 >= 0 && r1 < m && c1 >= 0 && c1 < n && grid[r1][c1] == 1) {
                    grid[r1][c1] = 2;
                    s.emplace(r1, c1);
                    times[r1][c1] = times[r][c] + 1;
                    ret = max(ret, times[r1][c1]);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            auto& row = grid[i];
            for (int j = 0; j < n; ++j) if (row[j] == 1) return -1;
        }

        return ret;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2},{1},{1},{1},{2},{1},{1}
    };
    Solution solution;
    solution.orangesRotting(grid);
}