#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {1,1,2,3,5,8,13,21,34,55};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);  // initialize with array
    
    cout << "Output of begin() and end(): ";
    for (auto i = vec.begin(); i != vec.end(); ++i) cout << *i << " ";
    
    cout << "\nOutput of rbegin() and rend(): ";
    for (auto i = vec.rbegin(); i != vec.rend(); ++i) cout << *i << " ";
    
    cout << "\nOutput of cbegin() and cend(): ";
    for (auto i = vec.cbegin(); i != vec.cend(); ++i) cout << *i << " ";

    cout << "\nOutput of crbegin() and crend(): ";
    for (auto i = vec.crbegin(); i != vec.crend(); ++i) cout << *i << " ";

    return 0;
}
