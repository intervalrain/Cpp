#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt <= 1; i++){
            if (nums[i-1] > nums[i]){
                cnt++;
                if (i-2 < 0 || nums[i-2] <= nums[i]) 
                    nums[i-1] = nums[i];
                else 
                    nums[i] = nums[i-1];
            }
        }
        return cnt <= 1;
    }
};
// @lc code=end
//
//
//        __            __
//    __                    __
//  __                    i_
//      i_           __
