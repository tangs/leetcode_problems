#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    inline bool isOk(int* nums1, int* nums2) {
        for (int i = 0; i < 128; ++i) {
            if (nums1[i] && nums1[i] > nums2[i]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int tlen = t.size();
        int destNums[128];
        memset(destNums, 0, sizeof(destNums));
        for (char ch: t) {
            ++destNums[ch];
        }

        int len = s.size();

        int min = INT_MAX;
        int dests = -1;
        int nums[128];
        memset(nums, 0, sizeof(nums));

        int i = 0;
        for (int j = 0; j < len; ++j) {
            ++nums[s[j]];
            if (isOk(destNums, nums)) {
                int len1 = j - i + 1;
                for (int len2 = len1; len2 >= tlen; ) {
                    if (len2 == tlen) {
                        return s.substr(i, len2);
                    }
                    if (len2 < min) {
                        min = len2;
                        dests = i;
                    }
                    char ch = s[i++];
                    --nums[ch];
                    --len2;
                    if (nums[ch] < destNums[ch]) {
                        break;
                    }
                }
            }
        }
        if (dests == -1) return "";
        else return s.substr(dests, min);
    }
};

int main() {
    Solution solu;
    solu.minWindow(
        "aaaaaaaaaaaabbbbbcdd",
        "abcdd"
    );
}