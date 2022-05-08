#include <iostream>
#include <vector>
using namespace std;

vector<int>::iterator next_vec(vector<int>::iterator it, int n = 1){
    return it + n;
}


void adv(vector<int>::iterator& it, int n){
    it = it + n;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    vector<int> vec (arr, arr + 5);
    vector<int>::iterator it = vec.begin();

    cout << *(it) << endl;    // 10

    adv(it, 2);               // act like advance()

    cout << *(it) << endl;    // 30

    next_vec(it, 2);          // act like next()

    cout << *(it) << endl;    // 30

    it = next_vec(it, 2);

    cout << *(it) << endl;    // 50

    return 0;
}
