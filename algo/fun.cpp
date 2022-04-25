#include <iostream>
using namespace std;

int main(){
    int num = 16;
    num--;
    while (num-- != 0){
        cout << (num--) << " ";
        num--;
    }
    return 0;
}