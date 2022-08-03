#include <iostream>
#include <string>

/**
 * Assume you have a mehtod isSubstring which checks if one word is a substring of another.
 * Given two strings, s1, s2, write a code to check if s2 is a rotation of s1 using only one call to isSubstring.
 * (e.g. "waterbottle" is a rotation of "erbottlewat".
 */

using namespace std;

class Solution{
  public:
    bool isRotation(string s, string t){
        return isSubstring(s + s, t);
    }

    bool isSubstring(string s, string t){
        if (s.length() < t.length()) return false;
        int n = t.length();
        for (int i = 0; i + n <= s.length(); i++){
            if (s.substr(i, n) == t) return true;
        }
        return false;
    }
};

int main(){
    string s = "waterbottle";
    string t = "erbottlewat";

    Solution* sol = new Solution();

    cout << ((sol->isRotation(s, t)) ? "True" : "False") << endl;

    return 0;
}
