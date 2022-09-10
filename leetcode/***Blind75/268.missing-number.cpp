#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int i = 0;
        while (i < n){
            if (nums[i] == i || nums[i] == n)
                i++;
            else {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < n; i++){
            if (nums[i] != i) return i;
        }
        return n;
    }
};
// @lc code=end

// [9,6,4,2,3,5,7,0,1]
// [9,7,4,2,3,5,6,0,1]
// [9,0,4,2,3,5,6,7,1]
// [0,9,4,2,3,5,6,7,1]
// [0,9,3,2,4,5,6,7,1]
// [0,9,2,3,4,5,6,7,1]
// [0,1,2,3,4,5,6,7,9]
