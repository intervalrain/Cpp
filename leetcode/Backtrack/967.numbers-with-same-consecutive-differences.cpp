/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for (int i = 1; i <= 9; i++){
            backtrack(i, res, n, k, 1);
        }
        return res;
    }
    void backtrack(int num, vector<int>& res, int n, int k, int cnt){
        if (n == cnt){
            res.push_back(num);
            return;
        }
        int mod = num % 10;
        int next;
        if ((next = mod + k) < 10) 
            backtrack(10 * num + next, res, n, k, cnt+1);
        if ((next = mod - k) >= 0 && k != 0)
            backtrack(10 * num + next, res, n, k, cnt+1);
    }
};
// @lc code=end