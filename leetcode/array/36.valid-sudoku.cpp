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
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxs(9, vector<bool>(9, false));
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                char x = board[row][col];
                if (x == '.') continue;
                if (rows[row][x-'1']) return false;
                if (cols[col][x-'1']) return false;
                if (boxs[(row/3)*3+(col/3)%3][x-'1']) return false;
                rows[row][x-'1'] = true;
                cols[col][x-'1'] = true;
                boxs[(row/3)*3+(col/3)%3][x-'1'] = true;
            }
        }
        return true;
    }
};
// @lc code=end

