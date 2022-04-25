#include <iostream>
#include <algorithm>
#include <vector>
#include "print.cc"

using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    print(vec);         // [1,2,3,4,5,6,7]

    next_permutation(vec.begin(), vec.end());
    print(vec);         // [1,2,3,4,5,7,6]

    next_permutation(vec.begin(), vec.end());
    print(vec);         // [1,2,3,4,6,5,7]

    next_permutation(vec.begin(), vec.end());
    print(vec);         // [1,2,3,4,6,7,5]

    next_permutation(vec.begin(), vec.end());
    print(vec);         // [1,2,3,4,7,5,6]

    prev_permutation(vec.begin(), vec.end());
    print(vec);         // [1,2,3,4,6,7,5]

    return 0;
}