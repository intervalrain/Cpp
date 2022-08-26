#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.');
        vector<string> grid(n, s);
        backtrack(grid, res, 0);

        return res;
    }

    void backtrack(vector<string>& grid, vector<vector<string>>& res, int row){
        if (row == grid.size()){
            res.push_back(grid);
            return;
        }
        int n = grid.size();
        for (int i = 0; i < n; i++){
            if (!isValid(grid, row, i)) continue;
            grid[row][i] = 'Q';
            backtrack(grid, res, row+1);
            grid[row][i] = '.';
        }
    }

    bool isValid(vector<string>& grid, int& row, int& col){
        int n = grid.size();
        if (n == row) return true;
        for (int i = row-1; i >= 0; i--){
            if (grid[i][col] == 'Q') return false;
        }
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if (grid[i][j] == 'Q') return false;
        }
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
            if (grid[i][j] == 'Q') return false;
        }
        return true;
    }
};
// @lc code=end

