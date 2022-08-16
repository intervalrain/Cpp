#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int wordNum = words.size();
        int wordLen = words[0].length();
        int validLen = wordNum * wordLen;
        
        unordered_map<string,int> need;  // {{foo, 1},{bar, 1}}
        for (string word : words){
            need[word]++;
        }
        vector<int> res;

        if (s.length() < validLen) return res;

        for (int i = 0; i < wordLen; i++){
            unordered_map<string,int> window;
            int valid = 0;
            int left = i, right = i;
            while (right < n){
                string c = s.substr(right, wordLen);
                right += wordLen;
                window[c]++;
                if (need.count(c) && need[c] == window[c]) valid++;
                if (right - left == validLen){
                    if (valid == need.size()){
                        res.push_back(left);
                    }
                    string d = s.substr(left, wordLen);
                    if (need.count(d) && need[d] == window[d]) valid--;
                    window[d]--;
                    left += wordLen;
                }
            }
        }
        return res;
    }
};
// @lc code=end

