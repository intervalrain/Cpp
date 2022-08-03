#include <iostream>
#include <string>

/**
 * Implement a method to perform basic string compression using the counts of repeated characters.
 * For example, the string aabcccccaaa would become a2b1c5a3.
 * If the "compressed" string would not become smaller than the original string,
 * your method should return the original string.
 * You can assume that the string has only uppercase and lowercase letter(a-z).
 */

using namespace std;

class Solution{
  public:
    string compress(string s){
        string res = "";
        int cnt = 0;
        for (int i = 0; i < s.length(); i++){
            cnt++;
            if (i+1 >= s.length() || s[i] != s[i+1]){
                res.push_back(s[i]);
                res.push_back('0' + cnt);
                cnt = 0;
            }
        }
        return res.length() < s.length() ? res : s;
    }
};

int main(){
    Solution* sol = new Solution();
    while (true){
        cout << "Please enter a string to compress the word: ";
        string s;
        cin >> s;
        if (s[0] == 'q' || s[0] == 'Q') break;
        cout << "After being compressed >>>>> " << sol->compress(s) << endl;
    }

    return 0;
}
