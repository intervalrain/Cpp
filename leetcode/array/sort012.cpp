#include <iostream>
#include <vector>
using namespace std;

/**
 * Sort an array of 0s, 1s, 2s (Easy)
 *
 * Given an array of size N containing only 0s, 1s, and 2s;
 * sort the array in ascending order.
 */

void swap(vector<int>& arr, int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void sort012(vector<int>& arr, int n){
    int dp[3] = {0,0,0};
    for (int i= 0; i < n ;i++){
        dp[arr[i]]++;
    }
    int k = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < dp[i]; j++, k++)
            arr[k] = i;
    }
}

void print(vector<int> vec){
    for (int i : vec)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> arr = {0,2,1,2,0,1,2,0,0,1,0,2,2,1,1,2,0,1,2,1};
    int n = arr.size();
    sort012(arr, n);
    print(arr);
}
