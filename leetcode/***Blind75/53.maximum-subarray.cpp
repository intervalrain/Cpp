#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            curr = max(nums[i], nums[i] + curr);
            res = max(curr, res);
        }
        return res;
    }
};
// @lc code=end

