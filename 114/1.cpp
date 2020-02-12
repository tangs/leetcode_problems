#include <vector>
#include <optional>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* traverse(TreeNode* node, TreeNode* prev) {
        if (!node) return prev;
        auto right = node->right;
        prev->right = node;
        prev = node;
        prev = traverse(node->left, prev);
        prev = traverse(right, prev);
        node->left = NULL;
        if (prev == node) node->right = NULL;
        return prev;
    }
public:
    void flatten(TreeNode* root) {
        traverse(root, root);
    }
};

int main() {
    TreeNode node1(0), node2(2), node3(3);
    // node1.left = &node2;
    // node1.right = &node3;
    Solution solution;
    solution.flatten(&node1);
    return 0;
}