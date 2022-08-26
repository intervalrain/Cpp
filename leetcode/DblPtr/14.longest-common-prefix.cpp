#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].length();
        string s;
        for (int i = 0; i < strs.size(); i++){
            for (int j = 0; j < n; j++){
                if (strs[0][j] != strs[i][j]){
                    n = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, n);
    }
    // string longestCommonPrefix(vector<string>& strs) {
    //     if (strs.size() == 1) return strs[0];
    //     string s = strs[0];
    //     for (int i = 1; i < strs.size(); i++){
    //         s = commonPrefix(s, strs[i]);
    //     }
    //     return s;
    // }
    // string commonPrefix(string& s, string& t){
    //     int n = min(s.length(), t.length());
    //     if (s.substr(0, n) == t.substr(0, n)) return s.substr(0, n);
    //     string res;
    //     for (int i = 0; i < n; i++){
    //         if (s[i] != t[i]) break;
    //         res.push_back(s[i]);
    //     }
    //     return res;
    // }
};
// @lc code=end

