#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> lis;
        int len = 0;
        for (int x : nums){
            if (lis.size() == 0){
                lis.push_back(x);
                len++;
                continue;
            }
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()){
                lis.push_back(x);
                len++;
                if (len == 3) return true;
            } else {
                *it = x;
            }
        }
        return false;
    }
};
// @lc code=end

