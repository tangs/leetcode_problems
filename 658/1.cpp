#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();

        int p = 0;
        int q = len - 1;
        while (p < q) {
            if (p == q - 1) {
                if (x- arr[p] > arr[q] - x) {
                    ++p;
                }
                break;
            }
            int mid = (p + q) / 2;
            int value = arr[mid];
            if (value == x) {
                p = mid;
                break;
            }
            if (value < x) {
                p = mid;
            } else {
                q = mid;
            }
        }

        // int s = max(0, q - k + 1);
        // int e = min(len - 1, q + k - 1);

        auto begin = arr.begin();
        auto end = arr.end();

        auto it = begin + p;
        auto lp = it;
        auto rp = it;

        for (int i = 1; i < k; ++i) {
            if (lp == begin) {
                rp++;
            } else if (rp == end - 1) {
                --lp;
            } else {
                int num1 = x - *(lp - 1);
                int num2 = *(rp + 1) - x;
                if (num1 <= num2) 
                    --lp;
                else 
                    ++rp;
            }
        }
        arr.erase(rp + 1, end);
        arr.erase(begin, lp);
        return arr;
        // vector<int> ret(lp, rp + 1);
        // return ret;
    }
};

int main() {
    vector<int> arr = {
        1,1,1,10,10,10
    };
    Solution solution;
    solution.findClosestElements(arr, 1, 9);
}
