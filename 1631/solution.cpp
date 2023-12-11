#include "vector"

class Solution {
public:
    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        const int rows = heights.size();
        const int columns = heights[0].size();
        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(columns + 1));



        return dp[rows][columns];
    }
};

int main() {

}
