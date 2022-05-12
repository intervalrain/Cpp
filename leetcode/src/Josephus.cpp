#include <iostream>
#include <list>
using namespace std;

int josephus(int n, int k){
    list<int> l;
    for (int i = 1; i <= n; i++){
        l.push_back(i);
    }
    int j = 1;
    while (true){
        if (l.size() == 1) break;
        int tmp = l.front();
        l.pop_front();
        j = (j + 1) % k;
        if (j != 0) l.push_back(tmp);
    }
    return l.front();
}

int main(){
    cout << josephus(5, 3);
}