#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[2][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (s[i-1] == s[n-j]){
                    dp[i % 2][j] = dp[(i-1) % 2][j-1] + 1;
                } else {
                    dp[i % 2][j] = max(dp[(i-1) % 2][j], dp[i%2][j-1]);
                }
            }
        }
        return dp[n%2][n];
    }
};
// @lc code=end

//     b b b a b
//   0 0 0 0 0 0
// b 0 1 1 1 1 1
// a 0 1 1 1 2 2
// b 0 1 2 2 2 2
// b 0 1 2 3 3 3
// b 0 1 2 3 3 4
// 

