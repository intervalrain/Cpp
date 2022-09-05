#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string res;
        int left = 0, right = 0;
        while (right < s.length()){
            while (s[left] == ' ' && left < s.length()){
                left++;
            } 
            right = left;
            while (s[right] != ' ' && right < s.length()){
                right++;
            }
            if (right-left > 0){
                vec.push_back(s.substr(left, right-left));
            }
            left = right;
        }
        for (int i = vec.size()-1; i > 0; i--){
            res = res + vec[i] + " ";
        }
        res = res + vec[0];
        return res;
    }
};
// @lc code=end

//s = "  hello world  "
//                    ^
//                    ^
