#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (!len) return 0;

        stack<int> nums;
        nums.push(-1);

        int ret = 0;
        for (int i = 0; i < len; ++i) {
            int h = heights[i];
            while (1) {
                int tidx = nums.top();
                int tnum = tidx >= 0 ? heights[tidx] : 0;
                if (tnum <= h) break;
                nums.pop();
                ret = max(ret, (i - nums.top() - 1) * tnum);
            }
            nums.push(i);
        }

        while (1) {
            int tidx = nums.top();
            if (tidx == -1) break;
            int tnum = heights[tidx];
            nums.pop();
            ret = max(ret, (len - nums.top() - 1) * tnum);
        }

        return ret;
    }
};

int main() {
    vector<int> heights = {
        1
    };
    Solution solution;
    solution.largestRectangleArea(heights);
}