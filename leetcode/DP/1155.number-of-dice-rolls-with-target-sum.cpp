#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
#define MOD 1000000007
class Solution {
public:
    int numRollsToTarget(int n, int face, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= min(target, j * face); j++){
                int sum = 0;
                for (int k = max(j-face, 0); k <= j-1; k++){
                    sum = ((sum + dp[i-1][k]) % MOD);
                }
                dp[i][j] = sum;
            }
        }
        return dp[n][target];
    }
};
// @lc code=end

