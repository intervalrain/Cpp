#include <iostream>
using namespace std;

int main(){
    int r;
    cin >> r;
    for (int i = 0; i <= 2 * r; ++i){
        for (int j = 0; j <= 2 * r; ++j){
            if ((i-r)*(i-r)+(j-r)*(j-r) <= r*r){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
