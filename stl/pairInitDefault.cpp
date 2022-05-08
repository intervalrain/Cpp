#include <iostream>
#include <utility>
using namespace std;

template <typename T, typename U>
void print(pair<T, U> p){
    cout << p.first << " ";
    cout << p.second << endl;
}

int main(){
    pair <int, double> p1;
    pair <string, char> p2;

    print(p1);    // 0, 0.0
    print(p2);    //        i.e., null

    return 0;
}
