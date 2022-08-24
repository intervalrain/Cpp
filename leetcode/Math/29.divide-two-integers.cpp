/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long div = labs(dividend), dor = labs(divisor), res = 0;
        bool sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        while (div >= dor){
            long tmp = dor, cnt = 1;
            while (tmp << 1 <= div){
                tmp <<= 1;
                cnt <<= 1;
            }
            div -= tmp;
            res += cnt;
        }
        return sign ? res : -res;

    }
};
// @lc code=end
