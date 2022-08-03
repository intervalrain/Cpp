#include <iostream>

/**
 * Given two strings, write a method to decide if one is a permutation of the other.
 */

using namespace std;

class Solution{
  public:
    bool isPermutation(string s, string t){
        int map[26] = {0};
        if (s.length() != t.length()) return false;
        int n = s.length();
        for (int i = 0; i < n; i++){
            map[s[i]-'a']++;
        }
        for (int i = 0; i < n; i++){
            if (map[t[i]-'a'] == 0) return false;
            map[t[i]-'a']--;
        }
        return true;
    }
};

int main(){
    Solution* sol = new Solution();
        string s, t;
    while (true){
        cout << "Please input two strings to check permutation(q to quit): ";
        cin >> s;
        if (s[0] == 'q' || s[0] == 'Q') break;
        cin >> t;
        cout << s << (sol->isPermutation(s, t) ? " is permutaton" : " is not permutation") << endl;
    }

    return 0;
}
