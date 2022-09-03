#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> path;
        int n = matrix.size() * matrix[0].size();
        int d = 0, row = 0, col = 0;
        for (int i = 0; i < n; i++){
            if (isValid(matrix, row, col)){
                path.push_back(matrix[row][col]);
                matrix[row][col] = INT_MIN;
                row += dir[d][0];
                col += dir[d][1];
            } else {
                i--;
                row -= dir[d][0];
                col -= dir[d][1];
                d = (d + 1)%4;
                row += dir[d][0];
                col += dir[d][1];
            }
        }
        return path;
    }
    bool isValid(vector<vector<int>>& matrix, int row, int col){
        return ;
    }
};
// @lc code=end

