#include <bits/stdc++.h>
using namespace std;

void fun(int x){
    cout << "Integer Call: " << x << endl;
}

void fun(int *x){
    cout << "Pointer Call: " << x << endl;
}

int main(){
    int* p = NULL;
    fun(0);     // Integer call: 0
    fun(p);     // Pointer call: 0x0
//    fun(NULL);  // ambiguity issue;

    return 0;
}
