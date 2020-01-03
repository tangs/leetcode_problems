#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if (!size) return 1;
        bool tmp[size];
        memset(tmp, 0, sizeof(tmp));
        for (int num: nums) {
            if (num > 0 && num <= size)
                tmp[num - 1] = true;
        }
        for (int i = 0; i < size; ++i)
            if(!tmp[i]) return i + 1;
        return size + 1;
    }
};
