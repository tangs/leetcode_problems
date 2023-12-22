#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <stack>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x100 ? '1' : '0'), \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

using namespace std;

class Solution {
    void printHex(short mayable[9][9]) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                printf(BYTE_TO_BINARY_PATTERN" ", BYTE_TO_BINARY(mayable[i][j]));
            }
            printf("\n");
        }
    }

    void updateCanable(vector<vector<char>>& board, short canable[9][9]) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    canable[i][j] = 0x1FF;
                    int gr = i / 3;
                    int gc = j / 3;
                    for (int k = 0; k < 9; ++k) {
                        int hor = board[i][k] - '1';
                        int ver = board[k][j] - '1';

                        int cgr = gr * 3 + k / 3;
                        int cgc = gc * 3 + k % 3;
                        int group = board[cgr][cgc] - '1';
                        if (k != j && hor >= 0) {
                            canable[i][j] &= ~(1 << hor);
                        }
                        if (k != i && ver >= 0) {
                            canable[i][j] &= ~(1 << ver);
                        }
                        if (!(i == cgr && j == cgc) && group >= 0) {
                            canable[i][j] &= ~(1 << group);
                        }
                    }
                } else {
                    canable[i][j] = 0;
                }
            }
        }
    }

    short getCanable(vector<vector<char>>& board, int i, int j) {
        short bits = 0x1FF;
        int gr = i / 3;
        int gc = j / 3;
        for (int k = 0; k < 9; ++k) {
            int hor = board[i][k] - '1';
            int ver = board[k][j] - '1';

            int cgr = gr * 3 + k / 3;
            int cgc = gc * 3 + k % 3;
            int group = board[cgr][cgc] - '1';
            if (k != j && hor >= 0) {
                bits &= ~(1 << hor);
            }
            if (k != i && ver >= 0) {
                bits &= ~(1 << ver);
            }
            if (!(i == cgr && j == cgc) && group >= 0) {
                bits &= ~(1 << group);
            }
        }
        return bits;
    }

    bool deal(vector<vector<char>>& board, 
    vector<int>& idxs, int cur) {
        if (cur == idxs.size()) {
            return true;
        }
        int idx = idxs[cur];
        int r = idx >> 4;
        int c = idx & 0x0f;
        // int can = canable[r][c];
        int can = getCanable(board, r, c);
        if (!can) return false;
        for (int i = 0; i < 9; ++i) {
            if (!(can & (1 << i))) continue;
            // char old = board[r][c];
            board[r][c] = i + '1';
            if (deal(board, idxs, cur + 1)) return true;
            // board[r][c] = old;
        }
        board[r][c] = '.';
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // short canable[9][9];
        // memset(mayable, 0, sizeof(mayable));
        // updateCanable(board, canable);
        vector<int> idxs;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') idxs.push_back((i << 4) + j);
            }
        }
        deal(board, idxs, 0);
        // printHex(canable);
        int a = 3;
    }
};

int main() {
    vector<vector<char>> vecs = {
        // {'5','3','4','6','7','8','9','1','2'},
        // {'6','7','2','1','9','5','3','4','8'},
        // {'1','9','8','3','4','2','5','6','7'},
        // {'8','5','9','7','6','1','4','2','3'},
        // {'4','2','6','8','.','3','.','.','1'},
        // {'7','1','3','.','2','.','.','.','6'},
        // {'.','6','.','.','.','.','2','8','.'},
        // {'.','.','.','4','1','9','.','.','5'},
        // {'.','.','.','.','8','.','.','7','9'}
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution solution;
    solution.solveSudoku(vecs);
}