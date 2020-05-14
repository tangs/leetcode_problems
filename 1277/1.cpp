#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0];
            if (dp[i][0]) ++ans;
        }
        for (int i = 1; i < n; ++i) {
            dp[0][i] = matrix[0][i];
            if (dp[0][i]) ++ans;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][j]) continue;
                int val = min(matrix[i - 1][j], min(matrix[i - 1][j - 1], matrix[i][j - 1]));
                if (val) {
                    matrix[i][j] = val + 1;
                    ans += matrix[i][j];
                } else ++ans;
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,0,1},
        {1,1,0},
        {1,1,0}
    };
    Solution solution;
    solution.countSquares(matrix);
}