#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        if (!len) return NULL;
        stack<TreeNode*> nodes;
        unordered_map<int, int> idxs;
        for (int i = 0; i < len; ++i) idxs[inorder[i]] = i;
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        nodes.push(root);
        while (postorder.size()) {
            auto lnode = nodes.top();
            nodes.pop();
            TreeNode* node = new TreeNode(postorder.back());
            postorder.pop_back();
            int idx = idxs[node->val];
            if (idx > idxs[lnode->val]) {
                lnode->right = node;
                nodes.push(lnode);
                nodes.push(node);
            } else {
                while (nodes.size() && idxs[nodes.top()->val] > idx) {
                    lnode = nodes.top();
                    nodes.pop();
                }
                lnode->left = node;
                nodes.push(node);
            }
        }
        return root;
    }
};

int main() {
    vector<int> inorder = {3, 2, 1};
    vector<int> postorder = inorder;
    Solution solution;
    solution.buildTree(inorder, postorder);
}