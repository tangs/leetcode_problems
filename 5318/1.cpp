#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    inline int getr(vector<int>& ranges, vector<int>& idxs, int len) {
        int r = -1;
        for (int i = 0; i < len; ++i) {
            int idx = idxs[i];
            r = max(r, idx + ranges[idx]);
        }
        return r;
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        if (!n) return true;
        vector<int> idxs;
        int len = ranges.size();
        for (int i = 0; i < len; ++i) {
            int ran = ranges[i];
            if (ran <= 0) continue;
            int r = min(n, i + ran);
            int l = max(0, i - ran);
            int size1 = idxs.size();

            bool needPush = true;
            while (idxs.size()) {
                int top = idxs.back();
                int tv = ranges[top];
                int tl = max(0, top - tv);
                int tr = min(n, top + tv);
                if (r <= tr || l > tr) {
                    needPush = false;
                    break;
                } else if (r > tr) {
                    int prevr = getr(ranges, idxs, idxs.size() - 1);
                    if (l <= tl || prevr >= l)
                        idxs.pop_back();
                    else break;
                } else {
                    break;
                }
            }
            if (needPush) {
                idxs.push_back(i);
            }
        }

        int len1 = idxs.size();
        if (!len1) return -1;
        int lastidx = idxs.back();
        int r = lastidx + ranges[lastidx];
        return r >= n ? len1 : -1;
    }
};

int main() {
    vector<int> nums = {
        1,2,1,0,2,1,0,1
    };
    Solution solution;
    solution.minTaps(7, nums);
}
