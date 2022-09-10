#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return max(max(nums[0], nums[1]), nums[2]);
        int dp[2][3] = {{nums[0], 0, nums[0]+nums[2]},{0, nums[1], nums[2]}};
        for (int i = 3; i < n-1; i++)
            for (int j = 0; j < 2; j++)
                dp[j][i % 3] = nums[i] + max(dp[j][(i-2) % 3], dp[j][(i-3) % 3]);
        dp[1][(n-1) % 3] = nums[n-1] + max(dp[1][(n-3) % 3], dp[1][(n-4) % 3]);
        int res = 0;
        for (int i = 0; i < 3; i++){
            res = max(res, max(dp[0][i], dp[1][i]));
        }
        return res;
    }
};
// @lc code=end

