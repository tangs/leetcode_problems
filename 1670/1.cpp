#include <vector>
#include <stack>
#include <deque>

class FrontMiddleBackQueue {
  std::deque<int> head_;
  std::deque<int> tail_;
  void refresh() {
    const auto head_size = head_.size();
    const auto tail_size = tail_.size();

    if (head_size > tail_size) {
      tail_.push_front(head_.back());
      head_.pop_back();
    } else if (tail_size > head_size + 1) {
      head_.push_back(tail_.front());
      tail_.pop_front();
    }
  }
public:
  FrontMiddleBackQueue() {

  }

  void pushFront(const int val) {
    head_.push_front(val);
    refresh();
  }

  void pushMiddle(const int val) {
    if (head_.size() < tail_.size()) {
      head_.push_back(val);
    } else {
      tail_.push_front(val);
    }
  }

  void pushBack(const int val) {
    tail_.push_back(val);
    refresh();
  }

  int popFront() {
    const auto head_size = head_.size();
    const auto tail_size = tail_.size();

    if (head_size == 0 && tail_size == 0) return -1;

    int ret;
    if (head_size > 0) {
      ret = head_.front();
      head_.pop_front();
    } else {
      ret = tail_.front();
      tail_.pop_front();
    }
    refresh();

    return ret;
  }

  int popMiddle() {
    const auto head_size = head_.size();
    const auto tail_size = tail_.size();

    if (head_size == 0 && tail_size == 0) return -1;

    int ret;
    if (head_size < tail_size) {
      ret = tail_.front();
      tail_.pop_front();
    } else {
      ret = head_.back();
      head_.pop_back();
    }
    refresh();
    return ret;
  }

  int popBack() {
    const auto head_size = head_.size();
    const auto tail_size = tail_.size();

    if (head_size == 0 && tail_size == 0) return -1;
    int ret;
    if (tail_size > 0) {
      ret = tail_.back();
      tail_.pop_back();
    } else {
      ret = head_.back();
      head_.pop_back();
    }
    refresh();
    return ret;
  }
};

int main() {

}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */