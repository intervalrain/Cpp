#include <iostream>
using namespace std;

template <typename T>

// function template

T myMax(T x, T y){
    return (x > y) ? x : y;
}

int main(){

    cout << myMax<int>(3, 7) << endl;

    cout << myMax<char>('c', 'g') << endl;

    return 0;
}
