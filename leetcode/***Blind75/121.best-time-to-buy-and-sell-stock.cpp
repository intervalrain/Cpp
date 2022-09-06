#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int earn = 0;
        int cost = INT_MIN;
        for (int i = 0; i < prices.size(); i++){
            cost = max(cost, -prices[i]);
            earn = max(earn, cost+prices[i]);
        }
        return earn;
    }
};
// @lc code=end


//       7  1  5  3  6  4
// cost -7 -1 -1 -1 -1 -1
// earn  0  0  4  4  5  5