#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 6;
    int arr[] = {2,3,1,5,6,8};

    int sum = 0;

    for (int i = 0; i < n; i++){
        sum += arr[i];
    }

    cout << sum / (double)n << endl;

    return 0;
}
