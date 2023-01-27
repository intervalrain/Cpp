#include <iostream>
#include <vector>

using namespace std;

/**
 * Merge Sort:
 *
 * Divide and conquer, separate an array into two half subarray.
 * Merge subarray when the subarray only contains two elementsm,
 * then merge two sorted subarray containing two elements, and so on.
 *
 * Best Time Complexity: O(nlogn)
 * Avg Time Compleixty: O(nlogn)
 * Worst Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 */

void merge(vector<int>& nums, int left, int mid, int right) {
    int i = left, j = mid+1;
    vector<int> res;
    while (i <= mid && j <= right) {
        int x = nums[i] < nums[j] ? nums[i++] : nums[j++];
        res.push_back(x);
    }
    while (i <= mid) res.push_back(nums[i++]);
    while (j <= right) res.push_back(nums[j++]);
    for (i = left; i <= right; i++)
        nums[i] = res[i-left];
}

void helper(vector<int>& nums, int left, int right) {
    if (right <= left) return;
    int mid = left + (right-left)/2;
    helper(nums, left, mid);
    helper(nums, mid+1, right);
    merge(nums, left, mid, right);
}

void sort(vector<int>& nums) {
    helper(nums, 0, nums.size()-1);
}
