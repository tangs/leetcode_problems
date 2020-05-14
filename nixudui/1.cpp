#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    int merge_sort(vector<int>& nums, int* tmp, int lo, int mid, int hi) {
        if (hi - lo < 2) return 0;
        int ret = merge_sort(nums, tmp, lo, (lo + mid) / 2, mid) +
            merge_sort(nums, tmp, mid, (mid + hi) / 2, hi);
        int left = lo, right = mid;
        int times = 0;
        for (int i = lo; i < hi; ++i) {
            if (right >= hi || (left < mid && nums[left] < nums[right])) {
                times += abs(i - left);
                tmp[i] = nums[left++];
            } else {
                times += abs(i - right);
                tmp[i] = nums[right++];
            }
        }
        times >>= 1;
        memcpy(nums.data() + lo, tmp + lo, (hi - lo) * sizeof(int));
        return ret + times;
    }
public:
    int reversePairs(vector<int>& nums) {
        int tmp[nums.size()];
        return merge_sort(nums, tmp, 0, nums.size() / 2, nums.size());
    }
};

int main() {
    vector<int> nums = {
        // 7,5,6,4
        1,4,3,2,76,3,6,83,3,3,7,8,34,2,36,7,21,45,8,1,9,62,35
    };
    Solution solution;
    int ret = solution.reversePairs(nums);
    return 0;
}