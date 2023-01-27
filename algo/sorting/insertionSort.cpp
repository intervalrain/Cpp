#include <iostream>
#include <vector>

using namespace std;

/*
 * Insertion Sort:
 *
 * Iterate from the first index to the last index.
 * shift ahead if the previous one is bigger than itself,
 * stop until encounter a smaller element.
 *
 * Best Time Complexity: O(n)
 * Avg Time Complexity: O(n^2)
 * Worst Time Complexity: O(n^2)
 * Spaec Complexity: O(1)
 */

void sort(vector<int>& nums) {
    int i, j;
    for (i = 1; i < nums.size(); i++) {
        int curr = nums[i];
        for (j = i-1; j >= 0 && curr < nums[j]; j--) {
            nums[j+1] = nums[j];
        }
        nums[j+1] = curr;
    }
}
