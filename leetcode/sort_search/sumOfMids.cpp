#include <iostream>
#include <vector>
using namespace std;

/**
 * Sum of Middle Elements of two sorted arrays (Medium)
 *
 * Given 2 sorted arrays arr1 and arr2 of size N each.
 * Merge the given arrays and find the sum of the two middle elements of the merged array.
 */


class Solution{
public:
    int findMidSum(int arr1[], int arr2[], int n){
        if (n == 1) return arr1[0] + arr2[0];
        if (n == 2) return max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]);
        int i = (n-1)/2;
        int j = n-i-2;
        int d = max(1, i/2);
        while (true){
            if (arr1[i] <= arr2[j+1] && arr2[j] <= arr1[i+1])
                break;
            else if (arr1[i] > arr2[j+1]){
                i -= d;
                j += d;
            } else {
                i += d;
                j -= d;
            }
            d = max(d/2, 1);
        }
        return max(arr1[i], arr2[j]) + min(arr1[i+1], arr2[j+1]);
    }
};

int main(){
    Solution* sol = new Solution;
    int arr1[] = {1,2,4,6,10};
    int arr2[] = {4,5,6,9,12};
    cout << sol->findMidSum(arr1, arr2, 5) << endl;  // 11

    int arr3[] = {1,12,15,26,38};
    int arr4[] = {2,13,17,30,45};
    cout << sol->findMidSum(arr3, arr4, 5) << endl;  // 32

    return 0;
}
