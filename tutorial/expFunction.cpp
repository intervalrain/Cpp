#include <iostream>
using namespace std;

int power(int base, int pow){
    int res;
    for (int i = 0; i < pow; i++){
        res *= base;
    }
    return res;
}

int main(){
    int a, b;
    cout << "Base: ";
    cin >> a;
    cout << "Power: ";
    cin >> b;
    cout << "Power " << b << " of " << a << " = " << power(a, b) << endl;

    return 0;
}
