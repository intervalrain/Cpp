#include <iostream>
using namespace std;

/**
 * Merge Without Extra Space (Hard)
 *
 * Given two sorted arrays arr1[] nad arr2[] of sizes n and m in non-decreasing order.
 * Merge them in sorted order without using any extra space.
 * Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
 */

class Solution{
public:
    void merge(int arr1[], int arr2[], int n, int m){
        int i = n - 1, j = 0;
        while (i >= 0 && j < m){
            if (arr1[i] <= arr2[j])
                break;
            swap(arr1[i--], arr2[j++]);
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

void print(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    Solution* sol = new Solution;
    int n = 4, m = 5;
    int arr1[] = {1,3,5,7};
    int arr2[] = {0,2,6,8,9};
    sol->merge(arr1, arr2, n, m);
    print(arr1, n);
    print(arr2, m);
}
