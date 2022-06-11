#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <type_traits>

using namespace std;

bool comp(int a, int b){
  return a < b;
}
using Compare = integral_constant<decltype(&comp), &comp>;

int main(){
    vector<int> vec = {3,6,7,2,1,9,5,4,8};
    priority_queue<int, vector<int>, decltype(&comp)> pq(comp);
    for (int num:vec) pq.push(num);
    while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
