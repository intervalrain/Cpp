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
    // void sortColors(vector<int>& nums) {
    //     int memo[3];
    //     memset(memo, 0, sizeof(memo));
    //     for (int x : nums){
    //         memo[x]++;
    //     }
    //     int left = 0;
    //     for (int i = 0; i <= 2; i++){
    //         fill(nums, left, memo[i], i);
    //         left += memo[i];
    //     }
        
    // }
    // void fill(vector<int>& nums, int left, int len, int val){
    //     auto it = nums.begin() + left;
    //     std::fill(it, it + len, val);
    // }
};
// @lc code=end

