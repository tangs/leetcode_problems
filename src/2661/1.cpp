#include <vector>

class Solution {
public:
  int firstCompleteIndex(const std::vector<int>& arr, const std::vector<std::vector<int>>& mat) {
    const auto rows = mat.size();
    const auto cols = mat[0].size();
    const auto n = arr.size();

    std::vector<int> val_to_row(n + 1);
    std::vector<int> val_to_col(n + 1);

    for (auto i = 0; i < rows; ++i) {
      const auto& row_data = mat[i];
      for (auto j = 0; j < cols; ++j) {
        const auto val = row_data[j];

        val_to_row[val] = i;
        val_to_col[val] = j;
      }
    }

    std::vector<int> rows_count(rows);
    std::vector<int> cols_count(cols);

    for (int i = 0; i < n; ++i) {
      const auto val = arr[i];
      const auto row = val_to_row[val];
      const auto col = val_to_col[val];

      if (++rows_count[row] == cols) return i;
      if (++cols_count[col] == rows) return i;
    }

    return -1;
  }
};

int main() {
  const std::vector arr = {1,3,4,2};
  const std::vector<std::vector<int>> mat = {{1,4}, {2,3}};
  Solution solution;
  auto ret = solution.firstCompleteIndex(arr, mat);
  return 0;
}