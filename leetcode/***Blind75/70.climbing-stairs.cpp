#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int dp[n+1];
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for (int i = 4; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
// @lc code=end

// dp[1] = 1
// dp[2] = 2
// dp[3] = dp[3-1] + dp[3-2] = 3
// dp[4] = dp[4-1] + dp[4-2] = 5
// dp[5] = 8
