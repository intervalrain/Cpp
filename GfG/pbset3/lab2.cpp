#include <bits/stdc++.h>
using namespace std;

void print(int* p, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << *(p + i * m + j) << " ";
        }
        cout << endl;
    }
}
int main(){
    int a[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };

    print((int*)a, 3, 4);

    return 0;
}
