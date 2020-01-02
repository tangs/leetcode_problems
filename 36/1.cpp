#include <vector>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, bool> numsRow;
        unordered_map<int, bool> numsCol;
        unordered_map<int, bool> numsGrid;
        for (int i = 0; i < 9; ++i) {
            numsRow.clear();
            numsCol.clear();
            numsGrid.clear();
            for (int j = 0; j < 9; ++j) {
                char num1 = board[i][j];
                if (num1 == '.') continue;
                if (numsRow[num1]) 
                    return false;
                int num2 = board[j][i];
                if (num2 == '.') continue;
                if (numsCol[num2]) 
                    return false;
                int x = (i % 3) * 3 + j % 3;
                int y = i / 3 * 3 + j / 3;
                int num3 = board[y][x];
                if (num3 == '.') continue;
                if (numsGrid[num3]) 
                    return false;
                numsRow[num1] = true;
                numsCol[num2] = true;
                numsGrid[num3] = true;
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