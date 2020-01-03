#include <vector>

using namespace std;

class Solution {
public:
    void deal(vector<vector<int>>& ret, vector<int>& candidates, vector<int>& nums, int surplus) {
        int last = nums.size() > 0 ? nums.back() : -1;
        for (auto data: candidates) {
            if (data < last) continue;
            if (data > surplus) break;
            if (data == surplus) {
                nums.push_back(data);
                ret.push_back(nums);
                nums.pop_back();
                break;
            } else {
                nums.push_back(data);
                deal(ret, candidates, nums, surplus - data);
                nums.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> nums;
        deal(ret, candidates, nums, target);
        return ret;
    }
};

int main() {
    vector<int> nums = {
       8, 7, 4, 3
    };
    int target = 11;
    Solution solution;
    solution.combinationSum(nums, target);
}