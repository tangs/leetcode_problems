#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if (!len) return 0;
        int dp[len + 1];
        memset(dp, 0, sizeof(dp));
        if (s[0] == '0') return false;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < len; ++i) {
            int num1 = s[i] - '0';
            int num2 = s[i - 1] - '0';
            int vaule = num2 * 10 + num1;
            if (num1 != 0) dp[i + 1] += dp[i];
            if (vaule >= 10 && vaule <= 26) dp[i + 1] += dp[i - 1];
        }
        return dp[len];
    }
};

int main() {
    Solution solu;
    solu.numDecodings("12302310");
}
