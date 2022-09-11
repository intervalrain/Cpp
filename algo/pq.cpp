#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> greater_pq;
    priority_queue<int, vector<int>, less<int>> less_pq;
    priority_queue<int> default_pq;

    for (int i = 0; i < 10; i++){
        greater_pq.push(i);
        less_pq.push(i);
        default_pq.push(i);
    }

    cout << "priority queue with greater<int>: ";
    while (!greater_pq.empty()){
        cout << greater_pq.top() << " ";
        greater_pq.pop();
    }
    cout << "\npriority queue with less<int>: ";
    while (!less_pq.empty()){
        cout << less_pq.top() << " ";
        less_pq.pop();
    }
    cout << "\npriority queue with default setting: ";
    while (!default_pq.empty()){
        cout << default_pq.top() << " ";
        default_pq.pop();
    }
    cout << endl;

    return 0;
}
