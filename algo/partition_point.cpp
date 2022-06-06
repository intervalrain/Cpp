#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool even(int x){
    return x % 2 == 0;
}

int main(){
    vector<int> vec = {2, 1, 5, 6, 8, 7, 3, 4, 9, 0};
    // stable_partition(vec.begin(), vec.end(), [](int x){
    //     return x % 2 == 0;
    // });
    stable_partition(vec.begin(), vec.end(), even);

    cout << "The partitioned vector is: ";
    for (int &x : vec) cout << x << " ";
    cout << endl;

    auto itp = partition_point(vec.begin(), vec.end(), even);

    cout << "The vector elements returning true for condition are: ";
    for (auto it = vec.begin(); it != itp; it++)
        cout << *it << " ";
    cout << endl;

    return 0;

}
