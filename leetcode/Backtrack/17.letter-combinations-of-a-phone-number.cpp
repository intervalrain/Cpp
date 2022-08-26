#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        vector<string> map = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string path;
        backtrack(digits, map, res, path, 0);
        return res;
    }
    void backtrack(string& digits, vector<string>& map, vector<string>& res, string& path, int i){
        if (i == digits.length()){
            res.push_back(path);
            return;
        }
        char c = digits[i];
        string str = map[c-'2'];
        for (char x : str){
            path.push_back(x);
            backtrack(digits, map, res, path, i+1);
            path.pop_back();
        }
    }
};
// @lc code=end