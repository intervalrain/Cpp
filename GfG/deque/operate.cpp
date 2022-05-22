#include <iostream>
#include <deque>
using namespace std;

/**
 * dq.begin()
 * dq.insert(position, value)
 * dq.pop_front()
 * dq.pop_back()
 * dp.emtpy()
 * dp.clear()
 */

int main(){
    deque<int> dq = {10,15,30,5,12};

    auto it = dq.begin();

    it++;

    dq.insert(it, 20);        // 10,20,15,30,5,12

    dq.pop_front();             // 20,15,30,5,12
    dq.pop_back();              // 20,15,30,5

    cout << "Deque size: " << dq.size() << endl;      // 4
    cout << "Iterator it points to " << (*it) << endl; // 20

    it = dq.insert(it, 1, 3);   // 20,3,3,15,30,5

    for (int i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;

    return 0;
}
