#include <iostream>
using namespace std;

/**
 * Kth smallest element (Medium)
 *
 * Given an array arr[] and an integer K where K is smaller than size of array,
 * the task is to fine the Kth smallest element in the given array.
 * It is given that all array elements are distinct.
 */

class Solution{
public:
    int kthSmallest(int arr[], int l, int r, int k){
        sort(arr, arr + r + 1);
        return arr[k-1];
    }
};

int main(){
    Solution* sol = new Solution;
    int arr1[] = {7, 10, 4, 3, 20, 15};
    cout << sol->kthSmallest(arr1, 0, 5, 3) << endl;   // 7

    int arr2[] = {7, 10, 4, 20, 15};
    cout << sol->kthSmallest(arr2, 0, 4, 4) << endl;   // 15
}
