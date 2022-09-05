#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    // O(n)
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int res = 0;
        do {
            res = max(res, area(height, left, right));
            if (height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        } while (left < right);
        return res;
    }
    int area(vector<int>& height, int left, int right){
        return min(height[right], height[left]) * (right - left);
    }
};
// @lc code=end

