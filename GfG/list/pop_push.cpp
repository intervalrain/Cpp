#include <iostream>
#include <list>
#include "print.cpp"
using namespace std;

int main(){

    list<int> l = {2,3,4,5,6,7,8};
    print(l);

    l.push_back(9);
    print(l);

    l.push_front(1);
    print(l);

    l.pop_back();
    print(l);

    l.pop_front();
    print(l);

    return 0;
}
