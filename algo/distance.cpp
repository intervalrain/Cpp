#include <iostream>
#include <algorithm>
#include <vector>
#include "print.cc"

using namespace std;

int main(){
    int arr[] = {5,10,15,20,20,23,42,45};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    print(vec);         // [5,10,15,20,20,23,42,45]

    cout << distance(vec.begin(), max_element(vec.begin(), vec.end())) << endl;

    return 0;
}