#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        char tmp[maxWidth + 1];
        tmp[maxWidth] = 0;
        int len = words.size();
        int s = 0;
        int e = 0;
        int cur = 0;
        while (e <= len) {
            bool isLast = e == len;
            if (!isLast) {
                int wordLen = words[e].size();
                if (cur + wordLen + (e - s - 1) < maxWidth) {
                    cur += wordLen;
                    ++e;
                    continue;
                }
            }

            int wordsCnt = e - s;
            if (wordsCnt) {
                int space;
                int addCnt;
                if (isLast || wordsCnt == 1) {
                    space = 1;
                    addCnt = 0;
                } else {
                    int spaceLen = (maxWidth - cur);
                    space = spaceLen / (wordsCnt - 1);
                    addCnt = spaceLen % (wordsCnt - 1);
                }
                memset(tmp, ' ', maxWidth);
                int idx = words[s].size();
                memcpy(tmp, words[s].c_str(), idx);
                // strcpy(tmp, words[s].c_str());
                for (int i = s + 1,j = 0; i < e; ++i, ++j) {
                    int sCnt = space;
                    if (j < addCnt) sCnt++;
                    // memset(tmp + idx, ' ', sCnt);
                    idx += sCnt;
                    int len = words[i].size();
                    memcpy(tmp + idx, words[i].c_str(), len);
                    idx += len;
                    // strcpy(tmp + idx, words[i].c_str());
                    // idx += words[i].size();
                }
                if (idx < maxWidth) {
                    // memset(tmp + idx, ' ', maxWidth - idx);
                }
                ret.push_back(tmp);
            }
            if (isLast) break;
            s = e;
            cur = 0;
        }
        return ret;
    }
};

int main() {
    vector<string> strs = {
        "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"
    };
    Solution solution;
    solution.fullJustify(strs, 20);
}