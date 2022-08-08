#include <bits/stdc++.h>

using namespace std;


/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    // sliding window
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;
        int len = 0;
        int left = 0, right = 0;
        while (right < s.length()){
            char c = s[right++];
            window[c]++;
            while (window[c] == 2){
                char d = s[left++];
                window[d]--;
            }
            len = max(len, right - left);
        }
        return len;
    }
};
// @lc code=end

