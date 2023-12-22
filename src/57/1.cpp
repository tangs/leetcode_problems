#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        
        if (len == 0) {
            vector<vector<int>> ret { newInterval };
            return ret;
        }
        vector<vector<int>>::iterator it = intervals.begin();
        vector<vector<int>>::iterator end = intervals.end();
        int s = newInterval[0], e = newInterval[1];
        // int s1 = -1;

        vector<vector<int>>::iterator its = it;
        vector<vector<int>>::iterator ite = end; 

        while (it != end) {
            if (e < ((*it)[0])) {
                ite = it;
                break;
            }
            if (s > ((*it++)[1])) {
                its = it;
            }
        }

        if (its == end) {
            intervals.push_back(newInterval);
        } else if (its == ite) {
            intervals.insert(its, newInterval);
        } else {
            int ds = min((*its)[0], s);
            int de = max(e, ((*(ite - 1))[1]));
            intervals.erase(its, ite);
            intervals.insert(its, { ds, de });
        }
        return intervals;
    }
};

int main() {
    vector<vector<int>> data = {
        { 1, 5 }
    };
    vector<int> insert = {
        2, 3
    };
    Solution solution;
    solution.insert(data, insert);
}
