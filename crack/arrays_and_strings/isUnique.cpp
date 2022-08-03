#include <iostream>

/** Implement an algorithm to determine if a string has all unique characters.
 *  What if you cannot use additional data structures?
 */

using namespace std;

class Solution{
  public:
    bool isUnique(string s){
        int bitmask = 0;
        for (int i = 0; i < s.length(); i++){
            int bit = 1 << (s[i] - 'a');
            if ((bitmask & bit) != 0) return false;
            bitmask |= bit;
        }
        return true;
    }
};

int main(){
    Solution* sol = new Solution();
    string s;
    while (true) {
        cout << "Please input a string(q to quit): ";
        cin >> s;
        if (s[0] == 'q' || s[0] == 'Q') break;
        cout << s << (sol->isUnique(s) ? " is unique" : " is not unique") << endl;
    }

    return 0;
}
