#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
    inline int compare(const string& s1, const string& s2, int idx, int n) {
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i + idx]) return false;
        }
        return true;
    }

    bool deal1(unordered_set<int>& idxs, unordered_map<int, vector<int>>& container, 
      int dest, int wl, int size) {
        int idxlen = idxs.size();
        if (size == idxlen) {
            return true;
        } else {
            auto it = container.find(dest);
            auto end = container.end();
            if (it != end) {
                auto& second = it->second;
                int len = second.size();
                if (!len) return false;

                auto idxEnd = idxs.end();
                int idx = -1;
                for (int i = 0; i < len; ++i) {
                    int idx1 = second[i];
                    if (idxs.find(idx1) == idxEnd) {
                        idx = idx1;
                        break;
                    }
                }
                if (idx == -1) return false;
        
                idxs.insert(idx);
                bool ret = deal1(idxs, container, dest + wl, wl, size);
                idxs.erase(idx);

                return ret;
            }
            return false;
        }
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = words.size();
        if (!size) return {};
        int slen = s.size();
        int wl = words[0].size();
        int subStringLen = size * wl;
        if (slen < subStringLen) return {};

        if (wl == 1) {
            char ch = s[0];
            bool allSame = true;
            for (int i = 0; i < slen; ++i) {
                if (s[i] != ch) {
                    allSame = false;
                    break;
                }
            }
            for (const string& word: words) {
                if (word[0] != ch) {
                    allSame = false;
                    break;
                }
            }
            if (allSame) {
                int len = slen - size + 1;
                vector<int> ret;
                for (int i = 0; i < len; ++i) {
                    ret.push_back(i);
                }
                return ret;
            }
        }

        unordered_map<int, vector<int>> container;
        int len = slen - wl;
        for (int j = 0; j < size; ++j) {
            for (int i = 0; i <= len; ++i) {
                if (compare(words[j], s, i, wl)) {
                    // rowIdxs[j][i] = true;
                    container[i].push_back(j);
                }
            }
            // if (!rowIdxs[j].size()) return {};
        }
        unordered_set<int> idxs;
        vector<int> rets;
        // unordered_set<int> ret1;
        unordered_map<string, bool> retCache;
        len = slen - subStringLen;
        for (int i = 0; i <= len; ++i) {
            string substr = s.substr(i, subStringLen);
            auto it = retCache.find(substr);
            if (it != retCache.end()) {
                if (it->second) rets.push_back(i);
                continue;
            }
            bool ret = deal1(idxs, container, i, wl, size);
            if (ret) rets.push_back(i);
            retCache.insert(pair<string, bool>(move(substr), ret));
        }
        // vector<int> ret(ret1.begin(), ret1.end());
        return move(rets);
    }
};

int main() {
    vector<string> strs = {
        "ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab",
        "ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab",
        "ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab",
        "ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab",
        "ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab",
        "ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab",
        "ba","ab","ba","ab","ba","ab","ba","ab","ba"
    };
    string str = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababababababababab";
    str = "barfoothefoobarman";
    strs = { "foo","bar" };

    str = "barfoofoobarthefoobarman";
    strs = { "bar","foo","the" };

    str = "wordgoodgoodgoodbestword";
    strs = { "word","good","best","word" };

    Solution solution;
    solution.findSubstring(str, strs);
}
