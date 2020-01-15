#include <vector>
#include <utility>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
    bool deal(vector<vector<char>>& board, const string& word, 
    unordered_set<int>& poses, int m, int n, int pos) {
        if (poses.find(pos) != poses.end()) return false;
        poses.insert(pos);
        int desetlen = word.size();
        int poslen = poses.size();
        if (desetlen == poslen) return true;

        int r = pos >> 16;
        int c = pos % (1 << 16);

        static vector<pair<int, int>> dfs = {
            { 0, 1 },
            { 0, -1 },
            { 1, 0 },
            { -1, 0}
        };

        char dest = word[poslen];
        for (auto& it : dfs) {
            int x = r + it.first;
            int y = c + it.second;
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == dest) {
                if (deal(board, word, poses, m, n, (x << 16) + y)) return true;
            }
        }
        poses.erase(poses.find(pos));
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (!word.size()) return true;
        int m = board.size();
        if (!m) return false;
        int n = board[0].size();
        if (!n) return false;

        char f = word[0];

        unordered_set<int> poses;
        // vector<int> starts;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // if (board[i][j] == f) starts.push_back((i << 16) + j);
                if (board[i][j] == f) {
                    poses.clear();
                    if (deal(board, word, poses, m, n, (i << 16) + j)) return true;
                }

            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    Solution solu;
    solu.exist(board, "ABCCED");
}
