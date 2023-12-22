#include <vector>
#include <iostream>
#include <stack>
#include <stdlib.h>

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

    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (!len) return 0;

        stack<int> nums;
        nums.push(-1);

        int ret = 0;
        for (int i = 0; i < len; ++i) {
            int h = heights[i];
            while (1) {
                int tidx = nums.top();
                int tnum = tidx >= 0 ? heights[tidx] : 0;
                if (tnum <= h) break;
                nums.pop();
                ret = max(ret, (i - nums.top() - 1) * tnum);
            }
            nums.push(i);
        }

        while (1) {
            int tidx = nums.top();
            if (tidx == -1) break;
            int tnum = heights[tidx];
            nums.pop();
            ret = max(ret, (len - nums.top() - 1) * tnum);
        }

        return ret;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        if (!n) return 0;

        int row = m;
        int col = n;

        // int heights[row][col];
        // memset(heights, 0, sizeof(heights));

        int ret = 0;
        vector<int> heights(col);

        stack<int> nums;
        nums.push(-1);
        for (int i = 0; i < row; ++i) {
            auto& row = matrix[i];
            for (int j = 0; j < col; ++j) {
                int h = 0;
                if (row[j] == '1') {
                    h = heights[j] + 1;
                }
                heights[j] = h;
                int top = nums.top();
                int h1;
                while (top != -1 && (h1 = heights[top]) > h) {
                    nums.pop();
                    ret = max(ret, h1 * (j - (top = nums.top()) - 1));
                }
                nums.push(j);
            }
            int h = heights[col - 1];
            int top = nums.top();
            while (top != -1) {
                // top = nums.top();
                nums.pop();
                ret = max(ret, heights[top] * (col - (top = nums.top()) - 1));
            }
        }

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
