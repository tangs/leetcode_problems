#include <vector>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            int bitRow = 0;
            int bitCol = 0;
            int bitGrid = 0;
            for (int j = 0; j < 9; ++j) {
                int num1 = board[i][j] - '0';
                if (num1 != -2) {
                    int bit = 1 << num1;
                    if (bitRow & bit) return false;
                    bitRow |= bit;
                }

                int num2 = board[j][i] - '0';               
                if (num2 != -2) {
                    int bit = 1 << num2;
                    if (bitCol & bit) return false;
                    bitCol |= bit;
                }

                int x = (i % 3) * 3 + j % 3;
                int y = i / 3 * 3 + j / 3;
                int num3 = board[y][x] - '0';
                if (num3 != -2) {
                    int bit = 1 << num3;
                    if (bitGrid & bit) return false;
                    bitGrid |= bit;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> vecs = {
        { '5','3','.','.','7','.','.','.','.' },
        { '6','.','.','1','9','5','.','.','.' },
        { '.','9','8','.','.','.','.','6','.' },
        { '8','.','.','.','6','.','.','.','3' },
        { '4','.','.','8','.','3','.','.','1' },
        { '7','.','.','.','2','.','.','.','6' },
        { '.','6','.','.','.','.','2','8','.' },
        { '.','.','.','4','1','9','.','.','5' },
        { '.','.','.','.','8','.','.','7','9' }
    };
    Solution solution;
    solution.isValidSudoku(vecs);
}