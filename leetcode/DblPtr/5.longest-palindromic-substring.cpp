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
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.length(); i++){
            string s1 = palindrome(s, i, i);   // s[i] as center
            string s2 = palindrome(s, i, i+1); // s[i] and s[i+1] as center
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }

    // aaaabcdefgfedcbabbbbbb
    //   ^             ^
    //   left          right    len = right - left - 1

    string palindrome(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
// @lc code=end

