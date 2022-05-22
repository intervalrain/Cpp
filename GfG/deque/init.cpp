#include <deque>
#include <iostream>

using namespace std;

int main(){
    // creates an empty Deque
    deque<int> dq;

    // push element at back
    dq.push_back(10);

    // push element at front
    dq.push_front(20);

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    return 0;
}
