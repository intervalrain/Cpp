#include <iostream>
#include <forward_list>
using namespace std;

void print (forward_list<int> l){
    for (auto it = l.begin(); it != l.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
}

int main(){
    forward_list<int> l1 = {1, 3, 5, 7, 9};
    forward_list<int> l2 = {2, 4, 6, 8, 10};

    l1.merge(l2);

    print(l1);
    print(l2);


    return 0;
}
