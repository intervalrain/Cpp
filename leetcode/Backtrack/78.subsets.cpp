/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, res, path, 0);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int idx){
        res.push_back(path);
        for (int i = idx; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(nums, res, path, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

