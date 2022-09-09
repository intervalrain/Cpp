#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    vector<bool> visited;
    bool wordBreak(string s, vector<string>& wordDict) {
        visited = vector<bool>(s.length()+1, false);
        return solve(s, wordDict);
    }
    bool solve(string s, vector<string>& wordDict) {
        if (s.length() == 0) return true;
        if (visited[s.length()]) return false;
        for (const auto& word : wordDict){
            if (isPrefix(s, word)){
                bool res = solve(s.substr(word.length()), wordDict);
                if (res) return true;
                visited[s.length()] = true;
            }
        }
        return false;
    }
    bool isPrefix(string s, string prefix){
        if (s.length() < prefix.length()) return false;
        return s.substr(0, prefix.length()) == prefix;
    }
};
// @lc code=end

// applepenapple
