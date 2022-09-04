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
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        int m = max(row, col);
        int n = min(row, col);
        bool flag = row > col;
        int sums[m];
        for (int l = 0; l < n; ++l){
            memset(sums, 0, sizeof(sums));
            for (int r = l; r < n; ++r){
                for (int i = 0; i < m; ++i){
                    sums[i] += (flag ? matrix[i][r] : matrix[r][i]);
                }
                
                int curr = INT_MIN;
                for (int i = 0, sum = 0; curr <= k && i < m; ++i){
                    curr = max(curr, sum = sum > 0 ? sum + sums[i] : sums[i]);
                    if (curr == k) return k;
                }
                if (curr < k){
                    res = max(res, curr);
                    continue;
                }
                for (int i = 0; i < m; ++i){
                    for (int j = i, sum = 0; j < m; ++j){
                        if ((sum += sums[j]) <= k) res = max(res, sum);
                    }
                    if (res == k) return k;
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

