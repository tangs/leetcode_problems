#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int row = matrix.size();
        if (row == 0) return ret;
        int col = matrix[0].size();
        if (col == 0) return ret;

        int sum = row * col;
        // int cur = 0;

        int x = 0;
        int y = 0;
        // 0.r 1.b 2.l 3.t
        int dir = 0;
        // 0.r 1.b 2.l 3.t
        int used[] = {0, 0, 0, 0};
        int x_dt[] = {1, 0, -1, 0};
        int y_dt[] = {0, 1, 0, -1};

        for (;;) {
            ret.push_back(matrix[y][x]);
            if (ret.size() == sum) break;
            int nx = x + x_dt[dir];
            int ny = y + y_dt[dir];
            if (nx < (0 + used[2]) || nx >= (col - used[0]) 
                || ny < (0 + used[3]) || ny >= (row - used[1])) {
                int idx = (dir + 3) % 4;
                ++used[idx];
                dir = (dir + 1) % 4;
                nx = x + x_dt[dir];
                ny = y + y_dt[dir];
            }
            x = nx;
            y = ny;
        }

        return ret;
    }
};

int main() {
    vector<vector<int>> data = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    Solution solution;
    solution.spiralOrder(data);
}