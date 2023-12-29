#include <string>
#include <string_view>
#include <vector>

class Solution {
public:
  bool wordBreak(std::string s, const std::vector<std::string> &wordDict) {
    const auto n = s.size();
    std::vector<bool> dp(n + 1);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
      for (const auto& wold: wordDict) {
        const auto size = wold.size();
        if (size > i || !dp[i - size] || std::string_view(s.c_str() + i - size, size) != wold) continue;

        dp[i] = true;
        break;
      }
    }

    return dp[n];
  }
};
