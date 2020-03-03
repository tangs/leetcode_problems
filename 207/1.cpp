#include <math.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& arr: prerequisites)
            adj[arr[1]].push_back(arr[0]);

        int color[numCourses];
        // int b[numCourses];
        // int f[numCourses];
        int pi[numCourses];
        // int time = 0;

        memset(pi, -1, sizeof(pi));
        memset(color, 0, sizeof(color));

        std::function<bool(int)> dfs_visit;
        dfs_visit = [&] (int idx) {
            color[idx] = 1;
            for (int idx1: adj[idx]) {
                pi[idx1] = idx;
                if (color[idx1] == 1) return false;
                if (color[idx1]) continue;
                if (!dfs_visit(idx1)) return false;
            }
            color[idx] = 2;
            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (color[i]) continue;
            // pi[i] = -1;
            if (!dfs_visit(i)) return false; 
        }

        unordered_set<int> heads;
        for (int i = 0; i < numCourses; ++i) if (pi[i] == -1) heads.insert(i);
        if (!heads.size()) return false;

        memset(color, 0, sizeof(color));
        for (int i: heads) {
            if (!dfs_visit(i)) return false; 
        }

        return true;
    }
};

int main() {
    vector<vector<int>> pres = {
        {0,2},
        {1,2},
        {2,0}
    };
    Solution solution;
    solution.canFinish(3, pres);
}