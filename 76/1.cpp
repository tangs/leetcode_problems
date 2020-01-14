#include <stdlib.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int bits = 0;
        for (char ch: t) {
            bits |= 1 << (ch - 'A');
        }

        int len = s.size();
        int dp[len + 1];
        // memset(dp, 0, sizeof(dp));
        int min = INT_MAX;
        int dests = -1;
        for (int i = 0; i < len; ++i) {
            dp[0] = 0;
            for (int j = i; j < len; ++j) {
                int bit = s[j] - 'A';
                dp[j + 1] = dp[j] | (1 << bit);
                int len = j - i + 1;
                if (len < min && ((bits ^ dp[j + 1]) & bits) == 0) {
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