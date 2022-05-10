#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(vector<T> vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> lessThanK(int* arr, int n, int K){
    vector<int> vec;
    for (int i = 0; i < n; i++){
        if (arr[i] < K)
            vec.push_back(arr[i]);
    }
    return vec;
}

int main(){
    int arr[] = {17, 10, 20, 13, 7, 9};
    int n = sizeof(arr)/sizeof(int);
    int K = 15;
    vector<int> res = lessThanK(arr, n, K);
    print(res);

    return 0;
}
