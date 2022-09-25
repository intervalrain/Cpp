#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= right){
                right = max(right, intervals[i][1]);
            } else {
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};
// @lc code=end

