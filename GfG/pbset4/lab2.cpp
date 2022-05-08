/**
 * Generic sort
 *
 * You need to sort elements of an array where the array can be of following data-types:
 *   1. Integer
 *   2. String
 *   3. floating number
 * Your task is to complete the given two functions: sortArray() and printArray().
 *
 * The input line contains 2 lines. The first line contains n(size of array) and q(type of array) separated by space.
 * Below is the description aboue q.
 *   q = 1, means elements of the array are integer type.
 *   q = 2, means elements of the array are of string type.
 *   q = 3, means elements of array are of floating digit type.
 *
 * The second line contains n elements of the array separated by space.
 * We have to print the elements in sorted form of given type of array separated by space.
 */

#include <bits/stdc++.h>
using namespace std;

template <class T>
void sortArray(T a[], int n){
    sort(a, a+n);
}

template <class T>
void printArray(T a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int t = 3;
    while (t > 0){
        t--;
        cout << "Enter number of inputs: ";
        int n, q, i;
        cin >> n;
        cout << "Enter class type (1 for integer, 2 for string, 3 for float): ";
        cin >> q;
        int iarr[n];
        string sarr[n];
        float farr[n];

        switch(q){
            case 1:
                for (int i = 0; i < n; i++){
                    cin >> iarr[i];
                }
                sortArray(iarr, n);
                printArray(iarr, n);
                break;
            case 2:
                for (int i = 0; i < n; i++){
                    cin >> sarr[i];
                }
                sortArray(sarr, n);
                printArray(sarr, n);
                break;
            case 3:
                for (int i = 0; i < n; i++){
                    cin >> farr[i];
                }
                sortArray(farr, n);
                printArray(farr, n);
                break;
            default:
                break;
        }
    }
    return 0;
}
