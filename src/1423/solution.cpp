#include <vector>

class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        const int n = cardPoints.size();
        int cur = 0;

        for (int i = 0; i < k; ++i) {
            cur += cardPoints[i];
        }

        int l = k - 1;
        int r = n - 1;
        int ret = cur;

        for (int i = 0; i < k; ++i) {
            cur += -cardPoints[l--] + cardPoints[r--];
            ret = std::max(ret, cur);
        }
        return ret;
    }
};

int main() {
    // std::vector<int> cardPoints = {1,2,3,4,5,6,1};
    std::vector<int> cardPoints = {100,40,17,9,73,75};
    Solution solution;
    solution.maxScore(cardPoints, 3);
    return 0;
}