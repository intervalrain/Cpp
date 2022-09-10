#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string& s, string& t) {
        if (s.length() != t.length()) return false;
        unordered_map<char,int> smap, tmap;
        smap = mapping(s);
        tmap = mapping(t);
        if (smap.size() != tmap.size()) return false;
        for (auto m : smap){
            if (!tmap.count(m.first) || tmap[m.first] != m.second) return false;
        }
        return true;
    }
    unordered_map<char,int> mapping(string& s){
        unordered_map<char,int> map;
        for (char c : s) map[c]++;
        return map;
    }
};
// @lc code=end

