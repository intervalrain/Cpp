#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct comp{
    bool operator() (const int& a, const int& b) const {
        return a < b;
    }
};

int main(){
    vector<int> vec = {3,6,7,2,1,9,5,4,8};

    priority_queue<int, vector<int>, comp> pq(vec.begin(), vec.end());

    while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
