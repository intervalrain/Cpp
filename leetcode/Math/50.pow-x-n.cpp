#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (n == 0) return 1;
        if (n == INT_MIN) return myPow(x * x, n/2);  // x^(-2147483648) = (1/x^2)^(2147483648/2)
        if (n < 0) return myPow(1/x, -n);

        if ((n & 1) == 1)
            return x * myPow(x * x, n/2);
        return myPow(x * x, n/2);
    }
};
// @lc code=end

