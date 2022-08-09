/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {

// dp: time complexity: O(mn), space complexity: O(min(m,n))
public:
    int longestCommonSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return longestCommonSubsequence(t, s);
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (s[i-1] == t[j-1]){
                    dp[i % 2][j] = dp[(i-1) % 2][j-1] + 1;
                } else {
                    dp[i % 2][j] = max(dp[(i-1) % 2][j], dp[i % 2][j-1]);
                }
            }
        }
        return dp[m % 2][n];
    }
};
// @lc code=end

//     a c e
//   0 0 0 0
// a 0 1 1 1
// b 0 1 1 1
// c 0 1 2 2
// d 0 1 2 2
// e 0 1 2 3
