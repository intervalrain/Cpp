#include <bits/stdc++.h>
using namespace std;

/**
 * Write a program simulating a calculator (supporting +,-,*,/).
 * It should continuously ask for 2 numbers and the particular operation to perform (as a character),
 * and produce the output accordingly.
 * The program should quit if the user enters the character 'Q'.
 */

int main(){
    // opr ~ operation to perform
    // op1 ~ operand 1
    // op2 ~ operand 2
    // output: (op1 ior io2)
    char opr;
    double op1, op2;

    cout << "=====Welcome to simulating calculater=====\n";

    while (true){

        cout << "Please enter 3 inputs in order or 'q' to exit: (operator[+,-,*,/,q], double, double): ";
        cin >> opr;

        if (opr == 'Q' || opr == 'q')
            break;
        else{
            cin >> op1 >> op2;
            switch(opr){
                case '+':
                    cout << op1 + op2 << "\n";
                    break;
                case '-':
                    cout << op1 - op2 << "\n";
                    break;
                case '*':
                    cout << op1 * op2 << "\n";
                    break;
                case '/':
                    cout << op1 / op2 << "\n";
                    break;
                default:
                    cout << "Invalid Input\n";
                    break;
            }
        }
    }

    return 0;
}
