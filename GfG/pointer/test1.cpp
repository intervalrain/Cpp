#include <iostream>

using namespace std;

int main(){
    int var = 10;
    int *ptr = &var;
    *ptr = 20;

    int **pptr = &ptr;
    **pptr = 30;

    cout << var << endl;
    cout << *ptr << endl;
    cout << **pptr << endl;

    return 0;
}
