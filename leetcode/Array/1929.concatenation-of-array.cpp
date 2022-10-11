#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size(), 0);
        for (int i = 0; i < nums.size(); i++){
            ans[i] = nums[i];
            ans[i+nums.size()] = nums[i];
        }
        return ans;
    }
};
// @lc code=end

