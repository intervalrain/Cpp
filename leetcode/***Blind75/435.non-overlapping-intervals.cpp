#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // int cnt = 0;
        // auto comp = [](vector<int>& a, vector<int>& b){
        //     if (a[1] == b[1]) return a[0] > b[0];
        //     return a[1] < b[1];
        // };
        // sort(intervals.begin(), intervals.end(), comp);
        // int upbound = intervals[0][1];
        // for (int i = 1; i < intervals.size(); i++){
        //     vector<int> v = intervals[i];
        //     if (v[0] >= upbound){
        //         upbound = v[1];
        //     } else {
        //         cnt++;
        //     }
        // }
        // return cnt;
        int cnt = 0;
        auto comp = [](pair<int,int>& a, pair<int,int>& b){
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        };
        vector<pair<int,int>> v;
        for (const auto& interval : intervals){
            v.push_back({interval[0], interval[1]});
        }
        sort(v.begin(), v.end(), comp);
        int upbound = v[0].second;
        for (int i = 1; i < v.size(); i++){
            if (v[i].first >= upbound){
                upbound = v[i].second;
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

// [1,2]
// [2,3]
// [1,3]
// [3,4]

