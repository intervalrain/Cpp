#include <iostream>
#include <forward_list>
using namespace std;

template <typename T>
void print(forward_list<T> l){
    for (auto it = l.begin(); it != l.end(); it++)
        cout << (*it) << " ";
    cout << endl;
}

int main(){
    forward_list<int> l = {1,3,2,4,6,5,7,8};
    print(l);
    cout << (l.empty() ? "empty" : "not empty") << endl;

    l.clear();
    print(l);
    cout << (l.empty() ? "empty" : "not empty") << endl;

    return 0;
}
