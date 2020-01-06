#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
    inline void deal(vector<int>& height, int& ret, int& cur, int s, int e) {
        int data = height[e - 1];
        for (int i = s; i < e; ++i) {
            int value = data - cur - height[i];
            ret += max(0, value);
        }
        cur = data;;
    }
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int lMax = 0;
        int rCur = 0;
        int ret = 0;
        for (int i = 1; i < len; ++i) {
            int ldata = height[lMax];
            int data = height[i];
            if (data >= ldata) {
                if (i - lMax > 1) {
                    for (int j = lMax + 1; j < i; ++j) {
                        int value = ldata - rCur - height[j];
                        ret += max(0, value);
                    }
                    rCur = 0;
                }
                lMax = i;                
            } else if (data && i > lMax + 2 && data <= height[i - 1]) {
                int prevData = height[i - 1];
                deal(height, ret, rCur, lMax + 1, i);
            }
        }
        deal(height, ret, rCur, lMax + 1, len);
        return ret;
    }
};

int main() {
    vector<int> vecs = {
        0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1, 2
    };
    Solution solution;
    solution.trap(vecs);
}
