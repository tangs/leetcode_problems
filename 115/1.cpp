#include <vector>
#include <string>

using namespace std;

class Solution {
    void handle(vector<vector<int>>& matches, int idx, int value, int& cnt) {
        if (idx == matches.size()) {
            ++cnt;
            return;
        }
        for (int idx1: matches[idx]) {
            if (idx1 <= value) continue;
            handle(matches, idx + 1, idx1, cnt);
        }
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> matches;
        int s_size = s.size();
        int t_size = t.size();
        int max = s_size;
        for (int i = t_size - 1; i >= 0; --i) {
            vector<int> arr;
            char ch = t[i];
            for (int j = 0; j < s_size; ++j) {
                if (ch == s[j]) arr.push_back(j);
            }
            if (!arr.size()) return 0;
            max = arr.back();
            matches.push_back(move(arr));
        }

        for (int i = 0; i < t_size / 2; ++i) {
            swap(matches[i], matches[t_size - 1 - i]);
        }

        int cnt = 0;
        handle(matches, 0, -1, cnt);
        return cnt;
    }
};

int main() {
    Solution solution;
    auto cnt = solution.numDistinct(
        "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc",
        "bcddceeeebecbc"
    );
    return 0;
}