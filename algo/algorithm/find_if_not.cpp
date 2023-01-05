#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> arr = {1,3,7,4,9,12,5};
    auto it1 = find_if_not(arr.begin(), arr.end(), [](int x)->bool{ return x < 8; });
    auto it2 = find_if_not(arr.begin(), arr.end(), [](int x)->bool{ return x < 13; });
    auto it3 = find_if_not(arr.begin(), arr.end(), [](int x)->bool{ return x == 1; });

    cout << distance(arr.begin(), it1) << endl;
    cout << distance(arr.begin(), it2) << endl;
    cout << distance(arr.begin(), it3) << endl;

    return 0;
}
