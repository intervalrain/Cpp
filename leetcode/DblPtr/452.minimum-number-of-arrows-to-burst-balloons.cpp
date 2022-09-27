#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 1;
        vector<pair<int,int>> vp;
        for (const auto& v : points){
            vp.push_back({v[0], v[1]});
        }
        sort(vp.begin(), vp.end());
        int right = vp[0].second;
        for (int i = 1; i < vp.size(); i++){
            if (vp[i].first <= right){
                right = min(right, vp[i].second);
            } else {
                res++;
                right = vp[i].second;
            }
        }
        return res;
    }
};
// @lc code=end

