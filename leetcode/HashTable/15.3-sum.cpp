/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> map;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size()-2; i++){
            for (int j = i+1; j < nums.size()-1; j++){
                int toFind = -(nums[i] + nums[j]);
                if (toFind < 0) continue;
                if (map.count(toFind) && map[toFind] > j){
                    res.push_back({nums[i], nums[j], toFind});
                }
                j = map[nums[j]];
            }
            i = map[nums[i]];
        }
        return res;
    }
};
// @lc code=end

