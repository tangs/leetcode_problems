#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int dis = INT_MAX;
        int len = nums.size() - 2;
        for (int i = 0; i < len; ++i) {
            int prev = i + 1;
            int next = len + 1;
            int data = nums[i];
            while (prev < next) {
                // int pd = nums[prev];
                // int nd = nums[next];
                int sum = data + nums[prev] + nums[next];
                if (sum == target) return target;
                int dis1 = sum - target;
                if (abs(dis1) < abs(dis)) dis = dis1;
                if (sum < target) {
                    while (prev < next && nums[prev + 1] == data) ++prev;
                    ++prev;
                } else {
                    while (prev < next && nums[next - 1] == data) --next;
                    --next;
                }
            }
        }
        return dis + target;
    }
};

int main() {
    vector<int> data = { -1, 2, 1, -4 };
    Solution solution;
    solution.threeSumClosest(data, 1);
}