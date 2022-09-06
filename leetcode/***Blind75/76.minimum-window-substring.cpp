#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need, window;
        string res;
        int len = INT_MAX;
        for (char c:t) need[c]++;
        int left = 0, right = 0, valid = 0;
        while (right < s.length()){
            char c = s[right++];
            if (need.count(c)){
                window[c]++;
                if (window[c] == need[c]) valid++;
                while (valid == need.size()){
                    if (right - left < len){
                        len = right - left;
                        res = s.substr(left, len);
                        if (len == t.length()) return res;
                    }
                    char d = s[left++];
                    if (need.count(d)){
                        if (window[d] == need[d]) valid--;
                        window[d]--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

// ADOBECODEBANC
//              ^
//          ^
// A:1
// B:1
// C:1