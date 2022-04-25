#include <iostream>
#include <iterator>
#include <list>
#include "print.cc"

using namespace std;

int main(){
    list<int> list;

    for (int i = 0; i < 10; i++){
        list.push_back(i);
    }

    list.empty() ? cout << "Empty\n" : cout << "Not empty\n";
    list.insert(++++list.begin() , 3, -1);
    list.insert(list.begin() , -100);

    print(list);

    return 0;
}
