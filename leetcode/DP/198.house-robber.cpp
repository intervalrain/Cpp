#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        nums[2] += nums[0];
        int res = max(nums[1], nums[2]);
        for (int i = 3; i < n; i++){
            nums[i] += max(nums[i-3], nums[i-2]);
            res = max(nums[i], res);
        }
        return res;
    }
};
// @lc code=end

