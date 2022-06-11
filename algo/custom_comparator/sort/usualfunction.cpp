#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp (int a, int b){
    return a < b;
}

int main(){
    int arr[] = {3,6,7,2,1,9,5,4,8};
    int n = sizeof(arr)/sizeof(int);
    vector<int> vec(arr, arr+n);
    sort(vec.begin(), vec.end(), comp);
    for (int num:vec) cout << num << " ";
    cout << endl;

    return 0;
}
