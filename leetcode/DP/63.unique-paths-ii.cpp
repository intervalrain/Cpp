#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1) 
                    grid[i][j] = 0;
                else if (i == 0 || j == 0){
                    if (i == 0 && j == 0) grid[i][j] = -1;
                    if (i > 0 && j == 0) grid[i][j] = grid[i-1][j];
                    if (j > 0 && i == 0) grid[i][j] = grid[i][j-1];
                } else {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        return -grid[m-1][n-1];
    }
};
// @lc code=end

// -1 -1
//  1  1
//  0  0

