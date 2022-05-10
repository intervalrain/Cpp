#include <iostream>
#include <forward_list>
using namespace std;

int main(){

    forward_list<int> l;
    // assign 5 integers, which values 10.
    l.assign(5, 10);

    for (auto it = l.begin(); it != l.end(); it++)
        cout << (*it) << " ";
    return 0;
}
