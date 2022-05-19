#include <iostream>
using namespace std;
/** Merge Sort (Medium)
 *
 * Given an array arr[],
 * its starting position l and its ending position r.
 * Sort the array using merge sort algorithm.
 */

class Solution{
public:
    void merge(int arr[], int l, int m, int r){
        int i = l, j = m + 1;
        int newarr[r - l + 1];
        int cnt = 0;
        while (i <= m && j <= r){
            if (arr[i] < arr[j]){
                newarr[cnt++] = arr[i++];
            } else {
                newarr[cnt++] = arr[j++];
            }
        }
        while (i <= m) newarr[cnt++] = arr[i++];
        while (j <= r) newarr[cnt++] = arr[j++];
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

void print(int* arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
   cout << endl;
}

int main(){
    Solution* sol = new Solution;

    int n = 5;
    int arr[] = {4,1,3,9,7};
    sol->mergeSort(arr, 0, 4);
    print(arr, n);

    n = 10;
    int arr2[] = {10,9,8,7,6,5,4,3,2,1};
    sol->mergeSort(arr2, 0, 9);
    print(arr2, n);
}
