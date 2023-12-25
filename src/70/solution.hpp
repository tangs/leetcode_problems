class Solution {
public:
  [[nodiscard]]
  int climbStairs(int n) const noexcept {
    if (n <= 2) return n;
    int p = 1;
    int c = 2;

    for (int i = 3; i <= n; ++i) {
      int tmp = p + c;
      p = c;
      c = tmp;
    }

    return c;
  }
};
