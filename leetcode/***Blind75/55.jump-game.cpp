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
        int target = nums.size()-1;
        int reach = 0;
        int i = 0;
        for (int i = 0; i <= target && i <= reach; i++){
            reach = max(reach, i+nums[i]);
            if (reach >= target) return true;
        }
        return reach >= target;
    }
};
// @lc code=end

// 2,3,1,1,4  target = 4
// 0,1,2,3,4
// 2,4,3,4,4

// 3,2,1,0,4  target = 4
// 0,1,2,3,4
// 3,3,3,3,4


