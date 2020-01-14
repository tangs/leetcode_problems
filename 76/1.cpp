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

    inline bool isOk(unordered_map<int, int>& nums1, unordered_map<int, int>& nums2) {
        // for (int i = 0; i < 128; ++i) {
        //     if (nums1[i] && nums1[i] > nums2[i]) return false;
        // }
        if (nums2.size() < nums1.size()) return false;
        for (auto it: nums1) {
            if (it.second > nums2[it.first]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int tlen = t.size();
        // long bits = 0;
        int destNums[128];
        // unordered_map<int, int> destNums;
        memset(destNums, 0, sizeof(destNums));
        for (char ch: t) {
            ++destNums[ch];
        }

        int len = s.size();

        int min = INT_MAX;
        int dests = -1;
        int nums[128];
        memset(nums, 0, sizeof(nums));

        // unordered_map<int, int> nums;

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
                    --nums[s[i++]];
                    --len2;
                    if (!isOk(destNums, nums)) {
                        break;
                    }
                }
            }
        }
        // }
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