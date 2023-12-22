#include <vector>
#include <string.h>
// #include <unordered_set>

using namespace std;

class Solution {
    void deal(vector<vector<int>>& ret, bool* idxs, 
      vector<int>& cur, vector<int>& nums) {
        int len = nums.size();
        if (cur.size() == len) {
            ret.push_back(cur);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (idxs[i]) continue;
            int data = nums[i];
            cur.push_back(data);
            idxs[i] = true;

            deal(ret, idxs, cur, nums);

            cur.pop_back();
            idxs[i] = false;
            while(i < len - 1 && nums[i] == nums[i + 1]) ++i;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        // unordered_set<int> idxs;
        int size = nums.size();
        bool bits[size];
        memset(bits, 0, sizeof(bits));
        vector<int> cur;
        deal(ret, bits, cur, nums);
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