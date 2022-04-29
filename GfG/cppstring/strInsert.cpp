#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "Hello everyone";
    string s2 = "and Good day to ";

    int index = s1.find("everyone");
    //int index = p - s1.begin();
    s1.insert(index, s2);

    cout << s1 << endl;

    return 0;
}
