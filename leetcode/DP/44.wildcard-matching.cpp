#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    bool helperMatch(const char* s, const char* p){
        const char* strAtStar = NULL;
        const char* starSeen = NULL;
        
        //While we haven't reached the end of the string
        while(*s) {
            
            //Str compare
            if(*p== '?' || *s == *p){
                p++;
                s++;
                continue;
            }
            
            //If we see a star pattern
            if(*p == '*') {
                starSeen = p;
                p = ++starSeen;
                strAtStar = s;
                continue;
            }
            
            //If we saw a star pattern in the past
            if(starSeen) {
                s = ++strAtStar;
                p = starSeen;
                continue;
            }
            
            
            return false;
        }
        
        
        while(*p== '*'){
            p++;
        }
        
        return !*p;
    }
        
    bool isMatch(string s, string p) {
        return helperMatch(s.c_str(), p.c_str());
    }


    // bool isMatch(string s, string p){
    //     int n = s.length(), m = p.length();
    //     vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    //     dp[0][0] = true;
    //     for (int i = 1; i <= m; i++){
    //         if (p[i-1] == '*') dp[i][0] = dp[i-1][0];
    //         for (int j = 1; j <= n; j++){
    //             if (p[i-1] == s[j-1] || p[i-1] == '?'){
    //                 dp[i][j] = dp[i-1][j-1];
    //             } else if (p[i-1] == '*'){
    //                 dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
    //             }   
    //         }
    //     }
    //     return dp[m][n];
    // }
    
    // bool isMatch(string s, string p) {
    //     if (p.length() == 0) return s.length() == 0;
    //     if (s.length() == 0) return p.length() == 0 || (p[0] == '*' && isMatch(s, p.substr(1)));
    //     if (s[0] == p[0] || p[0] == '?')
    //         return isMatch(s.substr(1), p.substr(1));
    //     else if (p[0] == '*')
    //         return isMatch(s, p.substr(1)) || isMatch(s.substr(1), p) || isMatch(s.substr(1), p.substr(1));
    //     return false;
    // }                                                                                             ab*bbab*bb*b****ba*ab*ba*aba**b***aa*b*a*bbbaaa*a**bb*b*****aab**b*****a*abaab*a*aba**a*a*aaab*****abba
};
// @lc code=end

//  _aa
// _o..
// *ooo

//  _adceb
// _o.....
// *oooooo
// a.o....
// *.ooooo
// b.....o
