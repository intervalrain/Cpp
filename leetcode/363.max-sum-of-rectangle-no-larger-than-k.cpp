#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
public:
    // O(min(m,n)^2 * max(m,n) * log(max(m,n)))
    // O(mlog(m)n^2)
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN;
        vector<vector<int>> sums(m, vector<int>(n));
        sums[0][0] = matrix[0][0];
        for (int i = 0; i < m; i++){
            for (int j = 1; j < n; j++){
                sums[i][j] = sums[i][j-1] + matrix[i][j];
            }
        }
        for (int l = 0; l < n; l++){
            for (int r = l; r < n; r++){
                set<int> sum;
                sum.insert(0);
                int curr = 0;
                for (int i = 0; i < m; i++){
                    curr += sums[i][r] - sums[i][l];
                    auto it = sum.lower_bound(curr - k);
                    if (it != sum.end()){
                        res = max(res, curr - *it);
                        if (res == k) return res;
                    }
                    sum.insert(curr);
                }
            }
        }
        return res;
    }
};
// @lc code=end

//  V     V
//  5 -4 -3  4  --> -4
// -3 -4  4  5  --> -3
//  5  1  5 -4  --> 11

// 1 0 1  --> 2
// 0-2 3  --> 1
