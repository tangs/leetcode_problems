#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    void proc(vector<vector<int>>& roads, unordered_set<int>& idxs, 
        vector<int>& idxs1, vector<int>& destIdxs,
        unordered_map<int, int>& nums, unordered_map<int, vector<int>>& tos,
        int& min, int cur, int dest, int len) {
        if (len >= min) return;
        if (cur == dest) {
            if (len < min) {
                destIdxs = idxs1;
                destIdxs.push_back(cur);
                min = len;
            }
            return;
        }
        idxs.insert(cur);
        idxs1.push_back(cur);
        for (int dest1: tos[cur]) {
            if (idxs.find(dest1) == idxs.end()) {
                int len1 = nums[(cur << 16) + dest1];
                proc(roads, idxs, idxs1, destIdxs, nums, tos, min, dest1, dest, len + len1);
            }
        }
        idxs.erase(idxs.find(cur));
        idxs1.pop_back();
    }
public:
    string happy(int n, vector<vector<int>>& roads, vector<string>& codes) {
        int len = roads.size();
        if (!len) return "";
        unordered_map<int, int> nums;
        unordered_map<int, vector<int>> tos;
        unordered_set<int> idxs;
        vector<int> idxs1;
        vector<int> destIdxs;
        for (auto& vec: roads) {
            int s = vec[0];
            int e = vec[1];
            int len = vec[2];
            nums[(s << 16) + e] = len;
            nums[(e << 16) + s] = len;
            tos[s].push_back(e);
            tos[e].push_back(s);
        }
        int min = INT_MAX;
        proc(roads, idxs, idxs1, destIdxs, nums, tos, min, 11, 0, 0);
        string ret;
        for (int idx: destIdxs) {
            ret += codes[idx];
        } 
        return ret;
    }
};