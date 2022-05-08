#include <iostream>
#include <vector>
using namespace std;

int main(){

    int arr[] = {10, 20, 30, 40, 50};
    vector<int> vec (arr, arr + 5);

    vector<int>::iterator it = vec.begin();

    for (; it != vec.end(); it++){
        cout << *(it) << " ";
    }
    cout << endl;

    for (it--; it != vec.begin()-1; it--){
        cout << *(it) << " ";
    }
    cout << endl;

    return 0;
}
