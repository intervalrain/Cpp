#include <iostream>
#include <string>
/**
 * Write a method to replace all spaces in a string with '%20'.
 * You may assume that the string has sufficient space at the end to hold the additional characters,
 * and that you are given the "true" length of the string.
 * (Note: If implementing in Java, please use a character array so that you can perform this operation in place.)
 */

using namespace std;

class Solution{
  public:
    string urlify(string s){
        string str;
        trim(s);
        char ch = s[0];
        for (int i = 1; i < s.length(); i++){
            if (ch == ' ' && s[i] == ' ') continue;
            ch = s[i];
            if (s[i] == ' '){
                str.push_back('%');
                str.push_back('2');
                str.push_back('0');
            } else {
                str.push_back(ch);
            }
        }
        return str;
    }
    void trim(string s){
        int n = s.length();
        while (n > 0){
            if (s[0] != ' ') break;
            s.erase(s.begin());
            n--;
        }
        while (n-1 >= 0){
            if (s[n-1] != ' ') break;
            s.pop_back();
            n--;
        }
    }
};

int main(){
    Solution* sol = new Solution();
    string s;
    while (true){
        cout << "Please input a string to urlify(q to quit): ";
        getline(cin, s);
        if (s[0] == 'q' || s[0] == 'Q') break;
        s = sol->urlify(s);
        cout << s << endl;
    }

    return 0;
};
