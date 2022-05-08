/**
 * Template in C++ is a feature. We write code once and use it for any data type including user defined data types.
 *
 * Given three cases:
 * 1st case when two strings are given, print the smallest of the two strings.
 * 2nd case when two integers are given, print the smallest of the two integers.
 * 3rd case whtn two char are given, print the smallest of the two characters(lowercase).
 *
 * Your task is to complete class minElement which would include a private variable say y,
 * a constructor which would set the given value to the private variable.
 * And a method check() which would take one parameter say x and print the min of x and y (private variable).
 *
 * First line of each input will contain 1 integer c.
 * Next line will contain two strings if c is equal to 1 or will contain two integers if c is equal to 2 or
 * will contain two char if value of c is equal to 3.
 * We have to print the lowest of the two values given.
 */

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class minElement{
private:
    T y;

public:
    minElement(T val){
        this->y = val;
    }

    T getValue(){
        return y;
    }

    void check(T x){
        cout << ((x < getValue()) ? x : getValue()) << endl;
    }
};

int main(){

    while (true){
        cout << "Enter 1 for string, 2 for integer, 3 for char, else to quit: ";
        int c;
        cin >> c;
        if (c == 1){
            string a, b;
            cin >> a >> b;
            minElement<string>obj1(a);
            obj1.check(b);
        } else if (c == 2){
            int a, b;
            cin >> a >> b;
            minElement<int>obj2(a);
            obj2.check(b);
        } else if (c == 3){
            char a, b;
            cin >> a >> b;
            minElement<char>obj3(a);
            obj3.check(b);
        } else {
            break;
        }
    }

    return 0;
}
