#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) x.begin(),x.end()

using namespace std;

int main(){
    vector<int> arr1 = {1,2,3,4,5,1,2,3,4,5};
    vector<int> arr2 = {1,2,3};
    vector<int> arr3 = {2,3,4};
    vector<int> arr4 = {4,5,6,4,5,6};
    vector<int> arr5 = {1,3,5};

    auto pred = [](int x, int y)->bool{ return x == y; };
    auto pred2 = [](int x, int y)->bool{ return x == y+3; };

    auto it1 = find_end(all(arr1), all(arr2));
    auto it2 = find_end(all(arr1), all(arr2), pred);
    auto it3 = find_end(all(arr1), all(arr3));
    auto it4 = find_end(all(arr1), all(arr4));
    auto it5 = find_end(all(arr4), all(arr2), pred2);
    auto it6 = find_end(all(arr1), all(arr5));

    cout << distance(arr1.begin(), it1) << endl;
    cout << distance(arr1.begin(), it2) << endl;
    cout << distance(arr1.begin(), it3) << endl;
    cout << distance(arr1.begin(), it4) << endl;
    cout << distance(arr4.begin(), it5) << endl;
    cout << distance(arr1.begin(), it6) << endl;

    return 0;
}
