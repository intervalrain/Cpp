#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> vec = {2,1,5,6,8,7};

    is_partitioned(vec.begin(), vec.end(), [](int x){
        return x % 2 == 0;
    }) ?
    cout << "Vector is partitioned":
    cout << "Vector is not partitioned";
    cout << endl;
    
    partition(vec.begin(), vec.end(), [](int x){
        return x % 2 == 0;
    });
    
    cout << "The partitioned vector is : ";
    for (int &x : vec) cout << x << " ";

    return 0;
}