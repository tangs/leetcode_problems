#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    inline bool putable(vector<int>& data, int cur) {
        int line = data.size();
        if (line == 0) return true;
        // if (abs(data[line - 2] - cur) <= 1) return false;
        for (int i = 0; i < line; ++i) {
            int idx = data[i];
            if (idx == cur) return false;
            int dis = line - i;
            if (abs(idx - cur) == dis) return false;
        }
        return true;
    }

    void deal(vector<vector<string>>& ret, int n, vector<int>& data) {
        if (data.size() == n) {
            char tmp[n + 1];
            memset(tmp, '.', n);
            tmp[n] = 0;
            int len = data.size();
            vector<string> strs;
            for (int i = 0; i < len; ++i) {
                int idx = data[i];
                tmp[idx] = 'Q';
                strs.push_back(tmp);
                tmp[idx] = '.';
            }
            ret.push_back(std::move(strs));
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (putable(data, i)) {
                data.push_back(i);
                deal(ret, n, data);
                data.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        if (n != 1 && n < 4) return ret;
        std::vector<int> data;
        deal(ret, n, data);
        return ret;
    }
};

int main() {
    Solution solution;
    solution.solveNQueens(4);
}