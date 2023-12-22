#include <math.h>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int len = rows * cols;
        
        int color[len];
        unsigned int d[len];

        memset(color, 0, sizeof(color));
        memset(d, -1, sizeof(d));

        color[0] = 1;
        d[0] = 0;
        queue<int> q;
        q.push(0);

        int dest = len - 1;
        int c_dt[] = { 0, 1, -1, 0, 0 };
        int r_dt[] = { 0, 0, 0, 1, -1 };

        while (q.size()) {
            int idx = q.front();
            if (idx == dest) return d[idx];
            int r = idx / cols;
            int c = idx % cols;
            int dir = grid[r][c];
            int next = idx;
            switch (dir) {
                case 1: if (c < cols - 1) next += 1; break;
                case 2: if (c > 0) next -= 1; break;
                case 3: if (r < rows - 1) next += cols; break;
                case 4: if (r > 0) next -= cols; break;
            }
            if (next != idx && color[next] != 2) {
                color[next] = 1;
                d[next] = d[idx];
                q.front() = next;
            } else {
                q.pop();
            }
            for (int i = 1; i <= 4; ++i) {
                int r1 = r + r_dt[i];
                int c1 = c + c_dt[i];
                if (r1 < 0 || r1 >= rows || c1 < 0 || c1 >= cols) continue;
                int next1 = r1 * cols + c1;
                if (next1 == next || color[next1]) continue;
                color[next1] = 1;
                d[next1] = d[idx] + 1;
                // cout << next1 << ":" << d[next1] << endl;
                q.push(next1);
            }
            color[idx] = 2;
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1,1,3},
        {3,2,2},
        {1,1,4}
    };
    Solution solution;
    solution.minCost(grid);
}