#include <math.h>
#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    bool isSameChar(const string& str) {
        int len = str.size();
        char ch = str[0];
        for (int i = 0; i < len; ++i) if (ch != str[i]) return false;
        return true;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (!words.size()) return {};
        unordered_set<string> words_set;
        words_set.insert(words.begin(), words.end());

        bool dp_ch[26];
        memset(dp_ch, 0, sizeof(dp_ch));
        int min_len = INT_MAX;
        int max_len = 0;
        for (auto& word: words) {
            int len = word.size();
            if (len && min_len > len) min_len = len;
            if (len == 1) dp_ch[word[0] - 'a'] = 1;
            if (len > max_len) max_len = len;
        }

        vector<string> ret;
        if (!max_len) return ret;
        
        bool dp[max_len][max_len];
        for (auto& word: words) {
            int len = word.size();
            if (len <= min_len) continue;
            bool isSame = isSameChar(word);
            if (dp_ch[word[0] - 'a'] && isSame) {
                ret.push_back(move(word));
                continue;
            }
            // bool dp[len][len];
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < len; ++i) {
                int str_len = i + 1;
                for (int j = 0; j < len - i; ++j) {
                    int col = i + j;
                    dp[j][col] = 0;
                    string str = word.substr(j, str_len);
                    if (i != len - 1 && words_set.find(str) != words_set.end()) {
                        dp[j][col] = 1;
                    } else {
                        for (int k = 0; k < i; ++k) {
                            if (dp[j][j + k] + dp[j + k + 1][col] == 2) {
                                dp[j][col] = 1;
                                break;
                            }
                        }
                    }

                    if (j == 0 && i < len - 1 && dp[j][col] && 
                    words_set.find(word.substr(i + 1, len - i - 1)) != words_set.end()) {
                        ret.push_back(move(word));
                        goto end1;
                    }
                }
            }

            if (dp[0][len - 1]) 
                ret.push_back(move(word));
end1:
            ;
        }
        return ret;
    }
};

int main() {
    vector<string> words = {
        "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"
    };
    Solution solution;
    auto ret = solution.findAllConcatenatedWordsInADict(words);
    return 0;
}