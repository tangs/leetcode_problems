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

        int dp[len + 1];
        dp[0] = 1;
        for (int i = 1; i <= len; ++i) {
            dp[i] = 0;
            string str = s.substr(0, i);
            if (wordSet.find(str) != wordSet.end()) {
                wordMap[i].insert(move(str));
                dp[i] = 1;
            }
            for (int j = 1; j < i; ++j) {
                if (!dp[j]) continue;
                string str = s.substr(j, i - j);
                if (wordSet.find(str) == wordSet.end()) continue;
                string str1 = s.substr(0, j) + " " + str;
                wordMap[i].insert(move(str1));
                dp[i] = 1;
            }
        }
        auto& last = wordMap[len];
        return vector<string>(last.begin(), last.end());
    }
};

int main() {
    vector<string> wordDict = {
        "cat", "cats", "and", "sand", "dog"
    };
    Solution solution;
    solution.wordBreak("catsanddog", wordDict);
}