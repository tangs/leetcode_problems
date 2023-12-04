#include <vector>
#include <unordered_set>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    const auto n = nums.size();
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> ret;
    for (int i = 0; i < n - 2;) {
      int l = i + 1;
      int r = n - 1;
      const auto num = nums[i];
      while (l < r) {
        const int sum = num + nums[l] + nums[r];
        if (sum > 0) {
          while (--r > l && nums[r] == nums[r + 1]);
          continue;
        }
        if (sum == 0) {
          ret.push_back({nums[i], nums[l], nums[r]});
        }
        while (++l < r && nums[l] == nums[l - 1]);
      }
      while (++i < n && nums[i] == nums[i - 1]);
    }
    return ret;
  }
};

int main() {
  std::vector nums {-1,0,1,2,-1,-4};
  Solution solution;
  auto ret = solution.threeSum(nums);
  return 0;
}