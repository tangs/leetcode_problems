#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        const auto n = s.size();
        auto ans = 0;

        auto l = 0;
        auto r = 0;
        bool bits[128] {};

        while (r < n) {
            if (const auto ch = s[r]; bits[ch]) {
                while (s[l++] != ch) {
                    bits[s[l - 1]] = false;
                }
            } else {
                bits[ch] = true;
            }
            ans = std::max(ans, r - l + 1);
            ++r;
        }

        return ans;
    }
};

int main() {

}