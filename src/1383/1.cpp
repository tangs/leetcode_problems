#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> vals(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            vals[i][0] = efficiency[i];
            vals[i][1] = speed[i];
        }
        sort(vals.rbegin(), vals.rend());

        long ret = 0;
        long speeds = 0;
        priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> que;
        for (auto& vec: vals) {
            // if ((long)vec[0] * (speeds + vec[1]) <= ret) continue;
            que.push({vec[1], vec[0]});
            speeds += vec[1];
            if (--k < 0) {
                speeds -= que.top()[0];
                que.pop();
            }
            ret = max(ret, speeds * vec[0]);
        }
        return ret % 1000000007;
    }
};

int main() {
    vector<int> speed = {
        // 2,10,3,1,5,8
        // 2, 8, 2
        1,4,1,9,4,4,4
    };
    vector<int> efficiency = {
        // 5,4,3,9,7,2
        // 2, 7, 1
        8,2,1,7,1,8,4
    };
    Solution solution;
    solution.maxPerformance(7, speed, efficiency, 6);
}

