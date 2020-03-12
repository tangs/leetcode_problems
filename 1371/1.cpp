#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int maxval = 0;
        int val = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            switch (ch) {
                case 'a': val ^= 1; break;
                case 'e': val ^= 1 << 1; break;
                case 'i': val ^= 1 << 2; break;
                case 'o': val ^= 1 << 3; break;
                case 'u': val ^= 1 << 4; break;
            }
            if (m.find(val) == m.end()) m[val] = i;
            else maxval = max(maxval, i - m[val]);
        }
        return maxval;
    }
};

int main() {
    Solution solution;
    solution.findTheLongestSubstring("amntyyaw");
}