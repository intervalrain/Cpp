#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zeros = 0;
        int index = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
                zeros++;
                index = i;
            } else {
                prod *= nums[i];
            }

            if (zeros == 2) return vector<int>(n, 0);
        }
        if (zeros == 1){
            fill(nums.begin(), nums.end(), 0);
            nums[index] = prod;
            return nums;
        }
        for (int i = 0; i < n; i++){
            nums[i] = prod/nums[i];
        }
        return nums;
    }
};
// @lc code=end
