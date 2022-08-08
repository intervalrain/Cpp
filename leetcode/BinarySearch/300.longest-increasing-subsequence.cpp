#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        
        for (int x : nums){
            if (dp.size() == 0){
                dp.push_back(x);
                continue;
            }
            int pos = lbound(dp, x);
            if (pos == dp.size()) dp.push_back(x);
            else dp[pos] = x;
        }
        return dp.size();
    }

    int lbound(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] >= target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

