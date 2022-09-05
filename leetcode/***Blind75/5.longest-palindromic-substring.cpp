#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    // string longestPalindrome(string s) {
    //     int n = s.length();
    //     int dp[n][n];
    //     int len = 0;
    //     int left = 0;
    //     memset(dp, false, sizeof(dp));
    //     for (int i = 0; i < n; i++){
    //         for (int j = 0; j <= i; j++){
    //             if (i == j) {
    //                 dp[i][j] = true;
    //             } else if (i - j == 1){
    //                 dp[i][j] = s[i] == s[j];
    //             } else {
    //                 dp[i][j] = (s[i] == s[j] && dp[i-1][j+1]);
    //             }

    //             if (dp[i][j] && i - j >= len){
    //                 left = j;
    //                 len = i - j + 1;
    //             }
    //         }
    //     }
    //     return s.substr(left, len);
    // }
    // O(n^2)
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.length(); i++){
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i+1);
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }
    string palindrome(string s, int left, int right){
        while (left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
};
// @lc code=end

//   b a b a d
// b o
// a x o
// b o x o
// a x o x o
// d x x x x o