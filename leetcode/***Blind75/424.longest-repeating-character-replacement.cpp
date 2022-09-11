#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        int left = 0, right = 0, res = 0, curr = 0;
        while (right < s.length()){
            char in = s[right++];
            cnt[in-'A']++;
            curr = max(curr, cnt[in-'A']);
            if (right - left - curr > k){
                char out = s[left++];
                cnt[out-'A']--;
            }
            res = max(res, right-left);
        }
        return res;
    }
};
// @lc code=end

