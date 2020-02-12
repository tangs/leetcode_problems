#include <vector>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> nodes;
        TreeNode* node = root;
        TreeNode *prev = NULL;
        TreeNode *node_fir = NULL;
        TreeNode *node_sec = NULL;

        long prev_val = INT64_MIN;
        while (node || nodes.size()) {
            while (node) {
                nodes.push(node);
                node = node->left;
            }
            node = nodes.top();
            nodes.pop();

            if (node->val <= prev_val) {
                if (node_fir) {
                    node_sec = node;
                    break;
                } else {
                    node_fir = prev;
                    node_sec = node;
                }
            }

            prev = node;
            prev_val = node->val;
            node = node->right;
        }
        if (!node_fir) return;
        swap(node_fir->val, node_sec->val);
    }
};

int main() {
    TreeNode node0(1), node1(2), node2(3);
    node0.left = &node2;
    node2.right = &node1;
    Solution solution;
    solution.recoverTree(&node0);
    return 0;
}