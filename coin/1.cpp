#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    int waysToChange(int n) {
        vector<int> coins = {1, 5, 10, 25};
        int dp[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            long val = 0;
            for (int coin: coins) {
                if (i - coin < 0) break;
                val += dp[i - coin];
            } 
            dp[i] = val % 1000000007;
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    solution.waysToChange(10);
}