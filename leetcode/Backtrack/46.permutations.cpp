/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, res, path, visited);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& visited){
        if (path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (visited[i]) continue;
            path.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, res, path, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};
// @lc code=end

