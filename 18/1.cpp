#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
    inline int calcsum(vector<int>& nums, int poses[4]) {
        int sum = 0;
        for (int i = 0; i < 4; ++i) sum += nums[poses[i]];
        return sum;
    }

    inline int getlessIdx(vector<int>& nums, int poses[4], int target) {
        for (int i = 0; i < 4; ++i) if (nums[poses[i]] < target) return i;
        return -1;
    }

    inline int getmoreIdx(vector<int>& nums, int poses[4], int target) {
        for (int i = 0; i < 4; ++i) if (nums[poses[i]] > target) return i;
        return -1;
    }

    inline int getNextIdx(vector<int>& nums, int poses[4], int idx, bool ignoreNext) {
        int curIdx = poses[idx];
        int cur = nums[curIdx];
        int max = nums.size();
        if (!ignoreNext && idx < 3) max = poses[idx + 1];
        for (int i = curIdx + 1; i < max; ++i) if (nums[i] != cur) return i;
        return -1;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int size = nums.size();
        if (size < 4) return ret;
        sort(nums.begin(), nums.end());
        
        int len = size - 3;
        for (int i = 0; i < size - 3;) {
            int len1 = len + 1;
            int value1 = nums[i];
            for (int j = i + 1; j < len1;) {                
                int value2 = nums[j];
                int sum1 = value1 + value2;
                int p1 = j + 1;
                int p2 = size - 1;
                while (p1 < p2) {
                    int sum = sum1 + nums[p1] + nums[p2];
                    if (sum == target) {
                        ret.push_back({ value1, value2, nums[p1], nums[p2] });
                        while (p1 < p2 && nums[p1] == nums[p1 + 1]) ++p1;
                        while (p1 < p2 && nums[p2] == nums[p2 - 1]) --p2;
                        ++p1;
                        --p2;
                    } else if (sum < target) {
                        while (p1 < p2 && nums[p1] == nums[p1 + 1]) ++p1;
                        ++p1;
                    } else {
                        while (p1 < p2 && nums[p2] == nums[p2 - 1]) --p2;
                        --p2;
                    }
                }
                while (j < len1 && nums[j] == nums[j + 1]) ++j;
                ++j;
            }
            while (i < len1 && nums[i] == nums[i + 1]) ++i;
            ++i;
        }
        end:
        return ret;
    }
};

int main() {
    vector<int> nums = {
        { -5,5,4,-3,0,0,4,-2 }
    };
    int target = 4;
    Solution solution;
    solution.fourSum(nums, target);
}
