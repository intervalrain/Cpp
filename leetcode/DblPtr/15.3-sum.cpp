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
        vector<vector<int>> res;
        for (int i = 0; i < nums.size()-2; i++){
            if (nums[i] > 0) break;
            int j = i+1, k = nums.size()-1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0){
                    j++;
                } else if (sum > 0){
                    k--;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j+1 < k && nums[j] == nums[j+1]) j++;
                    while (k-1 > j && nums[k-1] == nums[k]) k--;
                    j++;
                    k--;
                }
            }
            while (i+1 < nums.size()-2 && nums[i] == nums[i+1]) i++;
        }
        return res;        
    }
};
// @lc code=end

// -4,-1,-1,0,1,2
//     ^
//          ^
//            ^
// -1,-1,2
// -1,0,1
// -1,0,1
