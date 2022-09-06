#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.length();
        int single = 1, couple = 0;
        for (int i = 1; i < n; i++){
            if (s[i] == '0'){
                if (s[i-1] == '0' || s[i-1] >= '3' || single == 0) return 0;
                couple = single;
                single = 0;
            } else if (s[i-1] >= '3' || (s[i-1] == '2' && s[i] >= '7')){
                single = single + couple;
                couple = 0;
            } else {
                int tmp = single;
                single = single + couple;
                couple = tmp;
            }
        }
        return single + couple;
    }
};
// @lc code=end

//       2 2 6 0
// sing: 1 1 2 
// coup: 0 1 1
