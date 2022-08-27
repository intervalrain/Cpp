#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            int row[10] = {0};
            int col[10] = {0};
            int cell[10] = {0};
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    if (row[board[i][j] - '0'] == 1) return false;
                    row[board[i][j] - '0']++;
                }
                if (board[j][i] != '.'){
                    if (col[board[j][i] - '0'] == 1) return false;
                    col[board[j][i] - '0']++;
                }
                int x = (i/3) * 3 + j/3;
                int y = (i%3) * 3 + j%3;
                if (board[x][y] != '.'){
                    if (cell[board[x][y] - '0'] == 1) return false;
                    cell[board[x][y] - '0']++;
                }
            }
        }
        return true;       
    }
};
// @lc code=end

