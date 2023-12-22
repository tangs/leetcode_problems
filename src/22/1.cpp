#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
    void deal(vector<string>& ret, char* str, int lcnt, int cur, int n) {
        if (lcnt < 0) return;
        if (cur == n) {
            if (!lcnt) ret.push_back(str);
            return;
        }
        str[cur] = '(';
        deal(ret, str, lcnt + 1, cur + 1, n);
        str[cur] = ')';
        deal(ret, str, lcnt - 1, cur + 1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        int len = n << 1;
        char str[len + 1];
        str[len] = 0;
        deal(ret, str, 0, 0, len);
        return ret;
    }
};

int main() {
    Solution solution;
    solution.generateParenthesis(3);
}
