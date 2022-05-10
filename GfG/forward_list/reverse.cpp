#include <iostream>
#include <forward_list>
using namespace std;

int main(){

    forward_list<int> l = {1, 2, 3, 4, 5, 6, 7, 8};
    l.reverse();

    for (auto it = l.begin(); it != l.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
    return 0;
}
