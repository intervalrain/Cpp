#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;
        string res;
        for (int i = 0, len = 0; i < n; i++){
            for (int j = 0, k = i; k < s.length(); j++){
                res.push_back(s[k]);
                len++;
                k += ((i == 0 || j % 2 == 0) && i != n - 1 ? 2 * (n - i - 1) : 2 * i);
            }
        }
        return res;
    }
};
// @lc code=end

