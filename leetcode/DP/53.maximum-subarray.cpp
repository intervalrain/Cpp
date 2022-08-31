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
        int res = INT_MIN;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++){
            curr = max(nums[i], nums[i] + curr);
            res = max(res, curr);
        }
        return res;
    }
};
// @lc code=end

