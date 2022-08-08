#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        unsigned base = 0;
        int i = 0;
        while (s[i] == ' ') i++;
        if (s[i] == '+')
            i++;
        else if (s[i] == '-'){
            sign = -1;
            i++;
        }
        while (isDigit(s[i])){
            if (sign == 1){
                if (base > INT_MAX/10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) return INT_MAX;
            } else if (sign == -1){
                if (base > INT_MAX/10 || (base == INT_MAX / 10 && s[i] - '0' > 8)) return INT_MIN;
            }
            base = 10 * base + (s[i] - '0');
            i++;
        }
        return base * sign;
    }
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
};
// @lc code=end

