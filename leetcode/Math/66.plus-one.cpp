#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int cin = 1;
        for (int i = n-1; i >= 0; i--){
            if (cin == 0) break;
            digits[i] += cin;
            if (digits[i] == 10){
                digits[i] = 0;
                cin = 1;
            } else {
                cin = 0;
            }
        }
        if (cin == 1) digits.insert(digits.begin(), cin);
        return digits;
    }
};
// @lc code=end

