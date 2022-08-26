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
        int need[256] = {0};
        int window[256] = {0};
        string res = "";
        int left = 0, right = 0;
        int valid = 0;
        int len = 0;
        int curr = INT_MAX;
        for (char c : t){
            int& cnt = need[c];
            cnt++;
            if (cnt == 1) len++;
        } 
        while (right < s.length()){
            char& c = s[right];
            right++;
            if (need[c] > 0){
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            while (valid == len){
                if (right - left < curr){
                    curr = right - left;
                    res = s.substr(left, curr);
                }
                char& d = s[left];
                left++;
                if (need[d] > 0){
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

