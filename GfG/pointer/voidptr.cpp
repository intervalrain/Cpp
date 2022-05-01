#include <bits/stdc++.h>
using namespace std;

void increase (void* data, int size){
    if (size == sizeof(char)){
        char* ptrchar = (char*) data;
        (*ptrchar)++;
    } else if (size == sizeof(int)){
        int* intchar = (int*) data;
        (*intchar)++;
    }
}

int main(){
    char c = 'x';
    int i = 10;
    increase(&c, sizeof(c));
    cout << c << endl;
    increase(&i, sizeof(int));
    cout << i << endl;

    return 0;
}
