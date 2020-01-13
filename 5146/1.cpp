#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> strs;
        int len = text.size();
        // int hlen = len >> 1;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 2; j <= len; j += 2) {
                int len1 = j - i;
                // if (len1 > hlen) break;
                
                int hlen1 = len1 >> 1;
                bool issame = true;
                for (int k = 0; k < hlen1; ++k) {
                    if (text[i + k] != text[i + k + hlen1]) {
                        issame = false;
                        break;
                    }
                }
                if (issame) 
                    strs.insert(text.substr(i, len1));
            }
        }
        return strs.size();
    }
};

int main() {
    Solution so;
    so.distinctEchoSubstrings("leetcodeleetcode");
}

