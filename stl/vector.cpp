#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>&nums){
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void iterprint(vector<int>&nums){
    vector<int>::iterator iter;
    for (iter = nums.begin(); iter != nums.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

bool f(int x, int y){
    return x > y;
}

int main(){
    // initialize vector
    vector<int> A = {11, 2, 3, 14};
    print(A);

    // sort vector
    sort(A.begin(), A.end()); // O(NlogN);
    print(A);

    // to find a number in an vector
    bool present = binary_search(A.begin(), A.end(), 3);  // true: 1
    cout << present << endl;
    present = binary_search(A.begin(), A.end(), 4);       // false: 0
    cout << present << endl;

    // add a new number into vector
    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100);     // true: 1
    cout << present << endl;

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);

    // use iterator
    vector<int>::iterator itlb = lower_bound(A.begin(), A.end(), 100);  // lower_bound has to apply on sorted array, >=
    vector<int>::iterator itub = upper_bound(A.begin(), A.end(), 100);  // upper_bound has to apply on sorted array, >

    sort(A.begin(), A.end());
    // 2 3 3 11 14 100 100 100 100 101 123 246 
    //          ^                   ^                   

    print(A);
    cout << *itlb << " " << *itub << endl;
    cout << itub - itlb << endl;

    sort(A.begin(), A.end(), f);
    iterprint(A);

    return 0;
}