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
    int inversionCount(int arr[], int n){
        int tmp[n];
        return mergeSort(arr, tmp, 0, n-1);
    }
    int merge(int arr[], int tmp[], int left, int mid, int right){
        int i, j, k;
        int cnt = 0;
        i = left;
        j = mid;
        k = left;
        while (i <= mid-1 && j <= right){
            if (arr[i] <= arr[j]){
                tmp[k++] = arr[i++];
            } else {
                tmp[k++] = arr[j++];
                cnt = cnt + (mid - i);
            }
        }
        while (i <= mid-1){
            tmp[k++] = arr[i++];
        }
        while (j <= right){
            tmp[k++] = arr[j++];
        }
        for (int i = left; i <= right; i++){
            arr[i] = tmp[i];
        }
        return cnt;
    }
    int mergeSort(int arr[], int tmp[], int left, int right){
        int mid, cnt = 0;
        if (right <= left) return 0;
        mid = left + (right - left)/2;
        cnt += mergeSort(arr, tmp, left, mid);
        cnt += mergeSort(arr, tmp, mid+1, right);
        cnt += merge(arr, tmp, left, mid+1, right);
        return cnt;
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
