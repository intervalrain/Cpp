#include <bits/stdc++.h>
using namespace std;

// pass-by-value
int square1(int n){
    cout << "address of n with pass-by-value method: " << &n << endl;
    n *= n;
    cout << "n^2 = ";
    return n;
}

// pass-by-reference with pointer
int square2(int* n){
    cout << "address of n with pass-by-reference with pointer method: " << n << endl;
    (*n) *= (*n);
    cout << "n^2 = ";
    return *n;
}

// pass-by-reference with Reference
int square3(int& n){
    cout << "address of n with pass-by-reference with Reference method: " << &n << endl;
    n *= n;
    cout << "n^2 = ";
    return n;
}

int main(){
    int n = 3;
    cout << "address of n in main(): " << &n << endl;
    cout << "n = " << n << endl;
    cout << square1(n) << endl;
    cout << "n = " << n << endl;
    cout << square2(&n) << endl;
    cout << "n = " << n << endl;
    cout << square3(n) << endl;
    cout << "n = " << n << endl;

    return 0;
}
