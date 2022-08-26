#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, res, path, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& path, int idx){
        if (target < 0) return;
        if (target == 0 && find(res.begin(), res.end(), path) == res.end()){
            res.push_back(path);
        }

        for (int i = idx; i < candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], res, path, i+1);
            path.pop_back();
        }
    }
};
// @lc code=end

