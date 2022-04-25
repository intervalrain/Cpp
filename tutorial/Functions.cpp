#include <iostream>
#include <string>
using namespace std;

void sayHi(string name){
    cout << "Hello " << name << endl;
}

int main(){
    string user;
    cout << "Enter your name: ";
    getline(cin, user);
    sayHi(user);

    return 0;
}
