/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vec(m+n-1, vector<int>());
        int shift = n-1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                vec[i-j+shift].push_back(mat[i][j]);
            }
        }
        for (int i = 0; i < vec.size(); i++){
            sort(vec[i].begin(), vec[i].end());
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                mat[i][j] = vec[i-j+shift][0];
                vec[i-j+shift].erase(vec[i-j+shift].begin());
            }
        }
        return mat;
    }
};
// @lc code=end
