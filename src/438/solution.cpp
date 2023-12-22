#include <vector>
#include <array>
#include <string>

class Solution {
    static std::array<int, 26> alphabetCounts(const std::string& str,
        const int s, const int e) {
        std::array<int, 26> counts = {};
        for (int i = s; i < e; ++i) {
            counts[str[i] - 'a']++;
        }
        return counts;
    }

public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        const auto ns = s.size();
        const auto n = p.size();

        if (n > ns) return {};

        const auto pCounts = alphabetCounts(p, 0, n);
        auto counts = alphabetCounts(s, 0, n);

        std::vector<int> ans;

        s.push_back('a');
        for (int i = 0; i <= ns - n; ++i) {
            if (counts == pCounts) ans.push_back(i);
            const auto l = i;
            const auto r = i + n;
            --counts[s[l] - 'a'];
            ++counts[s[r] - 'a'];
        }

        return ans;
    }
};

int main() {
    Solution solution;
    // auto ret0 = solution.findAnagrams("cbaebabacd", "abc");
    auto ret1 = solution.findAnagrams("abab", "ab");
    return 0;
}