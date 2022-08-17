/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(nums, res, path, 0);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int idx){
        if (find(res.begin(), res.end(), path) == res.end()){
            res.push_back(path);
        }
        for (int i = idx; i < nums.size();i++){
            if (i > idx && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backtrack(nums, res, path, i+1);
            path.pop_back();
        }
    }
};
// @lc code=end

