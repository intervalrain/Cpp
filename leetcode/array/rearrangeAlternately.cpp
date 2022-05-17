#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void rearrange(long long *arr, int n){
        long long res[n];
        int i = 0, l = 0, r = n-1;
        while (i < n){
            res[i++] = arr[r--];
            if (i >= n) break;
            res[i++] = arr[l++];
        }
        for (int i = 0; i < n; i++){
            arr[i] = res[i];
        }
    }
};


void print(long long* arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n = 6;
    long long arr[] = {1,2,3,4,5,6};
    Solution* sol = new Solution;
    sol->rearrange(arr, n);
    print(arr, n);

    n = 11;
    long long arr2[] = {10,20,30,40,50,60,70,80,90,100,110};
    sol->rearrange(arr2, n);
    print(arr2, n);
}
