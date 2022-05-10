#include <iostream>
#include <vector>

using namespace std;

int main(){

    int arr[] = {5,4,3,7,9,1,2,6,0,8};
    vector<int> vec(arr, arr+10);

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++){
        cout << *(iter) << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end());

    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *(it) << " ";
    }
    cout << endl;

    return 0;
}
