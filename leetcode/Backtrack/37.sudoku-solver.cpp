#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == '.'){
                    for (char c = '1'; c <= '9'; c++){
                        if (isValid(board, i, j, c)){
                            board[i][j] = c;
                            if (solve(board)){
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }   
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++){
            if (board[i][col] != '.' && board[i][col] == c) return false;
            if (board[row][i] != '.' && board[row][i] == c) return false;
            int x = (row/3)*3 + i/3;
            int y = (col/3)*3 + i%3;
            if (board[x][y] != '.' && board[x][y] == c) return false;
        }
        return true;
    }
};
// @lc code=end
