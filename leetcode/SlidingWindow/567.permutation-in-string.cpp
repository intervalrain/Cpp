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
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s.length()){
            char c = s[right++];
            if (need.count(c)){
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            while (right - left >= t.length()){
                if (valid == need.size())
                    return true;
                char d = s[left++];
                if (need.count(d)){
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

