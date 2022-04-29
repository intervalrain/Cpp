#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "GeeksforGeeks";

    // declaration of iterator;
    string::iterator it;

    // loop over the string using iterator
    for (it = s.begin(); it != s.end(); it++){
        cout << *it;
    }
    cout << endl;

    return 0;
}
