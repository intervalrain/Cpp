#include <iostream>
#include <forward_list>
using namespace std;

int main(){

    // assign method 1
    forward_list<int> l;
    l.assign({10, 20, 30, 10});

    // assign method 2
    forward_list<int> l2;
    l2.assign(l.begin(), l.end());

    for (auto it = l2.begin(); it != l2.end(); it++)
        cout << (*it) << " ";
    return 0;

}
