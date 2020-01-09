#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        int dp[len2 + 1][len1 + 1];
        for (int i = 0; i <= len1; ++i) dp[0][i] = i;
        for (int i = 0; i <= len2; ++i) dp[i][0] = i;
        for (int i = 1; i <= len2; ++i) {
            for (int j = 1; j <= len1; ++j) {
                int lt = dp[i - 1][j - 1] + 1;
                int t = dp[i - 1][j] + 1;
                int l = dp[i][j - 1] + 1;
                if (word1[j - 1] == word2[i - 1]) {
                    // t--;
                    lt--;
                }
                int dest = min(min(t, l), lt);
                dp[i][j] = dest;
            }
        }

        // print dp info.
        // cout << "    ";
        // for (int j = 0; j < len1; ++j) {
        //     cout << word1[j] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i <= len2; ++i) {
        //     if (i) cout << word2[i - 1] << " ";
        //     else cout << "  ";
        //     for (int j = 0; j <= len1; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[len2][len1];
    }
};

int main() {
    Solution solution;
    solution.minDistance("teacher", "acheer");
}
