#include <bits/stdc++.h>
using namespace std;


/** Check if a string entered is a palindrome or not. (A palindrome is a string which is the same as the original when reversed) */
bool isPalindrome(string s){
    int n = s.length();
    for (int i = 0; i < n/2; i++){
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

int main(){
    while (true){
        string str;
        cout << "Please enter a string to test if it is palindrome or not(q to quit): ";
        cin >> str;
        if (str == "q" || str == "Q")  break;
        cout << (isPalindrome(str) ? "yes" : "no") << endl;
    }
    return 0;
}
