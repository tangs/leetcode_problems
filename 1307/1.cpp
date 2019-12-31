#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;

class Solution {
public:
    inline int sum(const unordered_map<char, int>& l, unordered_map<char, int>& values) {
        int num = 0;
        auto end = l.end();
        for (auto it = l.begin(); it != end; ++it) {
            num += values[it->first] * it->second;
        }
        return num;
    }

    inline bool check(const unordered_map<char, int>& l, const unordered_map<char, int>& r, 
      unordered_map<char, int>& values) {
        return sum(l, values) == sum(r, values);
    }

    bool deal(const unordered_map<char, int>& l, const unordered_map<char, int>& r, 
      const vector<char>& letter, unordered_map<char, int>& values, unordered_set<char>& idxs) {
        int idx = values.size();
        if (idxs.size() == idx) {
            return check(l, r, values);
        }
        char ch = letter[idx];
        for (int i = 0; i <= 9; ++i) {
            if (idxs.find(i) != idxs.end()) continue;
            // values.push
        }
    }

    bool isSolvable(vector<string>& words, string result) {
        unordered_map<char, int> ldata;
        unordered_map<char, int> rdata;
        set<char> letter;
        int maxl = 0;
        for (auto& word: words) {
            int ratio = 1;
            max(maxl, (int)word.size());
            for (auto ch: word) {
                ldata[ch] += ratio;
                letter.insert(ch);
            }
            ratio *= 10;
        }
        if (maxl > result.size()) return false;
        int ratio = 1;
        for (auto ch: result) {
            rdata[ch] += ratio;
            letter.insert(ch);
        }
        ratio *= 10;

        unordered_map<char, int> values;
        unordered_set<char> idxs;

        // return deal(ldata, rdata, letter, values, idxs);
    }
};