#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        cout << len << endl;
        int idx = len - 1;
        while (idx > 0 && prices[idx - 1] >= prices[idx]) --idx;
        if (idx < len - 1) prices.erase(prices.begin() + idx);
        len = prices.size();
        idx = 0;
        while (idx < len - 1 && prices[idx] >= prices[idx + 1]) ++idx;
        if (idx) prices.erase(prices.begin(), prices.begin() + idx);
        len = prices.size();
        cout << len << endl << endl;
        return 0;
        // while (prices.size() > 1 && prices[0] > prices > [1]) 
        len = prices.size();
        if (len <= 1) return 0;
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; ++i) {
            int minVal = prices[i];
            int maxVal = 0;
            for (int j = i + 1; j < len; ++j) {
                if (prices[j] < minVal) minVal = prices[j];
                int val = prices[j] - minVal;
                if (val > maxVal) maxVal = val;
                dp[i][j] = maxVal;
            }
        }

        int ret = 0;
        for (int i = 1; i < len; ++i) {
            int val = dp[0][i] + dp[i][len - 1];
            if (val > ret) ret = val;
        }
        return ret;
    }
};

int main() {
    vector<int> prices = {
        3,3,5,0,0,3,1,4
    };
    Solution solution;
    solution.maxProfit(prices);
}