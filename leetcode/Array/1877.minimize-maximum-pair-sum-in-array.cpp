/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[0] + nums[n-1];
        for (int i = 1; i < n/2; i++){
            res = max(res, nums[i] + nums[n-1-i]);
        }
        return res;
    }
};
// @lc code=end

