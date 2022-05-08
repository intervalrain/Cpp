#include <iostream>
#include <utility>
using namespace std;

template <typename T, typename U>
void print(pair<T,U> p){
    cout << p.first << " ";
    cout << p.second << endl;
}


int main(){
    pair <int, char> p1;
    pair <string, double> p2("hello world", 3.13);
    pair <string, double> p3;

    p1.first = 100;
    p1.second = 'G';

    p3 = make_pair("hello ni hao ma", 3.14);

    print(p1);
    print(p2);
    print(p3);

    return 0;
}
