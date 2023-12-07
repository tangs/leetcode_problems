#include <vector>
#include <unordered_set>

class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::unordered_set<int>> du_adj(n);
        std::vector<std::unordered_set<int>> adj(n);

        for (const auto& connection: connections) {
            const auto from = connection[0];
            const auto to = connection[1];

            adj[from].insert(to);
            du_adj[from].insert(to);
            du_adj[to].insert(from);
        }

        std::vector<bool> visited(n);
        std::vector<int> citys = {0};
        visited[0] = true;

        int ans = 0;

        while (citys.size()) {
            std::vector<int> next_citys;
            for (const auto from: citys) {
                for (const auto to: du_adj[from]) {
                    if (visited[to]) continue;
                    if (adj[from].count(to) > 0) ++ans;
                    visited[to] = true;
                    next_citys.push_back(to);
                }
            }
            citys.swap(next_citys);
        }

        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> connections0{{0,1},{1,3},{2,3},{4,0},{4,5}};
    Solution solution;
    auto ret0 = solution.minReorder(6, connections0);

    return 0;
}