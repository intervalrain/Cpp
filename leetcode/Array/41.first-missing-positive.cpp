#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), res = 0;
        int i = 0;
        while (i < n){
            if (nums[i] < 1 || nums[i] > n || nums[i] == i+1) {
                i++;
            } else if (nums[i] == nums[nums[i]-1]){
                i++;
            } else {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        while (res < n && nums[res] == res + 1) res++;
        return res + 1;
    }
};
// @lc code=end

// 3,4,-1,1  1
// -1,4,3,1  1
// -1,1,3,4  1
// 1,-1,3,4  
