#include <bits/stdc++.h>
#define dswap(a,b) {int tmp = a; a = b; b = tmp;}

using namespace std;

void tswap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void vswap(int& a, int& b){
    a ^= b;
    b ^= a;
    a ^= b;
}

int main(){
    int a = 5;
    int b = 6;
    cout << "(a,b) = " << "(" << a << "," << b << ")" << endl;

    vswap(a,b);
    cout << "(a,b) = " << "(" << a << "," << b << ")" << endl;

    dswap(a,b);
    cout << "(a,b) = " << "(" << a << "," << b << ")" << endl;

    tswap(a,b);
    cout << "(a,b) = " << "(" << a << "," << b << ")" << endl;

    swap(a,b);
    cout << "(a,b) = " << "(" << a << "," << b << ")" << endl;

    return 0;
}
