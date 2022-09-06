#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) return (uniquePaths(n, m));
        vector<int> dp(m, 1);
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                dp[j] += dp[j-1];
            }
        }
        return dp[m-1];
    }
};
// @lc code=end

// 1 1 1 1  1  1  1
// 1 2 3 4  5  6  7
// 1 3 6 10 15 21 28
