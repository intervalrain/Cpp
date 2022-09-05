#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    unordered_map<char,char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++){
            if (map.count(s[i])){
                st.push(map[s[i]]);
            } else if (st.empty()){
                return false;
            } else if (st.top() == s[i]){
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end

// [([])[]{}]
// ])]
