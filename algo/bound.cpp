#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    sort(vec.begin(), vec.end());

    cout << binary_search(vec.begin(), vec.end(), 20) << endl;                  // 1
    cout << (lower_bound(vec.begin(), vec.end(), 20) - vec.begin()) << endl;    // 3
    cout << (upper_bound(vec.begin(), vec.end(), 20) - vec.begin()) << endl;    // 5

    return 0;
}