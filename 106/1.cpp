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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
    int& i, int& p, optional<int> stop) {
        if (p >= 0 && inorder[i] != stop) {
            auto node = new TreeNode(postorder[p--]);
            node->right = build(inorder, postorder, i, p, node->val);
            --i;
            node->left = build(inorder, postorder, i, p, stop);
            return node;
        }
        return NULL;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = inorder.size() - 1, p = postorder.size() - 1;
        return build(inorder, postorder, i, p, nullopt);
    }
};

int main() {
    vector<int> postorder = { 9,15,7,20,3 };
    vector<int> inorder = { 9,3,15,20,7 };
    Solution solution;
    solution.buildTree(postorder, inorder);
}