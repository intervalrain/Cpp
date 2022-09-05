#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1, lh = 0, rh = 0, res = 0;
        while (left < right){
            lh = max(height[left], lh);
            rh = max(height[right], rh);
            if (lh < rh){
                res += (lh - height[left]);
                left++;
            } else {
                res += (rh - height[right]);
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

