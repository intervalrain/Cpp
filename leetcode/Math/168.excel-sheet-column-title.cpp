#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber){
            char c = (columnNumber-1) % 26 + 'A';
            s = c+s;
            columnNumber = (columnNumber-1)/26;
        }
        return s;
    }
};
// @lc code=end


// 701 = 26*26 + 25
// 1234567890
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
