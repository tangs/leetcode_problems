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

        int y = m - 1;
        int x = 0;

        while (x < n && y >= 0) {
            if (matrix[y][x] == target) return true;
            if (matrix[y][x] > target) --y;
            else ++x;
        }

        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        // {1,2,3,4,5},
        // {6,7,8,9,10},
        // {11,12,13,14,15},
        // {16,17,18,19,20},
        // {21,22,23,24,25}
        { -1, 3 }
    };
    Solution solu;
    solu.searchMatrix(matrix, 1);
}