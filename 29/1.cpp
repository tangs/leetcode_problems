#include <limits.h>
#include <stdlib.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            if (divisor == -1) return INT_MAX;
        }
        if (divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;

        int ret = 0;
        int sign = ((dividend ^ divisor) & 0x80000000) ? -1 : 1;
        long long num1 = abs((long long)dividend);
        long long num2 = abs((long long)divisor);

        while (num1 >= num2) {
            long long tmp = num2;
            int n = 1;
            for(;;) {
                if (tmp & 0x40000000 || (tmp << 1) > num1) break;
                tmp <<= 1;
                n <<= 1;
            }
            ret += n;
            if (tmp == num1) break; 
            num1 -= tmp;
        }
        return ret * sign;
    }
};

int main() {
    Solution solution;
    solution.divide(-2147483648, 2);
}
