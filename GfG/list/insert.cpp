#include <iostream>
#include <list>
#include "print.cpp"
using namespace std;

int main(){
    list<int> l = {10, 20, 30};
    auto it = l.begin();  // point to 10
    it++;                 // point to 20
    print(l);

    // insert 15 at the second position and keeping the iterator at second position only
    it = l.insert(it, 15);    // 10, 15,20, 30
    print(l);

    // insert 7 two times at current position
    l.insert(it, 2, 7);       // 10, 7, 7, 15, 20, 30
    print(l);

    cout << "front is " << l.front() << "\n";
    cout << "back is " << l.back() << "\n";
    cout << "size is " << l.size() << endl;

    return 0;
}
