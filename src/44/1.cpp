#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        if (!slen && ! plen) return true;
        if (!plen) return false;
        bool dp[slen + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int ignoreCnt = 0;
        for (int i = 0; i < plen; ++i) {
            char ch = p[i];
            switch (ch) {
                case '?':
                    for (int j = slen; j > ignoreCnt; --j) 
                        dp[j] = dp[j - 1];
                    dp[0] = 0;
                    ++ignoreCnt;
                break;
                case '*':
                    for (int j = ignoreCnt; j <= slen; ++j) {
                        if (dp[j]) {
                            memset(dp + j, 1, slen - j + 1);
                        }
                    }
                break;
                default:
                    for (int j = slen; j > ignoreCnt; --j) 
                        dp[j] = dp[j - 1] && ch == s[j - 1];
                    dp[0] = 0;
                    ++ignoreCnt;
            }
            if (ignoreCnt > slen) return false;
        }
        
        return dp[slen];
    }
};

int main() {
    Solution solution;
    solution.isMatch(
        "a",
        "aa");
}
