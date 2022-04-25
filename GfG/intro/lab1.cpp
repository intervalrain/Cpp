#include <bits/stdc++.h>
using namespace std;

char caseTrans(char ch){
    return ch >= 'a' && ch <= 'z' ? (ch - 'a' + 'A') : (ch - 'A' + 'a');
}

int main(){
    char ch1 = 'a', ch2 = 'A';

    cout << "Character a changed to: " << caseTrans(ch1) << endl;
    cout << "Character A changed to: " << caseTrans(ch2) << endl;

    return 0;
}

