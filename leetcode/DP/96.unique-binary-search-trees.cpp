/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
            cout << dp[i] << endl;
        }
        return dp[n];
    }
};
// @lc code=end

// 0: 1 dp[0] = 1
// 1: 1 dp[1] = dp[0]*dp[0] = 1
// 2: 2 dp[2] = dp[0]*dp[1] + dp[1]*dp[0]
// 3: 5 dp[3] = dp[0]*dp[2] + dp[1]*dp[1] + dp[2]dp[0];
// 4:   dp[4] = dp[0]*dp[3] + dp[1]*dp[2] + dp[2]dp[1] + dp[3]dp[0]
// 

