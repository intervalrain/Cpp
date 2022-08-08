#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++){
            if (map.count(target - nums[i])){
                return {map[target-nums[i]], i};
            }
            map.insert({nums[i], i});
        }
        return {-1, -1};
    }
};
// @lc code=end

