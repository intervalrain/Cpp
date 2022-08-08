#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, r = nums.size()-1;
        while (m <= r){
            if (nums[m] == 0){
                swap(nums[m++], nums[l++]);
            } else if (nums[m] == 1){
                m++;
            } else {
                swap(nums[m], nums[r--]);
            }
        } 
    }
};
// @lc code=end

