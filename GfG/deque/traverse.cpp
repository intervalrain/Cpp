#include <iostream>
#include <deque>
using namespace std;

int main(){
    // Creates and initializes the Deque at the same time
    deque<int> dq = {10, 20, 30, 40, 50};

    // Traverse the Deque using foreach loop
    for (auto x : dq)
        cout << x << " ";
    cout << endl;

    return 0;
}
