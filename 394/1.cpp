#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    string decode(const string& s, int& cur) {
        int len = s.size();
        if (cur >= len) return "";

        string str;
        int times = 0;
        if (isdigit(s[cur])) {
            while (s[cur] != '[')
                times = times * 10 + s[cur++] - '0';
            ++cur;
        }

        while (cur < len) {
            char ch = s[cur];
            if (isdigit(ch)) {
                str += decode(s, cur);
                continue;
            }
            switch(ch) {
                case ']': {
                    string ret;
                    for (int i = 0; i < times; ++i) ret += str;
                    cur++;
                    return ret;
                }
                default:
                    str += s[cur++];
            }
        }
        return str;
    }
public:
    string decodeString(string s) {
        int cur = 0;
        int len = s.size();
        stringstream ss;
        while (cur < len) {
            ss << decode(s, cur);
        }
        return ss.str();
    }
};

int main() {
    Solution solution;
    solution.decodeString("2[abc]3[cd]ef");
}