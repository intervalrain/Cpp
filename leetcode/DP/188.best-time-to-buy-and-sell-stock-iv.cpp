#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> cost(k+1, INT_MIN);
        vector<int> earn(k+1, 0);
        int res = 0;

        for (int i = 0; i < n; i++){
            for (int j = k-1; j >= 0; j--){
                int c0 = cost[j];
                int e0 = earn[j];
                earn[j] = max(e0, cost[j] + prices[i]);
                cost[j] = max(c0, earn[j+1] - prices[i]);
                res = max(res, earn[j]);
            }
        }
        return res;
    }
};
// @lc code=end

// prices[i] = 2, 4, 1
//   cost[0] = x, x, x
//   earn[0] = 0, 0, 0
//   cost[1] =-2,-2,-1
//   earn[1] = 0, 2, 2
//   cost[2] = x, x,-1 
//   earn[2] = x, x, x 

//   earn[i] = cost[i] + prices[i];
//   cost[i] = earn[i+1] - prices[i];
