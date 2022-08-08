/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        int f0 = 0;
        int f1 = 1;
        int f2;
        for (int i = 2; i <= n; i++){
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};
// @lc code=end

