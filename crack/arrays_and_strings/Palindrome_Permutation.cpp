#include <iostream>

/**
 * Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards.
 * A permutation is a rearrangement of letters.
 * The palindrome does not need to be limited to just dictionary words.
 * You can ignore casing and non-letter characters.
 */
using namespace std;

class Solution{
  public:
    bool isPermutationOfPalindrome(string s){
        int single = 0;
        int map[26] = {0};
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ' ') continue;
            map[s[i]-'a']++;
            if (map[s[i]-'a'] == 1){
                single++;
            } else if (map[s[i]-'a'] == 2){
                single--;
            }
        }
        return single == 0 || single == 1;
    }
};

int main(){
    Solution* sol = new Solution();
    while (true){
        cout << "Please input a string to check if it is a permutation of palindrome(q to quit): ";
        string s;
        getline(cin, s);
        if (s[0] == 'q' || s[0] == 'Q') break;
        if (sol->isPermutationOfPalindrome(s)){
            cout << s << " is permutation of palindrome" << endl;
        } else {
            cout << s << " is not permutation of palindrome" << endl;
        }
    }
    return 0;
}
