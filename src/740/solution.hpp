#include <vector>
#include <array>

class Solution {
public:
  int deleteAndEarn(const std::vector<int>& nums) {
    constexpr int CNT = 10001;
    std::array<int, CNT> vals{};

    for (auto num: nums) vals[num] += num;

    int prev = 0, cur = 0;

    for (int i = 0; i < CNT; ++i) {
      int tmp = std::max(cur, prev + vals[i]);
      prev = cur;
      cur = tmp;
    }

    return cur;
  }
};
