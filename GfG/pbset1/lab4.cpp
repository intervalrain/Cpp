#include <bits/stdc++.h>
using namespace std;

int countMinChange(int money){
    assert (money >= 0);
    int q, res = 0;

    int arr[] = {1000, 500, 100, 50, 10, 5, 1};

    for (int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        q = money / arr[i];
        money -= q * arr[i];
        res += q;
    }

    return res;
}

int main(){
    int money;
    cout << "Please enter a number of money: ";
    cin >> money;

    cout << "The minimum number of denominations is: " << countMinChange(money) << endl;

    return 0;
}
