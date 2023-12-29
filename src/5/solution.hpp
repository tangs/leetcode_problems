#include <string>
#include <vector>

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    const auto n = s.size();
    s.insert(0, "-");

    std::vector<int> dp(n, 1);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {

      }
    }

    return {};
  }
};