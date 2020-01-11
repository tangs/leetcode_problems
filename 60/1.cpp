#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        char tmp[n + 1];
        tmp[n] = 0;
        int least = k - 1;
        vector<char> nums;
        for (int i = 0; i < n; ++i) nums.push_back(i);
        for (int i = 0; i < n; ++i) {
            int idx = least / nums.size();
            char v = nums[idx];
            tmp[i] = v + '1';
            nums.erase(nums.begin() + idx);
            least -= v;
        }
        return tmp;
    }
};