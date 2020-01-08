#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int len = intervals.size();
        vector<vector<int>> ret;
        if (!len) return ret;

        int idxs[len];
        for (int i = 0; i < len; ++i) idxs[i] = i;

        sort(idxs, idxs + len, [&intervals] (int idx1, int idx2) {
            // auto& item1 = intervals[idx1];
            // auto& item2 = intervals[idx2];
            return intervals[idx1][0] < intervals[idx2][0];
        });

        ret.push_back(intervals[idxs[0]]);
        for (int i = 1; i < len; ++i) {
            int idx = idxs[i];
            auto cur = intervals[idx];
            auto& last = ret.back();
            if (cur[0] <= last[1]) {
                cur[0] = min(cur[0], last[0]);
                cur[1] = max(cur[1], last[1]);
                ret.pop_back();
            }
            ret.push_back(move(cur));
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    Solution solution;
    solution.merge(intervals);
}
