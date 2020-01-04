#include <string>
#include <string.h>

using namespace std;

class Solution {
    int multiply1(int dp[100], int num1, int num2) {
        if (!num1 || !num2) return 0;
        int key = (num1 << 4) + num2;
        if (dp[key]) return dp[key];
        int ret = 0;
        for (int i = 0; i < 4; ++i) {
            if (num2 & (1 << i)) {
                ret += num1 << i;
            }
        }
        dp[key] = ret;
        return ret;
    }
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        const char *p1 = num1.c_str();
        const char *p2 = num2.c_str();
        char ret[512];
        memset(ret, 0, sizeof(ret));

        int dp[160];
        memset(dp, 0, sizeof(dp));
        
        int cnt = 0;
        for (int i = 0; i < len1; ++i) {
            char number1 = num1[len1 - i - 1] - 48;
            for (int j = 0; j < len2; ++j) {
                char number2 = num2[len2 - j - 1] - 48;
                char value = number1 * number2;
                // int value = multiply1(dp, number1, number2);
                int start = i + j;
                int add = 0;
                while (value || add) {
                    ret[start] += (value % 10) + add;
                    if (ret[start] >= 10) {
                        ret[start] %= 10;
                        add = 1;
                    } else {
                        add = 0;
                    }
                    cnt = max(cnt, ++start);
                    value /= 10;
                }
            }
        }
        if (!cnt) return "0";
        ret[cnt] = 0;
        int len = cnt >> 1;
        for (int i = 0; i < len; ++i) {
            int j = cnt - i - 1;
            char ch1 = ret[i];
            char ch2 = ret[j];
            ret[i] = ch2 + 48;
            ret[j] = ch1 + 48;
        }
        if (cnt & 1) ret[len] += 48;

        return ret;
    }
};

int main() {
    Solution solution;
    string str1 = "2";
    string str2 = "3";
    solution.multiply(str1, str2);
}
