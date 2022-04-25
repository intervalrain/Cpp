#include <iostream>
#include <algorithm>
#include <vector>
#include "print.cc"

using namespace std;

int main(){
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45, 20, 20, 20, 20, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    print(vec);                     // [5, 10, 15, 20, 20, 23, 42, 45, 20, 20, 20, 20, 20]

    vec.erase(vec.begin() + 1);     // [5, 15, 20, 20, 23, 42, 45, 20, 20, 20, 20, 20]
    print(vec);

    sort(vec.begin(), vec.end());   // [5, 15, 20, 20, 20, 20, 20, 20, 20, 23, 42, 45]
    print(vec);

    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    print(vec);                     // [5, 15, 20, 23, 42, 45]

    return 0;
}