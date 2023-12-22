#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void deal(vector<vector<int>>& ret, vector<int>& candidates, vector<int>& nums,
      int surplus, int idx) {
        int len = candidates.size();
        for (int i = idx; i < len; ++i) {
            int data = candidates[i];
            if (data > surplus) break;
            nums.push_back(data);
            if (data == surplus) {
                ret.push_back(nums);
            } else {
                deal(ret, candidates, nums, surplus - data, i + 1);
            }
            nums.pop_back();
            if (data == surplus) break;
            while (i < len - 1 && candidates[i] == candidates[i + 1]) ++i; 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> nums;
        deal(ret, candidates, nums, target, 0);
        return ret;
    }
};

int main() {
    // 1 1 2 5 6 7 10
    vector<int> nums = {
       10, 1, 2, 7, 6, 1, 5
    };
    int target = 8;
    Solution solution;
    solution.combinationSum2(nums, target);
}
