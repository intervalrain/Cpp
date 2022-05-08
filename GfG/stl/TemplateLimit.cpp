#include <iostream>
using namespace std;

template <typename T, int limit>
T arrMax(T arr[], int n){
    if (n > limit){
        cout << "limit exceeded";
        return 0;
    }

    T res = arr[0];

    for (int i = 1; i < n; i++){
        if (arr[i] > res)
              res = arr[i];
    }
    return res;
}

int main(){
    int arr1[] = {10, 40, 3, 2, 8, 6};
    float arr2[] = {10.5, 3.5, 1.5, 2.5, 9.5, 4.5};
    cout << arrMax<int, 50>(arr1, 6) << endl;
    cout << arrMax<float, 50>(arr2, 6) << endl;
}

