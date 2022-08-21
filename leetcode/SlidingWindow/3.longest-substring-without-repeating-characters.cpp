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
        int res = 0;
        int memo[256] = {0};
        int left = 0, right = 0;
        while (right < s.length()){
            int& c = memo[s[right]];
            c++;
            right++;
            while (c == 2){
                int& d = memo[s[left]];
                d--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
// @lc code=end

