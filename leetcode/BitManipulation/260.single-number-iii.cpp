#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long x = 0;
        for (int n : nums)
            x ^= n;
        long y = x & (~x+1);
        vector<int> res(2, 0);
        for (int n : nums){
            if ((n & y) == 0){
                res[0] ^= n;
            } else {
                res[1] ^= n;
            }
        }
        return res;
    }
};
// @lc code=end

