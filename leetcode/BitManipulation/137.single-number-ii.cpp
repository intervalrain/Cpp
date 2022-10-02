#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int x : nums){
            ones = ones ^ x & (~twos);
            twos = twos ^ x & (~ones);
        }
        return ones;
        
    }
};
// @lc code=end

