#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m-- + n-- - 1;
        while (m >= 0 && n >= 0){
            if (nums1[m] <= nums2[n]){
                nums1[pos--] = nums2[n--];
            } else {
                nums1[pos--] = nums1[m--];
            }
        }
        while (n >= 0){
            nums1[pos--] = nums2[n--];
        }
    }
};
// @lc code=end

