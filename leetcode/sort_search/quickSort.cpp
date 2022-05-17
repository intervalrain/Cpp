#include <iostream>
using namespace std;

/**
 * Quick Sort (Medium)
 *
 * Quick Sort is a Divide and Conquer algorithm.
 * It picks an element as pivot and partitions the given array around the picked pivot.
 * Given an array arr[], its starting position low and its ending position high.
 *
 * Implement the partition() and quickSort() functions to sort the array.
 */

void quickSort(int*, int, int);
int partition(int*, int, int);


void sort(int arr[], int n){
    quickSort(arr, 0, n-1);
}

void quickSort(int arr[], int low, int high){
    if (low >= high) return;
    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int partition(int arr[], int low, int high){
    int pivot = high;
    int left = low, right = high - 1;
    while (left < right){
        while (arr[left] < arr[pivot] && left < right){
            left++;
        }
        while (arr[right] > arr[pivot] && left < right){
            right--;
        }
        if (left == right){
            swap(arr[left], arr[pivot]);
        } else {
            swap(arr[left], arr[right]);
        }
    }
    return left;
}

void print(int arr[], int n){
    for (size_t i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n = 5;
    int arr[] = {4,1,3,9,7};
    sort(arr, n);
    print(arr, n);

    n = 9;
    int arr1[] = {2,1,6,10,4,1,3,9,7};
    sort(arr1, n);
    print(arr1, n);

    return 0;
}
