#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        int left = 0, right = n-1, top = 0, bot = n-1;
        int cnt = 1, total = n * n;
        while (cnt <= total){
            for (int i = left; i <= right && cnt <= total; i++, cnt++)
                v[top][i] = cnt;
            top++;
            for (int i = top; i <= bot && cnt <= total; i++, cnt++)
                v[i][right] = cnt;
            right--;
            for (int i = right; i >= left && cnt <= total; i--, cnt++)
                v[bot][i] = cnt;
            bot--;
            for (int i = bot; i >= top && cnt <= total; i--, cnt++)
                v[i][left] = cnt;
            left++;
        }
        return v;
    }
};
// @lc code=end

