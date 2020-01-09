#include <vector>
#include <iostream>

using namespace std;

class Solution {
    void print2DArray(int *arr, int m, int n) {
        // print dp info.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << arr[i * n + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        if (!n) return 0;

        int row = m + 1;
        int col = n + 1;
        int height[row][col];
        int left[row][col];
        int right[row][col];

        memset(height, 0, sizeof(height));
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));

        int ret = 0;
        for (int i = 1; i < row; ++i) {
            right[i][n] = matrix[i - 1][n - 1] - '0';
            for (int j = 1; j < col; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    height[i][j] = height[i - 1][j] + 1;
                    left[i][j] = left[i][j - 1] + 1;
                }
            }
            for (int j = n; j > 0; --j) {
                if (matrix[i - 1][j - 1] == '1') {
                    right[i][j] = right[i][j + 1] + 1;

                    int max1 = 0;
                    for (int k = 0; k < i; ++k) {
                        int h = height[k][j];
                        if (!h) break;
                        int area = h * (left[k][j] + right[k][j] - 1);
                        ret = max(ret, area);
                    }
                }
            }
        }

        print2DArray((int*)height, row, col);
        print2DArray((int*)left, row, col);
        print2DArray((int*)right, row, col);

        return ret;
    }
};

int main() {
    vector<vector<char>> matirx = {
        { '1','0','1','0','0' },
        { '1','0','1','1','1' },
        { '1','1','1','1','1' },
        { '1','0','0','1','0' },
    };
    Solution solution;
    solution.maximalRectangle(matirx);
}
