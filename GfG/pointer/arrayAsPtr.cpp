#include <bits/stdc++.h>
using namespace std;

int main(){
    int val[3] = {5, 10, 20};
    int* ptr = val;
    for (int i = 0; i < 3; i++){
        cout << *ptr << " ";
        ptr++;
    }

    return 0;
}
