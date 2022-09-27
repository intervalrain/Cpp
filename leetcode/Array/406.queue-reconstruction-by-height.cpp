#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> x, vector<int> y){
            return x[0] == y[0] ? x[1] < y[1] : x[0] > y[0];
        });
        vector<vector<int>> res;
        for (auto v: people){
            res.insert(res.begin() + v[1], v);
        }
        return res;
    }
};
// @lc code=end





