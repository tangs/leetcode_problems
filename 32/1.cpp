#include <stdio.h>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (!len) return 0;
        int leftNum = 0;
        std::stack<int> start;
        int ret = 0;
        // int dp[len];
        // memset(dp, 0, sizeof(dp));
        unordered_map<int, int> dp;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {       
                start.push(i);
                ++leftNum;
            } else {
                --leftNum;
                if (!start.size()) continue;
                int idx = start.top();
                start.pop();
                int len = i - idx + 1;
                dp[i] = len;
                if (idx > 0 && dp[idx - 1]) dp[i] += dp[idx - 1];
                ret = max(ret, dp[i]);
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    solution.longestValidParentheses("()(())");
}