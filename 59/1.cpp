#include <vector>

using namespace std;

class Solution {
public:
     vector<vector<int>> generateMatrix(int n) {
        // vector<vector<int>> ret(n);
        // if (!n) return ret;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         ret[i].push_back(0);
        //     }
        // }

        vector<vector<int>> ret(n, vector<int>(n));
        int x = 0;
        int y = 0;
        // 0.right 1.bottom 2.left 3.top
        int dir = 0;
        int xdf[] = { 1, 0, -1, 0 };
        int ydf[] = { 0, 1, 0, -1 };
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        const int len = n * n;
        for (int i = 1; i <= len; ++i) {
            ret[y][x] = i;
            int y1 = y + ydf[dir];
            int x1 = x + xdf[dir];
            if (x1 < 0 || x1 == n || y1 < 0 || y1 == n || dp[y1][x1]) {
                dir = (dir + 1) % 4;
                y1 = y + ydf[dir];
                x1 = x + xdf[dir];
            }
            dp[y][x] = true;
            y = y1;
            x = x1;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    solution.generateMatrix(6);
}
