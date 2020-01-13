#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int dp[n];
        if (n == 1) return "1";
        vector<char> nums;
        dp[0] = 0;
        dp[1] = 1;
        nums.push_back('1');
        nums.push_back('2');
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] * i;
            nums.push_back('1' + i);
        }

        char tmp[n + 1];
        tmp[n] = 0;
        int least = k - 1;
        for (int i = 0; i < n; ++i) {
            int base = dp[n - i - 1];
            int idx = base ? least / base : 0;
            tmp[i] = nums[idx];
            least -= base * idx;
            nums.erase(nums.begin() + idx);
        }
        return tmp;
    }
};

int main() {
    Solution solution;
    solution.getPermutation(3, 5);
}
