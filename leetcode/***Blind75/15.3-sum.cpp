#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     unordered_map<int,int> map;
    //     vector<vector<int>> res;
    //     for (int i = 0; i < nums.size(); i++){
    //         map[nums[i]] = i;
    //     }
    //     for (int i = 0; i < nums.size()-2; i++){
    //         for (int j = i+1; j < nums.size()-1; j++){
    //             int target = -(nums[i] + nums[j]);
    //             if (target < 0) continue;
    //             if (map.count(target) && map[target] > j){
    //                 res.push_back({nums[i], nums[j], target});
    //             }
    //             j = map[nums[j]];
    //         }
    //         i = map[nums[i]];
    //     }
    //     return res;
    // }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n-2; i++){
            if (nums[i] > 0) break;
            int left = i+1, right = n-1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0){
                    while (left < right && nums[left] == nums[left+1]) left++;
                    left++;
                } else if (sum > 0){
                    while (left < right && nums[right] == nums[right-1]) right--;
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
            while (i < n-2 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};
// @lc code=end

// -4, -1,-1,0,1,2

