#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len < 3) return 0;
        int l = 0;
        int r = len - 1;
        int nums[len];
        memset(nums, 0, sizeof(nums));
        while (l < r - 1) {
            int left = height[l];
            int right = height[r];
            int v = min(left, right);
            if (v) {
                for (int i = l + 1; i < r; ++i) {
                    nums[i] = v;
                }
            }
            if (left <= right) {
                ++l;
                while (l < r && height[l] <= left) ++l;
            } else {
                --r;
                while (l < r && height[r] <= right) --r;
            }
        }
        int ret = 0;
        for (int i = 0; i < len; ++i) {
            ret += max(0, nums[i] - height[i]);
        }
        return ret;
    }
};

int main() {
    vector<int> vecs = {
        0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1, 2
    };
    Solution solution;
    solution.trap(vecs);
}
