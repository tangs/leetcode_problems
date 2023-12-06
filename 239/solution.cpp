#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> ans;
        std::map<int, int> curs;

        for (int i = 0; i < k; ++i) ++curs[nums[i]];
        ans.push_back(curs.crbegin()->first);

        const auto n = nums.size();
        for (int i = k; i < n; ++i) {
            auto remove_idx = nums[i - k];
            if (const auto it = curs.find(remove_idx); --it->second == 0) curs.erase(it);
            ++curs[nums[i]];
            ans.push_back(curs.crbegin()->first);
        }

        return ans;
    }
};

int main() {
    std::vector<int> nums0 = {1,3,-1,-3,5,3,6,7};
    std::vector<int> nums1 = {1};
    std::vector<int> nums2 = {1,-1};
    Solution solution;
    auto ret0 = solution.maxSlidingWindow(nums0, 3);
    auto ret1 = solution.maxSlidingWindow(nums1, 1);
    auto ret2 = solution.maxSlidingWindow(nums2, 1);
    return 0;
}