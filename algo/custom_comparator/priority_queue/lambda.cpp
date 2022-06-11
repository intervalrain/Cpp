#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    auto comp = [](int a, int b){
        return a < b;
    };

    vector<int> vec = {3,6,7,2,1,9,5,4,8};

    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    for (int num : vec) pq.push(num);

    while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
