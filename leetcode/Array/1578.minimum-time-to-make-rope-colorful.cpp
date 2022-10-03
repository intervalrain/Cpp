#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0;
        int n = neededTime.size();
        int localMax = 0, sum = 0, res = 0;
        char curr = '#';
        while (i < n){
            if (curr != colors[i]){
                curr = colors[i];
                res += sum - localMax;
                localMax = sum = neededTime[i];
            } else {
                sum += neededTime[i];
                localMax = max(localMax, neededTime[i]);
            }
            i++;
        }
        res += sum - localMax;
        return res;
    }
};
// @lc code=end

