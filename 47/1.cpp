#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    void deal(vector<vector<int>>& ret, unordered_set<int>& idxs, 
      vector<int>& cur, vector<int>& nums) {
        int len = nums.size();
        if (cur.size() == len) {
            ret.push_back(cur);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (idxs.find(i) != idxs.end()) continue;
            int data = nums[i];
            cur.push_back(data);
            idxs.insert(i);

            deal(ret, idxs, cur, nums);

            cur.pop_back();
            idxs.erase(idxs.find(i));
            while(i < len - 1 && nums[i] == nums[i + 1]) ++i;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        unordered_set<int> idxs;
        vector<int> cur;
        deal(ret, idxs, cur, nums);
        return ret;
    }
};

int main() {
    vector<int> nums = {
        1, 1, 2
    };
    Solution solution;
    solution.permuteUnique(nums);
}