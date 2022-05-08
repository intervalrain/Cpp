#include <iostream>
#include <utility>
using namespace std;

int main(){
    pair<string, double> p("hello world", 3.14);

    cout << p.first << " ";
    cout << p.second << endl;

    return 0;
}

