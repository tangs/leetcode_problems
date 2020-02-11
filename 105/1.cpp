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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
    int& p, int& i, optional<int> stop) {
        if (i < inorder.size() && inorder[i] != stop) {
            auto node = new TreeNode(preorder[p++]);
            node->left = build(preorder, inorder, p, i, node->val);
            ++i;
            node->right = build(preorder, inorder, p, i, stop);
            return node;
        }
        return NULL;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0, i = 0;
        return build(preorder, inorder, p, i, nullopt);
    }
};

int main() {
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };
    Solution solution;
    solution.buildTree(preorder, inorder);
}