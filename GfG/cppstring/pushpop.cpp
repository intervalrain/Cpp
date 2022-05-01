#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "Hello world";
    string str2;

    for (auto it = str.rbegin(); it != str.rend(); ++it){
        str2.push_back(*it);
    }

    cout << str << endl;
    cout << str2 << endl;

    return 0;
}
