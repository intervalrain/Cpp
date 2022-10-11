#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=1920 lang=cpp
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res;
        for (int x : nums){
            res.push_back(nums[x]);
        }
        return res;
    }
};
// @lc code=end

