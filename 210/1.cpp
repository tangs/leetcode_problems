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
        int pi[numCourses];

        memset(color, 0, sizeof(color));

        std::function<bool(int)> dfs_visit;
        dfs_visit = [&] (int idx) {
            color[idx] = GRAY;
            for (int idx1: adj[idx]) {
                pi[idx1] = idx;
                if (color[idx1] == GRAY) return false;
                if (color[idx1]) continue;
                if (!dfs_visit(idx1)) return false;
            }
            color[idx] = BLACK;
            return true;
        };
        
        vector<int> ret;

        for (int i = 0; i < numCourses; ++i) {
            if (color[i]) continue;
            pi[i] = -1;
            if (!dfs_visit(i)) return ret;
        }

        unordered_set<int> heads;
        for (int i = 0; i < numCourses; ++i) if (pi[i] == -1) heads.insert(i);

        if (!heads.size()) return ret;
        memset(color, 0, sizeof(color));

        std::function<void(int)> dfs_visit1;
        dfs_visit1 = [&] (int idx) {
            color[idx] = GRAY;
            for (int idx1: adj[idx]) {
                if (!color[idx1]) dfs_visit1(idx1);
            }
            color[idx] = BLACK;
            ret.push_back(idx);
        };
        for (int idx: heads) {
            dfs_visit1(idx);
        }

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