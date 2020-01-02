#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return;
        // set<int> set1;
        vector<int> set1;
        int idx = -1;
        set1.push_back(nums[len - 1]);
        for (int i = len - 2; i >= 0; --i) {
            set1.push_back(nums[i]);
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        sort(set1.begin(), set1.end());
        // int size = set1.size();
        if (set1.size() > 1) {
            if (idx != -1) {
                auto end = set1.end();
                for (auto it = set1.begin(); it != end; ++it) {
                    if (nums[idx] < *it) {
                        nums[idx++] = *it;
                        set1.erase(it);
                        break;
                    }
                }
            } else {
                idx = 0;
            }
            // for (int i = 0; i < idx; ++i) --it;
            for (int num: set1) {
                nums[idx++] = num;
            }
        }

    }
};

int main() {
    vector<int> nums = {
        3, 2, 1
    };
    Solution solution;
    solution.nextPermutation(nums);
}
