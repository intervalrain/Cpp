/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    vector<int> tab;
    int strStr(string& txt, string& pat) {
        init(pat);
        int i = 0, j = 0;
        while (i < txt.length() && j < pat.length()){
            if (txt[i] == pat[j]){
                i++;
                j++;
            } else if (j == 0){
                i++;
            } else {
                j = tab[j-1];
            }
        }
        return j == pat.length() ? i - j : -1; 
    }
    void init(string& x){
        int n = x.length();
        tab = vector<int>(n, 0);
        tab[0] = 0;
        int i = 1, len = 0;
        while (i < n){
            if (x[i] == x[len]){
                tab[i++] = ++len;
            } else if (len == 0){
                tab[i++] = 0;
            } else {
                len = tab[len-1];
            }
        }
    }
};
// @lc code=end

