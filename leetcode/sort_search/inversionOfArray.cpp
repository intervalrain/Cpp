#include <iostream>
using namespace std;

/**
 * Count Inversions (Medium)
 *
 * Given an array of integers. Find the Inversion Count in the array.
 * Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
 * If array is already sorted then the inversion count is 0.
 * If an array is sorted in the reverse order then the inversion count is the maximum.
 * Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 */

class Solution{
public:
    int cnt = 0;
    int inversionCount(int arr[], int n){
        mergeSort(arr, 0, n-1);
        return cnt;
    }

    void merge(int arr[], int l, int m, int r){
        int i = l, j = m + 1, k = 0;
        int newarr[r - l + 1];
        while (i <= m && j <= r){
            if (arr[i] <= arr[j]){
                newarr[k++] = arr[i++];
            } else {
                newarr[k++] = arr[j++];
                cnt += (m+1-i);
            }
        }
        while (i <= m) newarr[k++] = arr[i++];
        while (j <= r) newarr[k++] = arr[j++];
        for (i = 0; i < r - l + 1; i++){
            arr[l+i] = newarr[i];
        }
    }
    void mergeSort(int arr[], int l, int r){
        if (l >= r) return;

        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};

int main(){
    Solution* sol = new Solution;
    int N = 5;
    int arr1[] = {2,4,1,3,5};
    cout << sol->inversionCount(arr1, N) << endl;

    int arr2[] = {2,3,4,5,6};
    cout << sol->inversionCount(arr2, N) << endl;

    int arr3[] = {10,10,10};
    cout << sol->inversionCount(arr3, 3) << endl;

    return 0;
}
