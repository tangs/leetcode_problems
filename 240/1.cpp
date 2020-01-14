#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size();
        if (!n) return false;

        int len = m * n;
        int i = m >> 1;
        int j = n >> 1;
        for (;;) {
            int v = matrix[i][j];
            if (v == target) return true;
            bool isEndI = i == m - 1;
            bool isEndJ = j == n - 1;
            // if (isEndI && isEndJ) return false;
            if (v < target) {
                if (isEndI && isEndJ) return false;
                if (isEndI) {
                    if (matrix[i][j + 1] > target) return false;
                    ++j;
                } else if (isEndJ) {
                    if (matrix[i + 1][j] > target) return false;
                    ++i;
                } else {
                    int num1 = target - matrix[i][j + 1];
                    int num2 = target - matrix[i + 1][j];
                    if (!num1 || !num2) return true;
                    if (num1 < 0 && num2 < 0) return false;
                    if (num1 > 0 && num2 > 0) {
                        ++i;
                        ++j;
                    } else if (num1 > 0) ++j;
                    else ++i;
                }
            } else {
                if (i == 0 && j == 0) return false;
                if (!i) { 
                    if (matrix[i][j - 1] < target) return false;
                    --j;
                } else if (!j) {
                    if (matrix[i - 1][j] < target) return false;
                     --i;
                } else {
                    int num1 = matrix[i][j - 1] - target;
                    int num2 = matrix[i - 1][j] - target;
                    if (!num1 || !num2) return true;
                    if (num1 < 0 && num2 < 0) return false;
                    if (num1 > 0 && num2 > 0) {
                        --i;
                        --j;
                    } else if (num1 > 0) --j;
                    else --i;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}
    };
    Solution solu;
    solu.searchMatrix(matrix, 5);
}