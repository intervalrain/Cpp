#include <iostream>
#include <vector>

using namespace std;

/**
 * Quick Sort:
 *
 * Picking a pivot element from the array and partitioning the remaining elements into two subarrays.
 * Two subarrays are based on whether they are greater or less than the pivot.
 * Quicksort has a better locality of reference than merge sort,
 * so that accesses are usually faster than merge sort accesses.
 *
 * Best Time Complexity: O(nlogn)
 * Avg Time Complexity: O(nlogn)
 * Worst Time Complexity: O(n^2)
 * Space Complexity: O(logn)
 */

int partition(vector<int>& nums, int left, int right) {
    int pivot = right;
    while (left < right) {
        while (nums[left] < nums[pivot]) left++;
        while (nums[right] > nums[pivot]) right--;
        if (left < right) {
            swap(nums[left], nums[right]);
        }
    }
    swap(nums[left], nums[pivot]);
    return left;

}

void helper(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int pivot = partition(nums, left, right);
    helper(nums, left, pivot-1);
    helper(nums, pivot+1, right);
}

void sort(vector<int>& nums) {
    helper(nums, 0, nums.size()-1);
}
