#include <iostream>
#include <vector>

using namespace std;

/*
 * Selection Sort:
 *
 * Find the minimum value in the remaining array.
 * Fix one item each round from the first index to the last index.
 * Swap the min value with the value of the stagged index.
 *
 * Best Time Complexity: O(n^2)
 * Avg Time Complexity: O(n^2)
 * Worst Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

void sort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int sel = i;
        for (int j = i+1; j < nums.size(); j++) {
            sel = nums[sel] > nums[j] ? j : sel;
        }
        swap(nums[sel], nums[i]);
    }
}
