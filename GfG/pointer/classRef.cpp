#include <bits/stdc++.h>

using namespace std;


struct Student{
    string name;
    string address;
    int rollNo;
};

void print(const Student &s){
    cout << s.name << " " << s.address << " " << s.rollNo << endl;
}

int main(){
    Student s;
    s.name = "Jack";
    s.address = "NYC";
    s.rollNo = 53997;

    print(s);

    return 0;

}
