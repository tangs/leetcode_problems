#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (!len) return 0;
        int prev = 0, cur = nums[0];
        for (int i = 1; i < len; ++i) {
            int tmp = max(prev + nums[i], cur);
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
};

int main() {
    vector<int> nums = {
        1,2,3,1
    };
    Solution solution;
    solution.rob(nums);
}