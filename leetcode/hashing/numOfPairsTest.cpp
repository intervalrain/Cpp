#include <iostream>

using namespace std;

int pow(int x, int y){
    int res = 1;
    for (int i = 0; i < y; i++){
        res *= x;
    }
    return res;
}

int main(){

    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j++)
            cout << "(" << i << "," << j << ")=" << (pow(i,j) > pow(j,i)) << " ";
        cout << endl;
    }

    return 0;
}
