#include <vector>

class Solution {
    long long ans_ = 0;
    int seats_ = 0;
public:
    long long dfs(const std::vector<std::vector<int>>& adjs, bool* visited, int index) {
        visited[index] = true;
        int people = 1;
        const auto& adj = adjs[index];
        for (const auto next: adj) {
            if (visited[next]) continue;
            people += dfs(adjs, visited, next);
        }
        if (index == 0) return ans_;
        ans_ += (people + seats_ - 1) / seats_;
        return people;
    }

    long long minimumFuelCost(const std::vector<std::vector<int>>& roads, int seats) {
        ans_ = 0;
        seats_ = seats;
        const auto n = roads.size() + 1;
        bool visited[n];
        memset(visited, 0, sizeof visited);

        std::vector<std::vector<int>> adjs(n);
        for (const auto& road: roads) {
            const auto a = road[0], b= road[1];
            adjs[a].push_back(b);
            adjs[b].push_back(a);
        }

        return dfs(adjs, visited, 0);
    }
};

int main() {
    std::vector<std::vector<int>> raods1 = {{0,1},{0,2},{0,3},};
    std::vector<std::vector<int>> raods2 = {{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}};
    std::vector<std::vector<int>> raods3 = {};

    Solution solution;
    auto ret1 = solution.minimumFuelCost(raods1, 5);
    auto ret2 = solution.minimumFuelCost(raods2, 2);
    auto ret3 = solution.minimumFuelCost(raods3, 1);
    return 0;
}