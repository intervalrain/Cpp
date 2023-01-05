#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,3,5,7,9};
    vector<int> arr3 = {2,4,6,8,10};
    auto isodd = [](int x)->bool{ return x%2; };
    cout << all_of(arr1.begin(), arr1.end(), isodd) << endl;
    cout << all_of(arr2.begin(), arr2.end(), isodd) << endl;
    cout << all_of(arr3.begin(), arr3.end(), isodd) << endl;

    return 0;
}
