#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        unordered_set<string> wordSet;
        for (auto& word: wordDict) wordSet.insert(move(word));
        
        unordered_map<int, unordered_set<string>> wordMap;

        bool dp[len][len];
        for (int i = 0; i < len; ++i) {
            string str = s.substr(i, 1);
            dp[i][i] = wordSet.find(str) != wordSet.end();
            if (dp[i][i]) {
                wordMap[(i << 16) | i].insert(move(str));
            }
        }

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < len - i; ++j) {
                int col = i + j;
                dp[j][col] = 0;
                int idx = (j << 16) | col;
                unordered_set<string> strs;
                for (int k = 0; k < i; ++k) {
                    if (dp[j][j + k] && dp[j + k + 1][col]) {
                        dp[j][col] = 1;
                        int idx1 = (j << 16) | (j + k);
                        int idx2 = ((j + k + 1) << 16) | col;
                        auto& vec1 = wordMap[idx1];
                        auto& vec2 = wordMap[idx2];
                        for (auto str1: vec1) {
                            string str;
                            for (auto str2: vec2) {
                                str = str1 + " " + str2;
                                strs.insert(move(str));
                            }
                        }
                    }
                }
                string str = s.substr(j, i + 1);
                if (wordSet.find(str) != wordSet.end()) {
                    // wordMap[idx].push_back(move(str));
                    strs.insert(move(str));
                    dp[j][col] = 1;
                }
                wordMap[idx] = move(strs);
            }
        }
        auto& lastStrs = wordMap[len - 1];
        return vector<string>(lastStrs.begin(), lastStrs.end());
    }
};

int main() {
    vector<string> wordDict = {
        "cat", "cats", "and", "sand", "dog"
    };
    Solution solution;
    solution.wordBreak("catsanddog", wordDict);
}