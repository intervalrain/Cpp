#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (char c : s) map[c]++;  // char, amount
        int cnt = 0;
        int odd = 0;
        for (auto m : map){
            if ((m.second & 1) == 0){  // odd
                cnt += m.second;
            } else {  // even
                odd = 1;
                if (m.second > 2){
                    cnt += (m.second - 1);
                }
            }
        }
        return cnt + odd;
    }
};
// @lc code=end


// abccccdd
// a:1 -> odd
// b:1 -> odd
// c:4 -> even
// d:2 -> even
// case 1: single character: a -> true
// case 2: even palindrome: composed even pairs len = 2n
// case 3: odd palindrome composed one odd pair and all the other even pairs, len = 2n+1.
// evens and odds
