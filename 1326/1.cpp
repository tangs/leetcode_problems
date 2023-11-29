#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        std::stack<int> idxs;
        int min = 1000;
        int max = -1;
        int len = ranges.size();
        int rMax = len - 1;
        for (int i = 0; i < len; ++i) {
            int range = ranges[i];
            if (range <= 0) continue;
            int l = std::max(0, i - range);
            int r = std::min(rMax, i + range);
            bool needPush = idxs.empty() || r > max;
            while (!idxs.empty()) {
                int top = idxs.top();
                int topRange = ranges[top];
                int tl = std::max(0, top - topRange);
                int tr = std::min(rMax, top + topRange);
                if (l <= tl && r >= tr) {
                    needPush = true;
                    idxs.pop();
                } else {
                    break;
                }
            }
            if (needPush) {
                idxs.push(i);
                min = std::min(min, l);
                max = std::max(max, r);
            }
        }
        if (min > 0 || max < len - 1) return -1;
        return idxs.size();
    }
};

int main() {
//    int n = 5;
//    vector<int> ranges = {3,4,1,1,0,0};
//    int n = 5;
//    vector<int> ranges = {3,4,1,1,0,0};

//    int n = 8;
//    vector<int> ranges = {4,0,0,0,4,0,0,0,4};

    int n = 9;
    vector<int> ranges = {0,5,0,3,3,3,1,4,0,4};

    Solution solution;
    solution.minTaps(n, ranges);
    return 0;
}