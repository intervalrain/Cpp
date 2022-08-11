#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
#define INF 10000
class Solution {
public:
    unordered_map<char, vector<int>> map;
    int findRotateSteps(string& ring, string& key) {
        int m = key.length(), n = ring.length();
        unordered_map<char,vector<int>> map;
        int res = INF;
        for (int i = 0; i < n; i++) map[ring[i]].push_back(i);

        int dp[2][n];
        memset(dp, INF, sizeof(dp));
        // vector<vector<int>> dp(2, vector<int>(n, INF));
        dp[0][0] = 0;
        for (int i = 1; i < m + 1; i++){
            for (int j = 0; j < n; j++){
                if (ring[j] == key[i-1]){
                    for (int k = 0; k < n; k++){
                        if (dp[(i-1)%2][k] != INF){
                            int diff = min(abs(k-j), n-abs(k-j));
                            dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][k] + diff);
                        }
                    }
                }
                if (i == m) {
                    res = min(res, dp[i%2][j]);
                }
            }
            memset(dp[(i-1)%2], INF, sizeof(dp[0]));
        }
        return res + m;
    }
};
// @lc code=end
//
// ring = ADBFEDBCD --> key = ABCDEF
//     
//        /--2--B--4--\ /--1--D--4--\ 
// A--0--A             C---2--D--1---E--1--F
//        \--3--B--1--/ \--3--D--3--/
//
//    A D B F E D B C D (j) ring
//  - 0 + + + + + + + +
//  A 0 + + + + + + + +
//  B + + 2 + + + 3 + +
//  C + + + + + + + 4 +
//  D + 7 + + + 6 + + 5
//  E + + + + 7 + + + +
//  F + + + 8 + + + + +
// (i)
// key

