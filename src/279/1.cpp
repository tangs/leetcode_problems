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
public:
    int numSquares(int n) {
        // int ret = n;

        static int squares[46340];
        static bool first = true;
        if (first) {
            int len = sizeof(squares) / sizeof(squares[0]);
            for (int i = 0; i < len; ++i) {
                squares[i] = i * i;
            }
            first = false;
        }

        unordered_map<int, bool> visited;

        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        visited[n] = true;
        while (q.size()) {
            auto val = q.front();
            q.pop();
            // if (!val.first) return val.second;
            int sqrt_val = sqrt(val.first);
            for (int i = 1; i <= sqrt_val; ++i) {
                int left = val.first - squares[i];
                if (!left) return val.second + 1;
                if (visited[left]) continue;
                q.push(make_pair(left, val.second + 1));
                visited[left] = true;
            }
        }

        return n;
    }
};

int main() {
    Solution solution;
    solution.numSquares(15468);
}