#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> arr = {1,2,3,5,8,13,21};
    for_each(arr.begin(), arr.end(), [](int x){ cout << x << " "; });

    return 0;
}
