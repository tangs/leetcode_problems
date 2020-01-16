#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        int dest = 1;
        for (int i = 1; i <= n; ++i) {
            int start = ret.size() - 1;
            for (int j = 0; j < dest; ++j) {
                ret.push_back(ret[start - j] | dest);
            }
            dest <<= 1;
        }
        return ret;
    }
};

int main() {
    Solution solu;
    solu.grayCode(4);
}
