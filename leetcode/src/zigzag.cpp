#include <iostream>
#include <vector>
using namespace std;

/**
 * Convert array into Zig-Zag fashion
 *
 * Given an array Arr(distinct elements) of size N. Rearrange the elements of array in zig-zag fashion.
 * The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output.
 * i.e you have to iterate on the original array only.
 *
 */

class Solution{
public:
    void zigZag(int arr[], int n){
        for (int i = 0; i < n - 1; i++){
            if ((i & 1) == 0){
                if (arr[i] > arr[i+1]){
                    swap(arr[i],arr[i+1]);
                }
            } else {
                if (arr[i] < arr[i+1]){
                    swap(arr[i],arr[i+1]);
                }
            }
        }
    }
};

void print(int* arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    Solution* sol = new Solution;

    int arr1[] = {4,3,7,8,6,2,1};
    int n = sizeof(arr1)/sizeof(int);
    sol->zigZag(arr1, n);
    print(arr1, n);

    int arr2[] = {1,4,3,2};
    n = sizeof(arr2)/sizeof(int);
    sol->zigZag(arr2, n);
    print(arr2, n);

    return 0;

}
