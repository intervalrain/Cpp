/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p){
        int m = s.length(), n = p.length();
        if (n == 0) return m == 0;
        
        bool dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for (int i = 2; i <= n; i++){
            if (p[i-1] == '*'){
                dp[0][i] = dp[0][i-2];
            }
        }

        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

//     m i s s i s s i p p i
//   o x x x x x x x x x x x 
// m x o x x x x x x x x x x 
// i x x o x x x x x x x x x 
// s x x x o x x x x x x x x
// * x x o o o x x x x x x x 
// i x x x x x o x x x x x x
// s x x x x x x o x x x x x 
// * x x x x x o o o x x x x 
// i x x x x x x x x o x x x
// p x x x x x x x x x o x x
// * x x x x x x x x o o o x
// . x x x x x x x x x x x o

