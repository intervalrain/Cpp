#include <iostream>

using namespace std;

int main(){
    int i1 = 1024, i2 = 2048;
    int &r1 = i1, r2 = i2;
    r1 = 2048;
    r2 = 1024;
    int i3 = 1024, &i4 = i3;
    int &r3 = i3, &r4 = i2;

    cout << "i1 = " << i1 << endl;
    cout << "i2 = " << i2 << endl;
    cout << "i3 = " << i3 << endl;
    cout << "i4 = " << i4 << endl;
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r3 = " << r3 << endl;
    cout << "r4 = " << r4 << endl;

    return 0; 
}