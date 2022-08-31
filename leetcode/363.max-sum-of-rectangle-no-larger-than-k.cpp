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
        int row = matrix.size(), col = matrix[0].size();
        int m = min(row, col);
        int n = max(row, col);
        bool flag = col > row;
        int res = INT_MIN;
        for (int i = 0; i < m; i++){
            vector<int> sums(n);
            for (int j = i; j >= 0; j--){
                int curr = 0;
                set<int> acc;
                acc.insert(0);
                for (int x = 0; x < n; x++){
                    sums[x] = sums[x] + (flag ? matrix[j][x] : matrix[x][j]);
                    curr += sums[x];
                    auto it = lower_bound(acc.begin(), acc.end(), curr - k);
                    if (it != acc.end()){
                        res = max(res, curr - *it);
                    }
                    acc.insert(curr);
                }
            }
        }
        return res;
    }
};
// @lc code=end

//  1  1  2
//  0 -2  1
