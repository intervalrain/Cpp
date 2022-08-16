/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<vector<bool>> grid(n, vector(n, false));
        backtrack(grid, res, 0);
        return res;
        
    }
    void backtrack(vector<vector<bool>>& grid, int& res, int row){
        if (grid.size() == row){
            res++;
            return;
        }
        for (int i = 0; i < grid.size(); i++){
            if (!isValid(grid, row, i)) continue;
            grid[row][i] = true;
            backtrack(grid, res, row+1);
            grid[row][i] = false;
        }
    }
    bool isValid(vector<vector<bool>>& grid, int& row, int& col){
        int n = grid.size();
        if (n == row) return true;
        for (int i = row-1; i >= 0; i--){
            if (grid[i][col]) return false;
        }
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if (grid[i][j]) return false;
        }
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
            if (grid[i][j]) return false;
        }
        return true;
    }
};
// @lc code=end

