#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> adj;
        for (auto& ticket: tickets)
            adj[ticket[0]][ticket[1]]++;
        unordered_map<string, bool> visited;

        vector<string> ret;
        ret.push_back("JFK");

        function<bool()> dfs;
        dfs = [&] () {
            if (ret.size() == tickets.size() + 1) return true;
            auto city = ret.back();
            auto& nexts = adj[city];
            for (auto& it: nexts) {
                if (!it.second) continue;
                it.second--;
                ret.push_back(it.first);
                if (dfs()) return true;
                ret.pop_back();
                it.second++;
            }
            return false;
        };
        dfs();

        return ret;
    }
};

int main() {
    vector<vector<string>> tickets = {
        {"MUC","LHR"},
        {"JFK","MUC"},
        {"SFO","SJC"},
        {"LHR","SFO"}
    };
    Solution solution;
    auto ret = solution.findItinerary(tickets);
    return 0;
}