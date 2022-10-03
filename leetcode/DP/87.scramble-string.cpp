#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution {
public:
    map<pair<string,string>,bool> dp;
    bool isScramble(string s, string t) {
        // prune 1: dp
        if (dp.count({s,t})) return dp[{s,t}];

        if (s == t) return true;

        // prune 2: length check
        if (s.length() != t.length()) return false;
        int n = s.length();

        // prune 3: anagram check
        int cnt[26] = {0};
        for (int i = 0; i < n; i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (cnt[i] != 0) return false;
        }

        // prune 4: n <= 3 must be scramble if they are anagrams
        if (n <= 3) return true;

        for (int i = 1; i < n; i++){
            if (isScramble(s.substr(0, i), t.substr(0, i)) && isScramble(s.substr(i), t.substr(i))) {
                dp[{s,t}] = true;
                return true;
            }
            if (isScramble(s.substr(0, i), t.substr(n-i)) && isScramble(s.substr(i), t.substr(0, n-i))) {
                dp[{s,t}] = true;
                return true;
            }
        }        
        dp[{s,t}] = false;
        return false;
    }
};
// @lc code=end

// T(n) = T(i) + T(n-i) for i to n-1
// T(n)   = 4 * SUM(T_{1, n-1}) = 4 * SUM (T_{1, n-2}) + 4 * T(n-1)
// T(n-1) = 4 * SUM(T_{1, n-2})

// T(n) = T(n-1) + 4 * T(n-1)
// T(n) = 5T(n-1)
//      = 5*5T(n-2)
//      = 5^n T(1) 
// time complexity : O(5^n)
