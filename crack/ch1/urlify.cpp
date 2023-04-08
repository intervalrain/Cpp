/**
 * URLify
 *
 * Write a method to replace all spaces in a string with '%20'.
 * You may assume that the string has sufficient space at the end to hold the additional characters,
 * and that you are given the "true" length of the string.
 * (Note: if implementing in Java, please use a character array so that you can perform this operation in place)
 */

#include <iostream>
#include <string>
#define space "%20"

using namespace std;

void urlify(string& s) {
    string res;
    char prev = '#';
    for (const auto& c : s) {
        if (prev == ' ' && c == ' ') continue;
        if (c == ' ') res += space;
        else res.push_back(c);
        prev = c;
    }
    s = res;
}

int main() {
    string s;
    while (getline(cin,s)) {
        if (s == "quit") break;
        urlify(s);
        cout << s << endl;
    }

    return 0;
}
