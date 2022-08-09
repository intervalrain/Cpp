#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
class Solution {
// dp[x] = sum(dp[x/f]*dp[f]) + 1
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int,long long> dp;
        long long MOD = pow(10,9)+7, cnt = 0;
        for (int i = 0; i < arr.size(); i++){
            int x = arr[i];
            dp[x] = 1;
            for (int j = 0; j <= i && arr[j] <= sqrt(x); j++){
                int f = arr[j];
                if (dp.count(x/f) && ((x/f) * f == x)){
                    if (x/f == f){
                        dp[x] = (dp[x] + (dp[x/f] * dp[f])) % MOD;
                    } else {
                        dp[x] = (dp[x] + 2 * (dp[x/f] * dp[f])) % MOD;
                    }
                    
                }
            }
            cnt = (cnt + dp[x]) % MOD;
        }
        return cnt % MOD;
    }
};
// @lc code=end

