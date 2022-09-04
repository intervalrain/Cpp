#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++){
            res = say(res);
        }
        return res;
    }
    string say(string s){
        char top = s[0];
        int cnt = 1;
        string res;
        for (int i = 1; i < s.length(); i++){
            if (top == s[i]){
                cnt++;
            } else {
                res = res + to_string(cnt);
                res.push_back(top);
                top = s[i];
                cnt = 1;
            }
        }
        res = res + to_string(cnt);
        res.push_back(top);
        return res;
    }
};
// @lc code=end

