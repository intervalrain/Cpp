#include <iostream>
#include <vector>

using namespace std;

/**
 * Bubble Sort:
 *
 * Swap two nearest item if the previous one is bigger
 * One value will pop up from the last index to the first index each round.
 *
 * Best time Complexity: O(n)
 * Avg Time Complexity: O(n^2)
 * Worst Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

void sort(vector<int>& nums){
    for (int i = 0; i < nums.size()-1; i++) {
        for (int j = 1; j < nums.size()-i; j++) {
            if (nums[j-1] > nums[j]) {
                swap(nums[j-1], nums[j]);
            }
        }
    }
}
