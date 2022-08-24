/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost = -prices[0];
        int earn = 0;

        for (int i = 1; i < prices.size(); i++){
            int tmp = cost;
            cost = max(cost, -prices[i] + earn);
            earn = max(earn, prices[i] + tmp);
        }

        return earn;
    }
};
// @lc code=end
//
//       7  1  5  3  6  4
// cost -7 -1 -1  1  1  1
// earn  0  0  4  4  7  7

