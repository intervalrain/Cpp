#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    // dp
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1, 10001);
        dp[0] = 0;
        for (int coin : coins){
            for (int j = coin; j <= amount; j++){
                dp[j] = min(dp[j-coin] + 1, dp[j]);
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};
// @lc code=end

