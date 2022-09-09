#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int neg = 1, curr = 1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                curr *= nums[i];
                res = max(res, curr);
                if (neg < 0 && curr < 0){
                    res = max(res, curr/neg);
                }
                if (neg >= 0) neg = curr;
            } else {
                curr = 1;
                neg = 0;
                res = max(res, 0);
            }
        }
        return res;
    }
};
// @lc code=end


// -2  1  -1
// -2  0  -1
// -2  0   0