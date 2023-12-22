#include <math.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
    inline bool valid(string& str, int s, int len) {
        int size = str.size();
        if (s + len > size) return false;
        if (len < 1) return false;
        if (len == 1) return true;
        if (len == 2) return str[s] != '0';
        if (len == 3) {
            int v = std::atoi(str.substr(s, len).c_str());
            return v >= 100 && v < 256;
        }
        return false;
    }
    void proc(vector<string>& ret, string& s, string& cur, int idx, int part) {
        int len = s.size();
        if (part == 3) {
            if (valid(s, idx, len - idx)) {
                cur += s.substr(idx, len - idx);
                ret.push_back(cur);
            }
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            if (valid(s, idx, i)) {
                int idxs = cur.size();
                cur += s.substr(idx, i);
                cur += '.';
                proc(ret, s, cur, idx + i, part + 1);
                cur.erase(cur.begin() + idxs, cur.end());
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string cur;
        proc(ret, s, cur, 0, 0);
        return ret;
    }
};

int main() {
    Solution solu;
    solu.restoreIpAddresses("25525511135");
}
