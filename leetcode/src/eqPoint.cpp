#include <bits/stdc++.h>
using namespace std;

void eqPoint(int arr[], int n){
    int left = 0, right = n-1;
    int prod1 = arr[left], prod2 = arr[right];
    while (left+1 < right){
        if (prod1 < prod2){
            prod1 *= arr[++left];
        } else {
            prod2 *= arr[--right];
        }
    }

    if (prod1 != prod2) {
        cout << "-1" << endl;
        return;
    }
    cout << left+1 << "." << right+1 << endl;
}

int main(){
    int arr[] = {1,1,1,1,1,1};
    int n = 6;
    eqPoint(arr, n);

    return 0;
}
