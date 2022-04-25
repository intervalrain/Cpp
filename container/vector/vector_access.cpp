#include <bits/stdc++.h>
#include "print.cc"

using namespace std;

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec(arr, arr + n);
    print(vec);
    
    cout << "vec[2]: " << vec[2] << "\n";
    cout << "vec.at(4): " << vec.at(4) << "\n";
    cout << "vec.front(): " << vec.front() << "\n";
    cout << "vec.back(): " << vec.back() << "\n";

    int* pos = vec.data();
    
    for (int* i = pos; i != pos + vec.size(); i++){
        cout << *i << " ";
    }

    return 0;
}