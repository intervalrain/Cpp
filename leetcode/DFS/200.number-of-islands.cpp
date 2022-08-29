/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int dirc[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& grid, int row, int col){
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0'){
            return;
        }
        grid[row][col] = '0';
        for (auto& d : dirc) dfs(grid, row+d[0], col+d[1]);
    }
};
// @lc code=end

