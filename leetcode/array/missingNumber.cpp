#include <iostream>
#include <vector>
using namespace std;

/**
 * Missing number in array (Easy)
 *
 * Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N.
 * Find th missing element.
 *
 * expected auxiliary space: O(1)
 */

class Solution{
public:
    int missingNumber(vector<int>& arr, int n){
        int sum = 0;
        for (int i = 0; i < n-1; i++){
            sum += arr[i];
        }
        return n*(n+1)/2-sum;
    }
};


int main(){

    Solution* sol = new Solution;
    int n = 5;
    vector<int> arr1 = {1,2,3,5};
    cout << sol->missingNumber(arr1, n);

    n = 10;
    vector<int> arr2 = {6,1,2,8,3,4,7,10,5};
    cout << sol->missingNumber(arr2, n);

    return 0;
}
