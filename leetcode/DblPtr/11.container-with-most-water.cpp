/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int res = 0;
        while (left < right){
            res = max(res, area(height, left, right));
            if (height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        }
        return res;
    }

    int area(vector<int>& height, int left, int right){
        return (right-left) * min(height[left], height[right]);
    }
};
// @lc code=end

