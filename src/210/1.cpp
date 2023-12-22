#include <math.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
    enum {
        WHITE = 0,
        GRAY = 1,
        BLACK = 2,
    };
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& arr: prerequisites)
            adj[arr[0]].push_back(arr[1]);

        int color[numCourses];

        memset(color, 0, sizeof(color));
        vector<int> ret;

        std::function<bool(int)> dfs_visit;
        dfs_visit = [&] (int idx) {
            color[idx] = GRAY;
            for (int idx1: adj[idx]) {
                if (color[idx1] == GRAY) return false;
                if (color[idx1]) continue;
                if (!dfs_visit(idx1)) return false;
            }
            color[idx] = BLACK;
            ret.push_back(idx);
            return true;
        };
        
        for (int i = 0; i < numCourses; ++i)
            if (!color[i] && !dfs_visit(i)) return {};

        return ret;
    }
};

int main() {
    vector<vector<int>> pre = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2},
    };
    Solution solution;
    solution.findOrder(4, pre);
}