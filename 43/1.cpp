#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        const char *p1 = num1.c_str();
        const char *p2 = num2.c_str();
        char ret[512];
        memset(ret, 0, sizeof(ret));
        char tmp[10];
        int cnt = 0;

        int s1 = (len1 - 4) / 4 * 4 + (len1 % 4);
        if (len1 < 4) s1 = 0;
        for (int i = 0; i < len1; i += 4, s1 -= 4) {
            s1 = max(0, s1);
            // int s1 = len1 - i * 4 - 1;
            int len = (len1 - i >= 4) ? 4 : len1 - i;
            strncpy(tmp, p1 + s1, len);
            tmp[len] = 0;
            int num1 = atoi(tmp);


            int s2 = (len2 - 4) / 4 * 4 + (len2 % 4);
            if (len2 < 4) s2 = 0;
            for (int j = 0; j < len2; j += 4, s2 -= 4) {
                s2 = max(0, s2);
                // int s2 = len2 - i * 4 - 1;
                int len = (len2 - j >= 4) ? 4 : len2 - j;
                strncpy(tmp, p2 + s2, len);
                tmp[len] = 0;
                int num2 = atoi(tmp);

                int value = num1 * num2;
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
            ret[i] = ch2 + '0';
            ret[j] = ch1 + '0';
        }
        if (cnt & 1) ret[len] += '0';

        return ret;
    }
};

int main() {
    Solution solution;
    string str1 = "2";
    string str2 = "3";
    solution.multiply(str1, str2);
}
