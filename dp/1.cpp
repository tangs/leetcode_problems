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

int main() {
    unordered_set<int> coins = {2, 3, 5};
    int dp[100];
    dp[0] = 0;
    for (int i = 1; i < 100; ++i) {
        if (coins.count(i)) dp[i] = 1;
        else {
            dp[i] = INT_MAX;
            for (int coin: coins) {
                if (i - coin > 0 && dp[i - coin] != -1) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
            if (dp[i] == INT_MAX) dp[i] = -1;
        }
        cout << i << ":" << dp[i] << endl;
    }
    
}