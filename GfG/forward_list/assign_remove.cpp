#include <iostream>
#include <forward_list>
using namespace std;

int main(){

    forward_list<int> l;
    l.assign({5, 10, 15, 20, 25, 10});
    l.remove(10);       // 5, 15, 20, 25

    for (auto it = l.begin(); it != l.end(); it++)
        cout << *(it) << " ";

    return 0;
}
