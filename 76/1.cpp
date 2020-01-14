#include <stdlib.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        long bits = 0;
        for (char ch: t) {
            int num = ch >= 'a' ? ch - 'a' + 32 : ch - 'A';
            bits |= 1l << num;
        }

        int len = s.size();
        long dp[len + 1];
        // memset(dp, 0, sizeof(dp));
        int min = INT_MAX;
        int dests = -1;
        for (int i = 0; i < len; ++i) {
            dp[i] = 0;
            for (int j = i; j < len; ++j) {
                // long bit = s[j] - 'A';
                char ch = s[j];
                int num = ch >= 'a' ? ch - 'a' + 32 : ch - 'A';
                dp[j + 1] = dp[j] | (1l << num);
                int len = j - i + 1;
                if (len < min && (bits ^ dp[j + 1] & bits) == 0) {
                    min = len;
                    dests = i;
                }
            }
        }
        if (dests == -1) return "";
        else return s.substr(dests, min);
    }
};

int main() {
    Solution solu;
    solu.minWindow("ADOBECODEBANC", "ABC");
}