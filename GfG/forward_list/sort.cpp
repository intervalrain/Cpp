#include <iostream>
#include <forward_list>
using namespace std;


void print(forward_list<int> l){
    for (auto it = l.begin(); it != l.end(); it++)
        cout << (*it) << " ";
    cout << endl;
}

int main(){
    forward_list<int> l = {1,3,2,4,6,5,7,8};
    l.sort();
    print(l);

    return 0;
}
