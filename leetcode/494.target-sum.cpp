#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
// +1+2+3+4+5 = 15
// -1+2+3-4+5 =  5
// ---------------
//   +4+6  +10= 20
//  x o o x o
// --> find how many combinations to compose target = (target+sum)/2
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        int zeros = 0;
        int n = nums.size();
        for (int x : nums) {
            total += x;
            if (x == 0) zeros++;
        }
        if (abs(target) == total) return pow(2, zeros);
        if (abs(target) > total || ((target + total) & 1) == 1) return 0;

        target = (total+target)/2;

        int dp[target+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;  // all quit
        for (int x : nums){
            for (int i = target; i >= x; i--){
                dp[i] = dp[i] + dp[i-x];
            }
        }
        return dp[target];
    }
};
// @lc code=end


//  0  1  2  3  4 5  6 7 8 9 10
//  ----------------------------
// -5 -4 -3 -2 -1 0  1 2 3 4 5
//  0  0  0  0  0 1  0 0 0 0 0
//  0  0  0  0  1 0  1 0 0 0 0
//  0  0  0  1  0 2  0 1 0 0 0
//  0  0  1  0  3 0  3 0 1 0 0
//  0  1  0  4  0 6  0 4 0 1 0
//  1  0  5  0 10 0 10 0 5 0 1

//   0 1 2 3 4 5
// 0 1 0 0 0 0 0
// 1 1 1 0 0 0 0 
// 2 1 1 1 1 0 0
// 3 1 1 1 2 1 1
// 4 1 1 1 2 2 2
// 5 1 1 1 2 2 3
// {1,4},{2,3},{5}



