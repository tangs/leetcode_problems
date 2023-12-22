#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int len = A.size();
        if (len < 2) return len;
        int ans = 1;
        int valid = 1;
        int dir = 0;
        for (int i = 1; i < len; ++i) {
            if (A[i] == A[i - 1]) {
                valid = 1;
                dir = 0;
                continue;
            }
            int cur_dir = A[i] > A[i - 1] ? 1 : -1;
            if (cur_dir == dir) valid = 2;
            else if (++valid > ans) ans = valid;
            dir = cur_dir;
        }
        return ans;
    }
};

int main() {
    vector<int> A = {
        9,4,2,10,7,8,8,1,9
    };
    Solution solution;
    solution.maxTurbulenceSize(A);
}