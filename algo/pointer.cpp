#include <iostream>
using namespace std;

int* addition(int a, int b){
    int* sum = new int(a+b);
    return sum;
}

int substraction(int a, int b){
    return a - b;
}

int operation(int x, int y, int (*func)(int,int)){
    return (*func)(x,y);
}


int main(){
    int (*minus)(int,int) = substraction;
    int* m = addition(1,2);
    int n = operation(3, *m, minus);

    cout << *m << " " << n << endl;

    return 0;
}
