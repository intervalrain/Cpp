#include <bits/stdc++.h>
using namespace std;

#define ll long long


/** Convert decimal number input by the user to binary */
int main(){
    ll num;
    string bin;
    cout << "Decimal number to binary number: ";
    cin >> num;
    while (num > 0){
        bin.push_back((char)((num & 1) + '0'));
        num >>= 1;
    }
    reverse(bin.begin(), bin.end());
    cout << bin << endl;
    return 0;
}

