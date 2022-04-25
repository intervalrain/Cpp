#include <iostream>
#include <string>

using namespace std;

int main(){
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello " << name << endl;

    cout << "Enter your age: ";
    cin >> age;
    cout << "Wow! You look younger than " << age << endl;

    return 0;
}

