#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ret;
        int rLen = matrix.size();
        int cLen = matrix[0].size();

        for (unsigned int i = 0; i < rLen; ++i) {
            vector<int> row(cLen, INT_MAX - 1000);
            for (unsigned int j = 0; j < cLen; ++j) {
                if (matrix[i][j] == 0) {
                    row[j]= 0;
                } else {
                    if (i > 0) row[j] = min(ret[i - 1][j] + 1, row[j]);
                    if (j > 0) row[j] = min(row[j - 1] + 1, row[j]);
                }
            }
            ret.push_back(std::move(row));
        }

        for (int i = rLen - 1; i >= 0; --i) {
            for (int j = cLen - 1; j >= 0; --j) {
                if (ret[i][j] == 0) continue;
                if (i < rLen - 1) ret[i][j] = min(ret[i + 1][j] + 1, ret[i][j]);
                if (j < cLen - 1) ret[i][j] = min(ret[i][j + 1] + 1, ret[i][j]);
            }
        }
        return ret;
    }
};
