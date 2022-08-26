#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size()-2; i++){
            int j = i+1, k = nums.size()-1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target){
                    if (abs(sum-target) < abs(res-target)) res = sum;
                    j++;
                } else if (sum > target){
                    if (abs(sum-target) < abs(res-target)) res = sum;
                    k--;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};
// @lc code=end

