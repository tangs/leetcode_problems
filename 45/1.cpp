#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        unsigned int len = nums.size();
        if (!len) return 0;
        unsigned int dp[len];
        memset(dp, 0xff, sizeof(dp));
        dp[0] = 0;
        for (unsigned int i = 0; i < len;) {
            unsigned int v = nums[i];
            unsigned int next = dp[i] + 1;
            int len1 = min(i + v, len - 1);
            ++i;
            for (int j = i; j <= len1; ++j) {
                dp[j] = min(dp[j], next);
                if (dp[j] <= dp[i] && nums[j] + j >= nums[i] + i) i = j;
            }
        }
        return dp[len - 1];
    }
};

int main() {
    vector<int> nums = {
        2,3,0,1,4
    };
    Solution solution;
    solution.jump(nums);
}
