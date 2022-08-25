#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return *max_element(nums.begin(), nums.end());
        vector<int> first(n, 0);
        vector<int> second(n, 0);
        int res = 0;
        first[0] = nums[0];
        first[2] = nums[2] + first[0];
        second[1] = nums[1];
        second[2] = nums[2];
        res = max3(res, first[2], second[1]);
        for (int i = 3; i < n-1; i++){
            first[i] = max(first[i-2], first[i-3]) + nums[i];
            second[i] = max(second[i-2], second[i-3]) + nums[i];
            res = max3(res, first[i], second[i]);
        }
        second[n-1] = max(second[n-3], second[n-4]) + nums[n-1];
        return max(res, second[n-1]);
    }
    int max3(int a, int b, int c){
        return max(max(a,b),c);
    }
};
// @lc code=end

//  1, 2, 3, 4, 5, 1, 2, 3, 4, 5
//  1, 0, 4
//  0, 2, 3