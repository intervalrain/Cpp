#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n & (n-1)) return false;
        if ((0x55555555 & n) != n) return false;
        return true;
    }
};
// @lc code=end


