class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        const int max = 46340;
        if (x >= max * max) return max;
        // long ret = 0;
        // while (ret * ret <= x) ++ret;
        int l = 0, r = max;
        while (l < r) {
            int m = (l + r) >> 1;
            int v = m * m;
            if (v == x) 
                return m;
            if (v > x) {
                if ((m - 1) * (m - 1) <= x) 
                    return m - 1;
                r = m;
            } else {
                if ((m + 1) * (m + 1) > x) 
                    return m;
                l = m;
            }
        }
        return l;
    }
};

int main() {
    Solution solution;
    solution.mySqrt(9);
}
