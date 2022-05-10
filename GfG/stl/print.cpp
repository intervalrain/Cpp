#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(vector<T> vec){
    for (T a : vec)
        cout << a << " ";
    cout << endl;
}
