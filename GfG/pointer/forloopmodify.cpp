#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40};
    vector<int> vec (arr, arr + 4);
    for (int &x : vec)
        x += 5;

    for (int x : vec)
        cout << x << " ";

    return 0;
}
