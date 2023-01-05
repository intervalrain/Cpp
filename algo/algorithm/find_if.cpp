#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    auto isOdd = [](int x)->bool{ return x%2; };
    vector<int> arr = {2,3,7,4,9,12,5};
    auto it = find_if(arr.begin(), arr.end(), isOdd);

    cout << distance(arr.begin(), it) << endl;


    return 0;
}
