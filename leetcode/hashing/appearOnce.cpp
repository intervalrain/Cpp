#include <iostream>
using namespace std;

/**
 * Find the element that appears once in sorted array (Basic)
 *
 * Given a sorted array arr[] of size n.
 * Find the element that appears only once in the array.
 * All other elements appear exactly twice.
 */

class Solution{
public:
    int findOnce(int arr[], int n){
        if (n == 1) return arr[0];
        if (n == 3) return arr[0] == arr[1] ? arr[2] : arr[0];
        int left = 0, right = n - 1;
        int mid;
        while (left <= right){
            mid = left + (right - left)/2;
            if (mid == 0){
                if (arr[mid] != arr[mid+1]) return arr[mid];
                left = mid + 1;
            } else if (mid == n - 1){
                if (arr[mid] != arr[mid-1]) return arr[mid];
            } else if ((mid & 1) == 0){
                if (arr[mid] == arr[mid+1]){
                    left = mid + 1;
                } else if (arr[mid] == arr[mid-1]){
                    right = mid - 1;
                } else {
                    break;
                }
            } else if ((mid & 1) == 1){
                if (arr[mid] == arr[mid+1]){
                    right = mid - 1;
                } else if (arr[mid] == arr[mid-1]){
                    left = mid + 1;
                } else {
                    break;
                }
            }
        }
        return arr[mid];
    }
};

int main(){
    Solution* sol = new Solution;
    int n = 11;
    int arr[] = {1,1,2,2,3,3,4,50,50,65,65};
    cout << sol->findOnce(arr, n) << endl;

    return 0;
}
