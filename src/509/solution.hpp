class Solution {
public:
  int fib(int n) {
    if (n <= 0) return 0;

    int prev = 1, cur = 1;

    for (int i = 3; i <= n; ++i) {
      cur += prev;
      prev = cur - prev;
    }

    return cur;
  }
};