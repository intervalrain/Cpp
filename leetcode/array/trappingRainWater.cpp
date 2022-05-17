#include <iostream>
#include <vector>
using namespace std;

/**
 * Teapping Rain Water (Medium)
 *
 * Given an array arr[] of N non-negative integers representing the height of blocks.
 * If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.
 */

class Solution{
public:
    long long trappingWater(int arr[], int n){
        int left[n], right[n];
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for (int i = 1; i < n; i++){
            left[i] = max(left[i-1],arr[i]);
        }
        for (int i = n-2; i >= 0; i--){
            right[i] = max(right[i+1],arr[i]);
        }
        long long res = 0;
        for (int i = 0; i < n; i++){
            res += min(left[i], right[i]) - arr[i];
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution;
    int arr1[] = {3,0,0,2,0,4};
    cout << sol->trappingWater(arr1, 6) << endl;    // 10

    int arr2[] = {7,4,0,9};
    cout << sol->trappingWater(arr2, 4) << endl;    // 10

    int arr3[] = {6,9,9};
    cout << sol->trappingWater(arr3, 3) << endl;    // 0

    return 0;
}
