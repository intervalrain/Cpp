/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
// dp: time complexity: O(mn), space complexity: O(min(m, n))
public:
    int minDistance(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return minDistance(t, s);
        vector<vector<int>> dp(2, vector<int>(n+1, 0));

        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= n; j++){
                if (i == 0 || j == 0){
                    dp[i % 2][j] = i == 0 ? j : i;
                } else if (s[i-1] == t[j-1]){
                    dp[i % 2][j] = dp[(i-1) % 2][j-1];
                } else {
                    dp[i % 2][j] = min(dp[(i-1) % 2][j], dp[i % 2][j-1])+1;
                }
            }
        }

        return dp[m % 2][n];
    }
};
// @lc code=end

/**
 *    sea
 *   0123
 *  e1212
 *  a2321
 *  t3432
 */