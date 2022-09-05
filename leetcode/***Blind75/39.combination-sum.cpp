#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> res;
        backtrack(candidates, path, res, target, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, vector<int>& path, vector<vector<int>>& res, int target, int idx){
        if (target == 0){
            res.push_back(path);
            return;
        }
        for (int i = idx; i < candidates.size(); i++){
            int can = candidates[i];
            if (can > target) continue;
            path.push_back(can);
            backtrack(candidates, path, res, target-can, i);
            path.pop_back();
        }
    }
};
// @lc code=end



