#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int times = n / 2;
        for (int i = 0; i < times; ++i) {
            // int max = n - i * 2 - 1;
            int ie = n - i - 1;
            for (int j = i; j < ie; ++j) {
                // int l = i + j;
                int je = ie - j + i;
                int numt = matrix[i][j];
                int numr = matrix[j][ie];
                int numb = matrix[ie][je];
                int numl = matrix[je][i];

                matrix[i][j] = numl;
                matrix[j][ie] = numt;
                matrix[ie][je] = numr;
                matrix[je][i] = numb;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        { 5,1,9,11 },
        { 2,4,8,10 },
        { 13,3,6,7 },
        { 15,14,12,16 }
    };
    Solution solution;
    solution.rotate(matrix);
}
