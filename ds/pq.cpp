#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> vec = {3,7,2,4,1,6,5,9,8,0};
    for (int x : vec){
        pq.push(x);
    }

    while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
