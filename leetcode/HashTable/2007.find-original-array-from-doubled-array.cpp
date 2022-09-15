#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if ((changed.size() & 1) == 1) return {};
        unordered_map<int,int> map;
        for (int x : changed) map[x]++;
        sort(changed.begin(), changed.end());
        vector<int> res;
        for (int x : changed){
            if (map[x] == 0) continue;
            else if (map[2*x] == 0) return {};
            map[x]--;
            map[2*x]--;
            res.push_back(x);
        }
        return res;
    }
};
// @lc code=end

