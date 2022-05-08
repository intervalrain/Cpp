#include <iostream>
using namespace std;

template <typename T>

T arrMax(T arr[], int n){
    T res = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > res)
            res = arr[i];
    return res;
}


template <typename T>
T* arrMax2(T* a, T* b){
    T* res = a;
    for (T* it = a; it != b; it++){
        if (*(it) > *(res))
            res = it;
    }
    return res;
}

int main(){
    int arr[] = {3, 10, 43, 23, 81, 0, 26};
    cout << arrMax<int>(arr, 7) << endl; // 81
    cout << arrMax<int>(arr, 3) << endl; // 43

    float farr[] = {3.0, 3.14, 6.28, 5,42};
    cout << *(arrMax2<float>(farr, farr+4));  // 6.28:


    return 0;
}
