/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;

        int cost[2] = {INT_MIN};
        int earn[2] = {0};
        cost[0] = -prices[0];
        cost[1] = max(cost[0], -prices[1]);
        earn[1] = max(0, cost[1] + prices[1]);

        for (int i = 2; i < prices.size(); i++){
            cost[i%2] = max(cost[(i-1)%2], -prices[i] + earn[i%2]);
            earn[i%2] = max(earn[(i-1)%2], prices[i] + cost[i%2]);
        }

        return earn[(n-1)%2];
    }
};
// @lc code=end
//    1  2  3  0  2
//   -1 -1 
//    0  1 
