#include <vector>

class Solution {
public:
  int rob(const std::vector<int>& nums) {
    int prev = 0, cur = 0;

    for (auto num: nums) {
      int tmp = std::max(cur, prev + num);
      prev = cur;
      cur = tmp;
    }

    return cur;
  }
};