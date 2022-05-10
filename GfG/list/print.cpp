#include <iostream>
#include <list>
using namespace std;

template <typename T>

void print(list<T> l){
    for (auto it = l.begin(); it != l.end(); it++)
        cout << (*it) << " ";
    cout << endl;
}
