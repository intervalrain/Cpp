#include <iostream>
using namespace std;

int main(){
    // define a var name as a string, and assign a char array for its value.
    string name = "Rain Hu";
    cout << name << endl;
    // to derive how many characters in the string.
    int len = name.length();
    cout << len << endl;
    // to derive the 5th character in the string.
    cout << name[5] << endl;
    // replace the 5th character with 'D'.
    name[5] = 'D';
    cout << name << endl;

    // find character or string x inside the string str from the starting index i. ex. str.find(x, y);
    cout << name.find("in", 0) << endl;

    // take the substring from the string from index x, and the sub string's length is y. ex. str.substr(x, y);
    cout << name.substr(5, 2) << endl;

    return 0;

}
