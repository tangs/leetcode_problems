#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // if (!k) return nums.size() > 1;
        int n = nums.size();
        if (n < 2) return false;
        int dp[n];
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + nums[i];
            if ((!k && !dp[i]) || (k && dp[i] % k == 0)) 
                return true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 2; j < n; ++j) {
                dp[j] -= nums[i];
                if ((!k && !dp[i]) || (k && dp[i] % k == 0)) 
                    return true;
            }
        }
        return false;
    }
};

int main() {
    // vector<int> arr = {23,2,6,4,7};
    vector<int> arr = {1, 0};
    Solution solution;
    solution.checkSubarraySum(arr, 2);
}