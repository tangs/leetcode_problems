#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int size = nums.size();
        if (size < 4) return ret;
        sort(nums.begin(), nums.end());
        
        int len = size - 3;
        for (int i = 0; i < len;) {
            int value1 = nums[i];
            if (value1 > 0 && value1 >= target) break;
            int len1 = len + 1;
            if (value1 + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) goto endi;
            if (value1 + nums[len] + nums[len + 1] + nums[len + 2] < target) goto endi;
            for (int j = i + 1; j < len1;) {                
                int value2 = nums[j];
                int sum1 = value1 + value2;

                if (value2 > 0 && sum1 >= target) break;

                int p1 = j + 1;
                int p2 = size - 1;
                if (sum1 + nums[j + 1] + nums[j + 2] > target) goto endj;
                if (sum1 + nums[len + 1] + nums[len + 2] < target) goto endj;
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
                endj:
                while (j < len1 && nums[j] == nums[j + 1]) ++j;
                ++j;
            }
            endi:
            while (i < len1 && nums[i] == nums[i + 1]) ++i;
            ++i;
        }
        end:
        return ret;
    }
};

int main() {
    vector<int> nums = {
        { -4,-3,-2,-1,0,0,1,2,3,4 }
    };
    int target = 0;
    Solution solution;
    solution.fourSum(nums, target);
}
