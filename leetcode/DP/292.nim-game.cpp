#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        // if (n <= 3) return true;
        // bool dp[n+1];
        // dp[0] = false;
        
        // for (int i = 1; i <= n; i++){
        //     dp[i] = (!dp[i-1] || !dp[i-2] || !dp[i-3]);
        // }
        // return dp[n];
        return !(n % 4 == 0);
    }
};
// @lc code=end

// dp[1] = win
// dp[2] = win
// dp[3] = win
// dp[i] = (!dp[i-1] || !dp[i-2] || !dp[i-3])
// dp[4] = (!dp[1] || !dp[2] || !dp[3]) = false

// dp[i][j]   i: how many nim left,
//            j: I(0) move or he/she(1) move
// dp[1] = true
// dp[2] = true
// dp[3] = true
// dp[4] = false
// dp[5] = true
// dp[6] = true
// dp[7] = true
// dp[8] = false
// ...
