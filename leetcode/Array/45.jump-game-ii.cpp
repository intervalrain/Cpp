#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int target = nums.size()-1;
        int cnt = 1;
        int top = nums[0];
        while (true){
            if (top >= target) return cnt;
            int next = 0;
            for (int i = 0; i <= top; i++){
                next = max(next, nums[i] + i);
            }
            top = next;
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

// 2,3,0,1,4
// 2,4,0,4,8
//
// target = 4, cnt = 1, top = 2
// {next = 4}
// 
// target = 4, cnt = 2, top = 4