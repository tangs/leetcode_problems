#include <vector>
#include <array>

class Solution {
public:
  int deleteAndEarn(const std::vector<int>& nums) {
    constexpr int CNT = 10001;
    std::array<int, CNT> times{};

    for (auto num: nums) ++times[num];

    int prev = 0, cur = 0;

    for (int i = 0; i < CNT; ++i) {
      int tmp = std::max(cur, prev + i * times[i]);
      prev = cur;
      cur = tmp;
    }

    return cur;
  }
};
