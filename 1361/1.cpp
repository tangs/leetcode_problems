#include <math.h>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int len = leftChild.size();
        unordered_map<int, int> idxs;
        for (int i = 0; i < len; ++i) {
            int left = leftChild[i];
            int right = rightChild[i];
            auto it = idxs.find(i);
            int val = it != idxs.end() ? it->second : -1;
            if (left != -1) {
                if (idxs.find(left) != idxs.end()) return false;
                if (val == left) return false;
                idxs[left] = i;
            }
            if (right != -1) {
                if (idxs.find(right) != idxs.end()) return false;
                if (val == right) return false;
                idxs[right] = i;
            }
        }
        return idxs.size() == n - 1;
    }
};