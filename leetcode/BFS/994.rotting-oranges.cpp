
#include <bits/stdc++.h>

using namespace std;/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dirc = {{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int depth = -1;
        int cnt = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                } else if (grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        if (cnt == 0) return 0;
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (auto d : dirc){
                    if (isValid(grid, row+d[0], col+d[1])){
                        cnt--;
                        grid[row+d[0]][col+d[1]] = 2;
                        q.push({row+d[0], col+d[1]});
                    }
                }
            }
            depth++;
        }
        return cnt == 0 ? depth : -1;
    }
    bool isValid(vector<vector<int>>& grid, int row, int col){
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1;
    }
};
// @lc code=end

