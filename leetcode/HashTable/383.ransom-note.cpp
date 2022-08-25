#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26] = {0};
        for (char c : magazine) map[c-'a']++;
        for (char c : ransomNote) {
            map[c-'a']--;
            if (map[c-'a'] < 0) return false;
        }
        return true;
    }
};
// @lc code=end

