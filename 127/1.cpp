#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
    int getDiffrentCnt(const string& str1, const string& str2) {
        int size = str1.size();
        if (str2.size() != size) return 0;
        int ret = 0;
        for (int i = 0; i < size; ++i) if (str1[i] != str2[i]) ++ret;
        return ret;
    }

    int getMaxLen(vector<string>& wordList, bool* used,
    const string& cur, const string& dest, int len) {
        if (cur == dest) return len;
        int ret = INT_MAX;
        int size = wordList.size();
        for (int i = 0; i < size; ++i) {
            if (used[i]) continue;
            auto& word = wordList[i];
            if (getDiffrentCnt(word, cur) != 1) continue;
            used[i] = true;
            int ret1 = getMaxLen(wordList, used, word, dest, len + 1);
            used[i] = false;
            if (ret1) ret = min(ret, ret1);
        }
        return ret == INT_MAX ? 0 : ret;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool used[wordList.size()];
        return getMaxLen(wordList, used, beginWord, endWord, 1);
    }
};

int main() {
    std:vector<string> words = {
        "hot","dot","dog","lot","log","cog"
    };
    Solution solution;
    solution.ladderLength("hit", "cog", words);
}