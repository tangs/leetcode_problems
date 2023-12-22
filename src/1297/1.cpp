#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    inline int getLetterNum(const string& str) {
        int bit = 0;
        for (auto& ch: str) {
            bit |= 1 << ch - 'a';
        }
        int num = 0;
        while (bit) {
            num += bit & 1;
            bit >>= 1;
        }
        return num;
    }
    
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int len = s.size();
        int lastIdx = len - minSize;
        int max = 0;
        unordered_map<string, int> datas;
        for (int i = 0; i <= lastIdx; ++i) {
            string sub = s.substr(i, minSize);
            int num = getLetterNum(sub);
            if (num > maxLetters) continue;
            int cnt = ++datas[std::move(sub)];
            if (cnt > max) max = cnt;
        }
        return max;
    }
};

int main() {
    Solution solution;
    solution.maxFreq("abcde", 2, 3, 3);
}