#include <iostream>
using namespace std;

template <typename T>
struct Pair {
    T x, y;
    Pair(T i, T j){
        x = i;
        y = j;
    }

    // Function of T type
    T first(){
        return x;
    }
    T second(){
        return y;
    }
};

int main(){
    Pair<int> p1(10, 20);
    cout << p1.first() << " " << p1.second();

    return 0;

}
