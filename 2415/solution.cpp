#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    std::vector<TreeNode*> curs;
    curs.push_back(root);

    auto need_revert = false;

    while (!curs.empty()) {
      std::vector<TreeNode*> nexts;

      if (need_revert) {
        const auto len = curs.size();
        for (auto i = 0; i < len / 2; ++i) {
          std::swap(curs[i]->val, curs[len - i - 1]->val);
        }
      }

      if (curs[0]->left == nullptr) break;

      for (auto cur: curs) {
        nexts.push_back(cur->left);
        nexts.push_back(cur->right);
      }

      curs.swap(nexts);
      need_revert = !need_revert;
    }

    return root;
  }
};

int main() {


}