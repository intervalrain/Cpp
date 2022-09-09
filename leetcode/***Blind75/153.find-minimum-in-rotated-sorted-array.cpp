#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left < right){
            if (nums[right] > nums[left]) return nums[left];
            int mid = left + (right-left)/2;
            if (mid + 1 < n && nums[mid] > nums[mid+1]) return nums[mid+1];
            if (mid - 1 >= 0 && nums[mid-1] > nums[mid]) return nums[mid];
            if (nums[left] < nums[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};
// @lc code=end

// l-------m-------r
//     ^
// l-------m-------r
//             ^

