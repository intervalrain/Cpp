#include <iostream>
using namespace std;

int main(){
    int age = 19;
    int *pAge = &age;
    double gpa = 4.3;
    double *pGpa = &gpa;
    string name = "Rain";
    string *pName = &name;

    // pointer is a datatype, which is a memory address.
    cout << "Age: " << *pAge << endl;
    cout << "Gpa: " << *pGpa << endl;
    cout << "Name: " << *pName << endl;

    return 0;
}
