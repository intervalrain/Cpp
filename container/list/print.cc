#include <iostream>
#include <vector>
#include <list>

using namespace std;

void print(list<int> lst){
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); ++it){
        cout << *it << " ";
    }
    cout << "\n";
}