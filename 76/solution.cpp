#include <string>
#include <unordered_map>
#include <string_view>

class Solution {
public:
  std::optional<std::pair<int, int>> minWindow1(std::string_view s, const std::string& t) {
    const auto n_s = s.size();
    const auto n_t = t.size();

    if (n_t > n_s) return {};

    std::unordered_map<int, int> left_chs;
    std::unordered_map<int, int> cur_chs;

    for (const auto ch: t) ++left_chs[ch];

    auto t_chs = left_chs;

    auto right = -1;
    for (int i = 0; i < n_s; ++i) {
      const auto ch = s[i];
      ++cur_chs[ch];
      const auto it = left_chs.find(ch);

      if (it == left_chs.end()) continue;
      if (--it->second != 0) continue;

      left_chs.erase(it);
      if (left_chs.size() == 0) {
        right = i;
        break;
      }
    }

    if (right == -1) return {};

    for (int i = 0; i <= right; ++i) {
      const auto ch = s[i];
      const auto it = t_chs.find(ch);

      if (it == t_chs.end()) continue;
      if (--cur_chs[ch] < it->second) {
        return std::make_pair(i, right + 1);
      }
    }

    return {};
  }

  std::string minWindow(std::string s, std::string t) {
    const auto n_s = s.size();
    const auto n_t = t.size();

    if (n_t > n_s) return {};

    int left = 0;
    std::optional<std::pair<int, int>> range;

    do {
      const std::string_view sv(s.data() + left);
      const auto ret = minWindow1(sv, t);
      if (!ret) {
        return range ? s.substr(range->first, range->second - range->first) : "";
      }
      if (!range || ret->second - ret->first < range->second - range->first) {
        range = {ret->first + left, ret->second + left};
      }
      left += ret->second;
    } while (true);
  }
};

int main() {
  Solution solution;

  auto ret0 = solution.minWindow("ADOBECODEBANC", "ABC");
  auto ret1 = solution.minWindow("a", "a");
  auto ret2 = solution.minWindow("a", "aa");

  return 0;
}
