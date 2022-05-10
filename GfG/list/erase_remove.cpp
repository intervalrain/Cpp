#include <iostream>
#include <list>
#include "print.cpp"
using namespace std;

int main(){

    list<int> l = {10, 20, 30, 40, 30, 20, 40};
    auto it = l.begin();

    // delete the element pointed by iterator
    it = l.erase(it);
    print(l);


    // delete all the elements valued 40
    l.remove(40);
    print(l);

    return 0;
}

