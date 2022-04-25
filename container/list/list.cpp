#include <iostream>
#include <iterator>
#include <list>
#include "print.cc"

using namespace std;

int main(){
    list<int> lst1, lst2;
    for (int i = 0; i < 10; ++i){
        lst1.push_back(i);
        lst2.push_front(i);
    }
    cout << "List1 is : ";
    print(lst1);
    cout << "List2 is : ";
    print(lst2);

    cout << "List1.front() : " << lst1.front() << "\n";
    cout << "List2.back() : " << lst2.back() << "\n";

    cout << "After List1.pop_front() : ";
    print(lst1);
    cout << "After List2.pop_back() : ";
    lst2.pop_back();
    print(lst2);

    cout << "After List1.reverse() : ";
    lst1.reverse();
    print(lst1);

    cout << "After List2.sort() : "; 
    lst2.sort();
    print(lst2);

    return 0;
}