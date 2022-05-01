#include <bits/stdc++.h>
using namespace std;

/** write a program to swap two numbers */
void swap(int& x, int& y){
    int tmp = x;
    x = y;
    y = tmp;
}

int main(){
    int a = 5, b = 6;
    cout << "Before swap: \n";
    cout << "(a, b) = " << "(" << a << ", " << b << ")" << endl;
    swap(a, b);
    cout << "After swap: \n";
    cout << "(a, b) = " << "(" << a << ", " << b << ")" << endl;

    return 0;
}
