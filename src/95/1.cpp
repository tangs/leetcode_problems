#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void insert(TreeNode* head, TreeNode* node) {
        if (head->val > node->val) {
            if (head->left) insert(head->left, node);
            else head->left = node;
        } else {
            if (head->right) insert(head->right, node);
            else head->right = node;
        }
    }

    void handle(vector<TreeNode*>& ret, vector<int>& seq_push,
      vector<int>& seq_pop, const int push_idx, const int len) {
        if (!seq_push.size() && push_idx == len) {
            TreeNode* head = NULL;
            for (int v: seq_pop) {
                auto node = new TreeNode(v);
                if (!head) {
                    head = node;
                    ret.push_back(node);
                } else {
                    insert(head, node);
                }
            }
            return;
        }
        if (seq_push.size()) {
            int val = seq_push.back();
            seq_pop.push_back(val);
            seq_push.pop_back();
            handle(ret, seq_push, seq_pop, push_idx, len);
            seq_push.push_back(val);
            seq_pop.pop_back();
        }
        if (push_idx < len) {
            seq_push.push_back(push_idx + 1);
            handle(ret, seq_push, seq_pop, push_idx + 1, len);
            seq_push.pop_back();
        }
    }
 public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        vector<int> seq_push;
        vector<int> seq_pop;
        handle(ret, seq_push, seq_pop, 0, n);
        return ret;
    }
};

int main() {
    Solution solution;
    auto ret = solution.generateTrees(3);
    return 0;
}
