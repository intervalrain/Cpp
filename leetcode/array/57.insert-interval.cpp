#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> res;
        int pos = 0;
        for (int i = 0; i < intervals.size(); i++){
            auto v = intervals[i];
            if (left > v[1]){
                res.push_back(v);
                pos++;
            } else if (right < v[0]){
                res.push_back(v);
            } else {
                left = min(left, v[0]);
                right = max(right, v[1]);
            }
        }
        res.insert(res.begin()+pos, {left, right});
        return res;
    }
};
// @lc code=end

