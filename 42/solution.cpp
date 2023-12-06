#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        const auto n = height.size();
        return 0;
    }
};

int main() {
    std::vector<int> hegith0 = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::vector<int> hegith1 = {4,2,0,3,2,5};

    Solution solution;
    auto ret0 = solution.trap(hegith0);
    auto ret1 = solution.trap(hegith1);

    return 0;
}
