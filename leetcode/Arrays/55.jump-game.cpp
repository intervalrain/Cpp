#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = nums[0];
        for (int i = 1; i <= reach && i < nums.size(); i++){
            reach = max(reach, nums[i] + i);
        }
        return reach >= nums.size()-1;
    }
};
// @lc code=end

