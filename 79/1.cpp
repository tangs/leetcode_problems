#include <vector>
#include <utility>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
    bool deal(vector<vector<char>>& board, const string& word, 
    bool *dp, int m, int n, int x, int y, int poslen) {
        int pos = x * n + y;
        if (dp[pos]) return false;
        dp[pos] = true;
        ++poslen;
        int desetlen = word.size();
        if (desetlen == poslen) return true;

        char dest = word[poslen];
        if (x > 0 && board[x - 1][y] == dest) {
            if (deal(board, word, dp, m, n, x - 1, y, poslen)) return true;
        }
        if (x < m - 1 && board[x + 1][y] == dest) {
            if (deal(board, word, dp, m, n, x + 1, y, poslen)) return true;
        }
        if (y > 0 && board[x][y - 1] == dest) {
            if (deal(board, word, dp, m, n, x, y - 1, poslen)) return true;
        }
        if (y < n - 1 && board[x][y + 1] == dest) {
            if (deal(board, word, dp, m, n, x, y + 1, poslen)) return true;
        }

        dp[pos] = false;
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
        bool dp[m * n];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == f) {
                    if (deal(board, word, dp, m, n, i, j, 0)) 
                        return true;
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
