#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 && x != 0) return false;
        int num = 0;
        while (x > num){
            num = num * 10 + x % 10;
            x /= 10;
        }
        return (num == x || num/10 == x);
    }
};
// @lc code=end

