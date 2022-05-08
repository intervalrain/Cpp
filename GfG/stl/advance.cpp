#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    vector<int> vec (arr, arr+5);

    vector<int>::iterator it = vec.begin();

    advance(it, 3);

    cout << *(it) << " ";
    return 0;
}
