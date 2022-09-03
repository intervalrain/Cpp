#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int left = n-2; left >= 0; left--){
            for (int right = n-1; right > left; right--){
                if (nums[left] < nums[right]){
                    swap(nums[left], nums[right]);
                    reverse(nums.begin()+left+1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

// 1,2,4,3
// 1,3,4,2
// 1,3,2,4
