#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> arr = {1,3,7,4,9,12,5};
    vector<int>::iterator it1 = find(arr.begin(), arr.end(), 12);
    auto it2 = find(arr.begin(), arr.end(), 8);

    cout << distance(arr.begin(), it1) << endl;
    cout << distance(arr.begin(), it2) << endl;


    return 0;
}
