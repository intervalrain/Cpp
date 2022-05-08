#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    vector<int> vec (arr, arr+5);
    vector<int>::iterator it = vec.begin();

    it = next(it);

    cout << *(it) << " "; // 20

    it = next(it, 2);

    cout << *(it) << " "; // 40

    it = prev(it);

    cout << *(it) << " "; // 30

    next(it, 3);
    cout << *(it) << " "; // 30


    return 9;
}
