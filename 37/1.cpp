#include <vector>
#include <stdlib.h>
#include <stack>

using namespace std;

class Solution {
    inline bool deal(vector<vector<char>>& board, int x, int y, short& bits) {
        char value = board[y][x];
        if (value != '.') {
            bits &= ~(1 << (value - '1'));
            return true;
        }
        return false;
    }

    inline short getMayableNum(vector<vector<char>>& board, int x, int y, char& num) {
        if (board[y][x] != '.') {
            num = 0;
            return 0;
        }
        short bits = 0x1ff;
        num = 9;
        int r = y / 3;
        int c = x / 3;
        for (int i = 0; i < 9; ++i) {
            if (i == x) continue;
            if (deal(board, i, y, bits) || 
                deal(board, x, i, bits) ||
                deal(board, c * 3 + (i % 3), r * 3 + i / 3, bits)) {
                --num;
            }
        }
        if (!num) bits = -1;
        return bits;
    }

    inline int getFirst(short bits) {
        for (int i = 0; i < 9; ++i) {
            if (bits & (1 << i)) return i;
        }
        return -1;
    }

    inline bool deal2(vector<vector<char>>& board, short mayable[9][9], int x, int y) {
        char num;
        short bits = getMayableNum(board, x, y, num);
        mayable[y][x] = bits;
        if (num == 1) {
            char value = getFirst(bits) + '1';
            updateValue(board, mayable, x, y, value);
            return true;
        }
        return false;
    }

    void updateValue(vector<vector<char>>& board, short mayable[9][9], 
      int x, int y, char value) {
        board[y][x] = value;
        char num;
        for (int i = y - 1; i >= 0; --i) {
            if (deal2(board, mayable, x, i)) break;
        }
        for (int i = x - 1; i >= 0; --i) {
            if (deal2(board, mayable, i, y)) break;
        }
        int r = y / 3;
        int c = x / 3;
        int cur = (y - r) * 3 + c;
        for (int i = 0; i < 9; ++i) {
            if (i == cur) continue;
            if (deal2(board, mayable, r * 3 + (i % 3), c * 3 + i / 3)) break;
        }
    }

    inline bool updateMayable(vector<vector<char>>& board, short mayable[9][9]) {
        char num;
        bool ret = true;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                short bits = getMayableNum(board, j, i, num);
                mayable[i][j] = bits;
                if (bits == -1) ret = false;
                if (num == 1) {
                    int value = getFirst(bits) + '1';
                    updateValue(board, mayable, j, i, value);
                }
            }
        }
        return ret;
    }

    int check(vector<vector<char>>& board) {
        int ret = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
            }
        }
    }

    bool deal3(vector<vector<char>>& board, short mayable[9][9], int x, int y, int least) {
        if (!least) {
            if (check(board) == 0) {
                return true;
            }
            return false;
        }
        for (int i = y; i < 9; ++i) {
            for (int j = x; j < 9; ++j) {
                if (board[i][j] == '.') {
                    int bits = mayable[i][j];
                    for (int i = 0; i < 9; ++i) {
                        if (bits & (1 << i)) {
                            board[i][j] = i;
                        }
                    }
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        short mayable[9][9];
        // memset(mayable, 0, sizeof(mayable));
        updateMayable(board, mayable);
        return;
    }
};

int main() {
    vector<vector<char>> vecs = {
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