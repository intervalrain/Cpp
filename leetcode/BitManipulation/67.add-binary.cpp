#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(), n = b.length();
        int len = max(m--, n--);
        string res(len, '0');
        int cin = 0;

        while (m >= 0 && n >= 0){
            int bita = a[m--] - '0';
            int bitb = b[n--] - '0';
            res[--len] = (bita ^ bitb ^ cin) + '0';
            cin = ((bita & bitb) || (bita & cin) || (bitb & cin));
        }
        while (m >= 0){
            int bita = a[m--] - '0';
            res[--len] = (bita ^ cin) + '0';
            cin = (bita & cin);
        }
        while (n >= 0){
            int bitb = b[n--] - '0';
            res[--len] = (bitb ^ cin) + '0';
            cin = (bitb & cin);
        }
        if (cin != 0){
            res = "1" + res;
        }
        return res;
    }
};
// @lc code=end
//
//    1010
//    1011
//    ----
//   1 1
//    0001
//   -----
//   10101
