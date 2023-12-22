#include <vector>

using namespace std;

class Solution {
    bool handle(vector<int>& target, vector<int>& arr, int max_val, int max, long dest_sum, long sum) {
        if (max > max_val || sum > dest_sum) return false;
        if (max == max_val && sum == dest_sum) {
            vector<int> arr1 = arr;
            sort(arr1.begin(), arr1.end());
            return target == arr1;
        }
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            if (arr[i] == target[i]) continue;
            if (arr[i] > target[i]) return false;
            int tmp = arr[i];
            arr[i] = sum;
            if (handle(target, arr, max_val, sum, dest_sum, (sum << 1) - tmp)) return true;
            arr[i] = tmp;
        }
        return false;
    }
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if (!n) return true;
        sort(target.begin(), target.end());
        vector<int> arr(n, 1);
        int max_val = INT_MIN;
        long dest_sum = 0;
        for (int val: target) {
            max_val = max(max_val, val);
            dest_sum += val;
        }
        return handle(target, arr, max_val, 1, dest_sum, n);
    }
};

int main() {
    vector<int> target = {
        // 1,1384,1,1,10,2767,379,1,217,1
        // 9,3,5
        29799,253,1,4016,1007,1,1,1,14936,7528
        // 8, 5
    };
    Solution solu;
    bool ret = solu.isPossible(target);
    return 0;
}