#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int tlen = t.size();
        int len = s.size();

        int destNums[128] = {0};
        for (char ch: t) ++destNums[ch];

        int min = len + 1;
        int dests = -1;

        int cnt = 0;
        for (int left = 0, right = 0; right < len; ++right) {
            // int idx1 = getIdx(s[right]);
            if (--destNums[s[right]] >= 0) ++cnt; else continue;
            while (cnt == tlen) {
                int len2 = right - left + 1;
                if (len2 == tlen) {
                    return s.substr(left, len2);
                }
                if (len2 < min) {
                    min = len2;
                    dests = left;
                }
                // int idx = getIdx(s[left++]);
                --len2;
                if (++destNums[s[left++]] > 0) --cnt;
            }
        }
        if (dests == -1) return "";
        else return s.substr(dests, min);
    }
};

int main() {
    Solution solu;
    solu.minWindow(
        "ADOBECODEBANC",
        "ABC"
    );
}
