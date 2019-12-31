#include <vector>
#include <unordered_set>
#include <tuple>

using namespace std;

class Solution {
public:
    bool deal(vector<int>& arr, unordered_set<long long>& idxs, int start) {
        if (start < 0 || start >= arr.size()) return false;
        int val = arr[start];
        if (!val) return true;
        long long key = ((long long)start << 32) + val;
        if (idxs.find(key) != idxs.end()) return false;
        idxs.insert(key);
        if (deal(arr, idxs, start + val)) return true;
        if (deal(arr, idxs, start - val)) return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        unordered_set<long long> idxs;
        return deal(arr, idxs, start);
    }
};

int main() {
    vector<int> arr = {
        4,2,3,0,3,1,2
    };
    Solution solution;
    solution.canReach(arr, 5);
}
