#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> res;
        backtrack(n, k, path, res, 1);
        return res;
    }
    void backtrack(int n, int k, vector<int>& path, vector<vector<int>>& res, int idx){
        if (path.size() == k){
            res.push_back(path);
            return;
        }
        for (int i = idx; i <= n; i++){
            path.push_back(i);
            backtrack(n, k, path, res, i+1);
            path.pop_back();
        }
    }
};
// @lc code=end

