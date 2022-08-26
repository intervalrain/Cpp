#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int left = 0, right = 0;
        int res = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right){
                res = max(res, left+right);
            } else if (right > left){
                left = right = 0;
            }
        }

        left = right = 0;

        for (int i = n-1; i >= 0; i--){
            if (s[i] == ')') right++;
            else left++;

            if (left == right){
                res = max(res, left+right);
            } else if (left > right){
                left = right = 0;
            }
        }

        return res;
    }
};
// @lc code=end

