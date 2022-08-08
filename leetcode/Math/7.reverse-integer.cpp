#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0){
            int mod = x % 10;
            x /= 10;

            // INT_MIN = -2147483648
            // INT_MAX = 2147483647
            if (res > INT_MAX/10 || (res == INT_MAX/10 && mod > 7)) return 0;
            if (res < INT_MIN/10 || (res == INT_MIN/10 && mod < -8)) return 0;
            res = 10*res + mod;
        }
        return res;
    }
};
// @lc code=end

