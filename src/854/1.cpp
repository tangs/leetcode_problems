#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void allPossible(vector<TreeNode*>& ret, vector<bool>& cur, const int sum, const int rCnt, const int rDest) {
        if (!sum && rCnt == rDest) {
            // todo
            TreeNode* head = new TreeNode(0);
            vector<TreeNode*> nodes = { head };
            for (bool val : cur) {
                auto node = new TreeNode(0);
                if (val) {
                    nodes.back()->right = node;
                } else {
                    nodes.pop_back();
                    nodes.back()->left = node;
                    nodes.pop_back();
                }
                nodes.push_back(node);
            }

            ret.push_back(head);
            return;
        }
        if (rCnt < rDest) {
            cur.push_back(true);
            allPossible(ret, cur, sum + 1, rCnt + 1, rDest);
            cur.pop_back();
        }
        if (sum > 0) {
            cur.push_back(false);
            allPossible(ret, cur, sum - 1, rCnt, rDest);
            cur.pop_back();
        }
    }
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if (!(N & 1)) return {};
        int rDest = (N - 1) >> 1;
        vector<TreeNode*> ret;
        vector<bool> cur;
        allPossible(ret, cur, 0, 0, rDest);
        return ret;
    }
};

int main() {
    Solution solution;
    solution.allPossibleFBT(7);
}