#include <iostream>

using namespace std;

void print(int* arr, int n){
    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    // declare with specific size
    int arr1[10];

    // declare after user-input
    int n;
    cout << "Please enter a integer: ";
    cin >> n;
    int arr2[n];

    // declare by initializing elements
    int arr3[] = {1, 2, 3, 4, 5};

    // declare by specifying size and initializing
    int arr4[5] = {5, 4, 3, 2, 1};

    int arr5[7] = {1, 2, 3, 4, 5};

    cout << "arr1: "; print(arr1, 10);

    cout << "arr2: "; print(arr2, n);
    cout << "arr3: "; print(arr3, 5);
    cout << "arr4: "; print(arr4, 5);
    cout << "arr5: "; print(arr5, 7);

    return 0;
}
