/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (const auto coin : coins){
            for (int i = coin; i <= amount; i++){
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end



// dp[i] += dp[i-coin]
//     1 2 3 4 5
//   1 0 0 0 0 0
// 1 1 1 1 1 1 1 
// 2 1 1 2 2 3 3
// 5 1 1 2 2 3 4