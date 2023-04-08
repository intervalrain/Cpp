/**
 * Check Permutation
 *
 * Given two strings, write a method to decide if one is a permutation of the other.
 */

#include <iostream>
#include <string>

using namespace std;

bool is_permutation(string& a, string& b) {
    if (a.size() != b.size()) return false;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    for (const auto& c : a) cnt[c-'a']++;
    for (const auto& c : b) {
        if (cnt[c-'a']-- == 0) return false;
    }
    return true;
}

int main() {
    string a, b;
    while (true) {
        cin >> a >> b;
        if (a == "quit") break;
        cout << a << (is_permutation(a, b) ? " is a " : "is not a ") << "permutation of " << b << endl;
    }


    return 0;
}
