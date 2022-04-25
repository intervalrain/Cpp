#include <iostream>
#include <string>

using namespace std;
using std::string;

class Human{
public:
    string name;
    int age;
    string sex;

    Human(string name, int age, string sex){
        this->name = name;
        this->age = age;
        this->sex = sex;
    }

    void intro(){
        cout << "Hello, my name is " << name << ", " << age << " years old." << endl;
    }
};

int main(){
    Human p("Rain", 30, "Male");
    Human *ptr = &p;
    ptr->intro();
    cout << ptr->sex << endl;

    return 0;
}
