#include <set>

using namespace std;

class Solution {
public:
    bool foo(set<int>& s, int z) {
        for (int val: s) if (!(z % val)) return true;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            auto it2 = it;
            for (++it2; it2 != s.rend(); ++it2) {
                int val = *it - *it2;
                if (val && s.find(val) == s.end()) {
                    s.insert(val);
                    return foo(s, z);
                }
            }
        }
        return false;
    }
    bool canMeasureWater(int x, int y, int z) {
        if (x == 1 || y == 1) return true;
        set<int> s;
        s.insert(x);
        s.insert(y);
        return foo(s, z);
    }
};

int main() {
    Solution solution;
    solution.canMeasureWater(2, 6, 5);
}