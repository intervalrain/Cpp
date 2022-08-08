#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int len = m + n;
        if ((len & 1) == 1){
            return kth(nums1, nums2, 0, 0, len/2+1);
        } else {
            return (kth(nums1, nums2, 0, 0, len/2+1) + kth(nums1, nums2, 0, 0, len/2))/2;
        }
    }

    /**
     * @brief to return the kth element of the two arrays, O(log(m+n))
     * 
     * @param nums1 
     * @param nums2 
     * @param i: the start position of nums1
     * @param j: the start position of nums2
     * @param k: the kth element we gonna find(1-index);
     * @return double 
     */
    double kth(vector<int>& nums1, vector<int>& nums2, int i, int j, int k){
        int m = nums1.size(), n = nums2.size();
        if (i == m) return nums2[j + k - 1];
        if (j == n) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);

        int mid1 = (i + k/2 - 1 < m) ? nums1[i + k/2 - 1] : INT_MAX;
        int mid2 = (j + k/2 - 1 < n) ? nums2[j + k/2 - 1] : INT_MAX;
        if (mid1 < mid2){
            return kth(nums1, nums2, i + k/2, j, k - k/2);
        } else {
            return kth(nums1, nums2, i, j + k/2, k - k/2);
        }

        //  1,2,2,3,5,6,8,8,9 (nums1)
        //      ^ o o o               ^ = i,    total of o = k
        //  0,3,3,4,4,4,4,6,7 (nums2)
        //        ^ o o               ^ = j,
    }
};
// @lc code=end

