#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include "print.cc"

using namespace std;

int main(){
    int arr[] = {10, 20, 5, 23, 42, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);

    // print initial vector
    print(vec);

    // sort
    sort(vec.begin(), vec.end());
    print(vec);

    // reverse
    reverse(vec.begin(), vec.end());
    print(vec);

    // max & min
    cout << *max_element(vec.begin(), vec.end()) << endl;
    cout << *min_element(vec.begin(), vec.end()) << endl;

    // accumulate
    cout << accumulate(vec.begin(), vec.end(), 0) << endl;

    return 0;
}
