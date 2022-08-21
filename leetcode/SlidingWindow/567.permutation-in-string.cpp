#include <bits/stdc++.h>

using namespace std;


/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    // sliding window
    bool checkInclusion(string t, string s) {
        int need[26] = {0};
        int window[26] = {0};
        int len = 0;
        int valid = 0;
        int left = 0, right = 0;
        for (char c : s1){
            int& cnt = need[c-'a'];
            cnt++;
            if (cnt == 1) len++;
        }
        while (right < s2.length()){
            char c = s2[right++];
            window[c-'a']++;
            if (window[c-'a'] == need[c-'a']) valid++;
            while (valid == len){
                if (right - left == s1.length()) return true;
                char d = s2[left++];
                if (window[d-'a'] == need[d-'a']) valid--;
                window[d-'a']--;
            }
            
        }
        return false;
    }
};
// @lc code=end

