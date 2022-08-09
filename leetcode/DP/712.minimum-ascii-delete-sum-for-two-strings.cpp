/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
// dp: time complexity(mn),  space complexity: O(min(n))
public:
    int minimumDeleteSum(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return minimumDeleteSum(t, s);
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<vector<int>> dp(2, vector<int>(n+1, 0));

        for (int j = 1; j <= n; j++)
            dp[0][j] = dp[0][j-1] + t[j-1];
        for (int i = 1; i <= m; i++){
            for (int j = 0; j <= n; j++){
                if (j == 0){
                    // dp[i][0] = dp[i-1][0] + s[i-1];
                    dp[i % 2][0] = dp[(i-1) % 2][0] + s[i-1];
                    continue;   
                }
                if (s[i-1] == t[j-1]){
                    // dp[i][j] = dp[i-1][j-1];
                    dp[i % 2][j] = dp[(i-1) % 2][j-1];
                } else {
                    // dp[i][j] = min(dp[i-1][j] + s[i-1], dp[i][j-1] + t[j-1]);
                    dp[i % 2][j] = min(dp[(i-1) % 2][j] + s[i-1], dp[i % 2][j-1] + t[j-1]);
                }
            }
        }

        // return dp[m][n];
        return dp[m % 2][n];
    }
};
// @lc code=end

//     |       |   a   |   c   |   e   |   
//     |   -   |   a   |   c   |   e   |
//   a |   a   |   -   |   c   |   ce  |
//   b |   b   |   b   |   bc  |  bce  |
//   c |   c   |   bc  |   b   |   be  |
//   d |   d   |  bcd  |   bd  |  bde  |
//   e |   e   |  abcd |  bde  |   bd  |
