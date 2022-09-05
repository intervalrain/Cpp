#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for (auto m : map){
            res.push_back(m.second);
        }
        return res;
    }
};
// @lc code=end

