#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> A = {1,2,3,4,5};

    for (int &x : A){
        x++;
    }

    for (int x : A){
        cout << x << " ";
    }
    cout << endl;
}