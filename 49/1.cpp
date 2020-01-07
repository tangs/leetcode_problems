#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> idxs;
        // int idx = 0;
        for (const string& str: strs) {
            string str1 = str;
            sort(str1.begin(), str1.end());
            auto it = idxs.find(str1);
            if (it != idxs.end()) {
                ret[it->second].push_back(str);
            } else {
                idxs[move(str1)] = ret.size(); 
                vector<string> strs1;
                strs1.push_back(str);
                ret.push_back(move(strs1));
            }
        }
        return ret;
    }
};

int main() {
    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    Solution solution;
    solution.groupAnagrams(strs);
}
