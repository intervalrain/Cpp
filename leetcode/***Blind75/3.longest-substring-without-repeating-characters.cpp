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
    // O(n)
    int lengthOfLongestSubstring(string s) {
        int cnt[256] = {0};
        int res = 0;
        int left = 0, right = 0;
        while (right < s.length()){
            char c = s[right++];
            cnt[c]++;
            while (cnt[c] == 2){
                char d = s[left++];
                cnt[d]--;
            }
            res = max(res, right-left);
        }
        return res;
    }
};
// @lc code=end

