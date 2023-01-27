#include <iostream>
#include <vector>

using namespace std;

/**
 * Heap Sort:
 *
 * Sort by a binary heap, construct a min-heap,
 * drag to the top of the heap or pull down of the heap according to the value of the element
 *
 * Best Time Complexity: O(nlogn)
 * Avg Time Complexity: O(nlogn)
 * Worst Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 */

void heapify(vector<int>& nums, int n, int i) {
    int x = i;
    int left = i*2+1;
    int right = i*2+2;
    if (left < n && nums[left] > nums[x])
        x = left;
    if (right < n && nums[right] > nums[x])
        x = right;
    if (x != i) {
        swap(nums[i], nums[x]);
        heapify(nums, n, x);
    }

}

void sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n/2-1; i >= 0; i--) {
        heapify(nums, n, i);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }

}
