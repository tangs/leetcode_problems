#include <vector>

class Solution {
public:
  int minCostClimbingStairs(const std::vector<int>& cost) {
    const auto n = cost.size();
    int prev = 0, cur = 0;

    for (auto i = 0; i < n; ++i) {
      int tmp = cost[i] + std::min(cur, prev);
      prev = cur;
      cur = tmp;
    }

    return std::min(prev, cur);
  }
};