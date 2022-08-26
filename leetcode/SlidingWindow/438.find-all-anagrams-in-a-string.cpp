#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int window[26] = {0};
        int need[26] = {0};
        int left = 0, right = 0;
        int len = 0;
        int valid = 0;
        int n = s.length();
        vector<int> res;
        for (char c : p){
            int& cnt = need[c-'a'];
            cnt++;
            if (cnt == 1) len++;
        } 
        while (right < n){
            char& c = s[right];
            right++;
            if (need[c-'a'] > 0){
                window[c-'a']++;
                if (window[c-'a'] == need[c-'a']) valid++;
            }
            if (right - left == p.length()){
                if (valid == len) res.push_back(left);
                char& d = s[left];
                left++;
                if (need[d-'a'] > 0){
                    if (window[d-'a'] == need[d-'a']) valid--;
                    window[d-'a']--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
