#include <vector>

using namespace std;

class Solution {
    void deal(vector<vector<int>>& ret, vector<int>& idxs, int n, int k) {
        int len = idxs.size();
        if (len == k) {
            ret.push_back(idxs);
            return;
        }
        int start = len == 0 ? 0 : idxs.back();
        for (int i = start + 1; i <= n; ++i) {
            idxs.push_back(i);
            deal(ret, idxs, n, k);
            idxs.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (n < k) return ret;
        vector<int> idxs;
        deal(ret, idxs, n, k);
        return ret;
    }
};
