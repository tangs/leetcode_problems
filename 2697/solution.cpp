#include <string>

class Solution {
public:
    std::string makeSmallestPalindrome(std::string s) {
        const auto len = s.size();
        for (auto i = 0; i < len / 2; ++i) {
            const auto r = len - i - 1;
            const auto dest = std::min(s[i], s[r]);
            s[i] = s[r] = dest;
        }
        return s;
    }
};

int main() {

}
