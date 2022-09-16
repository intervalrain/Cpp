#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=1770 lang=cpp
 *
 * [1770] Maximum Score from Performing Multiplication Operations
 */

// @lc code=start
class Solution {
public:
    int m, n;
    vector<vector<int>> memo;
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        this->n = nums.size();
        this->m = muls.size();
        memo = vector<vector<int>>(m, vector<int>(m, INT_MIN));
        return dp(nums, muls, 0, 0);
    }
    int dp(vector<int>& nums, vector<int>& muls, int l, int i){
        if (i == m) return 0;
        if (memo[l][i] != INT_MIN) return memo[l][i];
        int left = dp(nums, muls, l+1, i+1) + nums[l]*muls[i];
        int right = dp(nums, muls, l, i+1) + nums[n-1-(i-l)]*muls[i];
        memo[l][i] = max(left, right);
        return memo[l][i];
    }
};



// @lc code=end

