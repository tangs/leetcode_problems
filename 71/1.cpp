#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
    inline void deal(vector<string>& paths, const string& path, int s, int len) {
        string dir = path.substr(s, len);
        if (dir == "..") {
            if (paths.size()) paths.pop_back();
        } else if (dir != ".") {
            paths.push_back(move(dir));
        }
    }
public:
    string simplifyPath(string path) {
        int len = path.size();
        vector<string> paths;
        int s = 0;
        int e;
        while ((e = path.find('/', s)) != string::npos) {
            int len = e - s;
            if (len > 0) {
                deal(paths, path, s, len);
            }
            s = e + 1;
        }

        int len2 = len - s;
        if (len2 > 0) {
            deal(paths, path, s, len2);
        }

        char tmp[len + 1];
        int idx = 0;
        tmp[idx++] = '/';
        for (auto& str: paths) {
            int len1 = str.size();
            strcpy(tmp + idx, str.c_str());
            idx += len1;
            tmp[idx++] = '/';
        }
        if (idx > 1)
            tmp[idx - 1] = 0;
        else
            tmp[idx] = 0;
        return tmp;
    }
};

int main() {
    Solution solu;
    solu.simplifyPath("/");
}
