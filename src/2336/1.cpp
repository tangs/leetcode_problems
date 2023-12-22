#include <set>

class SmallestInfiniteSet {
  std::set <int> nums;
  int next = 1;
public:
  SmallestInfiniteSet() = default;

  int popSmallest() {
    if (nums.empty()) return next++;
    const auto it = nums.cbegin();
    const auto ret = *it;
    nums.erase(it);
    return ret;
  }

  void addBack(const int num) {
    if (num >= next) return;
    nums.insert(num);
  }
};

int main() {

}