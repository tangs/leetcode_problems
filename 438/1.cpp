#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> need, window;
        for (char ch: p) need[ch]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s.size()) {
            char ch = s[right++];
            if (need.count(ch)) {
                if (++window[ch] == need[ch]) ++valid;
            }
            
            while (right - left >= p.size()) {
                if (right - left == p.size() && valid == need.size()) {
                    ans.push_back(left);
                    break;
                }
                char ch1 = s[left++];
                if (need.count(ch1)) {
                    if (window[ch1]-- == need[ch1]) --valid;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    solution.findAnagrams("cbaebabacd", "abc");
}