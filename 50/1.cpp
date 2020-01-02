#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

class Solution {
public:
    long long getMax2(long long i) {
        long long ret = 1;
        // int idx = 0;
        while (ret < i) {
            ret <<= 1;
            // ++idx;
        }
        return ret >> 1;
    }

    double get(map<long long, double>& dp, double x, long long i) {
        if (i == 0) return 1.0;
        if (i == 1) return x;
        auto it = dp.find(i);
        if (it != dp.end()) return dp[i];
        int num1 = getMax2(i);
        double ret = get(dp, x, num1) * get(dp, x, i - num1);
        dp[i] = ret;
        return ret;
    }

    double myPow(double x, int n) {
        if (x == 0.0) return 0;
        // double dp[n + 1];
        map<long long, double> dp;
        // memset(dp, 0, sizeof(dp));
        long long n1 = abs((long long)n);
        double ret = get(dp, x, n1);
        if (n < 0) ret = 1.0 / ret;
        return ret;
    }
};

int main() {
    Solution solution;
    solution.myPow(0.00001, 2147483647);
}