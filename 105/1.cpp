#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
        unordered_map<int, int>& idx_inorder, int& uesed, stack<int>& parents_idx) {
            int psize = preorder.size();
            if (psize <= uesed) return NULL;
            auto val = preorder[uesed];
            // auto it = find(inorder.begin(), in)
            int idx = idx_inorder[val];
            auto node = new TreeNode(val);
            int parent_idx = parents_idx.top();
            if (uesed < psize - 1) {
                parents_idx.push(idx);
                auto next_val = preorder[uesed + 1];
                auto next_idx = idx_inorder[next_val];
                if (next_idx < idx) {
                    node->left = build(preorder, inorder, idx_inorder, ++uesed, parents_idx);
                }
                parents_idx.pop();

                if (uesed < psize - 1) {
                    auto next_val2 = preorder[uesed + 1];
                    auto next_idx2 = idx_inorder[next_val2];

                    if (next_idx2 > idx && next_idx2 < parent_idx) {
                        node->right = build(preorder, inorder, idx_inorder, ++uesed, parents_idx);
                    }
                }
            }
            return node;
        }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> idx_inorder;
        stack<int> parents_idx;
        int idx = 0;
        parents_idx.push(inorder.size());
        int len = inorder.size();
        for (int i = 0; i < len; ++i) idx_inorder[inorder[i]] = i;
        auto ret = build(preorder, inorder, idx_inorder, idx, parents_idx);
        return ret;
    }
};

int main() {
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };
    Solution solution;
    solution.buildTree(preorder, inorder);
}