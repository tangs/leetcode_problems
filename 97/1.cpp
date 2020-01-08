#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    bool check1(const string& s1, const string& s2, const string& s3, 
        bool* idxs, int n, int x, int y) {
        int sIdx = x + y;
        if (sIdx == s3.size()) return true;
        int idx = y * n + x;
        if (idxs[idx]) return false;
        idxs[idx] = true;
        char ch = s3[sIdx];
        if (x < s1.size() && s1[x] == ch) {
            if (check1(s1, s2, s3, idxs, n, x + 1, y)) return true;
        }
        if (y < s2.size() && s2[y] == ch) {
            if (check1(s1, s2, s3, idxs, n, x, y + 1)) return true;
        }
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int BUFF_SIZE = 128;
        int len1 = s1.size();
        int len2 = s2.size();
        int wordslen = len1 + len2;
        int len3 = s3.size();
        if (len3 == 0 && wordslen == 0) return true;
        if (wordslen != len3) return false;
        if (len1 && len2) {
            if (s3[0] != s1[0] && s3[0] != s2[0]) return false;
            if (s3[len3 - 1] != s1[len1 - 1] && s3[len3 - 1] != s2[len2 - 1]) return false;
        }
        
        int n = len1 + 1;
        int len = n * (len2 + 1);
        // int dp[len2 + 1][n];
        // bool dp[len];
        // memset(dp, 0, sizeof(dp));
        bool idxs[len];
        memset(idxs, 0, sizeof(idxs));

        return check1(s1, s2, s3, idxs, n, 0, 0);
    }
};

int main() {
    Solution solution;
    solution.isInterleave(
        "cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc", 
        "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb", 
        "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb");
}
