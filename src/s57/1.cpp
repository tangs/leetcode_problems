#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        
        int max = (target + 1) >> 1;
        int l = 0;
        int r = 1;

        int sum = 1;
        cur.push_back(1);
        while (l < r && r <= max) {
            if (sum == target) {
                if (r - l > 1) ret.emplace_back(cur.begin() + l++, cur.end());
                sum -= l;
            } else if (sum < target) {
                cur.push_back(++r);
                sum += r;
            } else {
                sum -= ++l;
            } 
        }

        return ret;
    }
};

int main() {
    Solution solution;
    solution.findContinuousSequence(9);
}