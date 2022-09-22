#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string path;
        helper(s, wordDict, res, path);
        return res;
    }
    void helper(string s, vector<string>& wordDict, vector<string>& res, string path){
        if (s.length() == 0){
            res.push_back(path.substr(0, path.length()-1));
        }
        for (string& word : wordDict){
            if (isPrefix(s, word)){
                path += (word + " ");
                helper(s.substr(word.length()), wordDict, res, path);
                path = path.substr(0, path.length() - 1 - word.length());
            }
        }
    }
    
    bool isPrefix(string s, string t){
        if (t.length() > s.length()) return false;
        return s.substr(0, t.length()) == t;
    }
};
// @lc code=end

