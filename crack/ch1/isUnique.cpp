/**
 * Is Unique
 *
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional structrues?
 */

#include <iostream>

using namespace std;

bool is_unique(string& s){
    int bitmask = 0;
    for (const auto& c : s) {
        int bit = (1 << (c - 'a'));
        if (bitmask & bit) return false;
        bitmask |= bit;
    }
    return true;
}

int main() {
    string s;
    while (getline(cin, s)) {
        cout << s << " is " << (is_unique(s) ? "unique." : "not unique.") << endl;
        if (s == "quit") break;
    }

    return 0;
}
