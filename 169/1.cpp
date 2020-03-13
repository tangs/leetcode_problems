#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums.size() / 2;
        unordered_set<int, int> s;
        for (int num: nums) if (s[1] > val) return num;
        return 0;
    }
};