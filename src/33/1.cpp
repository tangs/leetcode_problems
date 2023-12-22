#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (!size) return -1;
        int p = 0;
        int q = size - 1;
        while (p < q) {
            int m = (p + q) >> 1;
            int v = nums[m];
            if (v == target) return m;
            int l = nums[p];
            // if (l == target) return p;
            int r = nums[q];
            // if (r == target) return q;
            if (l < v) {
                if (target >= l && target <= v) {
                    q = m;
                } else {
                    p = m + 1;
                }
            } else {
                if (target >= l || target <= v) {
                    q = m;
                } else {
                    p = m + 1;
                }
            }
        }
        return nums[p] == target ? p : -1;
    }
};

int main() {
    vector<int> nums = {
        1
    };
    Solution solution;
    solution.search(nums, 0);
}