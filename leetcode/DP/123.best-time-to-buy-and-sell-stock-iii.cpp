/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost1 = -prices[0];
        int earn1 = 0;
        int cost2 = INT_MIN;
        int earn2 = 0;
        for (int i = 1; i < prices.size(); i++){
            cost1 = max(cost1, -prices[i]);
            earn1 = max(earn1, cost1 + prices[i]);
            cost2 = max(cost2, earn1 - prices[i]);
            earn2 = max(earn2, cost2 + prices[i]);
        }
        return earn2;
    }
};
// @lc code=end


