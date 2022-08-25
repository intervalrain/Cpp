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
        int dp[2];
        dp[0] = 2;
        dp[1] = 3;
        for (int i = 4; i <= n; i++){
            dp[i%2] = dp[i%2] + dp[(i-1)%2];
        }
        return dp[n%2];
    }
};
// @lc code=end

// 1, 2, 3, 5, 8, 13, 21
