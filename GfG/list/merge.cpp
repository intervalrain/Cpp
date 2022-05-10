#include <iostream>
#include <list>
#include "print.cpp"
using namespace std;

int main(){

    list<int> list1 = {1, 3, 5, 7, 9};
    list<int> list2 = {2, 4, 6, 8, 10};

    list2.merge(list1);

    print(list1);
    print(list2);

    return 0;
}
