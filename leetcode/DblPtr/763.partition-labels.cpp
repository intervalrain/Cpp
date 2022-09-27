#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>> map;
        vector<int> res;
        for (int i = 0; i < s.length(); i++){
            if (map.find(s[i]) == map.end()){
                map[s[i]] = {i,i};
            } else {
                map[s[i]].second = i;
            }
        }
        vector<pair<int,int>> intervals;
        for (auto mp : map){
            intervals.push_back({mp.second.first, mp.second.second});
        }
        sort(intervals.begin(), intervals.end());
        int left = 0, right = 0;
        for (auto p : intervals){
            if (p.first <= right){
                right = max(right, p.second);
            } else {
                res.push_back(right-left+1);
                left = p.first;
                right = p.second;
            }
        }
        res.push_back(right-left+1);
        return res;
    }
};
// @lc code=end


// 
// ababcbaca defegde hijhklij
//             ^
//      5
// 

