#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        const auto n = nums.size();
        int ans = 0;

        int pre_sum = 0;
        std::unordered_map<int, int> pre_sum_count;

        pre_sum_count.insert({0, 1});

        for (const auto num: nums) {
            pre_sum += num;
            ans += pre_sum_count[pre_sum - k];
            pre_sum_count[pre_sum]++;
        }

        return ans;
    }
};

int main() {
    std::vector<int> nums0 = {1,1,1};
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {1};
    Solution solution;
    auto ret0 = solution.subarraySum(nums0, 2);
    auto ret1 = solution.subarraySum(nums1, 3);
    auto ret2 = solution.subarraySum(nums2, 0);
    return 0;
}
