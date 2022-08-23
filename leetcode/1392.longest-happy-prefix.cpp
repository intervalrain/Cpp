/*
 * @lc app=leetcode id=1392 lang=cpp
 *
 * [1392] Longest Happy Prefix
 */

// @lc code=start
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        int tab[n];
        memset(tab, 0, sizeof(tab));
        tab[0] = 0;
        int len = 0;
        int i = 1;
        while (i < n){
            if (s[i] == s[len]){
                tab[i++] = ++len;
            } else if (len == 0){
                tab[i++] = 0;
            } else {
                len = tab[len-1];
            }
        }
        return s.substr(0, tab[n-1]);
    }
};
// @lc code=end

