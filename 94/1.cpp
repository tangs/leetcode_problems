#include <math.h>
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ret;
        stack<TreeNode*> nodes;
        TreeNode* node = root;
        for (;;) {
            if (node->left) {
                nodes.push(node);
                node = node->left;
                continue;
            }
        right:
            ret.push_back(node->val);
            if (node->right) {
                node = node->right;
                continue;
            }
            if (!nodes.size()) break;
            node = nodes.top();
            nodes.pop();
            goto right;
        }
        return ret;
    }
};

int main() {
    TreeNode node1(1), node2(2), node3(3);
    node1.right = &node2;
    node2.left = &node3;
    Solution solu;
    solu.inorderTraversal(&node1);
}
