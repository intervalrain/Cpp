#include <iostream>
using namespace std;

/**
 * Binary Search (Basic)
 *
 * Given a sorted array of size n and an integer k,
 * find the position at which k is present in the array using binary search.
 */

class Solution{
public:
    int binarysearch(int arr[], int n, int k){
        int left = 0;
        int right = n-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (arr[mid] == k)
                return mid;
            else if (arr[mid] > k){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution* sol = new Solution;

    int n1 = 5;
    int arr1[] = {1,2,3,4,5};
    int k1 = 4;
    cout << sol->binarysearch(arr1, n1, k1) << endl;

    int n2 = 5;
    int arr2[] = {11,22,33,44,55};
    int k2 = 445;
    cout << sol->binarysearch(arr2, n2, k2) << endl;

    return 0;
}
