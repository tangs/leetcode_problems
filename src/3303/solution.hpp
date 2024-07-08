#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        const auto m = matrix.size();
        const auto n = matrix.front().size();

        std::vector<int> columnMaxes(n);

        for (int i = 0; i < n; ++i) {
          int max = 0;
          for (int j = 0; j < m; ++j) {
              max = std::max(max, matrix[j][i]);
          }
          columnMaxes[i] = max;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
              matrix[i][j] = matrix[i][j] != -1 ? matrix[i][j] : columnMaxes[j];
            }
        }

      return matrix;
    }
};