#include <iostream>
#include <list>
#include "print.cpp"
using namespace std;

int main(){

    // construct a list, which is a doubly linked list
    list<int> l;

    // push_back
    l.push_back(10);    // 10
    l.push_back(20);    // 10, 20

    // push_front
    l.push_front(5);

    print(l);

    return 0;

}
