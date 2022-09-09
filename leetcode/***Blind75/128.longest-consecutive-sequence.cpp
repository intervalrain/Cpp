#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int,int>> map;
        int res = 0;
        for (int x : nums){
            if (map.count(x)) continue;

            int left = map.count(x-1) ? map[x-1].first : x;
            int right = map.count(x+1) ? map[x+1].second : x;
            
            map[x] = {left, right};
            map[left] = {left, right};
            map[right] = {left, right};
            
            res = max(res, right-left+1);
        }
        return res;        
    }
};
// @lc code=end

