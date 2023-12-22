#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
    inline vector<int> getVersions(string version) {
        vector<int> ret;
        int num = 0;
        for (char ch: version) {
            if (ch == '.') {
                ret.push_back(num);
                num = 0;
            } else num = num * 10 + ch - '0';
        }
        if (num) ret.push_back(num);
        while (ret.size() && ret.back() == 0) ret.pop_back();
        return ret;
    }
public:
    int compareVersion(string version1, string version2) {
        auto ver1 = getVersions(version1);
        auto ver2 = getVersions(version2);
        int len1 = ver1.size();
        int len2 = ver2.size();
        int len = min(len1, len2);
        for (int i = 0; i < len; ++i)
            if (ver1[i] != ver2[i]) return ver1[i] > ver2[i] ? 1 : -1;
        return len1 == len2 ? 0 : len1 > len2 ? 1 : -1;
    }
};

int main() {
    Solution solution;
    solution.compareVersion("0.1", "1.1");
}