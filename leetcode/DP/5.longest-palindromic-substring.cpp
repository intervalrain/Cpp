/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int left, right;
        int len = 0;
        for (int j = 0; j < n; j++){
            for (int i = 0; i <= j; i++){
                if (i == j){
                    dp[i][j] = true;
                } else if (j - i == 1){
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if (dp[i][j] && j - i >= len){
                    left = i;
                    right = j;
                    len = right - left + 1;
                }
            }
        }
        return s.substr(left, len);
    }
};
// @lc code=end

    // dp
    //   b a b a d
    // b o 
    // a x o 
    // b o x o 
    // a x o x o 
    // d x x x x o