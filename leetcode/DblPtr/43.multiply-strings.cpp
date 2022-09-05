#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        int len = m + n;
        string s(len, '0');
        for (int i = m-1; i >= 0; i--){
            for (int j = n-1; j >= 0; j--){
                int pos = i + j + 1;
                int cin = pos - 1;
                int multi = (num1[i]-'0')*(num2[j]-'0')+(s[pos]-'0');
                s[pos] = (multi % 10) + '0';
                s[cin] += (multi/10);
            }
        }
        cout << s << endl;
        int i = 0;
        for (; i < len; i++){
            if (s[i] != '0') break;
        }
        s = s.substr(i);
        return s.length() == 0 ? "0" : s;
    }
};
// @lc code=end