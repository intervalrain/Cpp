#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int j = 1; j < n; j++){
            grid[0][j] += grid[0][j-1];
        }
        for (int i = 1; i < m; i++){
            grid[i][0] += grid[i-1][0];
            
            for (int j = 1; j < n; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
// @lc code=end

// [1,3,1]
// [1,5,1]
// [4,2,1]

// [1,4,5]
// [2,7,6]
// [6,8,7]
