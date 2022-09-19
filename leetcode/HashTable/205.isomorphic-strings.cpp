#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return mapping(s) == mapping(t);
    }
    string mapping(string& s){
        unordered_map<char, int> map;
        string res;
        for (int i = 0; i < s.length(); i++){
            if (!map.count(s[i])){
                map[s[i]] = map.size();
            }
            res.push_back(map[s[i]]);
        }
        return res;
    }
};
// @lc code=end

