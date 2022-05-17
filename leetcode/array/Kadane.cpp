#include <iostream>
using namespace std;

/**
 * Kadane's Algorithm (Medium)
 *
 * Given an array arr[] of n integers.
 * Find the contiguous sub-array(containing at least one number)
 * which has the maximum sum and return its sum.
 */

class Solution{
public:
    long long maxSubarraySum(int arr[], int n){
        long long res = arr[0];
        long long cur = res;
        for (int i = 1; i < n; i++){
            cur = (cur < 0) ? arr[i] : cur + arr[i];
            res = max(res, cur);
        }

        return res;
    }
};

int main(){
    Solution* sol = new Solution;
    int arr1[] = {1,2,3,-2,5};
    cout << sol->maxSubarraySum(arr1, 5) << endl;

    int arr2[] = {-1,-2,-3,-4};
    cout << sol->maxSubarraySum(arr2, 4) << endl;

    return 0;
}
