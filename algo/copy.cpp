// #include <iostream>
// #include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6};
    int arr2[6];

    copy_n(arr, 6, arr2);

    for (int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }

    return 0;
}