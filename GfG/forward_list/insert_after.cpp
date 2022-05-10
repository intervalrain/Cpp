#include <iostream>
#include <forward_list>
using namespace std;

void print(forward_list<int> l){
    for (auto it = l.begin(); it != l.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
}


int main(){
    forward_list<int> l1 = {15, 20, 30};        // 15, 20, 30
    auto it = l1.insert_after(l1.begin(), 10);  // 15, 10, 20, 30
                                                //     ^
    // inserting a set of elements to the list
    it = l1.insert_after(it, {2, 3, 5});        // 15, 10, 2, 3, 5, 20, 30
    print(l1);                                  //               ^

    // the function is similar to the insert() function with
    it = l1.emplace_after(it, 40);              // 15, 10, 2, 3, 5, 40, 20, 30
                                                //                   ^
    print(l1);

    it = l1.emplace_after(it, 20);              // 15, 10, 2, 3, 5, 40, 20, 20, 30
                                                //                       ^
    print(l1);


    // remove an element from the forward_list
    it = l1.erase_after(it);                    // 15, 10, 2, 3, 5, 40, 20, 30
    print(l1);                                  //                          ^

    auto it1 = l1.insert_after(it, {1,1,1});    // 15, 10, 2, 3, 5, 40, 20, 1, 1, 1;
                                                //                          ^it   ^it1
    print(l1);

    // remove an element from it till end()
    it1 = l1.erase_after(it, l1.end());          // 15, 10, 2, 3, 5, 40, 20
    print(l1);

    return 0;


}
