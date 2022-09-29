#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> svec;
        for (const auto& x : nums) svec.push_back(to_string(x));
        sort(svec.rbegin(), svec.rend(), [](string a, string b){
            return a + b < b + a;
        });
        string res;
        for (const auto& s : svec) res += s;
        int i = 0;
        for (; i < res.length(); i++){
            if (res[i] != '0') break;
        }
        res = res.substr(i);
        return res.length() == 0 ? "0" : res;
    }
};
// @lc code=end

