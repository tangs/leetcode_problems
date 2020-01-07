
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
        for (int i = 0; i < len; ++i) {
            int data = arr[i];
            arr[i] = abs(data - x) + data;
        }
        sort(arr.begin(), arr.end(), [] (int a, int b) {
            return a < b;
        });
        return arr[k];
    }
};