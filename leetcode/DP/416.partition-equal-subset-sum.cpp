#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0, n = nums.size();
        for (int x : nums) {
            total += x;
        }
        if ((total & 1) == 1) return false;
        int target = (total >> 1);

        bool dp[target+1];
        memset(dp, false, sizeof(dp));
        
        dp[0] = true;

        for (int x : nums){
            // from target update to 1 to keep last round
            for (int i = target; i >= x; i--){
                dp[i] |= dp[i - x];
            }
        }
        return dp[target];
    }
};
// @lc code=end

// dp[i] = (dp[i] || dp[i-x])

