#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int earn = 0;
        int cost = -prices[0];
        for (int i = 1; i < prices.size(); i++){
            int tmp = cost;
            cost = max(cost, earn - prices[i]);
            earn = max(earn, tmp + prices[i] - fee);
        }
        return earn;
    }
};
// @lc code=end
 
//       1  3  2  8  4  9
// cost -1 -1 -1 -1  1  1 
// earn  0  0  0  5  5  8

//       1  3  7  5 10  3
// cost -1 -1 -1 -1 -1  3 
// earn  0  0  3  3  6  6

