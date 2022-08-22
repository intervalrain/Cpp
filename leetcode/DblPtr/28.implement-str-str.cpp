/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class KMP {
private:
    vector<vector<int>> dp;
    string pat;
public:
    KMP(string pat){
        this->pat = pat;
        int m = pat.length();
        dp = vector<vector<int>>(m, vector<int>(256, 0));
        dp[0][pat[0]] = 1;
        int x = 0;
        for (int i = 1; i < m; i++){
            for (int j = 0; j < 256; j++)
                dp[i][j] = dp[x][j];
            dp[i][pat[i]] = i + 1;
            x = dp[x][pat[i]];
        }
    }
    int search(string txt){
        int m = pat.length();
        int n = txt.length();
        int j = 0;
        for (int i = 0; i < n; i++){
            j = dp[j][txt[i]];
            if (j == m) return i-m+1;
        }
        return -1;
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        KMP kmp(needle);
        return kmp.search(haystack);
    }
};
// @lc code=end
