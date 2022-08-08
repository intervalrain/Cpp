/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b)->bool{return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);});
        vector<int> dp;
        for (auto v : envelopes){
            int pos = lbound(dp, v[1]);
            if (dp.size() == pos) dp.push_back(v[1]);
            else dp[pos] = v[1];
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


// [2,3],[5,4],[6,7],[6,4]