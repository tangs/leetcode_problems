#include <string>
#include <algorithm>
#include <array>

class Solution {
  static auto calcCharsBits(const std::string& word) {
    int chars_bits = 0;
    for (const auto ch: word) {
      const int index = ch - 'a';
      chars_bits |= 1 << index;
    }
    return chars_bits;
  }
  static auto calcCharsCount(const std::string& word) {
    std::array<int, 26> chars_count {};
    for (const auto ch: word) {
      const int index = ch - 'a';
      ++chars_count[index];
    }
    std::sort(chars_count.begin(), chars_count.end());
    return chars_count;
    // return std::set<int>(chars_count.begin(), chars_count.end());
  }
public:
  bool closeStrings(const std::string& word1, const std::string& word2) {
    const auto n_l = word1.size();
    const auto n_r = word2.size();
    if (n_l != n_r) return false;

    const auto chars_bits_l = calcCharsBits(word1);
    const auto chars_bits_r = calcCharsBits(word2);
    if (chars_bits_l != chars_bits_r) return false;

    const auto chars_count_l = calcCharsCount(word1);
    const auto chars_count_r = calcCharsCount(word2);
    if (chars_count_l != chars_count_r) return false;

    return true;
  }
};

int main() {
  Solution solution;
  // auto ret1 = solution.closeStrings("cabbba", "abbccc");
  auto ret2 = solution.closeStrings("aaabbbbccddeeeeefffff", "aaaaabbcccdddeeeeffff");
  // solution.closeStrings("abbzzca", "babzzcz");
  return 0;
}