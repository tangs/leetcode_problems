#include <vector>

class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        constexpr int NUM_LEN = 1001;
        int arr[NUM_LEN] {};
        for (const auto& trip: trips) {
            const auto numPassengers = trip[0];
            arr[trip[1]] += numPassengers;
            arr[trip[2]] -= numPassengers;
        }
        int num = 0;
        for (const auto value: arr) {
            num += value;
            if (num > capacity) return false;
        }
        return true;
    }
};

int main() {
}