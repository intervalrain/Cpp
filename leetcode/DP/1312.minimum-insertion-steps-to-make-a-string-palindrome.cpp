#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution {

public:
    int minInsertions(string& s) {
        const int n = s.length();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (s[i-1] == s[n-j]){
                    dp[i % 2][j] = dp[(i-1) % 2][j-1] + 1;
                } else {
                    dp[i % 2][j] = max(dp[i % 2][j-1], dp[(i-1) % 2][j]);
                }
            }
        }
        return s.length() - dp[n%2][n];
    }
 
    // int minInsertions(string& s){
    //     string t = reverse(s);
    //     return s.length() - lcs(s, t);
    // }

    // int lcs(string& s, string& t){
    //     const int m = s.length(), n = t.length();
    //     vector<vector<int>> dp(2, vector<int>(n+1, 0));
    //     for (int i = 1; i <= m; i++){
    //         for (int j = 1; j <= n; j++){
    //             if (s[i-1] == t[j-1]){
    //                 dp[i % 2][j] = dp[(i-1) % 2][j-1] + 1;
    //             } else {
    //                 dp[i % 2][j] = max(dp[i % 2][j-1], dp[(i-1) % 2][j]);
    //             }
    //         }
    //     }
    //     return dp[m % 2][n];
    // }

    // string reverse(string s){
    //     int n = s.length();
    //     int i = 0, j = n-1;
    //     while (i < j){
    //         char tmp = s[i];
    //         s[i] = s[j];
    //         s[j] = tmp;
    //         i++;
    //         j--;
    //     }
    //     return s;
    // }


};
// @lc code=end

// leetcode
//  ^^    ^

//     l e e t c o d e
//   0 0 0 0 0 0 0 0 0  
// e 0 0 1 1 1 1 1 1 1
// d 0 0 1 1 1 1 1 2 2
// o 0 0 1 1 1 1 2 2 2
// c 0 0 1 1 1 2 2 2 2
// t 0 0 1 1 2 2 2 2 2
// e 0 0 1 2 2 2 2 2 3 <-
// e 0 0 1 2 2 2 2 2 3
// l 0 0 1 2 2 2 2 2 3