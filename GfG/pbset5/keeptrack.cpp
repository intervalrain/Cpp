#include <iostream>
#include <vector>
#include <utility>
using namespace std;


void keeptrack(int* arr, int n){
    vector<pair<int,int> > vec;
    for (int i = 0; i < n; i++){
        vec.push_back(make_pair(arr[i], i));
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++){
        cout << "{" << vec[i].first << ", " << vec[i].second << "}\n";
    }
}

int main(){
    int arr[] = {2, 5, 3, 7, 1};
    keeptrack(arr, sizeof(arr)/sizeof(int));

    return 0;
}
