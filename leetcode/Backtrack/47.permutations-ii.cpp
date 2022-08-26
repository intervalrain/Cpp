#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        backtrack(nums, res, path, visited);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& visited){
        if (path.size() == nums.size()){
            if (find(res.begin(), res.end(), path) == res.end()){
                res.push_back(path);
            }
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (visited[i]) continue;
            // if (i > 0 && nums[i-1] == nums[i] && visited[i-1]) continue;
            path.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, res, path, visited);
            path.pop_back();
            visited[i] = false;
            while (i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
    }
};
// @lc code=end

