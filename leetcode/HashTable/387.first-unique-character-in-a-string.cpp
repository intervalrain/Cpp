/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        int map[26] = {0};
        for (int i = 0; i < s.length(); i++){
            map[s[i]-'a']++;
        }
        for (int i = 0; i < s.length(); i++){
            if (map[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};
// @lc code=end



