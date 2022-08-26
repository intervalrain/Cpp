#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) return s.length() == 0;
        bool firstMatch = s.length() > 0 && (s[0] == p[0] || p[0] == '.');

        if (p.length() >= 2 && p[1] == '*'){
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        }
        return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
};
// @lc code=end
