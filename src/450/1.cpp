#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        TreeNode** prev = &root;
        TreeNode* node = root;

        while (node) {
            if (node->val == key) {
                if (!node->left) {
                    *prev = node->right;
                } else if (!node->right) {
                    *prev = node->left;
                } else {
                    auto p1 = node;
                    auto left = p1->right;
                    if (!left->left) {
                        left->left = node->left;
                    } else {
                        while (left->left) {
                            p1 = left;
                            left = left->left;
                        }
                        p1->left = left->right;
                        left->left = node->left;
                        left->right = node->right;
                    }
                    *prev = left;
                }
                break;
            } else if (node->val > key) {
                prev = &node->left;
                node = node->left;
            } else {
                prev = &node->right;
                node = node->right;
            }
        }
        return root;
    }
};

int main() {
    TreeNode root(5);
    TreeNode node1(3);
    TreeNode node2(6);
    TreeNode node3(2);
    TreeNode node4(4);
    TreeNode node5(7);
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.right = &node5;
    

    Solution solution;
    solution.deleteNode(&root, 3);
}