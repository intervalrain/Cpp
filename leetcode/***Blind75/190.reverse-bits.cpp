#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0 || n == -1) return n;
        uint32_t res = 0;
        int cnt = 32;
        while (--cnt > 0){
            res += (n & 1);
            res <<= 1;
            n >>= 1;
        }
        return res + n;
    }

};
// @lc code=end

// input: 
// 11111111111111111111111111111101
//
// 11111111111111111111111111111101
// 

