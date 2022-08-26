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
        int res = 0;
        int cost = -prices[0];
        int earn = prices[0];
        for (int i = 0; i < prices.size(); i++){
            cost = max(cost, -prices[i]);
            res = max(res, cost + prices[i]);
        }
        return res;
    }
};
// @lc code=end

//   7,1,5,3,6,4
// 
//  
