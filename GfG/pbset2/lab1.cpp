#include <bits/stdc++.h>
using namespace std;

int main(){

    unsigned long long int x = 255657434267;

    int num_digits = 0;

    while (x > 0){
        x /= 10;
        num_digits++;
    }

    cout << num_digits << endl;

    return 0;
}
