#include <vector>
#include <stack>

class Solution {
public:
  int sumSubarrayMins(std::vector<int>& arr) {
    const auto n = static_cast<int>(arr.size());
    std::vector<int> lefts(n);
    std::vector<int> rights(n);
    std::stack<int> stack;

    for (int i = 0; i < n; ++i) {
      const auto val = arr[i];
      while (!stack.empty() && arr[stack.top()] > val) stack.pop();
      const auto left = stack.empty() ? -1 : stack.top();
      if (stack.empty() || val >= arr[stack.top()]) stack.push(i);
      lefts[i] = left;
    }

    stack = {};
    for (int i = n - 1; i >= 0; --i) {
      const auto val = arr[i];
      while (!stack.empty() && arr[stack.top()] >= val) stack.pop();
      const auto right = stack.empty() ? n : stack.top();
      if (stack.empty() || val >= arr[stack.top()]) stack.push(i);
      rights[i] = right;
    }

    auto sum = 0l;
    for (int i = 0; i < n; ++i) {
      const auto left = i - lefts[i];
      const auto right = rights[i] - i;
      sum = (sum + left * right * static_cast<long>(arr[i])) % 1000000007;
    }
    return sum;
  }
};

int main() {
  // std::vector arr = {3,   1,   2,   4,   1};
  std::vector arr = {3,   1,   2,   4};
  Solution solution;
  auto sum = solution.sumSubarrayMins(arr);
  return 0;
}