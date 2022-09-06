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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& u) {
        vector<vector<int>> res;
        int pos = 0, left = u[0], right = u[1];
        for (int i = 0; i < intervals.size(); i++){
            vector<int>& v = intervals[i];
            if (v[1] < u[0]){
                res.push_back(v);
                pos++;
            } else if (v[0] > u[1]){
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

