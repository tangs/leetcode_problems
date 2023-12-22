#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int len = nums.size();
        int p = 0;
        int q = len - 1;
        // int dest = -1;
        while (p <= q) {
            int mid = (p + q) / 2;
            int value = nums[mid];
            if (value == target) {
                int s = mid;
                int e = mid;
                while (s > 0 && nums[s] == nums[s - 1]) --s;
                while (e < len - 1 && nums[e] == nums[e + 1]) ++e;
                return { s, e };
            }
            if (value < target) {
                p = mid + 1;
            } else {
                q = mid - 1;
            }
        }
        return { -1, -1 };
    }
};

int main() {
    vector<int> nums = {
        2, 2
    };
    int target = 2;
    Solution solution;
    solution.searchRange(nums, target);
}
