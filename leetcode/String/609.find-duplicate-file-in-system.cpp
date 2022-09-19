#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for (auto& path : paths){
            vector<string> vec = split(path);
            string filePath = vec[0];
            for (int i = 1; i < vec.size(); i++){
                pair<string,string> info = getTxt(vec[i]);
                map[info.second].push_back(filePath + "/" + info.first);
            }
        }
        for (const auto& m : map){
            vector<string> v = m.second;
            if (v.size() > 1) res.push_back(v);
        }

        return res;
    }
    vector<string> split(string& str){
        vector<string> res;
        int start = 0;
        int end = 0;
        for (; end < str.length(); end++){
            if (str[end] == ' '){
                res.push_back(str.substr(start, end-start));
                start = end+1;
            }
        }
        res.push_back(str.substr(start, end-start));
        return res;
    }
    pair<string,string> getTxt(string& str){
        pair<string,string> res;
        int n = str.length();
        for (int i = 0; i < n; i++){
            if (str[i] == '('){
                res = {str.substr(0, i), str.substr(i+1, n-i-2)};
                break;
            }
        }
        return res;
    }
};
// @lc code=end

