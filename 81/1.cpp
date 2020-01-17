#include <vector>

using namespace std;

class Solution {
    bool contains(vector<int>& nums, int target, int left, int right) {
        if (left > right) return false;
        if (left == right) return nums[left] == target;
        int mid = (left + right) >> 1;
        int value = nums[mid];
        if (target == value) return true;
        if (target > value && target <= nums[right]) {
            return contains(nums, target, mid + 1, right);
        }
        if (contains(nums, target, left, mid - 1)) return true;
        return contains(nums, target, mid + 1, right);
    }
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (!len) return false;
        int l = 0;
        int r = len - 1;
        return contains(nums, target, l, r);
    }
};

int main() {
    vector<int> nums = {
        1, 3
    };
    Solution solu;
    solu.search(nums, 3);
}
