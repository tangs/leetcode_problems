#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto& word: wordDict) wordSet.insert(move(word));

        int len = s.size();
        bool dp[len][len];
        // memset(dp, 0, sizeof(dp));

        for (int i = 0; i < len; ++i) 
            dp[i][i] = wordSet.find(s.substr(i, 1)) != wordSet.end();

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < len - i; ++j) {
                int col = i + j;
                for (int k = 0; k < i; ++k) {
                    if (dp[j][j + k] && dp[j + k + 1][col]) dp[j][col] = 1;
                }
                if (!dp[j][col] && wordSet.find(s.substr(j, i + 1)) != wordSet.end())
                    dp[j][col] = 1;
            }
        }

        for (int i =0; i <len; ++i) {
            for (int j = 0; j< len; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[0][len - 1];
    }
};

int main() {
    
}