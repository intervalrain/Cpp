#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int arr[] = {10,15,8,20};

    // sort
    sort(arr, arr + 4);

    for (int i = 0; i < 4; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // binary search(vailable when array is sorted)
    if (binary_search(arr, arr + 4, 8))
        cout << "Present";
    else
        cout << "Not present";

    return 0;
}