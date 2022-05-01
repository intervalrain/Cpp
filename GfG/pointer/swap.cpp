#include <bits/stdc++.h>
using namespace std;

void swapcpp(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void swapc(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a = 2;
    int b = 3;

    cout << a << " " << b << endl;
    swapcpp(a, b);
    cout << a << " " << b << endl;
    swapc(&a, &b);
    cout << a << " " << b << endl;

    return 0;
}
