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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, top = 0, bot = matrix.size()-1, right = matrix[0].size()-1;
        int n = (bot+1)*(right+1);
        vector<int> res;
        while (n > 0){
            for (int i = left; i <= right && n > 0; i++, n--)
                res.push_back(matrix[top][i]);
            top++;
            for (int i = top; i <= bot && n > 0; i++, n--)
                res.push_back(matrix[i][right]);
            right--;
            for (int i = right; i >= left && n > 0; i--, n--)
                res.push_back(matrix[bot][i]);
            bot--;
            for (int i = bot; i >= top && n > 0; i--, n--)
                res.push_back(matrix[i][left]);
            left++;
        }
        return res;
    }
};
// @lc code=end

